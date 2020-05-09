## Animator-属性动画

动画 **会** 改变控件真是坐标



#### 透明动画

```java
ObjectAnimator
        .ofFloat(imageView, "alpha", 1.0f, 0.0f, 1.0f, 0.0f, 0.8f)
        .setDuration(2000)
        .start();
```

#### 旋转动画

```java
ObjectAnimator
        .ofFloat(imageView, "rotation", 0, 180, 0, -180, 0)
        .setDuration(2000)
        .start();
```

#### 缩放动画

```java
ObjectAnimator
        .ofFloat(imageView, "scaleY", 1.0f, 2.0f, 1.5f, 2.0f)
        .setDuration(2000)
        .start();
```

#### 位移动画

```java
ObjectAnimator
        .ofFloat(imageView, "translationX", 10, 50, 20, 80)
        .setDuration(2000)
        .start();
```

#### 组合动画

```java
ObjectAnimator oaA = ObjectAnimator.ofFloat(imageView, "alpha", 0, 0.5f, 0, 1);
ObjectAnimator oaR = ObjectAnimator.ofFloat(imageView, "rotation", 0, 180, 90, 360);
ObjectAnimator oaS = ObjectAnimator.ofFloat(imageView, "scaleY", 0.5f, 1, 1.5f, 1);
ObjectAnimator oaT = ObjectAnimator.ofFloat(imageView, "translationX", 10, 20, 50, 0);
AnimatorSet as = new AnimatorSet();
as.setTarget(imageView);
as.setDuration(2000);
//as.playSequentially(oaA, oaR, oaS, oaT); // 顺序执行动画
as.playTogether(oaA, oaR, oaS, oaT); // 混合同时执行动画
as.start();
```



#### 使用xml实现属性动画

在 `res` 目录下创建动画目录 `animator` 

#### 创建动画xml文件

###### animator_alpha.xml

```java
<animator xmlns:android="http://schemas.android.com/apk/res/android">
    <objectAnimatior
        android:propertyName="alpha"
        android:duration="2000"
        android:valueFrom="1"
        android:valueTo="0.2">
    </objectAnimatior>
</animator>
```















