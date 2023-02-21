[TOC]



# Vue 核心



## 数据

### 数据绑定

#### v-bind:

单向数据绑定，`v-bind:` 可以简写成 `:`

#### v-mode:

双向数据绑定，`v-model:value` 可以简写成 `v-model`

```html
<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
    <script type="text/javascript" src="../js/vue.js"></script>
</head>

<body>
    <div id="root">
        <h1>{{ title }}</h1>
        <a :href="source.url.toUpperCase()">点击 {{ source.name }} 跳转</a>
        <input type="text" v-model="source.name">
    </div>

    <script type="text/javascript">
        Vue.config.productionTip = false

        new Vue({
            el: '#root',
            data: {
                title: 'hello vue.',
                source: {
                    name: "baidu",
                    url: "http://www.baidu.com"
                }
            }
        })
    </script>
</body>

</html>
```

### el 

el 的两种写法

```html
<script type="text/javascript">
    const vm = new Vue({
        // el: '#root',
        data: {
            title: 'vue...',
            source: {
                name: "baidu",
                url: "http://www.baidu.com"
            }
        }
    })
    vm.$mount('#root')
</script>
```

### data

data 的两种写法

```html
<script type="text/javascript">
    const vm = new Vue({
        // el: '#root',
        // data: {
        //     title: 'vue...',
        //     source: {
        //         name: "baidu",
        //         url: "http://www.baidu.com"
        //     }
        // }
        data() {
            return {
                title: 'vue...',
                source: {
                    name: "baidu",
                    url: "http://www.baidu.com"
                }
            }
        }
    })
    vm.$mount('#root')
</script>
```



### Object.defineProperty

```html
<body>
    <script type="text/javascript">
        let number = 18
        let person = {
            name: '张三',
            sex: '男'
        }
        Object.defineProperty(person, 'age', {
            // value: 18,
            // enumerable: true, // 控制属性是否可枚举
            // writable: true, // 控制属性是否可被修改
            // configurable: true, // 控制属性是否可被删除

            // 动态获取 age 属性的值
            get() {
                return number 
            },
            set(value) {
                number = value
            }
        })
    </script>
</body>
```



### 数据代理

数据代理：通过一个对象代理对另一个对象中属性的操作（读/写）

```html
<body>
    <script type="text/javascript">
        let obj = {x: 100}
        let obj2 = {y: 200}
        Object.defineProperty(obj2, 'x', {
            get() {
                return obj.x
            },
            set(value) {
                obj.x = value
            }
        })
    </script>
</body>
```



## 事件

### @click

使用 `v-on:xxx` 或 `@xxx` 绑定事件，其中 `xxx` 是事件名；

事件中的 `this` 是 `vm`；

```html
<body>
    <div id="root">
        <div>欢迎来到 {{ name }}</div>
        <button v-on:click="showInfo1">不传参</button>
        <button @click="showInfo2($event, 123)">传参</button>
    </div>
    <script type="text/javascript">
        const vm = new Vue({
            el: '#root',
            data: {
                name: 'lalall'
            },
            methods: {
                showInfo1(event) {
                    console.log(this === vm); // true
                    console.log(event.target); // <button>不传参</button>
                    console.log(event.target.innerText); // 不传参
                },
                showInfo2(event, num) {
                    console.log(event.target.innerText, num) // 传参 123
                }
            }
        })
    </script>
</body>
```



### 事件修饰符

- prevent：阻止默认事件（常用）
- stop：阻止事件冒泡（常用）
- once：事件只发生一次（常用）
- capture：使用事件的捕获模式
- self：是有 event.target 是当前操作的元素时才触发事件
- passive：事件的默认行为立即执行，无需等待事件回调执行完毕

```html
<body>
    <div id="root">
        <a href="http://www.baidu.com" @click.prevent="showInfo">点我提示信息</a>
    </div>
    <script type="text/javascript">
        const vm = new Vue({
            el: '#root',
            methods: {
                showInfo(e) {
                    console.log(e);
                }
            }
        })
    </script>
</body>
```



### 键盘事件

- Vue 中常用的按键别名：
  - 回车 => enter
  - 删除 => delete（捕获“删除”和“退格”键）
  - 退出 => esc
  - 空格 => space
  - 换行 => tab
  - 上 => up
  - 下 => down
  - 左 => left
  - 右 => right
- Vue 未提示别名的按键，可以使用按键原始的 key 值去绑定，但注意要转为 kebab-case（短横线命名）
- 系统修饰键（用法特殊）：ctrl、alt、shift、meta
  - 配合 keyup 使用：按下修饰键的同时，在按下其他键，随后释放其他键，事件才被触发
  - 配合 keydown 使用：正常触发事件
- 也可以使用 keyCode 去指定具体的按键（不推荐）
- Vue.config.keyCodes.自定义键名 = 键码，可以去定制按键别名

