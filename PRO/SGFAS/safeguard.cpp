// Qt for android   Project.
/****************************************************************************/
/*                                                                          */
/*  @file       : *_safeguard.cpp                  	                        */
/*  @Copyright  : Powered by MULTIBEANS ORG rights reserved.                */
/*  @Revision   : Ver 1.0.                                                  */
/*  @Data       : 2017.08.19 Realse.                                        */
/*  @Belong     : PROJECT.                                                  */
/*  @Git        : https://gitlab.com/coarlqq/safeGuardForAutoSale.git       */
/*  **code : (UTF-8) in Linux(Ubuntu16.04). Qt 5.8.0 for Linux platform.    */
/****************************************************************************/
/*  @Attention:                                                             */
/*  ---------------------------------------------------------------------   */
/*  |    Data    |  Behavior |     Offer      |          Content         |  */
/*  | 2017.08.19 |   create  |Carlos Lopez(M) | ceate the document.      |  */
/*  ---------------------------------------------------------------------   */
/*  Email: carlos@mltbns.top                                  MULTIBEANS.   */
/****************************************************************************/

#include "safeguard.h"
#include "ui_safeguard.h"
#include <qdebug.h>
#include <QPixmap>
#include "iostream"
#include <QBuffer>
#include <QImage>
#include "comm.h"
#include <QPalette>

static const QLatin1String serviceUuid("00001101-0000-1000-8000-00805F9B34FB");

