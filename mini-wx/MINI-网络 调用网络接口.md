## 调用网络接口

**调用接口前，需要去微信工作平台-小程序，填写合法域名** 



#### 基本网络请求

```js
wx.request({
  url: 'https://api-hmugo-web.itheima.net/api/public/v1/categories',
  success:(res) => {
    this.setData({
      cates: res.data.message
    })
  }
});
```



#### Promise 语法网络请求

###### 封装全局网络请求类 `request/request.js`

```js
export const request=(params)=>{
  const baseUrl = 'https://api-hmugo-web.itheima.net/api/public/v1'
  return new Promise((resolve, reject)=>{
    wx.request({
      ...params,
      url: baseUrl + params.url,
      success:(res)=>{
        resolve(res);
      },
      fail:(err)=>{
        reject(err);
      }
    })
  })
}
```

###### 接口调用 e.g.

```js
request({ url: '/categories' })
  .then(res => {
    this.Cates = res.data.message;
    // 保存分类缓存数据
    wx.setStorageSync('cates', {time:Date.now(), data:this.Cates});
		// 提取大分类
    let leftMenuList = this.Cates.map(v=>v.cat_name);
  	// 提取子分类数据
    let rightContent = this.Cates[0].children;
    this.setData({
      leftMenuList,
      rightContent
    })
  })
}
```



#### 使用 es7 的 async 语法

###### 配置语法支持

1、在小程序开发工具中，勾选 es6 转 es5 语法；

2、下载 facebook 的 regenerator 库中的 [regenerator/packages/regenerator-runtime/runtime.js](https://github.com/facebook/regenerator/blob/master/packages/regenerator-runtime/runtime.js) ，进入页面点击 Raw 在浏览器打开后复制全部代码；

3、在小程序目录下新建文件夹 lib/runtime/runtime.js ，将代码拷贝进入；

4、在每一个需要使用 async 语法的页面 js 文件中引入（不能全局引入）

```js
import regeneratorRuntime from '../../lib/runtime/runtime';
```



###### 目前使用 async 语法，不再需要配置，直接打开 '增强编译' 即可使用



###### 接口调用 e.g. 使用 es7 的 async  await 发送请求

```js
// 发送异步请求
const res = await request({ url: '/categories' })
// 拿到返回数据 res 后执行下面代码
this.Cates = res.data.message;
wx.setStorageSync('cates', {time:Date.now(), data:this.Cates});
let leftMenuList = this.Cates.map(v=>v.cat_name);
let rightContent = this.Cates[0].children;
this.setData({
  leftMenuList,
  rightContent
})
```



