## 行布局

( left | right (top/btm) )

`.wxml`

```javascript
<view class="tab_0">
  <navigator class="goods_item">
    <!-- 图片 -->
    <view class="goods_img_wrap">
      <image mode="aspectFill" src="http://image5.suning.cn/uimg/b2c/newcatentries/0000000000-000000000160455569_1_400x400.jpg"></image>
    </view>
    <!-- 标题价格 -->
    <view class="goods_info_wrap">
      <view class="goods_name">海信(Hisense)LED55MU9600X3DUC 55英寸 4K超高清量子点电视 ULED画质 VIDAA系统 ULED画质 VIDAA系统</view>
      <view class="goods_price">￥13999</view>
    </view>
  </navigator>
  <navigator class="goods_item">
    <!-- 图片 -->
    <view class="goods_img_wrap">
      <image mode="aspectFill" src="http://image5.suning.cn/uimg/b2c/newcatentries/0000000000-000000000193373779_1_400x400.jpg"></image>
    </view>
    <!-- 标题价格 -->
    <view class="goods_info_wrap">
      <view class="goods_name">海信(Hisense)LED55MU9600X3DUC 55英寸 4K超高清量子点电视 ULED画质 VIDAA系统</view>
      <view class="goods_price">￥13999</view>
    </view>
  </navigator>
</view>
```

`.wxss`

```javascript
.goods_item {
  border-bottom: 1rpx solid #eee;
  display: flex;
  justify-content: left;
  align-items: center;
  padding: 2px 16rpx;
  height: 80px;
}
.goods_img_wrap {
  flex: 2;
  height: 90%;
  display: flex;
  justify-content: center;
  align-items: center;
}
.goods_img_wrap image {
  height: 100%;
  width: 100%;
}
.goods_info_wrap {
  flex: 6;
  height: 90%;
  margin-left:16rpx;
  display: flex;
  flex-direction: column;
  justify-content: space-around;
}
.goods_name {
  font-size: 14px;
  display: -webkit-box;
  overflow: hidden;
  -webkit-line-clamp: 2;
  -webkit-box-orient: vertical;
  white-space: normal;
  text-overflow: ellipsis;
  word-wrap: break-word;
  word-break: break-all;
}
.goods_price {
  color: var(--themeColor);
  font-size: 16px;
}
```



