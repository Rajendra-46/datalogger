/*
FileName	:DataRecord
Purpose     :This Files is used to see the database records.
Authour     :Gururaj B M / Kasturi Rangan.
*/

#include "datarecord.h"
#include "ui_datarecord.h"

DataRecord::DataRecord(const QString &IPAddress, const QString &Port,
                       const QString & dbName,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DataRecord)
{
    ui->setupUi(this);
    this->setWindowTitle("Database Records");
    ui->progressBar->setTextVisible(false);
    Str_IPAddress = IPAddress;
    Str_port = Port;
    Str_dbName = dbName.trimmed();
    socket = new QTcpSocket(this);
    QStringList qListdays;
    qListdays << "This Month" << "Last Month" ; //<< "Last Six Month" << "This Year" << "Last Year" << "All" ;
    ui->comboBox_Records->addItems(qListdays);
    monthInDay();
}

DataRecord::~DataRecord()
{
    delete ui;
}

void DataRecord::on_pushButton_show_clicked()
{
    ui->tableWidget->setRowCount(0);
    ui->progressBar->setValue(0);
    strList_datafound.clear();
    int noOfDays;
    QString TimeStamp = ui->comboBox_Records->currentText();
    int nCreateFlag = 0;

    if(TimeStamp.trimmed() == "This Month")
    {
        QDate date = QDate::currentDate();
        int mnth = date.month();
        int year = date.year();
        //int day = date.day();

        noOfDays = map_monthInDay.value(mnth);

        QDate CurrentStartDate;
        CurrentStartDate.setDate(year,mnth,01);
        QString startDate = CurrentStartDate.toString("yyyy-MM-dd");
        Final_Start_Date = QDate::fromString(startDate,"yyyy-MM-dd");

        QDate CurrentEndDate;
        CurrentEndDate.setDate(year,mnth,noOfDays);
        QString endDate = CurrentEndDate.toString("yyyy-MM-dd");
        Final_end_DateTime = QDate::fromString(endDate,"yyyy-MM-dd");
    }
    if(TimeStamp.trimmed() == "Last Month")
    {
        QDate date = QDate::currentDate();
        int mnth = date.month()-1;
        int year = date.year();
        //int day = date.day();
        if(mnth == 0)
        {
            mnth = 12;
            year = date.year() - 1;
        }

        noOfDays = map_monthInDay.value(mnth);
        QDate CurrentStartDate;
        CurrentStartDate.setDate(year,mnth,01);
        QString startDate = CurrentStartDate.toString("yyyy-MM-dd");
        Final_Start_Date = QDate::fromString(startDate,"yyyy-MM-dd");

        QDate CurrentEndDate;
        CurrentEndDate.setDate(year,mnth,noOfDays);
        QString endDate = CurrentEndDate.toString("yyyy-MM-dd");
        Final_end_DateTime = QDate::fromString(endDate,"yyyy-MM-dd");
    }
    int days = Final_Start_Date.daysTo(Final_end_DateTime);
    float noDayIter = days/10.00;
    float FnlValue = 100.00/noDayIter;
    int fnl_bar_value = qRound(FnlValue);
    int FinalProgressBar_Itr_Value = 0;

    do {
        QString startFinalDate = Final_Start_Date.toString("yyyy-MM-dd");
        QDate fEndDate = Final_Start_Date.addDays(9);
        if(Final_Start_Date.day() == 21)
        {
            if(noOfDays == 31)
            {
                fEndDate = Final_Start_Date.addDays(10);
            }
        }
        QString endFinalDate = fEndDate.toString("yyyy-MM-dd");
        QJsonObject jsonKeys;
        QJsonArray jsonArray,plot_array;
        jsonKeys.insert("username","rushikesh");
        jsonKeys.insert("passcode","finecho@178");
        jsonKeys.insert("authkey","abcd");
        jsonKeys.insert("endpoint","fetchdaywisecounts");
        jsonKeys.insert("dbname",Str_dbName);
        jsonKeys.insert("start_date",startFinalDate);
        jsonKeys.insert("end_date",endFinalDate);
        //===============================================
        jsonArray.append(jsonKeys);
        QJsonDocument jsonDoc;
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
            for(int m=0; m<500; m++){
                socket->waitForReadyRead(30000);
                iBytes = socket->bytesAvailable();
                if(iBytes==0)
                    break;
                data += socket->readAll();
                usleep(100000);
            }

            QJsonDocument loadDoc(QJsonDocument::fromJson(data, &json_error));
            if (json_error.error != QJsonParseError::NoError)
            {
                qDebug() << "JSON parse error: "<< json_error.errorString();
            }

            QJsonObject rootObj = loadDoc.object();
            //qDebug() << "rootObj===" << rootObj;
            QJsonArray fieldDefJSONArray = rootObj.value("field").toArray();

            QJsonValue fieldSet;
            QJsonObject fieldObj;
            clearValues();
            for(int i=0; i< fieldDefJSONArray.size(); i++)
            {
                fieldSet = fieldDefJSONArray.at(i);
                fieldObj = fieldSet.toObject();

                strList_datafound << fieldObj.value("date").toString();
                strList_date << fieldObj.value("date").toString();
                strList_startTime << fieldObj.value("start_time").toString();
                strList_endTime << fieldObj.value("end_time").toString();
                strList_count << fieldObj.value("count").toString();
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
        GeneratedRecords();
        ui->tableWidget->repaint();
        ui->tableWidget->viewport()->update();
        Final_Start_Date = fEndDate.addDays(1);
        FinalProgressBar_Itr_Value = fnl_bar_value + FinalProgressBar_Itr_Value;
        if(FinalProgressBar_Itr_Value > 100)
        {
            FinalProgressBar_Itr_Value = 100;
        }
        ui->progressBar->setValue(FinalProgressBar_Itr_Value);

    } while (Final_Start_Date < Final_end_DateTime);
    ui->progressBar->setValue(100);
    if(strList_datafound.size() == 0){
        QString message = QString( "No data Found");
        QMessageBox::information(this,"Info....", message );
    }
}
void DataRecord::GeneratedRecords()
{
    int row = ui->tableWidget->rowCount();
    int i = 0;
    while(i < strList_date.length())
    {
        ui->tableWidget->insertRow(row);
        QTableWidgetItem *item;
        QString date = strList_date.at(i);
        QString count = strList_count.at(i);
        QString startTime = strList_startTime.at(i);
        QString endTime = strList_endTime.at(i);

        item = new QTableWidgetItem(date);
        item->setFlags(item->flags() & ~Qt::ItemIsEditable); // non editable
        ui->tableWidget->setItem(row,0,item);
        // ui->tableWidget->item(row,0)->setText(date);

        item = new QTableWidgetItem(count);
        item->setFlags(item->flags() & ~Qt::ItemIsEditable); // non editable
        ui->tableWidget->setItem(row,1,item);

        item = new QTableWidgetItem(startTime);
        item->setFlags(item->flags() & ~Qt::ItemIsEditable); // non editable
        ui->tableWidget->setItem(row,2,item);

        item = new QTableWidgetItem(endTime);
        item->setFlags(item->flags() & ~Qt::ItemIsEditable); // non editable
        ui->tableWidget->setItem(row,3,item);

        ui->tableWidget->repaint();
        ui->tableWidget->viewport()->update();

        i++;
        row++;
    }
}

void DataRecord::monthInDay()
{
    map_monthInDay.insert(1,31);
    map_monthInDay.insert(2,28);
    map_monthInDay.insert(3,31);
    map_monthInDay.insert(4,30);
    map_monthInDay.insert(5,31);
    map_monthInDay.insert(6,30);
    map_monthInDay.insert(7,31);
    map_monthInDay.insert(8,31);
    map_monthInDay.insert(9,30);
    map_monthInDay.insert(10,31);
    map_monthInDay.insert(11,30);
    map_monthInDay.insert(12,31);
}
void DataRecord::clearValues()
{
    strList_date.clear();
    strList_startTime.clear();
    strList_endTime.clear();
    strList_count.clear();
}

void DataRecord::on_pshBtn_close_clicked()
{
    this->close();
}

void DataRecord::on_pushButton_clicked()
{
  this->close();
}
