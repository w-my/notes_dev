# JavaWeb - Tomcat&Servlet



## Web服务器软件

常见的java相关的web服务器软件

- webLogic：oracle公司，大型的JavaEE服务器，支持所有的JavaEE规范，收费的。
- webSphere：IBM公司，大型的JavaEE服务器，支持所有的JavaEE规范，收费的。
- JBOSS：JBOSS公司的，大型的JavaEE服务器，支持所有的JavaEE规范，收费的。
- Tomcat：Apache基金组织，中小型的JavaEE服务器，仅仅支持少量的JavaEE规范servlet/jsp。开源的，免费的。

## JavaEE

Java语言在企业级开发中使用的技术规范的总和，一共规定了13项大的规范



## Tomcat

web服务器软件

#### 安装


	1. 下载：http://tomcat.apache.org/
	2. 安装（Mac端）：解压压缩包放到期望的位置即可。
	  * 注意：安装目录不要有中文和空格
	3. 卸载：删除目录就行了
	4. 启动：
	  * 终端进入安装目录/bin下，执行 `startup.sh`
	  * 访问：浏览器输入：
	  			http://localhost:8080 访问自己
	        http://别人的ip:8080 访问别人
	5. 关闭：
	  1. 正常关闭：
	    * 终端进入安装目录/bin下，执行 `shutdown.bat`
	    * ctrl+c
	  2. 强制关闭：
	    * 点击启动窗口的×
	6. 配置全局路径访问：
		* 编辑配置文件：`vim ~/.bash_profile`
		* 文件中加入执行文件路径： `export PATH=$PATH:/Library/apache-tomcat-10.0.6/bin`
		* 保存关闭后，刷新文件：`source ~/.bash_profile`
		* 之后就可以直接使用 `startup.sh` 或 `shutdown.sh` 开启后关闭tomcat服务了
	7. 配置：
	  * 部署项目的方式：
	    1. 直接将项目放到webapps目录下即可。
	      * /hello：项目的访问路径-->虚拟目录
	      * 简化部署：将项目打成一个war包，再将war包放置到webapps目录下。
	        * war包会自动解压缩
	    2. 配置conf/server.xml文件
	      在<Host>标签体中配置
	      <Context docBase="D:\hello" path="/hehe" />
	      * docBase:项目存放的路径
	      * path：虚拟目录
	    3. 在conf\Catalina\localhost创建任意名称的xml文件。在文件中编写
	      <Context docBase="D:\hello" />
	      * 虚拟目录：xml文件的名称
	
	  * 静态项目和动态项目：
	    * 目录结构
	      * java动态项目的目录结构：
	        -- 项目的根目录
	          -- WEB-INF目录：
	            -- web.xml：web项目的核心配置文件
	            -- classes目录：放置字节码文件的目录
	            -- lib目录：放置依赖的jar包

#### IDEA集成Tomcat


	* 将Tomcat集成到IDEA中，并且创建JavaEE的项目，部署项目。
		* 打开IDEA 
			-> run 
			-> Edit configurations 
			-> + 
			-> TomEE Server 
			-> Local 
			-> Application server 选择 tomcat 文件夹
			-> OK
		* 创建项目或Module
			-> 选择 Java Enterprise
			-> Project template 选择 Web application
			-> Application server 选择对应的 Tomcat
			-> Next 
			-> Finish



## Servlet：server applet

Servlet就是一个接口，定义了Java类被浏览器访问到(tomcat识别)的规则。

#### 简单使用

```
1. 创建JavaEE项目
2. 定义一个类，实现Servlet接口
  * public class ServletDemo1 implements Servlet
3. 实现接口中的抽象方法
4. 配置Servlet
   在web.xml中配置：
    <!--配置Servlet -->
    <servlet>
        <servlet-name>demo1</servlet-name>
        <servlet-class>cn.itcast.web.servlet.ServletDemo1</servlet-class>
    </servlet>
    <servlet-mapping>
        <servlet-name>demo1</servlet-name>
        <url-pattern>/demo1</url-pattern>
    </servlet-mapping>
```

#### 执行原理

```
1. 当服务器接受到客户端浏览器的请求后，会解析请求URL路径，获取访问的Servlet的资源路径
2. 查找web.xml文件，是否有对应的<url-pattern>标签体内容。
3. 如果有，则在找到对应的<servlet-class>全类名
4. tomcat会将字节码文件加载进内存，并且创建其对象
5. 调用其方法
```

#### Servlet 中的生命周期方法


	1. 被创建：执行init方法，只执行一次
	  * Servlet什么时候被创建？
	    * 默认情况下，第一次被访问时，Servlet被创建
	    * 可以配置执行Servlet的创建时机。
	      * 在<servlet>标签下配置
	        1. 第一次被访问时，创建
	                  * <load-on-startup>的值为负数
	              2. 在服务器启动时，创建
	                  * <load-on-startup>的值为0或正整数
	  * Servlet的init方法，只执行一次，说明一个Servlet在内存中只存在一个对象，Servlet是单例的
	    * 多个用户同时访问时，可能存在线程安全问题。
	    * 解决：尽量不要在Servlet中定义成员变量。即使定义了成员变量，也不要修改值
	2. 提供服务：执行service方法，执行多次
	  * 每次访问Servlet时，Service方法都会被调用一次。
	3. 被销毁：执行destroy方法，只执行一次
	  * Servlet被销毁时执行。服务器关闭时，Servlet被销毁
	  * 只有服务器正常关闭时，才会执行destroy方法。
	  * destroy方法在Servlet被销毁之前执行，一般用于释放资源

#### Servlet3.0

 ```
 * 好处：
   * 支持注解配置。可以不需要web.xml了。
 * 步骤：
   1. 创建JavaEE项目，选择Servlet的版本3.0以上，可以不创建web.xml
   2. 定义一个类，实现Servlet接口
   3. 复写方法
   4. 在类上使用@WebServlet注解，进行配置
 ```


```java
@WebServlet("资源路径")
@Target({ElementType.TYPE})
@Retention(RetentionPolicy.RUNTIME)
@Documented
public @interface WebServlet {
    String name() default "";//相当于<Servlet-name>
    String[] value() default {};//代表urlPatterns()属性配置
    String[] urlPatterns() default {};//相当于<url-pattern>
    int loadOnStartup() default -1;//相当于<load-on-startup>
    WebInitParam[] initParams() default {};
    boolean asyncSupported() default false;
    String smallIcon() default "";
    String largeIcon() default "";
    String description() default "";
    String displayName() default "";
}
```

#### Servlet 结构体系

```
Servlet -- 接口
  |
GenericServlet -- 抽象类
  |
HttpServlet  -- 抽象类

* GenericServlet：将Servlet接口中其他的方法做了默认空实现，只将service()方法作为抽象
  * 将来定义Servlet类时，可以继承GenericServlet，实现service()方法即可

* HttpServlet：对http协议的一种封装，简化操作
  1. 定义类继承HttpServlet
  2. 复写doGet/doPost方法
```

#### Servlet相关配置

```
1. urlpartten:Servlet访问路径
  1. 一个Servlet可以定义多个访问路径 ： @WebServlet({"/d4","/dd4","/ddd4"})
  2. 路径定义规则：
    1. /xxx：路径匹配
    2. /xxx/xxx:多层路径，目录结构
    3. *.do：扩展名匹配
```

