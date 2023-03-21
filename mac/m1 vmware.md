# VMWare 安装





# M1 装 Windows

1. 下载

[windows下载 https://next.itellyou.cn/Original/Index](https://next.itellyou.cn/Original/Index)

2. 安装

选择镜像文件安装，进入安装时按 esc ，执行完安装。

3. 安装 vmware tools

虚拟机 --> 安装 vmware tools，然后多出一个 D 盘。

开始菜单找到 windows teminal，右键管理员身份运行，依次执行一下命令：

 `Set-ExecutionPolicy RemoteSigned` 

`cd d:`

`.\setup.ps1`

安装成功后分辨率和网络就好了。

4. 共享文件

在 windows 里找个文件夹，右键-属性-共享，关闭密码保护，然后到 mac 到访达，【前往服务器】 输入 `smb://DESKTOP-...` ，或网络选择共享的文件夹。


