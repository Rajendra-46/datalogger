/*
FileName	:DataRecord
Purpose     :This Files is used to see the database records.
Authour     :Gururaj B M / Kasturi Rangan.
*/

#ifndef DATARECORD_H
#define DATARECORD_H

#include <QWidget>
#include <QTcpSocket>
#include <QJsonParseError>
#include <QMessageBox>
#include <QJsonObject>
#include <QJsonArray>
#include <QDateTime>
#include <QDebug>
#include <unistd.h>
namespace Ui {
class DataRecord;
}

class DataRecord : public QWidget
{
    Q_OBJECT

public:
    explicit DataRecord(const QString & IPAddress = QString(),const QString & Port = QString(),
                        const QString & dbName = QString(),QWidget *parent = nullptr);
    ~DataRecord();
    QString Str_IPAddress,Str_port,Str_dbName;
    QTcpSocket *socket;
    void clearValues();
    QStringList strList_date,strList_startTime,strList_endTime,strList_count,strList_datafound;
    QDate Final_Start_DateTime,Final_Start_Date;
    QDate Final_end_DateTime;
    void GeneratedRecords();
    QMap <int,int> map_monthInDay;
    void monthInDay();

private slots:
    void on_pushButton_show_clicked();

    void on_pshBtn_close_clicked();

    void on_pushButton_clicked();

private:
    Ui::DataRecord *ui;
};

#endif // DATARECORD_H
