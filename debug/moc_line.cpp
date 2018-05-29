/****************************************************************************
** Meta object code from reading C++ file 'line.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../line.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'line.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Line_t {
    QByteArrayData data[14];
    char stringdata0[124];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Line_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Line_t qt_meta_stringdata_Line = {
    {
QT_MOC_LITERAL(0, 0, 4), // "Line"
QT_MOC_LITERAL(1, 5, 23), // "previousPositionChanged"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 7), // "clicked"
QT_MOC_LITERAL(4, 38, 5), // "Line*"
QT_MOC_LITERAL(5, 44, 4), // "rect"
QT_MOC_LITERAL(6, 49, 10), // "signalMove"
QT_MOC_LITERAL(7, 60, 14), // "QGraphicsItem*"
QT_MOC_LITERAL(8, 75, 4), // "item"
QT_MOC_LITERAL(9, 80, 2), // "dx"
QT_MOC_LITERAL(10, 83, 2), // "dy"
QT_MOC_LITERAL(11, 86, 8), // "slotMove"
QT_MOC_LITERAL(12, 95, 11), // "signalOwner"
QT_MOC_LITERAL(13, 107, 16) // "previousPosition"

    },
    "Line\0previousPositionChanged\0\0clicked\0"
    "Line*\0rect\0signalMove\0QGraphicsItem*\0"
    "item\0dx\0dy\0slotMove\0signalOwner\0"
    "previousPosition"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Line[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       1,   52, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    1,   35,    2, 0x06 /* Public */,
       6,    3,   38,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    3,   45,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 7, QMetaType::QReal, QMetaType::QReal,    8,    9,   10,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 7, QMetaType::QReal, QMetaType::QReal,   12,    9,   10,

 // properties: name, type, flags
      13, QMetaType::QPointF, 0x00495103,

 // properties: notify_signal_id
       0,

       0        // eod
};

void Line::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Line *_t = static_cast<Line *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->previousPositionChanged(); break;
        case 1: _t->clicked((*reinterpret_cast< Line*(*)>(_a[1]))); break;
        case 2: _t->signalMove((*reinterpret_cast< QGraphicsItem*(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])),(*reinterpret_cast< qreal(*)>(_a[3]))); break;
        case 3: _t->slotMove((*reinterpret_cast< QGraphicsItem*(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])),(*reinterpret_cast< qreal(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Line* >(); break;
            }
            break;
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
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (Line::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Line::previousPositionChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Line::*_t)(Line * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Line::clicked)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Line::*_t)(QGraphicsItem * , qreal , qreal );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Line::signalMove)) {
                *result = 2;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        Line *_t = static_cast<Line *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QPointF*>(_v) = _t->previousPosition(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        Line *_t = static_cast<Line *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setPreviousPosition(*reinterpret_cast< QPointF*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject Line::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Line.data,
      qt_meta_data_Line,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Line::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Line::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Line.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QGraphicsPathItem"))
        return static_cast< QGraphicsPathItem*>(this);
    return QObject::qt_metacast(_clname);
}

int Line::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void Line::previousPositionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Line::clicked(Line * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Line::signalMove(QGraphicsItem * _t1, qreal _t2, qreal _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
