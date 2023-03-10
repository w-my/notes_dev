# Router



## vue-router 

vue 的一个插件库，专门用来实现 SPA 应用。

> vue-router4 可以在 vue3 中使用，vue-router3 才能在 vue2 中使用

安装：

```sh
npm i vue-router@3
```



## 基础使用

引入：

```sh
import VueRouter from 'vue-router'
```

应用插件：

```sh
Vue.use(VueRouter)
```

配置路由：

`src/router/index.js`

```js
import VueRouter from 'vue-router'
import Home from '../components/pages/Home'
import About from '../components/pages/About'

export default new VueRouter ({
  routes: [
    {
      path: '/home',
      component: Home
    },
    {
      path: '/about',
      component: About
    }
  ]
})
```

`src/main.js`

```js
import Vue from 'vue'
import App from './App.vue'

import VueRouter from 'vue-router'
import router from './router'

Vue.config.productionTip = false

Vue.use(VueRouter)

new Vue({
  render: h => h(App),
  router: router
}).$mount('#app')
```

实现切换：

```html
<router-link active-class="active" to="/home">Home</router-link>
```

指定展示位置：

```html
<router-view></router-view>
```



## 多级路由

多级路由配置，使用 `children` ，`path` 不需要加 `/`

```js
import VueRouter from 'vue-router'
import Home from '../components/pages/Home'
import About from '../components/pages/About'
import News from '../components/pages/News'
import Message from '../components/pages/Message'

export default new VueRouter ({
  routes: [
    {
      path: '/home',
      component: Home
    },
    {
      path: '/about',
      component: About,
      children: [
        {
          path: 'news',
          component: News
        },
        {
          path: 'message',
          component: Message
        }
      ]
    }
  ]
})
```

使用时候需要写全路径 `/about/news`

```html
<router-link active-class="active" to="/about/news">Home</router-link>
```



## 命名路由

简化路由的跳转

```html
<router-link to="/about/message/detail">detail</router-link>
```

变成：

```js
<router-link :to="{name: 'xiangqing'}">detail</router-link>
```



## 路由参数

### query 参数

query 传参字符串写法：

```html
<router-link :to="`/home/message/detail?id=${m.id}&title=${m.title}`">{{ title }}</router-link>
```

query 传参对象写法：

```html
<router-link :to="{
                    path: '/home/message/detail',
                    query: {
                      id: m.id,
                      title: m.title
                    }
                  }">
	{{ title }}
</router-link>
```

接收参数：

```js
$route.query.id
$route.query.title
```



### params 参数

```js
path: 'detail/:id/:title',
```

e.g.

```js
export default new VueRouter ({
  routes: [
    {
      path: '/home',
      component: Home
    },
    {
      path: '/about',
      component: About,
      children: [
        {
          path: 'news',
          component: News
        },
        {
          path: 'message',
          component: Message,
          children: [
            {
              path: 'detail/:id/:title',
	            component: Detail
            }
          ]
        }
      ]
    }
  ]
})
```

传参：

```html
<router-link :to="`/home/message/detail/${m.id}/${m.title}`">{{ title }}</router-link>
```

取值：

```js
$route.params.id
$route.params.title
```

> 路由携带 params 参数时，若使用to对象写法，则不能使用path配置项，必须使用name配置。



## 路由的 props 配置

作用：让路由组件更方便的接收参数

```js
{
  name: 'xiangqing',
  path: 'detail',
  component: Detail,
  // 第一种写法，值为对象，该对象中多有key-value都会以props形式传递，缺点值固定，基本不用
  // props: {id: 1, title: 'hello'}
    
  // 第二种写法，值为bool，若为真，就会把该路由的所有params参数，以props形式传递，缺点不能传query参数
  // props: true
    
  // 第三种写法，值为函数
  props($route) {
    return { id: $route.query.id, title: $route.query.title }
  }
  // 或
  props({ query }) {
    return { id: query.id, title: query.title }
  }
  // 或
  props({ query: {id, title} }) {
    return { id, title }
  }
}
```



## replace 属性

作用：控制路由跳转时操作浏览器历史记录模式

