/****************************************************************************
** Meta object code from reading C++ file 'dotsignal.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../dotsignal.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dotsignal.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Dotsignal_t {
    QByteArrayData data[10];
    char stringdata0[115];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Dotsignal_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Dotsignal_t qt_meta_stringdata_Dotsignal = {
    {
QT_MOC_LITERAL(0, 0, 9), // "Dotsignal"
QT_MOC_LITERAL(1, 10, 23), // "previousPositionChanged"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 18), // "signalMouseRelease"
QT_MOC_LITERAL(4, 54, 10), // "signalMove"
QT_MOC_LITERAL(5, 65, 14), // "QGraphicsItem*"
QT_MOC_LITERAL(6, 80, 11), // "signalOwner"
QT_MOC_LITERAL(7, 92, 2), // "dx"
QT_MOC_LITERAL(8, 95, 2), // "dy"
QT_MOC_LITERAL(9, 98, 16) // "previousPosition"

    },
    "Dotsignal\0previousPositionChanged\0\0"
    "signalMouseRelease\0signalMove\0"
    "QGraphicsItem*\0signalOwner\0dx\0dy\0"
    "previousPosition"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Dotsignal[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       1,   38, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06 /* Public */,
       3,    0,   30,    2, 0x06 /* Public */,
       4,    3,   31,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5, QMetaType::QReal, QMetaType::QReal,    6,    7,    8,

 // properties: name, type, flags
       9, QMetaType::QPointF, 0x00495103,

 // properties: notify_signal_id
       0,

       0        // eod
};

void Dotsignal::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Dotsignal *_t = static_cast<Dotsignal *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->previousPositionChanged(); break;
        case 1: _t->signalMouseRelease(); break;
        case 2: _t->signalMove((*reinterpret_cast< QGraphicsItem*(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])),(*reinterpret_cast< qreal(*)>(_a[3]))); break;
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
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (Dotsignal::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Dotsignal::previousPositionChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Dotsignal::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Dotsignal::signalMouseRelease)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Dotsignal::*_t)(QGraphicsItem * , qreal , qreal );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Dotsignal::signalMove)) {
                *result = 2;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        Dotsignal *_t = static_cast<Dotsignal *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QPointF*>(_v) = _t->previousPosition(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        Dotsignal *_t = static_cast<Dotsignal *>(_o);
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

const QMetaObject Dotsignal::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Dotsignal.data,
      qt_meta_data_Dotsignal,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Dotsignal::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Dotsignal::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Dotsignal.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QGraphicsRectItem"))
        return static_cast< QGraphicsRectItem*>(this);
    return QObject::qt_metacast(_clname);
}

int Dotsignal::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
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
void Dotsignal::previousPositionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Dotsignal::signalMouseRelease()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Dotsignal::signalMove(QGraphicsItem * _t1, qreal _t2, qreal _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
