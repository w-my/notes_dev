## AIDL 进程间通信

本地服务：运行在自己应用里的服务

远程服务：运行在其他应用里的服务

实现进程间的通信：IPC

AIDL：专门是用来解决进程间通信



1、把 `Iservice.java` 文件改成 `Iservice.aidl` 文件

2、删除 `Iservice.aidl` 中 `public` 删掉

3、系统自动生成一个 `Iservice.java` 文件，自动生成一个类 `Stub`

4、把自己定义的 `IBinder` 类继承改为 `Stub`

5、保证两个应用中的 `aidl` 文件是同一个，所在的包名相同

6、修改 `IBinder` 获取方式

```
iservice = Stub.asInterface(service);
```