SafeGuard::SafeGuard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SafeGuard)
{
    ui->setupUi(this);

    rxDataBuffer = new QByteArray();
    scene = new QGraphicsScene();

    discoveryAgent = new QBluetoothDeviceDiscoveryAgent();
    localDevice = new QBluetoothLocalDevice();
    socket = new QBluetoothSocket(QBluetoothServiceInfo::RfcommProtocol);

    connect(discoveryAgent,
            SIGNAL(deviceDiscovered(QBluetoothDeviceInfo)),
            this,
            SLOT(addBlueToothDevicesToList(QBluetoothDeviceInfo))
            );
    connect(ui->list,
            SIGNAL(itemActivated(QListWidgetItem*)),
            this,
            SLOT(itemActivated(QListWidgetItem*))
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

    // 仲裁蓝牙状态判断
    if( localDevice->hostMode() == QBluetoothLocalDevice::HostPoweredOff ) {
        ui->pushButton_openBluetooth->setEnabled(true);
        ui->pushButton_closeDevice->setEnabled(false);
        ui->pushButton_scan->setEnabled(false);
    }else {
        ui->pushButton_openBluetooth->setEnabled(false);
        ui->pushButton_closeDevice->setEnabled(true);
        ui->pushButton_scan->setEnabled(true);
    }
    ui->pushButton_disconnect->setEnabled(false);
    if( localDevice->hostMode() == QBluetoothLocalDevice::HostDiscoverable ) {
        ui->checkBox_discoverable->setChecked(true);
    }else {
        ui->checkBox_discoverable->setChecked(false);
    }

}

SafeGuard::~SafeGuard()
{
    delete ui;
}

void SafeGuard::on_pushButton_scanwifi_clicked()
{



}
// slots函数，触发的时候增加设备到List里面
void SafeGuard::addBlueToothDevicesToList(const QBluetoothDeviceInfo &info)
{
    QString label = QString("%1 %2").arg(info.address().toString()).arg(info.name());

    QList<QListWidgetItem *> items = ui->list->findItems(label, Qt::MatchExactly);

    if (items.empty()) {
        QListWidgetItem *item = new QListWidgetItem(label);
        QBluetoothLocalDevice::Pairing pairingStatus = localDevice->pairingStatus(info.address());
        if (pairingStatus == QBluetoothLocalDevice::Paired || pairingStatus == QBluetoothLocalDevice::AuthorizedPaired )
            item->setTextColor(QColor(Qt::green));
        else
            item->setTextColor(QColor(Qt::black));
        ui->list->addItem(item);
    }
}
// slots函数，激活，链接蓝牙
void SafeGuard::itemActivated(QListWidgetItem *item)
{
    QString text = item->text();

    int index = text.indexOf(' ');

    if (index == -1)
        return;

    QBluetoothAddress address(text.left(index));
    QString name(text.mid(index + 1));
    qDebug() << "You has choice the bluetooth address is " << address;
    qDebug() << "The device is connneting.... ";
    QMessageBox::information(this,tr("Info"),tr("The device is connecting..."));
    socket->connectToService(address, QBluetoothUuid(serviceUuid) ,QIODevice::ReadWrite);
}
// 蓝牙接收数据
uint count = 0;
void SafeGuard::readBluetoothDataEvent()
{

    QByteArray rxArray;
    QString rxString;
    QByteArray array;
    QImage image("image.jpg");

    rxArray = socket->readAll();
    qDebug() << "blue rec: " << count ++  << " :"<< rxArray;
    rxDataBuffer->append(rxArray);
    // 识别为图像数据
    if( !rxDataBuffer->isEmpty() ) {

        // 如果发送命令包含 ###，则是图像文件 读图像数据
        if( rxDataBuffer->contains("###") ) {

            array = rxDataBuffer->left(rxDataBuffer->indexOf("###"));

            ui->textBrowser->append("A pic signal... \n");
            //ui->textBrowser->append(array.toHex());
            bool flag = image.loadFromData((const uchar *)array.data(),array.size());
            if (  flag == true  ) {

                ui->textBrowser->append("drawing....\n");
                QPixmap pixmap = QPixmap::fromImage( image );
                ui->imageLabel->setPixmap( pixmap );
                QMessageBox::information(this,"提示", "图像获取完毕。。");
            }else {
                ui->imageLabel->setText(" 获取图像失败，请重新获取！ ");
                QMessageBox::information(this,"提示", "图像获取失败。。");
            }
            // 清空缓冲区
            rxString.clear();
            rxDataBuffer->clear();
            array.clear();
            rxArray.clear();
            ui->textBrowser->append("Draw the pic!\n");

        }

        // 读取命令,则接受为命令数据 需要处理命令
        if( rxDataBuffer->contains("@@@") ) {

            ui->textBrowser->append("a cmd signal.\n");
            array = rxDataBuffer->left( rxDataBuffer->indexOf("@@@") );
            rxString = array.toHex();
            qDebug() << " Rec cmd:" << rxString;
            // array 为整个命令栈
            // 判断cmd的数据头信息
            if( rxString.contains("aabb") ) {
                uint t_cmd;
                t_cmd = rxString.mid(4,2).toInt();
                qDebug() << " Rec cmd:" << t_cmd;
                switch( t_cmd ) {

                case CMD_ID_CONFIRM:

                    QMessageBox::StandardButton reply;
                    // 弹出身份确认按钮，并获得用户的选择
                    reply = QMessageBox::question(NULL, "认证身份确认", "设备请求确认身份，确认吗？", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
                    // 如果选择Yes 身份确认通过之后，将允许信息发送给树莓派，交给树莓派处理
                    if( reply == QMessageBox::Yes ) {
                        // 如果选择No 身份没有认定，将信息发送给树莓派，让树莓派来处理
                        SendCmdToRaspi( CMD_ID_CONFIRM_YES );
                    }else {
                        SendCmdToRaspi( CMD_ID_CONFIRM_NO );
                    }
                    rxString.clear();
                    rxDataBuffer->clear();
                    array.clear();
                    rxArray.clear();
                    break;

                case CMD_THEFT_CHECKED:

                    QMessageBox::warning(this,"Warring","设备检测到盗窃行为！");
                    QPalette pal = ui->pushButton_alartLed->palette();
                    pal.setColor( QPalette::Window,QColor(255,0,0) );
                    ui->pushButton_alartLed->setPalette(pal);
                    ui->label_stateText->setText("有人盗窃....");
                    rxString.clear();
                    rxDataBuffer->clear();
                    array.clear();
                    rxArray.clear();
                    break;

                }
            }
        }
    }

}

// 蓝牙连接之后的事件
void SafeGuard::bluetoothConnectedEvent()
{
    // 停止搜寻服务，防止数据阻塞
    discoveryAgent->stop();
    qDebug() << "The android device has been connected successfully!";
    QMessageBox::information(this,tr("Info"),tr("Successful connection!"));
    ui->pushButton_disconnect->setEnabled(true);
    ui->pushButton_scan->setEnabled(false);

}
// 蓝牙断开连接之后的事件
void SafeGuard::bluetoothDisconnectedEvent()
{
    qDebug() << "The android device has been disconnected successfully!";
    QMessageBox::information(this,tr("Info"),tr("Successful disconnection!"));
    ui->pushButton_disconnect->setEnabled(false);
    ui->pushButton_scan->setEnabled(true);

}


void SafeGuard::on_pushButton_readImage_clicked()
{
    //QMessageBox::information(this,"提示", "图像获取中.....");

    SendCmdToRaspi( CMD_GET_IMAGE  );
}

void SafeGuard::on_pushButton_id_clicked()
{
    SendCmdToRaspi( CMD_ID_CONFIRM );
}


void SafeGuard::on_pushButton_scan_clicked()
{
    discoveryAgent->start();
    ui->pushButton_scan->setEnabled(false);
}

void SafeGuard::on_pushButton_closeDevice_clicked()
{
    localDevice->setHostMode(QBluetoothLocalDevice::HostPoweredOff);
    ui->pushButton_closeDevice->setEnabled(false);
    ui->pushButton_openBluetooth->setEnabled(true);
    ui->pushButton_scan->setEnabled(false);
}

void SafeGuard::on_pushButton_disconnect_clicked()
{
    socket->disconnectFromService();
}

void SafeGuard::on_pushButton_openBluetooth_clicked()
{
    localDevice->powerOn();
    ui->pushButton_closeDevice->setEnabled(true);
    ui->pushButton_openBluetooth->setEnabled(false);
    ui->pushButton_scan->setEnabled(true);
}


void SafeGuard::SendCmdToRaspi( uint cmd )
{
    QByteArray cmd_array;

    cmd_array.clear();

    cmd_array.append(0xAA);
    cmd_array.append(0xBB);
    cmd_array.append(cmd);
    cmd_array.append('@');
    socket->write(cmd_array);

}

void SafeGuard::on_pushButton_clear_clicked()
{
    ui->label_stateText->setText("设备正常！");
    SendCmdToRaspi(CMD_STOP_WARN);
}

void SafeGuard::on_pushButton_warning_clicked()
{
    SendCmdToRaspi( CMD_ALARM );
}

