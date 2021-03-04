/****************************************************************************
** Meta object code from reading C++ file 'RobotControlView.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "RobotControlView.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'RobotControlView.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_RobotControlView_t {
    QByteArrayData data[13];
    char stringdata0[169];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RobotControlView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RobotControlView_t qt_meta_stringdata_RobotControlView = {
    {
QT_MOC_LITERAL(0, 0, 16), // "RobotControlView"
QT_MOC_LITERAL(1, 17, 11), // "ForwardSlot"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 12), // "BackwardSlot"
QT_MOC_LITERAL(4, 43, 8), // "LeftSlot"
QT_MOC_LITERAL(5, 52, 9), // "RightSlot"
QT_MOC_LITERAL(6, 62, 8), // "StopSlot"
QT_MOC_LITERAL(7, 71, 12), // "AutoModeSlot"
QT_MOC_LITERAL(8, 84, 14), // "ManualModeSlot"
QT_MOC_LITERAL(9, 99, 26), // "ReleaseCurrentRobotBtnSlot"
QT_MOC_LITERAL(10, 126, 16), // "RobotInfoBtnSlot"
QT_MOC_LITERAL(11, 143, 14), // "GetRobotIpSlot"
QT_MOC_LITERAL(12, 158, 10) // "GetRobotIp"

    },
    "RobotControlView\0ForwardSlot\0\0"
    "BackwardSlot\0LeftSlot\0RightSlot\0"
    "StopSlot\0AutoModeSlot\0ManualModeSlot\0"
    "ReleaseCurrentRobotBtnSlot\0RobotInfoBtnSlot\0"
    "GetRobotIpSlot\0GetRobotIp"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RobotControlView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x0a /* Public */,
       3,    0,   70,    2, 0x0a /* Public */,
       4,    0,   71,    2, 0x0a /* Public */,
       5,    0,   72,    2, 0x0a /* Public */,
       6,    0,   73,    2, 0x0a /* Public */,
       7,    0,   74,    2, 0x0a /* Public */,
       8,    0,   75,    2, 0x0a /* Public */,
       9,    0,   76,    2, 0x0a /* Public */,
      10,    0,   77,    2, 0x0a /* Public */,
      11,    1,   78,    2, 0x0a /* Public */,
      12,    0,   81,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::QStringList,

       0        // eod
};

void RobotControlView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RobotControlView *_t = static_cast<RobotControlView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ForwardSlot(); break;
        case 1: _t->BackwardSlot(); break;
        case 2: _t->LeftSlot(); break;
        case 3: _t->RightSlot(); break;
        case 4: _t->StopSlot(); break;
        case 5: _t->AutoModeSlot(); break;
        case 6: _t->ManualModeSlot(); break;
        case 7: _t->ReleaseCurrentRobotBtnSlot(); break;
        case 8: _t->RobotInfoBtnSlot(); break;
        case 9: _t->GetRobotIpSlot((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: { QStringList _r = _t->GetRobotIp();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObject RobotControlView::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_RobotControlView.data,
      qt_meta_data_RobotControlView,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *RobotControlView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RobotControlView::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_RobotControlView.stringdata0))
        return static_cast<void*>(const_cast< RobotControlView*>(this));
    return QWidget::qt_metacast(_clname);
}

int RobotControlView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
