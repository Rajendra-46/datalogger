#include "selection.h"
#include "ui_selection.h"
#include"version.h"
#define GROUPSAVE "IP_PORT_GROUP_SAVE"
//========================
#define GROUP "IP_PORT_GROUP"
#define KEY "IP_key"
#define DEFAULT_IP_PORT "10.96.46.55:6789"
//===============
#define DBGROUP "DB_GROUP"
#define DBKEY "DB_key"
//====================
#define SCALING "scaling"
#define OFFSET "offset"
selection::selection(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::selection)
{
    ui->setupUi(this);

    socket = new QTcpSocket(this);
    //====================rotate==============
    m_timer = new QTimer();
    m_timer->setInterval(100);
    connect(m_timer,SIGNAL(timeout()),this,SLOT(rotate()),Qt::DirectConnection);

    m_wait_label=new QLabel(this);
    m_time_label=new QLabel(this);
    m_cancel_button = new QPushButton(this);

    QImage image(":/images/index.png");
    QImage image2 = image.scaled(150, 150);
    connect(m_cancel_button,&QPushButton::clicked,this,
            &selection::on_cancel_button_clicked);

    m_wait_label->setVisible(false);
    m_time_label->setVisible(false);
    m_cancel_button->setVisible(false);

    m_wait_label->setGeometry(this->width()/2-75,this->height()/2-75,150,150);
    m_time_label->setGeometry(this->width()/2-95,this->height()/2+80,230,30);
    m_cancel_button->setGeometry(this->width()/2+95,this->height()/2+80,140,30);

    m_wait_label->setPixmap(QPixmap::fromImage(image2));
    m_cancel_button->setText("Cancel");

    //==============================
    ui->label_sel->hide();
    ui->label_nan->hide();

    ui->gridLayoutTree->setContentsMargins(0,0,0,0);
    ui->gridLayoutTree->setAlignment(Qt::AlignTop);
    ui->gridLayoutTree->setSpacing(0);
    ui->scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    ui->comboBox_ConnectedIPs->setEditable(true);
    ui->comboBox_ConnectedIPs->lineEdit()->setFont(QFont("ubuntu",11));
    ui->comboBox_ConnectedIPs->lineEdit()->setPlaceholderText("Search or Enter IP and Port....");
    ui->comboBox_ConnectedIPs->setInsertPolicy(QComboBox::NoInsert);
    ui->comboBox_ConnectedIPs->completer()->setCompletionMode(QCompleter::PopupCompletion);
    ui->comboBox_ConnectedIPs->completer()->popup()->setFont(QFont("ubuntu",11));

    QRegExp ip("[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}:[0-9]{1,6}");
    QRegExpValidator *pReg_ip = new QRegExpValidator(ip, this);
    ui->comboBox_ConnectedIPs->setValidator(pReg_ip);

    QRegExp dec_neg("[-]?[0-9]+[.]?[0-9]{0,5}");
    QRegExpValidator *pReg_port_dec_neg = new QRegExpValidator(dec_neg, this);
    ui->lineEdit_Parm->setValidator(pReg_port_dec_neg);
    ui->lineEdit_AndParm->setValidator(pReg_port_dec_neg);

    QRegExp port("[0-9]{1,10}");
    QRegExpValidator *pReg_port = new QRegExpValidator(port, this);
    ui->lineEdit_After->setValidator(pReg_port);
    ui->lineEdit_Before->setValidator(pReg_port);
    ui->cmbBx_Samples->setValidator(pReg_port);

    InisialTime();
    displayText = "";
    QString Title = QString("PLC Data Analyzer V %1.%2.%3").arg(VERSION_MAJ).arg(VERSION_MIN).arg(VERSION_REV);
    this->setWindowTitle(Title);

    m_pingThread = new QThread(this);
    m_pingTimer = new QTimer(0);
    m_pingTimer->setInterval(10000);
    m_pingTimer->moveToThread(m_pingThread);

    // connect(m_pingThread,SIGNAL(started()),m_pingTimer,SLOT(start()));
    // connect(m_pingTimer,SIGNAL(timeout()),this,SLOT(CheckConnection()));

    connect(m_pingTimer, SIGNAL(timeout()), SLOT(CheckConnection()), Qt::DirectConnection);
    m_pingTimer->connect(m_pingThread, SIGNAL(started()), SLOT(start()));

    ReloadLastSelDB();
    ReloadDefaultIps();
    ReloadLastSelectedIPs();
    //SavedGroupNames();

    //=======================================================================
    connect(ui->customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), this, SLOT(xAxisChanged(QCPRange)));
    connect(ui->customPlot->yAxis, SIGNAL(rangeChanged(QCPRange)), this, SLOT(yAxisChanged(QCPRange)));
    connect(ui->customPlot,SIGNAL(mouseWheel(QWheelEvent *)),SLOT(controlledZoomX(QWheelEvent *)));
    connect(ui->customPlot,SIGNAL(mouseRelease(QMouseEvent *)), SLOT(mouseRelease(QMouseEvent *)));
    connect(ui->customPlot,SIGNAL(mousePress(QMouseEvent *)), SLOT(mousePress(QMouseEvent *)));
    connect(ui->customPlot,SIGNAL(mouseMove(QMouseEvent *)), SLOT(mouseMove(QMouseEvent *)));

}

selection::~selection()
{
    delete ui;
}

void selection::InisialTime()
{
    ui->cmbBx_Samples->setEditable(true);
    ui->PshBtn_search->setEnabled(false);
    ui->PshBtn_PLot->setEnabled(false);

    ui->radioButton_x_axis->setChecked(true);
    //    ui->radioButton_y_axis->setEnabled(false);
    //    ui->radioButton_y_axis2->setEnabled(false);

    ui->cmbBx_Type->setEnabled(false);
    ui->m_PshBtn_SavedPlots->setEnabled(false);
    ui->m_PshBtn_Delete->setEnabled(false);

    ui->m_PshBtn_Save->setEnabled(false);
    ui->m_PshBtn_export->setEnabled(false);
    ui->m_PshBtn_Scaling->setEnabled(false);

    //    ui->m_PshBtn_FetchDayWiseCont->setEnabled(false);
    //    ui->m_PshBtn_DBMatrics->setEnabled(false);
    ui->m_PshBtn_exportcsvFrmDB->setEnabled(false);


    // ui->cmbBx_SavedGroup->setEditable(false);
    ui->radioButton_TSEndTime->setChecked(true);
    ui->End_PvradioBtn->setChecked(true);
    ui->cmbBx_Etime->setEnabled(false);
    ui->cmbBx_EtimeDur->setEnabled(false);

    ui->lineEdit_After->setText("30");
    ui->lineEdit_Before->setText("30");

    QDateTime CurrentStartDateTime = QDateTime::currentDateTime().addSecs(-5 * 60);
    ui->TimeStamp_StartTime->setDateTime(CurrentStartDateTime);
    ui->timeEdit_StartTime->setTime(CurrentStartDateTime.time());

    QDateTime CurrentEndDateTime = QDateTime::currentDateTime();
    ui->TimeStamp_EndTime->setDateTime(CurrentEndDateTime);
    ui->timeEdit_EndTime->setTime(CurrentEndDateTime.time());

    QDateTime CurrentDurDateTime = ui->TimeStamp_StartTime->dateTime().addSecs(1 * 60);
    QString eTime = CurrentDurDateTime.toString("dd MMM yyyy hh:mm:ss");
    ui->label_TSDur->setText(eTime);

    QDateTime CurrentPvStartDateTime = QDateTime::currentDateTime().addDays(-1);
    ui->Pvalue_StartdateTime->setDateTime(CurrentPvStartDateTime);
    ui->timeEdit_PValueStart->setTime(CurrentPvStartDateTime.time());

    QDateTime CurrentPvEndDateTime = QDateTime::currentDateTime();
    ui->Pvalue_EnddateTime->setDateTime(CurrentPvEndDateTime);
    ui->timeEdit_PValueEnd->setTime(CurrentPvEndDateTime.time());

    QDateTime PvalCurrentDurDateTime = ui->Pvalue_StartdateTime->dateTime().addSecs(1 * 60 * 60);
    QString ePvDurime = PvalCurrentDurDateTime.toString("dd MMM yyyy hh:mm:ss");
    ui->label_TSDurPv->setText(ePvDurime);

    QStringList strlist;
    strlist << "True" << "False";
    ui->comboBox_true->addItems(strlist);
    ui->comboBox_false->addItems(strlist);

    QStringList qListOperators;
    qListOperators << ">" << "<" << "=" << "!=";
    ui->comboBox_AndCriOpr->addItems(qListOperators);
    ui->comboBox_CriOpr->addItems(qListOperators);

    //Other Combo Boxes
    QStringList qListDurations;
    qListDurations << "1 minute" << "5 minutes" << "10 minutes" << "30 minutes" << "1 hour" << "4 hours" << "8 hours";
    ui->cmbBx_Etime->addItems(qListDurations);

    QStringList qListSamples;
    qListSamples << "500" << "750" << "1000" << "2000";
    ui->cmbBx_Samples->addItems(qListSamples);
    //ui->cmbBx_SamplesPv->addItems(qListSamples);

    QStringList qListPeriods;
    qListPeriods<< "1 hour" << "2 hours" << "4 hours" << "8 hours" << "1 day" << "1 week" << "1 month" << "2 months" << "6 months" ;
    ui->cmbBx_EtimeDur->addItems(qListPeriods);

    ui->label_Samples->setText("Res 600 ms");
    //ui->label_SamplesPv->setText("Res 120ms");

}

void selection::ReloadDefaultIps()
{
    QSettings setting("Finecho_IP_Port_Save","IP_Port_Details_Save");
    setting.beginGroup(GROUPSAVE);
    foreach (const QString &key, setting.childKeys())
    {
        QString value = setting.value(key).toString();
        ui->comboBox_ConnectedIPs->addItem(value);
    }
    setting.endGroup();
}
void selection::SavedGroupNames()
{
    ui->cmbBx_SavedGroup->clear();
    QFile file(qApp->applicationDirPath()+"/"+Str_IPAddress+"-"+dbName+".txt");
    ui->cmbBx_SavedGroup->addItem("===None===");

    if(!file.open(QFile::ReadOnly |
                  QFile::Text))
    {
        //qDebug() << " Could not open the file for reading";
        return;
    }
    QTextStream in(&file);
    QString myText1 = in.readAll();
    QString myText2 = myText1.trimmed();
    QString myText = myText2.simplified();
    file.close();

    QString savedGroup = ui->cmbBx_SavedGroup->currentText();
    QStringList str_lst = myText.split('|');
    for (int i=0;i < str_lst.length()-1;i++)
    {
        QStringList val = str_lst.at(i).split(':');
        ui->cmbBx_SavedGroup->addItem(val.at(0).simplified());
    }
}
void selection::on_cmbBx_SavedGroup_currentIndexChanged(const QString &arg1)
{
    if(ui->cmbBx_SavedGroup->currentText() != "===None===")
    {
        //====================Reset scalemap========23/01/24========
        QMap<QString, QString>::iterator iterator_scale = str_mapScale.begin();
        while (iterator_scale != str_mapScale.end())
        {
            str_mapScale[iterator_scale.key().simplified()] = "1";
            ++iterator_scale;
        }

        //====================Reset offsetmap=======23/01/24=========
        QMap<QString, QString>::iterator iterator_offset = str_mapOffSet.begin();
        while (iterator_offset != str_mapOffSet.end())
        {
            str_mapOffSet[iterator_offset.key().simplified()] = "0";
            ++iterator_offset;
        }

        //=========================================================
        QFile file(qApp->applicationDirPath()+"/"+Str_IPAddress+"-"+dbName+".txt");
        if(!file.open(QFile::ReadOnly | QFile::Text))
        {
            //qDebug() << " Could not open the file for reading";
            return;
        }
        QTextStream in(&file);
        QString myText1 = in.readAll();
        QString myText2 = myText1.trimmed();
        QString myText = myText2.simplified();

        file.close();
        params.clear();
        scale.clear();
        offset.clear();
        QString savedGroup = ui->cmbBx_SavedGroup->currentText();
        QStringList str_lst = myText.split('|');
        //qDebug() << "str_lst==" << str_lst;

        for (int i=0;i < str_lst.length()-1;i++)
        {
            QStringList val = str_lst.at(i).split(':');
            //qDebug() << "val==" << val;
            if(val.at(0).simplified() == savedGroup)
            {
                QStringList strlstfnl = val.at(1).split(';');
                for (int i=0;i < strlstfnl.length()-1;i++)
                {
                    QStringList strlstfnlval = strlstfnl.at(i).split(',');
                    params << strlstfnlval.at(0).trimmed();
                    scale  << strlstfnlval.at(1);
                    offset << strlstfnlval.at(2);
                    //===========To add parameter scaling and offset of groupnames===19/01/24========
                    if (str_mapScale.contains(strlstfnlval.at(0).trimmed()))
                    {
                        str_mapScale[strlstfnlval.at(0).trimmed()] = strlstfnlval.at(1);
                    }
                    if (str_mapOffSet.contains(strlstfnlval.at(0).trimmed()))
                    {
                        str_mapOffSet[strlstfnlval.at(0).trimmed()] = strlstfnlval.at(2);
                    }
                    //===============================================================
                }
            }
        }
        selectedItemsClicked(params);
    }else{
        on_pshBtn_clearParams_clicked();
    }
}
void selection::ReloadLastSelectedIPs()
{
    QSettings settings("Finecho_IP_Port","IP_Port_Details");
    settings.beginGroup(GROUP);
    QString value = settings.value(KEY).toString();
    ui->comboBox_ConnectedIPs->setCurrentText(value);
    QStringList strlst = value.split(':');
    int dSize = value.length();
    QString strIP,strPort;
    if(dSize > 0){
        strIP = strlst.at(0);
        strPort = strlst.at(1);
        ConnectToIp_Port(strIP,strPort);
    }
    else
    {
        strIP = "127.0.0.1";
        strPort = "6789";
        ConnectToIp_Port(strIP,strPort);
    }
    settings.endGroup();

}
void selection::ReloadLastSelDB()
{
    QSettings settings_db("Finecho_Db","Db_Details");
    settings_db.beginGroup(DBGROUP);
    strLastSelDb = settings_db.value(DBKEY).toString();

    if(strLastSelDb == "")
    {
        strLastSelDb = "plc_data_40001";
    }
    settings_db.endGroup();
}
void selection::ConnectToIp_Port(QString strIP, QString strPort)
{
    socket->connectToHost(strIP, strPort.toInt());
    if(socket->waitForConnected(10000))
    {
        enable = true;
        m_pingThread->exit();
        QSettings setting("Finecho_IP_Port_Save","IP_Port_Details_Save");
        setting.beginGroup(GROUPSAVE);
        int i=0;
        QStringList lst = setting.allKeys();
        if(lst.length() == 0)
        {
            setting.setValue(strIP, strIP+":"+strPort);
        }
        foreach (const QString &key, setting.childKeys())
        {
            int num = lst.length();
            QString value = setting.value(key).toString();
            if(value != strIP+":"+strPort )
            {
                i++;
            }
            if(num == i)
            {
                setting.setValue(strIP, strIP+":"+strPort);
            }
        }
        QStringList strlst;
        foreach (const QString &key, setting.childKeys())
        {
            QString value = setting.value(key).toString();
           strlst << value;
            ui->comboBox_ConnectedIPs->addItem(value);
        }
        strlst.removeDuplicates();

        ui->comboBox_ConnectedIPs->clear();
        ui->comboBox_ConnectedIPs->addItems(strlst);
        ui->comboBox_ConnectedIPs->setCurrentText(strIP+":"+strPort);
        setting.endGroup();

        Str_IPAddress = strIP;
        Str_port = strPort;

        showConnectedIPPortPlots();
        //================================================================

        socket->write("[{\"username\":\"sateesh\",\"passcode\":\"123456\",\"authkey\":\"abcd\",\"endpoint\":\"getDatabases\"}]");
        socket->waitForBytesWritten(30000);

        QJsonParseError json_error_db;
        QByteArray data_db;
        QJsonDocument loadDoc_db;

        int iBytes_db = 0;
        int m_db;
        for(m_db=0; m_db<500; m_db++)
        {
            socket->waitForReadyRead(300);
            iBytes_db = socket->bytesAvailable();
            if (socket->state() != QAbstractSocket::ConnectedState)
                break;

            data_db += socket->readAll();
            usleep(50000);
        }
        if(data_db=="null"  || data_db=="")
        {
            dbName.clear();
            ui->lbl_Connection->setStyleSheet("background-color:green;");
            ui->comboBox_databases->hide();
            QMessageBox msgBox;
            msgBox.setText("No response from server.");
            msgBox.exec();
            return;
        }
        else{
            dbName.clear();
            loadDoc_db=QJsonDocument::fromJson(data_db, &json_error_db);
            if (json_error_db.error != QJsonParseError::NoError)
            {
                QMessageBox msgBox;
                msgBox.setText("JSON parse error: " + json_error_db.errorString()); // Invalid Response from Server.
                msgBox.exec();

                //ui->lbl_error_msg->setText("ERROR: " + json_error.errorString());
                ui->lbl_Connection->setStyleSheet("background-color:red;");
            }
        }

        QJsonObject rootObj_db = loadDoc_db.object();
        QJsonArray list_dbArray = rootObj_db.value("Active_Databases").toArray();
        QJsonArray list_prvdbArray = rootObj_db.value("Prev_Databases").toArray();

        strList_db.clear();
        strList_prvdb.clear();

        for(int i=0; i< list_dbArray.size(); i++)
        {
            strList_db << list_dbArray.at(i).toString();
        }

        for(int i=0; i< list_prvdbArray.size(); i++) // added lokesh active and prev dbs.
        {
            strList_prvdb << list_prvdbArray.at(i).toString();
        }

        ui->comboBox_databases->clear();
        ui->comboBox_databases->addItems(strList_db);
        ui->comboBox_databases->addItems(strList_prvdb);
        //  close the connection
        socket->close();

        if((strList_db.length() + strList_prvdb.length()) > 1)
        {
            ui->comboBox_databases->show();
            //fetchDB_Data();
        }
        else
        {
            ui->comboBox_databases->hide();
            //fetchDB_Data();
        }
        //=================================================================
        //ui->lbl_error_msg->setText("");
        ui->PshBtn_search->setEnabled(true);
        ui->PshBtn_PLot->setEnabled(true);

        //        ui->radioButton_x_axis->setEnabled(true);
        //        ui->radioButton_y_axis->setEnablstrlsted(true);
        //        ui->radioButton_y_axis2->setEnabled(true);

        ui->cmbBx_Type->setEnabled(true);
        ui->m_PshBtn_SavedPlots->setEnabled(true);
        ui->m_PshBtn_Delete->setEnabled(true);

        ui->m_PshBtn_Save->setEnabled(true);
        ui->m_PshBtn_export->setEnabled(true);
        ui->m_PshBtn_Scaling->setEnabled(true);

        //        ui->m_PshBtn_FetchDayWiseCont->setEnabled(true);
        //        ui->m_PshBtn_DBMatrics->setEnabled(true);
        ui->m_PshBtn_exportcsvFrmDB->setEnabled(true);
        ui->lbl_Connection->setStyleSheet("background-color:green;");

        QSettings settings("Finecho_IP_Port","IP_Port_Details");
        settings.beginGroup(GROUP);
        settings.setValue(KEY, strIP+":"+strPort);
        settings.endGroup();

        socket1 = new QTcpSocket(this);
        if(socket1->state() == QAbstractSocket::UnconnectedState)
        {
            socket1->connectToHost(strIP, strPort.toInt());
        }
        m_pingThread->start();

        // FillComboBoxes();
    }
    else
    {
        m_pingThread->exit();
        rootObj = QJsonObject();
        on_pshBtn_clearParams_clicked();
        fillData();
        QMessageBox msgBox;
        msgBox.setText("Error: " + socket->errorString() + "\nPlease Check connectivity to server");
        msgBox.exec();
        //ui->lbl_error_msg->setText("ERROR: " + socket->errorString());
        ui->lbl_Connection->setStyleSheet("background-color:red;");
        ui->label_Location->setText("");
    }
}

