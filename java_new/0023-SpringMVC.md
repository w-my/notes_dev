# SpringMVC



## Spring与Web环境集成

#### ApplicationContext应用上下文获取方式

应用上下文对象是通过 `new ClasspathXmlApplicationContext(spring配置文件) ` 方式获取的，但是每次从容器中获得Bean时都要编写`new ClasspathXmlApplicationContext(spring配置文件) `，这样的弊端是配置文件加载多次，应用上下文对象创建多次。

在Web项目中，可以使用ServletContextListener监听Web应用的启动，我们可以在Web应用启动时，就加载Spring的配置文件，创建应用上下文对象ApplicationContext，在将其存储到最大的域servletContext域中，这样就可以在任意位置从域中获得应用上下文ApplicationContext对象了。

#### Spring提供获取应用上下文的工具

上面的分析不用手动实现，Spring提供了一个监听器ContextLoaderListener就是对上述功能的封装，该监听器内部加载Spring配置文件，创建应用上下文对象，并存储到ServletContext域中，提供了一个客户端工具WebApplicationContextUtils供使用者获得应用上下文对象。

所以我们需要做的只有两件事：

1. 在web.xml中配置ContextLoaderListener监听器（导入spring-web坐标）

2. 使用WebApplicationContextUtils获得应用上下文对象ApplicationContext

#### 导入Spring集成web的坐标

```xml
<dependency>
    <groupId>org.springframework</groupId>
    <artifactId>spring-web</artifactId>
    <version>5.0.5.RELEASE</version>
</dependency>
```

#### 配置ContextLoaderListener监听器

```xml
<!--全局参数-->
<context-param>
    <param-name>contextConfigLocation</param-name>
    <param-value>classpath:applicationContext.xml</param-value>
</context-param>
<!--Spring的监听器-->
<listener>
	<listener-class>
       org.springframework.web.context.ContextLoaderListener
   </listener-class>
 </listener>
```

#### 通过工具获得应用上下文对象

```java
ApplicationContext app = WebApplicationContextUtils.getWebApplicationContext(servletContext);
Object obj = app.getBean("id");
```

**知识要点**

Spring集成web环境步骤

1. 配置ContextLoaderListener监听器

2. 使用WebApplicationContextUtils获得应用上下文



## SpringMVC的简介

#### SpringMVC概述

SpringMVC 是一种基于 Java 的实现 MVC 设计模型的请求驱动类型的轻量级 Web 框架，属于SpringFrameWork 的后续产品，已经融合在 Spring Web Flow 中。

SpringMVC 已经成为目前最主流的MVC框架之一，并且随着Spring3.0 的发布，全面超越 Struts2，成为最优秀的 MVC 框架。它通过一套注解，让一个简单的 Java 类成为处理请求的控制器，而无须实现任何接口。同时它还支持 RESTful 编程风格的请求。

#### SpringMVC快速入门

需求：客户端发起请求，服务器端接收请求，执行逻辑并进行视图跳转。

**开发步骤**

1. 导入SpringMVC相关坐标

2. 配置SpringMVC核心控制器DispathcerServlet

3. 创建Controller类和视图页面

4. 使用注解配置Controller类中业务方法的映射地址

5. 配置SpringMVC核心文件 spring-mvc.xml

6. 客户端发起请求测试

**代码实现**

1. 导入Spring和SpringMVC的坐标、导入Servlet和Jsp的坐标

```xml
 <!--Spring坐标-->
 <dependency>
     <groupId>org.springframework</groupId>
     <artifactId>spring-context</artifactId>
     <version>5.0.5.RELEASE</version>
 </dependency>
 <!--SpringMVC坐标-->
 <dependency>
     <groupId>org.springframework</groupId>
     <artifactId>spring-webmvc</artifactId>
     <version>5.0.5.RELEASE</version>
 </dependency>
<!--Servlet坐标-->
<dependency>
    <groupId>javax.servlet</groupId>
    <artifactId>servlet-api</artifactId>
    <version>2.5</version>
</dependency>
<!--Jsp坐标-->
<dependency>
    <groupId>javax.servlet.jsp</groupId>
    <artifactId>jsp-api</artifactId>
    <version>2.0</version>
</dependency>
```

2. 在web.xml配置SpringMVC的核心控制器

