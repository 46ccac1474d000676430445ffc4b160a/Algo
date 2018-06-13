/****************************************************************************
** Meta object code from reading C++ file 'graphtraversal.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Lab5/graphtraversal.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'graphtraversal.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GraphTraversal_t {
    QByteArrayData data[11];
    char stringdata0[114];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GraphTraversal_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GraphTraversal_t qt_meta_stringdata_GraphTraversal = {
    {
QT_MOC_LITERAL(0, 0, 14), // "GraphTraversal"
QT_MOC_LITERAL(1, 15, 13), // "repaintVertex"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 7), // "Vertex*"
QT_MOC_LITERAL(4, 38, 11), // "repaintEdge"
QT_MOC_LITERAL(5, 50, 5), // "Edge*"
QT_MOC_LITERAL(6, 56, 12), // "curentVertex"
QT_MOC_LITERAL(7, 69, 10), // "curentEdge"
QT_MOC_LITERAL(8, 80, 8), // "finished"
QT_MOC_LITERAL(9, 89, 12), // "deepthSearch"
QT_MOC_LITERAL(10, 102, 11) // "widthSearch"

    },
    "GraphTraversal\0repaintVertex\0\0Vertex*\0"
    "repaintEdge\0Edge*\0curentVertex\0"
    "curentEdge\0finished\0deepthSearch\0"
    "widthSearch"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GraphTraversal[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       4,    1,   52,    2, 0x06 /* Public */,
       6,    1,   55,    2, 0x06 /* Public */,
       7,    1,   58,    2, 0x06 /* Public */,
       8,    0,   61,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   62,    2, 0x0a /* Public */,
      10,    0,   63,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void GraphTraversal::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GraphTraversal *_t = static_cast<GraphTraversal *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->repaintVertex((*reinterpret_cast< Vertex*(*)>(_a[1]))); break;
        case 1: _t->repaintEdge((*reinterpret_cast< Edge*(*)>(_a[1]))); break;
        case 2: _t->curentVertex((*reinterpret_cast< Vertex*(*)>(_a[1]))); break;
        case 3: _t->curentEdge((*reinterpret_cast< Edge*(*)>(_a[1]))); break;
        case 4: _t->finished(); break;
        case 5: _t->deepthSearch(); break;
        case 6: _t->widthSearch(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (GraphTraversal::*_t)(Vertex * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GraphTraversal::repaintVertex)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (GraphTraversal::*_t)(Edge * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GraphTraversal::repaintEdge)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (GraphTraversal::*_t)(Vertex * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GraphTraversal::curentVertex)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (GraphTraversal::*_t)(Edge * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GraphTraversal::curentEdge)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (GraphTraversal::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GraphTraversal::finished)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject GraphTraversal::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_GraphTraversal.data,
      qt_meta_data_GraphTraversal,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *GraphTraversal::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GraphTraversal::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GraphTraversal.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int GraphTraversal::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void GraphTraversal::repaintVertex(Vertex * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GraphTraversal::repaintEdge(Edge * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void GraphTraversal::curentVertex(Vertex * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void GraphTraversal::curentEdge(Edge * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void GraphTraversal::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
