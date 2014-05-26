/****************************************************************************
** Meta object code from reading C++ file 'FileTextBox.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../FileTextBox.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FileTextBox.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_FileTextBox_t {
    QByteArrayData data[5];
    char stringdata[46];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_FileTextBox_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_FileTextBox_t qt_meta_stringdata_FileTextBox = {
    {
QT_MOC_LITERAL(0, 0, 11),
QT_MOC_LITERAL(1, 12, 12),
QT_MOC_LITERAL(2, 25, 6),
QT_MOC_LITERAL(3, 32, 0),
QT_MOC_LITERAL(4, 33, 11)
    },
    "FileTextBox\0sendFilename\0string\0\0"
    "buttonInput\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FileTextBox[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    3, 0x06,

 // slots: name, argc, parameters, tag, flags
       4,    0,   27,    3, 0x0a,

 // signals: parameters
    0x80000000 | 2, 0x80000000 | 2,    3,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void FileTextBox::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FileTextBox *_t = static_cast<FileTextBox *>(_o);
        switch (_id) {
        case 0: { string _r = _t->sendFilename((*reinterpret_cast< string(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< string*>(_a[0]) = _r; }  break;
        case 1: _t->buttonInput(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef string (FileTextBox::*_t)(string );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FileTextBox::sendFilename)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject FileTextBox::staticMetaObject = {
    { &QLineEdit::staticMetaObject, qt_meta_stringdata_FileTextBox.data,
      qt_meta_data_FileTextBox,  qt_static_metacall, 0, 0}
};


const QMetaObject *FileTextBox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FileTextBox::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FileTextBox.stringdata))
        return static_cast<void*>(const_cast< FileTextBox*>(this));
    return QLineEdit::qt_metacast(_clname);
}

int FileTextBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLineEdit::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
string FileTextBox::sendFilename(string _t1)
{
    string _t0 = string();
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(&_t0)), const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
    return _t0;
}
QT_END_MOC_NAMESPACE
