/****************************************************************************
** Meta object code from reading C++ file 'correctui.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../correctui.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'correctui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CorrectUI_t {
    QByteArrayData data[12];
    char stringdata[183];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CorrectUI_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CorrectUI_t qt_meta_stringdata_CorrectUI = {
    {
QT_MOC_LITERAL(0, 0, 9), // "CorrectUI"
QT_MOC_LITERAL(1, 10, 20), // "imageNameList_SIGNAL"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 20), // "parameterName_SIGNAL"
QT_MOC_LITERAL(4, 53, 15), // "newImage_SIGNAL"
QT_MOC_LITERAL(5, 69, 14), // "loadImage_SLOT"
QT_MOC_LITERAL(6, 84, 18), // "imageNameList_SLOT"
QT_MOC_LITERAL(7, 103, 18), // "loadParameter_SLOT"
QT_MOC_LITERAL(8, 122, 18), // "parameterName_SLOT"
QT_MOC_LITERAL(9, 141, 13), // "clearALL_SLOT"
QT_MOC_LITERAL(10, 155, 14), // "imageShow_SLOT"
QT_MOC_LITERAL(11, 170, 12) // "correct_SLOT"

    },
    "CorrectUI\0imageNameList_SIGNAL\0\0"
    "parameterName_SIGNAL\0newImage_SIGNAL\0"
    "loadImage_SLOT\0imageNameList_SLOT\0"
    "loadParameter_SLOT\0parameterName_SLOT\0"
    "clearALL_SLOT\0imageShow_SLOT\0correct_SLOT"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CorrectUI[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,
       3,    0,   65,    2, 0x06 /* Public */,
       4,    0,   66,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   67,    2, 0x08 /* Private */,
       6,    0,   68,    2, 0x08 /* Private */,
       7,    0,   69,    2, 0x08 /* Private */,
       8,    0,   70,    2, 0x08 /* Private */,
       9,    0,   71,    2, 0x08 /* Private */,
      10,    0,   72,    2, 0x08 /* Private */,
      11,    0,   73,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CorrectUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CorrectUI *_t = static_cast<CorrectUI *>(_o);
        switch (_id) {
        case 0: _t->imageNameList_SIGNAL(); break;
        case 1: _t->parameterName_SIGNAL(); break;
        case 2: _t->newImage_SIGNAL(); break;
        case 3: _t->loadImage_SLOT(); break;
        case 4: _t->imageNameList_SLOT(); break;
        case 5: _t->loadParameter_SLOT(); break;
        case 6: _t->parameterName_SLOT(); break;
        case 7: _t->clearALL_SLOT(); break;
        case 8: _t->imageShow_SLOT(); break;
        case 9: _t->correct_SLOT(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CorrectUI::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CorrectUI::imageNameList_SIGNAL)) {
                *result = 0;
            }
        }
        {
            typedef void (CorrectUI::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CorrectUI::parameterName_SIGNAL)) {
                *result = 1;
            }
        }
        {
            typedef void (CorrectUI::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CorrectUI::newImage_SIGNAL)) {
                *result = 2;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject CorrectUI::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_CorrectUI.data,
      qt_meta_data_CorrectUI,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CorrectUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CorrectUI::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CorrectUI.stringdata))
        return static_cast<void*>(const_cast< CorrectUI*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int CorrectUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void CorrectUI::imageNameList_SIGNAL()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void CorrectUI::parameterName_SIGNAL()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void CorrectUI::newImage_SIGNAL()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