浏览器的历史记录有两种写入方式：`push` 和 `replace` ，push 是追加历史记录，replace 是替换当前记录。默认为 push。

开启 `replace` 模式：`<router-link replace ...></router-link>`



## 编程式路由导航

作用：不借助 `<router-link>` 实现路由跳转，让路由跳转更加灵活

```js
this.$router.push({
  name: 'xiangqing',
  params: {
    id: xxx,
    title: xxx
  }
})
```

```js
this.$router.replace({
  name: 'xiangqing',
  params: {
    id: xxx,
    title: xxx
  }
})
```

```js
this.$router.forward()
this.$router.back()
this.$router.go(-2) // 后退两步
this.$router.go(1) // 前进一步
```



## 缓存路由组件

作用：让不展示的路由组件保持挂载，不被销毁。

```html
<keep-alive> // 不设置 include ，缓存全部子组件
	<router-view></router-view>
</keep-alive>
```

```html
<keep-alive include="News">
	<router-view></router-view>
</keep-alive>
```

```html
<keep-alive :include="['News', 'Message']">
	<router-view></router-view>
</keep-alive>
```

`include` 值为组件的 `name` 值。



## 路由守卫

作用：对路由进行权限控制



### 全局守卫

```js
const router = new VueRouter ({
  routes: [
    {
      path: '/home',
      component: Home,
      meta: {title: '主页'}
    },
    {
      path: '/about',
      component: About,
      meta: {title: '关于'},
      children: [
        {
          path: 'news',
          component: News,
          meta: {title: '新闻'}
        },
        {
          path: 'message',
          component: Message,
          meta: {isAuth: true, title: '消息'}
        }
      ]
    }
  ]
})
// 全局前置守卫，初始化时执行、每次路由切换前执行
router.beforeEach((to, from, next) => {
  if (to.meta.isAuth && !localStorage.getItem('school') === 'qinghua') {
    alert('非清华学校，无权查看');
  } else {
    next()
  }
})
// 全局后置守卫，初始化时执行、每次路由切换后执行
router.afterEach((to, from) => {
  document.title = to.meta.title || '学校系统'
})

export default router;
```



### 独享路由守卫

beforeEnter

```js
export default new VueRouter ({
  routes: [
    {
      path: '/home',
      component: Home,
      meta: {isAuth: true},
      beforeEnter(to, from, next) {
        if (to.meta.isAuth && !localStorage.getItem('school') === 'qinghua') {
          alert('无权查看');
        } else {
          next()
        }
      }
    },
    {
      path: '/about',
      component: About,
    }
  ]
})
```



### 组件内路由守卫

```vue
// 进入守卫，通过路由规则，进入该组件时被调用
beforeRouteEnter(to, from, next) {

},
// 离开守卫，通过路由规则，离开该组件时被调用
beforeRouteLeave(to, from, next) {

}
```



## 路由器的两种工作模式

### mode

- hash --- 默认模式
- history

```js
export default new VueRouter ({
  mode: 'history'
  routes: [
    {
      path: '/home',
      component: Home
    },
    {
      path: '/about',
      component: About
    }
  ]
})
```

1. 对于一个 url 来说，什么是 hash 值？ --- #及其后面的内容就是 hash 值。
2. hash值不回包含在 HTTP 请求中，即：hash 值不会带给服务器。
3. hash 模式：
   1. 地址中永远带着#号，不美观；
   2. 若以后将地址通过第三方手机app分享，若app校验严格，则地址会被标记为不合法；
   3. 兼容性较好。
4. history 模式：
   1. 地址干净，美观；
   2. 兼容性和 hash 模式相比略差；
   3. 应用部署上线时需要后端人员支持，解决刷新页面服务端 404 的问题。

> 一般使用 history 模式，通过后端技术识别hash部分并忽略

### nods 解决刷新 404

使用三方库 `connect-history-api-fallback`

```sh
npm i connect-history-api-fallback
```

`server.js`

```js
const express = require('express')
const history = require('connect-history-api-fallback')

const app = express()
app.use(history())
app.use(express.static(__dirname + '/static'))

app.listen(5000, (err) => {
  if(!err) console.log('服务器启动成功了！')
})
```





