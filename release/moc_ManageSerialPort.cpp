/****************************************************************************
** Meta object code from reading C++ file 'ManageSerialPort.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../SerialPort/ManageSerialPort.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ManageSerialPort.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ManageSerialPort[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      41,   18,   17,   17, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_ManageSerialPort[] = {
    "ManageSerialPort\0\0dataReceived,intReturn\0"
    "newDataReceived(QByteArray,int)\0"
};

void ManageSerialPort::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ManageSerialPort *_t = static_cast<ManageSerialPort *>(_o);
        switch (_id) {
        case 0: _t->newDataReceived((*reinterpret_cast< const QByteArray(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ManageSerialPort::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ManageSerialPort::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ManageSerialPort,
      qt_meta_data_ManageSerialPort, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ManageSerialPort::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ManageSerialPort::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ManageSerialPort::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ManageSerialPort))
        return static_cast<void*>(const_cast< ManageSerialPort*>(this));
    return QObject::qt_metacast(_clname);
}

int ManageSerialPort::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void ManageSerialPort::newDataReceived(const QByteArray & _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
static const uint qt_meta_data_ThreadSend[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_ThreadSend[] = {
    "ThreadSend\0"
};

void ThreadSend::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData ThreadSend::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ThreadSend::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_ThreadSend,
      qt_meta_data_ThreadSend, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ThreadSend::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ThreadSend::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ThreadSend::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ThreadSend))
        return static_cast<void*>(const_cast< ThreadSend*>(this));
    return QThread::qt_metacast(_clname);
}

int ThreadSend::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_ThreadReceive[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      38,   15,   14,   14, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_ThreadReceive[] = {
    "ThreadReceive\0\0dataReceived,intReturn\0"
    "newDataReceived(QByteArray,int)\0"
};

void ThreadReceive::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ThreadReceive *_t = static_cast<ThreadReceive *>(_o);
        switch (_id) {
        case 0: _t->newDataReceived((*reinterpret_cast< const QByteArray(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ThreadReceive::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ThreadReceive::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_ThreadReceive,
      qt_meta_data_ThreadReceive, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ThreadReceive::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ThreadReceive::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ThreadReceive::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ThreadReceive))
        return static_cast<void*>(const_cast< ThreadReceive*>(this));
    return QThread::qt_metacast(_clname);
}

int ThreadReceive::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void ThreadReceive::newDataReceived(const QByteArray & _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
