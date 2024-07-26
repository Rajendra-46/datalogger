/*
FileName	:DataRecord
Purpose     :This Files is used to export the records by using CSV.
Authour     :Gururaj B M / Kasturi Rangan.
*/

#include "exportcsv.h"
#include "ui_exportcsv.h"
#include <QFileDialog>
exportcsv::exportcsv(const QString &IPAddress, const QString &Port,
                     const QString & dbName,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::exportcsv)
{
    ui->setupUi(this);
    this->setWindowTitle("Export to csv");
    Str_IPAddress = IPAddress;
    Str_port = Port;
    Str_dbName = dbName.trimmed();
    socket = new QTcpSocket(this);
    thread = new QThread(this);

    QDateTime CurrentStartDateTime = QDateTime::currentDateTime().addSecs(-5 * 60);
    ui->TimeStamp_StartTime->setDateTime(CurrentStartDateTime);
    ui->timeEdit_Start->setTime(CurrentStartDateTime.time());

    QDateTime CurrentEndDateTime = QDateTime::currentDateTime();
    ui->TimeStamp_EndTime->setDateTime(CurrentEndDateTime);
    ui->timeEdit_End->setTime(CurrentEndDateTime.time());

    connect(this, SIGNAL(dataReceived(int)), this, SLOT(processData(int)));
}

exportcsv::~exportcsv()
{
    delete ui;
}
void exportcsv::Connection_status()
{
    //qDebug() << "thread in function==" << QThread::currentThread();
    QDateTime startDateTime;
    startDateTime = ui->TimeStamp_StartTime->dateTime();
    QString sTime = startDateTime.toString("yyyy-MM-dd hh:mm:ss.zzz");
    Final_Start_Date = QDateTime::fromString(sTime,"yyyy-MM-dd hh:mm:ss.zzz");

    QDateTime endDateTime;
    endDateTime = ui->TimeStamp_EndTime->dateTime();
    QString eTime = endDateTime.toString("yyyy-MM-dd hh:mm:ss.zzz");
    Final_end_DateTime = QDateTime::fromString(eTime,"yyyy-MM-dd hh:mm:ss.zzz");

    int secs = Final_Start_Date.secsTo(Final_end_DateTime);
    float noDateIter = secs/20.00;
    float FnlValue = 100.00/noDateIter;
    // int fnl_bar_value = qRound(FnlValue);
    float FinalProgressBar_Itr_Value = 0.0;
    //=========================================
    bool check = true;

    //==================================================
    teleFile.setFileName(str_file);
    if (!teleFile.exists())
    {
        createFile();
    }
    else{
        teleFile.open(QFile::WriteOnly|QFile::Truncate);
        teleFile.close();
    }
    //=========================================
    do {
        teleFile.open(QIODevice::WriteOnly | QIODevice::ReadWrite | QIODevice::Append | QIODevice::Text);
        QTextStream out(&teleFile);

        QString startFinalDate = Final_Start_Date.toString("yyyy-MM-dd hh:mm:ss.zzz");
        QDateTime fEndDate = Final_Start_Date.addSecs(20);
        if(fEndDate > Final_end_DateTime )
        {
            fEndDate = Final_end_DateTime;
        }
        QString endFinalDate = fEndDate.toString("yyyy-MM-dd hh:mm:ss.zzz");

        QJsonObject jsonKeys;
        QJsonArray jsonArray;
        QByteArray data;
        QJsonDocument jsonDoc;

        jsonKeys.insert("username","rushikesh");
        jsonKeys.insert("passcode","finecho@178");
        jsonKeys.insert("authkey","abcd");
        jsonKeys.insert("endpoint","extractToCsv");
        jsonKeys.insert("dbname",Str_dbName);
        jsonKeys.insert("start_time",startFinalDate);
        jsonKeys.insert("end_time",endFinalDate);
        jsonArray.append(jsonKeys);

        //QJsonParseError json_error;
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
            int nobyte = 0;
            for(int m=0; m<500; m++){
                socket->waitForReadyRead(8*1024*1024);
                iBytes = socket->bytesAvailable();
                nobyte = nobyte + iBytes;
                if(iBytes==0 )
                {
                    break;
                }
                data += socket->readAll();
                //qDebug() << "nobyte===" << nobyte;
                usleep(100000);
            }

            QJsonDocument loadDoc(QJsonDocument::fromJson(data, &json_error));
            if (json_error.error != QJsonParseError::NoError)
            {
                qDebug() << "JSON parse error: "<< json_error.errorString();
            }

            QJsonObject rootObj = loadDoc.object();
            // qDebug() << "rootObj===" << rootObj;
            QJsonArray fieldDefJSONArray = rootObj.value("field").toArray();
            // qDebug() << "fieldDefJSONArray===" << fieldDefJSONArray.size();

            QJsonValue fieldSet;
            QJsonObject fieldObj;
            QStringList strLstKeys;
            int count = 0;
            for(int i=0; i< fieldDefJSONArray.size(); i++)
            {
                fieldSet = fieldDefJSONArray.at(i);
                fieldObj = fieldSet.toObject();
                strLstKeys = fieldObj.keys();
            }
            foreach(const QString& key, fieldObj.keys())
            {
                QJsonValue value = fieldObj.value(key);
                QJsonArray array = value.toArray();
                count = array.count();
                break;
            }
            if(strLstKeys.length() > 0)
            {
                if(check == true)
                {
                    for (int i =0; i <strLstKeys.length(); i++)
                    {
                        out << strLstKeys.at(i) << ",";
                    }
                    out << "\n";
                }
                check = false;
            }

            for(int i =0 ; i < count; i++)
            {
                foreach(const QString& key, fieldObj.keys())
                {
                    QJsonValue value = fieldObj.value(key);
                    QJsonArray array = value.toArray();
                    out << array.at(i).toString() << "," ;
                }
                out << endl;
            }
            teleFile.close();
            socket->close();
            Final_Start_Date = fEndDate.addMSecs(1);
        }
        FinalProgressBar_Itr_Value = FnlValue + FinalProgressBar_Itr_Value;
        if(FinalProgressBar_Itr_Value > 100)
        {
            FinalProgressBar_Itr_Value = 100;
        }
        emit dataReceived(FinalProgressBar_Itr_Value);

    } while ((Final_Start_Date < Final_end_DateTime) && close_event);
}

