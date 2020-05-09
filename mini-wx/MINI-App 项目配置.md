## 项目配置

#### ~ 使用图标 [iconfont](https://www.iconfont.cn)

去该网站选好需要的图片添加到购物车，选择 `添加至项目` ，选择使用图标类 `Font class` ，点击 `查看在线链接`，复制到浏览器地址输入框，复制展示出来的代码，在项目中创建样式类 `iconfont.class` ，将复制的内容粘贴进去。

在 `app.wxss` 中全局导入样式

```css
@import "./styles/iconfont.wxss";
```

使用：

```html
<text class="iconfont icon-kefu"></text>
```



#### ~ 全局配置默认样式

`app.wxss`

```css
page,view,text,swiper,swiper-item,image,navigator {
  padding: 0;
  margin: 0;
  box-sizing: border-box;
}
```



#### ~ 全局配置颜色

`app.wxss`

```css
page {
  --themeColor:#ff8844;
}
```

使用主题色，例如在 `index.wxss` 给 `view` 设置颜色

```css
view {
  color: var(--themeColor);
}
```



~ 全局配置字体大小

`app.wxss`

```css
page {
  /* 定义全局字体大小 */
  font-size: 14px;
}

```

