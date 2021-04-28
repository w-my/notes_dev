# 语法进阶

## Object 类

`java.lang.Object` 类是Java语言中的根类，即所有类的父类。

Object 类中的其中两个方法：（Mac IDE 自动生成快捷键：ctrl+enter）

- `public String toString() `：返回该对象的字符串表示，`对象的类型+@+内存地址值`。
- `public boolean equals(Object obj)` ：指示其他某个对象是否与此对象”相等“。

#### toString

重写实现自定义

```java
@Override
public String toString() {
	return "";
}
```

#### equals

##### 默认地址比较

如果没有覆盖重写equals方法，那么Object类中默认进行 `==` 运算符的对象地址比较，只要不是同一个对象，结果必然为 false。

##### 对象内容比较

```java
public class Person {
  private String name;
  private int age;
  
  @Override
  public boolean equals(Object o) {
    // 如果对象地址一样，则认为相同
    if (this == 0) 
      return true;
    // 如果参数为空，或者类型信息不一样，则认为不同
    if (o == null || getClass() != o.getClass())
      return false;
    Person person = (Person)o;
    // 要求基本类型相等，并且将引用类型交给java.util.Objects类的equals静态方法取用结果
    return age == person.age && Object.equals(name, person.name);
  }
}
```



## Date类

`java.util.Date` 类 表示特定的瞬间，精确到毫秒。

- `public Date()`：分配Date对象并初始化此对象，以表示分配它的时间（精确到毫秒）。
- `public Date(long date)`：分配Date对象并初始化此对象，以表示自从标准基准时间（称为“历元（epoch）”，即1970年1月1日00:00:00 GMT）以来的指定毫秒数。

> tips: 由于我们处于东八区，所以我们的基准时间为1970年1月1日8时0分0秒。

