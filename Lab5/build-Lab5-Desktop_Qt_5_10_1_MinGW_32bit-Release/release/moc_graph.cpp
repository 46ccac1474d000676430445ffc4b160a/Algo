/****************************************************************************
** Meta object code from reading C++ file 'graph.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Lab5/graph.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'graph.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Graph_t {
    QByteArrayData data[10];
    char stringdata0[68];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Graph_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Graph_t qt_meta_stringdata_Graph = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Graph"
QT_MOC_LITERAL(1, 6, 9), // "addVertex"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 7), // "Vertex*"
QT_MOC_LITERAL(4, 25, 1), // "v"
QT_MOC_LITERAL(5, 27, 7), // "addEdge"
QT_MOC_LITERAL(6, 35, 2), // "v1"
QT_MOC_LITERAL(7, 38, 2), // "v2"
QT_MOC_LITERAL(8, 41, 12), // "placeRounded"
QT_MOC_LITERAL(9, 54, 13) // "clearVertices"

    },
    "Graph\0addVertex\0\0Vertex*\0v\0addEdge\0"
    "v1\0v2\0placeRounded\0clearVertices"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Graph[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x0a /* Public */,
       1,    1,   47,    2, 0x0a /* Public */,
       5,    2,   50,    2, 0x0a /* Public */,
       5,    2,   55,    2, 0x0a /* Public */,
       8,    0,   60,    2, 0x0a /* Public */,
       9,    0,   61,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,    6,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    6,    7,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Graph::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Graph *_t = static_cast<Graph *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->addVertex((*reinterpret_cast< Vertex*(*)>(_a[1]))); break;
        case 1: _t->addVertex((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->addEdge((*reinterpret_cast< Vertex*(*)>(_a[1])),(*reinterpret_cast< Vertex*(*)>(_a[2]))); break;
        case 3: _t->addEdge((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 4: _t->placeRounded(); break;
        case 5: _t->clearVertices(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Graph::staticMetaObject = {
    { &QGraphicsScene::staticMetaObject, qt_meta_stringdata_Graph.data,
      qt_meta_data_Graph,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Graph::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Graph::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Graph.stringdata0))
        return static_cast<void*>(this);
    return QGraphicsScene::qt_metacast(_clname);
}

int Graph::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsScene::qt_metacall(_c, _id, _a);
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
