// Qt for android   Project.                                            GitLab
/****************************************************************************/
/*                                                                          */
/*  @file       : *_safeguard.cpp                  	                        */
/*  @Copyright  : Powered by MULTIBEANS ORG rights reserved.                */
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

#include "wifi.h"
#include <QDebug>
#include <math.h>
#include "jni.h"


wifi::wifi(QObject *parent) : QObject(parent)
{

}

wifi::~wifi()
{

}

/***********************************wifi cability ********************/
bool wifi::isWifiEnable(){
    jint state = QAndroidJniObject::callStaticMethod<jint>("java/ExtendsQtWithJava",
                                       "networkState");
    if( state == 1 ) {
        qDebug() << "WIFI现在是开启的！";
    }else {
        qDebug() << "WIFI现在是关闭的！";
    }
    return state==1?true:false;
}

void wifi::openWifi(){
    QAndroidJniObject::callStaticMethod<void>("java/ExtendsQtWithJava",
                                       "openWifi");
    qDebug() << "开启WIFI 命令发送！";
}

void wifi::closeWifi(){
    QAndroidJniObject::callStaticMethod<void>("java/ExtendsQtWithJava",
                                       "closeWifi");
    qDebug() << "关闭WIFI 命令发送！";
}

void wifi::scanWifi(){
    QAndroidJniObject::callStaticMethod<void>("java/ExtendsQtWithJava",
                                       "scanWifi");
}

int wifi::getWifiListCount(){

 jint count=QAndroidJniObject::callStaticMethod<jint>("java/ExtendsQtWithJava",
                                                   "getWifiCount");
 return count;
}

QString wifi::getWifiSSID(int index){
    QAndroidJniObject str=QAndroidJniObject::callStaticObjectMethod("java/ExtendsQtWithJava",
                                                                             "getWifiSSID",
                                                                             "(I)Ljava/lang/String;",index);
    return str.toString();
}

QString wifi::getWifiBSSID(int index){
    QAndroidJniObject str=QAndroidJniObject::callStaticObjectMethod("java/ExtendsQtWithJava",
                                                                             "getWifiBSSID",
                                                                             "(I)Ljava/lang/String;",index);
    return str.toString();


}

int wifi::getWifiLevel(int index){
    int a= QAndroidJniObject::callStaticMethod<int>("java/ExtendsQtWithJava",
                                                           "getWifiLevel","(I)I",index);
    qDebug()<<"wifi level: "<<a;
    if(abs(a)>80){
        return 1;
    }
    else if(abs(a)>50&&abs(a)<=80){
        return 2;
    }
    else if(abs(a)<=50){
        return 3;
    }
}

QString wifi::getKeyType(int index){
    QAndroidJniObject str=QAndroidJniObject::callStaticObjectMethod("java/ExtendsQtWithJava",
                                                                             "getWifiKeyType",
                                                                             "(I)Ljava/lang/String;",index);
    return str.toString();
}


//获取当前连接的wifi信息
QString wifi::getConntectedWifiSSID(){
    QAndroidJniObject str=QAndroidJniObject::callStaticObjectMethod("java/ExtendsQtWithJava",
                                                                             "getCurrentWifiSSID",
                                                                             "()Ljava/lang/String;");
    return str.toString();

}

QString wifi::getConnectedWifiAddress(){
    QAndroidJniObject str=QAndroidJniObject::callStaticObjectMethod("java/ExtendsQtWithJava",
                                                                             "getHostIPAddress",
                                                                             "()Ljava/lang/String;");
    return str.toString();

}

//连接到wifi
void wifi::connectToWifi(int id,QString passwd){
    QAndroidJniObject str=QAndroidJniObject::fromString(passwd);
    jint a=QAndroidJniObject::callStaticMethod<jint>("java/ExtendsQtWithJava",
                                                                                 "connectToWifi",
                                                                                 "(ILjava/lang/String;)I",id,str.object<jstring>());
    qDebug()<<"connect to wifi :"<<a;
}
void wifi::connectToWifiWithoutPasswd(int id){
    jint a=QAndroidJniObject::callStaticMethod<jint>("java/ExtendsQtWithJava",
                                                                                 "connectToWifiWithoutPasswd",
                                                                                 "(I)I",id);
    qDebug()<<"connect to wifi :"<<a;
}


/***********************************wifi cability ********************/




/***********************************多媒体音量控制********************/

int wifi::getMaxVolumnStream(){
    return QAndroidJniObject::callStaticMethod<int>("java/ExtendsQtWithJava",
                                                    "getMaxVolumnStream","()I");
}

int wifi::getCurrentVolumnStream(){
    return QAndroidJniObject::callStaticMethod<int>("java/ExtendsQtWithJava",
                                                    "getCurrentVolumnStream","()I");
}

void wifi::setVolumnStream(int a){
    QAndroidJniObject::callStaticMethod<void>("java/ExtendsQtWithJava",
                                                        "setVolumnStream","(I)V",a);
}

/***********************************多媒体音量控制********************/

//获取屏幕像素密度
double wifi::getDentisy(){
    return QAndroidJniObject::callStaticMethod<double>("java/ExtendsQtWithJava",
                                                    "getDentisy","()D");
}




/***********************************user functionds*************************/
void wifi::refreshWifiList(){
    wifiList.clear();
    scanWifi();
    int count=getWifiListCount();
    for(int a=0;a<count;a++){
        WifiInfo info;
        info.SSID=getWifiSSID(a);
        info.BSSID=getWifiBSSID(a);
        info.level=getWifiLevel(a);
        info.keytype=getKeyType(a);
        wifiList.append(info);
    }
}


int  wifi::wifiCount(){
    return wifiList.count();
}

int  wifi::wifiLevel(int i){
    return wifiList.at(i).level;
}

QString wifi::wifiSSID(int i){
    return wifiList.at(i).SSID;
}

QString wifi::wifiBSSID(int i){
    return wifiList.at(i).BSSID;
}

QString wifi::wifiKeyType(int i){
    return wifiList.at(i).keytype;
}