void selection::showConnectedIPPortPlots()
{
    if(ip_port.size() == 0)
    {
        return;
    }
    else
    {
        ui->cmbBx_Type->clear();
        ui->customPlot->clearGraphs();
        ui->customPlot->replot();
        QString ipportPlot = Str_IPAddress+Str_port;
        QString dbname  = dbName;
        for(int i=0;i< ip_port.size();i++)
        {
            if(dbname == dbnames.at(i) && ipportPlot == ip_port.at(i))
            {
                ui->cmbBx_Type->addItem(plots.at(i));
            }
        }
    }
}
void selection::on_comboBox_databases_currentTextChanged(const QString &arg1)
{
    if(dbnames.size() == 0)
    {
        return;
    }
    else
    {
        json_objtimeStamp = QJsonObject(); // added v1.0.7 build
        ui->cmbBx_Type->clear();
        ui->customPlot->clearGraphs();
        ui->customPlot->replot();
        QString ipportPlot = Str_IPAddress+Str_port;
        for(int i=0;i< dbnames.size();i++)
        {
            if(arg1 == dbnames.at(i) && ipportPlot == ip_port.at(i))
            {
                ui->cmbBx_Type->addItem(plots.at(i));
            }
        }
    }
}

void selection::on_comboBox_databases_currentIndexChanged(int index)
{
    on_pshBtn_clearParams_clicked();
    if(flagDb == true)
    {
        flagDb = false;
        ui->comboBox_databases->setCurrentText(strLastSelDb);
        if(ui->comboBox_databases->currentIndex()==0)
            fetchDB_Data();
    }
    else if(index >= 0)
        fetchDB_Data();
}
void selection::fetchDB_Data()
{
    QJsonObject jsonKeys;
    QJsonArray jsonArray;
    dbName = ui->comboBox_databases->currentText().trimmed();
    jsonKeys.insert("username","sateesh");
    jsonKeys.insert("passcode","123456");
    jsonKeys.insert("authkey","abcd");
    jsonKeys.insert("dbname",dbName);
    jsonKeys.insert("endpoint","getFieldsfromrd");
    jsonArray.append(jsonKeys);

    auto jsonDoc = QJsonDocument(jsonArray);
    //qDebug() << "jsonDoc=====" << jsonDoc;
    socket->connectToHost(Str_IPAddress,Str_port.toInt());
    if(socket->waitForConnected(10000))
    {
        socket->write(jsonDoc.toJson().constData());
        socket->waitForBytesWritten(30000);

        QJsonParseError json_error;
        QByteArray data;

        int iBytes=0;
        int m;
        for(m=0; m<500; m++)
        {
            socket->waitForReadyRead(3000);
            QApplication::setOverrideCursor(Qt::WaitCursor);
            iBytes = socket->bytesAvailable();
            if (socket->state() != QAbstractSocket::ConnectedState)
            {
                QApplication::setOverrideCursor(Qt::ArrowCursor);
                break;
            }

            data += socket->readAll();
            usleep(50000);
        }
        QJsonDocument loadDoc(QJsonDocument::fromJson(data, &json_error));
        if(data == "null"  || data == "")
        {
            QMessageBox msgBox;
            msgBox.setText("No response from server.");
            msgBox.exec();
        }
        else{
            if (json_error.error != QJsonParseError::NoError)
            {
                QMessageBox msgBox;
                msgBox.setText("JSON parse error: " + json_error.errorString());
                msgBox.exec();

                //ui->lbl_error_msg->setText("ERROR: " + json_error.errorString());
                ui->lbl_Connection->setStyleSheet("background-color:red;");
            }
        }
        rootObj = loadDoc.object();
    }
    socket->close();
    //qDebug() << "rootObj===" << rootObj;

    fillData();
    SavedGroupNames();

    strList_ParameterName.clear();
    strList_cmt.clear();
    strList_ParameterType.clear();
    strList_ScallingFactor.clear();
    str_mapScale.clear();
    str_mapOffSet.clear();
    str_mapType.clear();
    str_mapCmt.clear();

    generate_scaling_lists(rootObj);

    QJsonArray fieldDefJSONArrayServerTimeZone = rootObj.value("servertimezone").toArray();
    QJsonValue fieldSet_ServerTimeZone;
    QJsonObject fieldObj_ServerTimeZone;

    fieldSet_ServerTimeZone = fieldDefJSONArrayServerTimeZone.at(0);
    fieldObj_ServerTimeZone = fieldSet_ServerTimeZone.toObject();
    ServerTimeZone = fieldObj_ServerTimeZone.value("value").toString();
    ServerTimeZone = "The connected crane has Locale set to - " + ServerTimeZone + " ";
    ui->label_Location->setText(ServerTimeZone);
    //QMessageBox::information(this,"Info...","Database variables updated successfully");

}
void selection::generate_scaling_lists(QJsonValue json_value)
{
    if(json_value.isObject())
    {
        QJsonObject json_obj = json_value.toObject();
        if(json_obj.contains("parameterName")||json_obj.contains("alarm_id"))
        {
            QString p,t,d;
            if(json_obj.contains("parameterName")){
                p=json_obj.value("parameterName").toString();
                t=json_obj.value("comment").toString();
                d=json_obj.value("datatype").toString();
            }
            else if(json_obj.contains("alarm_id")) {
                p=json_obj.value("alarm_id").toString();
                t=json_obj.value("db_field_name").toString();
                d=json_obj.value("type").toString();
            }
            strList_ParameterName.append(p);
            strList_ParameterType.append(d);
            strList_cmt.append(t);
            strList_ScallingFactor.append("1");
            strList_offSet.append("0");
            str_mapType[p]=d;
            str_mapCmt[p]=t;
            str_mapScale[p]="1";
            str_mapOffSet[p]="0";
        }
        else
            for(auto key:json_obj.keys())
                generate_scaling_lists(json_obj.value(key));
    }
    else if(json_value.isArray())
        for(auto k : json_value.toArray())
            generate_scaling_lists(k);
}

