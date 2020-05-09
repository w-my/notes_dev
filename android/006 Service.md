## Service

#### startService 方式开启服务

特点：

服务一旦被开启，此服务就会在后台长期运行，知道用户主动停止；

外部无法调用服务里的方法；



1、创建服务类

```java
public class DemoService extends Service {
    @Override
    public IBinder onBind(Intent intent) {
        return null;
    }

    @Override
    public void onCreate() { // 只在创建时调用一次
        super.onCreate();
        System.out.println("服务被创建");
    }

    @Override
    public int onStartCommand(Intent intent, int flags, int startId) { // 每次开启都会调用
        System.out.println("服务被开启");
        return super.onStartCommand(intent, flags, startId);
    }

    @Override
    public void onDestroy() {
        super.onDestroy();
        System.out.println("服务被停止");
    }
}
```

2、配置服务

```java
<service android:name=".Service.DemoService" />
```

3、开启停止服务

```java
public void startService(View v) {
    Intent intent = new Intent(this, DemoService.class);
    startService(intent);
}
public void stopService(View v) {
    Intent intent = new Intent(this, DemoService.class);
    stopService(intent);
}
```



#### bindService 方式开启服务

特点：

bind方式开启服务，服务不能在设置中找到，相当于一个隐形服务；

activity销毁时，必须关闭服务；

外部可以调用服务里的方法；



1、创建服务类

```java
public class DemoService extends Service {
    @Override
    public IBinder onBind(Intent intent) { // 只能被绑定一次
        System.out.println("服务被绑定");
        return null;
    }

    @Override
    public void onCreate() { // 只在创建时调用一次
        super.onCreate();
        System.out.println("服务被创建");
    }
}
```

2、配置服务

```java
<service android:name=".Service.DemoService" />
```

3、开启停止服务

```java
public class ServiceTestActivity extends AppCompatActivity {

    MyConn myConn;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

    }

    @Override
    protected void onDestroy() {
        unbindService(myConn);
        super.onDestroy();
    }

    public void bindService(View v) {
        Intent intent = new Intent(this, DemoService.class);
        myConn = new MyConn();
        bindService(intent, myConn, BIND_AUTO_CREATE);
    }

//    public void unbindService(View v) {
//        unbindService(myConn);
//    }

    private class MyConn implements ServiceConnection {
        @Override
        public void onServiceConnected(ComponentName name, IBinder service) {
            // 服务类中 `onBind` 方法返回 `nil` 时，不会调用此方法
            System.out.println("连接服务");
        }

        @Override
        public void onServiceDisconnected(ComponentName name) {
            System.out.println("断开服务");
        }
    }
}
```



#### 使用bindService方法调用服务里的方法

1、创建服务

```java
public class TestBindService extends Service {
    @Nullable
    @Override
    public IBinder onBind(Intent intent) {
        return new MyBinder();
    }

    public void serviceClick() {
        Toast.makeText(getApplicationContext(), "服务内的方法被调用", Toast.LENGTH_SHORT).show();
    }

    public class MyBinder extends Binder {
        public void callServiceClick() {
            serviceClick();
        }
    }
}
```

2、配置服务

```java
<service android:name=".TestBindService"/>
```

3、绑定服务，调用方法

```java
public class MainActivity extends AppCompatActivity {
    private MySerivceConn mySerivceConn;
    TestBindService.MyBinder myBinder;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        Intent intent = new Intent(this, TestBindService.class);
        mySerivceConn = new MySerivceConn();
        bindService(intent, mySerivceConn, BIND_AUTO_CREATE);
    }

    @Override
    protected void onDestroy() {
        unbindService(mySerivceConn);
        super.onDestroy();
    }

    public void click(View v) {
        myBinder.callServiceClick();
    }

    private class MySerivceConn implements ServiceConnection {
        @Override
        public void onServiceConnected(ComponentName componentName, IBinder iBinder) {
            myBinder = (TestBindService.MyBinder) iBinder;
        }

        @Override
        public void onServiceDisconnected(ComponentName componentName) {

        }
    }
}
```



##### 使用bindService，通过接口方式调用服务里的方法

1、通过接口暴露服务想要暴露的方法

```java
public interface Iservice {
    public void publicServiceClick();
}
```

2、创建服务类，实现接口方法

