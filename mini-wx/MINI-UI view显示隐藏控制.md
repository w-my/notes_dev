## view 的显示控制

`showView1` 为true，显示 `view1` 不显示 `view2`，否则隐藏 `view1` 显示 `view2`。

`wxml`

```javascript
<view>
  <view wx:if="{{showView1}}">view1</view>
  <block wx:else>
    <view>view2</view>
  </block>
  <view>view3</view>
  <button bindtap="btnClick">不显示view1，显示view2</button>
</view>
```

`js`

```javascript
data: {
  showView1: true
},

btnClick: function () {
  this.setData({
    showView1: false
  })
}
```

