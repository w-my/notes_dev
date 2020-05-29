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





#### 节点集合





#### 实例操作



## WeakMap

#### 声明定义





#### 基本操作





#### 垃圾回收





#### 选课案例



