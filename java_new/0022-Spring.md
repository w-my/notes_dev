# Spring



## Spring概述

#### Spring是什么

Spring是分层的 Java SE/EE应用 full-stack 轻量级开源框架，以 IOC（Inverse Of Control：反转控制）和 AOP（Aspect Oriented Programming：面向切面编程）为内核。

提供了展现层 SpringMVC 和持久层 Spring JDBCTemplate 以及业务层事务管理等众多的企业级应用技术，还能整合开源世界众多著名的第三方框架和类库，逐渐成为使用最多的 Java EE 企业应用开源框架。

#### Spring的优势

方便解耦，简化开发

AOP 编程的支持

声明式事务的支持

方便程序的测试

#### Spring的体系结构

<img src="./img/0022-SpringFrameworkRuntime.png" alt="SpringFrameworkRuntime" />



## Maven 项目创建

1. 在系统目录下创建文件夹 `Spring`
2. 打开IDEA，选择 `文件`，打开创建的文件夹
3. 打开后选中项目目录，右键 `New` -> `Module...` -> `Maven` -> `Next`
4. Groupid 输入 `com.xxx` ，Artifactid 输入 `xx_spring_aop`
5. 选中 `xx_spring_aop` ，选择菜单栏 `文件` -> `Product Structure...` 
6. `Project` 选择需要的 `Project SDK` ，选择需要的 `Project language level` ，修改 `Project compiler output` 后部路径：`.../Spring/xx_spring_aop`
7. `Facets` 点击 `+` ，选择 `Web` ，选择 `xx_spring_aop` 点击 OK
8. 修改 Type 后部路径：`.../Spring/xx_spring_aop/src/main/webapp/WEB-INF/web.xml`
9. 修改 `Web Resource Directory` 后部路径 ：`.../Spring/xx_spring_aop/src/main/webapp`
10. 最后点击 `Apply` 完成 `OK`
11. 重复3-10，同理创建 `xx_spring_ioc`



## Spring快速入门

#### Spring程序开发步骤 

1. 导入 Spring 开发的基本包坐标
2. 编写 Dao 接口和实现类
3. 创建 Spring 核心配置文件
4. 在 Spring 配置文件中配置 UserDaoImpl
5. 使用 Spring 的 API 获得 Bean 实例

#### 导入Spring开发的基本包坐标

```xml
<properties>
  	<spring.version>5.0.5.RELEASE</spring.version>
</properties>
<!-- 导入spring的context坐标，context依赖core、beans、expression -->
<dependencies> 
    <dependency>  
        <groupId>org.springframework</groupId> 
        <artifactId>spring-context</artifactId> 
        <version>${spring.version}</version>
    </dependency>
</dependencies>
```

#### 编写Dao接口和实现类

```java
public interface UserDao {
    public void save();
}

public class UserDaoImpl implements UserDao {
    @Override
    public void save() {
        System.out.println("userdao save running...");
    }
}
```

#### 创建Spring核心配置文件

在类路径下（resources）创建 `applicationContext.xml` 配置文件

```xml
<?xml version="1.0" encoding="UTF-8" ?>
<beans xmlns="http://www.springframework.org/schema/beans"
       xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
       xsi:schemaLocation="http://www.springframework.org/schema/beans
                    http://www.springframework.org/schema/beans/spring-beans.xsd">
</beans>
```

#### 在Spring配置文件中配置UserDaoImpl

```xml
<?xml version="1.0" encoding="UTF-8" ?>
<beans xmlns="http://www.springframework.org/schema/beans"
       xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
       xsi:schemaLocation="http://www.springframework.org/schema/beans
                           http://www.springframework.org/schema/beans/spring-beans.xsd">
   <bean id="userDao" class="com.itheima.dao.impl.UserDaoImpl"></bean>
</beans>
```

#### 使用Spring的API获得Bean实例

```java
@Test
public void test1() {
	ApplicationContext applicationContext = new ClassPathXmlApplicationContext("applicationContext.xml");
  UserDao userDao = (UserDao) applicationContext.getBean("userDao");
  userDao.save();
}
```



## Spring配置文件

#### Bean标签基本配置 

用于配置对象交由 Spring 来创建。

默认情况下它调用的是类中的无参构造函数，如果没有无参构造函数则不能创建成功。

基本属性：

id：Bean实例在Spring容器中的唯一标识

class：Bean的全限定名称

#### Bean标签范围配置 

scope：指对象的作用范围，取值如下： 

| 取值范围       | 说明                                                         |
| -------------- | ------------------------------------------------------------ |
| singleton      | 默认值，单例的                                               |
| prototype      | 多例的                                                       |
| request        | WEB 项目中，Spring 创建一个 Bean 的对象，将对象存入到 request 域中 |
| session        | WEB 项目中，Spring 创建一个 Bean 的对象，将对象存入到 session 域中 |
| global session | WEB 项目中，应用在 Portlet 环境，如果没有 Portlet 环境那么 globalSession 相当于 session |

1. 当scope的取值为singleton时

​      Bean的实例化个数：1个

​      Bean的实例化时机：当Spring核心文件被加载时，实例化配置的Bean实例

​      Bean的生命周期：

对象创建：当应用加载，创建容器时，对象就被创建了

对象运行：只要容器在，对象一直活着

对象销毁：当应用卸载，销毁容器时，对象就被销毁了

2. 当scope的取值为prototype时

​      Bean的实例化个数：多个

​      Bean的实例化时机：当调用getBean()方法时实例化Bean

对象创建：当使用对象时，创建新的对象实例

对象运行：只要对象在使用中，就一直活着

对象销毁：当对象长时间不用时，被 Java 的垃圾回收器回收了

#### Bean生命周期配置

init-method：指定类中的初始化方法名称

destroy-method：指定类中销毁方法名称

#### Bean实例化三种方式

1. 使用无参构造方法实例化

​      它会根据默认无参构造方法来创建类对象，如果bean中没有默认无参构造函数，将会创建失败

```xml
<bean id="userDao" class="com.xxx.dao.impl.UserDaoImpl"/>
```

2. 工厂静态方法实例化

​      工厂的静态方法返回Bean实例

```java
public class StaticFactoryBean {
	public static UserDao createUserDao(){    
		return new UserDaoImpl();
	}
}
```

```xml
<bean id="userDao" class="com.xxx.factory.StaticFactoryBean" factory-method="createUserDao" />
```

3. 工厂实例方法实例化

​      工厂的非静态方法返回Bean实例

```java
public class DynamicFactoryBean {  
	public UserDao createUserDao() {        
		return new UserDaoImpl(); 
	}
}
```

```xml
<bean id="factoryBean" class="com.xxx.factory.DynamicFactoryBean"/>
<bean id="userDao" factory-bean="factoryBean" factory-method="createUserDao"/>
```

#### Bean的依赖注入入门

1. 创建 UserService，UserService 内部在调用 UserDao的save() 方法

```java
public class UserServiceImpl implements UserService {
	@Override
	public void save() {
		ApplicationContext app = new ClassPathXmlApplicationContext("applicationContext.xml");
    UserDao userDao = (UserDao) app.getBean("userDao");	
		userDao.save();
	}
}
```

2. 将 UserServiceImpl 的创建权交给 Spring

```xml
<bean id="userService" class="com.xxx.service.impl.UserServiceImpl"/>
```

3. 从 Spring 容器中获得 UserService 进行操作

```java
ApplicationContext app = new ClassPathXmlApplicationContext("applicationContext.xml");
UserService userService = (UserService) app.getBean("userService");
userService.save();
```

#### Bean的依赖注入概念

依赖注入（Dependency Injection）：它是 Spring 框架核心 IOC 的具体实现。

在编写程序时，通过控制反转，把对象的创建交给了 Spring，但是代码中不可能出现没有依赖的情况。

IOC 解耦只是降低他们的依赖关系，但不会消除。例如：业务层仍会调用持久层的方法。

那这种业务层和持久层的依赖关系，在使用 Spring 之后，就让 Spring 来维护了。

简单的说，就是坐等框架把持久层对象传入业务层，而不用我们自己去获取

