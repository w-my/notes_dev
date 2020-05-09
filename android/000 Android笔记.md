## 笔记



#### 界面跳转传值

##### 正向传值

```java

public class MainActivity extends AppCompatActivity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    public void click(View view) {
        Intent intent = new Intent(this, TestActivity.class);
        intent.putExtra("name", name);
        startActivity(intent);
    }
}
```

```java
public class TestActivity extends AppCompatActivity {
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_test);
      
     		Intent intent = getIntent();
      	String name = intent.getStringExtra("name");
    }
}
```



##### 反向传值

```java
public class MainActivity extends AppCompatActivity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    public void click(View view) {
        Intent intent = new Intent(this, TestActivity.class);
        startActivityForResult(intent, 1);
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, @Nullable Intent data) {
        String phone = data.getStringExtra("phone");
        ...
        super.onActivityResult(requestCode, resultCode, data);
    }
}

```

```java
public class TestActivity extends AppCompatActivity {
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_test);
    }
  
    public void finishClick(View view) {
        Intent intent = new Intent();
        intent.putExtra("phone", "18910001000");
        setResult(10, intent);
				finish();
    }
}
```



#### 生命周期

```java
@Override
protected void onCreate(Bundle savedInstanceState) { // 创建
    super.onCreate(savedInstanceState);
}

@Override
protected void onStart() { // 可见
    super.onStart();
}

@Override
protected void onResume() { // 可交互
    super.onResume();
}

@Override
protected void onPause() { // 不可交互
    super.onPause();
}

@Override
protected void onStop() { // 不可见
    super.onStop();
}

@Override
protected void onDestroy() { // 销毁
    super.onDestroy();
}
```



#### 横竖屏切换

```java
android:screenOrientation="portrait" // 竖屏
android:screenOrientation="landscape" // 横屏
```

**注意：切换横竖屏，当前实例会被销毁重新创建**


