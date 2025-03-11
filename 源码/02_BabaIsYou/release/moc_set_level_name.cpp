/****************************************************************************
** Meta object code from reading C++ file 'set_level_name.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../set_level_name.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'set_level_name.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Set_Level_Name_t {
    QByteArrayData data[7];
    char stringdata0[108];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Set_Level_Name_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Set_Level_Name_t qt_meta_stringdata_Set_Level_Name = {
    {
QT_MOC_LITERAL(0, 0, 14), // "Set_Level_Name"
QT_MOC_LITERAL(1, 15, 15), // "return_to_level"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 21), // "return_to_guide_scene"
QT_MOC_LITERAL(4, 54, 7), // "getname"
QT_MOC_LITERAL(5, 62, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(6, 84, 23) // "on_pushButton_2_clicked"

    },
    "Set_Level_Name\0return_to_level\0\0"
    "return_to_guide_scene\0getname\0"
    "on_pushButton_clicked\0on_pushButton_2_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Set_Level_Name[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    0,   40,    2, 0x06 /* Public */,
       4,    0,   41,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   42,    2, 0x08 /* Private */,
       6,    0,   43,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Set_Level_Name::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Set_Level_Name *_t = static_cast<Set_Level_Name *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->return_to_level(); break;
        case 1: _t->return_to_guide_scene(); break;
        case 2: _t->getname(); break;
        case 3: _t->on_pushButton_clicked(); break;
        case 4: _t->on_pushButton_2_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Set_Level_Name::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Set_Level_Name::return_to_level)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Set_Level_Name::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Set_Level_Name::return_to_guide_scene)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Set_Level_Name::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Set_Level_Name::getname)) {
                *result = 2;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject Set_Level_Name::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Set_Level_Name.data,
      qt_meta_data_Set_Level_Name,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Set_Level_Name::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Set_Level_Name::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Set_Level_Name.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Set_Level_Name::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void Set_Level_Name::return_to_level()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Set_Level_Name::return_to_guide_scene()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Set_Level_Name::getname()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
