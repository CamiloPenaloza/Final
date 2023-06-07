/****************************************************************************
** Meta object code from reading C++ file 'game.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Programa/game.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'game.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_game_t {
    uint offsetsAndSizes[22];
    char stringdata0[5];
    char stringdata1[20];
    char stringdata2[1];
    char stringdata3[8];
    char stringdata4[13];
    char stringdata5[14];
    char stringdata6[16];
    char stringdata7[9];
    char stringdata8[10];
    char stringdata9[10];
    char stringdata10[16];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_game_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_game_t qt_meta_stringdata_game = {
    {
        QT_MOC_LITERAL(0, 4),  // "game"
        QT_MOC_LITERAL(5, 19),  // "updatePuntajeSignal"
        QT_MOC_LITERAL(25, 0),  // ""
        QT_MOC_LITERAL(26, 7),  // "puntaje"
        QT_MOC_LITERAL(34, 12),  // "reset_visual"
        QT_MOC_LITERAL(47, 13),  // "moveCharacter"
        QT_MOC_LITERAL(61, 15),  // "muerteCharacter"
        QT_MOC_LITERAL(77, 8),  // "moveBird"
        QT_MOC_LITERAL(86, 9),  // "moveFire1"
        QT_MOC_LITERAL(96, 9),  // "moveFire2"
        QT_MOC_LITERAL(106, 15)   // "checkCollisions"
    },
    "game",
    "updatePuntajeSignal",
    "",
    "puntaje",
    "reset_visual",
    "moveCharacter",
    "muerteCharacter",
    "moveBird",
    "moveFire1",
    "moveFire2",
    "checkCollisions"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_game[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   62,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    0,   65,    2, 0x08,    3 /* Private */,
       5,    0,   66,    2, 0x08,    4 /* Private */,
       6,    0,   67,    2, 0x08,    5 /* Private */,
       7,    0,   68,    2, 0x08,    6 /* Private */,
       8,    0,   69,    2, 0x08,    7 /* Private */,
       9,    0,   70,    2, 0x08,    8 /* Private */,
      10,    0,   71,    2, 0x08,    9 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject game::staticMetaObject = { {
    QMetaObject::SuperData::link<QGraphicsScene::staticMetaObject>(),
    qt_meta_stringdata_game.offsetsAndSizes,
    qt_meta_data_game,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_game_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<game, std::true_type>,
        // method 'updatePuntajeSignal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'reset_visual'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'moveCharacter'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'muerteCharacter'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'moveBird'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'moveFire1'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'moveFire2'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'checkCollisions'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void game::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<game *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->updatePuntajeSignal((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->reset_visual(); break;
        case 2: _t->moveCharacter(); break;
        case 3: _t->muerteCharacter(); break;
        case 4: _t->moveBird(); break;
        case 5: _t->moveFire1(); break;
        case 6: _t->moveFire2(); break;
        case 7: _t->checkCollisions(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (game::*)(const QString & );
            if (_t _q_method = &game::updatePuntajeSignal; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *game::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *game::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_game.stringdata0))
        return static_cast<void*>(this);
    return QGraphicsScene::qt_metacast(_clname);
}

int game::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsScene::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void game::updatePuntajeSignal(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
