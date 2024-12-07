# Vue3.0

[从入门到精通：Vue3一篇文章搞定](https://blog.csdn.net/2302_76329106/article/details/139447910)





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
5. setup 不能是 async 函数，应为返回值不再是 return 的对象，而是 promise，模板看不到return对象中的属性。（可以返回一个Promise实例，但需要Suspense和异步组件的配合）

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

#### computed

```js
<script>
  import { computed } from 'vue';

  export default {
    name: 'HelloWorld',
    setup() {
      ...
      // let fullName = computed(() => {
      //   return person.firstName + '-' + person.lastName
      // })
      let fullName = computed({
        get() {
          return person.firstName + '-' + person.lastName
        },
        set(value) {
          const nameArr = value.split('-')
          person.firstName = nameArr[0]
          person.lastName = nameArr[1]
        }
      })
      ...
    }
  }
</script>
```



#### watch

两个小坑：

1. 监视 reactive 定义的响应式数据时：oldValue 无法正确获取、强制开启了深度监视（depp配置失效）
2. 监视 reactive 定义的响应式数据某个属性时：deep配置有效

```js
// 监视ref定义的响应式数据
wtach(sum, (newValue, oldValue) => {
  console.log('sum变化了', newValue, oldValue);
},{immediate: true})
// 监视多个ref定义的响应式数据
watch([sum, msg], (newValue, oldValue) => {
  console.log('sum或msg变化了');
})
// 监视reactive定义的响应式数据
//    若watch监视的是reactive定义的响应式数据，则无法正确获得oldValue
//    若watch监视的是reactive定义的响应式数据，则强制开启了深度监视
watch(person, (newValue, oldValue) => {
  console.log('person变化了');
}, {immediate: true, deep: false}) // 此处的deep配置不奏效
// 监视reactive定义的响应式数组中的某个属性
watch(() => person.job, (newValue, oldValue) => {
  console.log('person的job变化了');
}, {immediate: true, deep: true})
// 监视reactive所定义的一个响应式数据中的某些属性
watch([()=>person.name, ()=>person.age], (newValue, oldValue) => {
  console.log('person的name或age变化了'); 
})
// 特俗情况
watch(()=>person.job, (newValue, oldValue) => {
  console.log('person的name或age变化了');
}, {deep: true}) // 此处由于监视的是reactive所定义的对象中的某个属性，所以deep配置有效
```



#### watchEffect

- 不用指明监视哪个属性，监视回调中用到哪个属性，就监视哪个属性。

- 有点像computed：
  - 但 computed 注重计算出来的值，所以必须要写返回值；
  - 而 watchEffect 更注重过程，不需要返回值。

```vue
// watchEffect所指定的回调中用到的数据只要发生变化，则直接重新执行回调
watchEffect(() => {
	const x1 = sum.value
	const x2 = person.age
	console.log('watchEffect配置的回调函数执行了')
})
```



## 生命周期

- `beforeCreate` ==> `setup()`
- `created` ==> `setup()`
- `beforeMount` ==> `onBeforeMount()`
- `mounted` ==> `onMounted`
- `beforeUpdate` ==> `onBeforeUpdate`
- `updated` ==> `onUpdated`
- `beforeUnmount` ==> `onBeforeUnmount`
- `unmounted` ==> `onUnmounted`

e.g.

```vue
setup() {
	// 通过组合式API形式使用生命周期钩子
	onMounted(() => {

	})
},
mounted() {
	// 配置项使用生命周期周期钩子
},
```



## hook函数

- 本质是一个函数，把setup函数中使用的 Composition API 进行了封装。

- 类似于 vue2.x 中的 mixin。

- 自定义 hook 的优势：复用代码，让 setup 中的逻辑更清晰易懂。

e.g.

`src/hooks/usePoint.js`

```js
import { reactive, onMounted, onBeforeUnmount } from 'vue'
export default function() {
	let point = reactive({
		x: 0,
		y: 0
	})

	function savePoint(event) {
		point.x = event.pageX
		point.y = event.pageY
	}

	onMounted(() => {
		window.addEventListener('click', savePoint)
	})

	onBeforeUnmount(() => {
		window.removeEventListener('click', savePoint)
	})

	return point
}
```

`src/components/Demo.vue`

```vue
<script>
	import usePoint from '../hooks/usePoint'
	export default {
		name 'Demo',
		setup() {
			let point = usePoint()
			return { point }
		}
	}
</script>
```



## toRef

- 作用：创建一个 ref 对象，其 value 值指向另一个对象中的某个属性；
- 语法：`const name = toRef(person, 'name')`
- 应用：要将响应式对象中的某个属性单独提供给外部使用时；
- 扩展：`toRefs` 与 `toRef` 功能一致，但可以批量创建多个 ref 对象，语法：`toRefs(peson)`

e.g.

```vue
<div>{{ name }}</div>
<div>{{ age }}</div>
<div>{{ job.salary }}</div>
...
setup() {
	let person = reactive({
		name: '',
		age: 18,
		job: {
			salary: 20
		}
	})

	return {
		person,
		name: toRef(person, 'name'),
		...toRefs(person)
	}
}
```



## 其他 Composition API

### shallowReactive 与 shallowRef

- shallowReactive ：只处理对象最外层属性的响应式（浅响应式）
- shallowRef ：只处理基本数据类型的响应式，不进行对象的响应式处理



### readonly 与 shallowReadonly

- readonly：让一个响应式数据变为只读（深只读）
- shallowReadonly：让一个响应式数据变为只读（浅只读）



### toRaw 与 markRaw

- toRaw:
  - 作用：将一个由 `reactive` 生成的**响应式对象**转为**普通对象**
- markRaw：
  - 作用：标记一个对象，使其永远不会再成为响应式对象
  - 应用场景：
    - 有些值不应该被设置为响应式的，例如复杂的三方库
    - 当渲染具有不可变数据的大列表时，跳过响应式转换可以提高性能



### customRef

作用：创建一个自定义的 ref， 并对其依赖跟踪和更新触发进行显示控制。

e.g. 实现防抖效果

```vue
<template>
	<input type="text" v-model="keyword">
	<h3>{{ keyword }}</h3>
</template>
<script>
	import {ref, customRef} from 'vue'
  export default {
    name 'Demo',
    setup() {
      function myRef(value, delay) {
        let timer
        
        return customRef((track, trigger) => {
          return {
            get() {
              track() // 告知Vue追踪value的变化
              return value
            },
            set(newValue) {
              clearTimeout(timer)
              timer = setTimeout(() => {
                value = newValue
              	trigger() // 告知Vue去重新解析模版
              }, delay)
            }
          }
        })
      }
      
      let keyword = myRef('hello', 500)
      
      return { keyword }
    }
  }
</script>
```



 ### provide 与 inject

作用：实现祖孙组件间的通信

套路：父组件有一个 `provide` 选项来提供数据，后代组件有一个 `inject` 选项来开始使用这些数据

用法：

`祖组件` 

```vue
import { reactive, provide } from 'vue'
...
setup() {
	...
	let car = reactive({ name: '', price: '' })
	provide('car', car)
	...
}
```

`后代组件`

```vue
import { inject } from 'vue'
...
setup(props, context) {
	...
	const car = inject('car')
	return { car }
}
```



### 响应式数据的判断

- isRef ：检查一个值是否为一个 `ref` 对象
- isReactive ：检查一个对象是否由 `reactive` 创建的响应代理
- isReadonly ：检查一个对象是否由 `reactive` 创建的只读代理
- isProxy ：检查一个对象是否由 `reactive` 或 `readonly` 创建的代理



## Composition API 的优势

### Options API 存在的问题

使用传统 OptionsAPI 中，新增或者修改一个需求，就需要分别在 data, methods, computed 里修改。



### Composition API 的优势

可以更加优雅的组织我们的代码，函数，让相关功能的代码更加有序的组织在一起。



## 新组件

### Fragment

在Vue2中，组件必须有一个根标签

在Vue3中，组件可以没有根标签，内部会将多个标签包含在一个Fragment虚拟元素中



### Teleport

是一个能够将 **组件html结构** 移动到指定位置的技术

```vue
<!-- 位置可以例如是 body or #Demo -->
<teleport to="移动到的位置">
	<div v-if="isShow" class="mask">
    <div class="dialog">
      <h3>这是一个弹窗</h3>
      <button @click="isShow = false">关闭弹窗</button>
    </div>
  </div>
</teleport>
```



### Suspense

等待异步组件时渲染一些额外内容，让应用有更好的用户体验

使用：

1. 异步引入组件

```vue
import {defineAsyncComponent} from 'vue'
const Child = defineAsyncComponent(() => import('./components/Child.vue'))
```

2. 使用 `Suspense` 包裹组件，并配置好 `default` 与 `fallback`

```vue
<template>
	<div class="app">
    <h3>这是App组件</h3>
    <Suspense>
  		<template v-slot:default>
        <Child/>
			</template>
			<template v-slot:fallback>
				<h3>加载中...</h3>
			</template>
  	</Suspense>
  </div>
</template>
```



## 其他

### 全局API的转移

- Vue2.x 有许多全局API配置

  - 例如：注册全局组件、注册全局指令等

    ```vue
    Vue.component('MyButton', {
    	data: () => ({
    
    	}),
    	template: '<button @click="count++">Clicked {{ count }} times.</button>'
    })
    ```

- Vue3.0对这些API做出来调整：

  - 将全局API，即 `Vue.xxx` 调整到应用实例（`app`）上

  | 2.x 全局API（Vue）       | 3.x 实例API（app）          |
  | ------------------------ | --------------------------- |
  | Vue.config.xxx           | app.config.xxx              |
  | Vue.config.productionTip | 移除                        |
  | Vue.component            | app.component               |
  | Vue.directive            | app.directive               |
  | Vue.mixin                | app.mixin                   |
  | Vue.use                  | app.use                     |
  | Vue.prototype            | app.config.globalProperties |



### 其他改变

- data 选项应该被申明为一个函数

- 过度累名的修改：

  - Vue2.x 写法

  ```vue
  .v-enter,
  .v-leave-to {
  	opacity: 0;
  }
  .v-leave,
  .v-enter-to {
  	opacity: 1;
  }
  ```

  - Vue3.x 写法

  ```vue
  .v-enter-from,
  .v-leave-to {
  	opacity: 0;
  }
  .v-leave-from,
  .v-enter-to {
  	opacity: 1;
  }
  ```

- 移除 keyCode 作为 v-on 的修饰符，同时也不再支持 `config.keyCodes`

- 移除 `v-on.native` 修饰符

  - 父组件中绑定事件

  ```vue
  <my-component 
  	v-on:close="handleComponentEvent"
    v-on:click="handleNativeClickEvent"
  />
  ```

  - 子组件中声明自定义事件

  ```vue
  <script>
  	export default {
      emits: ['close']
    }
  </script>
  ```

- 移除过滤器（filler）