```html
<body>
    <div id="root">
        <input type="text" placeholder="按下回车提示输入" @keydown.huiche="showInfo">
    </div>
    <script type="text/javascript">
        Vue.config.keyCodes.huiche = 13 // 定义了一个别名按键
        
        const vm = new Vue({
            el: '#root',
            data: {
                name: 'lalall'
            },
            methods: {
                showInfo(e) {
                    console.log(e);
                }
            }
        })
    </script>
</body>
```



## 属性

### computed

```html
<body>
    <div id="root">
        姓：<input type="tex" v-model="firstName"> <br/>
        名：<input type="tex" v-model="lastName"> <br/>
        全名：<span>{{ fullName }}</span>
    </div>
    <script type="text/javascript">
        const vm = new Vue({
            el: '#root',
            data: {
                firstName: '',
                lastName: ''
            },
            computed: {
                fullName() {
                    return this.firstName + '-' + this.lastName
                }
            }
        })
    </script>
</body>
```



### watch

当被监视的属性变化时，回调函数自动调用，进行相关操作

监视方法一：

```html
<script type="text/javascript">
    const vm = new Vue({
        el: '#root',
        data: {
            isHot: true
        },
        watch: {
            // isHot: {
            //     handler(newValue, oldValue) {
            //         console.log('isHot 被修改了');
            //     }
            // }
          	isHot(newValue, oldValue) {
                console.log('isHot 被修改了', newValue, oldValue);
            }
        }
    })
</script>
```

监视方法二：

```html
<script type="text/javascript">
    const vm = new Vue({
        el: '#root',
        data: {
            isHot: true
        }
    })
    // vm.$watch('isHot', {
    //     handler(newValue, oldValue) {
    //         console.log('isHot 被修改了');
    //     }
    // })
	  vm.$watch('isHot', function(newValue, oldValue) {
        console.log('isHot 被修改了', newValue, oldValue);
    })
</script>
```

#### immediate

初始化时让 handler 调用一下

```html
<script type="text/javascript">
    const vm = new Vue({
        el: '#root',
        data: {
            isHot: true
        },
        watch: {
            isHot: {
                immediate: true, // 初始化时让 handler 调用一下
                handler(newValue, oldValue) {
                    console.log('isHot 被修改了');
                }
            }
        }
    })
</script>
```

#### deep

深度监视，监视多级结构中所有属性的变化

```html
<script type="text/javascript">
    const vm = new Vue({
        el: '#root',
        data: {
            numbers: {
              a: 1,
              b: 2
            }
        },
        watch: {
        		numbers: {
				        deep: true, // 监视多级结构中所有属性的变化
        				handler() {
				            console.log('numbers 被修改了');
        				}
				    }
        }
    })
</script>
```



## 样式

### class

```html
<body>
    <div id="root">
        <div class="basic" :class="dynamic" @click="changeClass">字符串方式绑定class样式</div>
        <div class="basic" :class="classArr" @click="changeClass">数组方式绑定class样式</div>
        <div class="basic" :class="classObj" @click="changeClass">对象方式绑定class样式</div>
    </div>
    <script type="text/javascript">
        const vm = new Vue({
            el: '#root',
            data: {
                dynamic: 'bggreen',
                classArr: ['style1', 'style2'],
                classObj: {
                    style1: false,
                    style2: true
                }
            },
            methods: {
                changeClass() {
                    this.dynamic = 'bgblue'
                }
            },
        })
    </script>
</body>
```

### style

```html
<body>
    <div id="root">
        <div class="basic" :style="styleObj">绑定style样式</div>
    </div>
    <script type="text/javascript">
        const vm = new Vue({
            el: '#root',
            data: {
                styleObj: {
                    fontSize: '30px',
                    color: 'red',
                    backgroundColor: 'orange'
                }
            }
        })
    </script>
</body>
```



## 条件渲染

### v-show

适用：切换频率较高的场景；

特点：不展示的DOM元素未被移除，仅仅是样式隐藏



### v-if

- v-if

- v-else-if

- v-else

适用：切换频率较低的场景；

特点：不展示的DOM元素直接被移除；

注意：v-if 和 v-else-if、v-else 一起使用时要求结构不能被"打断"

> `<template>` 只能与 `v-if` 使用，不能搭配 `v-show` 使用



## 列表渲染

### v-for



e.g.

