/****************************************************************************
** Meta object code from reading C++ file 'safeguard.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../SGFAS/safeguard.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'safeguard.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SafeGuard_t {
    QByteArrayData data[19];
    char stringdata0[444];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SafeGuard_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SafeGuard_t qt_meta_stringdata_SafeGuard = {
    {
QT_MOC_LITERAL(0, 0, 9), // "SafeGuard"
QT_MOC_LITERAL(1, 10, 25), // "addBlueToothDevicesToList"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 20), // "QBluetoothDeviceInfo"
QT_MOC_LITERAL(4, 58, 13), // "itemActivated"
QT_MOC_LITERAL(5, 72, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(6, 89, 4), // "item"
QT_MOC_LITERAL(7, 94, 22), // "readBluetoothDataEvent"
QT_MOC_LITERAL(8, 117, 23), // "bluetoothConnectedEvent"
QT_MOC_LITERAL(9, 141, 26), // "bluetoothDisconnectedEvent"
QT_MOC_LITERAL(10, 168, 30), // "on_pushButton_scanwifi_clicked"
QT_MOC_LITERAL(11, 199, 31), // "on_pushButton_readImage_clicked"
QT_MOC_LITERAL(12, 231, 24), // "on_pushButton_id_clicked"
QT_MOC_LITERAL(13, 256, 26), // "on_pushButton_scan_clicked"
QT_MOC_LITERAL(14, 283, 33), // "on_pushButton_closeDevice_cli..."
QT_MOC_LITERAL(15, 317, 32), // "on_pushButton_disconnect_clicked"
QT_MOC_LITERAL(16, 350, 35), // "on_pushButton_openBluetooth_c..."
QT_MOC_LITERAL(17, 386, 27), // "on_pushButton_clear_clicked"
QT_MOC_LITERAL(18, 414, 29) // "on_pushButton_warning_clicked"

    },
    "SafeGuard\0addBlueToothDevicesToList\0"
    "\0QBluetoothDeviceInfo\0itemActivated\0"
    "QListWidgetItem*\0item\0readBluetoothDataEvent\0"
    "bluetoothConnectedEvent\0"
    "bluetoothDisconnectedEvent\0"
    "on_pushButton_scanwifi_clicked\0"
    "on_pushButton_readImage_clicked\0"
    "on_pushButton_id_clicked\0"
    "on_pushButton_scan_clicked\0"
    "on_pushButton_closeDevice_clicked\0"
    "on_pushButton_disconnect_clicked\0"
    "on_pushButton_openBluetooth_clicked\0"
    "on_pushButton_clear_clicked\0"
    "on_pushButton_warning_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SafeGuard[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x08 /* Private */,
       4,    1,   87,    2, 0x08 /* Private */,
       7,    0,   90,    2, 0x08 /* Private */,
       8,    0,   91,    2, 0x08 /* Private */,
       9,    0,   92,    2, 0x08 /* Private */,
      10,    0,   93,    2, 0x08 /* Private */,
      11,    0,   94,    2, 0x08 /* Private */,
      12,    0,   95,    2, 0x08 /* Private */,
      13,    0,   96,    2, 0x08 /* Private */,
      14,    0,   97,    2, 0x08 /* Private */,
      15,    0,   98,    2, 0x08 /* Private */,
      16,    0,   99,    2, 0x08 /* Private */,
      17,    0,  100,    2, 0x08 /* Private */,
      18,    0,  101,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SafeGuard::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SafeGuard *_t = static_cast<SafeGuard *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->addBlueToothDevicesToList((*reinterpret_cast< const QBluetoothDeviceInfo(*)>(_a[1]))); break;
        case 1: _t->itemActivated((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 2: _t->readBluetoothDataEvent(); break;
        case 3: _t->bluetoothConnectedEvent(); break;
        case 4: _t->bluetoothDisconnectedEvent(); break;
        case 5: _t->on_pushButton_scanwifi_clicked(); break;
        case 6: _t->on_pushButton_readImage_clicked(); break;
        case 7: _t->on_pushButton_id_clicked(); break;
        case 8: _t->on_pushButton_scan_clicked(); break;
        case 9: _t->on_pushButton_closeDevice_clicked(); break;
        case 10: _t->on_pushButton_disconnect_clicked(); break;
        case 11: _t->on_pushButton_openBluetooth_clicked(); break;
        case 12: _t->on_pushButton_clear_clicked(); break;
        case 13: _t->on_pushButton_warning_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QBluetoothDeviceInfo >(); break;
            }
            break;
        }
    }
}

const QMetaObject SafeGuard::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SafeGuard.data,
      qt_meta_data_SafeGuard,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SafeGuard::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SafeGuard::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SafeGuard.stringdata0))
        return static_cast<void*>(const_cast< SafeGuard*>(this));
    return QWidget::qt_metacast(_clname);
}

int SafeGuard::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