#### Bean的依赖注入方式

1. 构造方法

​      创建有参构造

```java
public class UserServiceImpl implements UserService {
    private UserDao userDao;

    public UserServiceImpl(UserDao userDao) {
        this.userDao = userDao;
    }
    public UserServiceImpl() {
    }

    @Override
    public void save() {
        userDao.save();
    }
}
```

​      配置Spring容器调用有参构造时进行注入

```xml
<bean id="userDao" class="com.xxx.dao.impl.UserDaoImpl"/>
<bean id="userService" class="com.xxx.service.impl.UserServiceImpl">
  <constructor-arg name="userDao" ref="userDao"></constructor-arg>
</bean>
```

2. set方法

​      在UserServiceImpl中添加setUserDao方法

```java
public class UserServiceImpl implements UserService {
    private UserDao userDao;
    public void setUserDao(UserDao userDao) {
        this.userDao = userDao;
    }
    @Override
    public void save() {
        userDao.save();
    }
}
```

​      配置Spring容器调用set方法进行注入

```xml
<bean id="userDao" class="com.xxx.dao.impl.UserDaoImpl"/>
<bean id="userService" class="com.xxx.service.impl.UserServiceImpl">
	<property name="userDao" ref="userDao"/>
</bean>
```

set方法:P命名空间注入

​      P命名空间注入本质也是set方法注入，但比起上述的set方法注入更加方便，主要体现在配置文件中，如下：

​      首先，需要引入P命名空间：

```xml
xmlns:p="http://www.springframework.org/schema/p"
```

其次，需要修改注入方式

```xml
<bean id="userService" class="com.xxx.service.impl.UserServiceImpl" p:userDao-ref="userDao"/>
```

#### Bean的依赖注入的数据类型

上面的操作，都是注入的引用Bean，处了对象的引用可以注入，普通数据类型，集合等都可以在容器中进行注入。

注入数据的三种数据类型 

普通数据类型

引用数据类型

集合数据类型

其中引用数据类型，此处就不再赘述了，之前的操作都是对UserDao对象的引用进行注入的，下面将以set方法注入为例，演示普通数据类型和集合数据类型的注入。

**Bean的依赖注入的数据类型**

1. 普通数据类型的注入

```java
public class UserDaoImpl implements UserDao {
private String company;
	private int age;
	public void setCompany(String company) {
		this.company = company;
	}
	public void setAge(int age) {
		this.age = age;
	}
	public void save() {
		System.out.println(company+"==="+age);
		System.out.println("UserDao save method running....");   
	}
}
```

```xml
<bean id="userDao" class="com.xxx.dao.impl.UserDaoImpl">
    <property name="company" value="啦啦啦"></property>
    <property name="age" value="15"></property>
</bean>
```

2. 集合数据类型 `List<String>` 的注入

```java
public class UserDaoImpl implements UserDao {
	private List<String> strList;
	public void setStrList(List<String> strList) {
		this.strList = strList;
	}
	public void save() {
		System.out.println(strList);
		System.out.println("UserDao save method running....");
	}
}
```

```xml
<bean id="userDao" class="com.xxx.dao.impl.UserDaoImpl">
  <property name="strList">
    <list>
      <value>aaa</value>
      <value>bbb</value>
      <value>ccc</value>
    </list>
  </property>
</bean>
```

3. 集合数据类型 `List<User>` 的注入

```java
public class UserDaoImpl implements UserDao {
	private List<User> userList;
	public void setUserList(List<User> userList) {
		this.userList = userList;  
	}
	public void save() {
    System.out.println(userList);
    System.out.println("UserDao save method running....");
	}
}
```

```xml
<bean id="u1" class="com.xxx.domain.User"/>
<bean id="u2" class="com.xxx.domain.User"/>
<bean id="userDao" class="com.xxx.dao.impl.UserDaoImpl">
  <property name="userList">
    <list>
      <bean class="com.xxx.domain.User"/>
      <bean class="com.xxx.domain.User"/>
      <ref bean="u1"/>
      <ref bean="u2"/>       
    </list>
  </property>
</bean>
```

4. 集合数据类型 `Map<String,User>` 的注入

```java
public class UserDaoImpl implements UserDao {
  private Map<String,User> userMap;
  public void setUserMap(Map<String, User> userMap) {
  	this.userMap = userMap;
  }    
  public void save() {      
    System.out.println(userMap);
    System.out.println("UserDao save method running....");
  }
}
```

```xml
<bean id="u1" class="com.xxx.domain.User"/>
<bean id="u2" class="com.xxx.domain.User"/>
<bean id="userDao" class="com.xxx.dao.impl.UserDaoImpl">
    <property name="userMap">
        <map>            
            <entry key="user1" value-ref="u1"/>
            <entry key="user2" value-ref="u2"/>
        </map>
    </property>
</bean>
```

5. 集合数据类型 `Properties` 的注入

```java
public class UserDaoImpl implements UserDao {
  private Properties properties;
  public void setProperties(Properties properties) {
  	this.properties = properties;
  }
	public void save() {
		System.out.println(properties);
		System.out.println("UserDao save method running....");
	}
}
```

```xml
<bean id="userDao" class="com.xxx.dao.impl.UserDaoImpl">
  <property name="properties">
    <props>
      <prop key="p1">aaa</prop>
      <prop key="p2">bbb</prop> 
      <prop key="p3">ccc</prop>
    </props>
  </property>
</bean>
```

#### 引入其他配置文件（分模块开发）

实际开发中，Spring 的配置内容非常多，这就导致 Spring 配置很繁杂且体积很大，所以，可以将部分配置拆解到其他配置文件中，而在 Spring 主配置文件通过 import 标签进行加载

```java
<import resource="applicationContext-xxx.xml"/>
```

#### Spring的重点配置

```xml
<bean>标签
    id属性：在容器中Bean实例的唯一标识，不允许重复
    class属性：要实例化的Bean的全限定名
    scope属性：Bean的作用范围，常用是Singleton（默认）和prototype
    <property>标签，属性注入
        name属性：属性名称
        value属性：注入的普通属性值
        ref属性：注入的对象引用值
        <list>标签
        <map>标签
        <properties>标签
    <constructor-arg>标签
<import>标签：导入其他Spring的分文件
```



## Spring相关API

#### ApplicationContext的继承体系

applicationContext：接口类型，代表应用上下文，可以通过其实例获得 Spring 容器中的 Bean 对象

#### ApplicationContext的实现类

1. `ClassPathXmlApplicationContext `

​      它是从类的根路径下加载配置文件，推荐使用这种

2. `FileSystemXmlApplicationContext `

​      它是从磁盘路径上加载配置文件，配置文件可以在磁盘的任意位置。

3. `AnnotationConfigApplicationContext`

​      当使用注解配置容器对象时，需要使用此类来创建 spring 容器。它用来读取注解。

#### getBean()方法使用

```java
public Object getBean(String name) throws BeansException {  
	assertBeanFactoryActive();   
	return getBeanFactory().getBean(name);
}
public <T> T getBean(Class<T> requiredType) throws BeansException {
  assertBeanFactoryActive();
	return getBeanFactory().getBean(requiredType);
}
```

其中，当参数的数据类型是字符串时，表示根据Bean的id从容器中获得Bean实例，返回是Object，需要强转。

当参数的数据类型是Class类型时，表示根据类型从容器中匹配Bean实例，当容器中相同类型的Bean有多个时，则此方法会报错

**getBean()方法使用**

```java
ApplicationContext app = new ClassPathXmlApplicationContext("applicationContext.xml");
UserService userService1 = (UserService) app.getBean("userService");
UserService userService2 = app.getBean(UserService.class);
```



## Spring配置数据源

#### 数据源（连接池）的作用 

数据源(连接池)是提高程序性能如出现的

事先实例化数据源，初始化部分连接资源

使用连接资源时从数据源中获取

使用完毕后将连接资源归还给数据源

常见的数据源(连接池)：DBCP、C3P0、BoneCP、Druid等

**开发步骤**

