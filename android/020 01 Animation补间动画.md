## Animation-补间动画

动画 **不会** 改变控件真是坐标



#### 透明动画

```java
AlphaAnimation aa = new AlphaAnimation(1.0f, 0.0f);
        aa.setDuration(1000);
        aa.setRepeatCount(1); // 重复次数
        aa.setRepeatMode(Animation.REVERSE // 反转执行动画
        );
imageView.startAnimation(aa);
```

#### 旋转动画

```java
RotateAnimation ra = new RotateAnimation(
        0, 360,
        Animation.RELATIVE_TO_SELF, 0.5f, // 相对于自己x向中心点为中心执行动画
        Animation.RELATIVE_TO_SELF, 0.5f);
ra.setDuration(1000);
ra.setRepeatCount(1);
ra.setRepeatMode(Animation.REVERSE);
imageView.startAnimation(ra);
```

#### 缩放动画

```java
ScaleAnimation sa = new ScaleAnimation(
        1.0f, 2.0f, // x向缩放比例
        1.0f, 2.0f,
        Animation.RELATIVE_TO_SELF, 0.5f,
        Animation.RELATIVE_TO_SELF, 0.5f);
sa.setDuration(1000);
sa.setRepeatCount(1);
sa.setRepeatMode(Animation.REVERSE);
imageView.startAnimation(sa);
```

#### 位移动画

```java
TranslateAnimation ta = new TranslateAnimation(
        Animation.RELATIVE_TO_PARENT, 0, // 相对于父控件x向起始点
        Animation.RELATIVE_TO_PARENT, 0,   // 相对于父控件x向移动比例
        Animation.RELATIVE_TO_PARENT, 0,
        Animation.RELATIVE_TO_PARENT, 0.2f);
ta.setDuration(1000);
ta.setFillAfter(true); // 动画结束后停留在目标位置
imageView.startAnimation(ta);
```

#### 组合动画

```java
AlphaAnimation aa = new AlphaAnimation(1.0f, 0.0f);
        aa.setDuration(1000);
        aa.setRepeatCount(1); // 重复次数
        aa.setRepeatMode(Animation.REVERSE // 反转执行动画
        );

RotateAnimation ra = new RotateAnimation(
        0, 360,
        Animation.RELATIVE_TO_SELF, 0.5f, // 相对于自己x向中心点为中心执行动画
        Animation.RELATIVE_TO_SELF, 0.5f);
ra.setDuration(1000);
ra.setRepeatCount(1);
ra.setRepeatMode(Animation.REVERSE);

AnimationSet set = new AnimationSet(true);
set.addAnimation(aa);
set.addAnimation(ra);
imageView.startAnimation(set);
```



## 使用xml实现补间动画

在 `res` 目录下创建动画目录 `anim` 

#### 创建动画xml文件

###### anim_alpha.xml

```java
<alpha xmlns:android="http://schemas.android.com/apk/res/android"
    android:fromAlpha="1.0"
    android:toAlpha="0.0"
    android:duration="1000"
    android:repeatCount="1"
    android:repeatMode="reverse" >
</alpha>
```

###### anim_rotate.xml

```java
<rotate xmlns:android="http://schemas.android.com/apk/res/android"
    android:fromDegrees="0"
    android:toDegrees="360"
    android:pivotX="50%"
    android:pivotY="50%"
    android:duration="1000"
    android:repeatCount="1"
    android:repeatMode="reverse" >
</rotate>
```

###### anim_scale.xml

```java
<scale xmlns:android="http://schemas.android.com/apk/res/android"
    android:fromXScale="1.0"
    android:toXScale="2.0"
    android:fromYScale="1.0"
    android:toYScale="2.0"
    android:pivotX="50%"
    android:pivotY="50%"
    android:duration="1000"
    android:repeatCount="1"
    android:repeatMode="reverse" >
</scale>
```

###### anim_translate.xml

```java
<translate xmlns:android="http://schemas.android.com/apk/res/android"
    android:fromXDelta="0%p"
    android:toXDelta="20%p"
    android:fromYDelta="0%p"
    android:toYDelta="20%p"
    android:duration="1000"
    android:fillAfter="true" >
</translate>
```

###### anim_translate.xml

```java
<set xmlns:android="http://schemas.android.com/apk/res/android"
    android:duration="1000"
    android:repeatCount="1"
    android:repeatMode="reverse">

    <alpha xmlns:android="http://schemas.android.com/apk/res/android"
        android:fromAlpha="1.0"
        android:toAlpha="0.0">
    </alpha>

    <rotate xmlns:android="http://schemas.android.com/apk/res/android"
        android:fromDegrees="0"
        android:toDegrees="360"
        android:pivotX="50%"
        android:pivotY="50%" >
    </rotate>

    <scale xmlns:android="http://schemas.android.com/apk/res/android"
        android:fromXScale="1.0"
        android:toXScale="2.0"
        android:fromYScale="1.0"
        android:toYScale="2.0"
        android:pivotX="50%"
        android:pivotY="50%" >
    </scale>

    <translate xmlns:android="http://schemas.android.com/apk/res/android"
        android:fromXDelta="0%p"
        android:toXDelta="20%p"
        android:fromYDelta="0%p"
        android:toYDelta="20%p">
    </translate>
</set>
```

#### 调用动画

```java
imageView.startAnimation(AnimationUtils.loadAnimation(getApplicationContext(), R.anim.anim_alpha));
```

```java
imageView.startAnimation(AnimationUtils.loadAnimation(getApplicationContext(), R.anim.anim_rotate));
```

```java
imageView.startAnimation(AnimationUtils.loadAnimation(getApplicationContext(), R.anim.anim_scale));
```

```java
imageView.startAnimation(AnimationUtils.loadAnimation(getApplicationContext(), R.anim.anim_translate));
```

```java
imageView.startAnimation(AnimationUtils.loadAnimation(getApplicationContext(), R.anim.anim_set));
```

