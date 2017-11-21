package an.qt.extendsQtWithJava;
import android.app.Notification;
import android.app.NotificationManager;
import android.content.Intent;
import android.app.PendingIntent;
import android.widget.Toast;
import android.os.Handler;
import android.os.Message;
import android.util.Log;
import android.net.ConnectivityManager;
import android.net.NetworkInfo;
import android.net.Uri;
import android.location.LocationManager;
import android.location.Criteria;
import android.provider.Settings;
import android.location.Location;
import android.location.LocationListener;
import android.location.LocationProvider;
import java.lang.ClassLoader;
import dalvik.system.DexClassLoader;
import java.lang.reflect.Field;
import android.os.Bundle;
import android.os.Environment;
import java.io.File;
import android.provider.MediaStore;


//tommego
import java.util.List;
import android.net.wifi.ScanResult;
import android.net.wifi.WifiConfiguration;
import android.net.wifi.WifiInfo;
import android.net.wifi.WifiManager;
import android.net.wifi.WifiManager.WifiLock;
import android.media.AudioManager;
import android.media.audiofx.Visualizer;
import android.media.audiofx.Equalizer;
import android.media.MediaPlayer;
import java.io.IOException;
import java.lang.Exception;
import java.lang.Throwable;
import android.net.DhcpInfo;
import android.content.Context;

//屏幕像素密度
import android.util.DisplayMetrics;
//tommego



public class ExtendsQtWithJava extends org.qtproject.qt5.android.bindings.QtActivity
{
    private static ExtendsQtWithJava m_instance;

    /***************************tommego*********************************************************************************/
    /***************************tommego*********************************************************************************/

    public static WifiInfo currentWifiInfo;//当前所连接的wifi

    public static List<ScanResult> wifiList;// wifi列表

    public static List<WifiConfiguration> wifiConList;// wifi 已成功连接过的配置列表

    public static int wifiIndex;//从scanResult 得到的wifi列表进行记录位置

    public static  String[] str;//。。。。。

    //手机连接wifi 后得到的动态ip
    public static DhcpInfo hostDhcpInfo;


    //多媒体播放
    public static MediaPlayer mMediaPlayer; //多媒体播放类
    public static Visualizer mVisualizer;   //Mp3音频频谱可视化数据采集类
    public static Equalizer mEqualizer;     //mp3音频均衡器类，控制音频输出风格
    public static byte[] visualDatas=new byte[128];     //存放音频频谱数据，数组大小范围：128~1024
    public static byte[] FftvisualDatas=new byte[128];  //存放音频均衡器数据，数组大小范围：128~1024

    public static final int maxCR = Visualizer.getMaxCaptureRate();



    /***************************tommego*********************************************************************************/
    /***************************tommego*********************************************************************************/

    public ExtendsQtWithJava(){
        m_instance = this;
    }                                   //实例化单例对象


    /***************************tommego*********************************************************************************/
    /***************************tommego*********************************************************************************/

    //open wifi
    public static void openWifi(){
        WifiManager conMan = (WifiManager) m_instance.getSystemService(Context.WIFI_SERVICE);
        if(!conMan.isWifiEnabled()){
            conMan.setWifiEnabled(true);
        }
    }

    //close wifi
    public static void closeWifi(){
        WifiManager conMan = (WifiManager) m_instance.getSystemService(Context.WIFI_SERVICE);
        if(conMan.isWifiEnabled()){
            conMan.setWifiEnabled(false);
        }
    }

    //scan wifi
    public static void scanWifi(){
        WifiManager conMan = (WifiManager) m_instance.getSystemService(Context.WIFI_SERVICE);
        conMan.startScan();
          // 获取扫描结果
        wifiList = conMan.getScanResults();

    }

