/****************************************************************************
** Meta object code from reading C++ file 'stationrobottool.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "stationrobottool.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'stationrobottool.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_StationRobotTool_t {
    QByteArrayData data[7];
    char stringdata0[81];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_StationRobotTool_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_StationRobotTool_t qt_meta_stringdata_StationRobotTool = {
    {
QT_MOC_LITERAL(0, 0, 16), // "StationRobotTool"
QT_MOC_LITERAL(1, 17, 12), // "ChangeModule"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(4, 48, 5), // "item1"
QT_MOC_LITERAL(5, 54, 6), // "count1"
QT_MOC_LITERAL(6, 61, 19) // "GetRobotTimeBtnSlot"

    },
    "StationRobotTool\0ChangeModule\0\0"
    "QTreeWidgetItem*\0item1\0count1\0"
    "GetRobotTimeBtnSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_StationRobotTool[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   24,    2, 0x0a /* Public */,
       6,    0,   29,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    4,    5,
    QMetaType::Void,

       0        // eod
};

void StationRobotTool::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        StationRobotTool *_t = static_cast<StationRobotTool *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ChangeModule((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->GetRobotTimeBtnSlot(); break;
        default: ;
        }
    }
}

const QMetaObject StationRobotTool::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_StationRobotTool.data,
      qt_meta_data_StationRobotTool,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *StationRobotTool::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *StationRobotTool::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_StationRobotTool.stringdata0))
        return static_cast<void*>(const_cast< StationRobotTool*>(this));
    return QWidget::qt_metacast(_clname);
}

int StationRobotTool::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