```html
<body>
    <div id="root">
        <!-- 遍历数组 -->
        <ul>
            <li v-for="p in persons" :key="p.id">
                {{p.name}} - {{p.age}}
            </li>
        </ul>
        <!-- 遍历对象 -->
        <ul>
            <li v-for="(value, key) in car" :key="key">
                {{key}}: {{value}}
            </li>
        </ul>
        <!-- 遍历字符串 -->
        <ul>
            <li v-for="(char, idx) in str" :key="idx">
                {{idx}}: {{char}}
            </li>
        </ul>
        <!-- 遍历次数 -->
        <ul>
            <li v-for="(num, idx) of 5" :key="idx">
                {{idx}}: {{num}}
            </li>
        </ul>
    </div>
    <script type="text/javascript">
        const vm = new Vue({
            el: '#root',
            data: {
                persons: [
                    {id: '01', name: 'name1', age: 10},
                    {id: '02', name: 'name2', age: 18},
                    {id: '03 ', name: 'name3', age: 12}
                ],
                car: {
                    name: 'bm',
                    color: 'black'
                },
                str: 'hello'
            }
        })
    </script>
</body>
```



## 监视数据

### Vue.set()

向响应式对象中添加一个 property，并确保这个新的 property 同样是响应式的，并触发视图更新

```html
<script type="text/javascript">
    const vm = new Vue({
        el: '#root',
        data: {
            obj: {
                name: 'aaa'
            }
        },
        methods: {
            addColor() {
                this.$set('this.obj', 'color', 'red')
            }
        },

    })
</script>
```

### 数组

Vue 将被侦听的数组的变更方法进行了包裹，通过以下方法可以触发视图更新

- push()
- pop()
- shift()
- unshift()
- splice()
- sort()
- reverse()
- Vue.set()
- vm.$set()  e.g.：this.$set(this.arr, 0, 'obj')



## 表单数据收集

### v-model

- trim
- number
- lazy

### radio

需要设置 value 值

### checkbox

需要设置 value 值，同时收集属性需要是 Array

### @submit

通过 @submit 指定自定义方法

通过 .prevent 阻止提交后，默认执行的刷新和跳转



e.g.

```html
<body>
    <div id="root">
        <form @submit.prevent="submit">
            账号：<input type="text" v-model.trim="userInfo.account"> <br/><br/>
            密码：<input type="password" v-model="userInfo.password"> <br/><br/>
            年龄：<input type="number" v-model.number="userInfo.age"> <br/><br/>
            性别：
            男<input type="radio" v-model="userInfo.sex" value="male">
            女<input type="radio" v-model="userInfo.sex" value="female"> <br/><br/>
            爱好：
            学习<input type="checkbox" v-model="userInfo.hobby" value="study">
            打游戏<input type="checkbox" v-model="userInfo.hobby" value="game">
            吃饭<input type="checkbox" v-model="userInfo.hobby" value="eat"> <br/><br/>
            所属校区：
            <select v-model="userInfo.city">
                <option>请选择校区</option>
                <option>北京</option>
                <option>上海</option>
                <option>深圳</option>
            </select> <br/><br/>
            其他信息：<textarea v-model.lazy="userInfo.other"></textarea> <br/><br/>
            <input type="checkbox" v-model="userInfo.agree">勾选表示同意<a href="http://baidu.com">《用户协议》</a> <br/><br/>
            <button>提交</button>
        </form>
    </div>
    <script type="text/javascript">
        new Vue({
            el: '#root',
            data: {
                userInfo: {
                    account: '',
                    password: '',
                    age: '',
                    sex: 'male',
                    hobby: [],
                    city: '',
                    other: '',
                    agree: false
                }
            },
            methods: {
                submit() {
                    console.log(JSON.stringify(this.userInfo));
                }
            },
        })
    </script>
</body>
```



## 过滤器

### filters

可以在 `插值语法` 和 `v-bind` 中使用

e.g.

```html
<body>
    <div id="root">
        <!-- 计算属性实现 -->
        <div v-model="fmtTime">当前时间：{{ fmtTime }}</div>
        <!-- 过滤器实现 -->
        <div v-model="fmtTime">当前时间：{{ time | timeFormater }}</div>
        <!-- 过滤器传参 -->
        <div v-model="fmtTime">当前时间：{{ time | timeFormater('YYYY_MM_DD') }}</div>
        <!-- 过滤器串联  -->
        <div v-model="fmtTime">当前时间：{{ time | timeFormater('YYYY_MM_DD') | mySlice }}</div>
    </div>
    <script type="text/javascript">
        Vue.filter('mySlice', function(val) {
            return val.slice(0, 4)
        })
        new Vue({
            el: '#root',
            data: {
                time: '1676520323438'
            },
            computed: {
                fmtTime() {
                    return dayjs(this.time).format('YYYY-MM-DD HH:mm:ss')
                }
            },
            filters: {
                timeFormater(val, str = 'YYYY-MM-DD HH:mm:ss') {
                    return dayjs(val).format(str)
                }
            }
        })
    </script>
</body>
```



## 指令

### v-text

向指定节点中渲染文本内容



### v-html

向指定节点中渲染包含html结构的内容，可以识别 html 结构，所以存在安全性问题，不能用在用户提交的内容上。



### v-cloak

