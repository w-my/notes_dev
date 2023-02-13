# Vue 基础

## 值绑定

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
        <a :href="source.url">点击 {{ source.name }} 跳转</a>
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