void exportcsv::processData(int value)
{
    ui->progressBar->setValue(value);
}

void exportcsv::on_timeEdit_Start_timeChanged(const QTime &time)
{
    ui->TimeStamp_StartTime->setTime(time);
}

void exportcsv::on_timeEdit_End_timeChanged(const QTime &time)
{
    ui->TimeStamp_EndTime->setTime(time);
}

void exportcsv::on_m_PshBtn_GetData_clicked()
{
    //qDebug() << "thread not in function==" << QThread::currentThread();
    ui->progressBar->setValue(0);
    ui->m_PshBtn_GetData->setEnabled(false);
    QString l_file_path,strVal;
    QSettings FileExportDbSetting("FileExportDbSetting","PathExportDbSetting");
    l_file_path = FileExportDbSetting.value("FilePath_ExportDb").toString();

    QFileDialog *object = new QFileDialog();
    QString path = "Exported_DBdata.csv";
    object->setDirectory(l_file_path);
    str_file = object->getSaveFileName(this, "Save as...",l_file_path+QDir::separator()+path, "CSV files (*.csv)");
    if(str_file == ""){
        QMessageBox msgBox;
        msgBox.setText("File name is empty");
        msgBox.exec();
        ui->m_PshBtn_GetData->setEnabled(true);
        return;
    }
    FileExportDbSetting.setValue("FilePath_ExportDb",str_file);
    object->close();

    //==================================
    thread = QThread::create([=](){
        Connection_status();
    });

    connect(thread,&QThread::started,[](){
        //qDebug() << "Thread started";
    });

    connect(thread,&QThread::finished,[](){
        //qDebug() << "Thread finished";
    });

    connect(thread,&QThread::finished,thread,&QThread::deleteLater);
    connect(thread,&QThread::finished,this,&exportcsv::updatePBar);

    thread->start();

}
void exportcsv::updatePBar()
{
    ui->progressBar->setValue(100);
    ui->m_PshBtn_GetData->setEnabled(true);
    this->close();
}
void exportcsv::createFile()
{
    teleFile.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text | QIODevice::ReadWrite);
    QTextStream out(&teleFile);
    teleFile.close();
}

void exportcsv::closeEvent(QCloseEvent *event)
{
    if(thread->isRunning()){
        QMessageBox::StandardButton resBtn = QMessageBox::question( this,"ExportCSV_FromDB",
                                                                    tr("Process is still running, It will take some time to close.\nDo you want to Exit?\n"),
                                                                    QMessageBox::Yes | QMessageBox::No);
        if (resBtn == QMessageBox::Yes) {
            close_event = false;
            event->ignore();
        } else {
            event->ignore();
        }
    }
    else{
        this->close();
    }
}



void exportcsv::on_pushButton_clicked()
{
    QCloseEvent *event = new QCloseEvent();
    closeEvent(event);
}