```xml
<servlet>
    <servlet-name>DispatcherServlet</servlet-name>
    <servlet-class>org.springframework.web.servlet.DispatcherServlet</servlet-class>  
    <init-param>
        <param-name>contextConfigLocation</param-name>
        <param-value>classpath:spring-mvc.xml</param-value>
    </init-param>
	<load-on-startup>1</load-on-startup>
</servlet>
<servlet-mapping>   
    <servlet-name>DispatcherServlet</servlet-name>
    <url-pattern>/</url-pattern>
</servlet-mapping>

```

3. 创建Controller和业务方法

```java
public class QuickController {
	public String quickMethod(){
		System.out.println("quickMethod running.....");
		return "index";
	}
}
```

3. 创建视图页面index.jsp

```jsp
<html>
<body>
    <h2>Hello SpringMVC!</h2>
</body>
</html>
```

4. 配置注解

```java
@Controller
public class QuickController {
	@RequestMapping("/quick")
	public String quickMethod(){
		System.out.println("quickMethod running.....");
			return "index";
	}
}
```

5. 创建spring-mvc.xml

```xml
<beans xmlns="http://www.springframework.org/schema/beans"      xmlns:mvc="http://www.springframework.org/schema/mvc"    xmlns:context="http://www.springframework.org/schema/context"     xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"    xsi:schemaLocation="http://www.springframework.org/schema/beans     http://www.springframework.org/schema/beans/spring-beans.xsd     http://www.springframework.org/schema/mvc       http://www.springframework.org/schema/mvc/spring-mvc.xsd      http://www.springframework.org/schema/context       http://www.springframework.org/schema/context/spring-context.xsd">    <!--配置注解扫描-->    <context:component-scan base-package="com.itheima"/></beans>
```

6. 访问测试地址

```xml
http://localhost:8080/itheima_springmvc1/quick 
```

控制台打印

```
quickMethod running.....
```

页面显示

![SpringMVC](./img/0023-SpringMVC.png)

#### SpringMVC流程图示

![SpringMVC流程图](./img/0023-SpringMVC流程图.png)

#### 知识要点

SpringMVC的开发步骤 

   ①导入SpringMVC相关坐标

   ②配置SpringMVC核心控制器DispathcerServlet

   ③创建Controller类和视图页面

   ④使用注解配置Controller类中业务方法的映射地址

   ⑤配置SpringMVC核心文件 spring-mvc.xml

   ⑥客户端发起请求测试

## SpringMVC的组件解析

#### SpringMVC的执行流程

![SpringMVC执行流程](./img/0023-SpringMVC执行流程.png)



1. 用户发送请求至前端控制器DispatcherServlet。
2. DispatcherServlet收到请求调用HandlerMapping处理器映射器。
3. 处理器映射器找到具体的处理器(可以根据xml配置、注解进行查找)，生成处理器对象及处理器拦截器(如果有则生成)一并返回给DispatcherServlet。
4. DispatcherServlet调用HandlerAdapter处理器适配器。
5. HandlerAdapter经过适配调用具体的处理器(Controller，也叫后端控制器)。
6. Controller执行完成返回ModelAndView。
7. HandlerAdapter将controller执行结果ModelAndView返回给DispatcherServlet。
8. DispatcherServlet将ModelAndView传给ViewReslover视图解析器。
9. ViewReslover解析后返回具体View。
10. DispatcherServlet根据View进行渲染视图（即将模型数据填充至视图中）。DispatcherServlet响应用户。

#### SpringMVC组件解析

1. **前端控制器：DispatcherServlet**

​    用户请求到达前端控制器，它就相当于 MVC 模式中的 C，DispatcherServlet 是整个流程控制的中心，由它调用其它组件处理用户的请求，DispatcherServlet 的存在降低了组件之间的耦合性。

2. **处理器映射器：HandlerMapping**

​    HandlerMapping 负责根据用户请求找到 Handler 即处理器，SpringMVC 提供了不同的映射器实现不同的映射方式，例如：配置文件方式，实现接口方式，注解方式等。

3. **处理器适配器：HandlerAdapter**

​    通过 HandlerAdapter 对处理器进行执行，这是适配器模式的应用，通过扩展适配器可以对更多类型的处理器进行执行。

4. **处理器：Handler**

​    它就是我们开发中要编写的具体业务控制器。由 DispatcherServlet 把用户请求转发到 Handler。由 Handler 对具体的用户请求进行处理。

5. **视图解析器：View Resolver**

​    View Resolver 负责将处理结果生成 View 视图，View Resolver 首先根据逻辑视图名解析成物理视图名，即具体的页面地址，再生成 View 视图对象，最后对 View 进行渲染将处理结果通过页面展示给用户。

