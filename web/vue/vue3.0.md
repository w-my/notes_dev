# Vue3.0

## 创建 vue3.0 工程

### vue-cli 创建

```sh
// 查看 @vue/cli 版本，确保在 4.5.0 以上
vue --version
// 安装或升级 @vue/cli
npm install -g @vue/cli
// 创建
vue create vue3_test
// 进入启动
cd vue3_test
npm run serve
```



### vite 创建

Vite 新一代的前端开发与构建工具

优势：

	- 开发环境中，无需打包操作，可快速冷启动
	- 轻量化快速热重载
	- 真正的按需编译，不再等待整个应用编译完成

```sh
// 创建工程
npm init vite-app vue3_test_vite
// 进入工程目录
cd vue3_test_vite
// 安装依赖
npm install
// 运行
npm run dev
```



## 工程结构

`main.js`

```js
// 引入的不再是Vue构造函数了，引入的是一个名为createApp的工厂函数
import { createApp } from 'vue'
import App from './App.vue'

createApp(App).mount('#app')
```

`App.vue`

vue3 中可以没有根标签



## 开发者工具





## 响应式原理

### vue2.x

- 实现原理

  - 对象类型：通过 `Object.defineProperty()` 对属性的读取、修改进行拦截（数据劫持）
  - 数组类型：通过重写更新数组的一系列方法实现拦截。（对数组的变更方法进行了包裹）

  ```js
  Object.defineProperty(data, 'count', {
    get() {},
    set() {}
  })
  ```

- 存在问题：

  - 新增属性、删除属性，界面不会更新；
  - 直接通过下标修改数组，界面不会自动更新；
  - 需要 `this.$set()` or `this.$delete()` 触发更新

### vue3.0

- 实现原理
  - 通过 Proxy（代理）：拦截对象中任意属性的变化，包括：属性值的读写、属性的添加、属性的删除等
  - 通过 Reflect（反射）：对被代理对象的属性进行操作
  - MDN 文档中描述的 Proxy 与 Reflect：

```js
new Proxy(data, {
	// 拦截读取属性值
	get(target, prop) {
		return Reflect.get(target, prop)
	},
	// 拦截设置属性值或添加属性
	set(target, prop, value) {
		return Reflect.set(target, prop, value)
	},
	// 拦截删除属性
	deleteProperty(target, prop) {
		return Reflect.deleteProperty(target, prop)
	}
})
```





## Composition API

 ### setup

1. Vue3.0 中一个新的配置项，值为一个函数；

2. 组件中所用到的：数据、方法等等，都要配置在 setup 中；

3. setup 函数有两种返回值：
   1. 返回一个对象，则对象中的属性、方法，在模板中均可直接使用。
   2. 若返回一个渲染函数，则可以自定义渲染内容。
4. 不要与vue2配置混用；
5. setup 不能是 async 函数，应为返回值不再是 return 的对象，而是 promise，模板看不到return对象中的属性。

**两个注意点：**

- setup 执行的时机
  - 在 beforeCreate 之前执行一次，this 是 `undefined`
- setup 的参数
  - props：值为对象，包含：组件外部传递过来，且组件内部申明接收了的属性
  - context：上下文对象
    - attrs：值为对象，包含：组件外部传递过来，但没有在props配置中申明的属性，相当于`this.$attrs`
    - slots：接收的插槽内容，相当于 `this.$slots`
    - emit：分发自定义事件的函数，相当于 `this.$emit`



### ref

作用：定义一个响应式的数据

```vue
<template>
	<div>{{ name }}</div>
	<div>{{ age }}</div>
	<div>{{ job.type }}</div>
	<div>{{ job.salary }}</div>
	<button @click="changeInfo">修改信息</button>
</template>

<script>
	import { ref } from 'vue'
  export default {
    name: 'App',
    setup() {
      // 数据
      let name = ref('zhangsan')
      let age = ref(18)
      let job = ref({
        type: 'web 开发',
        salary: '30k',
      })
      
      // 方法
      function changeInfo() {
        name.value = 'lisi'
        age.value = 20
        job.value.type = 'UI 设计师'
        job.value.salary = '50k'
      }
      
      // 返回一个对象
      return {
        name, age, job, changeInfo 
      }
    }
  }
</script>
```



### reactive

作用：定义一个**对象类型**的响应式数据（基本类型不要用它，要用 `ref` 函数）

内部基于 ES6 的 Proxy 实现，通过代理对象操作源对象内部数据进行操作。

```vue
<template>
	<div>{{ name }}</div>
	<div>{{ age }}</div>
	<div>{{ job.type }}</div>
	<div>{{ job.salary }}</div>
	<button @click="changeInfo">修改信息</button>
</template>

<script>
	import { ref, reactive } from 'vue'
  export default {
    name: 'App',
    setup() {
      // 数据
      let name = ref('zhangsan')
      let age = ref(18)
      let job = reactive({
        type: 'web 开发',
        salary: '30k',
      })
      
      // 方法
      function changeInfo() {
        name.value = 'lisi'
        age.value = 20
        job.type = 'UI 设计师'
        job.salary = '50k'
      }
      
      // 返回一个对象
      return {
        name, age, job, changeInfo 
      }
    }
  }
</script>
```



### 计算属性与监视























