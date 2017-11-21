#include "wireless.h"


Wireless::Wireless()
{
    discoveryAgent = new QBluetoothDeviceDiscoveryAgent();
    localDevice = new QBluetoothLocalDevice();
    socket = new QBluetoothSocket(QBluetoothServiceInfo::RfcommProtocol);

    connect(discoveryAgent,
            SIGNAL(deviceDiscovered(QBluetoothDeviceInfo)),
            this,
            SLOT(addBlueToothDevicesToList(QBluetoothDeviceInfo))
            );
    connect(socket,
            SIGNAL(readyRead()),
            this,
            SLOT(readBluetoothDataEvent())
            );
    connect(socket,
            SIGNAL(connected()),
            this,
            SLOT(bluetoothConnectedEvent())
            );
    connect(socket,
            SIGNAL(disconnected()),
            this,
            SLOT(bluetoothDisconnectedEvent())
            );
}
/* 蓝牙连接后执行的函数 */
void Wireless::bluetoothConnectedEvent()
{
    qDebug() << "The android device has been connected successfully!";
    QMessageBox::information(this,tr("Info"),tr("Successful connection!"));
    QByteArray arrayData;
    QString s("Hello Windows!!!\nThis message is sended via bluetooth of android device!\n");
    arrayData = s.toUtf8();
    socket->write(arrayData);
}

/* 蓝牙断开连接后执行的函数 */
void Wireless::bluetoothDisconnectedEvent()
{
    qDebug() << "The android device has been disconnected successfully!";
    QMessageBox::information(this,tr("Info"),tr("Successful disconnection!"));
}

/* 当有数据过来的时候蓝牙执行的函数 */
void Wireless::readBluetoothDataEvent()
{

}

void Wireless::writeData(const QByteArray &data)
{
    Wireless.socket->write(data);
}

