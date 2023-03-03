[TOC]



# lib

https://www.npmjs.com/



## less

查看 less-loader 可用版本

```sh
npm view less-loader versions
```

安装指定7.下最新版本：

```sh
npm i less-loader@7
```

> 注意：vue 使用的 webpack 版本不是最新版本，所以不能使用最新版本的 less-loader 。



## pubsub.js

消息订阅

**安装**

```sh
npm i pubsub-js
```

**使用**

引入：

```js
import pubsub from 'pubsub-js'
```

订阅：

```js
<scrip>
	import pubsub from 'pubsub-js'
	export default {
  	...
  	methods: {
  		demo(msgName, data) {
  			console.log('收到了消息', msgName, data)
  		}
  	},
  	mounted() {
  		this.pubId = pubsub.subscribe('hello', this.demo)
  	},
  	beforeDestroy() {
  		pubsub.unsubscribe(this.pubId);
  	}
  	...
  }
</scrip>
```

发布消息

```js
 pubsub.publish('xxx', 数据)
```



## [animate.css](https://www.npmjs.com/package/animate.css)

安装：

```sh
npm install animate.css
```

引入：

```js
import "animate.css"
```

使用：

```vue
<template>
	...
  <button @click="isShow = !isShow">显示/隐藏</button>
  <transition-group
    appear
    enter-active-class="animate__swing"
    leave-active-class="animate__backOutUp"
  >
    <h1 v-show="!isShow" key="1">你好啊</h1>
    <h1 v-show="isShow" key="2">hello</h1>
  </transition-group>
  ...
</template>

<script>
  export default {
    data() {
      return {
        isShow: true 
      }
    }
  }
</script>
```



## axios

安装：

```sh
npm i axios
```

引入：

```js
import axios from 'axios'
```

e.g.

```js
axios.get('http://loaclhost:8080/students').then(
	response => {
    console.log('请求成功了：', response.data)
  },
  error => {
    console.log('请求失败了：', error.message)
  }
)
```



**解决跨域问题：**

1. cors
2. 配置代理服务器
   1. nginx
   2. vue-cli



### vue-cli 代理

`vue.config.js`

方式一：

这种方式只能配置一个代理，请求了前端存在的资源时，那么请求就不会被转发了，直接返回本地资源

```js
module.exports = {
  pages: {
    ...
  },
  ...
  // 配置代理服务器
  devServer: { 
    proxy: 'http://localhost:5000'
  }
}
```

方式二：

```js
module.exports = {
  pages: {
    ...
  },
  ...
  // 配置代理服务器
  devServer: { 
    proxy: {
      '/api': {
        target: 'http://localhost:5000',
        pathRewrite: {'^/api': ''}, // 重写url，转发时去掉api
        ws: true, // 用于支持 websocket
        changeOrigin: true // 用于控制请求头中的host值
      },
      '/foo': {
        target: 'http://localhost:5001'
      }
    }
  }
}
```



## bootstrap.css