void selection::on_pushButton_connect_clicked()
{
    QString strIPAddress, strIPPort, strIP;
    QStringList strParts;
    bool bFlag=false;

    strIP = ui->comboBox_ConnectedIPs->currentText();
    strParts = strIP.split(":");
    strIPAddress = strParts.at(0);
    if(strParts.count()<2)
        strIPPort = DEFAULT_PORT;
    else
        strIPPort = strParts.at(1);

    if(strIPAddress.split(".").count()==4)
    {
        QHostAddress address(strIPAddress);
        if(QAbstractSocket::IPv4Protocol==address.protocol())
        {
            bFlag= true;
        }
        else if(QAbstractSocket::IPv6Protocol==address.protocol())
        {
            bFlag= true;
        }
        else
        {
            QMessageBox::information(this,"Warning","Not a Valid IP Address");
            bFlag= false;
        }
    }
    else
    {
        QMessageBox::information(this,"Warning","Not a Valid IP Address");
        bFlag= false;
    }

    if(bFlag==true)
    {
        if(ui->comboBox_ConnectedIPs->findText(strIP,Qt::MatchExactly) == -1)
        {
            //Save to local disk here
        }
        ConnectToIp_Port(strIPAddress,strIPPort);
    }
}
void selection::on_comboBox_ConnectedIPs_currentTextChanged(const QString &arg1)
{
    if(enable == true){
        //ui->label_locale->clear();
        m_pingThread->exit();
        //===========tree combx===========
        rootObj = QJsonObject();
        on_pshBtn_clearParams_clicked();
        fillData();
        ui->treeWidget_ParameterTimeValue->clear();
        //==========compitator=============
        SearchComboboxlist->clear();
        SearchComboboxlistDiscreate->clear();
        //==========Databases=============
        ui->comboBox_databases->clear();
        //===========Scaling============
        strList_ParameterName.clear();
        strList_cmt.clear();
        strList_ParameterType.clear();
        strList_ScallingFactor.clear();
        str_mapScale.clear();
        str_mapOffSet.clear();
        str_mapType.clear();
        str_mapCmt.clear();
        //==================================
        json_objtimeStamp = QJsonObject();  // added 04/09/23 to clear graph
        ui->customPlot->clearGraphs();
        ui->customPlot->setBackground(Qt::white);
        //====================================
        ui->PshBtn_search->setEnabled(false);
        ui->PshBtn_PLot->setEnabled(false);

        //    ui->radioButton_x_axis->setEnabled(false);
        //    ui->radioButton_y_axis->setEnabled(false);
        //    ui->radioButton_y_axis2->setEnabled(false);

        ui->cmbBx_Type->setEnabled(false);
        ui->m_PshBtn_SavedPlots->setEnabled(false);
        ui->m_PshBtn_Delete->setEnabled(false);

        ui->m_PshBtn_Save->setEnabled(false);
        ui->m_PshBtn_export->setEnabled(false);
        ui->m_PshBtn_Scaling->setEnabled(false);

        //ui->m_PshBtn_FetchDayWiseCont->setEnabled(false);
        //ui->m_PshBtn_DBMatrics->setEnabled(false);
        ui->m_PshBtn_exportcsvFrmDB->setEnabled(false);

        ui->lbl_Connection->setStyleSheet("background-color:red;");
        ui->label_Location->setText("");
        ui->label_nan->hide();
    }
}
void selection::CheckConnection()
{
    if(socket1->state() == QAbstractSocket::UnconnectedState)
    {
        socket1->connectToHost(Str_IPAddress, Str_port.toInt());
    }
    if(socket1->state() == QAbstractSocket::ConnectedState)
    {
        ui->lbl_Connection->setStyleSheet("background-color:green;");
        //ui->lbl_error_msg->setText("");
    }
    else
    {
        ui->lbl_Connection->setStyleSheet("background-color:red;");
        //ui->lbl_error_msg->setText("Connection lost");
    }
}
void selection::fillData()
{
    ui->comboBox_CriParm->setMouseTracking(true);
    ui->comboBox_CriParm->setEditable(true);

    ui->comboBoxdemo->setMouseTracking(true);
    ui->comboBoxdemo->setEditable(true);

    ui->comboBox_AndCriParm->setMouseTracking(true);
    ui->comboBox_AndCriParm->setEditable(true);

    ui->cmbx_Discreate->setMouseTracking(true);
    ui->cmbx_Discreate->setEditable(true);

    ui->cmbx_DiscreateAnd->setMouseTracking(true);
    ui->cmbx_DiscreateAnd->setEditable(true);

    ui->treeWidget_TrackTypes->clear();
    ui->treeWidget_TrackTypes->setColumnCount(2);
    ui->treeWidget_TrackTypes->setColumnWidth(0,352);
    ui->treeWidget_TrackTypes->setColumnWidth(1,0);
    ui->treeWidget_TrackTypes->setColumnHidden(1,true);

    QString json1,json2,json3;
    QList<QString> keys = rootObj.keys();
    for(auto key:keys)
    {
        QTreeWidgetItem* root = new QTreeWidgetItem();
        root->setText(0,key);
        root->setToolTip(0,key);
        traversJson_Tree(rootObj.value(key),root);
        if(root->childCount()>0){
            ui->treeWidget_TrackTypes->addTopLevelItem(root);
        }
    }

    //===================for combx====================
    SearchComboboxlist->clear();
    QStandardItemModel *m_model= new  QStandardItemModel();
    m_model->setColumnCount(2);

    for(auto key:keys)
    {
        if(key!="alarm"){
            QStandardItem * root=new QStandardItem();
            root->setText(key);
            traversJson_cmbx(rootObj.value(key),root);
            root->setSelectable(false);
            if(root->rowCount()>0)
                m_model->appendRow(root);
        }

    }
    SearchComboboxlistDiscreate->clear();
    QStandardItemModel *m_modelDiscreate = new  QStandardItemModel();
    m_modelDiscreate->setColumnCount(2);
    for(auto key:keys)
    {
        if(key!="alarm"){
            QStandardItem * root=new QStandardItem();
            root->setText(key);
            traversJson_cmbxDiscreate(rootObj.value(key),root);
            root->setSelectable(false);
            if(root->rowCount()>0)
                m_modelDiscreate->appendRow(root);
        }
    }

    QCompleter *completer1 = new QCompleter();
    completer1->setModel(SearchComboboxlist);
    completer1->popup()->setFont(QFont("ubuntu",11));
    completer1->setCaseSensitivity(Qt::CaseInsensitive);

    QCompleter *completer2 = new QCompleter();
    completer2->setModel(SearchComboboxlist);
    completer2->popup()->setFont(QFont("ubuntu",11));
    completer2->setCaseSensitivity(Qt::CaseInsensitive);

    QCompleter *completer3 = new QCompleter();
    completer3->setModel(SearchComboboxlistDiscreate);
    completer3->popup()->setFont(QFont("ubuntu",11));
    completer3->setCaseSensitivity(Qt::CaseInsensitive);

    QCompleter *completer4 = new QCompleter();
    completer4->setModel(SearchComboboxlistDiscreate);
    completer4->popup()->setFont(QFont("ubuntu",11));
    completer4->setCaseSensitivity(Qt::CaseInsensitive);

    QTreeView *tree_view1 = new QTreeView();
    tree_view1->setHeaderHidden(true);
    tree_view1->setAlternatingRowColors(true);
    tree_view1->setModel(m_model);
    tree_view1->setColumnWidth(0,ui->comboBox_CriParm->width());
    tree_view1->setColumnWidth(0,ui->comboBoxdemo->width());
    tree_view1->setColumnHidden(1,true);
    tree_view1->setMinimumHeight(200);
    tree_view1->setSortingEnabled(false);
    tree_view1->setAutoScroll(false);


        //listview->setHeaderHidden(true);
        //listview->setAlternatingRowColors(true);
        //listview->setModel(m_model);//#
        //listview->setColumnWidth(0,ui->comboBox_CriParm->width());
        //listview->setColumnWidth(0,ui->comboBoxdemo->width());
        //listview->setColumnHidden(1,true);
        //listview->setMinimumHeight(200);
        //listview->setSortingEnabled(false);
        //listview->setAutoScroll(false);


    ui->comboBox_CriParm->setEditable(true);
    ui->comboBox_CriParm->lineEdit()->setPlaceholderText("Search or Select Action....");
    ui->comboBox_CriParm->lineEdit()->setFont(QFont("ubuntu",12));
    ui->comboBox_CriParm->setInsertPolicy(QComboBox::NoInsert); // type + enter ==> no insertion in combobox
    ui->comboBox_CriParm->setView(tree_view1);
    ui->comboBox_CriParm->view()->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->comboBox_CriParm->setModel(m_model);
    ui->comboBox_CriParm->setCurrentIndex(-1);
    ui->comboBox_CriParm->setModelColumn(1);
    ui->comboBox_CriParm->setCompleter(completer1);


    ui->comboBoxdemo->setEditable(true);
    ui->comboBoxdemo->lineEdit()->setPlaceholderText("Search or Select Action....");
    ui->comboBoxdemo->lineEdit()->setFont(QFont("ubuntu",12));
    //ui->comboBoxdemo->setInsertPolicy(QComboBox::NoInsert); // type + enter ==> no insertion in combobox
    //ui->comboBoxdemo->setView(listview);
    ui->comboBoxdemo->view()->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->comboBoxdemo->addItems(listview);
    ui->comboBoxdemo->setCurrentIndex(-1);
    //ui->comboBoxdemo->setModelColumn(1);
    //ui->comboBoxdemo->setCompleter(completer1);


    QTreeView *tree_view2 = new QTreeView();
    tree_view2->setHeaderHidden(true);
    tree_view2->setAlternatingRowColors(true);
    tree_view2->setModel(m_model);
    tree_view2->setColumnWidth(0,ui->comboBox_AndCriParm->width());
    tree_view2->setColumnHidden(1,true);
    tree_view2->setMinimumHeight(200);
    tree_view2->setSortingEnabled(false);
    tree_view2->setAutoScroll(false);

    ui->comboBox_AndCriParm->setEditable(true);
    ui->comboBox_AndCriParm->lineEdit()->setPlaceholderText("Search or Select Action....");
    ui->comboBox_AndCriParm->lineEdit()->setFont(QFont("ubuntu",12));
    ui->comboBox_AndCriParm->setInsertPolicy(QComboBox::NoInsert);
    ui->comboBox_AndCriParm->setView(tree_view2);
    ui->comboBox_AndCriParm->view()->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->comboBox_AndCriParm->setModel(m_model);
    ui->comboBox_AndCriParm->setCurrentIndex(-1);
    ui->comboBox_AndCriParm->setModelColumn(1);
    ui->comboBox_AndCriParm->setCompleter(completer2);

    QTreeView *tree_view3 = new QTreeView();
    tree_view3->setHeaderHidden(true);
    tree_view3->setAlternatingRowColors(true);
    tree_view3->setModel(m_modelDiscreate);
    tree_view3->setColumnWidth(0,ui->cmbx_Discreate->width());
    tree_view3->setColumnHidden(1,true);
    tree_view3->setMinimumHeight(200);
    tree_view3->setSortingEnabled(false);
    tree_view3->setAutoScroll(false);

    ui->cmbx_Discreate->setEditable(true);
    ui->cmbx_Discreate->lineEdit()->setPlaceholderText("Search or Select Action....");
    ui->cmbx_Discreate->lineEdit()->setFont(QFont("ubuntu",12));
    ui->cmbx_Discreate->setInsertPolicy(QComboBox::NoInsert);
    ui->cmbx_Discreate->setView(tree_view3);
    ui->cmbx_Discreate->view()->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->cmbx_Discreate->setModel(m_modelDiscreate);
    ui->cmbx_Discreate->setCurrentIndex(-1);
    ui->cmbx_Discreate->setModelColumn(1);
    ui->cmbx_Discreate->setCompleter(completer3);

    QTreeView *tree_view4 = new QTreeView();
    tree_view4->setHeaderHidden(true);
    tree_view4->setAlternatingRowColors(true);
    tree_view4->setModel(m_modelDiscreate);
    tree_view4->setColumnWidth(0,ui->cmbx_DiscreateAnd->width());
    tree_view4->setColumnHidden(1,true);
    tree_view4->setMinimumHeight(200);
    tree_view4->setSortingEnabled(false);
    tree_view4->setAutoScroll(false);

    ui->cmbx_DiscreateAnd->setEditable(true);
    ui->cmbx_DiscreateAnd->lineEdit()->setPlaceholderText("Search or Select Action....");
    ui->cmbx_DiscreateAnd->lineEdit()->setFont(QFont("ubuntu",12));
    ui->cmbx_DiscreateAnd->setInsertPolicy(QComboBox::NoInsert);
    ui->cmbx_DiscreateAnd->setView(tree_view4);
    ui->cmbx_DiscreateAnd->view()->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->cmbx_DiscreateAnd->setModel(m_modelDiscreate);
    ui->cmbx_DiscreateAnd->setCurrentIndex(-1);
    ui->cmbx_DiscreateAnd->setModelColumn(1);
    ui->cmbx_DiscreateAnd->setCompleter(completer4);
}

void selection::closeEvent(QCloseEvent *event)
{
    if(m_more_status)
    {
        event->ignore();
        return;
    }

    QMessageBox::StandardButton resBtn = QMessageBox::question( this,"Datalogger",
                                                                tr("Do you want to Exit?\n"),
                                                                QMessageBox::Yes | QMessageBox::No);
    if (resBtn != QMessageBox::Yes) {
        event->ignore();
    } else {
        QSettings settings_db("Finecho_Db","Db_Details");
        settings_db.beginGroup(DBGROUP);
        settings_db.setValue(DBKEY,ui->comboBox_databases->currentText().trimmed());
        settings_db.endGroup();
        event->accept();
        m_pingThread->quit();
        QApplication::quit();
    }
}

void selection::traversJson_Tree(QJsonValue json_value,QTreeWidgetItem *tree_item)
{
    if(json_value.isObject())
    {
        QJsonObject json_obj=json_value.toObject();
        if(json_obj.contains("displayname")||json_obj.contains("alarm_id"))
        {
            QString p,t;
            QTreeWidgetItem* item=new QTreeWidgetItem();
            if(json_obj.contains("displayname")){
                p=json_obj.value("displayname").toString();
                t=json_obj.value("comment").toString();
                item->setText(1,json_obj.value("parameterName").toString());
            }
            else if(json_obj.contains("alarm_id")) {
                p=json_obj.value("alarm_id").toString();
                t=json_obj.value("db_field_name").toString();
                item->setText(1,json_obj.value("alarm_id").toString());
            }

            QFont font("Ubunut",11);
            QFontMetrics fm(font);
            QString s;
            item->setCheckState(0,Qt::Unchecked);
            item->setText(0,p+s.fill(' ',(((175-fm.width(p))/5)>0?0:(175-fm.width(p))/5)+10)+t);
            item->setToolTip(0,p+s.fill(' ',(((175-fm.width(p))/5)>0?0:(175-fm.width(p))/5)+10)+t);
            tree_item->addChild(item);
        }
        else{
            QString k=json_obj.keys()[0];
            QTreeWidgetItem *item=new QTreeWidgetItem();
            item->setText(0,k);
            traversJson_Tree(json_obj.value(k),item);
            if(item->childCount()>0)
                tree_item->addChild(item);
        }
    }
    else if(json_value.isArray())
    {
        for(auto t : json_value.toArray())
            traversJson_Tree(t,tree_item);
    }
}
void selection::traversJson_cmbx(QJsonValue json_value, QStandardItem *tree_item)
{
    if(json_value.isObject())
    {
        QJsonObject json_obj=json_value.toObject();
        if(json_obj.contains("displayname")||json_obj.contains("alarm_id")){
            if(json_obj.value("datatype")!="BOOL" && json_obj.value("type")!="BOOL")
            {
                QString p,t;
                if(json_obj.contains("displayname")){
                    p=json_obj.value("displayname").toString();
                    t=json_obj.value("comment").toString();
                    listview.append(p+t);
                }
                else if(json_obj.contains("alarm_id")) {
                    p=json_obj.value("alarm_id").toString();
                    t=json_obj.value("db_field_name").toString();
                }
                QStandardItem *item2=new QStandardItem();
                QStandardItem *item3=new QStandardItem();
                QFont font("Ubunut",11);
                QFontMetrics fm(font);
                QString s;
                item2->setText(p+s.fill(' ',(((175-fm.width(p))/5)>0?0:(175-fm.width(p))/5)+10)+t);
                item2->setToolTip(p+s.fill(' ',(((175-fm.width(p))/5)>0?0:(175-fm.width(p))/5)+10)+t);
                item3->setText(json_obj.value("parameterName").toString());
                tree_item->setChild(tree_item->rowCount(),0,item2);
                tree_item->setChild(tree_item->rowCount()-1,1,item3);

                QStandardItem *item=new QStandardItem();
                item->setText(json_obj.value("parameterName").toString());
                SearchComboboxlist->appendRow(item);
            }
        }
        else{
            QString k=json_obj.keys()[0];
            QStandardItem *item=new QStandardItem();
            item->setText(k);
            item->setSelectable(false);
            traversJson_cmbx(json_obj.value(k),item);
            if(item->rowCount()>0)
                tree_item->appendRow(item);
        }
    }
    else if(json_value.isArray())
        for(auto t : json_value.toArray())
            traversJson_cmbx(t,tree_item);
}
void selection::traversJson_cmbxDiscreate(QJsonValue json_value, QStandardItem *tree_item)
{
    if(json_value.isObject())
    {
        QJsonObject json_obj=json_value.toObject();
        if(json_obj.contains("displayname")||json_obj.contains("alarm_id")){
            if(json_obj.value("datatype")=="BOOL" || json_obj.value("type")=="BOOL")
            {
                QString p,t;
                if(json_obj.contains("displayname")){
                    p=json_obj.value("displayname").toString();
                    t=json_obj.value("comment").toString();
                    listview.append(p+t);
                }
                else if(json_obj.contains("alarm_id")) {
                    p=json_obj.value("alarm_id").toString();
                    t=json_obj.value("db_field_name").toString();
                }
                QStandardItem *item2=new QStandardItem();
                QStandardItem *item3=new QStandardItem();
                QFont font("Ubunut",11);
                QFontMetrics fm(font);
                QString s;
                item2->setText(p+s.fill(' ',(((175-fm.width(p))/5)>0?0:(175-fm.width(p))/5)+10)+t);
                item2->setToolTip(p+s.fill(' ',(((175-fm.width(p))/5)>0?0:(175-fm.width(p))/5)+10)+t);
                item3->setText(json_obj.value("parameterName").toString());
                tree_item->setChild(tree_item->rowCount(),0,item2);
                tree_item->setChild(tree_item->rowCount()-1,1,item3);

                QStandardItem *item=new QStandardItem();
                item->setText(json_obj.value("parameterName").toString());
                SearchComboboxlistDiscreate->appendRow(item);
            }
        }
        else{
            QString k=json_obj.keys()[0];
            QStandardItem *item=new QStandardItem();
            item->setText(k);
            item->setSelectable(false);
            traversJson_cmbxDiscreate(json_obj.value(k),item);
            if(item->rowCount()>0)
                tree_item->appendRow(item);
        }
    }
    else if(json_value.isArray())
        for(auto t : json_value.toArray())
            traversJson_cmbxDiscreate(t,tree_item);
}

void selection::on_timeEdit_StartTime_timeChanged(const QTime &time)
{
    ui->TimeStamp_StartTime->setTime(time);
}

void selection::on_timeEdit_EndTime_timeChanged(const QTime &time)
{
    ui->TimeStamp_EndTime->setTime(time);
}
void selection::on_timeEdit_PValueStart_timeChanged(const QTime &time)
{
    ui->Pvalue_StartdateTime->setTime(time);
}

void selection::on_timeEdit_PValueEnd_timeChanged(const QTime &time)
{
    ui->Pvalue_EnddateTime->setTime(time);
}
void selection::on_radioButton_TSEndTime_clicked()
{
    ui->TimeStamp_EndTime->setEnabled(true);
    ui->timeEdit_EndTime->setEnabled(true);
    ui->cmbBx_Etime->setEnabled(false);
    resolution(1);
}

void selection::on_radioButton_TSDurTime_clicked()
{
    ui->TimeStamp_EndTime->setEnabled(false);
    ui->timeEdit_EndTime->setEnabled(false);
    ui->cmbBx_Etime->setEnabled(true);
    QString strSel = ui->cmbBx_Etime->currentText();
    on_cmbBx_Etime_currentIndexChanged(strSel);
}
void selection::on_End_PvradioBtn_clicked()
{
    ui->Pvalue_EnddateTime->setEnabled(true);
    ui->timeEdit_PValueEnd->setEnabled(true);
    ui->cmbBx_EtimeDur->setEnabled(false);
}

void selection::on_Dur_PvradioBtn_clicked()
{
    ui->Pvalue_EnddateTime->setEnabled(false);
    ui->timeEdit_PValueEnd->setEnabled(false);
    ui->cmbBx_EtimeDur->setEnabled(true);
}
void selection::on_TimeStamp_EndTime_dateTimeChanged(const QDateTime &dateTime) //====
{
    QDateTime CurrentEndDurDateTime = QDateTime::currentDateTime();
    if(dateTime > CurrentEndDurDateTime)
    {
        //ui->TimeStamp_EndTime->setStyleSheet("background-color:red");
    }
    resolution(1);
}

