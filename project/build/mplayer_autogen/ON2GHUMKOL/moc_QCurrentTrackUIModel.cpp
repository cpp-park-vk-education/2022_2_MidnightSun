/****************************************************************************
** Meta object code from reading C++ file 'QCurrentTrackUIModel.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../impl/QModels/QCurrentTrackUIModel.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QCurrentTrackUIModel.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QCurrentTrackUIModel_t {
    QByteArrayData data[11];
    char stringdata0[162];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QCurrentTrackUIModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QCurrentTrackUIModel_t qt_meta_stringdata_QCurrentTrackUIModel = {
    {
QT_MOC_LITERAL(0, 0, 20), // "QCurrentTrackUIModel"
QT_MOC_LITERAL(1, 21, 11), // "playClicked"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 12), // "pauseClicked"
QT_MOC_LITERAL(4, 47, 17), // "shuffleOffClicked"
QT_MOC_LITERAL(5, 65, 16), // "shuffleOnClicked"
QT_MOC_LITERAL(6, 82, 16), // "repeatOffClicked"
QT_MOC_LITERAL(7, 99, 15), // "repeatOnClicked"
QT_MOC_LITERAL(8, 115, 17), // "volumeSliderMoved"
QT_MOC_LITERAL(9, 133, 14), // "muteOffClicked"
QT_MOC_LITERAL(10, 148, 13) // "muteOnClicked"

    },
    "QCurrentTrackUIModel\0playClicked\0\0"
    "pauseClicked\0shuffleOffClicked\0"
    "shuffleOnClicked\0repeatOffClicked\0"
    "repeatOnClicked\0volumeSliderMoved\0"
    "muteOffClicked\0muteOnClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QCurrentTrackUIModel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,
       3,    0,   60,    2, 0x06 /* Public */,
       4,    0,   61,    2, 0x06 /* Public */,
       5,    0,   62,    2, 0x06 /* Public */,
       6,    0,   63,    2, 0x06 /* Public */,
       7,    0,   64,    2, 0x06 /* Public */,
       8,    1,   65,    2, 0x06 /* Public */,
       9,    0,   68,    2, 0x06 /* Public */,
      10,    0,   69,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QCurrentTrackUIModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QCurrentTrackUIModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->playClicked(); break;
        case 1: _t->pauseClicked(); break;
        case 2: _t->shuffleOffClicked(); break;
        case 3: _t->shuffleOnClicked(); break;
        case 4: _t->repeatOffClicked(); break;
        case 5: _t->repeatOnClicked(); break;
        case 6: _t->volumeSliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->muteOffClicked(); break;
        case 8: _t->muteOnClicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QCurrentTrackUIModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QCurrentTrackUIModel::playClicked)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (QCurrentTrackUIModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QCurrentTrackUIModel::pauseClicked)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (QCurrentTrackUIModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QCurrentTrackUIModel::shuffleOffClicked)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (QCurrentTrackUIModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QCurrentTrackUIModel::shuffleOnClicked)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (QCurrentTrackUIModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QCurrentTrackUIModel::repeatOffClicked)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (QCurrentTrackUIModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QCurrentTrackUIModel::repeatOnClicked)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (QCurrentTrackUIModel::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QCurrentTrackUIModel::volumeSliderMoved)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (QCurrentTrackUIModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QCurrentTrackUIModel::muteOffClicked)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (QCurrentTrackUIModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QCurrentTrackUIModel::muteOnClicked)) {
                *result = 8;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QCurrentTrackUIModel::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_QCurrentTrackUIModel.data,
    qt_meta_data_QCurrentTrackUIModel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QCurrentTrackUIModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QCurrentTrackUIModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QCurrentTrackUIModel.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QCurrentTrackUIModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void QCurrentTrackUIModel::playClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void QCurrentTrackUIModel::pauseClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void QCurrentTrackUIModel::shuffleOffClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void QCurrentTrackUIModel::shuffleOnClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void QCurrentTrackUIModel::repeatOffClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void QCurrentTrackUIModel::repeatOnClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void QCurrentTrackUIModel::volumeSliderMoved(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void QCurrentTrackUIModel::muteOffClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void QCurrentTrackUIModel::muteOnClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
