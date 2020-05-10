## 选择器



#### 结构选择器

`main` 下的 `article` 下的所有 `h2` 都有效

```html
<!DOCTYPE html>
<html lang="en">
<head>
    <style>
        main article h2 {
            color: red;
        }
    </style>
</head>
<body>
    <main>
        <article>
            <h1></h1>
            <aside>
                <h2>h2-01</h2>
            </aside>
            <h2>h2-02</h2>
        </article>
    </main>
</body>
</html>
```

`main` 下的 `article` 下的所有 `h2` ，同时 `article` 下的 `h1` 都为红色

```html
<!DOCTYPE html>
<html lang="en">
<head>
    <style>
        main article h2,
      	article h1 {
            color: red;
        }
    </style>
</head>
<body>
    <main>
        <article>
            <h1>h1</h1>
            <aside>
                <h2>h2-01</h2>
            </aside>
            <h2>h2-02</h2>
        </article>
    </main>
</body>
</html>
```

`main` 下的 `article` 下的直接子 `h2` 有效，也就是 `h2-02` 为红色

```html
<!DOCTYPE html>
<html lang="en">
<head>
    <style>
        main article>h2 {
            color: red;
        }
    </style>
</head>
<body>
    <main>
        <article>
            <h1>h1</h1>
            <aside>
                <h2>h2-01</h2>
            </aside>
            <h2>h2-02</h2>
        </article>
    </main>
</body>
</html>
```

`article` 下的 `h1` 之后的同级 `h2` 有效，也就是 `h2-00` 和 `h2-02` 为红色

```html
<!DOCTYPE html>
<html lang="en">
<head>
    <style>
        article h1+h2 {
            color: red;
        }
    </style>
</head>
<body>
    <main>
        <article>
            <h1>h1</h1>
          	<h2>h2-00</h2>
            <aside>
                <h2>h2-01</h2>
            </aside>
            <h2>h2-02</h2>
        </article>
    </main>
</body>
</html>
```

`article` 下的 `h1` 同级挨着的 `h2` 有效，也就是 `h2-00` 为红色

```html
<!DOCTYPE html>
<html lang="en">
<head>
    <style>
        article h1+h2 {
            color: red;
        }
    </style>
</head>
<body>
    <main>
        <article>
            <h1>h1</h1>
          	<h2>h2-00</h2>
            <aside>
                <h2>h2-01</h2>
            </aside>
            <h2>h2-02</h2>
        </article>
    </main>
</body>
</html>
```



#### 属性选择器

https://www.bilibili.com/video/BV13E411q7nt?p=10

