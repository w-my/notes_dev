## 自定义组件

#### 创建一个 Tabs 组件

`Tabs.wxml`

```xml
<!--components/Tabs/Tabs.wxml-->
<view class="tabs">
  <view class="tabs_title">
    <view class="title_item {{item.isActive ? 'title_item_active' : ''}}"
      wx:for="{{tabs}}" wx:key="id"
      bindtap="handleItemTap" data-index="{{index}}">
      {{item.value}}
    </view>
  </view>
  <view class="tabs_content">
    <!-- slot：预留插槽，以在使用组件的地方插入 UI 模块 -->
    <slot></slot>
  </view>
</view>
```

`Tabs.wxss`

```css
/* components/Tabs/Tabs.wxss */
.tabs_title {
  height: 40px;
  display: flex;
}
.title_item {
  flex: 1;
  display: flex;
  justify-content: center;
  align-items: center;
  color: #555;
  border-bottom: 2px solid #ccc;
}
.title_item_active {
  color: var(--themeColor);
  border-bottom: 2px solid currentColor;
}
```

`Tabs.json`

```json
{
  "component": true,
  "usingComponents": {}
}
```

`Tabs.js` 

```js
// components/Tabs/Tabs.js
Component({
  /**
   * 组件的属性列表
   */
  properties: {
    // 暴露属性，实现数据传入
    tabs: Array
  },

  /**
   * 组件的初始数据
   */
  data: {

  },

  /**
   * 组件的方法列表
   */
  methods: {
    handleItemTap: function(e) {
      let idx = e.currentTarget.dataset.index
      // 提供一个触发事件 performItemChange，并传参 index，以实现外界事件绑定
      this.triggerEvent("tabsItemChange", idx);
    }
  }
})

```



#### 使用 Tabs 组件

`index.json` ，引入 `Tabs` 组件

```json
{
  "usingComponents": {
    "Tabs":"../../components/Tabs/Tabs"
  }
}
```

`index.wxml` 

```xml
<!-- tabs="{{tabs}}" ：绑定 tabs 到组件的 tabs -->
<!-- bindtabsItemChange="handleTabsItemChange" ：绑定 handleTabsItemChange 到组件的 tabsItemChange 方法 -->
<view>
  <Tabs tabs="{{tabs}}" bindtabsItemChange="handleTabsItemChange">
    <!-- 利用 block 配合 wx:if 实现在组件预留 slot 的位置插入模块 -->
    <block wx:if="{{tabs[0].isActive}}"><view class="tab0">综合</view></block>
    <block wx:elif="{{tabs[1].isActive}}"><view class="tab1">销量</view></block>
    <block wx:else><view class="tab2">价格</view></block>
  </Tabs>
</view>
```

`index.wxss`

```css
.tab0 {
  width: 100%;
  height: 200px;
  background-color: red;
}
.tab1 {
  width: 100%;
  height: 200px;
  background-color: green;
}
.tab2 {
  width: 100%;
  height: 200px;
  background-color: blue;
}
```

`index.js`

```js
Page({
  data: {
    tabs:[
      {
        id: 0,
        value: '综合',
        isActive: true
      },
      {
        id: 1,
        value: '销量',
        isActive: false
      },
      {
        id: 2,
        value: '价格',
        isActive: false
      }
    ]
  },

  onLoad: function (options) {

  },

  // 实现组件绑定的事件
  handleTabsItemChange:function (e) {
    let idx = e.detail;

    let {tabs} = this.data
    tabs.forEach((v,i)=>i===idx?v.isActive=true:v.isActive=false);
    // let tabs = JSON.parse(JSON.stringify(this.data.tabs))
    // tabs.forEach(element => {
    //   if (element.id === idx) {
    //     element.isActive = true;
    //   }else {
    //     element.isActive = false;
    //   }
    // });

    this.setData({
      tabs: tabs
    })
  },

})
```

