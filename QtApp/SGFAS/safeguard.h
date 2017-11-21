// Qt for android   Project.
/****************************************************************************/
/*                                                                          */
/*  @file       : *_safeguard.cpp                  	                        */
/*  @Copyright  : Powered by MULTIBEANS ORG rights reserved.                	*/
/*  @Revision   : Ver 1.0.                                                  */
/*  @Data       : 2017.08.19 Realse.                                        */
/*  @Belong     : PROJECT.                                                  */
/*                                                                          */
/*  **code : (UTF-8) in Linux(Ubuntu16.04). Qt 5.8.0 for Linux platform.    */
/****************************************************************************/
/*  @Attention:                                                             */
/*  ---------------------------------------------------------------------   */
/*  |    Data    |  Behavior |     Offer      |          Content         |  */
/*  | 2017.08.19 |   create  |Carlos Lopez(M) | ceate the document.      |  */
/*  ---------------------------------------------------------------------   */
/*  Email: carlos@mltbns.top                                  MULTIBEANS.   */
/****************************************************************************/

#ifndef SAFEGUARD_H
#define SAFEGUARD_H

#include <QWidget>
#include <QList>
#include <QListWidgetItem>
#include <QMessageBox>
#include "QByteArray"
#include <QtBluetooth/qbluetoothglobal.h>
#include <QtBluetooth/qbluetoothlocaldevice.h>
#include <QtBluetooth/qbluetoothaddress.h>
#include <QtBluetooth/qbluetoothdevicediscoveryagent.h>
#include <QtBluetooth/qbluetoothlocaldevice.h>
#include <QtBluetooth/qbluetoothsocket.h>
#include <QGraphicsView>
#include <QGraphicsScene>


#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

namespace Ui {
class SafeGuard;
}

class SafeGuard : public QWidget
{
    Q_OBJECT

public:
    explicit SafeGuard(QWidget *parent = 0);

    ~SafeGuard();


private slots:
    // by user.
    void addBlueToothDevicesToList(const QBluetoothDeviceInfo&);

    void itemActivated(QListWidgetItem *item);

    void readBluetoothDataEvent();

    void bluetoothConnectedEvent();

    void bluetoothDisconnectedEvent();

    // by system.
    void on_pushButton_scanwifi_clicked();


    void on_pushButton_readImage_clicked();

    void on_pushButton_id_clicked();


    void on_pushButton_scan_clicked();

    void on_pushButton_closeDevice_clicked();

    void on_pushButton_disconnect_clicked();

    void on_pushButton_openBluetooth_clicked();

    void on_pushButton_clear_clicked();

    void on_pushButton_warning_clicked();

private:

    Ui::SafeGuard *ui;

    QBluetoothDeviceDiscoveryAgent *discoveryAgent;
    QBluetoothLocalDevice *localDevice;
    QBluetoothSocket *socket;

    QByteArray *rxDataBuffer;
    QGraphicsScene *scene = new QGraphicsScene;
    void SendCmdToRaspi( uint cmd );
};

#endif // SAFEGUARD_H