```java
public class TestBindService extends Service {
    @Nullable
    @Override
    public IBinder onBind(Intent intent) {
        return new MyBinder();
    }

    public void serviceClick() { // 对外暴露
        Toast.makeText(getApplicationContext(), "服务内的方法被调用", Toast.LENGTH_SHORT).show();
    }

    public void serviceClick1() { // 对外私有

    }

    private class MyBinder extends Binder implements Iservice {
        @Override
        public void publicServiceClick() {
            serviceClick();
        }

        public void callServiceClick1() {
            serviceClick1();
        }
    }
}
```

2、配置服务

```java
<service android:name=".TestBindService"/>
```

3、绑定服务，调用方法

```java
public class MainActivity extends AppCompatActivity {
    private MySerivceConn mySerivceConn;
    Iservice myBinder;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        Intent intent = new Intent(this, TestBindService.class);
        mySerivceConn = new MySerivceConn();
        bindService(intent, mySerivceConn, BIND_AUTO_CREATE);
    }

    @Override
    protected void onDestroy() {
        unbindService(mySerivceConn);
        super.onDestroy();
    }

    public void click(View v) {
        myBinder.publicServiceClick();
        // myBinder.callServiceClick1(); // 无法调用，私有，且未通过接口暴露
    }

    private class MySerivceConn implements ServiceConnection {
        @Override
        public void onServiceConnected(ComponentName componentName, IBinder iBinder) {
            myBinder = (Iservice) iBinder;
        }

        @Override
        public void onServiceDisconnected(ComponentName componentName) {

        }
    }
}
```



#### 混合方式开启服务的流程

既想让服务再后台长期运行，又想调用服务里的方法



1、先调用 `startService` 方法开启服务，保证服务在后台长期运行

2、调用 `bindService` 方法，获取中间人对象

3、调用 `unbindService` 解绑对象

4、退出时调用 `stopService` 停止服务



实现：

1、定义服务接口

```java
public interface Iservice {
    public void playClick();
    public void stopClick();
    public void nextClick();
}
```

2、实现服务类

```java
public class PlayService extends Service {
    @Override
    public IBinder onBind(Intent intent) {
        System.out.println("服务被绑定");
        return new MyBinder();
    }

    @Override
    public void onCreate() {
        super.onCreate();
        System.out.println("服务被创建");
    }

    @Override
    public int onStartCommand(Intent intent, int flags, int startId) {
        System.out.println("服务被开启");
        return super.onStartCommand(intent, flags, startId);
    }

    @Override
    public void onDestroy() {
        System.out.println("服务被销毁");
        super.onDestroy();
    }


    public void prepare() {
        System.out.println("准备播放");
    }

    public void play() {
        System.out.println("开始播放");
    }

    public void stop() {
        System.out.println("停止播放");
    }

    public void next() {
        System.out.println("播放下一个");
    }

    private class MyBinder extends Binder implements Iservice {
        @Override
        public void playClick() {
            play();
        }

        @Override
        public void stopClick() {
            stop();
        }

        @Override
        public void nextClick() {
            next();
        }
    }
}
```

3、配置服务

```java
<service android:name=".PlayService" />
```

4、测试服务

```java
public class MainActivity extends AppCompatActivity {
    private MyServiceConn myServiceConn;
    private Iservice myBinder;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

      	// 混合方式开启服务
				Intent intent = new Intent(this, PlayService.class);
				startService(intent);
				myServiceConn = new MyServiceConn();
				bindService(intent, myServiceConn, BIND_AUTO_CREATE);
    }
  
	  @override
  	protected void onDestroy() {
      	// 解绑服务
      	unbindService(myServiceConn);
      	super.onDestroy();
    }

    //private void stopService() {
    //    Intent intent = new Intent(this, PlayService.class);
    //    stopService(intent);
    //}
   
    private void playClick() {
        myBinder.playClick();
    }

    private class MyServiceConn implements ServiceConnection {
        @Override
        public void onServiceConnected(ComponentName componentName, IBinder iBinder) {
            System.out.println("连接了服务");
            myBinder = (Iservice) iBinder;
        }

        @Override
        public void onServiceDisconnected(ComponentName componentName) {
            System.out.println("断开了服务");
        }
    }

}
```

```java



// 测试服务内部方法
playClick();
```