1. 导入数据源的坐标和数据库驱动坐标
2. 创建数据源对象
3. 设置数据源的基本连接数据
4. 使用数据源获取连接资源和归还连接资源

#### 数据源的手动创建

1. 导入

```xml
<!-- C3P0连接池 -->
<dependency>
    <groupId>c3p0</groupId>
    <artifactId>c3p0</artifactId>
    <version>0.9.1.2</version>
</dependency>
<!-- Druid连接池 -->
<dependency>
    <groupId>com.alibaba</groupId>
    <artifactId>druid</artifactId>
    <version>1.1.10</version>
</dependency>
<!-- mysql驱动 -->
<dependency>
    <groupId>mysql</groupId>
    <artifactId>mysql-connector-java</artifactId>
    <version>5.1.39</version>
</dependency>
```

2. 创建C3P0连接池

```java
@Test
public void testC3P0() throws Exception {
    DruidDataSource dataSource = new DruidDataSource();
    dataSource.setDriverClassName("com.mysql.jdbc.Driver");
    dataSource.setUrl("jdbc:mysql://localhost:3306/db1");
    dataSource.setUsername("root");
    dataSource.setPassword("root");
    DruidPooledConnection connection = dataSource.getConnection();
    System.out.println(connection);
    connection.close();
}
```

2. 创建Druid连接池

```java
@Test
public void testDruid() throws Exception {
    ComboPooledDataSource dataSource = new ComboPooledDataSource();
    dataSource.setDriverClass("com.mysql.jdbc.Driver");
    dataSource.setJdbcUrl("jdbc:mysql://localhost:3306/db1");
    dataSource.setUser("root");
    dataSource.setPassword("root");
    Connection connection = dataSource.getConnection();
    System.out.println(connection);
    connection.close();
}
```

3. 提取 `jdbc.properties` 配置文件

```properties
jdbc.driver=com.mysql.jdbc.Driver
jdbc.url=jdbc:mysql://localhost:3306/db1
jdbc.username=root
jdbc.password=root
```

4. 读取 `jdbc.properties` 配置文件创建连接池

```java
@Test
public void testC3P0ByProperties() throws Exception {
    //加载类路径下的jdbc.properties
    ResourceBundle rb = ResourceBundle.getBundle("jdbc");
    ComboPooledDataSource dataSource = new ComboPooledDataSource(); 
    dataSource.setDriverClass(rb.getString("jdbc.driver"));   
    dataSource.setJdbcUrl(rb.getString("jdbc.url")); 
    dataSource.setUser(rb.getString("jdbc.username")); 
    dataSource.setPassword(rb.getString("jdbc.password"));
    Connection connection = dataSource.getConnection();   
    System.out.println(connection);
}
```

#### Spring配置数据源

可以将DataSource的创建权交由Spring容器去完成

DataSource有无参构造方法，而Spring默认就是通过无参构造方法实例化对象的

DataSource要想使用需要通过set方法设置数据库连接信息，而Spring可以通过set方法进行字符串注入

```xml
<bean id="dataSource" class="com.mchange.v2.c3p0.ComboPooledDataSource">
    <property name="driverClass" value="com.mysql.jdbc.Driver"/>
    <property name="jdbcUrl" value="jdbc:mysql://localhost:3306/db1"/>
    <property name="user" value="root"/>
    <property name="password" value="12345678"/>
</bean>
```

测试从容器当中获取数据源

```java
@Test
public void test() throws Exception {
    ApplicationContext app = new ClassPathXmlApplicationContext("applicationContext.xml");
    DataSource dataSource = (DataSource) app.getBean("dataSource");
    Connection connection = dataSource.getConnection();
    System.out.println(connection);
    connection.close();
}
```

#### 抽取jdbc配置文件

`applicationContext.xml` 加载 `jdbc.properties` 配置文件获得连接信息。

首先，需要引入context命名空间和约束路径：

命名空间：`xmlns:context="http://www.springframework.org/schema/context"`

约束路径：`xsi:schemaLocation` 中添加

​		`http://www.springframework.org/schema/context`  

​		`http://www.springframework.org/schema/context/spring-context.xsd`

```xml
<?xml version="1.0" encoding="UTF-8"?>
<beans xmlns="http://www.springframework.org/schema/beans"
       xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
       xmlns:context="http://www.springframework.org/schema/context"
       xsi:schemaLocation="http://www.springframework.org/schema/beans
       http://www.springframework.org/schema/beans/spring-beans.xsd
       http://www.springframework.org/schema/context
       http://www.springframework.org/schema/context/spring-context.xsd">

    <!-- 加载外部properties文件 -->
    <context:property-placeholder location="classpath:jdbc.properties" />

    <bean id="dataSource" class="com.mchange.v2.c3p0.ComboPooledDataSource">
        <property name="driverClass" value="${jdbc.driver}" />
        <property name="jdbcUrl" value="${jdbc.url}" />
        <property name="user" value="${jdbc.username}" />
        <property name="password" value="${jdbc.password}" />
    </bean>

</beans>
```

#### 知识要点 

Spring容器加载properties文件

```xml
<context:property-placeholder location="xx.properties"/><property name="" value="${key}"/>
```

## Spring注解开发

#### Spring原始注解

Spring是轻代码而重配置的框架，配置比较繁重，影响开发效率，所以注解开发是一种趋势，注解代替xml配置文件可以简化配置，提高开发效率。 

Spring原始注解主要是替代<Bean>的配置

| 注解           | 说明                                           |
| -------------- | ---------------------------------------------- |
| @Component     | 使用在类上用于实例化Bean                       |
| @Controller    | 使用在web层类上用于实例化Bean                  |
| @Service       | 使用在service层类上用于实例化Bean              |
| @Repository    | 使用在dao层类上用于实例化Bean                  |
| @Autowired     | 使用在字段上用于根据类型依赖注入               |
| @Qualifier     | 结合@Autowired一起使用用于根据名称进行依赖注入 |
| @Resource      | 相当于@Autowired+@Qualifier，按照名称进行注入  |
| @Value         | 注入普通属性                                   |
| @Scope         | 标注Bean的作用范围                             |
| @PostConstruct | 使用在方法上标注该方法是Bean的初始化方法       |
| @PreDestroy    | 使用在方法上标注该方法是Bean的销毁方法         |

注意：

使用注解进行开发时，需要在 `applicationContext.xml` 中配置组件扫描，作用是指定哪个包及其子包下的Bean需要进行扫描以便识别使用注解配置的类、字段和方法。

```xml
<!--注解的组件扫描-->
<context:component-scan base-package="com.xx"></context:component-scan>
```

使用@Compont或@Repository标识UserDaoImpl需要Spring进行实例化。

```java
@Repository("userDao")
public class UserDaoImpl implements UserDao {    
  @Override    
  public void save() {    	
    System.out.println("save running... ...");
  }
}
```

使用@Compont或@Service标识UserServiceImpl需要Spring进行实例化

使用@Autowired或者@Autowired+@Qulifier或者@Resource进行userDao的注入

```java
@Service("userService")
public class UserServiceImpl implements UserService {    
  /*
  @Autowired    
  @Qualifier("userDao")
  */    
  @Resource(name="userDao")    
  private UserDao userDao;    
  @Override    
  public void save() {          	  
    userDao.save();    
  }
}
```

使用@Value进行字符串的注入

```java
@Repository("userDao")
public class UserDaoImpl implements UserDao {    

  @Value("${jdbc.driver}")    
  private String driver; 
  
  @Override    
  public void save() {        
    System.out.println(str);        
    System.out.println(driver);        
    System.out.println("save running... ...");    
  }
}
```

使用@Scope标注Bean的范围

```java
//@Scope("prototype")
@Scope("singleton")
public class UserDaoImpl implements UserDao {
  // 此处省略代码
}
```

使用@PostConstruct标注初始化方法，使用@PreDestroy标注销毁方法

```java
@PostConstructpublic 
void init() {	
  System.out.println("初始化方法....");
}
@PreDestroypublic 
void destroy() {	
  System.out.println("销毁方法.....");
}
```



#### Spring新注解

使用上面的注解还不能全部替代xml配置文件，还需要使用注解替代的配置如下：

