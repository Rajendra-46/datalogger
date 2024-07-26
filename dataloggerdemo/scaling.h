/*
FileName	:Scaling
Purpose     :This Files is used to setup the scaling.
Authour     :Gururaj B M / Kasturi Rangan.
*/

#ifndef SCALING_H
#define SCALING_H

#include <QWidget>
#include <QMap>
#include <QLineEdit>
#include <QPushButton>
#include <QCheckBox>
#include <QSettings>
#include <QFile>
#include <QTextStream>
namespace Ui {
class Scaling;
}

class Scaling : public QWidget
{
    Q_OBJECT

public:
    explicit Scaling(const QStringList & list_parms = QStringList(),const QStringList & list_cmt = QStringList(),
                     const QStringList & list_parmsType = QStringList(),const QStringList & list_scalingFactor = QStringList(),
                     const QStringList & list_offSet = QStringList(),const QString & IPAddress = QString(),const QString & Port = QString(),
                     const QString & Db = QString(),
                     QWidget *parent = nullptr);
    ~Scaling();

    QString Str_IPAddress,Str_port,Str_DbName;
    QMap<QString,QString> Scalevalmap,ScaleRevalmap;
    QMap<QString,QString> ScaleOffsetmap;
    QLineEdit  *edit,*edit_offset;
    QPushButton *m_pushbtn,*m_pushbtn_offset;
    QCheckBox *m_chckBox;
    int row,col,row1,col1;
    QString str,Xval,Yval1;
    QStringList strlstparm,strlstval,strlstparm_offset,strlstval_offset;
    QStringList strList_cmt,strList_ParameterName,strList_ParameterType,strList_ScallingFactor,strList_offSet;
    QStringList strList_ntcmt,strList_ntParameterName,strList_ntParameterType,strList_ntScallingFactor,strList_ntoffSet;
    void FillDataToTable();
    void ReloadLocalCustomScaleValues();
    QStringList strList_saveGroup_param,strList_saveGroup_scaling,strList_saveGroup_offset;
    QStringList strList_saveGroup_param1,strList_saveGroup_scaling1,strList_saveGroup_offset1;
    int rowval;
    QWidget *groupWidget,*saveWidget;
    QLineEdit *lEdt;
    void SavedGroupNames();
    QStringList params,scale,offset;

public slots:
    void saveGroupWidget();
    void closeGroupWidget();
    void editedvalue();
    void PushBtnClicked();
    void PushBtnClicked_Offset();

private slots:
    void on_m_PshBtn_Save_clicked();

    void on_comboBox_saveGroups_currentIndexChanged(const QString &arg1);

    void on_pushButton_NewGroup_clicked();

    void on_pushButton_show_clicked();

    void on_pushButton_Delete_clicked();

    void on_pushButton_ClearValue_clicked();

    void on_pushButton_update_clicked();

    void on_chbx_All_saved_group_clicked(bool checked);

    void on_pshBtn_close_clicked();

    void on_pushButton_clicked();

signals:
    void deleteGroupName(QString);
    void addGroupName(QString);
    void updateGroupName();

private:

    Ui::Scaling *ui;
};

#endif // SCALING_H
