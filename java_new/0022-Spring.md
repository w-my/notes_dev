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

