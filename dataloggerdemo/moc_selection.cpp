/****************************************************************************
** Meta object code from reading C++ file 'selection.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "selection.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'selection.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_selection_t {
    QByteArrayData data[77];
    char stringdata0[1896];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_selection_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_selection_t qt_meta_stringdata_selection = {
    {
QT_MOC_LITERAL(0, 0, 9), // "selection"
QT_MOC_LITERAL(1, 10, 19), // "close_event_changed"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 6), // "rotate"
QT_MOC_LITERAL(4, 38, 12), // "xAxisChanged"
QT_MOC_LITERAL(5, 51, 8), // "QCPRange"
QT_MOC_LITERAL(6, 60, 5), // "range"
QT_MOC_LITERAL(7, 66, 12), // "yAxisChanged"
QT_MOC_LITERAL(8, 79, 15), // "controlledZoomX"
QT_MOC_LITERAL(9, 95, 12), // "QWheelEvent*"
QT_MOC_LITERAL(10, 108, 5), // "event"
QT_MOC_LITERAL(11, 114, 12), // "mouseRelease"
QT_MOC_LITERAL(12, 127, 12), // "QMouseEvent*"
QT_MOC_LITERAL(13, 140, 10), // "mousePress"
QT_MOC_LITERAL(14, 151, 9), // "mouseMove"
QT_MOC_LITERAL(15, 161, 11), // "deleteGroup"
QT_MOC_LITERAL(16, 173, 13), // "del_groupname"
QT_MOC_LITERAL(17, 187, 8), // "addGroup"
QT_MOC_LITERAL(18, 196, 13), // "add_groupname"
QT_MOC_LITERAL(19, 210, 11), // "updateGroup"
QT_MOC_LITERAL(20, 222, 15), // "CheckConnection"
QT_MOC_LITERAL(21, 238, 29), // "on_pushButton_connect_clicked"
QT_MOC_LITERAL(22, 268, 43), // "on_comboBox_ConnectedIPs_curr..."
QT_MOC_LITERAL(23, 312, 4), // "arg1"
QT_MOC_LITERAL(24, 317, 33), // "on_timeEdit_StartTime_timeCha..."
QT_MOC_LITERAL(25, 351, 4), // "time"
QT_MOC_LITERAL(26, 356, 31), // "on_timeEdit_EndTime_timeChanged"
QT_MOC_LITERAL(27, 388, 35), // "on_timeEdit_PValueStart_timeC..."
QT_MOC_LITERAL(28, 424, 33), // "on_timeEdit_PValueEnd_timeCha..."
QT_MOC_LITERAL(29, 458, 34), // "on_cmbBx_Etime_currentIndexCh..."
QT_MOC_LITERAL(30, 493, 35), // "on_cmbBx_Samples_currentTextC..."
QT_MOC_LITERAL(31, 529, 5), // "value"
QT_MOC_LITERAL(32, 535, 36), // "on_cmbBx_Samples_currentIndex..."
QT_MOC_LITERAL(33, 572, 37), // "on_cmbBx_EtimeDur_currentInde..."
QT_MOC_LITERAL(34, 610, 38), // "on_TimeStamp_StartTime_dateTi..."
QT_MOC_LITERAL(35, 649, 8), // "dateTime"
QT_MOC_LITERAL(36, 658, 36), // "on_TimeStamp_EndTime_dateTime..."
QT_MOC_LITERAL(37, 695, 32), // "on_radioButton_TSEndTime_clicked"
QT_MOC_LITERAL(38, 728, 32), // "on_radioButton_TSDurTime_clicked"
QT_MOC_LITERAL(39, 761, 25), // "on_End_PvradioBtn_clicked"
QT_MOC_LITERAL(40, 787, 25), // "on_Dur_PvradioBtn_clicked"
QT_MOC_LITERAL(41, 813, 24), // "on_PshBtn_search_clicked"
QT_MOC_LITERAL(42, 838, 39), // "on_Pvalue_StartdateTime_dateT..."
QT_MOC_LITERAL(43, 878, 44), // "on_treeWidget_ParameterTimeVa..."
QT_MOC_LITERAL(44, 923, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(45, 940, 4), // "item"
QT_MOC_LITERAL(46, 945, 6), // "column"
QT_MOC_LITERAL(47, 952, 29), // "on_pshBtn_clearParams_clicked"
QT_MOC_LITERAL(48, 982, 22), // "on_PshBtn_PLot_clicked"
QT_MOC_LITERAL(49, 1005, 26), // "on_m_PshBtn_Delete_clicked"
QT_MOC_LITERAL(50, 1032, 29), // "on_radioButton_x_axis_clicked"
QT_MOC_LITERAL(51, 1062, 29), // "on_radioButton_y_axis_clicked"
QT_MOC_LITERAL(52, 1092, 24), // "on_m_PshBtn_Save_clicked"
QT_MOC_LITERAL(53, 1117, 26), // "on_m_PshBtn_export_clicked"
QT_MOC_LITERAL(54, 1144, 30), // "on_m_PshBtn_SavedPlots_clicked"
QT_MOC_LITERAL(55, 1175, 27), // "on_m_PshBtn_Scaling_clicked"
QT_MOC_LITERAL(56, 1203, 31), // "on_m_PshBtn_ImportGraph_clicked"
QT_MOC_LITERAL(57, 1235, 33), // "on_cmbBx_Type_currentIndexCha..."
QT_MOC_LITERAL(58, 1269, 38), // "on_comboBox_CriParm_currentTe..."
QT_MOC_LITERAL(59, 1308, 41), // "on_comboBox_AndCriParm_curren..."
QT_MOC_LITERAL(60, 1350, 36), // "on_cmbx_Discreate_currentText..."
QT_MOC_LITERAL(61, 1387, 39), // "on_cmbx_DiscreateAnd_currentT..."
QT_MOC_LITERAL(62, 1427, 27), // "on_pushButton_about_clicked"
QT_MOC_LITERAL(63, 1455, 41), // "on_comboBox_databases_current..."
QT_MOC_LITERAL(64, 1497, 5), // "index"
QT_MOC_LITERAL(65, 1503, 26), // "on_pshbtnSearchNow_clicked"
QT_MOC_LITERAL(66, 1530, 26), // "on_pshbtnSelectNow_clicked"
QT_MOC_LITERAL(67, 1557, 36), // "on_treeWidget_TrackTypes_item..."
QT_MOC_LITERAL(68, 1594, 36), // "on_treeWidget_TrackTypes_item..."
QT_MOC_LITERAL(69, 1631, 30), // "on_radioButton_y_axis2_clicked"
QT_MOC_LITERAL(70, 1662, 39), // "on_cmbBx_SavedGroup_currentIn..."
QT_MOC_LITERAL(71, 1702, 40), // "on_comboBox_databases_current..."
QT_MOC_LITERAL(72, 1743, 30), // "on_lineEdit_Before_textChanged"
QT_MOC_LITERAL(73, 1774, 29), // "on_lineEdit_After_textChanged"
QT_MOC_LITERAL(74, 1804, 34), // "on_m_PshBtn_exportcsvFrmDB_cl..."
QT_MOC_LITERAL(75, 1839, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(76, 1861, 34) // "on_comboBoxdemo_currentTextCh..."

    },
    "selection\0close_event_changed\0\0rotate\0"
    "xAxisChanged\0QCPRange\0range\0yAxisChanged\0"
    "controlledZoomX\0QWheelEvent*\0event\0"
    "mouseRelease\0QMouseEvent*\0mousePress\0"
    "mouseMove\0deleteGroup\0del_groupname\0"
    "addGroup\0add_groupname\0updateGroup\0"
    "CheckConnection\0on_pushButton_connect_clicked\0"
    "on_comboBox_ConnectedIPs_currentTextChanged\0"
    "arg1\0on_timeEdit_StartTime_timeChanged\0"
    "time\0on_timeEdit_EndTime_timeChanged\0"
    "on_timeEdit_PValueStart_timeChanged\0"
    "on_timeEdit_PValueEnd_timeChanged\0"
    "on_cmbBx_Etime_currentIndexChanged\0"
    "on_cmbBx_Samples_currentTextChanged\0"
    "value\0on_cmbBx_Samples_currentIndexChanged\0"
    "on_cmbBx_EtimeDur_currentIndexChanged\0"
    "on_TimeStamp_StartTime_dateTimeChanged\0"
    "dateTime\0on_TimeStamp_EndTime_dateTimeChanged\0"
    "on_radioButton_TSEndTime_clicked\0"
    "on_radioButton_TSDurTime_clicked\0"
    "on_End_PvradioBtn_clicked\0"
    "on_Dur_PvradioBtn_clicked\0"
    "on_PshBtn_search_clicked\0"
    "on_Pvalue_StartdateTime_dateTimeChanged\0"
    "on_treeWidget_ParameterTimeValue_itemClicked\0"
    "QTreeWidgetItem*\0item\0column\0"
    "on_pshBtn_clearParams_clicked\0"
    "on_PshBtn_PLot_clicked\0"
    "on_m_PshBtn_Delete_clicked\0"
    "on_radioButton_x_axis_clicked\0"
    "on_radioButton_y_axis_clicked\0"
    "on_m_PshBtn_Save_clicked\0"
    "on_m_PshBtn_export_clicked\0"
    "on_m_PshBtn_SavedPlots_clicked\0"
    "on_m_PshBtn_Scaling_clicked\0"
    "on_m_PshBtn_ImportGraph_clicked\0"
    "on_cmbBx_Type_currentIndexChanged\0"
    "on_comboBox_CriParm_currentTextChanged\0"
    "on_comboBox_AndCriParm_currentTextChanged\0"
    "on_cmbx_Discreate_currentTextChanged\0"
    "on_cmbx_DiscreateAnd_currentTextChanged\0"
    "on_pushButton_about_clicked\0"
    "on_comboBox_databases_currentIndexChanged\0"
    "index\0on_pshbtnSearchNow_clicked\0"
    "on_pshbtnSelectNow_clicked\0"
    "on_treeWidget_TrackTypes_itemChanged\0"
    "on_treeWidget_TrackTypes_itemPressed\0"
    "on_radioButton_y_axis2_clicked\0"
    "on_cmbBx_SavedGroup_currentIndexChanged\0"
    "on_comboBox_databases_currentTextChanged\0"
    "on_lineEdit_Before_textChanged\0"
    "on_lineEdit_After_textChanged\0"
    "on_m_PshBtn_exportcsvFrmDB_clicked\0"
    "on_pushButton_clicked\0"
    "on_comboBoxdemo_currentTextChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_selection[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      60,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  314,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,  315,    2, 0x0a /* Public */,
       4,    1,  316,    2, 0x0a /* Public */,
       7,    1,  319,    2, 0x0a /* Public */,
       8,    1,  322,    2, 0x0a /* Public */,
      11,    1,  325,    2, 0x0a /* Public */,
      13,    1,  328,    2, 0x0a /* Public */,
      14,    1,  331,    2, 0x0a /* Public */,
      15,    1,  334,    2, 0x0a /* Public */,
      17,    1,  337,    2, 0x0a /* Public */,
      19,    0,  340,    2, 0x0a /* Public */,
      20,    0,  341,    2, 0x08 /* Private */,
      21,    0,  342,    2, 0x08 /* Private */,
      22,    1,  343,    2, 0x08 /* Private */,
      24,    1,  346,    2, 0x08 /* Private */,
      26,    1,  349,    2, 0x08 /* Private */,
      27,    1,  352,    2, 0x08 /* Private */,
      28,    1,  355,    2, 0x08 /* Private */,
      29,    1,  358,    2, 0x08 /* Private */,
      30,    1,  361,    2, 0x08 /* Private */,
      32,    1,  364,    2, 0x08 /* Private */,
      33,    1,  367,    2, 0x08 /* Private */,
      34,    1,  370,    2, 0x08 /* Private */,
      36,    1,  373,    2, 0x08 /* Private */,
      37,    0,  376,    2, 0x08 /* Private */,
      38,    0,  377,    2, 0x08 /* Private */,
      39,    0,  378,    2, 0x08 /* Private */,
      40,    0,  379,    2, 0x08 /* Private */,
      41,    0,  380,    2, 0x08 /* Private */,
      42,    1,  381,    2, 0x08 /* Private */,
      43,    2,  384,    2, 0x08 /* Private */,
      47,    0,  389,    2, 0x08 /* Private */,
      48,    0,  390,    2, 0x08 /* Private */,
      49,    0,  391,    2, 0x08 /* Private */,
      50,    0,  392,    2, 0x08 /* Private */,
      51,    0,  393,    2, 0x08 /* Private */,
      52,    0,  394,    2, 0x08 /* Private */,
      53,    0,  395,    2, 0x08 /* Private */,
      54,    0,  396,    2, 0x08 /* Private */,
      55,    0,  397,    2, 0x08 /* Private */,
      56,    0,  398,    2, 0x08 /* Private */,
      57,    1,  399,    2, 0x08 /* Private */,
      58,    1,  402,    2, 0x08 /* Private */,
      59,    1,  405,    2, 0x08 /* Private */,
      60,    1,  408,    2, 0x08 /* Private */,
      61,    1,  411,    2, 0x08 /* Private */,
      62,    0,  414,    2, 0x08 /* Private */,
      63,    1,  415,    2, 0x08 /* Private */,
      65,    0,  418,    2, 0x08 /* Private */,
      66,    0,  419,    2, 0x08 /* Private */,
      67,    2,  420,    2, 0x08 /* Private */,
      68,    2,  425,    2, 0x08 /* Private */,
      69,    0,  430,    2, 0x08 /* Private */,
      70,    1,  431,    2, 0x08 /* Private */,
      71,    1,  434,    2, 0x08 /* Private */,
      72,    1,  437,    2, 0x08 /* Private */,
      73,    1,  440,    2, 0x08 /* Private */,
      74,    0,  443,    2, 0x08 /* Private */,
      75,    0,  444,    2, 0x08 /* Private */,
      76,    1,  445,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 12,    2,
    QMetaType::Void, 0x80000000 | 12,    2,
    QMetaType::Void, 0x80000000 | 12,    2,
    QMetaType::Void, QMetaType::QString,   16,
    QMetaType::Void, QMetaType::QString,   18,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   23,
    QMetaType::Void, QMetaType::QTime,   25,
    QMetaType::Void, QMetaType::QTime,   25,
    QMetaType::Void, QMetaType::QTime,   25,
    QMetaType::Void, QMetaType::QTime,   25,
    QMetaType::Void, QMetaType::QString,   23,
    QMetaType::Void, QMetaType::QString,   31,
    QMetaType::Void, QMetaType::QString,   31,
    QMetaType::Void, QMetaType::QString,   23,
    QMetaType::Void, QMetaType::QDateTime,   35,
    QMetaType::Void, QMetaType::QDateTime,   35,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QDateTime,   35,
    QMetaType::Void, 0x80000000 | 44, QMetaType::Int,   45,   46,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   23,
    QMetaType::Void, QMetaType::QString,   23,
    QMetaType::Void, QMetaType::QString,   23,
    QMetaType::Void, QMetaType::QString,   23,
    QMetaType::Void, QMetaType::QString,   23,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   64,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 44, QMetaType::Int,   45,   46,
    QMetaType::Void, 0x80000000 | 44, QMetaType::Int,   45,   46,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   23,
    QMetaType::Void, QMetaType::QString,   23,
    QMetaType::Void, QMetaType::QString,   23,
    QMetaType::Void, QMetaType::QString,   23,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   23,

       0        // eod
};

