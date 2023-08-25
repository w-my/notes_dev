# Docker

## 安装

[Docker 官网](https://docs.docker.com/desktop/install/mac-install/)

Apple silicon 最好安装 Rosetta 2.

```sh
$ softwareupdate --install-rosetta
```



**或者使用 Homebrew 安装**

```sh
$ brew cask install docker
```



## 配置

### 设置 Docker 默认镜像为阿里云仓库

打开 [阿里云镜像官网](https://cr.console.aliyun.com/cn-hangzhou/instances/mirrors) 扫码登录，复制加速器地址

打开 **DockerDesktop**，点击右上角设置小齿轮，并点击Docker Engine，将**registry-mirrors**下的网址替换成加速器地址，最后点击Apply&restart

```json
{
  "builder": {
    "gc": {
      "defaultKeepStorage": "20GB",
      "enabled": true
    }
  },
  "experimental": false,
  "features": {
    "buildkit": true
  },
  "registry-mirrors": [
     "https://....mirror.aliyuncs.com"
  ]
}
```



## 常用命令

查看已安装的镜像

```sh
$ docker images
```



