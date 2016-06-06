/****************************************************************************
** Meta object code from reading C++ file 'xl618.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../xl618.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'xl618.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_xl618[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      30,    7,    6,    6, 0x05,

 // slots: signature, parameters, type, tag, flags
      81,   70,    6,    6, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_xl618[] = {
    "xl618\0\0dataReceived,intReturn\0"
    "sig_serPort_RecDataToUI(QByteArray,int)\0"
    ",intReturn\0slt_serPort_RecDataToUI(QByteArray,int)\0"
};

void xl618::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        xl618 *_t = static_cast<xl618 *>(_o);
        switch (_id) {
        case 0: _t->sig_serPort_RecDataToUI((*reinterpret_cast< const QByteArray(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->slt_serPort_RecDataToUI((*reinterpret_cast< const QByteArray(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData xl618::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject xl618::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_xl618,
      qt_meta_data_xl618, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &xl618::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *xl618::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *xl618::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_xl618))
        return static_cast<void*>(const_cast< xl618*>(this));
    return QThread::qt_metacast(_clname);
}

int xl618::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void xl618::sig_serPort_RecDataToUI(const QByteArray & _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
