## 动画

#### 帧动画

1、创建动画资源

```java
<?xml version="1.0" encoding="utf-8"?>
<animation-list xmlns:android="http://schemas.android.com/apk/res/android">
    <item android:drawable="@drawable/anim_01" android:duration="200"/>
    <item android:drawable="@drawable/anim_02" android:duration="200"/>
    <item android:drawable="@drawable/anim_03" android:duration="200"/>
    <item android:drawable="@drawable/anim_04" android:duration="200"/>
    <item android:drawable="@drawable/anim_05" android:duration="200"/>
</animation-list>
```

2、执行动画

```java
public class AnimActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_anim);

        final ImageView iv = findViewById(R.id.iv);
        iv.setBackgroundResource(R.drawable.my_anim);

        AnimationDrawable anim = (AnimationDrawable) iv.getBackground();
        anim.start();

//        new Thread(){
//            @Override
//            public void run() {
//                SystemClock.sleep(20);
//                AnimationDrawable anim = (AnimationDrawable) iv.getBackground();
//                anim.start();
//            }
//        }.start();
    }
}
```



#### View动画



#### 属性动画



#### RotateAnimation 旋转动画

```java
RotateAnimation ra = new RotateAnimation(
        0f, -180f,
        Animation.RELATIVE_TO_SELF, 0.5f,
        Animation.RELATIVE_TO_SELF, 1.1f);
ra.setDuration(500);
ra.setFillAfter(true);
layout.startAnimation(ra);
```