    //get wifi info
    public static int getWifiCount(){
        return wifiList.size();
    }
    public static String getWifiSSID(int index){
        if(index>=0&&index<wifiList.size()){
            return wifiList.get(index).SSID;
        }
        else{
            return "";
        }


    }
    public static int getWifiLevel(int index){
        if(index>=0&&index<wifiList.size()){
            return wifiList.get(index).level;
        }
        else{
            return 0;
        }
    }
    public static int getWifiFrequency(int index){
        if(index>=0&&index<wifiList.size()){
            return wifiList.get(index).frequency;
        }
        else{
            return 0;
        }
    }
    public static String getWifiBSSID(int index){
        if(index>=0&&index<wifiList.size()){
            return wifiList.get(index).BSSID;
        }
        else{
            return "";
        }
    }
    //加密方式判断
    public static String getWifiKeyType(int index){
        if (wifiList.get(index).capabilities.contains("WEP")) {
            return "WEP";
        } else if (wifiList.get(index).capabilities.contains("PSK")) {
            return "PSK";
        } else if (wifiList.get(index).capabilities.contains("EAP")) {
            return "EAP";
        }
        return "无";
    }


    //get current connected wifi info
    public static String getCurrentWifiSSID(){
        WifiManager conMan = (WifiManager) m_instance.getSystemService(Context.WIFI_SERVICE);
        currentWifiInfo = conMan.getConnectionInfo();
        return currentWifiInfo.getSSID();
    }

    //get current ip address
    public static String getCurrentWifiIPAddress(){
        WifiManager conMan = (WifiManager) m_instance.getSystemService(Context.WIFI_SERVICE);
        currentWifiInfo = conMan.getConnectionInfo();
        return WifiUtil.intToIp(currentWifiInfo.getIpAddress());
    }

    //还是路由派来的IP，啊啊啊啊（…*……*…）
    public static String getHostIPAddress(){
        WifiManager conMan = (WifiManager) m_instance.getSystemService(Context.WIFI_SERVICE);
        hostDhcpInfo = conMan.getDhcpInfo();
        return WifiUtil.intToIp(hostDhcpInfo.serverAddress);
    }


    //get current network id
    public static int getCurrentNetworkId(){
        WifiManager conMan = (WifiManager) m_instance.getSystemService(Context.WIFI_SERVICE);
        currentWifiInfo = conMan.getConnectionInfo();
        return currentWifiInfo.getNetworkId();
    }





    //get current connected wifi info





    //get wifi connect state
    public static int networkState(){
        WifiManager conMan = (WifiManager) m_instance.getSystemService(Context.WIFI_SERVICE);
        return conMan.isWifiEnabled()? 1 : 0;
    }


    //连接到新设备
    public static void connectDevice(String ssid,String passwd){
//        WifiConfiguration wc = new WifiConfiguration();
//        wc.SSID = "\""+ssid+"\"";
//        wc.preSharedKey = "\""+passwd+"\"";

//        wc.hiddenSSID = true;
//        wc.status = WifiConfiguration.Status.ENABLED;
//        wc.allowedAuthAlgorithms.set(WifiConfiguration.AuthAlgorithm.OPEN);
//        wc.allowedGroupCiphers.set(WifiConfiguration.GroupCipher.TKIP);
//        wc.allowedGroupCiphers.set(WifiConfiguration.GroupCipher.CCMP);
//        wc.allowedKeyManagement.set(WifiConfiguration.KeyMgmt.WPA_PSK);
//        wc.allowedPairwiseCiphers.set(WifiConfiguration.PairwiseCipher.TKIP);
//        wc.allowedPairwiseCiphers.set(WifiConfiguration.PairwiseCipher.CCMP);
//        wc.allowedProtocols.set(WifiConfiguration.Protocol.WPA);
    }


