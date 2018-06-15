/****************************************************************************
** Meta object code from reading C++ file 'widget.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Lab5/widget.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Widget_t {
    QByteArrayData data[18];
    char stringdata0[266];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Widget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Widget_t qt_meta_stringdata_Widget = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Widget"
QT_MOC_LITERAL(1, 7, 8), // "loadFile"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 8), // "filename"
QT_MOC_LITERAL(4, 26, 29), // "on_placeRoundedButton_clicked"
QT_MOC_LITERAL(5, 56, 25), // "on_openFileButton_clicked"
QT_MOC_LITERAL(6, 82, 31), // "on_startTraversalButton_clicked"
QT_MOC_LITERAL(7, 114, 15), // "on_curentVertex"
QT_MOC_LITERAL(8, 130, 7), // "Vertex*"
QT_MOC_LITERAL(9, 138, 1), // "v"
QT_MOC_LITERAL(10, 140, 13), // "on_curentEdge"
QT_MOC_LITERAL(11, 154, 5), // "Edge*"
QT_MOC_LITERAL(12, 160, 1), // "e"
QT_MOC_LITERAL(13, 162, 16), // "on_repaintVertex"
QT_MOC_LITERAL(14, 179, 14), // "on_repaintEdge"
QT_MOC_LITERAL(15, 194, 30), // "on_restoreColorsButton_clicked"
QT_MOC_LITERAL(16, 225, 19), // "on_traversalStarted"
QT_MOC_LITERAL(17, 245, 20) // "on_traversalFinished"

    },
    "Widget\0loadFile\0\0filename\0"
    "on_placeRoundedButton_clicked\0"
    "on_openFileButton_clicked\0"
    "on_startTraversalButton_clicked\0"
    "on_curentVertex\0Vertex*\0v\0on_curentEdge\0"
    "Edge*\0e\0on_repaintVertex\0on_repaintEdge\0"
    "on_restoreColorsButton_clicked\0"
    "on_traversalStarted\0on_traversalFinished"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Widget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x08 /* Private */,
       4,    0,   72,    2, 0x08 /* Private */,
       5,    0,   73,    2, 0x08 /* Private */,
       6,    0,   74,    2, 0x08 /* Private */,
       7,    1,   75,    2, 0x08 /* Private */,
      10,    1,   78,    2, 0x08 /* Private */,
      13,    1,   81,    2, 0x08 /* Private */,
      14,    1,   84,    2, 0x08 /* Private */,
      15,    0,   87,    2, 0x08 /* Private */,
      16,    0,   88,    2, 0x08 /* Private */,
      17,    0,   89,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Widget *_t = static_cast<Widget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->loadFile((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->on_placeRoundedButton_clicked(); break;
        case 2: _t->on_openFileButton_clicked(); break;
        case 3: _t->on_startTraversalButton_clicked(); break;
        case 4: _t->on_curentVertex((*reinterpret_cast< Vertex*(*)>(_a[1]))); break;
        case 5: _t->on_curentEdge((*reinterpret_cast< Edge*(*)>(_a[1]))); break;
        case 6: _t->on_repaintVertex((*reinterpret_cast< Vertex*(*)>(_a[1]))); break;
        case 7: _t->on_repaintEdge((*reinterpret_cast< Edge*(*)>(_a[1]))); break;
        case 8: _t->on_restoreColorsButton_clicked(); break;
        case 9: _t->on_traversalStarted(); break;
        case 10: _t->on_traversalFinished(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Widget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Widget.data,
      qt_meta_data_Widget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Widget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
