#ifndef SELECTION_H
#define SELECTION_H

#include <QWidget>
#include <QAbstractItemView>
#include <QTreeWidgetItem>
#include <QJsonDocument>
#include <QMainWindow>
#include <QJsonObject>
#include <QTreeWidget>
#include <QJsonArray>
#include <QDebug>
#include <QFile>
#include <QMap>
#include <unistd.h>
#include <qlineedit.h>
#include <QCompleter>
#include <QtWidgets>
#include <QTcpSocket>
#include <qcustomplot.h>
#include <version.h>
#include <scaling.h>
#include <exportcsv.h>
#include <QHostAddress>
#include <QRegExpValidator>
#include <QRegExp>
#include <QRegularExpression>
#include <QValidator>
#include <QDateTime>
#include <QScreen>
#include <QFileDialog>
#include <QSqlDatabase>
#include <QtSql>
#include <unistd.h>
#include <QJsonParseError>
#include <qdebug.h>
#include <QRegExp>
#include <QRegularExpression>
#include <QRegExpValidator>
#include <about.h>
#include <QCloseEvent>
#include <QThread>
#include <QListView>



namespace Ui {
class selection;
}

class selection : public QWidget
{
    Q_OBJECT

public:
    explicit selection(QWidget *parent = nullptr);
    ~selection();
    bool enable = false;
    QTreeWidget *m_treeAnalog;
    QJsonObject rootObj;
    QString strLastSelDb;
    bool flagDb = true;
    void fillData();
    void closeEvent(QCloseEvent *event);
    void traversJson_Tree(QJsonValue json_value, QTreeWidgetItem *tree_item);
    void traversJson_cmbx(QJsonValue json_value, QStandardItem *tree_item);
    void traversJson_cmbxDiscreate(QJsonValue json_value, QStandardItem *tree_item);
    QStandardItemModel *SearchComboboxlist = new QStandardItemModel();
    QStandardItemModel *SearchComboboxlistDiscreate = new QStandardItemModel();
    //=============
    Scaling *m_Scaling;
    exportcsv *m_exportcsv;

    about *abtPage;
    QMap<QString,QString> str_mapScale,str_mapOffSet,str_mapType,str_mapAlarmType,str_mapCmt,str_mapScaleReval,str_mapOffSetReval;
    QMap<QString,QString> str_mapExportScale,str_mapExportOffSet,str_mapExportType;
    QStringList strList_cmt,strList_ParameterName,strList_ParameterType,strList_ScallingFactor,strList_offSet,strList_alramId;
    QStringList strList_db,strList_prvdb;

    bool m_bTreeWidget1 = false;
    bool m_bTreeWidget2 = false;

    QString ServerTimeZone;
    QStringList lstofSavedPLots;
    QString rslnUpdate;
    //==========================
    QString displayText;
    QThread *m_pingThread;
    QTimer *m_pingTimer;
    QTcpSocket *socket,*socket1;
    QString Str_IPAddress,Str_port;
    void ReloadDefaultIps();
    void ReloadLastSelectedIPs();
    void SavedGroupNames();
    void ReloadLastSelDB();
    void ConnectToIp_Port(QString strIP, QString strPort);
    void InisialTime();
    QDateTime CurrentDurDateTime,PvalCurrentDurDateTime;
    void resolution(int);
    QStringList str_Timestampvals;
    QString SelectedTimeStamp;
    QStringList strSelectedAlams;
    QStringList strSelectedParams;
    QStringList showSelectedParmsinSearch;
    QStringList params,scale,offset;
    //=====================================
    void paraTimeSlot(QDateTime, QDateTime, QStringList,QStringList, QString,QList<QDateTime> tsCriteria,QList<QDateTime> tsCriteria_sel, QString strTSParamCriteria,QJsonObject recordImportObj,QString Export);
    QList<QDateTime> lstCriteriaTS,lstCriteriaTS_sel;
    QString strParamCriteria;
    QDateTime sDateTime,eDateTime, dPlotStart, dPlotEnd;
    QStringList strLstOfSelectedParams,strLstOfSelectedAlarms,strLstOfSelectedParamScaleing;
    void drawGraph();
    void resolution();
    void createFile();
    QFile teleFile;
    QStringList listval;
    QJsonObject GetDataFromTimestamp();
    QJsonObject json_obj,json_objtimeStamp;
    double selStartX, selStartY;
    QStringList strPingParams,strPLotNames;
    QJsonObject exportedJsonData;
    // QMap<QString,QJsonObject> f;
    QString findExportData;

