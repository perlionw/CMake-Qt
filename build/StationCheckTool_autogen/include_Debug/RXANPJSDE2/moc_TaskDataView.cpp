/****************************************************************************
** Meta object code from reading C++ file 'TaskDataView.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "TaskDataView.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TaskDataView.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TaskDataView_t {
    QByteArrayData data[7];
    char stringdata0[118];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TaskDataView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TaskDataView_t qt_meta_stringdata_TaskDataView = {
    {
QT_MOC_LITERAL(0, 0, 12), // "TaskDataView"
QT_MOC_LITERAL(1, 13, 18), // "MapAreaInfoBtnSlot"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 18), // "MapEdgeInfoBtnSlot"
QT_MOC_LITERAL(4, 52, 20), // "DockPointInfoBtnSlot"
QT_MOC_LITERAL(5, 73, 21), // "PatrolAreaInfoBtnSlot"
QT_MOC_LITERAL(6, 95, 22) // "PatrolPointInfoBtnSlot"

    },
    "TaskDataView\0MapAreaInfoBtnSlot\0\0"
    "MapEdgeInfoBtnSlot\0DockPointInfoBtnSlot\0"
    "PatrolAreaInfoBtnSlot\0PatrolPointInfoBtnSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TaskDataView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x0a /* Public */,
       3,    0,   40,    2, 0x0a /* Public */,
       4,    0,   41,    2, 0x0a /* Public */,
       5,    0,   42,    2, 0x0a /* Public */,
       6,    0,   43,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TaskDataView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TaskDataView *_t = static_cast<TaskDataView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->MapAreaInfoBtnSlot(); break;
        case 1: _t->MapEdgeInfoBtnSlot(); break;
        case 2: _t->DockPointInfoBtnSlot(); break;
        case 3: _t->PatrolAreaInfoBtnSlot(); break;
        case 4: _t->PatrolPointInfoBtnSlot(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject TaskDataView::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_TaskDataView.data,
      qt_meta_data_TaskDataView,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TaskDataView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TaskDataView::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TaskDataView.stringdata0))
        return static_cast<void*>(const_cast< TaskDataView*>(this));
    return QWidget::qt_metacast(_clname);
}

int TaskDataView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