void selection::on_TimeStamp_StartTime_dateTimeChanged(const QDateTime &dateTime) //=====
{
    QString strSel = ui->cmbBx_Etime->currentText();
    on_cmbBx_Etime_currentIndexChanged(strSel);
}
void selection::on_Pvalue_StartdateTime_dateTimeChanged(const QDateTime &dateTime)
{
    QString strSel = ui->cmbBx_EtimeDur->currentText();
    on_cmbBx_EtimeDur_currentIndexChanged(strSel);
}
void selection::on_cmbBx_Etime_currentIndexChanged(const QString &arg1)
{
    if(arg1 == "1 minute")
    {
        CurrentDurDateTime = ui->TimeStamp_StartTime->dateTime().addSecs(60);
    }
    else if(arg1 == "5 minutes")
    {
        CurrentDurDateTime = ui->TimeStamp_StartTime->dateTime().addSecs(5 * 60);
    }
    else if(arg1 == "10 minutes")
    {
        CurrentDurDateTime = ui->TimeStamp_StartTime->dateTime().addSecs(10 * 60);
    }
    else if(arg1 == "30 minutes")
    {
        CurrentDurDateTime = ui->TimeStamp_StartTime->dateTime().addSecs(30 * 60);
    }
    else if(arg1 == "1 hour")
    {
        CurrentDurDateTime = ui->TimeStamp_StartTime->dateTime().addSecs(60 * 60);
    }
    else if(arg1 == "4 hours")
    {
        CurrentDurDateTime = ui->TimeStamp_StartTime->dateTime().addSecs(4 * 60 * 60);
    }
    else if(arg1 == "8 hours")
    {
        CurrentDurDateTime = ui->TimeStamp_StartTime->dateTime().addSecs(8 * 60 * 60);
    }
    else
    {
        CurrentDurDateTime = ui->TimeStamp_StartTime->dateTime().addSecs(1 * 60);
    }

    QString eTime = CurrentDurDateTime.toString("dd MMM yyyy hh:mm:ss");
    ui->label_TSDur->setText(eTime);

    resolution(1);
}
void selection::on_cmbBx_EtimeDur_currentIndexChanged(const QString &arg1)
{
    if(arg1 == "2 hours")
    {
        PvalCurrentDurDateTime = ui->Pvalue_StartdateTime->dateTime().addSecs(2 * 60 * 60);
    }
    else if(arg1 == "4 hours")
    {
        PvalCurrentDurDateTime = ui->Pvalue_StartdateTime->dateTime().addSecs(4 * 60 * 60);
    }
    else if(arg1 == "8 hours")
    {
        PvalCurrentDurDateTime = ui->Pvalue_StartdateTime->dateTime().addSecs(8 * 60 * 60);
    }
    else if(arg1 == "1 day")
    {
        PvalCurrentDurDateTime = ui->Pvalue_StartdateTime->dateTime().addDays(1);
    }
    else if(arg1 == "1 week")
    {
        PvalCurrentDurDateTime = ui->Pvalue_StartdateTime->dateTime().addDays(7);
    }
    else if(arg1 == "1 month")
    {
        PvalCurrentDurDateTime = ui->Pvalue_StartdateTime->dateTime().addMonths(1);
    }
    else if(arg1 == "2 months")
    {
        PvalCurrentDurDateTime = ui->Pvalue_StartdateTime->dateTime().addMonths(2);
    }
    else if(arg1 == "6 months")
    {
        PvalCurrentDurDateTime = ui->Pvalue_StartdateTime->dateTime().addMonths(6);
    }
    else
    {
        PvalCurrentDurDateTime = ui->Pvalue_StartdateTime->dateTime().addSecs(1 * 60 * 60);
    }

    QString eTime = PvalCurrentDurDateTime.toString("dd MMM yyyy hh:mm:ss");
    ui->label_TSDurPv->setText(eTime);
    QDateTime PvalCurrentEndDateTime = QDateTime::currentDateTime();
    if(PvalCurrentEndDateTime < PvalCurrentDurDateTime)
    {
        ui->label_TSDurPv->setStyleSheet("color:red");
    }
    else
    {
        ui->label_TSDurPv->setStyleSheet("color:black");
    }
}

void selection::on_cmbBx_Samples_currentTextChanged(const QString &value)
{
    resolution(1);
}

void selection::on_cmbBx_Samples_currentIndexChanged(const QString &value)
{
    resolution(1);
}
void selection::resolution(int iBand)
{
    double secondsDiff=0;
    double samples=0.0;
    QString strSamples = "0";

    if(iBand == 1)
    {
        QDateTime StartDateTime;
        QDateTime EndDateTime;

        StartDateTime = ui->TimeStamp_StartTime->dateTime();
        if(ui->radioButton_TSEndTime->isChecked())
        {
            EndDateTime = ui->TimeStamp_EndTime->dateTime();
            secondsDiff = StartDateTime.secsTo(EndDateTime); // (added 07-05-2023)
        }
        if(ui->radioButton_TSDurTime->isChecked())
        {
            QString strEtime;
            strEtime = ui->label_TSDur->text();
            EndDateTime = QDateTime::fromString(strEtime, "dd MMM yyyy hh:mm:ss");
            secondsDiff = StartDateTime.secsTo(EndDateTime)+1;  //Plus 1 to include the last second (added 07-05-2023)
        }
        // secondsDiff = StartDateTime.secsTo(EndDateTime);  //Plus 1 to include the last second (cmt 07-05-2023)

        samples=0.0;
        strSamples = ui->cmbBx_Samples->currentText().trimmed();
        if(strSamples != "")
            samples = ui->cmbBx_Samples->currentText().toFloat();
    }
    else if (iBand == 2)
    {
        secondsDiff = ui->lineEdit_Before->text().toFloat();
        secondsDiff += ui->lineEdit_After->text().toFloat();
        //strSamples = ui->cmbBx_SamplesPv->currentText().trimmed();
        //if(strSamples != "")
        //samples = ui->cmbBx_SamplesPv->currentText().toFloat();
    }
    double secondsDiffDivVal = 0.0;
    QString rsln;
    rslnUpdate.clear();
    if(samples != 0.0)
        secondsDiffDivVal = (secondsDiff) / samples;
    double value;
    ui->label_Samples->clear();
    if(secondsDiffDivVal <= 0)
    {
        value = 0;
        rsln = "?";
    }
    else if(secondsDiffDivVal < 1.0)
    {
        value = secondsDiffDivVal * 1000 ;
        rsln = QString::number(value).append(" ms");

    }
    else if(secondsDiffDivVal < 60.0)
    {
        value = secondsDiffDivVal;
        rsln = QString::number(value).append(" s");

    }
    else if(secondsDiffDivVal < 3600.0)
    {
        int valueMin = static_cast<int>(secondsDiffDivVal) / 60;
        int valueSec = static_cast<int>(secondsDiffDivVal) % 60;
        rsln = QString::number(valueMin).append(" m ").append(QString::number(valueSec)).append(" s");

    }
    else if(secondsDiffDivVal >= 3600.0)
    {
        int valueSec = static_cast<int>(secondsDiffDivVal) % 60;
        int valueMin = static_cast<int>(secondsDiffDivVal-valueSec) / 60;
        int valueHrs = valueMin / 60;
        valueMin = valueMin % 60;
        rsln = QString::number(valueHrs).append(" h ").append(QString::number(valueMin)).append(" m ").append(QString::number(valueSec)).append(" s");
    }

    if(iBand == 1){
        ui->label_Samples->setText(rsln.prepend("Res "));
        rslnUpdate = rsln;
    }
    if(iBand == 2){
        // ui->label_SamplesPv->setText(rsln.prepend("Res "));
    }
}
//================rotate============
void selection::rotate()
{
    int total_count_arr;
    if(socket->bytesAvailable())
    {
        QJsonParseError json_error;
        QByteArray data;
        int iBytes=0;
        for(int m=0; m < waitFor; m++){
            socket->waitForReadyRead(1000);
            iBytes = socket->bytesAvailable();
            if(iBytes==0)
            {
                break;
            }
            else
            {
                data += socket->readAll();
            }
            usleep(100000);
        }

        QJsonDocument loadDoc(QJsonDocument::fromJson(data, &json_error));
        if (json_error.error != QJsonParseError::NoError)
        {
            qDebug() << "JSON parse error: "<< json_error.errorString();
        }

        QJsonObject rootObj = loadDoc.object();
        // qDebug() << "rootObj===" << rootObj;
        QJsonArray fieldDefTimeStampJSONArray = rootObj.value("field").toArray();
        total_count_arr = rootObj.value("total_count").toArray()[0].toInt();

        str_Timestampvals.clear();
        QJsonArray fieldSet;
        QJsonObject fieldObj,fieldObj_count;

        for(int i=0; i< fieldDefTimeStampJSONArray.size(); i++)
        {
            fieldSet = fieldDefTimeStampJSONArray.at(i).toArray();
            str_Timestampvals << fieldSet.at(0).toString();
        }
        m_rotation = number_rotations;
    }
    if(number_rotations > m_rotation){
        QPixmap pixmap(*m_wait_label->pixmap());
        QTransform tr;
        tr.rotate(90);
        pixmap = pixmap.transformed(tr);
        m_wait_label->setPixmap(pixmap);

        m_wait_label->setGeometry(this->width()/2-75,this->height()/2-75,150,150);
        m_time_label->setGeometry(this->width()/2-95,this->height()/2+80,230,30);
        m_cancel_button->setGeometry(this->width()/2+95,this->height()/2+80,50,30);

        m_rotation++;
        m_time_label->setText("Wait for : "+QString::number(float((number_rotations-m_rotation))/10,'f',1)+" Sec");
    }
    else{
        m_rotation = 0;
        m_timer->stop();
        socket->close();

        QList<QWidget*> k = ui->tabWidget->findChildren<QWidget*>();
        for(auto i:k)
            i->setEnabled(true);

        ui->comboBox_ConnectedIPs->setEnabled(true);
        ui->pushButton_connect->setEnabled(true);
        ui->pushButton_about->setEnabled(true);
        ui->comboBox_databases->setEnabled(true);

        m_wait_label->setVisible(false);
        m_time_label->setVisible(false);
        m_cancel_button->setVisible(false);

        QTreeWidgetItem *widgetItem;
        QString strTS;
        int row =0;
        ui->treeWidget_ParameterTimeValue->clear();
        ui->treeWidget_ParameterTimeValue->setSelectionMode(QAbstractItemView::SingleSelection);
        ui->treeWidget_ParameterTimeValue->setColumnCount(1);

        while(row < str_Timestampvals.length())
        {
            widgetItem = new QTreeWidgetItem(ui->treeWidget_ParameterTimeValue);
            widgetItem->setText(0, str_Timestampvals.at(row));
            widgetItem->setToolTip(0, str_Timestampvals.at(row));
            // widgetItem->setCheckState(0, Qt::Unchecked);
            ui->treeWidget_ParameterTimeValue->insertTopLevelItem(row, widgetItem);
            row++;
        }
        if(row==0)
        {
            QString message = QString( "No match for given criteria in the selected time range");
            QMessageBox::information(this,"No Match Found!", message );
            ui->lbl_TSCount->setText("0");
        }else{
            ui->tabWidget->setCurrentIndex(1);
            selectedItemsClicked(showSelectedParmsinSearch);
            if(total_count_arr > 500){
                ui->lbl_TSCount->setText(" First 500 timestamps are shown");
            }else{
                ui->lbl_TSCount->setText(QString::number(total_count_arr));
            }
        }
    }
}

void selection::on_cancel_button_clicked()
{
    number_rotations = m_rotation;
}

void selection::on_PshBtn_search_clicked()
{
    if(ui->comboBox_CriParm->currentText() == "" && ui->comboBox_AndCriParm->currentText() == "" && ui->cmbx_Discreate->currentText() == "" && ui->cmbx_DiscreateAnd->currentText() == "")
    {
        QMessageBox msgBox;
        msgBox.setText("Select at least one parameter.");
        msgBox.exec();
        return;
    }

    if(ui->comboBoxdemo->currentText() == "" && ui->comboBox_AndCriParm->currentText() == "" && ui->cmbx_Discreate->currentText() == "" && ui->cmbx_DiscreateAnd->currentText() == "")
    {
        QMessageBox msgBox;
        msgBox.setText("Select at least one parameter.");
        msgBox.exec();
        return;
    }


    QDateTime startDateTime;
    QString sDTime,eDTime ;
    QJsonDocument jsonDoc;
    startDateTime = ui->Pvalue_StartdateTime->dateTime();
    sDTime =  startDateTime.toString("yyyy-MM-dd hh:mm:ss");

    QDateTime endDateTime;
    if(ui->End_PvradioBtn->isChecked())
    {
        endDateTime = ui->Pvalue_EnddateTime->dateTime();
        eDTime =  endDateTime.toString("yyyy-MM-dd hh:mm:ss");

    }
    if(ui->Dur_PvradioBtn->isChecked())
    {
        QString strEtime;
        strEtime = ui->label_TSDurPv->text();
        endDateTime = QDateTime::fromString(strEtime, "dd MMM yyyy hh:mm:ss");
        eDTime =  endDateTime.toString("yyyy-MM-dd hh:mm:ss");

    }
    //==========================================================
    QString strParam1, strVal1, strParam2, strVal2;
    QString strOper1, strOper2;

    if(ui->comboBox_CriParm->currentText() != "" && ui->comboBox_CriOpr->currentText() != "" && ui->lineEdit_Parm->text() != "")
    {
        strVal1 = ui->lineEdit_Parm->text();
        strParam1 = ui->comboBox_CriParm->currentText();
        strParam1 = strParam1.section(" ", 0, 0);
        strOper1 = ui->comboBox_CriOpr->currentText();
    }

    if(ui->comboBoxdemo->currentText() != "" && ui->comboBox_CriOpr->currentText() != "" && ui->lineEdit_Parm->text() != "")
    {
        strVal1 = ui->lineEdit_Parm->text();
        strParam1 = ui->comboBoxdemo->currentText();
        strParam1 = strParam1.section(" ", 0, 0);
        strOper1 = ui->comboBox_CriOpr->currentText();
    }

    if(ui->comboBox_AndCriParm->currentText() != "" && ui->comboBox_AndCriOpr->currentText() != "" && ui->lineEdit_AndParm->text() != "")
    {
        strVal2 = ui->lineEdit_AndParm->text();

        strParam2 = ui->comboBox_AndCriParm->currentText();
        strParam2 = strParam2.section(" ", 0, 0);

        strOper2 = ui->comboBox_AndCriOpr->currentText();

    }

    //==========================================================
    QString  strTrue, strFalse;
    QStringList strLstTrueParams,strLstFalseParams,strLstRisingTrigger,strLstFallingTrigger;
    strTrue = ui->cmbx_Discreate->currentText();
    strFalse = ui->cmbx_DiscreateAnd->currentText();

    if(ui->cmbx_Discreate->currentText() != "" && ui->cmbx_Discreate->currentText() != "CART" ){
        if(ui->comboBox_true->currentText() == "True")
        {
            strLstTrueParams << strTrue;
        }
        else
        {
            strLstFalseParams << strTrue;
        }
    }

    if(ui->cmbx_DiscreateAnd->currentText() != "" && ui->cmbx_DiscreateAnd->currentText() != "CART" ){
        if(ui->comboBox_false->currentText() == "True")
        {
            strLstTrueParams << strFalse;
        }
        else
        {
            strLstFalseParams << strFalse;
        }
    }
    showSelectedParmsinSearch.clear();
    showSelectedParmsinSearch << strParam1;
    showSelectedParmsinSearch << strParam2;
    showSelectedParmsinSearch << strLstTrueParams;
    showSelectedParmsinSearch << strLstFalseParams;

    //===================================================================
    QJsonObject jsonAPI,jsonKeys;
    QJsonArray jsonArray,plot_array;
    jsonKeys.insert("username","sateesh");
    jsonKeys.insert("passcode","123456");
    jsonKeys.insert("authkey","abcd");
    jsonKeys.insert("endpoint","fetchTimestamps");
    QJsonArray param_array,param_names_array,param_true,param_false,param_Alarms,param_RaisingTrigger,param_FallingTrigger;

    if(ui->comboBox_CriParm->currentText() != "" && ui->comboBox_CriParm->currentText() != "CART")
    {
        auto data2 = QJsonObject(
        {
                        qMakePair(QString("name"), QJsonValue(strParam1)),
                        qMakePair(QString("operation"), QJsonValue(strOper1)),
                        qMakePair(QString("value"), QJsonValue(strVal1))
                    });
        param_names_array.push_back(QJsonValue(data2));
    }

    if(ui->comboBoxdemo->currentText() != "" && ui->comboBoxdemo->currentText() != "CART")
    {
        auto data2 = QJsonObject(
        {
                        qMakePair(QString("name"), QJsonValue(strParam1)),
                        qMakePair(QString("operation"), QJsonValue(strOper1)),
                        qMakePair(QString("value"), QJsonValue(strVal1))
                    });
        param_names_array.push_back(QJsonValue(data2));
    }

    if(ui->comboBox_AndCriParm->currentText() != "" && ui->comboBox_AndCriParm->currentText() != "CART")
    {
        auto data3 = QJsonObject(
        {
                        qMakePair(QString("name"), QJsonValue(strParam2)),
                        qMakePair(QString("operation"), QJsonValue(strOper2)),
                        qMakePair(QString("value"), QJsonValue(strVal2))
                    });
        param_names_array.push_back(QJsonValue(data3));
    }


    for (int i=0;i < strLstTrueParams.length();i++)
    {
        param_true.append(strLstTrueParams.at(i));
    }

    for (int i=0;i < strLstFalseParams.length();i++)
    {
        param_false.append(strLstFalseParams.at(i));
    }

    for (int i=0;i < strLstRisingTrigger.length();i++)
    {
        param_RaisingTrigger.append(strLstRisingTrigger.at(i));
    }

    for (int i=0;i < strLstFallingTrigger.length();i++)
    {
        param_FallingTrigger.append(strLstFallingTrigger.at(i));
    }

    auto data1 = QJsonObject(
    {
                    qMakePair(QString("start_time"), QJsonValue(sDTime)),
                    qMakePair(QString("end_time"), QJsonValue(eDTime)),
                    qMakePair(QString("dbname"), QJsonValue(dbName)),
                    qMakePair(QString("param_names"), QJsonArray(param_names_array)),
                    qMakePair(QString("boolTrue"), QJsonArray(param_true)),
                    qMakePair(QString("boolFalse"), QJsonArray(param_false)),
                    qMakePair(QString("rising"), QJsonArray(param_RaisingTrigger)),
                    qMakePair(QString("falling"), QJsonArray(param_FallingTrigger))
                });

    plot_array.push_back(QJsonValue(data1));

    jsonKeys.insert("params",QJsonValue(plot_array));

    jsonArray.append(jsonKeys);

    jsonDoc = QJsonDocument(jsonArray);
    //qDebug() << "fetchTimestamps===" << jsonDoc;
    //=========================================
    QDateTime s = startDateTime;
    QDateTime t = endDateTime;
    waitFor = s.secsTo(t);
    waitFor = (waitFor/3600)*3 + 1; // 60*60 = 3600
    if(waitFor < 30)
    {
        waitFor = 30;
    }
    QString waitSec = QString::number(waitFor);
    //qDebug()<< "Waiting for" << waitFor;

    m_rotation = 0;
    number_rotations = waitFor*10;

    socket->connectToHost(Str_IPAddress,Str_port.toInt());
    if(socket->waitForConnected(10000))
    {
        socket->write(jsonDoc.toJson().constData());
        socket->waitForBytesWritten(3000);
        str_Timestampvals.clear();

        QList<QWidget*> k = ui->tabWidget->findChildren<QWidget*>();
        for(auto i:k)
            i->setEnabled(false);

        ui->comboBox_ConnectedIPs->setEnabled(false);
        ui->pushButton_connect->setEnabled(false);
        ui->pushButton_about->setEnabled(false);
        ui->comboBox_databases->setEnabled(false);

        m_wait_label->setVisible(true);
        m_time_label->setVisible(true);
        m_cancel_button->setVisible(true);
        m_timer->start(100);
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("Error: " + socket->errorString() + "\nPlease Check connectivity to server");
        msgBox.exec();
        //ui->lbl_error_msg->setText("ERROR: " + socket->errorString() );
        ui->lbl_Connection->setStyleSheet("background-color:red;");
        return;
    }

}
void selection::selectedItemsClicked(QStringList selectedItems)
{
    on_pshBtn_clearParams_clicked();
    QTreeWidgetItemIterator item(ui->treeWidget_TrackTypes);
    while(*item) {
        if(selectedItems.contains((*item)->text(1)) && (*item)->text(1)!="")
        {
            (*item)->setCheckState(0,Qt::Checked);
            //selectedItems.removeOne((*t)->text(1));
        }
        item++;
    }
}
void selection::on_lineEdit_Before_textChanged(const QString &arg1)
{
    QDateTime tsDateTime,startDateTime,endDateTime;
    if(SelectedTimeStamp == ""){
        return;
    }
    if(ui->radioButton_TSDurTime->isChecked()){
        ui->radioButton_TSDurTime->setChecked(false);
        ui->radioButton_TSEndTime->setChecked(true);
    }
    if(SelectedTimeStamp.length()==19)
        SelectedTimeStamp += ".000";
    else if(SelectedTimeStamp.length()==20)
        SelectedTimeStamp += "000";
    else if(SelectedTimeStamp.length()==21)
        SelectedTimeStamp += "00";
    else if(SelectedTimeStamp.length()==22)
        SelectedTimeStamp += "0";

    tsDateTime = QDateTime::fromString(SelectedTimeStamp, "yyyy-MM-dd hh:mm:ss.zzz");

    startDateTime = tsDateTime.addSecs(-1*(ui->lineEdit_Before->text().toInt()));

    endDateTime = tsDateTime.addSecs(ui->lineEdit_After->text().toInt());

    ui->TimeStamp_StartTime->setDateTime(startDateTime);
    ui->timeEdit_StartTime->setTime(startDateTime.time());

    ui->TimeStamp_EndTime->setDateTime(endDateTime);
    ui->timeEdit_EndTime->setTime(endDateTime.time());
}

