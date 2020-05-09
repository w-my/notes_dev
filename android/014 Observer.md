## Observer

#### 自定义监听

###### 创建一个监听

```java
public class ObserverActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_observer);

        Uri uri = Uri.parse("content://com.observer.test");
        getContentResolver().registerContentObserver(uri, true, new MyContentObserver(new Handler()));
    }

    private class MyContentObserver extends ContentObserver {
        public MyContentObserver(Handler handler) {
            super(handler);
        }

        public void onChange(boolean selfChange) {
            System.out.println("接收到了变更通知");
            super.onChange(selfChange);
        }
    }
}
```

###### 在另一个app中发送通知消息

```java
Uri uri = Uri.parse("content://com.observer.test/update");
getContentResolver().notifyChange(uri, null);
```



#### 监听系统短信通知

```java
public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        Uri uri = Uri.parse("content://sms");
        getContentResolver().registerContentObserver(uri, true, new MyContentObserver(new Handler()));
    }

    private class MyContentObserver extends ContentObserver {
        public MyContentObserver(Handler handler) {
            super(handler);
        }

        public void onChange(boolean selfChange) {
            System.out.println("短信数据库变更了");
            super.onChange(selfChange);
        }
    }
}
```

















