# Java 进阶 - Junit单元测试、反射、注解

- Junit 单元测试
- 反射
- 注解



## Junit 单元测试

#### 测试分类

- **黑盒测试**：不需要写代码，给输入值，看程序是否能够输出期望的值。
- **白盒测试**：需要写代码的。关注程序具体的执行流程。

#### Junit使用：白盒测试

##### 步骤：

1. 定义一个测试类

   - 测试类名：测试类名：被测试的类名Test		CalculatorTest
   - 包名：xxx.xxx.xx.test		cn.itcast.test

2. 定义测试方法：可以独立运行

   - 方法名：test测试的方法名		testAdd()

   - 返回值：void
   - 参数列表：空参

3. 给方法加 `@Test`

4. 导入 Junit 依赖环境

##### 判定结果

- 红色：失败
- 绿色：成功
- 一般我们会使用断言操作来处理结果
  - Assert.assertEquals(期望的结果,运算的结果);

##### 补充

- @Before:
  - 修饰的方法会在测试方法之前被自动执行
- @After:
  - 修饰的方法会在测试方法执行之后自动被执行



```java
package cn.xxx.junit;

public class Calculator {
    public int add(int a, int b) {
        return a + b;
    }

    public int sub(int a, int b) {
        return a - b;
    }
}
```

```java
package cn.xxx.test;

import cn.xxx.junit.Calculator;
import org.junit.After;
import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

public class CalculatorTest {

    @Before
    public void init() {
        System.out.println("init...");
    }

    @After
    public void close() {
        System.out.println("close...");
    }

    @Test
    public void testAdd() {
        Calculator c = new Calculator();
        int result = c.add(1, 2);
        Assert.assertEquals(3, result);
    }

    @Test
    public void testSub() {
        Calculator c = new Calculator();
        int result = c.sub(1, 2);
        Assert.assertEquals(-1, result);
    }
}
```



## 反射：框架设计的灵魂

**框架**：半成品软件。可以在框架的基础上进行软件开发，简化编码。

**反射**：将类的各个组成部分封装为其他对象，这就是反射机制。

**好处**

1. 可以在程序运行过程中，操作这些对象。
2. 可以解耦，提高程序的可扩展性。

#### 获取Class对象

- `Class.forName("全类名")` ：将字节码文件加载进内存，返回Class对象
  - 多用于配置文件，将类名定义在配置文件中。读取文件，加载类
- `类名.Class` ：通过类名的属性Class获取
  - 多用于参数的传递
- `对象.getClass()` ：getClass() 方法在Object类中定义着。
  - 多用于对象的获取字节码的方式

**结论**：同一个字节码文件(*.class)在一次程序运行过程中，只会被加载一次，不论通过哪一种方式获取的Class对象都是同一个。

#### Class对象功能

##### 获取成员变量

- `Field[] getFields()` ：获取所有public修饰的成员变量
- `Field getField(String name)`   获取指定名称的 public修饰的成员变量
- `Field[] getDeclaredFields()`  获取所有的成员变量，不考虑修饰符
- `Field getDeclaredField(String name)  `

##### 获取构造方法

- `Constructor<?>[] getConstructors()`
- `Constructor<T> getConstructor(类<?>... parameterTypes)`
- `Constructor<T> getDeclaredConstructor(类<?>... parameterTypes)`
- `Constructor<?>[] getDeclaredConstructors()`

##### 获取成员方法

- `Method[] getMethods()`
- `Method getMethod(String name, 类<?>... parameterTypes)`
- `Method[] getDeclaredMethods()`
- `Method getDeclaredMethod(String name, 类<?>... parameterTypes)`

##### 获取全类名

- `String getName()`

#### Field 成员变量

##### 操作

**设置值**

- `void set(Object obj, Object value)`

**获取值**

- `get(Object obj)`

**忽略访问权限修饰符的安全检查**

- `setAccessible(true)` ： 暴力反射

#### Constructor 构造方法

##### 创建对象

- `T newInstance(Object... initargs)`

如果构造空参构造方法创建对象，操作可以简化：`Class` 对象的 `newInstance` 方法

#### Method 方法对象

##### 执行方法

- `Object invoke(Object obj, Object... args)`

##### 获取方法名称

- `String getName()`

#### 案例

##### 需求：

写一个"框架"，不能改变该类的任何代码的前提下，可以帮我们创建任意类的对象，并且执行其中任意方法

- 实现：
    1. 配置文件
    2. 反射
- 步骤：
    1. 将需要创建的对象的全类名和需要执行的方法定义在配置文件中
    2. 在程序中加载读取配置文件
    3. 使用反射技术来加载类文件进内存
    4. 创建对象
    5. 执行方法



## 注解

**注解**（Annotation），也叫**元数据**。一种代码级别的说明。它是JDK1.5及以后版本引入的一个特性，与类、接口、枚举是在同一个层次。它可以声明在包、类、字段、方法、局部变量、方法参数等的前面，用来对这些元素进行说明，注释。

**作用分类**：