非自定义的Bean的配置：`<bean>`

加载properties文件的配置：`<context:property-placeholder>`

组件扫描的配置：`<context:component-scan>`

引入其他文件：`<import>`

| 注解            | 说明                                                         |
| --------------- | ------------------------------------------------------------ |
| @Configuration  | 用于指定当前类是一个 Spring 配置类，当创建容器时会从该类上加载注解 |
| @ComponentScan  | 用于指定 Spring   在初始化容器时要扫描的包。作用和在 Spring 的 xml 配置文件中的 <context:component-scan base-package="com.xx"/>一样 |
| @Bean           | 使用在方法上，标注将该方法的返回值存储到 Spring 容器中       |
| @PropertySource | 用于加载 .properties 文件中的配置                            |
| @Import         | 用于导入其他配置类                                           |

`@Configuration`

`@ComponentScan`

`@Import`

```java
@Configuration
@ComponentScan("com.xx")
@Import({DataSourceConfiguration.class})
public class SpringConfiguration {}
```

`@PropertySource`

`@value`

`@Bean`

```java
@PropertySource("classpath:jdbc.properties")
public class DataSourceConfiguration {    
  @Value("${jdbc.driver}")    
  private String driver;    
  @Value("${jdbc.url}")    
  private String url;    
  @Value("${jdbc.username}")    
  private String username;    
  @Value("${jdbc.password}")    
  private String password;
  
  @Bean(name="dataSource")
  public DataSource getDataSource() throws PropertyVetoException {     
    ComboPooledDataSource dataSource = new ComboPooledDataSource();     
    dataSource.setDriverClass(driver);    
    dataSource.setJdbcUrl(url);    
    dataSource.setUser(username);    
    dataSource.setPassword(password);    
    return dataSource;
  } 
}
```

测试加载核心配置类创建Spring容器

```java
@Testpublic 
void testAnnoConfiguration() throws Exception {
  ApplicationContext app = new AnnotationConfigApplicationContext(SpringConfiguration.class);    
  UserService userService = (UserService) app.getBean("userService");    
  userService.save();    
  
  DataSource dataSource = (DataSource) app.getBean("dataSource");    
  Connection connection = dataSource.getConnection();     
  System.out.println(connection);    
  connection.close();
}
```



## Spring整合Junit

#### 原始Junit测试Spring的问题

在测试类中，每个测试方法都有以下两行代码：

```java
ApplicationContext ac = new ClassPathXmlApplicationContext("bean.xml"); 
IAccountService as = ac.getBean("accountService",IAccountService.class);
```

这两行代码的作用是获取容器，如果不写的话，直接会提示空指针异常。所以又不能轻易删掉。

#### 上述问题解决思路

让 SpringJunit 负责创建 Spring 容器，但是需要将配置文件的名称告诉它

将需要进行测试 Bean 直接在测试类中进行注入

#### Spring集成Junit步骤

1. 导入spring集成Junit的坐标
2. 使用@Runwith注解替换原来的运行期
3. 使用@ContextConfiguration指定配置文件或配置类
4. 使用@Autowired注入需要测试的对象
5. 创建测试方法进行测试

#### Spring集成Junit代码实现

1. 导入spring集成Junit的坐标

```xml
<!--此处需要注意的是，spring5 及以上版本要求 junit 的版本必须是 4.12 及以上-->
<dependency>    
  <groupId>org.springframework</groupId>    
  <artifactId>spring-test</artifactId>    
  <version>5.0.2.RELEASE</version>
</dependency>
<dependency>    
  <groupId>junit</groupId>    
  <artifactId>junit</artifactId>    
  <version>4.12</version>    
  <scope>test</scope>
</dependency>
```

2. 使用@Runwith注解替换原来的运行期

```java
@RunWith(SpringJUnit4ClassRunner.class)
public class SpringJunitTest {}
```

3. 使用@ContextConfiguration指定配置文件或配置类

```java
@RunWith(SpringJUnit4ClassRunner.class)//加载spring核心配置文件
//@ContextConfiguration(value = {"classpath:applicationContext.xml"})//加载spring核心配置类
@ContextConfiguration(classes = {SpringConfiguration.class})
public class SpringJunitTest {}
```

4. 使用@Autowired注入需要测试的对象

```java
@RunWith(SpringJUnit4ClassRunner.class)
@ContextConfiguration(classes = {SpringConfiguration.class})
public class SpringJunitTest {    
  @Autowired    
  private UserService userService;
}
```

5. 创建测试方法进行测试

```java
@RunWith(SpringJUnit4ClassRunner.class)
@ContextConfiguration(classes = {SpringConfiguration.class})
public class SpringJunitTest {    
  @Autowired    
  private UserService userService;    
  @Test    
  public void testUserService() {   	 
    userService.save();    
  }
}
```

Spring集成Junit步骤

1. 导入spring集成Junit的坐标 
2. 使用@Runwith注解替换原来的运行期
3. 使用@ContextConfiguration指定配置文件或配置类
4. 使用@Autowired注入需要测试的对象
5. 创建测试方法进行测试



# Spring 的 AOP

## 什么是 AOP

AOP 为 Aspect Oriented Programming 的缩写，意思为面向切面编程，是通过预编译方式和运行期动态代理实现程序功能的统一维护的一种技术。

AOP 是 OOP 的延续，是软件开发中的一个热点，也是Spring框架中的一个重要内容，是函数式编程的一种衍生范型。利用AOP可以对业务逻辑的各个部分进行隔离，从而使得业务逻辑各部分之间的耦合度降低，提高程序的可重用性，同时提高了开发的效率。

#### AOP 的作用及其优势

作用：在程序运行期间，在不修改源码的情况下对方法进行功能增强

优势：减少重复代码，提高开发效率，并且便于维护

#### AOP 的底层实现

实际上，AOP 的底层是通过 Spring 提供的的动态代理技术实现的。在运行期间，Spring通过动态代理技术动态的生成代理对象，代理对象方法执行时进行增强功能的介入，在去调用目标对象的方法，从而完成功能的增强。

#### AOP 的动态代理技术

常用的动态代理技术

JDK 代理 : 基于接口的动态代理技术

cglib 代理：基于父类的动态代理技术

![AOP的动态代理技术](./img/0022-AOP的动态代理技术.png)

#### JDK 的动态代理

1. 目标类接口

```java
public interface TargetInterface {
    public void method();
}
```

2. 目标类

```java
public class Target implements TargetInterface {
    @Override
    public void method() {
        System.out.println("Target running....");
    }
}
```

​	增强类

```java
public class Advice {
    public void before() {
        System.out.println("前置增强");
    }
    public void after() {
        System.out.println("后置增强");
    }
}
```

3. 动态代理代码

```java
public class ProxyTest {
    public static void main(String[] args) {
	      // 创建目标对象
        final Target target = new Target();
        // 增强类
        final Advice advice = new Advice();
				// 创建代理对象
        TargetInterface proxy = (TargetInterface) Proxy.newProxyInstance(target.getClass().getClassLoader(),
                target.getClass().getInterfaces(),
                new InvocationHandler() {
                    public Object invoke(Object proxy, Method method, Object[] args) throws Throwable {
                        advice.before();
                        Object invoke = method.invoke(target, args);
                        advice.after();
                        return invoke;
                    }
                });

        proxy.save();
    }
}
```

4. 调用代理对象的方法测试

```java
// 测试,当调用接口的任何方法时，代理对象的代码都无序修改
proxy.method();
```

```
前置增强
Target running...
后置增强
```

#### cglib 的动态代理

1. 目标类

```java
public class Target {
    public void method() {
        System.out.println("Target running....");
    }
}
```

​	增强类

```java
public class Advice {
    public void before() {
        System.out.println("前置增强");
    }
    public void after() {
        System.out.println("后置增强");
    }
}
```

2. 动态代理代码