    //生成一个网络配置
    public WifiConfiguration CreateWifiInfo(ScanResult scanresult,String Password)
   {

       WifiConfiguration wc = new WifiConfiguration();
       wc.SSID = "\""+scanresult.SSID+"\"";      //<span style="color: rgb(255, 0, 0); ">这个地方一定要注意了。旁边的“是不能够省略的。密码的地方也一样。</span>
       wc.preSharedKey = "\""+Password+"\"";      //该热点的密码
       wc.hiddenSSID = true;
       wc.status = WifiConfiguration.Status.ENABLED;
       wc.allowedAuthAlgorithms.set(WifiConfiguration.AuthAlgorithm.OPEN);
       wc.allowedGroupCiphers.set(WifiConfiguration.GroupCipher.TKIP);
       wc.allowedGroupCiphers.set(WifiConfiguration.GroupCipher.CCMP);
       wc.allowedKeyManagement.set(WifiConfiguration.KeyMgmt.WPA_PSK);
       wc.allowedPairwiseCiphers.set(WifiConfiguration.PairwiseCipher.TKIP);
       wc.allowedPairwiseCiphers.set(WifiConfiguration.PairwiseCipher.CCMP);
       wc.allowedProtocols.set(WifiConfiguration.Protocol.WPA);
       return wc;
    }
    //无密码
    public WifiConfiguration CreateWifiInfoWithoutPasswd(ScanResult scanresult)
    {
        WifiConfiguration wc = new WifiConfiguration();
        wc.SSID = "\""+scanresult.SSID+"\"";      //<span style="color: rgb(255, 0, 0); ">这个地方一定要注意了。旁边的“是不能够省略的。密码的地方也一样。</span>
//        wc.preSharedKey = "\""+Password+"\"";      //该热点的密码
        wc.hiddenSSID = true;
        wc.status = WifiConfiguration.Status.ENABLED;
        wc.allowedAuthAlgorithms.set(WifiConfiguration.AuthAlgorithm.OPEN);
        wc.allowedGroupCiphers.set(WifiConfiguration.GroupCipher.TKIP);
        wc.allowedGroupCiphers.set(WifiConfiguration.GroupCipher.CCMP);
        wc.allowedKeyManagement.set(WifiConfiguration.KeyMgmt.WPA_PSK);
        wc.allowedPairwiseCiphers.set(WifiConfiguration.PairwiseCipher.TKIP);
        wc.allowedPairwiseCiphers.set(WifiConfiguration.PairwiseCipher.CCMP);
        wc.allowedProtocols.set(WifiConfiguration.Protocol.WPA);
        return wc;
     }

    //根据网络配置连接wifi
    public static int connectToWifi(int scanresultId,String Password){


        WifiManager conMan = (WifiManager) m_instance.getSystemService(Context.WIFI_SERVICE);

        int networkId = conMan.addNetwork(m_instance.CreateWifiInfo(wifiList.get(scanresultId),Password));
        if(networkId != -1){
            conMan.enableNetwork(networkId, false);
            conMan.saveConfiguration();
            return 1;//success
        }

        return 0;//falure
    }
    //无密码
    public static int connectToWifiWithoutPasswd(int scanresultId){

        WifiManager conMan = (WifiManager) m_instance.getSystemService(Context.WIFI_SERVICE);

        int networkId = conMan.addNetwork(m_instance.CreateWifiInfoWithoutPasswd(wifiList.get(scanresultId)));
        if(networkId != -1){
            conMan.enableNetwork(networkId, false);
            conMan.saveConfiguration();
            return 1;//success
        }
        return 0;//falure
    }

    //音乐文件模块
    public static String getSdcardPath(){
        File sdDir = null;
        boolean sdCardExist = Environment.getExternalStorageState()
                        .equals(android.os.Environment.MEDIA_MOUNTED);   //判断sd卡是否存在
        if(sdCardExist)
        {
             sdDir = Environment.getExternalStorageDirectory();//获取跟目录
             return sdDir.toString();
        }
        return "";
    }


    //多媒体音量控制
    public static int getMaxVolumnStream(){
        AudioManager am=(AudioManager) m_instance.getSystemService(Context.AUDIO_SERVICE);
        return am.getStreamMaxVolume(AudioManager.STREAM_MUSIC);
    }
    public static int getCurrentVolumnStream(){
        AudioManager am=(AudioManager) m_instance.getSystemService(Context.AUDIO_SERVICE);
        return am.getStreamVolume(AudioManager.STREAM_MUSIC);
    }
    public static void setVolumnStream(int a){
//        setStreamVolume(int streamType, int index, int flags)
        AudioManager am=(AudioManager) m_instance.getSystemService(Context.AUDIO_SERVICE);
        am.setStreamVolume(AudioManager.STREAM_MUSIC,a,0);
    }