本质是一个特殊的属性， Vue 实例创建完成并接管容器后，会删掉 v-cloak 属性。

使用 css 配合 v-cloak 可以解决网速慢时页面展示出 {{ xxx }} 的问题。

```html
<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
    <style>
        [v-cloak] {
            display: none;
        }
    </style>
</head>

<body>
    <div id="root">
        <div v-cloak>{{ text }}</div>
    </div>
    <script type="text/javascript" src="../js/vue.js"></script>
</body>
<script type="text/javascript">
    new Vue({
        el: '#root',
        data: {
            text: 'abcdef'
        },
        
    })
</script>
</html>
```



### v-once

所在节点在初次动态渲染后，就视为静态内容了。

以后数据的改变不回引起结构的更新，可用于优化性能。



### v-pre

跳过其所在节点的编译过程。可以跳过没有使用指令语法、插值语法的节点，加快编译。



### 自定义指令

### directives 

```html
<body>
    <div id="root">
        <div>当前原始值是：<span v-text="num"></span></div>
        <div>放大10被后的值是在：<span v-big="num"></span></div>
        <button @click="num++">点击num+1</button>
        <input type="text" v-fbind:value="num">
    </div>

</body>
<script type="text/javascript">
    // 写法三：
    // 全局自定义指令
    // Vue.directive('fbind', {
    //     // 指令与元素成功绑定时
    //     bind(element, binding) {
    //         element.value = binding.value
    //     },
    //     // 指令所在元素被插入页面时
    //     inserted(element, binding) {
    //         element.focus()
    //     },
    //     // 指令所在的模版被重新解析时
    //     update(element, binding) {
    //         element.value = binding.value
    //     }
    // })
    new Vue({
        el: '#root',
        data: {
            num: 1
        },
        directives: {
            // 写法一：
            // big函数调用时机：1.指令与元素成功绑定时；2.指令所在的模板被重新解析时
            big(element, binding) {
                element.innerText = binding.value * 10
            },
            // 写法二：
            fbind: {
                // 指令与元素成功绑定时
                bind(element, binding) {
                    element.value = binding.value
                },
                // 指令所在元素被插入页面时
                inserted(element, binding) {
                    element.focus()
                },
                // 指令所在的模版被重新解析时
                update(element, binding) {
                    element.value = binding.value
                }
            }
        }
    })
</script>
```



## 配置项

### ref 属性

1. 被用来给元素或自组件组册引用信息（id的替代者）

2. 应用在html标签上获取的是真实DOM元素，应用在组件标签上是组件实例对象（vc）

3. 使用方式：

   打标识：

   ```html
   <h1 ref="xxx">......</h1>
   <!-- 或 -->
   <School ref="xxx"></School>
   ```

   获取：

   ```js
   this.$refs.xxx
   ```

   

### props 配置

让组件接收外部传过来的数据

1. 传递数据

```html
<Demo name="xxx" />
```

2. 接收数据

```js
props: {
  name: {
    type: String, // 类型
    required: true, // 是否必填
    default: 'lalala' // 默认值
  }
}
```

props 是只读的，Vue 底层会检测对 props 的修改，如果修改了会发出警告。

若需要修改，需要在 data 中定义新属性接收传进来的值，然后去修改 data 的数据。



### mixin（混入）

可以把多个组件共用的配置提取成一个混入对象

使用方式：

1. 定义混合：

```js
{
  data() {...},
  methods: {...}
  ...
}
```

`mixin.js`

```js
export const mixin = {
  methods: {
    showName() {
      alert(this.name)
    }
  }
}
```

2. 使用混入：

```js
// 导入
import { mixin } from '../mixin'

// 全局混入：
Vue.mixin(xxx)
// 局部混入：
mixins: ['xxx', 'xxx2']
```



## plugins（插件）

功能：用于增强Vue

本质：包含install方法的一个对象，install的第一个参数是Vue，第二个以后的参数是插件使用者传递的数据。	

`plugins.js`

```js
export default {
  install(Vue) {
    // 全局过滤器
    Vue.filter('mySlice', function(value){
      return value.slice(0, 4)
    })
    // 全局指令
    Vue.directive('fbind', {
      // ...
    })
    // 全局混入
    Vue.mixin({
      // ...
    })
    // 给Vue原型上添加方法（vm和vc就都能用了）
    Vue.prototype.hello = ()=>{ alert('你好!!') }
  }
}
```



## scoped 样式

用作：让样式在局部生效，防止冲突。

写法：

```style
<style scoped>

</style>
```



## 生命周期

- `beforeCreate`：将要创建
- `created`：创建完毕
- `beforeMount`：将要挂载
- **`mounted`**：挂载完毕
- `beforeUpdate`：将要更新
- `updated`：更新完毕
- **`beforeDestroy`**：将要销毁
- `destroyed`：销毁完毕