```java
public class ProxyTest {
    public static void main(String[] args) {
		    // 创建目标对象
        final Target target = new Target();
      	// 增强类
        final Advice advice = new Advice();
				// 创建增强器
        Enhancer enhancer = new Enhancer();
      	// 设置父类
        enhancer.setSuperclass(Target.class);
      	// 设置回调
        enhancer.setCallback(new MethodInterceptor() {
            public Object intercept(Object o, Method method, Object[] objects, MethodProxy methodProxy) throws Throwable {
                advice.before();
                Object invoke = method.invoke(target, objects);
                advice.after();
                return invoke;
            }
        });
      	// 创建代理对象
        Target proxy = (Target) enhancer.create();
        proxy.save();
    }
}
```

3. 调用代理对象的方法测试

```java
// 测试,当调用接口的任何方法时，代理对象的代码都无序修改
proxy.method();
```

```
前置增强
save running...
后置增强
```

#### AOP 相关概念

Spring 的 AOP 实现底层就是对上面的动态代理的代码进行了封装，封装后我们只需要对需要关注的部分进行代码编写，并通过配置的方式完成指定目标的方法增强。

AOP 的相关术语：

- Target（目标对象）：代理的目标对象
- Proxy （代理）：一个类被 AOP 织入增强后，就产生一个结果代理类
- Joinpoint（连接点）：所谓连接点是指那些被拦截到的点。在spring中，这些点指的是方法，因为spring只支持方法类型的连接点
- Pointcut（切入点）：所谓切入点是指我们要对哪些 Joinpoint 进行拦截的定义
- Advice（通知/增强）：所谓通知是指拦截到 Joinpoint 之后所要做的事情就是通知
- Aspect（切面）：是切入点和通知（引介）的结合
- Weaving（织入）：是指把增强应用到目标对象来创建新的代理对象的过程。spring采用动态代理织入，而AspectJ采用编译期织入和类装载期织入

#### AOP 开发明确的事项

##### 需要编写的内容

- 编写核心业务代码（目标类的目标方法）
- 编写切面类，切面类中有通知(增强功能方法)
- 在配置文件中，配置织入关系，即将哪些通知与哪些连接点进行结合

##### AOP 技术实现的内容

Spring 框架监控切入点方法的执行。一旦监控到切入点方法被运行，使用代理机制，动态创建目标对象的代理对象，根据通知类别，在代理对象的对应位置，将通知对应的功能织入，完成完整的代码逻辑运行。

##### AOP 底层使用哪种代理方式

在 spring 中，框架会根据目标类是否实现了接口来决定采用哪种动态代理的方式。

#### 知识要点

- aop：面向切面编程

- aop底层实现：基于JDK的动态代理 和 基于Cglib的动态代理

- aop的重点概念：

  ```
  Pointcut（切入点）：被增强的方法
  Advice（通知/增强）：封装增强业务逻辑的方法
  Aspect（切面）：切点+通知
  Weaving（织入）：将切点与通知结合的过程
  ```

- 开发明确事项：

  ```
  谁是切点（切点表达式配置）
  谁是通知（切面类中的增强方法）
  将切点和通知进行织入配置
  ```

## 基于 XML 的 AOP 开发

#### 快速入门

1. 导入 AOP 相关坐标

2. 创建目标接口和目标类（内部有切点）

3. 创建切面类（内部有增强方法）

4. 将目标类和切面类的对象创建权交给 spring

5. 在 applicationContext.xml 中配置织入关系

6. 测试代码



1. 导入 AOP 相关坐标

```xml
<!-- 导入spring的context坐标，context依赖aop -->
<dependency>
  <groupId>org.springframework</groupId>
  <artifactId>spring-context</artifactId>
  <version>5.0.5.RELEASE</version>
</dependency>
<!-- aspectj的织入 -->
<dependency>
  <groupId>org.aspectj</groupId>
  <artifactId>aspectjweaver</artifactId>
  <version>1.8.13</version>
</dependency>
```

2. 创建目标接口和目标类（内部有切点）

```java
public interface TargetInterface {
    public void method();
}

public class Target implements TargetInterface {
    @Override
    public void method() {
        System.out.println("Target running...");
    }
}
```

3. 创建切面类（内部有增强方法）

```java
public class MyAspect {
    public void before(){
        System.out.println("前置代码增强...");
    }
}
```

4. 将目标类和切面类的对象创建权交给 spring

```xml
<!-- 配置目标类 -->
<bean id="target" class="com.itheima.aop.Target"></bean>
<!-- 配置切面类 -->
<bean id="myAspect" class="com.itheima.aop.MyAspect"></bean>
```

5. 在 `applicationContext.xml` 中配置织入关系

   导入aop命名空间

```xml
<beans xmlns="http://www.springframework.org/schema/beans"
       xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
       xmlns:context="http://www.springframework.org/schema/context"
       xmlns:aop="http://www.springframework.org/schema/aop"
       xsi:schemaLocation="
        http://www.springframework.org/schema/context
        http://www.springframework.org/schema/context/spring-context.xsd
        http://www.springframework.org/schema/aop
        http://www.springframework.org/schema/aop/spring-aop.xsd
        http://www.springframework.org/schema/beans
        http://www.springframework.org/schema/beans/spring-beans.xsd">
```

5. 在 `applicationContext.xml` 中配置织入关系

   配置切点表达式和前置增强的织入关系

```xml
<aop:config>
    <!--引用myAspect的Bean为切面对象-->
    <aop:aspect ref="myAspect">
        <!--配置Target的method方法执行时要进行myAspect的before方法前置增强-->
        <aop:before method="before" pointcut="execution(public void com.xx.aop.Target.method())" />
    </aop:aspect>
</aop:config>
```

6. 测试代码

```java
@RunWith(SpringJUnit4ClassRunner.class)
@ContextConfiguration("classpath:applicationContext.xml")
public class AopTest {
    @Autowired
    private TargetInterface target;
    @Test
    public void test1(){
        target.method();
    }
}
```

7. 测试结果

```
前置代码增强...
Target running...
```

#### XML 配置 AOP 详解

##### 切点表达式的写法

表达式语法：

```xml
execution([修饰符] 返回值类型 包名.类名.方法名(参数))
```

- 访问修饰符可以省略
- 返回值类型、包名、类名、方法名可以使用星号*  代表任意
- 包名与类名之间一个点 . 代表当前包下的类，两个点 .. 表示当前包及其子包下的类
- 参数列表可以使用两个点 .. 表示任意个数，任意类型的参数列表

例如：

```xml
execution(public void com.itheima.aop.Target.method())  
execution(void com.itheima.aop.Target.*(..))
execution(* com.itheima.aop.*.*(..))
execution(* com.itheima.aop..*.*(..))
execution(* *..*.*(..))
```

##### 通知的类型

通知的配置语法：

```xml
<aop:通知类型 method=“切面类中方法名” pointcut=“切点表达式"></aop:通知类型>
```

| 名称         | 标签                    | 说明                                                     |
| ------------ | ----------------------- | -------------------------------------------------------- |
| 前置通知     | `<aop:before>`          | 配置前置通知。指定增强的方法在切入点方法之前执行         |
| 后置通知     | `<aop:after-returning>` | 配置后置通知。指定增强的方法在切入点方法之后执行         |
| 环绕通知     | `<aop:around>`          | 配置环绕通知。指定增强的方法在切入点方法之前和之后都执行 |
| 异常抛出通知 | `<aop:throwing>`        | 配置异常抛出通知。指定增强的方法在出现异常时执行         |
| 最终通知     | `<aop:after>`           | 配置最终通知。无论增强方法执行是否有异常都会执行         |

##### 切点表达式的抽取

当多个增强的切点表达式相同时，可以将切点表达式进行抽取，在增强中使用 pointcut-ref 属性代替 pointcut 属性来引用抽取后的切点表达式。

```xml
<aop:config>
    <!--引用myAspect的Bean为切面对象-->
    <aop:aspect ref="myAspect">
        <aop:pointcut id="myPointcut" expression="execution(* com.itheima.aop.*.*(..))"/>
        <aop:before method="before" pointcut-ref="myPointcut"></aop:before>
    </aop:aspect>
</aop:config>
```

#### 知识要点

- aop织入的配置

