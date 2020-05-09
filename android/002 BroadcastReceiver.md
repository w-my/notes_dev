## 系统广播

#### SD卡状态监听

1、创建监听类

```java
public class SdcardStateReceiver extends BroadcastReceiver {
    @Override
    public void onReceive(Context context, Intent intent) {
        String action = intent.getAction();
        if ("android.intent.action.MEDIA_MOUNTED".equals(action)) {
            System.out.println("sd卡挂载了。。。");
        }else if ("android.intent.action.MEDIA_UNMOUNTED".equals(action)) {
            System.out.println("sd卡卸载了。。。");
        }
    }
}
```

2、`AndroidManifest.xml` 中添加配置

```java
<receiver android:name=".Broadcast.SdcardStateReceiver">
    <intent-filter>
        <action android:name="android.intent.action.MEDIA_MOUNTED"/>
        <action android:name="android.intent.action.MEDIA_UNMOUNTED"/>
        <data android:scheme="file"/>
    </intent-filter>
</receiver>
```



#### 电话拨出监听

1、创建监听类

```java
public class OutGoingCallReceiver extends BroadcastReceiver {
    @Override
    public void onReceive(Context context, Intent intent) {
        String str = getResultData();
        System.out.println("==> phone number: " + str);
    }
}
```

2、`AndroidManifest.xml` 中添加配置

```java
<receiver android:name=".Broadcast.OutGoingCallReceiver">
    <intent-filter>
        <action android:name="android.intent.action.NEW_OUTGOING_CALL" />
    </intent-filter>
</receiver>
```

3、`AndroidManifest.xml` 中添加权限

```java
<uses-permission android:name="android.permission.PROCESS_OUTGOING_CALLS"/>
```



#### 短信监听

1、创建监听类

```java
public class SmsReceiver extends BroadcastReceiver {
    @Override
    public void onReceive(Context context, Intent intent) {
        Object[] objs = (Object[]) intent.getExtras().get("pdus");
        for (Object obj : objs) {
            SmsMessage smsMessage = SmsMessage.createFromPdu((byte[]) obj);
            String msgBody = smsMessage.getMessageBody();
            String address = smsMessage.getOriginatingAddress();

            System.out.println("body: " + msgBody + " ---- " + address);
        }
    }
}
```

2、`AndroidManifest.xml` 中添加配置

```java
<receiver android:name=".Broadcast.SmsReceiver">
    <intent-filter>
        <action android:name="android.provider.Telephony.SMS_RECEIVED"/>
    </intent-filter>
</receiver>
```

3、`AndroidManifest.xml` 中添加权限

```java
<uses-permission android:name="android.permission.RECEIVE_SMS"/>
```



#### 应用安装卸载监听

1、创建监听类

```java
public class AppStateReceiver extends BroadcastReceiver {
    @Override
    public void onReceive(Context context, Intent intent) {
        String action = intent.getAction();
        if ("android.intent.action.PACKAGE_ADDED".equals(action)) {
            System.out.println("应用被安装了");
        }else if ("android.intent.action.PACKAGE_REMOVED".equals(action)) {
            System.out.println("应用被卸载了");
        }
    }
}
```

2、`AndroidManifest.xml` 中添加配置

```java
<receiver android:name=".Broadcast.AppStateReceiver">
    <intent-filter>
        <action android:name="android.intent.action.PACKAGE_ADDED"/>
        <action android:name="android.intent.action.PACKAGE_REMOVED"/>
        <data android:scheme="package"/>
    </intent-filter>
</receiver>
```



#### 开机监听 开机启动

1、创建监听类

```java
public class BootReceiver extends BroadcastReceiver {
    @Override
    public void onReceive(Context context, Intent intent) {
        // 手机启动时启动app
        Intent mainIntent = new Intent(context, MainActivity.class);
        // 不能在广播中直接开启activity，需要添加如下tag
        mainIntent.setFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
        context.startActivity(mainIntent);
    }
}
```

2、`AndroidManifest.xml` 中添加配置

```java
<receiver android:name=".Broadcast.BootReceiver">
    <intent-filter>
        <action android:name="android.intent.action.BOOT_COMPLETED"/>
    </intent-filter>
</receiver>
```

3、`AndroidManifest.xml` 中添加权限

