## `p` `span` 文本伪类操作

####  `p` `span`

```html
<!DOCTYPE html>
<html lang="en">
<head>
    <style>
        /* 段落第一个字符 */
        p::first-letter {
            color: red;
        }
        /* 段落首行 */
        p::first-line {
            color: yellowgreen;
        }
        span::before {
            content: "\00A9";
            color: goldenrod;
        }
    </style>
</head>
<body>
    <span>欣赏</span>
    <p>古木向人秋，惊蓬掠鬓稠。是重阳、何处堪愁。记得当年惆怅事，正风雨，下南楼。</p>
    <p>断梦几能留，香魂一哭休。怪凉蟾、空满衾禂。霜落鸟啼浑不睡，偏想出，旧风流。</p>
</body>
</html>
```



###### e.g. 自定义 input 功能框

```html
<!DOCTYPE html>
<html lang="en">
<head>
    <style>
        div {
            border: solid 1px #ddd;
            width: 130px;
        }
        div>input[type="text"] {
            border: none;
            outline: none;
            width: 100px;
        }
        div>input[type="text"]+span:after {
            content: "\2934";
            cursor: pointer;
        }
    </style>
</head>
<body>
    <div>
        <input type="text">
        <span></span>
    </div>
</body>
</html>
```

