/****************************************************************************
** Meta object code from reading C++ file 'handleeditor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../src/handleeditor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'handleeditor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_HandleEditor_t {
    QByteArrayData data[16];
    char stringdata0[181];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HandleEditor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HandleEditor_t qt_meta_stringdata_HandleEditor = {
    {
QT_MOC_LITERAL(0, 0, 12), // "HandleEditor"
QT_MOC_LITERAL(1, 13, 15), // "mystringChanged"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 1), // "v"
QT_MOC_LITERAL(4, 32, 20), // "activetriggerChanged"
QT_MOC_LITERAL(5, 53, 11), // "activeSaved"
QT_MOC_LITERAL(6, 65, 19), // "handleSubmitContent"
QT_MOC_LITERAL(7, 85, 4), // "data"
QT_MOC_LITERAL(8, 90, 18), // "handleActiveChange"
QT_MOC_LITERAL(9, 109, 9), // "getString"
QT_MOC_LITERAL(10, 119, 9), // "setString"
QT_MOC_LITERAL(11, 129, 6), // "string"
QT_MOC_LITERAL(12, 136, 9), // "getActive"
QT_MOC_LITERAL(13, 146, 9), // "setActive"
QT_MOC_LITERAL(14, 156, 15), // "m_activetrigger"
QT_MOC_LITERAL(15, 172, 8) // "mystring"

    },
    "HandleEditor\0mystringChanged\0\0v\0"
    "activetriggerChanged\0activeSaved\0"
    "handleSubmitContent\0data\0handleActiveChange\0"
    "getString\0setString\0string\0getActive\0"
    "setActive\0m_activetrigger\0mystring"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HandleEditor[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       2,   80, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       4,    1,   62,    2, 0x06 /* Public */,
       5,    0,   65,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   66,    2, 0x0a /* Public */,
       8,    1,   69,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
       9,    0,   72,    2, 0x02 /* Public */,
      10,    1,   73,    2, 0x02 /* Public */,
      12,    0,   76,    2, 0x02 /* Public */,
      13,    1,   77,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    7,

 // methods: parameters
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString,   11,

 // properties: name, type, flags
      14, QMetaType::QString, 0x00495003,
      15, QMetaType::QString, 0x00495003,

 // properties: notify_signal_id
       1,
       0,

       0        // eod
};

void HandleEditor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<HandleEditor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->mystringChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->activetriggerChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->activeSaved(); break;
        case 3: _t->handleSubmitContent((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->handleActiveChange((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: { QString _r = _t->getString();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 6: _t->setString((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: { QString _r = _t->getActive();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 8: _t->setActive((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (HandleEditor::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HandleEditor::mystringChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (HandleEditor::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HandleEditor::activetriggerChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (HandleEditor::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HandleEditor::activeSaved)) {
                *result = 2;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<HandleEditor *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->getActive(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->getString(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<HandleEditor *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setActive(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setString(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject HandleEditor::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_HandleEditor.data,
    qt_meta_data_HandleEditor,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *HandleEditor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HandleEditor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_HandleEditor.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int HandleEditor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void HandleEditor::mystringChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void HandleEditor::activetriggerChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void HandleEditor::activeSaved()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
