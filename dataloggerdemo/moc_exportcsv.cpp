/****************************************************************************
** Meta object code from reading C++ file 'exportcsv.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "exportcsv.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'exportcsv.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_exportcsv_t {
    QByteArrayData data[12];
    char stringdata0[186];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_exportcsv_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_exportcsv_t qt_meta_stringdata_exportcsv = {
    {
QT_MOC_LITERAL(0, 0, 9), // "exportcsv"
QT_MOC_LITERAL(1, 10, 12), // "dataReceived"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 5), // "value"
QT_MOC_LITERAL(4, 30, 19), // "close_event_changed"
QT_MOC_LITERAL(5, 50, 11), // "processData"
QT_MOC_LITERAL(6, 62, 10), // "updatePBar"
QT_MOC_LITERAL(7, 73, 29), // "on_timeEdit_Start_timeChanged"
QT_MOC_LITERAL(8, 103, 4), // "time"
QT_MOC_LITERAL(9, 108, 27), // "on_timeEdit_End_timeChanged"
QT_MOC_LITERAL(10, 136, 27), // "on_m_PshBtn_GetData_clicked"
QT_MOC_LITERAL(11, 164, 21) // "on_pushButton_clicked"

    },
    "exportcsv\0dataReceived\0\0value\0"
    "close_event_changed\0processData\0"
    "updatePBar\0on_timeEdit_Start_timeChanged\0"
    "time\0on_timeEdit_End_timeChanged\0"
    "on_m_PshBtn_GetData_clicked\0"
    "on_pushButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_exportcsv[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       4,    0,   57,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   58,    2, 0x08 /* Private */,
       6,    0,   61,    2, 0x08 /* Private */,
       7,    1,   62,    2, 0x08 /* Private */,
       9,    1,   65,    2, 0x08 /* Private */,
      10,    0,   68,    2, 0x08 /* Private */,
      11,    0,   69,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QTime,    8,
    QMetaType::Void, QMetaType::QTime,    8,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void exportcsv::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<exportcsv *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->dataReceived((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->close_event_changed(); break;
        case 2: _t->processData((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->updatePBar(); break;
        case 4: _t->on_timeEdit_Start_timeChanged((*reinterpret_cast< const QTime(*)>(_a[1]))); break;
        case 5: _t->on_timeEdit_End_timeChanged((*reinterpret_cast< const QTime(*)>(_a[1]))); break;
        case 6: _t->on_m_PshBtn_GetData_clicked(); break;
        case 7: _t->on_pushButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (exportcsv::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&exportcsv::dataReceived)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (exportcsv::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&exportcsv::close_event_changed)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject exportcsv::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_exportcsv.data,
    qt_meta_data_exportcsv,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *exportcsv::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *exportcsv::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_exportcsv.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int exportcsv::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void exportcsv::dataReceived(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void exportcsv::close_event_changed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
