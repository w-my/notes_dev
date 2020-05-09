#### 系统信任

安装三方软件，系统提示无法打开或损坏，可以关闭系统保护

``` 
// 关闭系统保护，可以安装苹果不信任的软件
sudo spctl --master-disable
// 打开系统保护，无法安装苹果不信任的软件
sudo spctl --master-enable
```



