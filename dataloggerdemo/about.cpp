#include "about.h"
#include "ui_about.h"

about::about(const QString &IPAddress, const QString &Port,const QString &Db,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::about)
{
    ui->setupUi(this);
    this->setFixedSize(this->width(),this->height());
    this->setWindowTitle("About the Application");

    Str_IPAddress = IPAddress;
    Str_port = Port;
    Str_DbName = Db;
    socket = new QTcpSocket(this);
    get_versions();
}

about::~about()
{
    delete ui;
}
void about::on_tabWidget_currentChanged(int tabIndex)
{
    // qDebug() <<"the tab index is:"<< tabIndex << endl;
    if(tabIndex == 0)
    {

    }else if(tabIndex == 1)
    {

    }else if(tabIndex == 2)
    {

    }
}
void about::get_versions()
{
    QJsonObject jsonKeys;
    QJsonArray jsonArray;
    QByteArray data;
    QJsonDocument jsonDoc;

    jsonKeys.insert("username","rushikesh");
    jsonKeys.insert("passcode","finecho@178");
    jsonKeys.insert("authkey","abcd");
    jsonKeys.insert("endpoint","get_versions");
    jsonArray.append(jsonKeys);

    jsonDoc = QJsonDocument(jsonArray);
    //qDebug() << "jsonDoc===" << jsonDoc;

    socket->connectToHost(Str_IPAddress,Str_port.toInt());
    if(socket->waitForConnected(10000))
    {
        socket->write(jsonDoc.toJson().constData());
        socket->waitForBytesWritten(30000);

        QJsonParseError json_error;
        QByteArray data;

        int iBytes=0;
        for(int m=0; m<10; m++){
            socket->waitForReadyRead(20000);
            iBytes = socket->bytesAvailable();
            if(iBytes==0)
                break;

            data += socket->readAll();
            usleep(1000);
        }

        QJsonDocument loadDoc(QJsonDocument::fromJson(data, &json_error));
        if (json_error.error != QJsonParseError::NoError)
        {
            qDebug() << "JSON parse error: "<< json_error.errorString();
        }

        QJsonObject rootObj = loadDoc.object();
        QJsonArray fieldDefJSONArray = rootObj.value("field").toArray();

        QJsonValue fieldSet;
        QJsonObject fieldObj;
        QStringList strLstKeys;

        for(int i=0; i< fieldDefJSONArray.size(); i++)
        {
            fieldSet = fieldDefJSONArray.at(i);
            fieldObj = fieldSet.toObject();
            strLstKeys = fieldObj.keys();
        }
        //            if(strLstKeys.length() == 0)
        //            {
        //                QString message = QString( "No Updated version found");
        //                QMessageBox::information(this,"Versions..!", message );
        //                return;
        //            }
        // ====================================
        foreach(const QString& key, fieldObj.keys())
        {
            QJsonValue value = fieldObj.value(key);
            QString str_Vnum =  value.toArray().at(0).toString();
            QString str_Date =  value.toArray().at(1).toString();
            QString str_Rnote = value.toArray().at(2).toString();
            if(key == "plcdatacollector")
            {
                ui->pc_Vnum->setText(str_Vnum);
                ui->pc_Date->setText(str_Date);
                ui->pc_Rnote->setText(str_Rnote);
            }else if (key == "alarmdatacollector") {
                ui->adc_Vnum->setText(str_Vnum);
                ui->adc_Date->setText(str_Date);
                ui->adc_Rnote->setText(str_Rnote);
            }else if (key == "dataloggerapi") {
                ui->s_Vnum->setText(str_Vnum);
                ui->s_Date->setText(str_Date);
                ui->s_Rnote->setText(str_Rnote);
            }else if (key == "kpiloggerapi") {
                ui->kpi_Vnum->setText(str_Vnum);
                ui->kpi_Date->setText(str_Date);
                ui->kpi_Rnote->setText(str_Rnote);
            }else if (key == "kpidatacollectioncron") {
                ui->kpicron_Vnum->setText(str_Vnum);
                ui->kpicron_Date->setText(str_Date);
                ui->kpicron_Rnote->setText(str_Rnote);
            }else{
                ui->cs_Vnum->setText(str_Vnum);
                ui->cs_Date->setText(str_Date);
                ui->cs_Rnote->setText(str_Rnote);
            }
        }
        socket->close();
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("Error: " + socket->errorString() + "\nPlease Check connectivity to server");
        msgBox.exec();
        return;
    }
}

void about::on_m_PshBtn_DBMatrics_clicked()
{
    m_DB_Metrics = new DB_Metrics(Str_IPAddress,Str_port,Str_DbName);
    m_DB_Metrics->show();
    m_DB_Metrics->activateWindow();

    m_more_status = true;

    this->setEnabled(false);
    m_DB_Metrics->setAttribute(Qt::WA_DeleteOnClose,true);
    connect(m_DB_Metrics , &QWidget::destroyed, this,[=]()->void{this->setEnabled(true);
        m_more_status=false;});
}

void about::on_m_PshBtn_FetchDayWiseCont_clicked()
{
    m_DataRecord = new DataRecord(Str_IPAddress,Str_port,Str_DbName);
    m_DataRecord->show();
    m_DataRecord->activateWindow();

    m_more_status = true;

    this->setEnabled(false);
    m_DataRecord->setAttribute(Qt::WA_DeleteOnClose,true);
    connect(m_DataRecord , &QWidget::destroyed, this,[=]()->void{this->setEnabled(true);
        m_more_status=false;});
}
void about::closeEvent(QCloseEvent *event)
{
    if(m_more_status)
    {
        event->ignore();
        return;
    }
    this->close();
    this->destroyed();
}

void about::on_m_PshBtn_quickGuide_clicked()
{
    QDesktopServices::openUrl(QUrl("https://confluence.konecranes.com/display/PDL/Analyser?preview=/135973073/145011536/Datalogger%20Analyzer%20guide%20ver%201.pdf", QUrl::TolerantMode));
}

void about::on_pushButton_clicked()
{

    QCloseEvent *event = new QCloseEvent();
    closeEvent(event);
}
