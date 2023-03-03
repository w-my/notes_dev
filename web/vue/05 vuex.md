# Vuex

## 搭建 vuex 环境

1. 创建文件：`src/store/index.js`

```js
// 引入 Vue 核心库
import Vue from 'vue'
// 引入 Vuex
import Vuex from 'vuex'

// 应用 Vuex 插件
Vue.use(Vuex)

// 响应组件中用户的动作
const action = {}
// 修改 state 中的数据
const mutations = {}
// 保存具体的数据
const state = {}

// 创建并暴露 store
export default new Vuex.Store({
	action,
	mutations,
	state
})
```

2. 在 `main.js` 中创建 vm 时传入 `store` 配置项

```js
...
// 引入 store
import store from './store'
...

new Vue({
  el: "#app",
  render: h => h(App),
  store
})
```



## 基本使用

1. 初始化数据、配置 `actions` 、配置 `mutations` ，操作文件 `store.js` 

```js
import Vue from 'vue'
import Vuex from 'vuex'

Vue.use(Vuex)

const action = {
	sum(context, value) {
		context.commit('SUM', value)
	}
}

const mutations = {
	SUM(state, value) {
		state.num += value
	}
}

const state = {
	num: 0
}

export default new Vuex.Store({
	action,
	mutations,
	state
})
```

2. 组件中读取 vuex 中的数据：

```js
$store.state.sum
```

3. 组件中修改 vuex 中的数据：

```js
$store.dispatch('action中的方法名', 数据) // $store.dispatch('sum', 1)
// or
$store.commit('mutations中的方法名', 数据) // $store.commit('SUM', 1)
```



## getters 的使用

1. 在 `store.js` 中追加 `getters` 配置

```js
...
const getters = {
  bigNum(state) {
    return state.num * 10
  }
}

export default new Vuex.Store({
  ...
  getters
})
```

2. 在组件中读取

```js
$store.getters.bigNum
```



## map 方法

```js
import {mapState, mapGetters, mapActions, mapMutations} from 'vuex'
```



### mapState

用于映射 `state` 中的数据为计算属性

```js
computed: {
  ...mapState({sum: 'sum', school: 'school'}),
  // or
  ...mapState(['sum', 'school'])
}
```



### mapGetters

用于映射 `getters` 中的数据为计算属性

```js
computed: {
  ...mapGetters({bigSum: 'bigSum'}),
  // or
  ...mapGetters(['bigSum'])
}
```



### mapActions

用于生成 `actions` 对话的方法，即：包含 `$store.dispatch(xxx)` 的函数

```js
methods: {
  ...mapActions({increment: 'sum'})
  // or
  ...mapActions(['sum'])
}
```



### mapMutations

用于生成 `mutations` 对话的方法，即：包含 `$store.commit(xxx)` 的函数

```js
methods: {
  ...mapMutations({increment: 'SUM'})
  // or
  ...mapMutations(['SUM'])
}
```



## vuex 模块化

1. 创建 `count.js`

```js
export default {
	namespaced: true,
	state: { num: 1, total: 0 },
	actions: { ... },
	mutations: { ... },
	getters: { ... }
}
```

2. 创建 `person.js`

```js
export default {
	namespaced: true,
	state: { list: [] },
	actions: { ... },
	mutations: { ... },
	getters: { ... }
}
```

3. 修改 `src/store/index.js`

```js
import Vue from 'vue'
import Vuex from 'vuex'
import countOptions from './count'
import personOptions from './person'

Vue.use(Vuex)

export default new Vuex.Store({
	countAbout: countOptions,
	personAbout: personOptions
})
```

4. 开启命名空间后，组件中读取 state 数据：

```js
this.$store.state.personAbout.list
// or
...mapState('countAbout', ['num', 'total'])
```

5. 开启命名空间后，组件中读取 getters 数据

```js
this.$store.getters['personAbout/firstPersonName']
// or
...mapGetters('countAbout', ['bigNum'])
```

6. 开启命名空间后，组件中调用 dispatch

```js
this.$store.dispatch('personAbout/addPerson', person)
// or
...mapActions('countAbout', {incrementOdd: 'incOdd', incrementWait: 'incWait'})
```

7. 开启命名空间后，组件中调用 commit

```js
this.$store.commit('personAbout/ADD_PERSON', person)
// or
...mapMutations('countAbout', {increment: 'inc', decrement: 'dec'})
```
