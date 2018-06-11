/****************************************************************************
** Meta object code from reading C++ file 'deepthfirst.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Lab5/deepthfirst.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'deepthfirst.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DeepthFirst_t {
    QByteArrayData data[8];
    char stringdata0[64];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DeepthFirst_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DeepthFirst_t qt_meta_stringdata_DeepthFirst = {
    {
QT_MOC_LITERAL(0, 0, 11), // "DeepthFirst"
QT_MOC_LITERAL(1, 12, 12), // "curentVertex"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 7), // "Vertex*"
QT_MOC_LITERAL(4, 34, 10), // "curentEdge"
QT_MOC_LITERAL(5, 45, 5), // "Edge*"
QT_MOC_LITERAL(6, 51, 8), // "finished"
QT_MOC_LITERAL(7, 60, 3) // "run"

    },
    "DeepthFirst\0curentVertex\0\0Vertex*\0"
    "curentEdge\0Edge*\0finished\0run"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DeepthFirst[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       4,    1,   37,    2, 0x06 /* Public */,
       6,    0,   40,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   41,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void DeepthFirst::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DeepthFirst *_t = static_cast<DeepthFirst *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->curentVertex((*reinterpret_cast< Vertex*(*)>(_a[1]))); break;
        case 1: _t->curentEdge((*reinterpret_cast< Edge*(*)>(_a[1]))); break;
        case 2: _t->finished(); break;
        case 3: _t->run(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (DeepthFirst::*_t)(Vertex * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DeepthFirst::curentVertex)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (DeepthFirst::*_t)(Edge * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DeepthFirst::curentEdge)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (DeepthFirst::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DeepthFirst::finished)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DeepthFirst::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_DeepthFirst.data,
      qt_meta_data_DeepthFirst,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *DeepthFirst::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DeepthFirst::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DeepthFirst.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int DeepthFirst::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void DeepthFirst::curentVertex(Vertex * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DeepthFirst::curentEdge(Edge * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void DeepthFirst::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
