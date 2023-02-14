# Vue 基础



## 语法

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



## Object.defineProperty

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



## 数据代理

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



## 事件处理

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



## 事件修饰符

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



## 键盘事件

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











