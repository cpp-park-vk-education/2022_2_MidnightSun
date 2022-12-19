/****************************************************************************
** Meta object code from reading C++ file 'QCurrentTrackController.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../project/impl/QControllers/QCurrentTrackController.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QCurrentTrackController.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QCurrentTrackController_t {
    QByteArrayData data[13];
    char stringdata0[132];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QCurrentTrackController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QCurrentTrackController_t qt_meta_stringdata_QCurrentTrackController = {
    {
QT_MOC_LITERAL(0, 0, 23), // "QCurrentTrackController"
QT_MOC_LITERAL(1, 24, 4), // "play"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 20), // "currentTrackPosition"
QT_MOC_LITERAL(4, 51, 5), // "pause"
QT_MOC_LITERAL(5, 57, 6), // "repeat"
QT_MOC_LITERAL(6, 64, 4), // "mute"
QT_MOC_LITERAL(7, 69, 11), // "setDuration"
QT_MOC_LITERAL(8, 81, 8), // "position"
QT_MOC_LITERAL(9, 90, 9), // "setVolume"
QT_MOC_LITERAL(10, 100, 7), // "shuffle"
QT_MOC_LITERAL(11, 108, 13), // "previousTrack"
QT_MOC_LITERAL(12, 122, 9) // "nextTrack"

    },
    "QCurrentTrackController\0play\0\0"
    "currentTrackPosition\0pause\0repeat\0"
    "mute\0setDuration\0position\0setVolume\0"
    "shuffle\0previousTrack\0nextTrack"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QCurrentTrackController[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x0a /* Public */,
       4,    1,   62,    2, 0x0a /* Public */,
       5,    1,   65,    2, 0x0a /* Public */,
       6,    1,   68,    2, 0x0a /* Public */,
       7,    2,   71,    2, 0x0a /* Public */,
       9,    2,   76,    2, 0x0a /* Public */,
      10,    0,   81,    2, 0x0a /* Public */,
      11,    0,   82,    2, 0x0a /* Public */,
      12,    0,   83,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    8,    3,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    8,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QCurrentTrackController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QCurrentTrackController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->play((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->pause((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->repeat((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->mute((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->setDuration((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->setVolume((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->shuffle(); break;
        case 7: _t->previousTrack(); break;
        case 8: _t->nextTrack(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QCurrentTrackController::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_QCurrentTrackController.data,
    qt_meta_data_QCurrentTrackController,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QCurrentTrackController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QCurrentTrackController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QCurrentTrackController.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QCurrentTrackController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
