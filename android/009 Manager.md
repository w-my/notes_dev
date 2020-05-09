## Manager

#### SmsManager



#### TelephonyManager

##### e.g. 电话监听

```java
TelephonyManager tm = (TelephonyManager) getSystemService(TELEPHONY_SERVICE);
tm.listen(new MyPhoneStateListener(), PhoneStateListener.LISTEN_CALL_STATE);
```

```java
private class MyPhoneStateListener extends PhoneStateListener {
    @Override
    public void onCallStateChanged(int state, String phoneNumber) {
        super.onCallStateChanged(state, phoneNumber);
        switch (state) {
            case TelephonyManager.CALL_STATE_IDLE: // 空闲状态

                break;
            case TelephonyManager.CALL_STATE_OFFHOOK: // 接听状态
                System.out.println("开始录音");
                break;
            case TelephonyManager.CALL_STATE_RINGING: // 来电响铃状态
                System.out.println("准备录音");
                break;
        }
    }
}
```



#### WindowManager 



#### FragmentManager



#### NotificationManager

- 通知和服务联用，提升进程的优先级

  

###### 权限

```java
<uses-permission android:name="android.permission.VIBRATE" />
```

###### 发送通知

```java
Notification notif = new Notification.Builder(this)
        .setContentTitle("标题")
        .setContentText("通知内容")
        .setSmallIcon(R.mipmap.ic_launcher)
        .setLargeIcon(BitmapFactory.decodeResource(getResources(), R.mipmap.ic_launcher))
        .build();

NotificationManager nm = (NotificationManager) getSystemService(NOTIFICATION_SERVICE);
nm.notify(10, notif);
```

###### 取消通知

```java
NotificationManager nm = (NotificationManager) getSystemService(NOTIFICATION_SERVICE);
nm.cancel(10);
```