void selection::on_lineEdit_After_textChanged(const QString &arg1)
{
    QDateTime tsDateTime,startDateTime,endDateTime;
    if(SelectedTimeStamp == ""){
        return;
    }
    if(ui->radioButton_TSDurTime->isChecked()){
        ui->radioButton_TSDurTime->setChecked(false);
        ui->radioButton_TSEndTime->setChecked(true);
    }
    if(SelectedTimeStamp.length()==19)
        SelectedTimeStamp += ".000";
    else if(SelectedTimeStamp.length()==20)
        SelectedTimeStamp += "000";
    else if(SelectedTimeStamp.length()==21)
        SelectedTimeStamp += "00";
    else if(SelectedTimeStamp.length()==22)
        SelectedTimeStamp += "0";

    tsDateTime = QDateTime::fromString(SelectedTimeStamp, "yyyy-MM-dd hh:mm:ss.zzz");

    startDateTime = tsDateTime.addSecs(-1*(ui->lineEdit_Before->text().toInt()));

    endDateTime = tsDateTime.addSecs(ui->lineEdit_After->text().toInt());

    ui->TimeStamp_StartTime->setDateTime(startDateTime);
    ui->timeEdit_StartTime->setTime(startDateTime.time());

    ui->TimeStamp_EndTime->setDateTime(endDateTime);
    ui->timeEdit_EndTime->setTime(endDateTime.time());
}
void selection::on_treeWidget_ParameterTimeValue_itemClicked(QTreeWidgetItem *item, int column)
{
    if(ui->radioButton_TSDurTime->isChecked()){
        ui->radioButton_TSDurTime->setChecked(false);
        ui->radioButton_TSEndTime->setChecked(true);
    }
    QDateTime tsDateTime,startDateTime,endDateTime;
    SelectedTimeStamp = ui->treeWidget_ParameterTimeValue->currentItem()->text(ui->treeWidget_ParameterTimeValue->currentColumn());

    if(SelectedTimeStamp.length()==19)
        SelectedTimeStamp += ".000";
    else if(SelectedTimeStamp.length()==20)
        SelectedTimeStamp += "000";
    else if(SelectedTimeStamp.length()==21)
        SelectedTimeStamp += "00";
    else if(SelectedTimeStamp.length()==22)
        SelectedTimeStamp += "0";

    tsDateTime = QDateTime::fromString(SelectedTimeStamp, "yyyy-MM-dd hh:mm:ss.zzz");

    startDateTime = tsDateTime.addSecs(-1*(ui->lineEdit_Before->text().toInt()));

    endDateTime = tsDateTime.addSecs(ui->lineEdit_After->text().toInt());

    ui->TimeStamp_StartTime->setDateTime(startDateTime);
    ui->timeEdit_StartTime->setTime(startDateTime.time());

    ui->TimeStamp_EndTime->setDateTime(endDateTime);
    ui->timeEdit_EndTime->setTime(endDateTime.time());
}

void selection::saveParams_clicked()
{
    strSelectedAlams.clear();
    strSelectedParams.clear();
    strSelectedAlams = getParamandAlarm("alarm");
    strSelectedParams = getParamandAlarm("CART");
    //qDebug() << "strAlams==="<< strSelectedAlams <<  "strLstVal===" << strSelectedParams;
}
QStringList selection::getParamandAlarm(QString s)
{
    QStringList r;
    if(s=="alarm")
        for(auto item:m_checked)
        {
            if(item->parent()->text(0)=="alarm")
                r.append(item->text(1));
        }
    else
        for(auto item:m_checked)
        {
            if(item->parent()->text(0)!="alarm")
                r.append(item->text(1));
        }
    return r;
}
void selection::on_PshBtn_PLot_clicked()
{
    //==================================Added frequency loging====================
    QJsonParseError json_error_db;
    QByteArray data_db;
    QJsonDocument loadDoc_db;
    QJsonObject jsonKeys;
    QJsonArray jsonArray;
    dbName = ui->comboBox_databases->currentText().trimmed();
    jsonKeys.insert("username","rushikesh");
    jsonKeys.insert("passcode","123456");
    jsonKeys.insert("authkey","abcd");
    jsonKeys.insert("dbname",dbName);
    jsonKeys.insert("endpoint","getFrequency");
    jsonArray.append(jsonKeys);
    auto jsonDoc = QJsonDocument(jsonArray);

    socket->connectToHost(Str_IPAddress, Str_port.toInt());
    if(socket->waitForConnected(10000))
    {
        socket->write(jsonDoc.toJson().constData());
        socket->waitForBytesWritten(30000);
        socket->waitForReadyRead(3000);
        data_db = socket->readAll();
        loadDoc_db = QJsonDocument::fromJson(data_db, &json_error_db);
    }

    QJsonObject rootObj_db = loadDoc_db.object();
    QString freq = rootObj_db.value("frequency").toString();
    if(rslnUpdate.split(" ").at(1) == "?"){
        QMessageBox msgBox;
        msgBox.setText("Resolution is invalid");
        msgBox.exec();
        return;
    }
    if(rslnUpdate.split(" ").at(2) == "ms"){
        QString rslnnum = rslnUpdate.split(" ").at(1);
        if(rslnnum.toFloat() < freq.toFloat())
        {
            int nCreateFlag = 0;
            QMessageBox qmsgMessageBox;
            nCreateFlag = qmsgMessageBox.warning(this,"Frequency!","Resolution is less than data arrival frequency.\nThere may be gap in the plot.\nDo you want to continue?.. ",QMessageBox::Yes, QMessageBox::No);

            if(nCreateFlag == QMessageBox::Yes)
            {

            }else
            {
                return;
            }
        }
    }
    socket->close();
    //===========================================================================
    ui->label_Samples_2->setText(rslnUpdate);
    savePlot = true;
    saveParams_clicked();
    // qDebug() << "SelectedTimeStamp==" << SelectedTimeStamp << str_Timestampvals.length();
    if(SelectedTimeStamp != "" && str_Timestampvals.length() > 0)
    {
        QStringList strParams;
        QStringList strLstOfSelectedAlarmItems = strSelectedAlams;
        QList<QDateTime> lstTS,lstTS_sel;
        QDateTime tsDateTime;
        //==========added=======
        QString str_timestamp;
        for(int i=0; i < str_Timestampvals.length(); i++)
        {
            if(str_Timestampvals.at(i).length() == 19)
            {
                str_timestamp = str_Timestampvals.at(i);
                str_timestamp += ".000";
            }
            else if(str_Timestampvals.at(i).length() == 20)
            {
                str_timestamp = str_Timestampvals.at(i);
                str_timestamp += "000";
            }
            else if(str_Timestampvals.at(i).length() == 21)
            {
                str_timestamp = str_Timestampvals.at(i);
                str_timestamp += "00";
            }
            else if(str_Timestampvals.at(i).length() == 22)
            {
                str_timestamp = str_Timestampvals.at(i);
                str_timestamp += "0";
            }
            lstTS.push_back(QDateTime::fromString(str_timestamp, "yyyy-MM-dd hh:mm:ss.zzz"));
        }
        if(SelectedTimeStamp.length()==19)
            SelectedTimeStamp += ".000";
        else if(SelectedTimeStamp.length()==20)
            SelectedTimeStamp += "000";
        else if(SelectedTimeStamp.length()==21)
            SelectedTimeStamp += "00";
        else if(SelectedTimeStamp.length()==22)
            SelectedTimeStamp += "0";

        int strBefore,strAfter;
        if(ui->lineEdit_Before->text() == ""){
            strBefore = 30;
        }else{
            strBefore = ui->lineEdit_Before->text().toInt();
        }

        if(ui->lineEdit_After->text() == ""){
            strAfter = 30;
        }else{
            strAfter = ui->lineEdit_After->text().toInt();
        }

        lstTS_sel.push_back(QDateTime::fromString(SelectedTimeStamp, "yyyy-MM-dd hh:mm:ss.zzz"));
        //tsDateTime = QDateTime::fromString(SelectedTimeStamp, "yyyy-MM-dd hh:mm:ss.zzz");
        //startDateTime = tsDateTime.addSecs(-1*(strBefore));
        //endDateTime = tsDateTime.addSecs(strAfter);

        QDateTime startDateTime,endDateTime;
        startDateTime = ui->TimeStamp_StartTime->dateTime();

        if(ui->radioButton_TSEndTime->isChecked())
        {
            endDateTime = ui->TimeStamp_EndTime->dateTime();
        }
        if(ui->radioButton_TSDurTime->isChecked())
        {
            QString strEtime;
            strEtime = ui->label_TSDur->text();
            endDateTime = QDateTime::fromString(strEtime, "dd MMM yyyy hh:mm:ss");
        }
        QString strSamples = ui->cmbBx_Samples->currentText().trimmed();
        strParams << strSelectedParams;
        if(strParams.count() + strLstOfSelectedAlarmItems.count() <= 0)
        {
            QMessageBox msgBox;
            msgBox.setText("Select at least one parameter to plot.");
            msgBox.exec();
            return;
        }

        QJsonObject recordImportObj;
        QString Export = "";
        //qDebug() << "lstTS===="<< lstTS << lstTS.length() << "lstTS_sel====" <<lstTS_sel << lstTS_sel.length();
        //qDebug() << startDateTime << endDateTime <<  strParams << strLstOfSelectedAlarmItems << lstTS << lstTS_sel << ui->comboBox_CriParm->currentText().section(" ", 0, 0);
        paraTimeSlot(startDateTime, endDateTime, strParams,strLstOfSelectedAlarmItems, strSamples,lstTS,lstTS_sel,ui->comboBox_CriParm->currentText().section(" ", 0, 0),recordImportObj,Export);
        paraTimeSlot(startDateTime, endDateTime, strParams,strLstOfSelectedAlarmItems, strSamples,lstTS,lstTS_sel,ui->comboBoxdemo->currentText().section(" ", 0, 0),recordImportObj,Export);

        SelectedTimeStamp.clear();
        ui->treeWidget_ParameterTimeValue->clearSelection();
    }
    else
    {
        QStringList strLstOfSelectedAlarmItems = strSelectedAlams;
        QStringList strLstOfSelectedParamsItems = strSelectedParams;
        //qDebug() << "strSelectedParams===" << strSelectedParams;
        if(strLstOfSelectedParamsItems.count() + strLstOfSelectedAlarmItems.count() <= 0)
        {
            QMessageBox msgBox;
            msgBox.setText("Select at least one parameter to plot.");
            msgBox.exec();
            return;
        }

        QDateTime startDateTime;
        startDateTime = ui->TimeStamp_StartTime->dateTime();

        QDateTime endDateTime;
        if(ui->radioButton_TSEndTime->isChecked())
        {
            endDateTime = ui->TimeStamp_EndTime->dateTime();
        }
        if(ui->radioButton_TSDurTime->isChecked())
        {
            QString strEtime;
            strEtime = ui->label_TSDur->text();
            endDateTime = QDateTime::fromString(strEtime, "dd MMM yyyy hh:mm:ss");
        }
        QString strSamples = ui->cmbBx_Samples->currentText().trimmed();
        QList<QDateTime> lstTS,lstTS_sel;
        QJsonObject recordImportObj;
        QString Export = "";
        paraTimeSlot(startDateTime,endDateTime,strLstOfSelectedParamsItems,strLstOfSelectedAlarmItems,strSamples,lstTS,lstTS_sel,"",recordImportObj,Export);
    }

}

