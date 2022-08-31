# JavaWeb - Cookie & Session



## Cookie

#### 概念

客户端会话技术，将数据保存到客户端

#### 使用

###### 创建Cookie对象，绑定数据

```java
new Cookie(String name, String value)
```

###### 发送Cookie对象

```java
response.addCookie(Cookie cookie)
```

###### 获取Cookie，拿到数据

```java
Cookie[] request.getCookies()
```

#### 实现原理

基于响应头set-cookie和请求头cookie实现

#### cookie的细节


	1. 一次可不可以发送多个cookie?
	  * 可以
	  * 可以创建多个Cookie对象，使用response调用多次addCookie方法发送cookie即可。
	2. cookie在浏览器中保存多长时间？
	  1. 默认情况下，当浏览器关闭后，Cookie数据被销毁
	  2. 持久化存储：
	    * setMaxAge(int seconds)
	      1. 正数：将Cookie数据写到硬盘的文件中。持久化存储。并指定cookie存活时间，时间到后，cookie文件自动失效
	      2. 负数：默认值
	      3. 零：删除cookie信息
	3. cookie能不能存中文？
	  * 在tomcat 8 之前 cookie中不能直接存储中文数据。
	    * 需要将中文数据转码---一般采用URL编码(%E3)
	  * 在tomcat 8 之后，cookie支持中文数据。特殊字符还是不支持，建议使用URL编码存储，URL解码解析
	4. cookie共享问题？
	  1. 假设在一个tomcat服务器中，部署了多个web项目，那么在这些web项目中cookie能不能共享？
	    * 默认情况下cookie不能共享
	    * setPath(String path):设置cookie的获取范围。默认情况下，设置当前的虚拟目录
	      * 如果要共享，则可以将path设置为"/"
	  2. 不同的tomcat服务器间cookie共享问题？
	    * setDomain(String path):如果设置一级域名相同，那么多个服务器之间cookie可以共享
	      * setDomain(".baidu.com"),那么tieba.baidu.com和news.baidu.com中cookie可以共享
	5. Cookie的特点和作用
		1. cookie存储数据在客户端浏览器
		2. 浏览器对于单个cookie 的大小有限制(4kb) 以及 对同一个域名下的总cookie数量也有限制(20个)
		* 作用：
			1. cookie一般用于存出少量的不太敏感的数据
			2. 在不登录的情况下，完成服务器对客户端的身份识别



## Session

服务器端会话技术，在一次会话的多次请求间共享数据，将数据保存在服务器端的对象中。

#### HttpSession

###### 获取

```java
HttpSession session = request.getSession();
```

###### 使用

```java
Object getAttribute(String name);
void setAttribute(String name, Object value);
void removeAttribute(String name);
```

####原理

Session的实现是依赖于Cookie的。

#### 细节

	1. 当客户端关闭后，服务器不关闭，两次获取session是否为同一个？		
	  * 默认情况下。不是。		
	  * 如果需要相同，则可以创建Cookie,键为JSESSIONID，设置最大存活时间，让cookie持久化保存。			 
	  Cookie c = new Cookie("JSESSIONID",session.getId());	         
	  c.setMaxAge(60*60);	         
	  response.addCookie(c);	
	2. 客户端不关闭，服务器关闭后，两次获取的session是同一个吗？		
	  * 不是同一个，但是要确保数据不丢失。tomcat自动完成以下工作			
	  * session的钝化：				
	  	* 在服务器正常关闭之前，将session对象系列化到硬盘上			
	  * session的活化：				
	    * 在服务器启动后，将session文件转化为内存中的session对象即可。				
	3. session什么时候被销毁？		
	  1. 服务器关闭		
	  2. session对象调用invalidate() 。		
	  3. session默认失效时间 30分钟			
	  	选择性配置修改				
	      <session-config>		        
		      <session-timeout>30</session-timeout>		    
	      </session-config> 

#### session的特点

	1. session用于存储一次会话的多次请求的数据，存在服务器端	 
	2. session可以存储任意类型，任意大小的数据	* session与Cookie的区别：		
	  1. session存储数据在服务器端，Cookie在客户端		
	  2. session没有数据大小限制，Cookie有		
	  3. session数据安全，Cookie相对于不安全

