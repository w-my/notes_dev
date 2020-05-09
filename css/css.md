



#### 样式引用

###### 使用 `link` 引入

`a.css`

```css
body {
    background-color: #ff0000;
}
```

`a.html`

```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
    <link rel="stylesheet" href="a.css" type="text/css">
</head>
<body>

</body>
</html>
```

###### 使用行内样式

```html
<h1 style="font-size: 12px;"></h1>
```



#### 样式组件引入样式

`menus.css`

```css
p {
    color: #00ff00;
}
```

`a.css`

```css
@import url("../common/menus.css");

body {
    background-color: #fefefe;
}
```

`a.html `

```css
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
    <link rel="stylesheet" href="a.css">
</head>
<body>
    <h1 style="font-size: 12px;">这是一个标题</h1>
    <p>这是一段内容</p>
</body>
</html>
```

