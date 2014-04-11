/****************************************************************************
** Meta object code from reading C++ file 'MyGLWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MyGLWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MyGLWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MyGLWidget_t {
    QByteArrayData data[15];
    char stringdata[91];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_MyGLWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_MyGLWidget_t qt_meta_stringdata_MyGLWidget = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 6),
QT_MOC_LITERAL(2, 18, 0),
QT_MOC_LITERAL(3, 19, 4),
QT_MOC_LITERAL(4, 24, 6),
QT_MOC_LITERAL(5, 31, 4),
QT_MOC_LITERAL(6, 36, 6),
QT_MOC_LITERAL(7, 43, 4),
QT_MOC_LITERAL(8, 48, 3),
QT_MOC_LITERAL(9, 52, 5),
QT_MOC_LITERAL(10, 58, 3),
QT_MOC_LITERAL(11, 62, 4),
QT_MOC_LITERAL(12, 67, 10),
QT_MOC_LITERAL(13, 78, 6),
QT_MOC_LITERAL(14, 85, 4)
    },
    "MyGLWidget\0lXDown\0\0lXUp\0lYDown\0lYUp\0"
    "lZDown\0lZUp\0rLR\0value\0rUD\0zoom\0"
    "updateFile\0string\0file\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyGLWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x0a,
       3,    0,   65,    2, 0x0a,
       4,    0,   66,    2, 0x0a,
       5,    0,   67,    2, 0x0a,
       6,    0,   68,    2, 0x0a,
       7,    0,   69,    2, 0x0a,
       8,    1,   70,    2, 0x0a,
      10,    1,   73,    2, 0x0a,
      11,    1,   76,    2, 0x0a,
      12,    1,   79,    2, 0x0a,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, 0x80000000 | 13,   14,

       0        // eod
};

void MyGLWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MyGLWidget *_t = static_cast<MyGLWidget *>(_o);
        switch (_id) {
        case 0: _t->lXDown(); break;
        case 1: _t->lXUp(); break;
        case 2: _t->lYDown(); break;
        case 3: _t->lYUp(); break;
        case 4: _t->lZDown(); break;
        case 5: _t->lZUp(); break;
        case 6: _t->rLR((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->rUD((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->zoom((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->updateFile((*reinterpret_cast< string(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject MyGLWidget::staticMetaObject = {
    { &QGLWidget::staticMetaObject, qt_meta_stringdata_MyGLWidget.data,
      qt_meta_data_MyGLWidget,  qt_static_metacall, 0, 0}
};


const QMetaObject *MyGLWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyGLWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MyGLWidget.stringdata))
        return static_cast<void*>(const_cast< MyGLWidget*>(this));
    return QGLWidget::qt_metacast(_clname);
}

int MyGLWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
