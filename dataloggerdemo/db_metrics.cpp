#include "db_metrics.h"
#include "ui_db_metrics.h"

DB_Metrics::DB_Metrics(const QString &IPAddress, const QString &Port,const QString &DBName,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DB_Metrics)
{
    ui->setupUi(this);
    this->setWindowTitle("DB Metrics");
    Str_IPAddress = IPAddress;
    Str_port = Port;
    Str_DBName = DBName;
    socket = new QTcpSocket(this);
    get_DBmatrics();
}

DB_Metrics::~DB_Metrics()
{
    delete ui;
}

void DB_Metrics::get_DBmatrics()
{
    QJsonObject jsonKeys;
    QJsonArray jsonArray;
    QByteArray data;
    QJsonDocument jsonDoc;

    jsonKeys.insert("username","rushikesh");
    jsonKeys.insert("passcode","123456");
    jsonKeys.insert("authkey","abcd");
    jsonKeys.insert("dbname",Str_DBName);
    jsonKeys.insert("endpoint","getdbMetricsFromMltpl_DBs");
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
        for(int m=0; m<50; m++){
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
       //qDebug() << "rootObj===" << rootObj;

        QString str1 = rootObj.value("Available_space_is").toString();
        ui->label_ASpace->setText(str1);

        QString str2 = rootObj.value("Available_space_percentage_is").toString();
        ui->label_ASpacePer->setText(str2);

        QString str4 = rootObj.value("Others_space_is").toString();
        ui->label_OtrSpace->setText(str4);

        QString str5 = rootObj.value("Others_space_percentage_is").toString();
        ui->label_OtrSpacePer->setText(str5);

        QString str6 = rootObj.value("Reserved_space_is").toString();
        ui->label_ResSpace->setText(str6);

        QString str7 = rootObj.value("Reserved_space_percentage_is").toString();
        ui->label_ResSpacePer->setText(str7);

        QString str8 = rootObj.value("Total_disk_space_is").toString();
        ui->label_tDiskSpace->setText(str8);

        QString str9 = rootObj.value("Total_disk_space_percentage_is").toString();
        ui->label_tDiskSpacePer->setText(str9);

        QString str10 = rootObj.value("Total_number_of_days_that_the_data_was_stored_in_data_table").toString();
        if(str10=="()")
            str10="";
        ui->label_dStoreInDataTable->setText(str10);

        QString str11 = rootObj.value("Used_space_is").toString();
        ui->label_USpace->setText(str11);

        QString str12 = rootObj.value("Used_space_percentage_is").toString();
        ui->label_USpacePer->setText(str12);

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

void DB_Metrics::on_pushButton_clicked()
{
  this->close();
}
