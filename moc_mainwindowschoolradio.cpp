/****************************************************************************
** Meta object code from reading C++ file 'mainwindowschoolradio.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindowschoolradio.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindowschoolradio.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ProcessStartThread_t {
    QByteArrayData data[1];
    char stringdata0[19];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ProcessStartThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ProcessStartThread_t qt_meta_stringdata_ProcessStartThread = {
    {
QT_MOC_LITERAL(0, 0, 18) // "ProcessStartThread"

    },
    "ProcessStartThread"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ProcessStartThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void ProcessStartThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject ProcessStartThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_ProcessStartThread.data,
      qt_meta_data_ProcessStartThread,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ProcessStartThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ProcessStartThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ProcessStartThread.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int ProcessStartThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_MainWindowSchoolRadio_t {
    QByteArrayData data[14];
    char stringdata0[294];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindowSchoolRadio_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindowSchoolRadio_t qt_meta_stringdata_MainWindowSchoolRadio = {
    {
QT_MOC_LITERAL(0, 0, 21), // "MainWindowSchoolRadio"
QT_MOC_LITERAL(1, 22, 10), // "updateTime"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 18), // "on_DurationChanged"
QT_MOC_LITERAL(4, 53, 8), // "duration"
QT_MOC_LITERAL(5, 62, 30), // "on_pushButtonRecording_clicked"
QT_MOC_LITERAL(6, 93, 41), // "on_horizontalSliderRecording_..."
QT_MOC_LITERAL(7, 135, 5), // "value"
QT_MOC_LITERAL(8, 141, 25), // "on_pushButtonPlay_clicked"
QT_MOC_LITERAL(9, 167, 28), // "on_pushButtonPlayDir_clicked"
QT_MOC_LITERAL(10, 196, 32), // "on_pushButtonTranslation_clicked"
QT_MOC_LITERAL(11, 229, 34), // "on_checkBoxMicrophone_stateCh..."
QT_MOC_LITERAL(12, 264, 4), // "arg1"
QT_MOC_LITERAL(13, 269, 24) // "on_toolButtonDir_clicked"

    },
    "MainWindowSchoolRadio\0updateTime\0\0"
    "on_DurationChanged\0duration\0"
    "on_pushButtonRecording_clicked\0"
    "on_horizontalSliderRecording_valueChanged\0"
    "value\0on_pushButtonPlay_clicked\0"
    "on_pushButtonPlayDir_clicked\0"
    "on_pushButtonTranslation_clicked\0"
    "on_checkBoxMicrophone_stateChanged\0"
    "arg1\0on_toolButtonDir_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindowSchoolRadio[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x08 /* Private */,
       3,    1,   60,    2, 0x08 /* Private */,
       5,    0,   63,    2, 0x08 /* Private */,
       6,    1,   64,    2, 0x08 /* Private */,
       8,    0,   67,    2, 0x08 /* Private */,
       9,    0,   68,    2, 0x08 /* Private */,
      10,    0,   69,    2, 0x08 /* Private */,
      11,    1,   70,    2, 0x08 /* Private */,
      13,    0,   73,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void,

       0        // eod
};

void MainWindowSchoolRadio::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindowSchoolRadio *_t = static_cast<MainWindowSchoolRadio *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateTime(); break;
        case 1: _t->on_DurationChanged((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 2: _t->on_pushButtonRecording_clicked(); break;
        case 3: _t->on_horizontalSliderRecording_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_pushButtonPlay_clicked(); break;
        case 5: _t->on_pushButtonPlayDir_clicked(); break;
        case 6: _t->on_pushButtonTranslation_clicked(); break;
        case 7: _t->on_checkBoxMicrophone_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_toolButtonDir_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindowSchoolRadio::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindowSchoolRadio.data,
      qt_meta_data_MainWindowSchoolRadio,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindowSchoolRadio::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindowSchoolRadio::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindowSchoolRadio.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindowSchoolRadio::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
