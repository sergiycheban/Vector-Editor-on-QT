/****************************************************************************
** Meta object code from reading C++ file 'workplace.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../workplace.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'workplace.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WorkPlace_t {
    QByteArrayData data[15];
    char stringdata0[185];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WorkPlace_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WorkPlace_t qt_meta_stringdata_WorkPlace = {
    {
QT_MOC_LITERAL(0, 0, 9), // "WorkPlace"
QT_MOC_LITERAL(1, 10, 23), // "previousPositionChanged"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 20), // "currentActionChanged"
QT_MOC_LITERAL(4, 56, 16), // "signalSelectItem"
QT_MOC_LITERAL(5, 73, 14), // "QGraphicsItem*"
QT_MOC_LITERAL(6, 88, 4), // "item"
QT_MOC_LITERAL(7, 93, 19), // "signalNewSelectItem"
QT_MOC_LITERAL(8, 113, 13), // "deselectItems"
QT_MOC_LITERAL(9, 127, 8), // "slotMove"
QT_MOC_LITERAL(10, 136, 11), // "signalOwner"
QT_MOC_LITERAL(11, 148, 2), // "dx"
QT_MOC_LITERAL(12, 151, 2), // "dy"
QT_MOC_LITERAL(13, 154, 13), // "currentAction"
QT_MOC_LITERAL(14, 168, 16) // "previousPosition"

    },
    "WorkPlace\0previousPositionChanged\0\0"
    "currentActionChanged\0signalSelectItem\0"
    "QGraphicsItem*\0item\0signalNewSelectItem\0"
    "deselectItems\0slotMove\0signalOwner\0"
    "dx\0dy\0currentAction\0previousPosition"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WorkPlace[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       2,   62, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    1,   45,    2, 0x06 /* Public */,
       4,    1,   48,    2, 0x06 /* Public */,
       7,    1,   51,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   54,    2, 0x08 /* Private */,
       9,    3,   55,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 5,    6,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5, QMetaType::QReal, QMetaType::QReal,   10,   11,   12,

 // properties: name, type, flags
      13, QMetaType::Int, 0x00495103,
      14, QMetaType::QPointF, 0x00495103,

 // properties: notify_signal_id
       1,
       0,

       0        // eod
};

void WorkPlace::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WorkPlace *_t = static_cast<WorkPlace *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->previousPositionChanged(); break;
        case 1: _t->currentActionChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->signalSelectItem((*reinterpret_cast< QGraphicsItem*(*)>(_a[1]))); break;
        case 3: _t->signalNewSelectItem((*reinterpret_cast< QGraphicsItem*(*)>(_a[1]))); break;
        case 4: _t->deselectItems(); break;
        case 5: _t->slotMove((*reinterpret_cast< QGraphicsItem*(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])),(*reinterpret_cast< qreal(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QGraphicsItem* >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QGraphicsItem* >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QGraphicsItem* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (WorkPlace::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WorkPlace::previousPositionChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (WorkPlace::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WorkPlace::currentActionChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (WorkPlace::*_t)(QGraphicsItem * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WorkPlace::signalSelectItem)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (WorkPlace::*_t)(QGraphicsItem * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WorkPlace::signalNewSelectItem)) {
                *result = 3;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        WorkPlace *_t = static_cast<WorkPlace *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->currentAction(); break;
        case 1: *reinterpret_cast< QPointF*>(_v) = _t->previousPosition(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        WorkPlace *_t = static_cast<WorkPlace *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setCurrentAction(*reinterpret_cast< int*>(_v)); break;
        case 1: _t->setPreviousPosition(*reinterpret_cast< QPointF*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject WorkPlace::staticMetaObject = {
    { &QGraphicsScene::staticMetaObject, qt_meta_stringdata_WorkPlace.data,
      qt_meta_data_WorkPlace,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *WorkPlace::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WorkPlace::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WorkPlace.stringdata0))
        return static_cast<void*>(this);
    return QGraphicsScene::qt_metacast(_clname);
}

int WorkPlace::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsScene::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void WorkPlace::previousPositionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void WorkPlace::currentActionChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void WorkPlace::signalSelectItem(QGraphicsItem * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void WorkPlace::signalNewSelectItem(QGraphicsItem * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
