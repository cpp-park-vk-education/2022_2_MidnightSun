/****************************************************************************
** Meta object code from reading C++ file 'CurrentTrack.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../project/impl/CurrentTrack.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CurrentTrack.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CurrentTrackUIModel_t {
    QByteArrayData data[8];
    char stringdata0[160];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CurrentTrackUIModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CurrentTrackUIModel_t qt_meta_stringdata_CurrentTrackUIModel = {
    {
QT_MOC_LITERAL(0, 0, 19), // "CurrentTrackUIModel"
QT_MOC_LITERAL(1, 20, 22), // "shuffleFunctionSuccess"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 28), // "previousTrackFunctionSuccess"
QT_MOC_LITERAL(4, 73, 19), // "playFunctionSuccess"
QT_MOC_LITERAL(5, 93, 24), // "nextTrackFunctionSuccess"
QT_MOC_LITERAL(6, 118, 21), // "repeatFunctionSuccess"
QT_MOC_LITERAL(7, 140, 19) // "muteFunctionSuccess"

    },
    "CurrentTrackUIModel\0shuffleFunctionSuccess\0"
    "\0previousTrackFunctionSuccess\0"
    "playFunctionSuccess\0nextTrackFunctionSuccess\0"
    "repeatFunctionSuccess\0muteFunctionSuccess"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CurrentTrackUIModel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    0,   45,    2, 0x06 /* Public */,
       4,    0,   46,    2, 0x06 /* Public */,
       5,    0,   47,    2, 0x06 /* Public */,
       6,    0,   48,    2, 0x06 /* Public */,
       7,    0,   49,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CurrentTrackUIModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CurrentTrackUIModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->shuffleFunctionSuccess(); break;
        case 1: _t->previousTrackFunctionSuccess(); break;
        case 2: _t->playFunctionSuccess(); break;
        case 3: _t->nextTrackFunctionSuccess(); break;
        case 4: _t->repeatFunctionSuccess(); break;
        case 5: _t->muteFunctionSuccess(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CurrentTrackUIModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CurrentTrackUIModel::shuffleFunctionSuccess)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CurrentTrackUIModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CurrentTrackUIModel::previousTrackFunctionSuccess)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (CurrentTrackUIModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CurrentTrackUIModel::playFunctionSuccess)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (CurrentTrackUIModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CurrentTrackUIModel::nextTrackFunctionSuccess)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (CurrentTrackUIModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CurrentTrackUIModel::repeatFunctionSuccess)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (CurrentTrackUIModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CurrentTrackUIModel::muteFunctionSuccess)) {
                *result = 5;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject CurrentTrackUIModel::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_CurrentTrackUIModel.data,
    qt_meta_data_CurrentTrackUIModel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CurrentTrackUIModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CurrentTrackUIModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CurrentTrackUIModel.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "ICurrentTrackUIModel"))
        return static_cast< ICurrentTrackUIModel*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int CurrentTrackUIModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void CurrentTrackUIModel::shuffleFunctionSuccess()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void CurrentTrackUIModel::previousTrackFunctionSuccess()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void CurrentTrackUIModel::playFunctionSuccess()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void CurrentTrackUIModel::nextTrackFunctionSuccess()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void CurrentTrackUIModel::repeatFunctionSuccess()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void CurrentTrackUIModel::muteFunctionSuccess()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}
struct qt_meta_stringdata_CurrentTrackController_t {
    QByteArrayData data[8];
    char stringdata0[73];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CurrentTrackController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CurrentTrackController_t qt_meta_stringdata_CurrentTrackController = {
    {
QT_MOC_LITERAL(0, 0, 22), // "CurrentTrackController"
QT_MOC_LITERAL(1, 23, 7), // "shuffle"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 13), // "previousTrack"
QT_MOC_LITERAL(4, 46, 4), // "play"
QT_MOC_LITERAL(5, 51, 9), // "nextTrack"
QT_MOC_LITERAL(6, 61, 6), // "repeat"
QT_MOC_LITERAL(7, 68, 4) // "mute"

    },
    "CurrentTrackController\0shuffle\0\0"
    "previousTrack\0play\0nextTrack\0repeat\0"
    "mute"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CurrentTrackController[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    0,   45,    2, 0x08 /* Private */,
       4,    0,   46,    2, 0x08 /* Private */,
       5,    0,   47,    2, 0x08 /* Private */,
       6,    0,   48,    2, 0x08 /* Private */,
       7,    0,   49,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CurrentTrackController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CurrentTrackController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->shuffle(); break;
        case 1: _t->previousTrack(); break;
        case 2: _t->play(); break;
        case 3: _t->nextTrack(); break;
        case 4: _t->repeat(); break;
        case 5: _t->mute(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject CurrentTrackController::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_CurrentTrackController.data,
    qt_meta_data_CurrentTrackController,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CurrentTrackController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CurrentTrackController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CurrentTrackController.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "ICurrentTrackController"))
        return static_cast< ICurrentTrackController*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int CurrentTrackController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
struct qt_meta_stringdata_CurrentTrackView_t {
    QByteArrayData data[8];
    char stringdata0[109];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CurrentTrackView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CurrentTrackView_t qt_meta_stringdata_CurrentTrackView = {
    {
QT_MOC_LITERAL(0, 0, 16), // "CurrentTrackView"
QT_MOC_LITERAL(1, 17, 14), // "shuffleClicked"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 20), // "previousTrackClicked"
QT_MOC_LITERAL(4, 54, 11), // "playClicked"
QT_MOC_LITERAL(5, 66, 16), // "nextTrackClicked"
QT_MOC_LITERAL(6, 83, 13), // "repeatClicked"
QT_MOC_LITERAL(7, 97, 11) // "muteClicked"

    },
    "CurrentTrackView\0shuffleClicked\0\0"
    "previousTrackClicked\0playClicked\0"
    "nextTrackClicked\0repeatClicked\0"
    "muteClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CurrentTrackView[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    0,   45,    2, 0x08 /* Private */,
       4,    0,   46,    2, 0x08 /* Private */,
       5,    0,   47,    2, 0x08 /* Private */,
       6,    0,   48,    2, 0x08 /* Private */,
       7,    0,   49,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CurrentTrackView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CurrentTrackView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->shuffleClicked(); break;
        case 1: _t->previousTrackClicked(); break;
        case 2: _t->playClicked(); break;
        case 3: _t->nextTrackClicked(); break;
        case 4: _t->repeatClicked(); break;
        case 5: _t->muteClicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject CurrentTrackView::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_CurrentTrackView.data,
    qt_meta_data_CurrentTrackView,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CurrentTrackView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CurrentTrackView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CurrentTrackView.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int CurrentTrackView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