```xml
<aop:config>
    <aop:aspect ref=“切面类”>
        <aop:before method=“通知方法名称” pointcut=“切点表达式"></aop:before>
    </aop:aspect>
</aop:config>
```

- 通知的类型：前置通知、后置通知、环绕通知、异常抛出通知、最终通知
- 切点表达式的写法：

```xml
execution([修饰符] 返回值类型 包名.类名.方法名(参数))
```

## 基于注解的 AOP 开发

#### 快速入门

基于注解的aop开发步骤：

1. 创建目标接口和目标类（内部有切点）

2. 创建切面类（内部有增强方法）

3. 将目标类和切面类的对象创建权交给 spring

4. 在切面类中使用注解配置织入关系

5. 在配置文件中开启组件扫描和 AOP 的自动代理

6. 测试



1. 创建目标接口和目标类（内部有切点）

```java
public interface TargetInterface {
    public void method();
}

public class Target implements TargetInterface {
    @Override
    public void method() {
        System.out.println("Target running...");
    }
}
```

2. 创建切面类（内部有增强方法)

```java
public class MyAspect {
    public void before(){
        System.out.println("前置增强...");
    }
}
```

3. 将目标类和切面类的对象创建权交给 spring

```java
@Component("target")
public class Target implements TargetInterface {
    @Override
    public void method() {
        System.out.println("Target running....");
    }
}
@Component("myAspect")
public class MyAspect {
    public void before(){
        System.out.println("前置增强.....");
    }
}
```

4. 在切面类中使用注解配置织入关系

```java
@Component("myAspect")
@Aspect
public class MyAspect {
    @Before("execution(* com.xx.aop.*.*(..))")
    public void before(){
        System.out.println("前置增强.....");
    }
}
```

5. 在配置文件中开启组件扫描和 AOP 的自动代理

```xml
<!--组件扫描-->
<context:component-scan base-package="com.xx.aop"/>
<!--aop的自动代理-->
<aop:aspectj-autoproxy></aop:aspectj-autoproxy>
```

6. 测试代码

```java
@RunWith(SpringJUnit4ClassRunner.class)
@ContextConfiguration("classpath:applicationContext.xml")
public class AopTest {
    @Autowired
    private TargetInterface target;
    @Test
    public void test1(){
        target.method();
    }
}
```

7. 测试结果

```
前置增强...
Target running...
```

#### 注解配置 AOP 详解

##### 1) 注解通知的类型

