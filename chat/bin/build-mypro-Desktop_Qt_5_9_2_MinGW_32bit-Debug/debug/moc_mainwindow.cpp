/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../mypro/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[18];
    char stringdata0[193];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 9), // "on_conned"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 12), // "on_disconned"
QT_MOC_LITERAL(4, 35, 12), // "on_readyread"
QT_MOC_LITERAL(5, 48, 6), // "login*"
QT_MOC_LITERAL(6, 55, 19), // "on_btn_exit_clicked"
QT_MOC_LITERAL(7, 75, 6), // "secret"
QT_MOC_LITERAL(8, 82, 8), // "QString&"
QT_MOC_LITERAL(9, 91, 11), // "writeOffMsg"
QT_MOC_LITERAL(10, 103, 6), // "sender"
QT_MOC_LITERAL(11, 110, 8), // "receiver"
QT_MOC_LITERAL(12, 119, 3), // "msg"
QT_MOC_LITERAL(13, 123, 10), // "readOffMsg"
QT_MOC_LITERAL(14, 134, 12), // "QDataStream&"
QT_MOC_LITERAL(15, 147, 3), // "dst"
QT_MOC_LITERAL(16, 151, 19), // "on_btn_save_clicked"
QT_MOC_LITERAL(17, 171, 21) // "on_btn_update_clicked"

    },
    "MainWindow\0on_conned\0\0on_disconned\0"
    "on_readyread\0login*\0on_btn_exit_clicked\0"
    "secret\0QString&\0writeOffMsg\0sender\0"
    "receiver\0msg\0readOffMsg\0QDataStream&\0"
    "dst\0on_btn_save_clicked\0on_btn_update_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x08 /* Private */,
       3,    0,   60,    2, 0x08 /* Private */,
       4,    1,   61,    2, 0x08 /* Private */,
       6,    0,   64,    2, 0x08 /* Private */,
       7,    1,   65,    2, 0x08 /* Private */,
       9,    3,   68,    2, 0x08 /* Private */,
      13,    2,   75,    2, 0x08 /* Private */,
      16,    0,   80,    2, 0x08 /* Private */,
      17,    0,   81,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    2,
    QMetaType::Void, 0x80000000 | 8, 0x80000000 | 8, 0x80000000 | 8,   10,   11,   12,
    QMetaType::Void, 0x80000000 | 8, 0x80000000 | 14,   11,   15,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_conned(); break;
        case 1: _t->on_disconned(); break;
        case 2: _t->on_readyread((*reinterpret_cast< login*(*)>(_a[1]))); break;
        case 3: _t->on_btn_exit_clicked(); break;
        case 4: _t->secret((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->writeOffMsg((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 6: _t->readOffMsg((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QDataStream(*)>(_a[2]))); break;
        case 7: _t->on_btn_save_clicked(); break;
        case 8: _t->on_btn_update_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< login* >(); break;
            }
            break;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
