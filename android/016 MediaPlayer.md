#### 音频播放

###### 普通播放

```java
MediaPlayer player = new MediaPlayer();
try {
    player.setDataSource("/sdcard/Download/chengdu.mp3");
    player.prepare();
    player.start();
} catch (IOException e) {
    e.printStackTrace();
}
```

###### 获取总时长

```java
int duration = player.getDuration();
```

###### 定时获取当前时长

```java
Timer timer = new Timer();
TimerTask timerTask = new TimerTask() {
    @Override
    public void run() {
        // 当前进度
        int currentPosition = player.getCurrentPosition();

    }
};
timer.schedule(timerTask, 100, 1000);
```

###### 指定播放位置

```java
player.seekTo(position);
```



#### SuffaceView

播放视频

`mediaplayer` 只能播放 `mp4` 格式或 `mp3` 格式

`surfaceview` 是一个重量级控件



#### VideoView

`videoView` 是对 `surfaceView` 和 `mediaplayer` 的封装

支持 `avi` 格式 或者 `rmvb` 格式



#### vitamio框架

