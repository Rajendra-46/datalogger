#ifndef DB_METRICS_H
#define DB_METRICS_H

#include <QWidget>
#include <QTcpSocket>
#include <QJsonParseError>
#include <QMessageBox>
#include <QJsonObject>
#include <QJsonArray>
#include <unistd.h>
#include <QDebug>
namespace Ui {
class DB_Metrics;
}

class DB_Metrics : public QWidget
{
    Q_OBJECT

public:
    explicit DB_Metrics(const QString & IPAddress = QString(),const QString & Port = QString(),
                        const QString & DBName = QString(),QWidget *parent = nullptr);
    ~DB_Metrics();

    QString Str_IPAddress,Str_port,Str_DBName;
    QTcpSocket *socket;
    void get_DBmatrics();

private slots:
    void on_pushButton_clicked();

private:
    Ui::DB_Metrics *ui;
};



#endif // DB_METRICS_H
