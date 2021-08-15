# Jsoup

Jsoup 是一款 Java 的 HTML 解析器。

## Jsoup 依赖

```xml
<!--Jsoup-->
<dependency>
    <groupId>org.jsoup</groupId>
    <artifactId>jsoup</artifactId>
    <version>1.10.2</version>
</dependency>
<!--测试-->
<dependency>
    <groupId>junit</groupId>
    <artifactId>junit</artifactId>
    <version>4.12</version>
</dependency>
<!--工具-->
<dependency>
    <groupId>org.apache.commons</groupId>
    <artifactId>commons-lang3</artifactId>
    <version>3.8.1</version>
</dependency>
<dependency>
    <groupId>commons-io</groupId>
    <artifactId>commons-io</artifactId>
    <version>2.6</version>
</dependency>
```



## Jsoup 解析

### 解析 url

```java
public void testJsoupUrl() throws Exception {
    Document document = Jsoup.parse(new URL("http://www.itcast.cn/"), 1000);
    Element title = document.getElementsByTag("title").first();
    System.out.println(title.text());
}
```

在实际中不作为发起请求解析使用，一般作为 html 解析工具使用。

### 解析字符串

```java
public void testJsoupString() throws Exception {
    String html = FileUtils.readFileToString(new File("jsoup.html"), "UTF-8");
    Document document = Jsoup.parse(html);
    // ...
}
```

### 解析文件

```java
public void testJsoupHtml() throw Exception {
  	Document document = Jsoup.parse(new File("jsoup.html"), "UTF-8");
  	// ...
}
```

### 使用 dom 方式遍历文档

#### 元素获取

- `getElementById`
- `getElementsByTag`
- `getElementsByClass`
- `getElementsByAttribute`

#### 元素中获取数据

- `id()`
- `className()`
- `attr("id")`
- `attributes().toString()`
- `text()`

### 使用选择器语法查找元素

jsoup elements对象支持类似于CSS (或jquery)的选择器语法，来实现非常强大和灵活的查找功能。这个select 方法在Document, Element,或Elements对象中都可以使用。且是上下文相关的，因此可实现指定元素的过滤，或者链式选择访问。

Select方法将返回一个Elements集合，并提供一组方法来抽取和处理结果。

### Selector 选择器概述

- `tagname` : 通过标签查找元素
- `#id` : 通过 ID 查找元素
- `.class` : 通过 class 名称查找元素
- `[attribute]` : 利用属性查找元素
- `[attr=value]` : 利用属性值来查找元素

```java
Element span = document.select("span");
for (Element element : span) {
    System.out.println(element.text());
}
//
String str = document.select("#city_bj").text();
//
str = document.select(".class_a").text();
//
str = document.select("[abc").text();
//
str = document.select("[class=s_name]").text();
```

### Selector 选择器组合使用

- `el#id` : 元素+ID
- `el.class` : 元素+class
- `el[attr]` : 元素+属性名
- `任意组合` : 比如：span[abc].s_name
- `ancestor child` : 查找某个元素下一个元素
- `parent > child` : 查找某个父元素下的直接子元素
- `.city_con > ul > li` : 查找 city_con 第一级（直接子元素）的 ul，再找所有 ul 下的第一级 li
- `parent > *` : 查找某个父元素下所有直接子元素

```java
//
String str = document.select("h3#city_bj").text();
// 
str = document.select("li.class_a").text();
//
str = document.select("span[abc]").text();
//
str = document.select("span[abc].s_name").text();
//
str = document.select(".city_con li").text();
//
str = document.select(".city_con > ul > li").text();
//
str = document.select(".city_con > *").text();
```







