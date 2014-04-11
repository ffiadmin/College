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
    QByteArrayData data[10];
    char stringdata[90];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_MyGLWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_MyGLWidget_t qt_meta_stringdata_MyGLWidget = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 13),
QT_MOC_LITERAL(2, 25, 0),
QT_MOC_LITERAL(3, 26, 8),
QT_MOC_LITERAL(4, 35, 7),
QT_MOC_LITERAL(5, 43, 9),
QT_MOC_LITERAL(6, 53, 9),
QT_MOC_LITERAL(7, 63, 10),
QT_MOC_LITERAL(8, 74, 6),
QT_MOC_LITERAL(9, 81, 7)
    },
    "MyGLWidget\0sendPlanarity\0\0loadFile\0"
    "orbitUp\0orbitDown\0orbitLeft\0orbitRight\0"
    "zoomIn\0zoomOut\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyGLWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       3,    1,   57,    2, 0x0a,
       4,    0,   60,    2, 0x0a,
       5,    0,   61,    2, 0x0a,
       6,    0,   62,    2, 0x0a,
       7,    0,   63,    2, 0x0a,
       8,    0,   64,    2, 0x0a,
       9,    0,   65,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MyGLWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MyGLWidget *_t = static_cast<MyGLWidget *>(_o);
        switch (_id) {
        case 0: _t->sendPlanarity((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->loadFile((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->orbitUp(); break;
        case 3: _t->orbitDown(); break;
        case 4: _t->orbitLeft(); break;
        case 5: _t->orbitRight(); break;
        case 6: _t->zoomIn(); break;
        case 7: _t->zoomOut(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MyGLWidget::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyGLWidget::sendPlanarity)) {
                *result = 0;
            }
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
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void MyGLWidget::sendPlanarity(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