6. **视图：View**

​    SpringMVC 框架提供了很多的 View 视图类型的支持，包括：jstlView、freemarkerView、pdfView等。最常用的视图就是 jsp。一般情况下需要通过页面标签或页面模版技术将模型数据通过页面展示给用户，需要由程序员根据业务需求开发具体的页面

#### SpringMVC注解解析

@RequestMapping

作用：用于建立请求 URL 和处理请求方法之间的对应关系

位置：

​		类上，请求URL 的第一级访问目录。此处不写的话，就相当于应用的根目录

​		方法上，请求 URL 的第二级访问目录，与类上的使用@ReqquestMapping标注的一级目录一起组成访问虚拟路径

属性：

​		value：用于指定请求的URL。它和path属性的作用是一样的

​		method：用于指定请求的方式

​		params：用于指定限制请求参数的条件。它支持简单的表达式。要求请求参数的key和value必须和配置的一模一样

例如：

​		params = {"accountName"}，表示请求参数必须有accountName

​		params = {"moeny!100"}，表示请求参数中money不能是100

1. mvc命名空间引入

```xml
命名空间：
xmlns:context="http://www.springframework.org/schema/context"
xmlns:mvc="http://www.springframework.org/schema/mvc"
约束地址：
http://www.springframework.org/schema/context
http://www.springframework.org/schema/context/spring-context.xsd
http://www.springframework.org/schema/mvc
http://www.springframework.org/schema/mvc/spring-mvc.xsd
```

2. 组件扫描

SpringMVC基于Spring容器，所以在进行SpringMVC操作时，需要将Controller存储到Spring容器中，如果使用@Controller注解标注的话，就需要使用<context:component-scan base-package=“com.itheima.controller"/>进行组件扫描。

#### SpringMVC的XML配置解析

SpringMVC有默认组件配置，默认组件都是DispatcherServlet.properties配置文件中配置的，该配置文件地址org/springframework/web/servlet/DispatcherServlet.properties，该文件中配置了默认的视图解析器，如下：

```properties
org.springframework.web.servlet.ViewResolver=org.springframework.web.servlet.view.InternalResourceViewResolver
```

翻看该解析器源码，可以看到该解析器的默认设置，如下：

```properties
REDIRECT_URL_PREFIX = "redirect:"  --重定向前缀
FORWARD_URL_PREFIX = "forward:"    --转发前缀（默认值）
prefix = "";     --视图名称前缀
suffix = "";     --视图名称后缀
```

1. 视图解析器

我们可以通过属性注入的方式修改视图的的前后缀

```xml
<!--配置内部资源视图解析器-->
<bean class="org.springframework.web.servlet.view.InternalResourceViewResolver">  
  <property name="prefix" value="/WEB-INF/views/"></property>  
  <property name="suffix" value=".jsp"></property>
</bean>
```

#### 知识要点

**SpringMVC的相关组件** 

前端控制器：DispatcherServlet

处理器映射器：HandlerMapping

处理器适配器：HandlerAdapter

处理器：Handler

视图解析器：View Resolver

视图：View

**SpringMVC的注解和配置** 

请求映射注解：@RequestMapping

视图解析器配置：

REDIRECT_URL_PREFIX = "redirect:"  

FORWARD_URL_PREFIX = "forward:"    

prefix = "";     

suffix = "";     





# SpringMVC的请求和响应

## SpringMVC的数据响应

#### 数据响应方式

1. 页面跳转

   直接返回字符串

   通过ModelAndView对象返回

2. 回写数据 

   直接返回字符串

   返回对象或集合    

#### 页面跳转-返回字符串形式

![SpringMVC数据响应-返回字符串](./img/0023-SpringMVC数据响应-返回字符串.jpg)

#### 页面跳转-返回ModelAndView形式1

在Controller中方法返回ModelAndView对象，并且设置视图名称

```java
@RequestMapping(value="/quick2")
public ModelAndView save2(){
    /*
        Model:模型 作用封装数据
        View：视图 作用展示数据
     */
    ModelAndView modelAndView = new ModelAndView();
    // 设置模型数据
    modelAndView.addObject("username","itcast");
    // 设置视图名称
    modelAndView.setViewName("success");

    return modelAndView;
}
```

#### 页面跳转-返回ModelAndView形式2

n在Controller中方法形参上直接声明ModelAndView，无需在方法中自己创建，在方法中直接使用该对象设置视图，同样可以跳转页面

