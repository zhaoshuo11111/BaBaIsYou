/****************************************************************************
** Meta object code from reading C++ file 'pause_scene.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../pause_scene.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pause_scene.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Pause_Scene_t {
    QByteArrayData data[11];
    char stringdata0[207];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Pause_Scene_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Pause_Scene_t qt_meta_stringdata_Pause_Scene = {
    {
QT_MOC_LITERAL(0, 0, 11), // "Pause_Scene"
QT_MOC_LITERAL(1, 12, 19), // "gameToChoose_signal"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 17), // "exitToGame_signal"
QT_MOC_LITERAL(4, 51, 18), // "gameToGuide_signal"
QT_MOC_LITERAL(5, 70, 14), // "restart_signal"
QT_MOC_LITERAL(6, 85, 22), // "testLevelToEdit_signal"
QT_MOC_LITERAL(7, 108, 27), // "on_b2_exitToChoose_released"
QT_MOC_LITERAL(8, 136, 20), // "on_b1_start_released"
QT_MOC_LITERAL(9, 157, 26), // "on_b5_exitToGuide_released"
QT_MOC_LITERAL(10, 184, 22) // "on_b3_reStart_released"

    },
    "Pause_Scene\0gameToChoose_signal\0\0"
    "exitToGame_signal\0gameToGuide_signal\0"
    "restart_signal\0testLevelToEdit_signal\0"
    "on_b2_exitToChoose_released\0"
    "on_b1_start_released\0on_b5_exitToGuide_released\0"
    "on_b3_reStart_released"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Pause_Scene[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,
       3,    0,   60,    2, 0x06 /* Public */,
       4,    0,   61,    2, 0x06 /* Public */,
       5,    0,   62,    2, 0x06 /* Public */,
       6,    0,   63,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   64,    2, 0x08 /* Private */,
       8,    0,   65,    2, 0x08 /* Private */,
       9,    0,   66,    2, 0x08 /* Private */,
      10,    0,   67,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Pause_Scene::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Pause_Scene *_t = static_cast<Pause_Scene *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->gameToChoose_signal(); break;
        case 1: _t->exitToGame_signal(); break;
        case 2: _t->gameToGuide_signal(); break;
        case 3: _t->restart_signal(); break;
        case 4: _t->testLevelToEdit_signal(); break;
        case 5: _t->on_b2_exitToChoose_released(); break;
        case 6: _t->on_b1_start_released(); break;
        case 7: _t->on_b5_exitToGuide_released(); break;
        case 8: _t->on_b3_reStart_released(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Pause_Scene::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Pause_Scene::gameToChoose_signal)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Pause_Scene::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Pause_Scene::exitToGame_signal)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Pause_Scene::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Pause_Scene::gameToGuide_signal)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (Pause_Scene::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Pause_Scene::restart_signal)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (Pause_Scene::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Pause_Scene::testLevelToEdit_signal)) {
                *result = 4;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject Pause_Scene::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Pause_Scene.data,
      qt_meta_data_Pause_Scene,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Pause_Scene::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Pause_Scene::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Pause_Scene.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Pause_Scene::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void Pause_Scene::gameToChoose_signal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Pause_Scene::exitToGame_signal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Pause_Scene::gameToGuide_signal()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Pause_Scene::restart_signal()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Pause_Scene::testLevelToEdit_signal()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
