## 小程序使用支持 es7 的 async 语法

1、在小程序开发工具中，勾选 es6 转 es5 语法；

2、下载 facebook 的 regenerator 库中的 [regenerator/packages/regenerator-runtime/runtime.js](https://github.com/facebook/regenerator/blob/master/packages/regenerator-runtime/runtime.js) ，进入页面点击 Raw 在浏览器打开后复制全部代码；

3、在小程序目录下新建文件夹 lib/runtime/runtime.js ，将代码拷贝进入；

4、在每一个需要使用 async 语法的页面 js 文件中引入（不能全局引入）

```js
import regeneratorRuntime from '../../lib/runtime/runtime';
```



