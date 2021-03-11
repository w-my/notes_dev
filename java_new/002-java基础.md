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



## JShell 脚本工具