```java
@RequestMapping(value="/quick3")
public ModelAndView save3(ModelAndView modelAndView){
    modelAndView.addObject("username","itheima");
    modelAndView.setViewName("success");
    return modelAndView;
}
@RequestMapping(value="/quick4")
public String save4(Model model){
    model.addAttribute("username","博学谷");
    return "success";
}
```

#### 页面跳转-返回ModelAndView形式3

在Controller方法的形参上可以直接使用原生的HttpServeltRequest对象，只需声明即可

```java
@RequestMapping(value="/quick5")
public String save5(HttpServletRequest request){
    request.setAttribute("username","酷丁鱼");
    return "success";
}
```

#### 回写数据-直接回写字符串

通过SpringMVC框架注入的response对象，使用 `response.getWriter().print(“hello world”)`  回写数据，此时不需要视图跳转，业务方法返回值为 `void`

将需要回写的字符串直接返回，但此时需要通过 `@ResponseBody` 注解告知SpringMVC框架，方法返回的字符串不是跳转是直接在http响应体中返回

```java
@RequestMapping(value="/quick7")
@ResponseBody  // 告知SpringMVC框架 不进行视图跳转 直接进行数据响应
public String save7() throws IOException {
    return "hello itheima";
}

@RequestMapping(value="/quick6")
public void save6(HttpServletResponse response) throws IOException {
    response.getWriter().print("hello itcast");
}
```

#### 回写数据-直接回写json格式字符串

```java
@RequestMapping(value="/quick8")
@ResponseBody
public String save8() throws IOException {
    return "{\"username\":\"zhangsan\",\"age\":18}";
}
```

手动拼接json格式字符串的方式很麻烦，开发中往往要将复杂的java对象转换成json格式的字符串，我们可以使用web阶段学习过的json转换工具jackson进行转换,通过jackson转换json格式字符串，回写字符串

```java
@RequestMapping(value="/quick9")
@ResponseBody
public String save9() throws IOException {
    User user = new User();
    user.setUsername("lisi");
    user.setAge(30);
    // 使用json的转换工具将对象转换成json格式字符串在返回
    ObjectMapper objectMapper = new ObjectMapper();
    String json = objectMapper.writeValueAsString(user);
    return json;
}
```

#### 回写数据-返回对象或集合

通过SpringMVC帮助我们对对象或集合进行json字符串的转换并回写，为处理器适配器配置消息转换参数，指定使用 `jackson` 进行对象或集合的转换，因此需要在 `spring-mvc.xml` 中进行如下配置：

```xml
<bean class="org.springframework.web.servlet.mvc.method.annotation.RequestMappingHandlerAdapter">
    <property name="messageConverters">
        <list>
            <bean class="org.springframework.http.converter.json.MappingJackson2HttpMessageConverter"/>
        </list>
    </property>
</bean>
```

```java
@RequestMapping(value="/quick10")
@ResponseBody
// 期望SpringMVC自动将User转换成json格式的字符串
public User save10() throws IOException {
    User user = new User();
    user.setUsername("lisi2");
    user.setAge(32);
    return user;
}
```

#### 回写数据-返回对象或集合2

在方法上添加 `@ResponseBody` 就可以返回json格式的字符串，但是这样配置比较麻烦，配置的代码比较多，因此，我们可以使用mvc的注解驱动代替上述配置

```xml
<mvc:annotation-driven/>
```

在 SpringMVC 的各个组件中，处理器映射器、处理器适配器、视图解析器称为 SpringMVC 的三大组件。

使用`<mvc:annotation-driven />`自动加载 RequestMappingHandlerMapping（处理映射器）和

RequestMappingHandlerAdapter（ 处 理 适 配 器 ），可用在 `Spring-xml.xml` 配置文件中使用

`<mvc:annotation-driven />`替代注解处理器和适配器的配置。

同时使用`<mvc:annotation-driven />`

默认底层就会集成jackson进行对象或集合的json格式字符串的转换

#### 知识要点小结

1. 页面跳转

   直接返回字符串

   通过ModelAndView对象返回

2. 回写数据 

   直接返回字符串

   HttpServletResponse 对象直接写回数据，HttpServletRequest对象带回数据，Model对象带回数据或者@ResponseBody将字符串数据写回

   返回对象或集合 

   @ResponseBody+`<mvc:annotation-driven/>   `

   

## SpringMVC的请求