```java
public class Demo01Date {
	public static void main(String[] args) {
		// 创建日期对象，把当前的时间
		System.out.println(new Date()); // Tue Jan 16 14:37:35 CST 2018
		// 创建日期对象，把当前的毫秒值转成日期对象
		System.out.println(new Date(0L)); // Thu Jan 01 08:00:00 CST 1970
	}
}

#### 常用方法

- `public long getTime()` 把日期对象转换成对应的时间毫秒值。

​```java
Date date = new Date();
long secone = date.getTime(); // 获取当前时间毫秒值
```



## DateFormat 类

`java.text.DateFormat` 是日期/时间格式化子类的抽象类。

#### 构造方法

由于DateFormat为抽象类，不能直接使用，所以需要常用的子类 `java.text.SimpleDateFormat`。

- `public SimpleDateFormat(String pattern)`：用给定的模式和默认语言环境的日期格式符号构造SimpleDateFormat。

```java
DateFormat format = new SimpleDateFormat("yyyy‐MM‐dd HH:mm:ss");
```

#### 常用方法

- `public String format(Date date)`：将Date对象格式化为字符串。
- `public Date parse(String source)`：将字符串解析为Date对象。

```java
Date date = new Date();
DateFormat df = new SimpleDateFormat("yyyy年MM月dd日");
String str = df.format(date);
```

```java
DateFormat df = new SimpleDsateFormat("yyyy年MM月dd日");
String str = "2020年12月02日";
Date date = dr.parse(str);
```

## Calendar 类

`java.util.Calendar` 是日历类，在Date后出现，替换掉了许多Date的方法。

#### 获取方式

Calendar为抽象类，由于语言敏感性，Calendar类在创建对象时并非直接创建，而是通过静态方法创建，返回子类对象。

- `public static Calendar getInstance()` ： 使用默认时区和语言环境获得一个日期

```java
Calender cal = Calender.getInstance();
```

#### 常用方法

- `public in get(int field)` ：返回给定日历字段的值。
- `public vlid set(int field, int value)` ：将给定的日历字段设置为给定值。
- `public abstract void add(int field, int amount)` ：根据日期的规则，为给定的日历字段添加或减去指定的时间量。
- `public Date getTime()` ：返回一个表示此 Calendar 时间值（从历元到现在毫秒偏移量）到Date对象。

Calendar类中的成员常量


| 字段值          | 含义                   |
| ------------ | -------------------- |
| YEAR         | 年                    |
| MONTH        | 月（从0开始，可以+1使用）       |
| DAY_OF_MONTH | 月中的天（几号）             |
| HOUR         | 时（12小时制）             |
| HOUR_OF_DAY  | 时（24小时制）             |
| MINUTE       | 分                    |
| SECOND       | 秒                    |
| DAY_OF_WEEK  | 周中的天（周几，周日为1，可以-1使用） |

#### get/set 方法

```java
Calendar cal = Calendar.getInstance();
int year = cal.get(Calendar.YEAR);
int month = cal.get(Calendar.MONTH) + 1;
int dayOfMonth = cal.get(Calendar.DAY_OF_MONTH);
```

```java
Calendar cal = Calendar.getInstance();
cal.set(Calendar.YEAR, 2020);
```

#### add 方法

add方法可以对指定日历字段的值进行加减操作，如果第二个参数为正数则加上偏移量，如果为负数则减去偏移量。

```java
Calendar cal = Calendar.getInstance();
cal.add(Calendar.DAY_OF_MONTH, 2); // 加2天
cal.add(Calendar.YEAR, -3); // 减3年
```

#### getTime 方法

Calendar中的getTime方法并不是获取毫秒时刻，而是拿到对应的Date对象。

```java
Calendar cal = Calendar.getInstance();
Date date = cal.getTime();
```

> 西方星期的开始为周日，中国为周一。
> 在Calendar类中，月份的表示是以0-11代表1-12月。
> 日期是有大小关系的，时间靠后，时间越大。



## System 类

`java.lang.System` 类中提供了大量的静态方法，可以获取与系统相关的信息或系统级操作。

- `public static long currentTimeMillis()`：返回以毫秒为单位的当前时间。
- `public static void arraycopy(Object src, int srcPos, Object dest, int destPos, int length)`：将数组中指定的数据拷贝到另一个数组中。

#### currentTimeMillis 方法

实际上，currentTimeMillis方法就是 获取当前系统时间与1970年01月01日00:00点之间的毫秒差值。

```java
System.currentTimeMillis();
```

#### array copy 方法

- `public static void arraycopy(Object src, int srcPos, Object dest, int destPos, int length)`：将数组中指定的数据拷贝到另一个数组中。

数组的拷贝动作是系统级的，性能很高。

| 参数名称 | 参数类型 | 参数含义             |
| -------- | -------- | -------------------- |
| src      | Object   | 源数组               |
| srcPos   | int      | 源数组索引起始位置   |
| dest     | Object   | 目标数组             |
| destPos  | int      | 目标数组索引起始位置 |
| length   | int      | 复制元素个数         |

```java
int[] src = new int[]{1,2,3,4,5};
int[] dest = new int[]{6,7,8,9,10};
System.arraycopy( src, 0, dest, 0, 3);
/*
	代码运行后：两个数组中的元素发生了变化
	src数组元素[1,2,3,4,5]
	dest数组元素[1,2,3,9,10]
*/
```



## StringBuilder

#### 字符串拼接问题

由于String类的对象内容不可改变，所以每当进行字符串拼接时，总是会在内存中创建一个新的对象。

由此可知，如果对字符串进行拼接操作，每次拼接，都会构建一个新的String对象，既耗时，又浪费空间。为了解 决这一问题，可以使用 `java.lang.StringBuilder` 类。

#### StringBuilder概述

`java.lang.StringBuilder`，`StringBuilder` 又称为可变字符序列，它是一个类似于 String 的字符串缓冲区，通过某些方法调用可以改变该序列的长度和内容。

#### 构造方法

- `public StringBuilder()`：构造一个空的StringBuilder容器。
- `public StringBuilder(String str)`：构造一个StringBuilder容器，并将字符串添加进去。

```java
public class StringBuilderDemo {
    public static void main(String[] args) {
        StringBuilder sb1 = new StringBuilder();
        System.out.println(sb1); // (空白)
        // 使用带参构造
        StringBuilder sb2 = new StringBuilder("itcast");
        System.out.println(sb2); // itcast
    }
}
```

#### 常用方法

- `public StringBuilder append(...)`：添加任意类型数据的字符串形式，并返回当前对象自身。
- `public String toString()`：将当前StringBuilder对象转换为String对象。

##### append 方法

```java
public class DemoStringBuilder {
	public static void main(String[] args) {
		// 创建对象
		StringBuilder builder = new StringBuilder();
		// public StringBuilder append(任意类型)
		StringBuilder builder2 = builder.append("hello");
		// 对比一下
		System.out.println("builder:"+builder);
		System.out.println("builder2:"+builder2);
		System.out.println(builder == builder2); //true
	  // 可以添加 任何类型
		builder.append("hello");
		builder.append("world");
		builder.append(true);
		builder.append(100);
		// 在我们开发中，会遇到调用一个方法后，返回一个对象的情况。然后使用返回的对象继续调用方法。
    // 这种时候，我们就可以把代码现在一起，如append方法一样，代码如下
		// 链式编程
		builder.append("hello").append("world").append(true).append(100);
		System.out.println("builder:"+builder);
	}
}
```

##### toString 方法

```java
public class DemoStringBuilder {
	public static void main(String[] args) {
    // 链式创建
    StringBuilder builder = new StringBuilder("Hello").append("World").append("Java");
    // 调用方法
    String str = builder.toString();
    System.out.println(str); // HelloWorldJava
  }
}
```



## 包装类

Java提供了两个类型系统，基本类型与引用类型，使用基本类型在于效率，然而很多情况，会创建对象使用，因为 对象可以做更多的功能，如果想要我们的基本类型像对象一样操作，就可以使用基本类型对应的包装类。

| 基本类型 | 对应的包装类（位于java.lang包中） |
| -------- | --------------------------------- |
| byte     | Byte                              |
| short    | Short                             |
| int      | **Integer**                       |
| long     | Long                              |
| float    | Float                             |
| double   | Double                            |
| char     | **Character**                     |
| boolean  | Boolean                           |

#### 装箱与拆箱

- **装箱**：从基本类型转换为对应的包装类对象。
- **拆箱**：从包装类对象转换为对应的基本类型。

```java
Integer i = new Integer(4);
Integer ii = Integer.valueOf(4);
```

```java
int num = i.intValue();
```

#### 基本类型与字符串之间的转换

##### 基本类型转换为String

```java
34+""
```

##### String转换成对应的基本类型

除了Character类之外，其他所有包装类都具有parseXxx静态方法可以将字符串参数转换为对应的基本类型：

- `public static byte parseByte(String s)`：将字符串参数转换为对应的byte基本类型。
- `public static short parseShort(String s)`：将字符串参数转换为对应的short基本类型。
- `public static int parseInt(String s)`：将字符串参数转换为对应的int基本类型。
- `public static long parseLong(String s)`：将字符串参数转换为对应的long基本类型。
- `public static float parseFloat(String s)`：将字符串参数转换为对应的float基本类型。
- `public static double parseDouble(String s)`：将字符串参数转换为对应的double基本类型。
- `public static boolean parseBoolean(String s)`：将字符串参数转换为对应的boolean基本类型。

```java
int num = Integer.parseInt("100");
```

>  如果字符串参数的内容无法正确转换为对应的基本类型，则会抛出 `java.lang.NumberFormatException` 异常。



## Collection 集合

- **集合**：集合是java中提供的一种容器，可以用来存储多个数据。

集合和数组都是容器，区别：

- 数组的长度是固定的。集合的长度是可变的。
- 数组中存储的是同一类型的元素，可以存储基本数据类型值。集合存储的都是对象。而且对象的类型可以不一致。在开发中一般当对象多的时候，使用集合进行存储。

#### 集合框架

集合按照其存储结构可以分为两大类，分别是单列集合 `java.util.Collection` 和双列集合 `java.util.Map`。

- **Collection**：单列集合类的根接口，用于存储一系列符合某种规则的元素，它有两个重要的子接口，分别是 `java.util.List` 和 `java.util.Set`。其中，`List` 的特点是元素有序、元素可重复。`Set` 的特点是元素无序，而且不可重复。`List` 接口的主要实现类有 `java.util.ArrayList` 和 `java.util.LinkedList` ，`Set` 接口的主要实现类有 `java.util.HashSet` 和 `java.util.TreeSet`。

![Collection集合继承体系](./img/Collection集合继承体系.png)

#### Collection 常用功能

Collection是所有单列集合的父接口，因此在Collection中定义了单列集合(List和Set)通用的一些方法。

* `public boolean add(E e)`：  把给定的对象添加到当前集合中 。
* `public void clear()` :清空集合中所有的元素。
* `public boolean remove(E e)`: 把给定的对象在当前集合中删除。
* `public boolean contains(E e)`: 判断当前集合中是否包含给定的对象。
* `public boolean isEmpty()`: 判断当前集合是否为空。
* `public int size()`: 返回集合中元素的个数。
* `public Object[] toArray()`: 把集合中的元素，存储到数组中。

```java
import java.util.ArrayList;
import java.util.Collection;

public class Demo1Collection {
  public static void main(String[] args) {
    // 创建集合对象 
    // 使用多态形式
    Collection<String> coll = new ArrayList<String>();
    // 使用方法
    // 添加功能  boolean  add(String s)
    coll.add("小李广");
    coll.add("扫地僧");
    coll.add("石破天");
    System.out.println(coll);

    // boolean contains(E e) 判断o是否在集合中存在
    System.out.println("判断  扫地僧 是否在集合中"+coll.contains("扫地僧"));

    // boolean remove(E e) 删除在集合中的o元素
    System.out.println("删除石破天："+coll.remove("石破天"));
    System.out.println("操作之后集合中元素:"+coll);

    // size() 集合中有几个元素
    System.out.println("集合中有"+coll.size()+"个元素");

    // Object[] toArray()转换成一个Object数组
    Object[] objects = coll.toArray();
    // 遍历数组
    for (int i = 0; i < objects.length; i++) {
      System.out.println(objects[i]);
    }

		// void  clear() 清空集合
		coll.clear();
		System.out.println("集合中内容为："+coll);
		// boolean  isEmpty()  判断是否为空
		System.out.println(coll.isEmpty());  	
	}
}
```



## Iterator 迭代器























## 泛型