//===========================================================
//===========================================================
void selection::paraTimeSlot(QDateTime sDate, QDateTime eDate, QStringList selParams,QStringList selAlarms,
                             QString strSamples,QList<QDateTime> lst_CriteriaTS,
                             QList<QDateTime> lst_CriteriaTS_sel, QString strTSParamCriteria,QJsonObject recordImportObj,QString Export)
{
    if(ui->cmbBx_SavedGroup->currentText() == "===None===") //=========23/01/24=====
    {
        //==============scaling===================================
        QSettings settings("Finecho_Scaling","Scaling_Details");
        settings.beginGroup(SCALING);
        foreach (const QString &key, settings.childKeys())
        {
            QString k_val = key;
            QString value = settings.value(key).toString();
            str_mapScaleReval.insert(k_val,value);
        }
        settings.endGroup();

        QMap<QString, QString>::iterator iterator = str_mapScale.begin();
        QMap<QString, QString>::iterator iterator1 = str_mapScaleReval.begin();
        while (iterator1 != str_mapScaleReval.end())
        {
            if (str_mapScale.contains(iterator1.key().simplified()))
            {
                str_mapScale[iterator1.key().simplified()] = str_mapScaleReval.value(iterator1.key());
            }
            ++iterator1;
        }
        //==============offSet===================================
        QSettings settings_offset("Finecho_offset","offset_Details");
        settings_offset.beginGroup(OFFSET);
        foreach (const QString &key, settings_offset.childKeys())
        {
            QString k_val = key;
            QString value = settings_offset.value(key).toString();
            str_mapOffSetReval.insert(k_val,value);
        }
        settings_offset.endGroup();

        // QMap<QString, QString>::iterator iterator = str_mapOffSet.begin();
        QMap<QString, QString>::iterator iterator_OffSet = str_mapOffSetReval.begin();
        while (iterator_OffSet != str_mapOffSetReval.end())
        {
            if (str_mapOffSet.contains(iterator_OffSet.key().simplified()))
            {
                str_mapOffSet[iterator_OffSet.key().simplified()] = str_mapOffSetReval.value(iterator_OffSet.key());
            }
            ++iterator_OffSet;
        }
    }
    //=====================================================
    //=====================================================
    lstCriteriaTS.clear();
    lstCriteriaTS_sel.clear();

    exportedJsonData = recordImportObj;
    findExportData = Export;
    lstCriteriaTS = lst_CriteriaTS;
    lstCriteriaTS_sel = lst_CriteriaTS_sel;
    strParamCriteria = strTSParamCriteria;

    //Update member variables
    sDateTime = QDateTime::fromString(sDate.toString("yyyy-MM-dd hh:mm:ss"), "yyyy-MM-dd hh:mm:ss");
    eDateTime = QDateTime::fromString(eDate.toString("yyyy-MM-dd hh:mm:ss"), "yyyy-MM-dd hh:mm:ss");

    dPlotStart = sDateTime;
    dPlotEnd = eDateTime;
    QString sTmeDte = dPlotStart.toString("dd-MMM-yyyy hh:mm:ss.zzz");
    QString eTmeDte = dPlotEnd.toString("dd-MMM-yyyy hh:mm:ss.zzz");
    ui->label_StartTime->setText(sTmeDte);
    ui->label_Etime->setText(eTmeDte);

    ui->cmbBx_Samples->setCurrentText(strSamples);

    strLstOfSelectedParams.clear();
    strLstOfSelectedAlarms.clear();

    strLstOfSelectedParams << selParams;
    strLstOfSelectedAlarms << selAlarms;
    // selectedItemsTobeClicked();
    drawGraph();

    ui->cmbBx_SavedGroup->setCurrentIndex(0); //============19/01/24=============

    QGraphicsOpacityEffect * effect = new QGraphicsOpacityEffect(ui->label_sel);
    effect->setOpacity(0.2);
    ui->label_sel->setGraphicsEffect(effect);

    ui->label_sel->resize(0,0);
    ui->label_sel->setVisible(false);

}

void selection::drawGraph()
{
    bNaNPresent = false;
    QJsonArray keyValueArray;
    QString strTime, strMs, strVal;
    double dVal, fLow, fHigh;
    QDateTime dTime;
    QVector<double> xData, yData, eData, sData;
    int i,j,jCriteriaParam=-1;

    int iRed[10] =   {255,255,128,000,000,128,128,000,255,000};
    int iGreen[10] = {128,000,255,255,128,000,128,255,000,000};
    int iBlue[10] =  {000,128,000,128,255,255,000,255,255,000};

    QString sTime = sDateTime.toString("yyyy-MM-dd hh:mm:ss.zzz"); // added .zzz 23/01/2024
    QString eTime = eDateTime.toString("yyyy-MM-dd hh:mm:ss.zzz"); // added .zzz 23/01/2024

    if(findExportData == "")
    {
        json_objtimeStamp = GetDataFromTimestamp();
        //qDebug() << "json_objtimeStamp===" << json_objtimeStamp << json_objtimeStamp.value("Data").toInt();
        if(json_objtimeStamp.value("Data") == "0")
        {
            QString message = QString( "There is no data for given timestamp...");
            QMessageBox::information(this,"Plot!", message );
            return;
        }
        else
        {
            if(savePlot == true)
            {
                QString plot = "PLOT-" + QString::number(tempPlots);
                ui->cmbBx_Type->insertItem(0,plot);
                ui->cmbBx_Type->setCurrentIndex(0);

                ip_port << Str_IPAddress+Str_port;
                dbnames << dbName;
                plots << plot;
                plotsJson << json_objtimeStamp;
                pStartDateTime << sTime;
                pEndDateTime << eTime;
                pSelectedParms << strLstOfSelectedParams;
                pSelectedAlarms << strLstOfSelectedAlarms;
                // pSelectedAllDate << lstCriteriaTS;
                pSelectedDate << lstCriteriaTS_sel;
                pSelectedCreParam << strParamCriteria;
                tempPlots++;
            }
        }
    }else
    {
        json_objtimeStamp = exportedJsonData; // To draw Import Graph and saved plots without calling API
        importGraph_savedPlot_backgroundChange = true;  // To change backround color for Import Graph and saved plots.
    }
    ui->customPlot->clearGraphs();
    ui->customPlot->replot();

    ui->customPlot->legend->setVisible(true);
    ui->customPlot->legend->setFont(QFont("Helvetica", 7));
    ui->customPlot->legend->setMaximumSize(100,100);

    QPen pen;
    QJsonObject json = json_objtimeStamp;
    //qDebug() << "json====" << json;

    double dX, dBitBaseOffset=-2, dOffset;  // [dOffset=0] 04/10/2021
    keyValueArray = json.value("x").toArray();
    for(i=0; i<keyValueArray.size(); i++)
    {
        strTime = keyValueArray.at(i).toString();
        strTime[10]=' ';    //remove the T in the returned time stamp"

        if(strTime.length()==19)
            strTime += ".000";
        else if(strTime.length()==20)
            strTime += "000";
        else if(strTime.length()==21)
            strTime += "00";
        else if(strTime.length()==22)
            strTime += "0";

        strMs = strTime.right(3);
        dTime = QDateTime::fromString(strTime, "yyyy-MM-dd hh:mm:ss.zzz");
        xData.push_back(dTime.toTime_t() + strMs.toFloat()/1000.0);
        //qDebug() << "xData====" << xData;
    }
    j=0;
    fLow=0;fHigh=0;

    if(findExportData != "IMPORT_GRAPH")
    {
        foreach (const QString& key, json.keys())
        {
            yData.clear();

            if(key != "x" && key != "Data")
            {
                keyValueArray = json.value(key).toArray();
                dX = str_mapScale.value(key).toDouble();
                if(dX == 0)
                    dX = 1;
                // dOffset = str_mapOffSet.value(key).toDouble();    //[] 04/10/2021

                if(str_mapType.value(key)=="BOOL" || str_mapAlarmType.value(key)=="BOOL" )
                {
                    dBitBaseOffset = dBitBaseOffset+2;
                    dOffset = dBitBaseOffset;
                }
                else
                {
                    dOffset = str_mapOffSet.value(key).toDouble();   // [dOffset = 0] 04/10/2021
                }
                for(i=0; i < keyValueArray.size(); i++)
                {
                    strVal = keyValueArray.at(i).toString();
                    if( strVal != "NaN" && strVal != "")
                    {
                        dVal = strVal.toFloat();
                        dVal = dOffset + dVal * dX;
                        yData.push_back(dVal);
                        fLow = dVal < fLow ? dVal : fLow;
                        fHigh = dVal > fHigh ? dVal : fHigh;
                    }
                    else
                    {
                        yData.push_back(qQNaN());
                        bNaNPresent = true;
                    }
                }

                if(str_mapType.value(key)=="BOOL" || str_mapAlarmType.value(key)=="BOOL" )
                {
                    ui->customPlot->addGraph(ui->customPlot->xAxis, ui->customPlot->yAxis2);
                    if(str_mapType.value(key)=="BOOL")
                        ui->customPlot->graph(j)->setName(QString::number(dOffset)+" "+key);
                    else
                        ui->customPlot->graph(j)->setName(QString::number(dOffset)+" "+ "Alarm-" +key);
                }
                else
                {
                    ui->customPlot->addGraph();
                    ui->customPlot->graph(j)->setName(key+","+QString::number(dX)+","+QString::number(dOffset));
                }

                int iR, iG, iB;

                iR = iRed[j%10];
                iG = iGreen[j%10];
                iB = iBlue[j%10];

                QPen qP(QColor(iR, iG, iB));
                qP.setWidth(3);
                ui->customPlot->graph(j)->setPen(qP);
                //if(str_mapType.value(key) != "BOOL")
                // ui->customPlot->graph(j)->setBrush(QBrush(QColor(iR, iG, iB, 20)));
                //qDebug() << "yData==" << yData << yData.length();
                ui->customPlot->graph(j)->setData(xData, yData);

                if(key.toStdString() == strParamCriteria.toStdString())
                    jCriteriaParam = j;

                j++;
            }
        }
    }else{  // to draw export graph parameter along with alram values.
        foreach (const QString& key, json.keys())
        {
            yData.clear();

            if(key != "x" && key != "Data")
            {
                keyValueArray = json.value(key).toArray();
                dX = str_mapExportScale.value(key).toDouble();
                if(dX == 0)
                    dX = 1;
                // dOffset = str_mapOffSet.value(key).toDouble();    //[] 04/10/2021

                if(str_mapExportType.value(key)=="BOOL")
                {
                    dBitBaseOffset = dBitBaseOffset+2;
                    dOffset = dBitBaseOffset;
                }
                else
                {
                    dOffset = str_mapExportOffSet.value(key).toDouble();   // [dOffset = 0] 04/10/2021
                }
                for(i=0; i < keyValueArray.size(); i++)
                {
                    strVal = keyValueArray.at(i).toString();
                    if( strVal != "NaN" && strVal != "")
                    {
                        dVal = strVal.toFloat();
                        dVal = dOffset + dVal * dX;
                        yData.push_back(dVal);
                        fLow = dVal < fLow ? dVal : fLow;
                        fHigh = dVal > fHigh ? dVal : fHigh;
                    }
                    else
                    {
                        yData.push_back(qQNaN());
                        bNaNPresent = true;
                    }
                }

                if(str_mapExportType.value(key)=="BOOL")
                {
                    ui->customPlot->addGraph(ui->customPlot->xAxis, ui->customPlot->yAxis2);
                    if(str_mapExportType.value(key)=="BOOL")
                        ui->customPlot->graph(j)->setName(QString::number(dOffset)+" "+key);
                    else
                        ui->customPlot->graph(j)->setName(QString::number(dOffset)+" "+ "Alarm-" +key);
                }
                else
                {
                    ui->customPlot->addGraph();
                    ui->customPlot->graph(j)->setName(key+","+QString::number(dX)+","+QString::number(dOffset));
                }

                int iR, iG, iB;

                iR = iRed[j%10];
                iG = iGreen[j%10];
                iB = iBlue[j%10];

                QPen qP(QColor(iR, iG, iB));
                qP.setWidth(3);
                ui->customPlot->graph(j)->setPen(qP);
                //if(str_mapType.value(key) != "BOOL")
                // ui->customPlot->graph(j)->setBrush(QBrush(QColor(iR, iG, iB, 20)));
                //qDebug() << "yData==" << yData << yData.length();
                ui->customPlot->graph(j)->setData(xData, yData);

                if(key.toStdString() == strParamCriteria.toStdString())
                    jCriteriaParam = j;

                j++;
            }
        }
    }
    // Highlight points as errorpoints
    if(jCriteriaParam >= 0)
    {
        QCPErrorBars *errorBars_sel;
        errorBars_sel = new QCPErrorBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
        double dPoint_sel;
        QString strPoint,strPoint_sel;

        errorBars_sel->removeFromLegend();
        errorBars_sel->setWhiskerWidth(0);
        errorBars_sel->setSymbolGap(15);

        QPen pn;
        pn.setColor(QColor(Qt::green));
        pn.setWidth(3);
        errorBars_sel->setPen(pn);

        errorBars_sel->setDataPlottable(ui->customPlot->graph(jCriteriaParam));
        //Now, add points to be highlighted as error data
        sData.push_back(0); // to correct the selected point , now it is showing one sample before
        //=================selected==========
        for(int iX=1; iX < xData.size(); iX++)
        {
            for( i=0; i<lstCriteriaTS_sel.size(); i++)
            {
                strPoint_sel = lstCriteriaTS_sel.at(i).toString("yyyy-MM-dd hh:mm:ss.zzz");
                strMs = strPoint_sel.right(3);
                dTime = lstCriteriaTS_sel.at(i);
                dPoint_sel = dTime.toTime_t() + strMs.toFloat()/1000.0;

                if( (dPoint_sel > xData.at(iX-1)) && (dPoint_sel <= xData.at(iX)) )
                    break;
            }
            if(i < lstCriteriaTS_sel.size())
                sData.push_back((fHigh-fLow)*0.1);
            else
                sData.push_back(0);
        }
        errorBars_sel->setData(sData);
    }

    // set locale to english, so we get english month names:
    ui->customPlot->setLocale(QLocale(QLocale::English, QLocale::UnitedKingdom));

    // configure bottom axis to show date instead of number:
    QSharedPointer<QCPAxisTickerDateTime> dateTicker(new QCPAxisTickerDateTime);
    dateTicker->setDateTimeFormat("dd-MMM-yy\n hh:mm:ss.zzz");
    dateTicker->setTickCount(12);
    ui->customPlot->xAxis->setTicker(dateTicker);
    ui->customPlot->xAxis->setLabel("Time");
    ui->customPlot->xAxis->ticker()->setTickCount(6);
    //Left axis
    ui->customPlot->yAxis->setLabel("Scaled Values");

    //Right axis
    //ui->customPlot->yAxis2->setTicker(1)
    ui->customPlot->yAxis2->setLabel("Bit Value");
    ui->customPlot->yAxis2->setVisible(true);
    ui->customPlot->yAxis2->setTickLength(3,3);


    // set a more compact font size for bottom and left axis tick labels:
    ui->customPlot->xAxis->setTickLabelFont(QFont(QFont().family(), 8));
    ui->customPlot->yAxis->setTickLabelFont(QFont(QFont().family(), 12));
    ui->customPlot->yAxis2->setTickLabelFont(QFont(QFont().family(), 12));

    //ui->customPlot->rescaleAxes();
    fLow = fLow > 0 ? fLow*0.8 : fLow * 1.2;
    fHigh = fHigh < 0 ? fHigh*0.8 : fHigh*1.2;
    ui->customPlot->yAxis->setRange(fLow, fHigh);

    if(dBitBaseOffset<6)
        ui->customPlot->yAxis2->setRange(0, 6);
    else
        ui->customPlot->yAxis2->setRange(0,dBitBaseOffset+2);

    //ui->customPlot->xAxis->setRange(sDateTime.toTime_t(), eDateTime.toTime_t());
    double dS, dE;
    dS = sDateTime.toTime_t();
    strMs = sDateTime.toString("zzz");
    dS = dS + strMs.toFloat()/1000.0;
    dE = eDateTime.toTime_t();
    strMs = eDateTime.toString("zzz");
    dE = dE + strMs.toFloat()/1000.0;
    ui->customPlot->xAxis->setRange(dS, dE);

    //    ui->customPlot->xAxis->rescale(true);
    //    ui->customPlot->update();
    //    ui->customPlot->xAxis->setRange(0,keyValueArray.size());
    //================================
    if(importGraph_savedPlot_backgroundChange == true)
    {
        ui->customPlot->setBackground(QColor(238, 238, 236));
        importGraph_savedPlot_backgroundChange = false;
    }else{
        ui->customPlot->setBackground(Qt::white);
    }
    //================================
    if(bNaNPresent == true)
    {
        ui->label_nan->show();
        str_Nan = "Time stamps are the actual timestamps within the resolution. Where there is no data in the log the timestamps are equispaced as per the resolution.";
        ui->label_nan->setText(str_Nan);
    }else{
        ui->label_nan->hide();
    }
    ui->customPlot->replot();

    if(ui->radioButton_x_axis->isChecked())
        on_radioButton_x_axis_clicked();
    else if(ui->radioButton_y_axis->isChecked())
        on_radioButton_y_axis_clicked();
    else
    {
        ui->radioButton_x_axis->setChecked(true);
        on_radioButton_x_axis_clicked();
    }
    ui->tabWidget->setCurrentIndex(2);
}