#### 获得请求参数-请求参数类型(理解)

客户端请求参数的格式是：name=value&name=value……

服务器端要获得请求的参数，有时还需要进行数据的封装，SpringMVC可以接收如下类型的参数

基本类型参数

POJO类型参数

数组类型参数

集合类型参数

#### 获得请求参数-获得基本类型参数(应用)

Controller中的业务方法的参数名称要与请求参数的name一致，参数值会自动映射匹配。并且能自动做类型转换；

自动的类型转换是指从String向其他类型的转换

`http://localhost:8080/itheima_springmvc1/quick9?username=zhangsan&age=12`

```java
@RequestMapping(value="/quick11")    @ResponseBody    public void save11(String username,int age) throws IOException {        System.out.println(username);        System.out.println(age);    }
```



#### 获得请求参数-获得POJO类型参数(应用)

Controller中的业务方法的POJO参数的属性名与请求参数的name一致，参数值会自动映射匹配。

```java
package com.itheima.domain;public class User {    private String username;    private int age;    public String getUsername() {        return username;    }    public void setUsername(String username) {        this.username = username;    }    public int getAge() {        return age;    }    public void setAge(int age) {        this.age = age;    }    @Override    public String toString() {        return "User{" +                "username='" + username + '\'' +                ", age=" + age +                '}';    }}
```

```java
@RequestMapping(value="/quick12")    @ResponseBody    public void save12(User user) throws IOException {        System.out.println(user);    }
```



#### 获得请求参数-获得数组类型参数(应用)

Controller中的业务方法数组名称与请求参数的name一致，参数值会自动映射匹配。

```java
@RequestMapping(value="/quick13")    @ResponseBody    public void save13(String[] strs) throws IOException {        System.out.println(Arrays.asList(strs));    }
```



#### 获得请求参数-获得集合类型参数1(应用)

获得集合参数时，要将集合参数包装到一个POJO中才可以。

```jsp
<form action="${pageContext.request.contextPath}/user/quick14" method="post">        <%--表明是第一个User对象的username age--%>        <input type="text" name="userList[0].username"><br/>        <input type="text" name="userList[0].age"><br/>        <input type="text" name="userList[1].username"><br/>        <input type="text" name="userList[1].age"><br/>        <input type="submit" value="提交">    </form>
```

```java
package com.itheima.domain;import java.util.List;public class VO {    private List<User> userList;    public List<User> getUserList() {        return userList;    }    public void setUserList(List<User> userList) {        this.userList = userList;    }    @Override    public String toString() {        return "VO{" +                "userList=" + userList +                '}';    }}
```

```java
@RequestMapping(value="/quick14")    @ResponseBody    public void save14(VO vo) throws IOException {        System.out.println(vo);    }
```



#### 获得请求参数-获得集合类型参数2(应用)

当使用ajax提交时，可以指定contentType为json形式，那么在方法参数位置使用@RequestBody可以直接接收集合数据而无需使用POJO进行包装

```jsp
<script src="${pageContext.request.contextPath}/js/jquery-3.3.1.js"></script>    <script>        var userList = new Array();        userList.push({username:"zhangsan",age:18});        userList.push({username:"lisi",age:28});        $.ajax({            type:"POST",            url:"${pageContext.request.contextPath}/user/quick15",            data:JSON.stringify(userList),            contentType:"application/json;charset=utf-8"        });    </script>
```

```java
@RequestMapping(value="/quick15")    @ResponseBody    public void save15(@RequestBody List<User> userList) throws IOException {        System.out.println(userList);    }
```



#### 获得请求参数-静态资源访问的开启(应用)

当有静态资源需要加载时，比如jquery文件，通过谷歌开发者工具抓包发现，没有加载到jquery文件，原因是SpringMVC的前端控制器DispatcherServlet的url-pattern配置的是/,代表对所有的资源都进行过滤操作，我们可以通过以下两种方式指定放行静态资源：

•在spring-mvc.xml配置文件中指定放行的资源

​     `<mvc:resources mapping="/js/**"location="/js/"/> `

•使用`<mvc:default-servlet-handler/>`标签

```xml
<!--开发资源的访问-->    <!--<mvc:resources mapping="/js/**" location="/js/"/>    <mvc:resources mapping="/img/**" location="/img/"/>-->    <mvc:default-servlet-handler/>
```

#### 获得请求参数-配置全局乱码过滤器(应用)

当post请求时，数据会出现乱码，我们可以设置一个过滤器来进行编码的过滤。

