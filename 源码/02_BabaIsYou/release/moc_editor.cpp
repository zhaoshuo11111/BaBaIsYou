/****************************************************************************
** Meta object code from reading C++ file 'editor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../editor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'editor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_editor_t {
    QByteArrayData data[10];
    char stringdata0[188];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_editor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_editor_t qt_meta_stringdata_editor = {
    {
QT_MOC_LITERAL(0, 0, 6), // "editor"
QT_MOC_LITERAL(1, 7, 21), // "return_to_guide_scene"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 15), // "return_to_level"
QT_MOC_LITERAL(4, 46, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(5, 68, 23), // "on_pushButton_3_clicked"
QT_MOC_LITERAL(6, 92, 23), // "on_pushButton_5_clicked"
QT_MOC_LITERAL(7, 116, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(8, 140, 23), // "on_pushButton_6_clicked"
QT_MOC_LITERAL(9, 164, 23) // "on_pushButton_4_clicked"

    },
    "editor\0return_to_guide_scene\0\0"
    "return_to_level\0on_pushButton_clicked\0"
    "on_pushButton_3_clicked\0on_pushButton_5_clicked\0"
    "on_pushButton_2_clicked\0on_pushButton_6_clicked\0"
    "on_pushButton_4_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_editor[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    0,   55,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   56,    2, 0x08 /* Private */,
       5,    0,   57,    2, 0x08 /* Private */,
       6,    0,   58,    2, 0x08 /* Private */,
       7,    0,   59,    2, 0x08 /* Private */,
       8,    0,   60,    2, 0x08 /* Private */,
       9,    0,   61,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void editor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        editor *_t = static_cast<editor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->return_to_guide_scene(); break;
        case 1: _t->return_to_level(); break;
        case 2: _t->on_pushButton_clicked(); break;
        case 3: _t->on_pushButton_3_clicked(); break;
        case 4: _t->on_pushButton_5_clicked(); break;
        case 5: _t->on_pushButton_2_clicked(); break;
        case 6: _t->on_pushButton_6_clicked(); break;
        case 7: _t->on_pushButton_4_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (editor::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&editor::return_to_guide_scene)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (editor::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&editor::return_to_level)) {
                *result = 1;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject editor::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_editor.data,
      qt_meta_data_editor,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *editor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *editor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_editor.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int editor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void editor::return_to_guide_scene()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void editor::return_to_level()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