```java
<uses-permission android:name="android.permission.RECEIVE_BOOT_COMPLETED"/>
```


## 自定义广播
#### 无序广播

1、定义接收自定义广播类

```java
public class CustomReceiver extends BroadcastReceiver {
    @Override
    public void onReceive(Context context, Intent intent) {
        String msg = intent.getStringExtra("msg");
        Toast.makeText(context, msg, Toast.LENGTH_SHORT).show();
    }
}
```

2、`AndroidManifest.xml` 中添加配置

```java
<receiver android:name=".Broadcast.CustomReceiver">
    <intent-filter>
        <action android:name="com.aw.broadcast.msg"/>
    </intent-filter>
</receiver>
```

3、发送无序广播

```java
public void sendBroadcast(View v) {
    Intent intent = new Intent();
    intent.setAction("com.aw.broadcast.msg");
    intent.putExtra("msg", "发送了一个无序广播");
    sendBroadcast(intent);
}
```



#### 有序广播

可配置接收优先级

有序广播可以被终止

有序广播可以被修改



1、定义接收自定义广播类

```java
public class ProvinceReceiver extends BroadcastReceiver {
    @Override
    public void onReceive(Context context, Intent intent) {
        String msg = getResultData();
        Toast.makeText(context, "省接收到："+msg, Toast.LENGTH_SHORT).show();
      	// 终止广播 
      	abortBroadcast();
      	// 修改广播数据
      	setResultData("500斤大米");
    }
}
```

```java
public class CityReceiver extends BroadcastReceiver {
    @Override
    public void onReceive(Context context, Intent intent) {
        String msg = getResultData();
        Toast.makeText(context, "市接收到："+msg, Toast.LENGTH_SHORT).show();
    }
}
```

```java
public class FinalReceiver extends BroadcastReceiver {
    @Override
    public void onReceive(Context context, Intent intent) {
        String msg = getResultData();
        Toast.makeText(context, "最终结果："+msg, Toast.LENGTH_SHORT).show();
    }
}
```

2、`AndroidManifest.xml` 中添加配置

```java
<receiver android:name=".Broadcast.ProvinceReceiver">
    <!-- 接收优先级：-1000~1000 -->
    <intent-filter android:priority="1000">
        <action android:name="com.aw.broadcast.ordermsg"/>
    </intent-filter>
</receiver>
<receiver android:name=".Broadcast.CityReceiver">
    <!-- 接收优先级：-1000~1000 -->
    <intent-filter android:priority="500">
        <action android:name="com.aw.broadcast.ordermsg"/>
    </intent-filter>
</receiver>   
```

3、发送有序广播

```java
public void sendBroadcast(View v) {
    Intent intent = new Intent();
    intent.setAction("com.aw.broadcast.ordermsg");
    sendOrderedBroadcast(intent, // 意图
            null, // 接收的权限
            new FinalReceiver(), // 最终的receiver
            null, // handler
            1, // 初始码
            "1000斤大米", // 广播消息
            null);
}
```

结果：省先接收到通知，市后就接收到通知，最后FinalReceiver接到通知，可对结果处理。



#### 特殊广播接收者

注册广播接收者的两种方式：

【1】动态注册 通过代码方式注册

【2】在清单文件通过 receiver tag 节点静态发布

##### 代码动态注册

1、定义接收广播类

```java
public class ScreenReceiver extends BroadcastReceiver {
    @Override
    public void onReceive(Context context, Intent intent) {
        String action = intent.getAction();
        if ("android.intent.action.SCREEN_OFF".equals(action)) {
            System.out.println("屏幕关闭了");
        }else if ("android.intent.action.SCREEN_ON".equals(action)) {
            System.out.println("屏幕解锁了");
        }
    }
}
```

2、动态注册接收

```java
public class MainActivity extends AppCompatActivity {
    
  	ScreenReceiver screenReceiver;
  
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        screenReceiver = new ScreenReceiver();
				
        IntentFilter intentFilter = new IntentFilter();
        intentFilter.addAction("android.intent.action.SCREEN_OFF");
        intentFilter.addAction("android.intent.action.SCREEN_ON");
      	// 注册
        registerReceiver(screenReceiver, intentFilter);
    }

    @Override
    protected void onDestroy() {
      	// 注销
        unregisterReceiver(screenReceiver);
        super.onDestroy();
    }
}
```





