```xml
<!--配置全局过滤的filter-->    <filter>        <filter-name>CharacterEncodingFilter</filter-name>        <filter-class>org.springframework.web.filter.CharacterEncodingFilter</filter-class>        <init-param>            <param-name>encoding</param-name>            <param-value>UTF-8</param-value>        </init-param>    </filter>    <filter-mapping>        <filter-name>CharacterEncodingFilter</filter-name>        <url-pattern>/*</url-pattern>    </filter-mapping>
```



#### 获得请求参数-参数绑定注解@RequestParam(应用)

当请求的参数名称与Controller的业务方法参数名称不一致时，就需要通过@RequestParam注解显示的绑定

```html
<form action="${pageContext.request.contextPath}/quick16" method="post">    <input type="text" name="name"><br>    <input type="submit" value="提交"><br></form>
```

```java
@RequestMapping(value="/quick16")    @ResponseBody    public void save16(@RequestParam(value="name",required = false,defaultValue = "itcast") String username) throws IOException {        System.out.println(username);    }
```



#### 获得请求参数-Restful风格的参数的获取(应用)

Restful是一种软件架构风格、设计风格，而不是标准，只是提供了一组设计原则和约束条件。主要用于客户端和服务器交互类的软件，基于这个风格设计的软件可以更简洁，更有层次，更易于实现缓存机制等。

Restful风格的请求是使用“url+请求方式”表示一次请求目的的，HTTP 协议里面四个表示操作方式的动词如下：

GET：用于获取资源

POST：用于新建资源

PUT：用于更新资源

DELETE：用于删除资源  

例如：

/user/1    GET ：       得到 id = 1 的 user

/user/1   DELETE：  删除 id = 1 的 user

/user/1    PUT：       更新 id = 1 的 user

/user       POST：      新增 user

上述url地址/user/1中的1就是要获得的请求参数，在SpringMVC中可以使用占位符进行参数绑定。地址/user/1可以写成/user/{id}，占位符{id}对应的就是1的值。在业务方法中我们可以使用@PathVariable注解进行占位符的匹配获取工作。

`http://localhost:8080/itheima_springmvc1/quick17/zhangsan`

```java
@RequestMapping(value="/quick17/{name}")@ResponseBody public void save17(@PathVariable(value="name") String username) throws IOException {        System.out.println(username); }
```

#### 获得请求参数-自定义类型转换器(应用)

SpringMVC 默认已经提供了一些常用的类型转换器，例如客户端提交的字符串转换成int型进行参数设置。

但是不是所有的数据类型都提供了转换器，没有提供的就需要自定义转换器，例如：日期类型的数据就需要自定义转换器。

```java
public class DateConverter implements Converter<String, Date> {    public Date convert(String dateStr) {        //将日期字符串转换成日期对象 返回        SimpleDateFormat format = new SimpleDateFormat("yyyy-MM-dd");        Date date = null;        try {            date = format.parse(dateStr);        } catch (ParseException e) {            e.printStackTrace();        }        return date;    }}
```

```java
@RequestMapping(value="/quick18")    @ResponseBody    public void save18(Date date) throws IOException {        System.out.println(date);    }
```



#### 获得请求参数-获得Servlet相关API(应用)

SpringMVC支持使用原始ServletAPI对象作为控制器方法的参数进行注入，常用的对象如下：

HttpServletRequest

HttpServletResponse

HttpSession

```java
@RequestMapping(value="/quick19")    @ResponseBody    public void save19(HttpServletRequest request, HttpServletResponse response, HttpSession session) throws IOException {        System.out.println(request);        System.out.println(response);        System.out.println(session);    }
```



#### 获得请求参数-获得请求头信息(应用)

使用@RequestHeader可以获得请求头信息，相当于web阶段学习的request.getHeader(name)

@RequestHeader注解的属性如下：

value：请求头的名称

required：是否必须携带此请求头

```java
@RequestMapping(value="/quick20")    @ResponseBody    public void save20(@RequestHeader(value = "User-Agent",required = false) String user_agent) throws IOException {        System.out.println(user_agent);    }
```

使用@CookieValue可以获得指定Cookie的值

@CookieValue注解的属性如下：

value：指定cookie的名称

required：是否必须携带此cookie

```java
 @RequestMapping(value="/quick21")    @ResponseBody    public void save21(@CookieValue(value = "JSESSIONID") String jsessionId) throws IOException {        System.out.println(jsessionId);    }
```



