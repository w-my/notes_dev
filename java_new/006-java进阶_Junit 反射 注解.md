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

























