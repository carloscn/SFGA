#ifndef WIFI_H
#define WIFI_H

#include <QObject>
#include <QAndroidJniObject>
#include <QList>
#include <QString>



struct WifiInfo{
    int level;
    QString SSID;
    QString BSSID;
    QString keytype;
};

class wifi : public QObject
{
    Q_OBJECT
public:
    explicit wifi(QObject *parent = 0);
    ~wifi();

    //wifi process
    Q_INVOKABLE bool isWifiEnable();
    Q_INVOKABLE void openWifi();
    Q_INVOKABLE void closeWifi();
    Q_INVOKABLE void scanWifi();

    Q_INVOKABLE int getWifiListCount();

    Q_INVOKABLE QString getWifiSSID(int index);
    Q_INVOKABLE QString getWifiBSSID(int index);
    Q_INVOKABLE int getWifiLevel(int index);
    Q_INVOKABLE QString getKeyType(int index);

    //获取当前连接的wifi信息
    Q_INVOKABLE QString getConntectedWifiSSID();
    Q_INVOKABLE QString getConnectedWifiAddress();

    //连接到wifi
    Q_INVOKABLE void connectToWifi(int id,QString passwd);
    Q_INVOKABLE void connectToWifiWithoutPasswd(int id);

    //多媒体音量控制
    Q_INVOKABLE int getMaxVolumnStream();
    Q_INVOKABLE int getCurrentVolumnStream();
    Q_INVOKABLE void setVolumnStream(int a);

    //获取屏幕像素密度
    Q_INVOKABLE double getDentisy();


    //user process
    Q_INVOKABLE void refreshWifiList();

    Q_INVOKABLE int  wifiCount();
    Q_INVOKABLE int  wifiLevel(int i);
    Q_INVOKABLE QString wifiSSID(int i);
    Q_INVOKABLE QString wifiBSSID(int i);
    Q_INVOKABLE QString wifiKeyType(int i);

    QString javaDocPath;

signals:

public slots:
private:

    QList<WifiInfo> wifiList;


};


#endif // WIFI_H
