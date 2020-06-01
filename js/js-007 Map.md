# Map

Map是一组键值对的结构，用于解决以往不能用对象做为键的问题

- 具有极快的查找速度
- 函数、对象、基本类型都可以作为键或值



## Map

#### 声明定义

可以接受一个数组作为参数，该数组的成员是一个表示键值对的数组。

```js
let map = new Map([
    ['key1', 'value1'],
    ['key2', 'value2']
]);
console.log(map.get('key1')); // value1
```

使用 `set` 方法添加元素，支持链式操作

```js
let map = new Map();
let obj = {
	  name: "aaa"
};
map.set(obj, "bb").set("name", "cc");
console.log(map.entries()); // MapIterator {{…} => "bb", "name" => "cc"}
```

使用构造函数 `new Map` 创建的原理如下

```js
const map = new Map();
const arr = [["aa", "a value"], ["bb", "b value"]];
arr.forEach(([key, value]) => {
	  map.set(key, value);
});
console.log(map);
```

对于键是对象的 `Map`， 键保存的是内存地址，值相同但内存地址不同的视为两个键。

```js
let arr = ["aa"];
const hd = new Map();
hd.set(arr, "bb");
console.log(hd.get(arr)); // bb
console.log(hd.get(["aa"])); // undefined
```



#### 获取数量

```js
console.log(map.size);
```



#### 元素检测

```js
console.log(map.has(obj1));
```



#### 读取元素

```js
let map = new Map();
let obj = {
		name: 'aa'
}
map.set(obj, 'bb');
console.log(map.get(obj));
```



#### 删除元素

使用 `delete()` 方法删除单个元素

```js
let map = new Map();
let obj = {
	name: 'aa'
}

map.set(obj, 'bb');
console.log(map.get(obj));

map.delete(obj);
console.log(map.get(obj));
```

使用 `clear` 方法清除 Map 所有元素

```js
let map = new Map();
let obj1 = {
	name: 'aa'
}

let obj2 = {
	name: 'bb'
}

map.set(obj1, {
	title: 'cc'
});

map.set(obj2, {
	title: 'dd'
});

console.log(map.size);
console.log(map.clear());
console.log(map.size);
```



#### 遍历数据

使用 `keys()` / `values()` / `entries()` 都可以返回可遍历的迭代对象。

```js
let map = new Map([["a", "av"], ["b", "bv"]]);
console.log(map.keys()); // MapIterator {"a", "b"}
console.log(map.values()); // MapIterator {"av", "bv"}
console.log(map.entries()); // MapIterator {"a" => "av", "b" => "bv"}
```

可以使用`keys/values` 函数遍历键与值

```js
let map = new Map([["a", "av"], ["b", "bv"]]);
for (const key of map.keys()) {
  console.log(key);
}
for (const value of map.values()) {
  console.log(value);
}
```

使用 `for/of` 遍历操作，直播遍历Map 等同于使用 `entries()` 函数

```js
let map = new Map([["a", "av"], ["b", "bv"]]);
for (const [key, value] of map) {
  console.log(`${key}=>${value}`);
}
```

使用`forEach`遍历操作

```js
let map = new Map([["a", "av"], ["b", "bv"]]);
map.forEach((value, key) => {
  console.log(`${key}=>${value}`);
});
```



#### 数组转换

可以使用 `展开语法` 或 `Array.form` 静态方法将Set类型转为数组，这样就可以使用数组处理函数了

```js
let map = new Map([["a", "av"], ["b", "bv"]]);

console.log(...map); // (2) ["a", "av"] (2) ["b", "bv"]
console.log(...map.entries()); // (2) ["a", "av"] (2) ["b", "bv"]
console.log(...map.values()); // av bv
console.log(...map.keys()); // a b
```

检索包含 `av` 的值组成新Map

```js
let hd = new Map([["a", "av"], ["b", "bv"]]);

let newArr = [...hd].filter(function(item) {
  return item[1].includes("av");
});

hd = new Map(newArr);
console.log(...hd.keys());
```



#### 节点集合

`map` 的 `key` 可以为任意类型，下面使用 `DOM` 节点做为键来记录数据。

```js
<body>
  <div desc="a">aa</div>
  <div desc="b">bb</div>
</body>

<script>
  const divMap = new Map();
  const divs = document.querySelectorAll("div");

  divs.forEach(div => {
    divMap.set(div, {
      content: div.getAttribute("desc")
    });
  });
  divMap.forEach((config, elem) => {
    elem.addEventListener("click", function() {
      alert(divMap.get(this).content);
    });
  });
</script>
```



#### 实例操作

当不接受协议时无法提交表单，并根据自定义信息提示用户。

```js
<form action="" onsubmit="return post()">
    接受协议:
    <input type="checkbox" name="agreement" message="请接受接受协议" />
    我是学生:
    <input type="checkbox" name="student" message="网站只对学生开放" />
    <input type="submit" />
  </form>
</body>

<script>
  function post() {
    let map = new Map();

    let inputs = document.querySelectorAll("[message]");
    // 使用set设置数据
    inputs.forEach(item =>
      map.set(item, {
        message: item.getAttribute("message"),
        status: item.checked
      })
    );

    // 遍历Map数据
    return [...map].every(([item, config]) => {
      config.status || alert(config.message);
      return config.status;
    });
  }
</script>
```



## WeakMap

**WeakMap** 对象是一组键/值对的集

- 键名必须是对象
- WeaMap对键名是弱引用的，键值是正常引用

- 垃圾回收不考虑WeaMap的键名，不会改变引用计数器，键在其他地方不被引用时即删除
- 因为WeakMap 是弱引用，由于其他地方操作成员可能会不存在，所以不可以进行 `forEach( )` 遍历等操作
- 也是因为弱引用，WeaMap 结构没有 keys( )，values( )，entries( ) 等方法和 size 属性
- 当键的外部引用删除时，希望自动删除数据时使用 `WeakMap`



#### 声明定义

以下操作由于键不是对象类型将产生错误

```text
new WeakSet("hdcms"); // TypeError: Invalid value used in weak set
```

将DOM节点保存到 `WeakSet`

```js
<body>
  <div>a</div>
  <div>b</div>
</body>
<script>
  const wm = new WeakMap();
  document
    .querySelectorAll("div")
    .forEach(item => wm.set(item, item.innerHTML));
  console.log(wm); // WeakMap {div => "b", div => "a"}
</script>
```



#### 基本操作

下面是 `WeakSet` 的常用指令

```js
const wm = new WeakMap();
const arr = ["aa"];
// 添加操作
wm.set(arr, "bb");
console.log(wm.has(arr)); // true

// 删除操作
wm.delete(arr);

// 检索判断
console.log(wm.has(arr)); // false
```



#### 垃圾回收

WakeMap的键名对象不会增加引用计数器，如果一个对象不被引用了会自动删除。

- 下例当 `a` 删除时内存即清除，因为 `WeakMap` 是弱引用不会产生引用计数
- 当垃圾回收时因为对象被删除，这时 `WakeMap` 也就没有记录了

```js
let map = new WeakMap();
let a = {};
map.set(hd, "aa");
a = null;
console.log(map);

setTimeout(() => {
  console.log(map);
}, 1000);
```