    void showConnectedIPPortPlots();
    QList<QString> ip_port;
    QList<QString> dbnames;
    QList<QString> plots;
    QList<QJsonObject> plotsJson;
    QList<QString> pStartDateTime;
    QList<QString> pEndDateTime;
    QList<QStringList> pSelectedParms;
    QList<QStringList> pSelectedAlarms;
    QList<QList<QDateTime>> pSelectedAllDate;
    QList<QList<QDateTime>> pSelectedDate;
    QList<QString> pSelectedCreParam;
    //
    //QListView *listview = new QListView();//#
    QStringList listview;
    int tempPlots = 1;
    bool savePlot = true;
    bool importGraph_savedPlot_backgroundChange = false;
    bool bNaNPresent = false;
    QString str_Nan;
    void saveParams_clicked();
    QString dbName;
    void generate_scaling_lists(QJsonValue json_value);
    void fetchDB_Data();
    //======================
    QList<QTreeWidgetItem*> m_checked;
    int m_row=0,m_width=0;
    bool m_clear=false;
    void update_flow();
    QStringList getParamandAlarm(QString s);
    void selectedItemsClicked(QStringList);

    //===========rotation============
    QPushButton * m_cancel_button;
    QLabel *m_wait_label;
    QLabel *m_time_label;
    QTimer *m_timer;
    int number_rotations = 0, m_rotation = 0;
    void on_cancel_button_clicked();
    int waitFor = 0;

    bool m_more_status=false;



    public slots:

        void rotate();
        //===================================
        void xAxisChanged(QCPRange range);
        void yAxisChanged(QCPRange range);
        void controlledZoomX(QWheelEvent *event);
        void mouseRelease(QMouseEvent *);
        void mousePress(QMouseEvent *);
        void mouseMove(QMouseEvent *);
        void deleteGroup(QString del_groupname);
        void addGroup(QString add_groupname);
        void updateGroup();

    private slots:

        void CheckConnection();
        void on_pushButton_connect_clicked();
        void on_comboBox_ConnectedIPs_currentTextChanged(const QString &arg1);

        void on_timeEdit_StartTime_timeChanged(const QTime &time);
        void on_timeEdit_EndTime_timeChanged(const QTime &time);
        void on_timeEdit_PValueStart_timeChanged(const QTime &time);
        void on_timeEdit_PValueEnd_timeChanged(const QTime &time);

        void on_cmbBx_Etime_currentIndexChanged(const QString &arg1);
        void on_cmbBx_Samples_currentTextChanged(const QString &value);
        void on_cmbBx_Samples_currentIndexChanged(const QString &value);
        void on_cmbBx_EtimeDur_currentIndexChanged(const QString &arg1);

        void on_TimeStamp_StartTime_dateTimeChanged(const QDateTime &dateTime);
        void on_TimeStamp_EndTime_dateTimeChanged(const QDateTime &dateTime);

        void on_radioButton_TSEndTime_clicked();
        void on_radioButton_TSDurTime_clicked();

        void on_End_PvradioBtn_clicked();
        void on_Dur_PvradioBtn_clicked();

        void on_PshBtn_search_clicked();

        void on_Pvalue_StartdateTime_dateTimeChanged(const QDateTime &dateTime);
        void on_treeWidget_ParameterTimeValue_itemClicked(QTreeWidgetItem *item, int column);

        void on_pshBtn_clearParams_clicked();

        void on_PshBtn_PLot_clicked();
        void on_m_PshBtn_Delete_clicked();

        //=================================
        void on_radioButton_x_axis_clicked();
        void on_radioButton_y_axis_clicked();
        void on_m_PshBtn_Save_clicked();
        void on_m_PshBtn_export_clicked();


        void on_m_PshBtn_SavedPlots_clicked();
        void on_m_PshBtn_Scaling_clicked();
        void on_m_PshBtn_ImportGraph_clicked();
        // void on_m_PshBtn_exportcsv_clicked();

        void on_cmbBx_Type_currentIndexChanged(const QString &arg1);
        void on_comboBox_CriParm_currentTextChanged(const QString &arg1);
        void on_comboBox_AndCriParm_currentTextChanged(const QString &arg1);
        void on_cmbx_Discreate_currentTextChanged(const QString &arg1);
        void on_cmbx_DiscreateAnd_currentTextChanged(const QString &arg1);
        void on_pushButton_about_clicked();
        void on_comboBox_databases_currentIndexChanged(int index);
        void on_pshbtnSearchNow_clicked();
        void on_pshbtnSelectNow_clicked();
        void on_treeWidget_TrackTypes_itemChanged(QTreeWidgetItem *item, int column);
        void on_treeWidget_TrackTypes_itemPressed(QTreeWidgetItem *item, int column);
        void on_radioButton_y_axis2_clicked();
        void on_cmbBx_SavedGroup_currentIndexChanged(const QString &arg1);

        void on_comboBox_databases_currentTextChanged(const QString &arg1);

        void on_lineEdit_Before_textChanged(const QString &arg1);

        void on_lineEdit_After_textChanged(const QString &arg1);

        void on_m_PshBtn_exportcsvFrmDB_clicked();

        void on_pushButton_clicked();
        void on_comboBoxdemo_currentTextChanged(const QString &arg1);


private:
        Ui::selection *ui;
    signals:
        void close_event_changed();
    };
    #endif // SELECTION_H

