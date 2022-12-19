/****************************************************************************
** Meta object code from reading C++ file 'QCurrentPlaylistController.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../project/impl/QControllers/QCurrentPlaylistController.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QCurrentPlaylistController.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QCurrentPlaylistController_t {
    QByteArrayData data[9];
    char stringdata0[91];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QCurrentPlaylistController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QCurrentPlaylistController_t qt_meta_stringdata_QCurrentPlaylistController = {
    {
QT_MOC_LITERAL(0, 0, 26), // "QCurrentPlaylistController"
QT_MOC_LITERAL(1, 27, 8), // "addTrack"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 11), // "std::string"
QT_MOC_LITERAL(4, 49, 4), // "path"
QT_MOC_LITERAL(5, 54, 11), // "deleteTrack"
QT_MOC_LITERAL(6, 66, 6), // "size_t"
QT_MOC_LITERAL(7, 73, 5), // "index"
QT_MOC_LITERAL(8, 79, 11) // "chooseTrack"

    },
    "QCurrentPlaylistController\0addTrack\0"
    "\0std::string\0path\0deleteTrack\0size_t\0"
    "index\0chooseTrack"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QCurrentPlaylistController[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x0a /* Public */,
       5,    1,   32,    2, 0x0a /* Public */,
       8,    1,   35,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 6,    7,

       0        // eod
};

void QCurrentPlaylistController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QCurrentPlaylistController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->addTrack((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 1: _t->deleteTrack((*reinterpret_cast< size_t(*)>(_a[1]))); break;
        case 2: _t->chooseTrack((*reinterpret_cast< size_t(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QCurrentPlaylistController::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_QCurrentPlaylistController.data,
    qt_meta_data_QCurrentPlaylistController,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QCurrentPlaylistController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QCurrentPlaylistController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QCurrentPlaylistController.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QCurrentPlaylistController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
