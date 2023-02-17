# Vue脚手架

？？？？？ 环境搭建  项目创建





## @vue/cli

```sh
npm install -g @vue/cli
```



















## 脚手架基础



### 脚手架文件结构

```
├── node_modules
├── public
│   ├── favicon.ico						页签图标
│   └── index.html						主页面
├── src
│   ├── assets                静态资源
│   │   └── logo.png
│   ├── components            组件
│   │   └── HelloWorld.vue
│   ├── App.vue               根组件
│   └── main.js               入口
├── .gitignore          			git版本忽略配置
├── babel.config.js						babel配置
├── package.json							包配置
├── package-lock.json					包版本控制
├── README.md									应用描述
└── vue.config.js							自定义配置
```



### 不同版本的Vue

vue.js 与 vue.runtime.xxx.js 的区别：

	1. vue.js 是完整版本的Vue，包含：核心功能 + 模块解析器。
	1. vue.runtime.xxx.js 是运行版本的Vue，只包含：核心功能，没有模板解析器。

因为 vue.runtime.xxx.js 没有模板解析器，所以不能使用 template 配置项，需要使用 render 函数接收到的 createElement 函数去指定具体内容。



### vue.config.js 配置文件

自定义脚手架配置

> 使用 vue inspect > output.js 可以查看到Vue脚手架的默认配置。
>
> 使用 vue.config.js 可以对脚手架进行个性化定制，详见：https://cli.vuejs.org/zh