void selection::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<selection *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->close_event_changed(); break;
        case 1: _t->rotate(); break;
        case 2: _t->xAxisChanged((*reinterpret_cast< QCPRange(*)>(_a[1]))); break;
        case 3: _t->yAxisChanged((*reinterpret_cast< QCPRange(*)>(_a[1]))); break;
        case 4: _t->controlledZoomX((*reinterpret_cast< QWheelEvent*(*)>(_a[1]))); break;
        case 5: _t->mouseRelease((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 6: _t->mousePress((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 7: _t->mouseMove((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 8: _t->deleteGroup((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->addGroup((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->updateGroup(); break;
        case 11: _t->CheckConnection(); break;
        case 12: _t->on_pushButton_connect_clicked(); break;
        case 13: _t->on_comboBox_ConnectedIPs_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 14: _t->on_timeEdit_StartTime_timeChanged((*reinterpret_cast< const QTime(*)>(_a[1]))); break;
        case 15: _t->on_timeEdit_EndTime_timeChanged((*reinterpret_cast< const QTime(*)>(_a[1]))); break;
        case 16: _t->on_timeEdit_PValueStart_timeChanged((*reinterpret_cast< const QTime(*)>(_a[1]))); break;
        case 17: _t->on_timeEdit_PValueEnd_timeChanged((*reinterpret_cast< const QTime(*)>(_a[1]))); break;
        case 18: _t->on_cmbBx_Etime_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 19: _t->on_cmbBx_Samples_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 20: _t->on_cmbBx_Samples_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 21: _t->on_cmbBx_EtimeDur_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 22: _t->on_TimeStamp_StartTime_dateTimeChanged((*reinterpret_cast< const QDateTime(*)>(_a[1]))); break;
        case 23: _t->on_TimeStamp_EndTime_dateTimeChanged((*reinterpret_cast< const QDateTime(*)>(_a[1]))); break;
        case 24: _t->on_radioButton_TSEndTime_clicked(); break;
        case 25: _t->on_radioButton_TSDurTime_clicked(); break;
        case 26: _t->on_End_PvradioBtn_clicked(); break;
        case 27: _t->on_Dur_PvradioBtn_clicked(); break;
        case 28: _t->on_PshBtn_search_clicked(); break;
        case 29: _t->on_Pvalue_StartdateTime_dateTimeChanged((*reinterpret_cast< const QDateTime(*)>(_a[1]))); break;
        case 30: _t->on_treeWidget_ParameterTimeValue_itemClicked((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 31: _t->on_pshBtn_clearParams_clicked(); break;
        case 32: _t->on_PshBtn_PLot_clicked(); break;
        case 33: _t->on_m_PshBtn_Delete_clicked(); break;
        case 34: _t->on_radioButton_x_axis_clicked(); break;
        case 35: _t->on_radioButton_y_axis_clicked(); break;
        case 36: _t->on_m_PshBtn_Save_clicked(); break;
        case 37: _t->on_m_PshBtn_export_clicked(); break;
        case 38: _t->on_m_PshBtn_SavedPlots_clicked(); break;
        case 39: _t->on_m_PshBtn_Scaling_clicked(); break;
        case 40: _t->on_m_PshBtn_ImportGraph_clicked(); break;
        case 41: _t->on_cmbBx_Type_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 42: _t->on_comboBox_CriParm_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 43: _t->on_comboBox_AndCriParm_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 44: _t->on_cmbx_Discreate_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 45: _t->on_cmbx_DiscreateAnd_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 46: _t->on_pushButton_about_clicked(); break;
        case 47: _t->on_comboBox_databases_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 48: _t->on_pshbtnSearchNow_clicked(); break;
        case 49: _t->on_pshbtnSelectNow_clicked(); break;
        case 50: _t->on_treeWidget_TrackTypes_itemChanged((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 51: _t->on_treeWidget_TrackTypes_itemPressed((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 52: _t->on_radioButton_y_axis2_clicked(); break;
        case 53: _t->on_cmbBx_SavedGroup_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 54: _t->on_comboBox_databases_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 55: _t->on_lineEdit_Before_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 56: _t->on_lineEdit_After_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 57: _t->on_m_PshBtn_exportcsvFrmDB_clicked(); break;
        case 58: _t->on_pushButton_clicked(); break;
        case 59: _t->on_comboBoxdemo_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (selection::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&selection::close_event_changed)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject selection::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_selection.data,
    qt_meta_data_selection,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *selection::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *selection::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_selection.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int selection::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 60)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 60;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 60)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 60;
    }
    return _id;
}

// SIGNAL 0
void selection::close_event_changed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
