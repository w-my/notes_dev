# Java 基础

## 变量和数据类型

**变量**：常量是固定不变的数据，那么在程序中可以变化的量称为变量。

**格式**：

```java
数据类型 变量名 = 数据值;
```

**Java 的数据类型分为两大类**：

**基本数据类型**：整数 (byte / short / int / long)、浮点数 (float / double)、字符 (char)、布尔 (boolean)。 
**引用数据类型**：字符串、数组、类 、接口 ...



## 数据类型转换

#### 自动转换

将 `取值范围小的类型` 自动提升为 `取值范围大的类型`。

> byte、short、char --> int --> long --> float --> double

#### 强制转换

将 `取值范围大的类型` 强制转换成 `取值范围小的类型`。

> 数据类型 变量名 =  (数据类型)被转数据值;

```java
int i = (int)1.5;
```



## 运算符

#### 算数运算符

> `+`  `-`  `*`  `/`  `%`  `++`  `--`

#### 赋值运算符

> `=`  `+=`  `-=`  `*=`  `/=`  `%=`

#### 比较运算符

> `==`  `<`  `>`  `<=`  `>=`  `!=` 

#### 逻辑运算符

> `&&`  `||`  `!`

#### 三元运算符

> 数据类型 变量名 = 布尔类型表达式 ? 结果1 : 结果2;



## 流程控制语句

- if else
- switch
- for
- while
- do while
- break, continue



## 方法

**方法** 就是将一个功能抽取出来，把代码单独定义在一个大括号内，形成一个单独的功能。

```java
修饰符 返回值类型 方法名 (参数列表) {
  代码...
	return ;
}
```

```java
public static void methodName() {
  System.out.println("这是一个方法");
}
```

```java
public class Demo {
  public static void main(String[] args) {
    method();
  }
  public static void method() {
    System.out.println("自定义的方法，需要被main调用运行");
  }
}
```



#### 方法重载

指在同一个类中，允许存在一个以上的同名方法，只要它们的**参数列表不同**即可，与**修饰符和返回值类型无关**。

```java
public static int sum(int a, int b) {
  return a + b;
}
public static int sum(int a, int b, int c) {
  return a + b + c;
}
```

```java
public static boolean compare(char a, char b) {
  return a == b;
}
public static boolean compare(int a, int b) {
  return a == b;
}
```



## Java虚拟机的内存划分

#### 栈（Stack）

存放的都是方法中的局部变量。**方法的运行一定要在栈中运行**。

​		局部变量：方法的参数，或者是方法{}内不的变量

​		作用域：一旦超出作用域，立刻从栈内存当中消失

#### 堆（Heap）

**凡是new出来的东西，都在堆当中**。

​		堆内存里面的东西都有一个地址值：16进制

​		堆内存里面的数据，都有默认值。规则：

​				整数				默认值为 0

​				浮点数			默认值为 0.0

​				字符				默认值为 '\u0000'

​				布尔				默认值为 false

​				引用类型		默认值为 null

#### 方法区（Method Area）

存储 .class 相关信息，包含方法的信息。

#### 本地方法栈（Native Method Stack）

与操作系统相关。

#### 寄存器（pc Register）

与 CPU 相关。



## 数组

#### 数组的初始化

**方式一**

```java
数据类型[] 数组名字 = new 数据类型[长度];
```

**方式二**

```java
数据类型[] 数组名 = new 数据类型[] {元素1, 元素2, 元素3...};
```

**方式三**

```java
数据类型[] 数组名 = {元素1, 元素2, 元素3...};
```

#### 数组的访问

```java
int[] arr = {1, 2, 3};
System.out.println(arr.length);
System.out.println(arr[0]);
```

#### 数组的常见操作

##### 越界异常

越界会抛出 `ArrayIndexOutOfBoundsException` 异常

##### 空指针异常

出现空指针会抛出 `NullPointerException` 异常

#### 数组遍历

```java
int[] arr = {1, 2, 3, 4, 5};
for (int i = 0; i < arr.length; i++) {
    System.out.println(arr[i]);
}
```

#### 数组获取最大值元素

```java
int[] arr = {1, 20, 4, 12, 5};
int max = arr[0];
for (int i = 0; i < arr.length; i++) {
    if (arr[i] > max) {
        max = arr[i];
    }
}
System.out.println("最大值是：" + max);
```

#### 数组反转

```java
int[] arr = {1, 2, 3, 4, 5};
for (int min = 0, max = arr.length - 1; min <= max; min++, max--) {
    int temp = arr[min];
    arr[min] = arr[max];
    arr[max] = temp;
}
for (int i = 0; i < arr.length; i++) {
    System.out.println(arr[i]);
}
```

#### 数组作为方法参数和返回值

```java
public class JavaClass {
    public static void main(String[] args) {
        int[] arr = {1, 2, 3, 4, 5};
        int[] result = reverseArr(arr);
        for (int i = 0; i < result.length; i++) {
            System.out.println(result[i]);
        }
    }

    public static int[] reverseArr(int[] arr) {
        for (int min = 0, max = arr.length - 1; min <= max; min++, max--) {
            int temp = arr[min];
            arr[min] = arr[max];
            arr[max] = temp;
        }
        return arr;
    }
}
```

#### 方法的参数类型区别

> 方法的参数作为基本类型时，传递的是数据值。方法的参数为引用类型时，传递的是地址值。



## 面向对象

**面向过程**：当需要实现一个功能等时候，每一个具体的步骤都要亲力亲为，详细处理每一个细节。
**面向对象**：当需要实现一个功能等时候，不关心具体的步骤，而是找一个已经具有改功能的人，来帮我做事儿。



## 类

```java
public class Demo01 {
    public static void main(String[] args) {
        Dog dog = new Dog();
        dog.name = "小狗";
        dog.run();
    }
}

class Dog {
    String name;
    public void run() {
        System.out.println(name + " 在跑步");
    }
}
```







Day06











