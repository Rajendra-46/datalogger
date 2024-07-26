/*
FileName	:about
Purpose     :This Files is used to SetUp the about functionality.
Authour     :Gururaj B M / Kasturi Rangan
*/

#ifndef ABOUT_H
#define ABOUT_H
#include <QtCore>
#include <QWidget>
#include <QTcpSocket>
#include <QJsonParseError>
#include <QMessageBox>
#include <QJsonObject>
#include <QJsonArray>
#include <unistd.h>
#include <QDebug>
#include <QCloseEvent>
#include <datarecord.h>
#include <db_metrics.h>
#include <iostream>
#include <QDesktopServices>

namespace Ui {
class about;
}

class about : public QWidget
{
    Q_OBJECT

public:
    explicit about(const QString & IPAddress = QString(),const QString & Port = QString(),
            const QString & Db = QString(),QWidget *parent = nullptr);
    ~about();
    QString Str_IPAddress,Str_port,Str_DbName;
    QTcpSocket *socket;
    void get_versions();
    DataRecord *m_DataRecord;
    DB_Metrics *m_DB_Metrics;
    void closeEvent(QCloseEvent *event);
    bool m_more_status=false;

public slots:
    void on_m_PshBtn_DBMatrics_clicked();

    void on_m_PshBtn_FetchDayWiseCont_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_m_PshBtn_quickGuide_clicked();

private slots:
    void on_pushButton_clicked();

private:
    Ui::about *ui;
};

#endif // ABOUT_H
