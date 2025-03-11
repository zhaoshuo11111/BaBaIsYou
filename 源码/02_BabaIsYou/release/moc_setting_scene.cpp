/****************************************************************************
** Meta object code from reading C++ file 'setting_scene.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../setting_scene.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'setting_scene.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Setting_Scene_t {
    QByteArrayData data[12];
    char stringdata0[217];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Setting_Scene_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Setting_Scene_t qt_meta_stringdata_Setting_Scene = {
    {
QT_MOC_LITERAL(0, 0, 13), // "Setting_Scene"
QT_MOC_LITERAL(1, 14, 20), // "openAniChange_signal"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 15), // "shakeWin_signal"
QT_MOC_LITERAL(4, 52, 13), // "eVolumeChange"
QT_MOC_LITERAL(5, 66, 5), // "value"
QT_MOC_LITERAL(6, 72, 13), // "mVolumeChange"
QT_MOC_LITERAL(7, 86, 19), // "on_b6_exit_released"
QT_MOC_LITERAL(8, 106, 24), // "on_b2_animation_released"
QT_MOC_LITERAL(9, 131, 20), // "on_b3_shake_released"
QT_MOC_LITERAL(10, 152, 32), // "on_s1_dffectVolum_sliderReleased"
QT_MOC_LITERAL(11, 185, 31) // "on_s2_musicVolum_sliderReleased"

    },
    "Setting_Scene\0openAniChange_signal\0\0"
    "shakeWin_signal\0eVolumeChange\0value\0"
    "mVolumeChange\0on_b6_exit_released\0"
    "on_b2_animation_released\0on_b3_shake_released\0"
    "on_s1_dffectVolum_sliderReleased\0"
    "on_s2_musicVolum_sliderReleased"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Setting_Scene[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,
       3,    0,   60,    2, 0x06 /* Public */,
       4,    1,   61,    2, 0x06 /* Public */,
       6,    1,   64,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   67,    2, 0x08 /* Private */,
       8,    0,   68,    2, 0x08 /* Private */,
       9,    0,   69,    2, 0x08 /* Private */,
      10,    0,   70,    2, 0x08 /* Private */,
      11,    0,   71,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Setting_Scene::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Setting_Scene *_t = static_cast<Setting_Scene *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->openAniChange_signal(); break;
        case 1: _t->shakeWin_signal(); break;
        case 2: _t->eVolumeChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->mVolumeChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_b6_exit_released(); break;
        case 5: _t->on_b2_animation_released(); break;
        case 6: _t->on_b3_shake_released(); break;
        case 7: _t->on_s1_dffectVolum_sliderReleased(); break;
        case 8: _t->on_s2_musicVolum_sliderReleased(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Setting_Scene::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Setting_Scene::openAniChange_signal)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Setting_Scene::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Setting_Scene::shakeWin_signal)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Setting_Scene::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Setting_Scene::eVolumeChange)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (Setting_Scene::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Setting_Scene::mVolumeChange)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject Setting_Scene::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Setting_Scene.data,
      qt_meta_data_Setting_Scene,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Setting_Scene::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Setting_Scene::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Setting_Scene.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Setting_Scene::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void Setting_Scene::openAniChange_signal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Setting_Scene::shakeWin_signal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Setting_Scene::eVolumeChange(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Setting_Scene::mVolumeChange(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