    //-------------------------------多媒体播放控制----------------------//
    //初始化音频媒体和可视化监听器
    public static void setSource(String path){


        if(mMediaPlayer != null){
            mMediaPlayer.release();
        }

        m_instance.setVolumeControlStream(AudioManager.STREAM_MUSIC);//设置音频流 - STREAM_MUSIC：音乐回放即媒体音量

        Uri uri = Uri.parse(path);

        mMediaPlayer = MediaPlayer.create(m_instance, uri);


        try {

        //在播放之前先判断playerMusic是否被占用，这样就不会报错了

               if (mMediaPlayer != null) {
                   mMediaPlayer.stop();
               }

        mMediaPlayer.prepare();
        } catch (IllegalStateException e) {

        e.printStackTrace();

        } catch (IOException e) {

        e.printStackTrace();

        }


        //初始化visualizer
        mVisualizer = new Visualizer(mMediaPlayer.getAudioSessionId());
        mVisualizer.setCaptureSize(128);
//        mVisualizer.setCaptureSize(Visualizer.getCaptureSizeRange()[1]);
        mVisualizer.setDataCaptureListener(
        new Visualizer.OnDataCaptureListener()
        {
            public void onWaveFormDataCapture(Visualizer visualizer,
            byte[] bytes, int samplingRate)
            {

//                visualDatas=new
//                  byte[] model = new byte[bytes.length];
//                  visualDatas[0] = bytes[0];
                  for (int j = 0;j < 128;j++)
                  {
                        visualDatas[j]=bytes[j];
                  }
//                  visualDatas = model;
            }
            public void onFftDataCapture(Visualizer visualizer,
            byte[] fft, int samplingRate)
            {
                for (int j = 0;j < 128;j++)
                {
                      FftvisualDatas[j]=fft[j];
                }
            }
        }, maxCR / 2, true, true);

        //初始化均衡器
        mEqualizer = new Equalizer(0, mMediaPlayer.getAudioSessionId());
        mEqualizer.setEnabled(true);

        //监听时必须调用的函数
        mVisualizer.setEnabled(true);
        //播放完成后关闭
        mMediaPlayer.setOnCompletionListener(new MediaPlayer.OnCompletionListener() {
                    public void onCompletion(MediaPlayer mediaPlayer) {
                        mVisualizer.setEnabled(false);
                    }
                });

    }

    //播放媒体
    public static void playMusic(){
        if(mMediaPlayer!=null){
            mMediaPlayer.start();
        }
    }

    //暂停媒体
    public static void pauseMusic(){
        if(mMediaPlayer.isPlaying()){
            mMediaPlayer.pause();
        }
    }

    //停止媒体
    public static void stopMusic(){
        mMediaPlayer.stop();
        mVisualizer.setEnabled(false);
    }

    //返回音频媒体的时间长度
    public static int getDuration(){
        return mMediaPlayer. getDuration();
    }

    //返回媒体播放的位置
    public static int getPosistion(){
        return mMediaPlayer.getCurrentPosition();
    }

    public static int getDatasLength(){
        //指针异常处理
        if(visualDatas==null){
            return -1;
        }

        return visualDatas.length;
    }
    public static int getDatasAt(int a){
        //指针异常处理
        if(visualDatas==null){
            return -1;
        }

        return (byte)visualDatas[a];
    }

    //Fft
    public static int getFftDatasLength(){
        //指针异常处理
        if(FftvisualDatas==null){
            return -1;
        }

        return visualDatas.length;
    }
    public static int getFftDatasAt(int a){
        //指针异常处理
        if(FftvisualDatas==null){
            return -1;
        }

        return (byte)visualDatas[a];
    }


    //-------------------------------多媒体播放控制----------------------//


    //获取屏幕像素密度
    public static double getDentisy(){
        DisplayMetrics metrics=new DisplayMetrics();
        m_instance.getWindowManager().getDefaultDisplay().getMetrics(metrics);
        return metrics.density;
    }








    /***************************tommego*********************************************************************************/
    /***************************tommego*********************************************************************************/
}