通知的配置语法：@通知注解(“切点表达式")

| 名称         | 标签              | 说明                                                     |
| ------------ | ----------------- | -------------------------------------------------------- |
| 前置通知     | `@Before`         | 配置前置通知。指定增强的方法在切入点方法之前执行         |
| 后置通知     | `@AfterReturning` | 配置后置通知。指定增强的方法在切入点方法之后执行         |
| 环绕通知     | `@Around`         | 配置环绕通知。指定增强的方法在切入点方法之前和之后都执行 |
| 异常抛出通知 | `AfterThrowing`   | 配置异常抛出通知。指定增强的方法在出现异常时执行         |
| 最终通知     | `After`           | 配置最终通知。无论增强方法执行是否有异常都会执行         |

##### 2) 切点表达式的抽取

同 xml 配置 aop 一样，我们可以将切点表达式抽取。抽取方式是在切面内定义方法，在该方法上使用 @Pointcut 注解定义切点表达式，然后在在增强注解中进行引用。具体如下：

```java
@@Component("myAspect")
@Aspect
public class MyAspect {
    @Before("MyAspect.myPoint()")
    public void before(){
        System.out.println("前置代码增强.....");
    }
    @Pointcut("execution(* com.itheima.aop.*.*(..))")
    public void myPoint(){}
}
```

#### 知识要点

- 注解aop开发步骤
  1. 使用@Aspect标注切面类
  2. 使用@通知注解标注通知方法
  3. 在配置文件中配置aop自动代理 `<aop:aspectj-autoproxy/>`

- 通知注解类型

| 名称         | 标签              | 说明                                                     |
| :----------- | :---------------- | -------------------------------------------------------- |
| 前置通知     | `@Before`         | 配置前置通知。指定增强的方法在切入点方法之前执行         |
| 后置通知     | `@AfterReturning` | 配置后置通知。指定增强的方法在切入点方法之后执行         |
| 环绕通知     | `@Around`         | 配置环绕通知。指定增强的方法在切入点方法之前和之后都执行 |
| 异常抛出通知 | `AfterThrowing`   | 配置异常抛出通知。指定增强的方法在出现异常时执行         |
| 最终通知     | `After`           | 配置最终通知。无论增强方法执行是否有异常都会执行         |



# JdbcTemplate基本使用

## JdbcTemplate基本使用-概述(了解)

JdbcTemplate是spring框架中提供的一个对象，是对原始繁琐的Jdbc API对象的简单封装。spring框架为我们提供了很多的操作模板类。例如：操作关系型数据的JdbcTemplate和HibernateTemplate，操作nosql数据库的RedisTemplate，操作消息队列的JmsTemplate等等。

## JdbcTemplate基本使用-开发步骤(理解)

①导入spring-jdbc和spring-tx坐标

②创建数据库表和实体

③创建JdbcTemplate对象

④执行数据库操作

## JdbcTemplate基本使用-快速入门代码实现(应用)

导入spring-jdbc和spring-tx坐标

```xml
<?xml version="1.0" encoding="UTF-8"?>

<project xmlns="http://maven.apache.org/POM/4.0.0" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
  xsi:schemaLocation="http://maven.apache.org/POM/4.0.0 http://maven.apache.org/xsd/maven-4.0.0.xsd">
  <modelVersion>4.0.0</modelVersion>
  <groupId>com.itheima</groupId>
  <artifactId>itheima_spring_jdbc</artifactId>
  <version>1.0-SNAPSHOT</version>
  <packaging>war</packaging>

  <name>itheima_spring_jdbc Maven Webapp</name>
  <!-- FIXME change it to the project's website -->
  <url>http://www.example.com</url>
  <dependencies>
    <dependency>
      <groupId>mysql</groupId>
      <artifactId>mysql-connector-java</artifactId>
      <version>5.1.32</version>
    </dependency>
    <dependency>
      <groupId>c3p0</groupId>
      <artifactId>c3p0</artifactId>
      <version>0.9.1.2</version>
    </dependency>
    <dependency>
      <groupId>com.alibaba</groupId>
      <artifactId>druid</artifactId>
      <version>1.1.10</version>
    </dependency>
    <dependency>
      <groupId>junit</groupId>
      <artifactId>junit</artifactId>
      <version>4.12</version>
    </dependency>
    <dependency>
      <groupId>org.springframework</groupId>
      <artifactId>spring-context</artifactId>
      <version>5.0.5.RELEASE</version>
    </dependency>
    <dependency>
      <groupId>org.springframework</groupId>
      <artifactId>spring-test</artifactId>
      <version>5.0.5.RELEASE</version>
    </dependency>
    <dependency>
      <groupId>org.springframework</groupId>
      <artifactId>spring-web</artifactId>
      <version>5.0.5.RELEASE</version>
    </dependency>
    <dependency>
      <groupId>org.springframework</groupId>
      <artifactId>spring-webmvc</artifactId>
      <version>5.0.5.RELEASE</version>
    </dependency>
    <dependency>
      <groupId>javax.servlet</groupId>
      <artifactId>javax.servlet-api</artifactId>
      <version>3.0.1</version>
      <scope>provided</scope>
    </dependency>
    <dependency>
      <groupId>javax.servlet.jsp</groupId>
      <artifactId>javax.servlet.jsp-api</artifactId>
      <version>2.2.1</version>
      <scope>provided</scope>
    </dependency>
    <dependency>
      <groupId>com.fasterxml.jackson.core</groupId>
      <artifactId>jackson-core</artifactId>
      <version>2.9.0</version>
    </dependency>
    <dependency>
      <groupId>com.fasterxml.jackson.core</groupId>
      <artifactId>jackson-databind</artifactId>
      <version>2.9.0</version>
    </dependency>
    <dependency>
      <groupId>com.fasterxml.jackson.core</groupId>
      <artifactId>jackson-annotations</artifactId>
      <version>2.9.0</version>
    </dependency>
    <dependency>
      <groupId>commons-fileupload</groupId>
      <artifactId>commons-fileupload</artifactId>
      <version>1.3.1</version>
    </dependency>
    <dependency>
      <groupId>commons-io</groupId>
      <artifactId>commons-io</artifactId>
      <version>2.3</version>
    </dependency>
    <dependency>
      <groupId>org.springframework</groupId>
      <artifactId>spring-jdbc</artifactId>
      <version>5.0.5.RELEASE</version>
    </dependency>
    <dependency>
      <groupId>org.springframework</groupId>
      <artifactId>spring-tx</artifactId>
      <version>5.0.5.RELEASE</version>
    </dependency>
  </dependencies>
</project>

```

创建数据库表和实体

![](/Users/caianfang/Downloads/__/20 Java/03-就业课(2.1)-Spring/day04_ JdbcTemplate基本使用/笔记/img/1.png)

```java
package com.itheima.domain;

public class Account {

    private String name;
    private double money;

    public String getNa me() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public double getMoney() {
        return money;
    }

    public void setMoney(double money) {
        this.money = money;
    }

    @Override
    public String toString() {
        return "Account{" +
                "name='" + name + '\'' +
                ", money=" + money +
                '}';
    }
}

```

创建JdbcTemplate对象

执行数据库操作

```java
@Test
    //测试JdbcTemplate开发步骤
    public void test1() throws PropertyVetoException {
        //创建数据源对象
        ComboPooledDataSource dataSource = new ComboPooledDataSource();
        dataSource.setDriverClass("com.mysql.jdbc.Driver");
        dataSource.setJdbcUrl("jdbc:mysql://localhost:3306/test");
        dataSource.setUser("root");
        dataSource.setPassword("root");

        JdbcTemplate jdbcTemplate = new JdbcTemplate();
        //设置数据源对象  知道数据库在哪
        jdbcTemplate.setDataSource(dataSource);
        //执行操作
        int row = jdbcTemplate.update("insert into account values(?,?)", "tom", 5000);
        System.out.println(row);

    }
```



## JdbcTemplate基本使用-spring产生模板对象分析(理解)

我们可以将JdbcTemplate的创建权交给Spring，将数据源DataSource的创建权也交给Spring，在Spring容器内部将数据源DataSource注入到JdbcTemplate模版对象中,然后通过Spring容器获得JdbcTemplate对象来执行操作。

## JdbcTemplate基本使用-spring产生模板对象代码实现(应用)

配置如下：

```xml
<!--数据源对象-->
    <bean id="dataSource" class="com.mchange.v2.c3p0.ComboPooledDataSource">
        <property name="driverClass" value="com.mysql.jdbc.Driver"></property>
        <property name="jdbcUrl" value="jdbc:mysql:///test"></property>
        <property name="user" value="root"></property>
        <property name="password" value="root"></property>
    </bean>

    <!--jdbc模板对象-->
    <bean id="jdbcTemplate" class="org.springframework.jdbc.core.JdbcTemplate">
        <property name="dataSource" ref="dataSource"/>
    </bean>

```

测试代码

```java
 @Test
    //测试Spring产生jdbcTemplate对象
    public void test2() throws PropertyVetoException {
        ApplicationContext app = new ClassPathXmlApplicationContext("applicationContext.xml");
        JdbcTemplate jdbcTemplate = app.getBean(JdbcTemplate.class);
        int row = jdbcTemplate.update("insert into account values(?,?)", "lisi", 5000);
        System.out.println(row);
    }
```

## JdbcTemplate基本使用-spring产生模板对象代码实现（抽取jdbc.properties）(应用)

将数据库的连接信息抽取到外部配置文件中，和spring的配置文件分离开，有利于后期维护

```properties
jdbc.driver=com.mysql.jdbc.Driver
jdbc.url=jdbc:mysql://localhost:3306/test
jdbc.username=root
jdbc.password=root
```

配置文件修改为:

```xml
<?xml version="1.0" encoding="UTF-8"?>
<beans xmlns="http://www.springframework.org/schema/beans"
       xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
       xmlns:context="http://www.springframework.org/schema/context"
       xsi:schemaLocation="
       http://www.springframework.org/schema/beans http://www.springframework.org/schema/beans/spring-beans.xsd
       http://www.springframework.org/schema/context http://www.springframework.org/schema/context/spring-context.xsd
">

    <!--加载jdbc.properties-->
    <context:property-placeholder location="classpath:jdbc.properties"/>

    <!--数据源对象-->
    <bean id="dataSource" class="com.mchange.v2.c3p0.ComboPooledDataSource">
        <property name="driverClass" value="${jdbc.driver}"/>
        <property name="jdbcUrl" value="${jdbc.url}"/>
        <property name="user" value="${jdbc.username}"/>
        <property name="password" value="${jdbc.password}"/>
    </bean>

    <!--jdbc模板对象-->
    <bean id="jdbcTemplate" class="org.springframework.jdbc.core.JdbcTemplate">
        <property name="dataSource" ref="dataSource"/>
    </bean>

</beans>
```

## JdbcTemplate基本使用-常用操作-更新操作(应用)

```java
package com.itheima.test;

import com.itheima.domain.Account;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.jdbc.core.BeanPropertyRowMapper;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.test.context.ContextConfiguration;
import org.springframework.test.context.junit4.SpringJUnit4ClassRunner;

import java.util.List;

@RunWith(SpringJUnit4ClassRunner.class)
@ContextConfiguration("classpath:applicationContext.xml")
public class JdbcTemplateCRUDTest {

    @Autowired
    private JdbcTemplate jdbcTemplate;
    
	//修改更新
    @Test
    public void testUpdate(){
        jdbcTemplate.update("update account set money=? where name=?",10000,"tom");
    }
	//删除
    @Test
    public void testDelete(){
        jdbcTemplate.update("delete from account where name=?","tom");
    }

}

```



## JdbcTemplate基本使用-常用操作-查询操作(应用)

```java
package com.itheima.test;

import com.itheima.domain.Account;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.jdbc.core.BeanPropertyRowMapper;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.test.context.ContextConfiguration;
import org.springframework.test.context.junit4.SpringJUnit4ClassRunner;

import java.util.List;

@RunWith(SpringJUnit4ClassRunner.class)
@ContextConfiguration("classpath:applicationContext.xml")
public class JdbcTemplateCRUDTest {

    @Autowired
    private JdbcTemplate jdbcTemplate;
    
	//聚合查询
    @Test
    public void testQueryCount(){
        Long count = jdbcTemplate.queryForObject("select count(*) from account", Long.class);
        System.out.println(count);
    }
	//查询一个
    @Test
    public void testQueryOne(){
        Account account = jdbcTemplate.queryForObject("select * from account where name=?", new BeanPropertyRowMapper<Account>(Account.class), "tom");
        System.out.println(account);
    }
	//查询所有
    @Test
    public void testQueryAll(){
        List<Account> accountList = jdbcTemplate.query("select * from account", new BeanPropertyRowMapper<Account>(Account.class));
        System.out.println(accountList);
    }

}
```

## JdbcTemplate基本使用-知识要点(理解，记忆)

①导入spring-jdbc和spring-tx坐标

②创建数据库表和实体

③创建JdbcTemplate对象

    		JdbcTemplate jdbcTemplate = newJdbcTemplate();
    	       jdbcTemplate.setDataSource(dataSource);

④执行数据库操作

    更新操作：
    
        jdbcTemplate.update (sql,params)
    
    查询操作：
    
        jdbcTemplate.query (sql,Mapper,params)
    
    jdbcTemplate.queryForObject(sql,Mapper,params)

# 声明式事务控制

## 编程式事务控制相关对象

### PlatformTransactionManager

PlatformTransactionManager 接口是 spring 的事务管理器，它里面提供了我们常用的操作事务的方法。

| 方法                                                         | 说明               |
| ------------------------------------------------------------ | ------------------ |
| TransactionStatus getStransaction(TransactionDefination defination) | 获取事务的状态信息 |
| void commit(TransactionStatus status)                        | 提交事务           |
| void rollback(TransactionStatus status)                      | 回滚事务           |

注意：

PlatformTransactionManager 是接口类型，不同的 Dao 层技术则有不同的实现类，例如：Dao 层技术是jdbc 或 mybatis 时：org.springframework.jdbc.datasource.DataSourceTransactionManager 

Dao 层技术是hibernate时：org.springframework.orm.hibernate5.HibernateTransactionManager

### TransactionDefinition

TransactionDefinition 是事务的定义信息对象，里面有如下方法：

| 方法                         | 说明               |
| ---------------------------- | ------------------ |
| int getIsolationLevel()      | 获得事务的隔离级别 |
| int getPropogationBehavior() | 获得事务的传播行为 |
| int getTimeout()             | 获得超时时间       |
| Boolean isReadOnly()         | 是否只读           |

#### 1. 事务隔离级别

设置隔离级别，可以解决事务并发产生的问题，如脏读、不可重复读和虚读。

- ISOLATION_DEFAULT

- ISOLATION_READ_UNCOMMITTED

- ISOLATION_READ_COMMITTED

- ISOLATION_REPEATABLE_READ

- ISOLATION_SERIALIZABLE

#### 2. 事务传播行为

- **REQUIRED：如果当前没有事务，就新建一个事务，如果已经存在一个事务中，加入到这个事务中。一般的选择（默认值）**

- **SUPPORTS：支持当前事务，如果当前没有事务，就以非事务方式执行（没有事务）**

- MANDATORY：使用当前的事务，如果当前没有事务，就抛出异常

- REQUERS_NEW：新建事务，如果当前在事务中，把当前事务挂起。

- NOT_SUPPORTED：以非事务方式执行操作，如果当前存在事务，就把当前事务挂起

- NEVER：以非事务方式运行，如果当前存在事务，抛出异常

- NESTED：如果当前存在事务，则在嵌套事务内执行。如果当前没有事务，则执行 REQUIRED 类似的操作

- 超时时间：默认值是-1，没有超时限制。如果有，以秒为单位进行设置

- 是否只读：建议查询时设置为只读

### TransactionStatus

TransactionStatus 接口提供的是事务具体的运行状态，方法介绍如下。

| 方法                       | 说明           |
| -------------------------- | -------------- |
| boolean hasSavepoint()     | 是否存储回滚点 |
| boolean isCompleted()      | 事务是否完成   |
| boolean isNewTransaction() | 是否是新事务   |
| boolean isRollbackOnly()   | 事务是否回滚   |

### 知识要点

编程式事务控制三大对象

- PlatformTransactionManager

- TransactionDefinition

- TransactionStatus

## 基于 XML 的声明式事务控制

### 什么是声明式事务控制

Spring 的声明式事务顾名思义就是采用声明的方式来处理事务。这里所说的声明，就是指在配置文件中声明，用在 Spring 配置文件中声明式的处理事务来代替代码式的处理事务。

**声明式事务处理的作用**

- 事务管理不侵入开发的组件。具体来说，业务逻辑对象就不会意识到正在事务管理之中，事实上也应该如此，因为事务管理是属于系统层面的服务，而不是业务逻辑的一部分，如果想要改变事务管理策划的话，也只需要在定义文件中重新配置即可

- 在不需要事务管理的时候，只要在设定文件上修改一下，即可移去事务管理服务，无需改变代码重新编译，这样维护起来极其方便

**注意：Spring 声明式事务控制底层就是AOP。**



### 声明式事务控制的实现

声明式事务控制明确事项：

- 谁是切点？

- 谁是通知？

- 配置切面？

①引入tx命名空间

```xml
<beans xmlns="http://www.springframework.org/schema/beans"
       xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
       xmlns:context="http://www.springframework.org/schema/context"
       xmlns:aop="http://www.springframework.org/schema/aop"
       xmlns:tx="http://www.springframework.org/schema/tx"
       xsi:schemaLocation="
        http://www.springframework.org/schema/context
        http://www.springframework.org/schema/context/spring-context.xsd
        http://www.springframework.org/schema/aop
        http://www.springframework.org/schema/aop/spring-aop.xsd
        http://www.springframework.org/schema/tx 
        http://www.springframework.org/schema/tx/spring-tx.xsd
        http://www.springframework.org/schema/beans
        http://www.springframework.org/schema/beans/spring-beans.xsd">


```

②配置事务增强

```xml
<!--平台事务管理器-->
<bean id="transactionManager" class="org.springframework.jdbc.datasource.DataSourceTransactionManager">
    <property name="dataSource" ref="dataSource"></property>
</bean>

<!--事务增强配置-->
<tx:advice id="txAdvice" transaction-manager="transactionManager">
    <tx:attributes>
        <tx:method name="*"/>
    </tx:attributes>
</tx:advice>
```

③配置事务 AOP 织入

```xml
<!--事务的aop增强-->
<aop:config>
    <aop:pointcut id="myPointcut" expression="execution(* com.itheima.service.impl.*.*(..))"/>
    <aop:advisor advice-ref="txAdvice" pointcut-ref="myPointcut"></aop:advisor>
</aop:config>
```

④测试事务控制转账业务代码

```java
@Override
public void transfer(String outMan, String inMan, double money) {
    accountDao.out(outMan,money);
    int i = 1/0;
    accountDao.in(inMan,money);
}
```

### 切点方法的事务参数的配置

```xml
<!--事务增强配置-->
<tx:advice id="txAdvice" transaction-manager="transactionManager">
    <tx:attributes>
        <tx:method name="*"/>
    </tx:attributes>
</tx:advice>
```

其中，<tx:method> 代表切点方法的事务参数的配置，例如：

```xml
<tx:method name="transfer" isolation="REPEATABLE_READ" propagation="REQUIRED" timeout="-1" read-only="false"/>
```

- name：切点方法名称

- isolation:事务的隔离级别

- propogation：事务的传播行为

- timeout：超时时间

- read-only：是否只读

### 知识要点

**声明式事务控制的配置要点**

- 平台事务管理器配置

- 事务通知的配置

- 事务aop织入的配置

## 基于注解的声明式事务控制

### 使用注解配置声明式事务控制

1. 编写 AccoutDao

```java
@Repository("accountDao")
public class AccountDaoImpl implements AccountDao {
    @Autowired
    private JdbcTemplate jdbcTemplate;
    public void out(String outMan, double money) {
        jdbcTemplate.update("update account set money=money-? where name=?",money,outMan);
    }
    public void in(String inMan, double money) {
        jdbcTemplate.update("update account set money=money+? where name=?",money,inMan);
    }
}
```

2. 编写 AccoutService

```java
@Service("accountService")
@Transactional
public class AccountServiceImpl implements AccountService {
    @Autowired
    private AccountDao accountDao;
    @Transactional(isolation = Isolation.READ_COMMITTED,propagation = Propagation.REQUIRED)
    public void transfer(String outMan, String inMan, double money) {
        accountDao.out(outMan,money);
        int i = 1/0;
        accountDao.in(inMan,money);
    }
}
```

3. 编写 applicationContext.xml 配置文件

```xml
<!—之前省略datsSource、jdbcTemplate、平台事务管理器的配置-->
<!--组件扫描-->
<context:component-scan base-package="com.itheima"/>
<!--事务的注解驱动-->
<tx:annotation-driven/>
```

### 注解配置声明式事务控制解析

①使用 @Transactional 在需要进行事务控制的类或是方法上修饰，注解可用的属性同 xml 配置方式，例如隔离级别、传播行为等。

②注解使用在类上，那么该类下的所有方法都使用同一套注解参数配置。

③使用在方法上，不同的方法可以采用不同的事务参数配置。

④Xml配置文件中要开启事务的注解驱动<tx:annotation-driven />

### 知识要点

**注解声明式事务控制的配置要点**

- 平台事务管理器配置（xml方式）

- 事务通知的配置（@Transactional注解配置）

- 事务注解驱动的配置 <tx:annotation-driven/>



   







































   



 
