/****************************************************************************
** Meta object code from reading C++ file 'TaskControlView.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "TaskControlView.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TaskControlView.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TaskControlView_t {
    QByteArrayData data[20];
    char stringdata0[302];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TaskControlView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TaskControlView_t qt_meta_stringdata_TaskControlView = {
    {
QT_MOC_LITERAL(0, 0, 15), // "TaskControlView"
QT_MOC_LITERAL(1, 16, 13), // "TaskStartSlot"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 13), // "TaskPauseSlot"
QT_MOC_LITERAL(4, 45, 15), // "TaskRestartSlot"
QT_MOC_LITERAL(5, 61, 14), // "TaskCancelSlot"
QT_MOC_LITERAL(6, 76, 18), // "TaskAutoChargeSlot"
QT_MOC_LITERAL(7, 95, 13), // "LoadPointSlot"
QT_MOC_LITERAL(8, 109, 15), // "GetTaskPathSlot"
QT_MOC_LITERAL(9, 125, 15), // "SearchPointSlot"
QT_MOC_LITERAL(10, 141, 16), // "LoadTaskPathSlot"
QT_MOC_LITERAL(11, 158, 16), // "SetTaskPointSlot"
QT_MOC_LITERAL(12, 175, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(13, 192, 19), // "DeleteTaskPointSlot"
QT_MOC_LITERAL(14, 212, 4), // "item"
QT_MOC_LITERAL(15, 217, 14), // "GetRobotIpSlot"
QT_MOC_LITERAL(16, 232, 17), // "GetTaskStatusSlot"
QT_MOC_LITERAL(17, 250, 13), // "TaskStatuSlot"
QT_MOC_LITERAL(18, 264, 21), // "GetTaskExcuteDataSlot"
QT_MOC_LITERAL(19, 286, 15) // "SetTaskPathSlot"

    },
    "TaskControlView\0TaskStartSlot\0\0"
    "TaskPauseSlot\0TaskRestartSlot\0"
    "TaskCancelSlot\0TaskAutoChargeSlot\0"
    "LoadPointSlot\0GetTaskPathSlot\0"
    "SearchPointSlot\0LoadTaskPathSlot\0"
    "SetTaskPointSlot\0QListWidgetItem*\0"
    "DeleteTaskPointSlot\0item\0GetRobotIpSlot\0"
    "GetTaskStatusSlot\0TaskStatuSlot\0"
    "GetTaskExcuteDataSlot\0SetTaskPathSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TaskControlView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   99,    2, 0x0a /* Public */,
       3,    0,  100,    2, 0x0a /* Public */,
       4,    0,  101,    2, 0x0a /* Public */,
       5,    0,  102,    2, 0x0a /* Public */,
       6,    0,  103,    2, 0x0a /* Public */,
       7,    0,  104,    2, 0x0a /* Public */,
       8,    0,  105,    2, 0x0a /* Public */,
       9,    0,  106,    2, 0x0a /* Public */,
      10,    0,  107,    2, 0x0a /* Public */,
      11,    1,  108,    2, 0x0a /* Public */,
      13,    1,  111,    2, 0x0a /* Public */,
       8,    1,  114,    2, 0x0a /* Public */,
      15,    1,  117,    2, 0x0a /* Public */,
      16,    0,  120,    2, 0x0a /* Public */,
      17,    2,  121,    2, 0x0a /* Public */,
      18,    0,  126,    2, 0x0a /* Public */,
      19,    0,  127,    2, 0x0a /* Public */,

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
    QMetaType::Void, 0x80000000 | 12,    2,
    QMetaType::Void, 0x80000000 | 12,   14,
    QMetaType::Void, 0x80000000 | 12,   14,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TaskControlView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TaskControlView *_t = static_cast<TaskControlView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->TaskStartSlot(); break;
        case 1: _t->TaskPauseSlot(); break;
        case 2: _t->TaskRestartSlot(); break;
        case 3: _t->TaskCancelSlot(); break;
        case 4: _t->TaskAutoChargeSlot(); break;
        case 5: _t->LoadPointSlot(); break;
        case 6: _t->GetTaskPathSlot(); break;
        case 7: _t->SearchPointSlot(); break;
        case 8: _t->LoadTaskPathSlot(); break;
        case 9: _t->SetTaskPointSlot((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 10: _t->DeleteTaskPointSlot((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 11: _t->GetTaskPathSlot((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 12: _t->GetRobotIpSlot((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 13: _t->GetTaskStatusSlot(); break;
        case 14: _t->TaskStatuSlot((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 15: _t->GetTaskExcuteDataSlot(); break;
        case 16: _t->SetTaskPathSlot(); break;
        default: ;
        }
    }
}

const QMetaObject TaskControlView::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_TaskControlView.data,
      qt_meta_data_TaskControlView,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TaskControlView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TaskControlView::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TaskControlView.stringdata0))
        return static_cast<void*>(const_cast< TaskControlView*>(this));
    return QWidget::qt_metacast(_clname);
}

int TaskControlView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
