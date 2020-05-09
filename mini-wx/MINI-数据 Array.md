## Array

#### 遍历

```javascript
// 先对原数组做深拷贝，然后再遍历，可以避免异常错误
let arr = JSON.parse(JSON.stringify(this.data.arr))
arr.forEach(element => {
  
});
```