QJsonObject selection::GetDataFromTimestamp()
{
    QJsonObject recordObj;
    QStringList listParams,listAlarms;
    int i, iInterval;

    QString strQuery;

    i = ui->cmbBx_Samples->currentText().toInt();
    i = i <=0 ? 1 : i;
    iInterval = (eDateTime.toTime_t() - sDateTime.toTime_t())*1000 / i;

    //qDebug() << "iInterval==" << iInterval;

    listParams = strLstOfSelectedParams;
    listAlarms = strLstOfSelectedAlarms;
    //=====================================================
    QString sDTime =  sDateTime.toString("yyyy-MM-dd hh:mm:ss.zzz"); // added .zzz 23/01/2024
    QString eDTime =  eDateTime.toString("yyyy-MM-dd hh:mm:ss.zzz"); // added .zzz 23/01/2024

    QJsonObject jsonKeys;
    QJsonArray jsonArray,param_names_array,param_names_alrams,plot_array;

    jsonKeys.insert("username","sateesh");
    jsonKeys.insert("passcode","123456");
    jsonKeys.insert("authkey","abcd");
    jsonKeys.insert("endpoint","fetchValues");

    for (int i=0;i < listParams.length();i++)
    {
        param_names_array.append(listParams.at(i));
    }
    for (int i=0;i < listAlarms.length();i++)
    {
        param_names_alrams.append(listAlarms.at(i));
    }
    auto data1 = QJsonObject(
    {
                    qMakePair(QString("start_time"), QJsonValue(sDTime)),
                    qMakePair(QString("end_time"), QJsonValue(eDTime)),
                    qMakePair(QString("dbname"), QJsonValue(dbName)),
                    qMakePair(QString("skip"), QJsonValue(iInterval)),
                    qMakePair(QString("param_names"), QJsonArray(param_names_array)),
                    qMakePair(QString("param_alarms"), QJsonArray(param_names_alrams))
                });

    plot_array.push_back(QJsonValue(data1));

    jsonKeys.insert(QString("params"), QJsonValue(plot_array));

    jsonArray.append(jsonKeys);

    auto jsonDoc = QJsonDocument(jsonArray);
    //qDebug() << "fetchValues===" << jsonDoc;
    socket->connectToHost(Str_IPAddress, Str_port.toInt());
    if(socket->waitForConnected(10000))
    {
        ui->lbl_Connection ->setStyleSheet("background-color:green;");
        socket->write(jsonDoc.toJson().constData());
        socket->waitForBytesWritten(30000);

        QJsonParseError json_error;
        QByteArray data;

        int iBytes=0;
        for(int m=0; m<500; m++)
        {
            socket->waitForReadyRead(3000);
            QApplication::setOverrideCursor(Qt::WaitCursor);
            iBytes = socket->bytesAvailable();
            if(socket->state() != QAbstractSocket::ConnectedState)
            {
                QApplication::setOverrideCursor(Qt::ArrowCursor);
                break;
            }
            data += socket->readAll();
            usleep(50000);
        }
        //===========================================
        QJsonDocument loadDoc(QJsonDocument::fromJson(data, &json_error));
        if (json_error.error != QJsonParseError::NoError)
        {

        }
        recordObj = loadDoc.object();
        socket->close();
    }
    else
    {
        //ui->lbl_Server->setText("ERROR: " + socket->errorString()+" " + ui->lbl_Server->text());
        ui->lbl_Connection->setStyleSheet("background-color:red;");
    }
    //qDebug() << "recordObj===" << recordObj;
    return recordObj;

}

void selection::on_radioButton_x_axis_clicked()
{
    ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
    ui->customPlot->axisRect()->setRangeDrag( Qt::Horizontal);
    //  ui->customPlot->axisRect()->setRangeZoom(Qt::Horizontal );
    ui->customPlot->axisRect()->setRangeZoom(nullptr);
}
void selection::on_radioButton_y_axis_clicked()
{
    ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
    ui->customPlot->axisRect()->setRangeDrag( Qt::Vertical);
    ui->customPlot->axisRect()->setRangeZoom(Qt::Vertical );
    ui->customPlot->axisRect()->setRangeDragAxes(ui->customPlot->xAxis,ui->customPlot->yAxis);
    ui->customPlot->axisRect()->setRangeZoomAxes(ui->customPlot->xAxis,ui->customPlot->yAxis);
}
void selection::on_radioButton_y_axis2_clicked()
{
    ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
    ui->customPlot->axisRect()->setRangeDrag( Qt::Vertical);
    ui->customPlot->axisRect()->setRangeZoom(Qt::Vertical );
    ui->customPlot->axisRect()->setRangeDragAxes(ui->customPlot->xAxis,ui->customPlot->yAxis2);
    ui->customPlot->axisRect()->setRangeZoomAxes(ui->customPlot->xAxis,ui->customPlot->yAxis2);
}
void selection::xAxisChanged(QCPRange range)
{

    dPlotStart = QDateTime::fromMSecsSinceEpoch(range.lower*1000);
    dPlotEnd = QDateTime::fromMSecsSinceEpoch(range.upper*1000);

    ui->label_StartTime->setText(dPlotStart.toString("dd-MMM-yyyy hh:mm:ss.zzz"));
    ui->label_Etime->setText(dPlotEnd.toString("dd-MMM-yyyy hh:mm:ss.zzz"));

    resolution();
}
void selection::resolution()
{
    double secondsDiff=0;
    double samples=0.0;
    QString strSamples = "0";

    secondsDiff = dPlotStart.secsTo(dPlotEnd);  //The plus 1 is not needed as the times are truncated of milli and micro secs
    samples=0.0;
    strSamples = ui->cmbBx_Samples->currentText().trimmed();
    if(strSamples != "")
        samples = ui->cmbBx_Samples->currentText().toFloat();

    double secondsDiffDivVal = 0.0;

    if(samples != 0.0)
        secondsDiffDivVal = (secondsDiff) / samples;
    double value;
    // ui->label_Samples->clear();
    QString rsln;
    if(secondsDiffDivVal <= 0)
    {
        value = 0;
        rsln = "?";
    }
    else if(secondsDiffDivVal < 1.0)
    {
        value = secondsDiffDivVal * 1000 ;
        rsln = QString::number(value).append(" ms");
    }
    else if(secondsDiffDivVal < 60.0)
    {
        value = secondsDiffDivVal;
        rsln = QString::number(value).append(" s");
    }
    else if(secondsDiffDivVal < 3600.0)
    {
        int valueMin = static_cast<int>(secondsDiffDivVal) / 60;
        int valueSec = static_cast<int>(secondsDiffDivVal) % 60;
        rsln = QString::number(valueMin).append(" m ").append(QString::number(valueSec)).append(" s");
    }
    else if(secondsDiffDivVal >= 3600.0)
    {
        int valueSec = static_cast<int>(secondsDiffDivVal) % 60;
        int valueMin = static_cast<int>(secondsDiffDivVal-valueSec) / 60;
        int valueHrs = valueMin / 60;
        valueMin = valueMin % 60;
        rsln = QString::number(valueHrs).append(" h ").append(QString::number(valueMin)).append(" m ").append(QString::number(valueSec)).append(" s");
    }
    ui->label_Samples_2->setText(rsln.prepend("Res "));
}

void selection::mousePress(QMouseEvent *event)
{
    if(event->button()==Qt::RightButton)
    {
        QLabel *qSel;

        selStartX = event->x();
        selStartY = event->y();

        qSel = ui->label_sel;
        qSel->move(selStartX, selStartY);
        ui->label_sel->resize(0,0);
        qSel->setVisible(true);
    }
}

void selection::mouseMove(QMouseEvent *event)
{
    if(event->buttons()==Qt::RightButton)           //For mouse move, use buttons() method, not button(), as per Qt documentation
    {
        long l, h;

        l = event->x();
        h = event->y();

        if( (l<selStartX) || (h < selStartY) )
            return;

        l = l - selStartX;
        h = h - selStartY;

        QLabel *qSel;
        qSel = ui->label_sel;
        qSel->resize(l,h);
    }

    int x = ui->customPlot->xAxis->pixelToCoord(event->pos().x());
    int y = ui->customPlot->yAxis->pixelToCoord(event->pos().y());
    int z = ui->customPlot->yAxis2->pixelToCoord(event->pos().y());

    // setToolTip(QString("%1 , %2 , %3").arg(x).arg(y).arg(z));

    QDateTime t = QDateTime().fromTime_t(x);

    QString date = t.toString("dd-MMM-yyyy hh:mm:ss.zzz");

    ui->label_x_y->setText(QString("%1 %2 %3 %4 %5 %6").arg(" X=").arg(date).arg("Y1=").arg(y).arg("Y2=").arg(z));
}
void selection::mouseRelease(QMouseEvent *event)
{
    if(event->button()== Qt::LeftButton)
    {
        QDateTime sDate, eDate;
        QCPRange range;
        bool bFetchData;

        bFetchData=false;
        range = ui->customPlot->xAxis->range();
        sDate = QDateTime::fromMSecsSinceEpoch(range.lower*1000);
        eDate = QDateTime::fromMSecsSinceEpoch(range.upper*1000);

        if(sDate < sDateTime){
            sDateTime = sDate;
            eDateTime = eDate;
            bFetchData=true;
        }
        if(eDate > eDateTime){
            sDateTime = sDate;
            eDateTime = eDate;
            bFetchData=true;
        }
        if(bFetchData){
            savePlot = false;
            drawGraph();
        }
    }
    else if (event->button() == Qt::RightButton)
    {
        double sX, eX, sY, eY;
        QLabel *qSel;
        QPoint pRel;

        qSel = ui->label_sel;
        qSel->setVisible(false);

        eX = ui->customPlot->xAxis->pixelToCoord(event->x());
        eY = ui->customPlot->yAxis->pixelToCoord(event->y());
        sX = ui->customPlot->xAxis->pixelToCoord(selStartX);
        sY = ui->customPlot->yAxis->pixelToCoord(selStartY);

        ui->customPlot->xAxis->setRange(sX, eX);
        ui->customPlot->yAxis->setRange(sY, eY);
        ui->customPlot->replot();
    }
}

void selection::controlledZoomX(QWheelEvent *event)
{
    if(ui->radioButton_x_axis->isChecked())
    {
        QPoint mPoint;
        QPointF fPoint;
        QCPRange range;
        QCPAxisRect *qCPRect;
        double xMin, xMax, xLeft, pWidth;
        double fScale=0.1;
        int nSamples, nRes;

        qCPRect = ui->customPlot->axisRect();
        pWidth = qCPRect->width();
        range = ui->customPlot->xAxis->range();
        mPoint = event->angleDelta();
        if(mPoint.y()>0)
            fScale = 1-fScale;
        else
            fScale = 1+fScale;
        fPoint = event->posF();
        xLeft = fPoint.rx() - qCPRect->left();
        xLeft = xLeft*(1-fScale);

        xMin = range.lower+xLeft/(pWidth)*(range.upper-range.lower);

        xMax = xMin + (range.upper-range.lower)*fScale;


        nSamples = ui->cmbBx_Samples->currentText().toInt();
        nRes = (xMax-xMin)*1000/nSamples;
        //        if((nRes<SAMPLE_INTERVAL) && (fScale<1.0))
        //            return;

        ui->customPlot->xAxis->setRange(xMin, xMax);
        ui->customPlot->replot();
    }
}

void selection::yAxisChanged(QCPRange range)
{
    //ui->verticalScrollBar->setValue(qRound(-range.center()*100.0)); // adjust position of scroll bar slider
    //ui->verticalScrollBar->setPageStep(qRound(range.size()*100.0)); // adjust size of scroll bar slider
}
void selection::on_m_PshBtn_Save_clicked()
{
    QString l_file_path;

    QSettings FileSaveImageSetting("FileSaveImageSetting","PathSaveImageSetting");
    l_file_path = FileSaveImageSetting.value("FilePath_Image").toString();

    QFileDialog *object = new QFileDialog();
    QString path = "name.png";
    object->setDirectory(l_file_path);
    QString str_file = object->getSaveFileName(this, "Save as...",l_file_path+QDir::separator()+path,"PNG (*.png);; BMP (*.bmp);;TIFF (*.tiff *.tif);; JPEG (*.jpg *.jpeg)");
    if(str_file == ""){
        return;
    }
    FileSaveImageSetting.setValue("FilePath_Image",str_file);
    ui->customPlot->grab().save(str_file);
}

void selection::createFile()
{
    QJsonObject json = json_objtimeStamp;
    QStringList strlst,strcmt,strOffset,strParamtype,strParamAlaramtype;
    foreach (const QString& key, json.keys())
    {
        if(key != "x")
        {
            strlst << str_mapScale.value(key);
            strOffset << str_mapOffSet.value(key);
            strcmt << str_mapCmt.value(key);
            QString str = str_mapType.value(key);
            if(str == "")
            {
                QString str_alarm = "BOOL";
                strParamtype << str_alarm;
            }
            else
            {
                strParamtype << str;
            }
        }
        else
        {
            QString strscale = "ScalingFactor";
            QString strofst = "OffSet";
            QString strComment = "Comment";
            QString strparamalarmtype = "Type";
            strlst << strscale;
            strOffset << strofst;
            strcmt << strComment;
            strParamtype << strparamalarmtype;
        }
    }
    QStringList lstparams = json.keys();
    teleFile.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text | QIODevice::ReadWrite);
    QTextStream out(&teleFile);
    for(int i = lstparams.length()-1; i >= 0;i--)
    {
        if(lstparams.at(i) != "Data"){
            out << lstparams.at(i) << " ," ;
        }
    }
    out << endl;
    for(int i = strParamtype.length()-1; i >= 0;i--)
    {
        if(lstparams.at(i) != "Data"){
            out << strParamtype.at(i) << " ," ;
        }
    }
    out << endl;
    for(int i = strlst.length()-1; i >= 0;i--)
    {
        if(lstparams.at(i) != "Data"){
            out << strlst.at(i) << " ," ;
        }
    }
    out << endl;
    for(int i = strOffset.length()-1; i >= 0;i--)
    {
        if(lstparams.at(i) != "Data"){
            out << strOffset.at(i) << " ," ;
        }
    }
    out << endl;
    for(int i = strcmt.length()-1; i >= 0;i--)
    {
        if(lstparams.at(i) != "Data"){
            out << strcmt.at(i) << " ," ;
        }
    }
    out << endl;
    out.flush();
    teleFile.close();
}

