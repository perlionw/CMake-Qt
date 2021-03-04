/****************************************************************************
** Meta object code from reading C++ file 'DataView.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "DataView.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DataView.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_DataView_t {
    QByteArrayData data[6];
    char stringdata0[79];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DataView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DataView_t qt_meta_stringdata_DataView = {
    {
QT_MOC_LITERAL(0, 0, 8), // "DataView"
QT_MOC_LITERAL(1, 9, 17), // "StationDeviceSlot"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 13), // "RobotDataSlot"
QT_MOC_LITERAL(4, 42, 18), // "GetControlModeSlot"
QT_MOC_LITERAL(5, 61, 17) // "GetTaskStatusSlot"

    },
    "DataView\0StationDeviceSlot\0\0RobotDataSlot\0"
    "GetControlModeSlot\0GetTaskStatusSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DataView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x0a /* Public */,
       3,    1,   37,    2, 0x0a /* Public */,
       4,    0,   40,    2, 0x0a /* Public */,
       5,    0,   41,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DataView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DataView *_t = static_cast<DataView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->StationDeviceSlot((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->RobotDataSlot((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->GetControlModeSlot(); break;
        case 3: _t->GetTaskStatusSlot(); break;
        default: ;
        }
    }
}

const QMetaObject DataView::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_DataView.data,
      qt_meta_data_DataView,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DataView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DataView::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DataView.stringdata0))
        return static_cast<void*>(const_cast< DataView*>(this));
    return QWidget::qt_metacast(_clname);
}

int DataView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
