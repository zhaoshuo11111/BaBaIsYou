/****************************************************************************
** Meta object code from reading C++ file 'term_borad.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../term_borad.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'term_borad.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Term_Borad_t {
    QByteArrayData data[8];
    char stringdata0[133];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Term_Borad_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Term_Borad_t qt_meta_stringdata_Term_Borad = {
    {
QT_MOC_LITERAL(0, 0, 10), // "Term_Borad"
QT_MOC_LITERAL(1, 11, 14), // "back_to_editor"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 11), // "have_chosen"
QT_MOC_LITERAL(4, 39, 23), // "on_pushButton_4_clicked"
QT_MOC_LITERAL(5, 63, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(6, 85, 23), // "on_pushButton_3_clicked"
QT_MOC_LITERAL(7, 109, 23) // "on_pushButton_2_clicked"

    },
    "Term_Borad\0back_to_editor\0\0have_chosen\0"
    "on_pushButton_4_clicked\0on_pushButton_clicked\0"
    "on_pushButton_3_clicked\0on_pushButton_2_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Term_Borad[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    0,   45,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   46,    2, 0x08 /* Private */,
       5,    0,   47,    2, 0x08 /* Private */,
       6,    0,   48,    2, 0x08 /* Private */,
       7,    0,   49,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Term_Borad::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Term_Borad *_t = static_cast<Term_Borad *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->back_to_editor(); break;
        case 1: _t->have_chosen(); break;
        case 2: _t->on_pushButton_4_clicked(); break;
        case 3: _t->on_pushButton_clicked(); break;
        case 4: _t->on_pushButton_3_clicked(); break;
        case 5: _t->on_pushButton_2_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Term_Borad::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Term_Borad::back_to_editor)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Term_Borad::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Term_Borad::have_chosen)) {
                *result = 1;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject Term_Borad::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Term_Borad.data,
      qt_meta_data_Term_Borad,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Term_Borad::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Term_Borad::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Term_Borad.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Term_Borad::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void Term_Borad::back_to_editor()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Term_Borad::have_chosen()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
