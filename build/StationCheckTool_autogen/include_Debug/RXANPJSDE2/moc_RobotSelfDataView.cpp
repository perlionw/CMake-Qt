/****************************************************************************
** Meta object code from reading C++ file 'RobotSelfDataView.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "RobotSelfDataView.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'RobotSelfDataView.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_RobotSelfDataView_t {
    QByteArrayData data[8];
    char stringdata0[121];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RobotSelfDataView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RobotSelfDataView_t qt_meta_stringdata_RobotSelfDataView = {
    {
QT_MOC_LITERAL(0, 0, 17), // "RobotSelfDataView"
QT_MOC_LITERAL(1, 18, 18), // "BatteryInfoBtnSlot"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 16), // "SpeedInfoBtnSlot"
QT_MOC_LITERAL(4, 55, 14), // "PosInfoBtnSlot"
QT_MOC_LITERAL(5, 70, 18), // "MileageInfoBtnSlot"
QT_MOC_LITERAL(6, 89, 14), // "GasInfoBtnSlot"
QT_MOC_LITERAL(7, 104, 16) // "AlarmInfoBtnSlot"

    },
    "RobotSelfDataView\0BatteryInfoBtnSlot\0"
    "\0SpeedInfoBtnSlot\0PosInfoBtnSlot\0"
    "MileageInfoBtnSlot\0GasInfoBtnSlot\0"
    "AlarmInfoBtnSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RobotSelfDataView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x0a /* Public */,
       3,    0,   45,    2, 0x0a /* Public */,
       4,    0,   46,    2, 0x0a /* Public */,
       5,    0,   47,    2, 0x0a /* Public */,
       6,    0,   48,    2, 0x0a /* Public */,
       7,    0,   49,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void RobotSelfDataView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RobotSelfDataView *_t = static_cast<RobotSelfDataView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->BatteryInfoBtnSlot(); break;
        case 1: _t->SpeedInfoBtnSlot(); break;
        case 2: _t->PosInfoBtnSlot(); break;
        case 3: _t->MileageInfoBtnSlot(); break;
        case 4: _t->GasInfoBtnSlot(); break;
        case 5: _t->AlarmInfoBtnSlot(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject RobotSelfDataView::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_RobotSelfDataView.data,
      qt_meta_data_RobotSelfDataView,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *RobotSelfDataView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RobotSelfDataView::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_RobotSelfDataView.stringdata0))
        return static_cast<void*>(const_cast< RobotSelfDataView*>(this));
    return QWidget::qt_metacast(_clname);
}

int RobotSelfDataView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
