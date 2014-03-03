/****************************************************************************
** Meta object code from reading C++ file 'MyLCD.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MyLCD.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MyLCD.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MyLCD_t {
    QByteArrayData data[6];
    char stringdata[44];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_MyLCD_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_MyLCD_t qt_meta_stringdata_MyLCD = {
    {
QT_MOC_LITERAL(0, 0, 5),
QT_MOC_LITERAL(1, 6, 4),
QT_MOC_LITERAL(2, 11, 0),
QT_MOC_LITERAL(3, 12, 8),
QT_MOC_LITERAL(4, 21, 9),
QT_MOC_LITERAL(5, 31, 11)
    },
    "MyLCD\0pass\0\0override\0increment\0"
    "increment10\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyLCD[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06,
       3,    1,   35,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       4,    0,   38,    2, 0x0a,
       5,    0,   39,    2, 0x0a,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MyLCD::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MyLCD *_t = static_cast<MyLCD *>(_o);
        switch (_id) {
        case 0: _t->pass(); break;
        case 1: _t->override((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->increment(); break;
        case 3: _t->increment10(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MyLCD::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyLCD::pass)) {
                *result = 0;
            }
        }
        {
            typedef void (MyLCD::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyLCD::override)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject MyLCD::staticMetaObject = {
    { &QLCDNumber::staticMetaObject, qt_meta_stringdata_MyLCD.data,
      qt_meta_data_MyLCD,  qt_static_metacall, 0, 0}
};


const QMetaObject *MyLCD::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyLCD::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MyLCD.stringdata))
        return static_cast<void*>(const_cast< MyLCD*>(this));
    return QLCDNumber::qt_metacast(_clname);
}

int MyLCD::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLCDNumber::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void MyLCD::pass()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void MyLCD::override(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
