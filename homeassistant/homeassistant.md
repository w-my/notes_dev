# Home assistant

https://www.hachina.io/

1. 安装 python 3.5.4 （https://www.python.org/downloads/macos/）

   

## docker 安装 homeassistant

1. 下载镜像

```sh
docker pull homeassistant/home-assistant
```

2. 创建容器并运行安装程序

```sh
docker run -d --name="home-assistants" -v /[容器安装位置]:/config -p 8123:8123 homeassistant/home-assistant
```

容器安装在一个新文件夹内

**记住容器位置，后面安装hacs需要**

e.g.

```sh
docker run -d --name="hass" -v /Users/digiqal/Documents/hass:/config -p 8123:8123 homeassistant/home-assistant
```

3. 打开 home-assistant

通过 [127.0.0.1:8123](127.0.0.1:8123) 进入配置 Home-Assistant

- hass-root



## HACS插件商城

1. 进入容器执行

   ```sh
   docker exec -it homeassistant bash
   ```

2. 执行hacs安装命令

   ```sh
   wget -O - https://get.hacs.xyz | bash -
   ```

```
# 如果遇到网络问题下载不了github的仓库代码，
# 要不科学上网，要不直接下载 https://github.com/hacs/integration/releases/latest/download/hacs.zip
# 然后把hacs.zip解压到容器的/config/custom_components/hacs目录，手动重启容器
```

