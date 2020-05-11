## `form` 表单样式



```html
<!DOCTYPE html>
<html lang="en">
<head>
    <style>
        /* !important 强制优先级 */
        input:disabled {
            border: solid 1px #ddd !important;
        }
        input:enabled {
            background-color: #eee;
        }
        /* 选中紧挨着的 `label` */
        input:checked+label {
            color: red;
        }
        /* 去掉外边线 */
        input {
            outline: none;
        }
        /* 非必填 */
        input:optional {
            border: solid 1px green;
        }
        /* 必填 */
        input:required {
            border: solid 1px red;
        }
        /* 内容有效的 */
        input:valid {
            background-color: blanchedalmond;
        }
        /* 内容无效的 */
        input:invalid {
            background-color: blueviolet;
        }
    </style>
</head>
<body>
    <form action="">
        <input type="text" disabled>
        <input type="text">
        <hr>
        <input type="radio" name="sex" id="boy">
        <label for="boy">男</label>
        <input type="radio" name="sex" id="girl" checked>
        <label for="girl">女</label>
        <hr>
        <input type="text" required>
        <button>保存</button>
    </form>
</body>
</html>
```

