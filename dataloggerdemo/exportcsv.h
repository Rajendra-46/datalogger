/*
FileName	:DataRecord
Purpose     :This Files is used to export the records by using CSV.
Authour     :Gururaj B M / Kasturi Rangan.
*/

#ifndef EXPORTCSV_H
#define EXPORTCSV_H

#include <QWidget>
#include <QTcpSocket>
#include <QJsonParseError>
#include <QMessageBox>
#include <QJsonObject>
#include <QJsonArray>
#include <unistd.h>
#include <QDebug>
#include <QFileDialog>
#include <QFile>
#include <QDateTime>
#include <QTextStream>
#include <QProgressBar>
#include <QSettings>
#include <QThread>
#include <QCloseEvent>

namespace Ui {
class exportcsv;
}

class exportcsv : public QWidget
{
    Q_OBJECT

public:
    explicit exportcsv(const QString & IPAddress = QString(),const QString & Port = QString(),
                       const QString & dbName = QString(),QWidget *parent = nullptr);
    ~exportcsv();
    QString Str_IPAddress,Str_port,Str_dbName;
    void createFile();
    QTcpSocket *socket;
    QFile teleFile;
    QDateTime Final_Start_Date;
    QDateTime Final_end_DateTime;
    bool check = true;
    void Connection_status();
    void closeEvent(QCloseEvent *event);
    QThread * thread;
    QString str_file;
    bool close_event=true;
signals:
    void dataReceived(int value);
    void close_event_changed();

private slots:
    void processData(int value);
    void updatePBar();

private slots:
    void on_timeEdit_Start_timeChanged(const QTime &time);
    void on_timeEdit_End_timeChanged(const QTime &time);
    void on_m_PshBtn_GetData_clicked();

    void on_pushButton_clicked();

private:

    Ui::exportcsv *ui;
};

#endif // EXPORTCSV_H
