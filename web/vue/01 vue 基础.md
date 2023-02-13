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
    const v = new Vue({
        // el: '#root',
        data: {
            title: 'vue...',
            source: {
                name: "baidu",
                url: "http://www.baidu.com"
            }
        }
    })
    v.$mount('#root')
</script>
```

### data

data 的两种写法

```html
<script type="text/javascript">
    const v = new Vue({
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
    v.$mount('#root')
</script>
```





