/****************************************************************************
** Meta object code from reading C++ file 'rectangle.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../rectangle.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'rectangle.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Rectangle_t {
    QByteArrayData data[13];
    char stringdata0[125];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Rectangle_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Rectangle_t qt_meta_stringdata_Rectangle = {
    {
QT_MOC_LITERAL(0, 0, 9), // "Rectangle"
QT_MOC_LITERAL(1, 10, 11), // "rectChanged"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 10), // "Rectangle*"
QT_MOC_LITERAL(4, 34, 4), // "rect"
QT_MOC_LITERAL(5, 39, 23), // "previousPositionChanged"
QT_MOC_LITERAL(6, 63, 7), // "clicked"
QT_MOC_LITERAL(7, 71, 10), // "signalMove"
QT_MOC_LITERAL(8, 82, 14), // "QGraphicsItem*"
QT_MOC_LITERAL(9, 97, 4), // "item"
QT_MOC_LITERAL(10, 102, 2), // "dx"
QT_MOC_LITERAL(11, 105, 2), // "dy"
QT_MOC_LITERAL(12, 108, 16) // "previousPosition"

    },
    "Rectangle\0rectChanged\0\0Rectangle*\0"
    "rect\0previousPositionChanged\0clicked\0"
    "signalMove\0QGraphicsItem*\0item\0dx\0dy\0"
    "previousPosition"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Rectangle[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       1,   48, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       5,    0,   37,    2, 0x06 /* Public */,
       6,    1,   38,    2, 0x06 /* Public */,
       7,    3,   41,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 8, QMetaType::QReal, QMetaType::QReal,    9,   10,   11,

 // properties: name, type, flags
      12, QMetaType::QPointF, 0x00495103,

 // properties: notify_signal_id
       1,

       0        // eod
};

void Rectangle::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Rectangle *_t = static_cast<Rectangle *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->rectChanged((*reinterpret_cast< Rectangle*(*)>(_a[1]))); break;
        case 1: _t->previousPositionChanged(); break;
        case 2: _t->clicked((*reinterpret_cast< Rectangle*(*)>(_a[1]))); break;
        case 3: _t->signalMove((*reinterpret_cast< QGraphicsItem*(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])),(*reinterpret_cast< qreal(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Rectangle* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Rectangle* >(); break;
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
            typedef void (Rectangle::*_t)(Rectangle * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Rectangle::rectChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Rectangle::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Rectangle::previousPositionChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Rectangle::*_t)(Rectangle * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Rectangle::clicked)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (Rectangle::*_t)(QGraphicsItem * , qreal , qreal );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Rectangle::signalMove)) {
                *result = 3;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        Rectangle *_t = static_cast<Rectangle *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QPointF*>(_v) = _t->previousPosition(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        Rectangle *_t = static_cast<Rectangle *>(_o);
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

const QMetaObject Rectangle::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Rectangle.data,
      qt_meta_data_Rectangle,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Rectangle::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Rectangle::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Rectangle.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QGraphicsRectItem"))
        return static_cast< QGraphicsRectItem*>(this);
    return QObject::qt_metacast(_clname);
}

int Rectangle::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void Rectangle::rectChanged(Rectangle * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Rectangle::previousPositionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Rectangle::clicked(Rectangle * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Rectangle::signalMove(QGraphicsItem * _t1, qreal _t2, qreal _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
