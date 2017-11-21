#ifndef WIRELESS_H
#define WIRELESS_H

#include <QDebug>
#include <QMessageBox>
#include <QtBluetooth/qbluetoothglobal.h>
#include <QtBluetooth/qbluetoothlocaldevice.h>
#include <QtBluetooth/qbluetoothaddress.h>
#include <QtBluetooth/qbluetoothdevicediscoveryagent.h>
#include <QtBluetooth/qbluetoothlocaldevice.h>
#include <QtBluetooth/qbluetoothsocket.h>

class Wireless
{
public:

    Wireless();

public:

    QBluetoothDeviceDiscoveryAgent *discoveryAgent;
    QBluetoothLocalDevice *localDevice;
    QBluetoothSocket *socket;

private:

private slots:

    void readBluetoothDataEvent();
    void bluetoothConnectedEvent();
    void bluetoothDisconnectedEvent();


};

#endif // WIRELESS_H
