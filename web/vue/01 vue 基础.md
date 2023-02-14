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

