# Vue

## 创建vue项目
前题：己安装16.0或更高版本的 Node.js

> npm init vue@latest

这一指令将会安装并执行 create-vue，它是 Vue 官方的项目脚手架工具。

在项目被创建后，通过以下步骤安装依赖并启动开发服务器：

> cd <your-project-name>
> npm install
> npm run dev

当准备将应用发布到生产环境时，运行：

> npm run build

此命令会在 ./dist 文件夹中为应用创建一个生产环境的构建版本。

## 创建vue应用

### 应用实例

```vue
import { createApp } from 'vue'

const app = createApp({
  /* 根组件选项 */
})
```

### 挂载应用

应用实例必须在调用了 .mount() 方法后才会渲染出来。该方法接收一个“容器”参数，可以是一个实际的 DOM 元素或是一个 CSS 选择器字符串：

```html
<div id="app"></div>
```
```js
app.mount('#app')
```

### 应用配置

应用实例会暴露一个 .config 对象允许我们配置一些应用级的选项，例如定义一个应用级的错误处理器，它将捕获所有由子组件上抛而未被处理的错误：

```js
app.config.errorHandler = (err) => {
  /* 处理错误 */
}
```

## 模板语法

  

  

