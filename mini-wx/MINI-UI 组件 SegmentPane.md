## 自定义组件 SegmentPane

#### SegmentBar

`SegmentBar.json`

```json
{
  "component": true,
  "usingComponents": {}
}
```

`SegmentBar.wxml`

```xml
<!--components/SegmentBar/SegmentBar.wxml-->
<view class="segment_bar segment_bar_cls">
  <view class="segment_item {{index==currentIdx?'active':''}}"
    id="{{index}}"
    wx:for="{{items}}" wx:key="id"
    bindtap="_handleTap">
    <text>{{item.title}}</text>
  </view>
</view>
```

`SegmentBar.wxss`

```css
/* components/SegmentBar/SegmentBar.wxss */
.segment_bar {
  display: flex;
}
.segment_item {
  flex: 1;
  min-height: 40px;
  border-bottom: 1px solid #ccc;
  color: #333;
  display: flex;
  flex-direction: column;
  justify-content: center;
  align-items: center;
}
.active {
  color: #ff8844;
  border-bottom: 1px solid currentColor;
}
```

`SegmentBar.js` 

```js
// components/SegmentBar/SegmentBar.js
Component({
  externalClasses: ['segment_bar_cls'],

  properties: {
    items: {
      type: Array,
      value: []
    },
    currentIdx: {
      type: Number,
      value: 0
    }
  },

  data: {
    
  },

  methods: {
    _handleTap: function(e) {
      const index = e.currentTarget.id;
      this.triggerEvent("segmentChange", {selectIdx: index});
    }
  }
})
```



#### SegmentPane

`SegmentPane.json`

```json
{
  "component": true,
  "usingComponents": {
    "SegmentBar":"/components/SegmentBar/SegmentBar"
  }
}
```

`SegmentPane.wxml`

```xml
<!--components/SegmentPane/SegmentPane.wxml-->
<view class="segment_pane segment_pane_cls">
  <SegmentBar 
    segment_bar_cls="segment_bar" 
    items="{{segmentItems}}" 
    currentIdx="{{currentIdx}}"
    bind:segmentChange="_handleSegmentChange"/>
  <swiper circular current="{{currentIdx}}" bindchange="_handleSwiperChange">
    <swiper-item wx:for="{{segmentItems}}" wx:key="index">
      <slot name="{{index}}"/>
    </swiper-item>
  </swiper>
</view>
```

`SegmentPane.wxss`

```css
/* components/SegmentPane/SegmentPane.wxss */
.segment_pane {

}
.segment_bar {
  background-color: #fff;
}
```

`SegmentPane.js` 

```js
// components/SegmentPane/SegmentPane.js
Component({
  externalClasses: ['segment_pane_cls'],
  options: {
    multipleSlots: true
  },

  properties: {
    segmentItems: {
      type: Array,
      value: []
    },
    currentIdx: {
      type: Number,
      value: 0
    }
  },

  data: {
    
  },

  methods: {
    _handleSegmentChange: function(e) {
      const index = e.detail.selectIdx;
      this.triggerEvent("segmentChange", {selectIdx: index});
    },
    _handleSwiperChange: function(e) {
      const index = e.detail.current;
      this.triggerEvent("segmentChange", {selectIdx: index});
    }
  }
})
```



#### 使用 SegmentPane 组件

`index.json` ，引入 `SegmentPane` 组件

```json
{
  "usingComponents": {
    "SegmentPane":"/components/SegmentPane/SegmentPane"
  }
}
```

`index.wxml` 

```xml
<view class="container">
  <SegmentPane 
    segment_pane_cls="segment_pane" 
    segmentItems="{{segmentItems}}"
    currentIdx="{{currentIdx}}"
    bind:segmentChange="_handleSegmentChange">
    <view slot="0"><button>按钮</button></view>
    <view slot="1"><switch></switch></view>
    <view slot="2"></view>
    <view slot="3"></view>
  </SegmentPane>
</view>
```

`index.wxss`

```css
Page {
  background-color: #fafafa;
}
.segment_pane {
  background-color: #fff;
  height: 100vh;
}
```

`index.js`

```js
Page({
  _handleSegmentChange: function(e) {
    const index = e.detail.selectIdx;
    this.setData({ 
      currentIdx: index
    });
  },

  data: {
    segmentItems: [
      {
        'id': 0,
        'title': 'item0'
      },
      {
        'id': 1,
        'title': 'item1'
      },
      {
        'id': 2,
        'title': 'item2'
      }
    ],
    currentIdx: 0,
  },

  onLoad: function (options) {

  }
})
```