1. 编写文档：通过代码里标识的注解生成文档【生成文档doc文档】
2. 代码分析：通过代码里标识的注解对代码进行分析【使用反射】
3. 编译检查：通过代码里标识的注解让编译器能够实现基本的编译检查【Override】

#### JDK中预定义的一些注解

- `@Override` ：检测被该注解标注的方法是否是继承自父类(接口)的
-  `@Deprecated` ：该注解标注的内容，表示已过时
-  `@SuppressWarnings` ：压制警告
  -  一般传递参数all  `@SuppressWarnings("all")`

#### 自定义注解

##### 格式

```java
元注解
public @interface 注解名称 {
  属性列表
}
```

##### 本质

注解本质上就是一个接口，该接口默认继承Annotation接口

- `public interface MyAnno extends java.lang.annotation.Annotation {}`

##### 属性

接口中的抽象方法

**要求**

- 属性的返回值类型有下列取值
  - 基本数据类型
  - String
  - 枚举
  - 注解
  - 以上类型的数组
- 定义了属性，在使用时需要给属性赋值
  - 如果定义属性时，使用default关键字给属性默认初始化值，则使用注解时，可以不进行属性的赋值。
  - 如果只有一个属性需要赋值，并且属性的名称是value，则value可以省略，直接定义值即可。
  - 数组赋值时，值使用{}包裹。如果数组中只有一个值，则{}可以省略

##### 元注解

用于描述注解的注解

- `@Target` ：描述注解能够作用的位置
  - ElementType取值：
    - `TYPE`：可以作用于类上
    - `METHOD`：可以作用于方法上
    - `METHOD`：可以作用于方法上
- `@Retention` ：描述注解被保留的阶段
  - `@Retention(RetentionPolicy.RUNTIME)` ：当前被描述的注解，会保留到class字节码文件中，并被JVM读取到
- `@Documented` ：描述注解是否被抽取到api文档中
- `@Inherited` ：描述注解是否被子类继承

#### 在程序使用(解析)注解

获取注解中定义的属性值

- 获取注解定义的位置的对象  （Class，Method,Field）

- 获取指定的注解

  - getAnnotation(Class) 其实就是在内存中生成了一个该注解接口的子类实现对象

  ```java
  public class ProImpl implements Pro{
      public String className(){
          return "cn.itcast.annotation.Demo1";
      }
      public String methodName(){
          return "show";
      }
  }
  ```

- 调用注解中的抽象方法获取配置的属性值

#### 案例

简单的测试框架

**Calculator类**

```java
package cn.xx.annotation.demo;

/**
 * 定义的计算器类
 */
public class Calculator {
    @Check
    public void add(){
        String str = null;
        str.toString();
        System.out.println("1 + 0 =" + (1 + 0));
    }
    @Check
    public void sub(){
        System.out.println("1 - 0 =" + (1 - 0));
    }
    @Check
    public void mul(){
        System.out.println("1 * 0 =" + (1 * 0));
    }
    @Check
    public void div(){
        System.out.println("1 / 0 =" + (1 / 0));
    }

    public void show(){
        System.out.println("永无bug...");
    }

}
```

**Check类**

```java
package cn.xx.annotation.demo;

import java.lang.annotation.ElementType;
import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;
import java.lang.annotation.Target;

@Retention(RetentionPolicy.RUNTIME)
@Target(ElementType.METHOD)
public @interface Check {
  
}
```

**TestCheck类**

```java
package cn.xx.annotation.demo;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;

/**
 * 简单的测试框架
 *
 * 当主方法执行后，会自动自行被检测的所有方法(加了Check注解的方法)，判断方法是否有异常，记录到文件中
 */
public class TestCheck {

    public static void main(String[] args) throws IOException {
        // 1.创建计算器对象
        Calculator c = new Calculator();
        // 2.获取字节码文件对象
        Class cls = c.getClass();
        // 3.获取所有方法
        Method[] methods = cls.getMethods();

        int number = 0; // 出现异常的次数
        BufferedWriter bw = new BufferedWriter(new FileWriter("bug.txt"));

        for (Method method : methods) {
            // 4.判断方法上是否有Check注解
            if(method.isAnnotationPresent(Check.class)){
                // 5.有，执行
                try {
                    method.invoke(c);
                } catch (Exception e) {
                    // 6.捕获异常

                    // 记录到文件中
                    number ++;

                    bw.write(method.getName()+ " 方法出异常了");
                    bw.newLine();
                    bw.write("异常的名称:" + e.getCause().getClass().getSimpleName());
                    bw.newLine();
                    bw.write("异常的原因:"+e.getCause().getMessage());
                    bw.newLine();
                    bw.write("--------------------------");
                    bw.newLine();

                }
            }
        }

        bw.write("本次测试一共出现 "+number+" 次异常");

        bw.flush();
        bw.close();
    }
}
```

#### 小结

1. 大多数时候，我们会使用注解，而不是自定义注解
2. 注解给谁用？
   1. 编译器
   2. 给解析程序用
3. 注解不是程序的一部分，可以理解为注解就是一个标签