void selection::on_m_PshBtn_export_clicked()
{
    QJsonObject json = json_objtimeStamp;
    if(json.isEmpty())
    {
        QMessageBox msgBox;
        msgBox.setText("No data to export.                   ");
        msgBox.exec();
        return;
    }

    QString l_file_path,strVal;
    QSettings FileExportSetting("FileExportSetting","PathExportSetting");
    l_file_path = FileExportSetting.value("FilePath").toString();

    QFileDialog *object = new QFileDialog();
    QString path = "Exported_Plotdata.csv";
    object->setDirectory(l_file_path);
    QString str_file = object->getSaveFileName(this, "Save as...",l_file_path+QDir::separator()+path, "CSV files (*.csv)");
    if(str_file == ""){
        return;
    }
    FileExportSetting.setValue("FilePath",str_file);
    teleFile.setFileName(str_file);
    if (!teleFile.exists())
    {
        createFile();
    }else{
        teleFile.open(QFile::WriteOnly|QFile::Truncate);
        teleFile.close();
        createFile();
    }

    teleFile.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text);
    QTextStream out(&teleFile);
    QStringList lstparams = json.keys();
    if(lstparams.length() == 0){
        return;
    }
    QJsonArray keyValueArray = json.value("x").toArray();
    int x;
    for(x=0; x < keyValueArray.size(); x++)
    {
        listval.clear();
        foreach (const QString& key, json.keys())
        {
            if(key != "Data"){
                QJsonArray keyValueArray = json.value(key).toArray();
                strVal = keyValueArray.at(x).toString();
                if(strVal == "NaN")
                {
                    strVal = " ";
                }
                listval << strVal;
            }
        }
        for(int i=listval.length()-1; i >= 0; i--)
        {
            out << listval.at(i) << ",";
        }
        out << "\n";
    }
    //    if(bNaNPresent == true){
    //        out << str_Nan << endl ;
    //    }
    out.flush();
    teleFile.close();
}

void selection::on_cmbBx_Type_currentIndexChanged(const QString &arg1)
{

}
void selection::on_m_PshBtn_SavedPlots_clicked()
{
    savePlot = false;
    QDateTime startDateTime;
    QDateTime endDateTime;
    QList<QDateTime> lstTS,lstTS_sel;
    QString parSelCre;

    QString strSamples = ui->cmbBx_Samples->currentText().trimmed();
    QList<QString> strLstOfSelectedParamsItems;
    QStringList strLstOfSelectedAlarmItems;

    QString plot = ui->cmbBx_Type->currentText();
    if(plot != ""){

        int pIndex = plots.indexOf(plot);
        //qDebug() << "pIndex==" << pIndex;
        QString sDTime = pStartDateTime.at(pIndex);
        if(sDTime.length()==19)
            sDTime += ".000";
        else if(sDTime.length()==20)
            sDTime += "000";
        else if(sDTime.length()==21)
            sDTime += "00";
        else if(sDTime.length()==22)
            sDTime += "0";
        startDateTime = QDateTime::fromString(sDTime, "yyyy-MM-dd hh:mm:ss.zzz");

        QString eDTime = pEndDateTime.at(pIndex);
        if(eDTime.length()==19)
            eDTime += ".000";
        else if(eDTime.length()==20)
            eDTime += "000";
        else if(eDTime.length()==21)
            eDTime += "00";
        else if(eDTime.length()==22)
            eDTime += "0";
        endDateTime = QDateTime::fromString(eDTime, "yyyy-MM-dd hh:mm:ss.zzz");

        strLstOfSelectedParamsItems = pSelectedParms.at(pIndex);
        strLstOfSelectedAlarmItems = pSelectedAlarms.at(pIndex);
        // qDebug() << pSelectedParms << pSelectedAlarms;

        // lstTS = pSelectedAllDate.at(pIndex);

        lstTS_sel = pSelectedDate.at(pIndex);
        parSelCre = pSelectedCreParam.at(pIndex);

        QJsonObject recordImportObj = plotsJson.at(pIndex);
        QString Export = "SAVED_PLOTS";

        paraTimeSlot(startDateTime,endDateTime,strLstOfSelectedParamsItems, strLstOfSelectedAlarmItems,strSamples,lstTS,lstTS_sel,parSelCre.trimmed(),recordImportObj,Export);
    }else{
        QMessageBox::information(this,"Warning","There is no saved plots to plot...");
    }
}

void selection::on_m_PshBtn_Delete_clicked()
{
    QString PlotName = ui->cmbBx_Type->currentText().trimmed();
    if(PlotName != ""){
        int nCreateFlag = 0;
        QMessageBox qmsgMessageBox;
        nCreateFlag = qmsgMessageBox.warning(this,"DELETE!","Do You Want to delete " + PlotName,QMessageBox::Yes, QMessageBox::No);

        if(nCreateFlag == QMessageBox::Yes)
        {
            ui->cmbBx_Type->removeItem(ui->cmbBx_Type->currentIndex());
        }
    }else{
        QMessageBox::information(this,"Warning","There is no saved plots to delete...");
    }
}

void selection::on_m_PshBtn_Scaling_clicked()
{
    m_Scaling = new Scaling(strList_ParameterName,strList_cmt,strList_ParameterType,strList_ScallingFactor,strList_offSet,Str_IPAddress,Str_port,dbName);
    QObject::connect(m_Scaling, SIGNAL(deleteGroupName(QString)), this, SLOT(deleteGroup(QString)));
    QObject::connect(m_Scaling, SIGNAL(addGroupName(QString)), this, SLOT(addGroup(QString)));
    QObject::connect(m_Scaling, SIGNAL(updateGroupName()), this, SLOT(updateGroup()));
    m_Scaling->show();
    m_Scaling->activateWindow();

    this->setEnabled(false);
    m_Scaling->setAttribute(Qt::WA_DeleteOnClose,true);
    connect(m_Scaling , &QWidget::destroyed, this,[=]()->void{
        this->setEnabled(true);
    });
}
void selection::deleteGroup(QString del_groupname)
{
    int index = ui->cmbBx_SavedGroup->findText(del_groupname);
    ui->cmbBx_SavedGroup->removeItem(index);
}
void selection::addGroup(QString add_groupname)
{
    ui->cmbBx_SavedGroup->addItem(add_groupname);
}
void selection::updateGroup()
{
    ui->cmbBx_SavedGroup->setCurrentIndex(0);
}
void selection::on_m_PshBtn_ImportGraph_clicked()
{
    QJsonArray recordArray;
    QJsonObject recordImportObj;
    QDateTime sImportDTime,eImportDTime;

    QStringList StrLstImportTimeStamps,StrLstImportParamNames,strLstOfSelectedParamsItems,strLstOfSelectedAlarmItems;
    StrLstImportTimeStamps.clear();
    StrLstImportParamNames.clear();
    strLstOfSelectedParamsItems.clear();

    QString filePath;
    QList<QByteArray> lst,lsttype,lstscale,lstoffset;
    str_mapExportType.clear();
    str_mapExportScale.clear();
    str_mapExportOffSet.clear();
    filePath  = QFileDialog::getOpenFileName(this,tr("Load From File"),"",tr("CSV file(*.csv);;"));
    if(filePath == "")
    {
        //        QMessageBox msgBox;
        //        msgBox.setText("Select exported .csv file");
        //        msgBox.exec();
        return;
    }
    //    QStringList splitter =  filePath.split("/");
    //    int nShpCnt = splitter.count() - 1;
    //    QString Path = splitter.at(nShpCnt);
    //    QString subString = Path.mid(0,24);

    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly))
    {
        qDebug() << file.errorString();
    }
    int i = 0;
    bool fline = true;
    while (!file.atEnd())
    {
        QByteArray line = file.readLine();
        StrLstImportTimeStamps.append(line.split(',').at(0));
        if(fline)
        {
            lst = line.split(',');
        }
        fline = false;
        if(i == 1)
            lsttype << line.split(',');
        if(i == 2)
            lstscale << line.split(',');
        if(i == 3)
            lstoffset << line.split(',');
        i++;
    }
    file.close();
    for (int i=0;i < lst.length();i++) {
        str_mapExportType[lst[i].simplified()] = lsttype[i].simplified();
        str_mapExportScale[lst[i].simplified()] = lstscale[i].simplified();
        str_mapExportOffSet[lst[i].simplified()] = lstoffset[i].simplified();
    }
    QString varify = lst.at(0).simplified();

    if(varify == "x")
    {
        for(int i=0; i < lst.length()-1;i++)
        {
            StrLstImportParamNames.clear();
            while (recordArray.count())
            {
                recordArray.pop_back();
            }
            if (!file.open(QIODevice::ReadOnly))
            {
                qDebug() << file.errorString();
            }
            while (!file.atEnd())
            {
                QByteArray line = file.readLine();
                StrLstImportParamNames.append(line.split(',').at(i));
            }
            for(int i=5; i < StrLstImportParamNames.length();i++)
            {
                QString str_YValues = StrLstImportParamNames.at(i);
                recordArray.push_back(str_YValues.simplified());
            }
            //qDebug() << "lst==" << lst.at(i).simplified() << "recordArray==" << recordArray;
            recordImportObj.insert(lst.at(i).simplified(),recordArray);
            //qDebug() << "recordImportObj==" << recordImportObj;
            strLstOfSelectedParamsItems << lst.at(i).simplified();
            file.close();
        }

        QString sDTime =  StrLstImportTimeStamps.at(5);
        int t =  StrLstImportTimeStamps.length() -1;
        QString eDTime =  StrLstImportTimeStamps.at(t);

        if(sDTime.length()==19)
            sDTime += ".000";
        else if(sDTime.length()==20)
            sDTime += "000";
        else if(sDTime.length()==21)
            sDTime += "00";
        else if(sDTime.length()==22)
            sDTime += "0";

        if(eDTime.length()==19)
            eDTime += ".000";
        else if(eDTime.length()==20)
            eDTime += "000";
        else if(eDTime.length()==21)
            eDTime += "00";
        else if(eDTime.length()==22)
            eDTime += "0";

        sImportDTime = QDateTime::fromString(sDTime,"yyyy-MM-dd hh:mm:ss.zzz");
        eImportDTime = QDateTime::fromString(eDTime,"yyyy-MM-dd hh:mm:ss.zzz");

        QList<QDateTime> lstTS,lstTS_sel;
        QString strSamples = ui->cmbBx_Samples->currentText().trimmed();
        QString Export = "IMPORT_GRAPH";

        paraTimeSlot(sImportDTime,eImportDTime,strLstOfSelectedParamsItems,strLstOfSelectedAlarmItems,strSamples,lstTS,lstTS_sel,"",recordImportObj,Export);
        // ui->tabWidget->setCurrentIndex(2);
        //        ui->radioButton_x_axis->setEnabled(true);
        //        ui->radioButton_y_axis->setEnabled(true);
        //        ui->radioButton_y_axis2->setEnabled(true);

        ui->m_PshBtn_Save->setEnabled(true);
        // ui->m_PshBtn_export->setEnabled(true);
    }
}

//void Selection::on_m_PshBtn_exportcsv_clicked()
//{
//    m_exportcsv = new exportcsv(Str_IPAddress,Str_port,dbName);
//    m_exportcsv->show();
//    m_exportcsv->activateWindow();
//}

void selection::on_comboBox_CriParm_currentTextChanged(const QString &arg1)
{
    ui->treeWidget_ParameterTimeValue->clear();
    on_pshBtn_clearParams_clicked();
    str_Timestampvals.clear();
    ui->lbl_TSCount->setText("0");
    SelectedTimeStamp = "";
}

void selection::on_comboBoxdemo_currentTextChanged(const QString &arg1)
{
    ui->treeWidget_ParameterTimeValue->clear();
    on_pshBtn_clearParams_clicked();
    str_Timestampvals.clear();
    ui->lbl_TSCount->setText("0");
    SelectedTimeStamp = "";
}

void selection::on_comboBox_AndCriParm_currentTextChanged(const QString &arg1)
{
    ui->treeWidget_ParameterTimeValue->clear();
    on_pshBtn_clearParams_clicked();
    str_Timestampvals.clear();
    ui->lbl_TSCount->setText("0");
    SelectedTimeStamp = "";
}

void selection::on_cmbx_Discreate_currentTextChanged(const QString &arg1)
{
    ui->treeWidget_ParameterTimeValue->clear();
    on_pshBtn_clearParams_clicked();
    str_Timestampvals.clear();
    ui->lbl_TSCount->setText("0");
    SelectedTimeStamp = "";
}

void selection::on_cmbx_DiscreateAnd_currentTextChanged(const QString &arg1)
{
    ui->treeWidget_ParameterTimeValue->clear();
    on_pshBtn_clearParams_clicked();
    str_Timestampvals.clear();
    ui->lbl_TSCount->setText("0");
    SelectedTimeStamp = "";
}

void selection::on_pushButton_about_clicked()
{
    abtPage = new about(Str_IPAddress,Str_port,dbName);
    abtPage->show();
    abtPage->activateWindow();

    m_more_status = true;

    this->setEnabled(false);
    //abtPage->setAttribute(Qt::WA_DeleteOnClose,true);
    connect(abtPage , &QWidget::destroyed, this,[=]()->void{
        this->setEnabled(true);
        m_more_status=false;});
}

void selection::on_pshbtnSearchNow_clicked()
{
    QDateTime CurrentPvStartDateTime = QDateTime::currentDateTime();
    ui->Pvalue_StartdateTime->setDateTime(CurrentPvStartDateTime);
    ui->timeEdit_PValueStart->setTime(CurrentPvStartDateTime.time());
}

void selection::on_pshbtnSelectNow_clicked()
{
    QDateTime CurrentStartDateTime = QDateTime::currentDateTime();
    ui->TimeStamp_StartTime->setDateTime(CurrentStartDateTime);
    ui->timeEdit_StartTime->setTime(CurrentStartDateTime.time());
}

void selection::on_treeWidget_TrackTypes_itemChanged(QTreeWidgetItem *item, int column)
{
    if(item->checkState(0)==Qt::Checked)
        m_checked.append(item);
    else
        m_checked.removeOne(item);
    update_flow();
}

void selection::on_treeWidget_TrackTypes_itemPressed(QTreeWidgetItem *item, int column)
{
    if(item->childCount()==0)
    {
        if(item->checkState(0) == Qt::Checked)
            item->setCheckState(0,Qt::Unchecked);
        else
            item->setCheckState(0,Qt::Checked);
    }
}
void selection::update_flow()
{
    while(ui->gridLayoutTree->count())
    {
        QWidget* widget = ui->gridLayoutTree->itemAt(0)->widget();
        if( widget )
        {
            ui->gridLayoutTree->removeWidget(widget);
            delete widget;
        }
    }
    QHBoxLayout *layout=new QHBoxLayout();
    m_row=0,m_width=0;
    for(int i=0;i<m_checked.length();i++)
    {
        QString s = "   "+m_checked[i]->text(1)+"        ";
        QFont f("ubuntu",11);
        QFontMetrics fm(f);
        int width=fm.width(s);

        QPushButton* button = new QPushButton(s);
        button->setFont(f);
        button->setFixedSize(width+15,25);
        button->setStyleSheet("QPushButton{background-image: url(:/images/delete.png);background-position:right;background-repeat:no-repeat}");
        connect(button, &QPushButton::clicked, this,[=] () -> void {
            m_checked[i]->setCheckState(0,Qt::Unchecked);
        });

        if(m_width+width > ui->scrollArea->width()-20)
        {
            QWidget *widget1= new QWidget();
            widget1->setLayout(layout);
            widget1->setFixedHeight(40);
            ui->gridLayoutTree->setRowMinimumHeight(m_row,30);
            ui->gridLayoutTree->addWidget(widget1,m_row++,0,Qt::AlignLeft);
            layout =new QHBoxLayout();
            layout->addWidget(button);
            m_width=width+10;
        }
        else
        {
            layout->addWidget(button);
            m_width=m_width+width+10;
        }
    }
    QWidget *widget1= new QWidget();
    widget1->setLayout(layout);
    ui->gridLayoutTree->addWidget(widget1,m_row,0,Qt::AlignLeft);
}
void selection::on_pshBtn_clearParams_clicked()
{
    while(m_checked.length())
        m_checked.last()->setCheckState(0,Qt::Unchecked);
}
void selection::on_m_PshBtn_exportcsvFrmDB_clicked()
{
    m_exportcsv = new exportcsv(Str_IPAddress,Str_port,dbName);
    m_exportcsv->activateWindow();
    m_exportcsv->show();

    this->setEnabled(false);
    m_exportcsv->setAttribute(Qt::WA_DeleteOnClose,true);
    connect(m_exportcsv , &QWidget::destroyed, this,[=]()->void{
        this->setEnabled(true);
    });
}

void selection::on_pushButton_clicked()
{
    QCloseEvent *event = new QCloseEvent();
    closeEvent(event);
}
