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

- `public Iterator iterator()` ：获取集合对应的迭代器，用来遍历集合中的元素的。

常用方法：

- `public E next()` ：返回迭代的下一个元素。
- `public boolean hasNext()` ：如果仍有元素可以迭代，则返回 true。

```java
Collection<String> coll = new ArrayList<String>();
coll.add("aa");
coll.add("bb");
coll.add("cc");
Iterator<String> it = coll.iterator;
while(it.hasNext()) {
  String s = it.next();
  System.out.println(s);
}
```

> tips::在进行集合元素取出时，如果集合中已经没有元素了，还继续使用迭代器的next方法，将会发生 `java.util.NoSuchElementException` 没有集合元素的错误。

#### 增强 for

增强for循环(也称for each循环)是**JDK1.5**以后出来的，专门用来遍历数组和集合的。它的内部原理其实是个Iterator迭代器，所以在遍历的过程中，**不能**对集合中的元素进行**增删**操作。

```java
for(元素的数据类型 变量 : Collection集合or数组){ 
  	// 操作代码
}
```

```java
int[] arr = {3, 5, 6, 87};
for(int a : arr){
  System.out.println(a);
}
```

```java
Collection<String> coll = new ArrayList<String>();
coll.add("小河神");
coll.add("老河神");
for(String s : coll){
  System.out.println(s);
}
```



## 泛型

在前面学习集合时，我们都知道集合中是可以存放任意对象的，只要把对象存储集合后，那么这时他们都会被提升成 Object 类型。当我们在取出每一个对象，并且进行相应的操作，这时必须采用类型转换。

```java
Collection coll = new ArrayList();
coll.add("abc");
coll.add("itcast");
coll.add(5); // 由于集合没有做任何限定，任何类型都可以给其中存放
Iterator it = coll.iterator();
while(it.hasNext()){
  // 需要打印每个字符串的长度,就要把迭代出来的对象转成String类型
  String str = (String) it.next();
  System.out.println(str.length());
}
```

程序在运行时发生了问题 **java.lang.ClassCastException**。为什么会发生类型转换异常呢？我们来分析下：由于集合中什么类型的元素都可以存储。导致取出时强转引发运行时 ClassCastException。怎么来解决这个问题呢？Collection虽然可以存储各种对象，但实际上通常Collection只存储同一类型对象。例如都是存储字符串对象。因此在JDK5之后，新增了**泛型**(**Generic**)语法，让你在设计API时可以指定类或方法支持泛型，这样我们使用API的时候也变得更为简洁，并得到了编译时期的语法检查。

#### 使用泛型的好处

- 将运行时期的 ClassCastException，转移到了编译时期变成了编译失败。
- 避免了类型强转的麻烦。

```java
Collection<String> list = new ArrayList<String>();
list.add("abc");
list.add("itcast");
// list.add(5); // 当集合明确类型后，存放类型不一致就会编译报错
// 集合已经明确具体存放的元素类型，那么在使用迭代器的时候，迭代器也同样会知道具体遍历元素类型
Iterator<String> it = list.iterator();
while(it.hasNext()){
  String str = it.next();
  // 当使用Iterator<String>控制元素类型后，就不需要强转了。获取到的元素直接就是String类型
  System.out.println(str.length());
}
```

#### 泛型的定义与使用

##### 定义和使用含有泛型的类

```java
修饰符 class 类名<代表泛型的变量> {  }
```

```java
class ArrayList<E>{ 
  public boolean add(E e){ }
  public E get(int index){ }
  ....
}
```

**在创建对象的时候确定泛型**

`ArrayList<String> list = new ArrayList<String>();`

此时，变量E的值就是String类型,那么我们的类型就可以理解为：

```java
class ArrayList<String>{ 
   public boolean add(String e){ }
   public String get(int index){  }
   ...
}
```

`ArrayList<Integer> list = new ArrayList<Integer>();`

此时，变量E的值就是Integer类型,那么我们的类型就可以理解为：

```java
class ArrayList<Integer> { 
   public boolean add(Integer e) { }
   public Integer get(int index) {  }
   ...
}
```

##### 含有泛型的方法

定义格式：

```java
修饰符 <代表泛型的变量> 返回值类型 方法名(参数) { }
```

```java
public class MyGenericMethod {
  public <MVP> void show(MVP mvp) {
    System.out.println(mvp.getClass());
  }
  public <MVP> MVP show2(MVP mvp) {
    return mvp;
  }
}
```

使用格式：**调用方法时，确定泛型的类型**

```java
public class GenericMethodDemo {
  public static void main(String[] args) {
    MyGenericMethod mm = new MyGenericMethod();
    // 演示看方法提示
    mm.show("aaa");
    mm.show(123);
    mm.show(12.45);
  }
}
```

##### 含有泛型的接口

定义格式：

```java
修饰符 interface 接口名<代表泛型的变量> { }
```

例如：

```java
public interface MyGenericInterface<E> {
  public abstract void add(E e);
  public abstract E getE();
}
```

使用格式：

**1、定义类时确定泛型的类型**

```java
public class MyImp1 implements MyGenericInterface<String> {
  @Override
  public void add(String e) {
    
  }
  @Override
  public String getE() {
    return null;
  }
}
```

**2、始终不确定泛型的类型，直到创建对象时，确定泛型的类型**

```java
public class MyImp2<E> implements MyGenericInterface<E> {
  @Override
  public void add(E e) {
    
  }
  @Override
  public E getE() {
    return null;
  }
}
```

确定泛型：

```java
public class GenericInterface {
  public static void main(String[] args) {
    MyImp2<String> my = new MyImp2<String>();
    my.add("aa");
  }
}
```

#### 泛型通配符

当使用泛型类或者接口时，传递的数据中，泛型类型不确定，可以通过通配符<?>表示。但是一旦使用泛型的通配符后，只能使用Object类中的共性方法，集合中元素自身方法无法使用。

##### 通配符的基本使用

泛型的通配符：不知道使用什么类型来接收的时候，此时可以使用 **?** , **?** 表示未知通配符。

此时只能接受数据，不能往该集合中存储数据。

举个例子：

```java
public static void main(String[] args) {
  Collection<Integer> list1 = new ArrayList<Integer>();
  getElement(list1);
  Collection<String> list2 = new ArrayList<String>();
  getElement(list2);
}
// ? 代表可以接收任意类型
public static void getElement(Collection<?> coll) { }
```

> tips : 泛型不存在继承关系 Collection list = new ArrayList(); 这种事错误的。
>
> #### 通配符高级使用----受限泛型
>
> 之前设置泛型的时候，实际上是可以任意设置的，只要是类就可以设置。但是在Java的泛型中可以指定一个泛型的**上限**和**下限**。
>
> **泛型的上限：**
>
> - 格式：`类型名称 <? extends 类> 对象名称`
> - 意义：`只能接收该类型及其子类`
>
> **泛型的下限：**
>
> - 格式：`类型名称 <? super 类> 对象名称`
> - 意义：`只能接收该类型及其父类型`
>
> 比如：现已知 Object 类，String类，Number类，Integer类，其中Number是Integer的父类
>
> ```java
> public static void main(Stirng[] args) {
> 	Collection<Integer> list1 = new ArrayList<Integer>();
> 	Collection<Stirng> list2 = new ArrayList<String>();
> 	Collection<Number> list3 = new ArrayList<Number>();
> 	Collection<Object> list4 = new ArrayList<Object>();
> 
> 	getElement1(list1);
> 	getElement1(list2); // 报错
> 	getElement1(list3);
> 	getElement1(list4); // 报错
> 
> 	getElement2(list1); // 报错
> 	getElement2(list2); // 报错
> 	getElement2(list3);
> 	getElement2(list4);
> }
> // 泛型的上限:此时的泛型?，必须是Number类型或者Number类型的子类
> public static void getElement1(Collection<? extends Number> coll) { }
> // 泛型的下限:此时的泛型?，必须是Number类型或者Number类型的父类
> public static void getElement2(Collection<? super Number> coll) { }
> ```



## 数据结构

#### 栈

- **栈**：**stack** ，又称堆栈，它是运算受限的线性表，其限制是仅允许在标的一端进行插入和删除操作，不允许在其他任何位置进行添加、查找、删除等操作。
- 先进后出。

#### 队列

- **队列：queue**，简称队，它同堆栈一样，也是一种运算受限的线性表，其限制是仅允许在表的一端进行插入， 而在表的另一端进行删除。
- 先进先出。

#### 数组

- **数组：Array**,是有序的元素序列，数组是在内存中开辟一段连续的空间，并在此空间存放元素。就像是一排出租屋，有100个房间，从001到100每个房间都有固定编号，通过编号就可以快速找到租房子的人。
- 查找元素快。
- 增删元素慢。

#### 链表

- **链表**:**linked list**,由一系列结点node（链表中每一个元素称为结点）组成，结点可以在运行时动态生成。每个结点包括两个部分：一个是存储数据元素的数据域，另一个是存储下一个结点地址的指针域。我们常说的链表结构有单向链表与双向链表，这里介绍的是**单向链表**。
- 多个节点之间，通过地址进行连接。
- 查找元素慢
- 增删元素快

#### 红黑树

- **二叉树**：**binary tree** ,是每个结点不超过2的有序**树（tree）** 。

简单的理解，就是一种类似于我们生活中树的结构，只不过每个结点上都最多只能有两个子结点。

二叉树是每个节点最多有两个子树的树结构。顶上的叫根结点，两边被称作“左子树”和“右子树”。

我们要说的是二叉树的一种比较有意思的叫做**红黑树**，红黑树本身就是一颗二叉查找树，将节点插入后，该树仍然是一颗二叉查找树。也就意味着，树的键值仍然是有序的。

红黑树的约束:
1. 节点可以是红色的或者黑色的
2. 根节点是黑色的
3. 叶子节点(特指空节点)是黑色的
4. 每个红色节点的子节点都是黑色的
5. 任何一个节点到其每一个叶子节点的所有路径上黑色节点数相同

红黑树的特点:

速度特别快,趋近平衡树,查找叶子元素最少和最多次数不多于二倍。



## List 集合

Collection中的常用几个子类（ `java.util.List` 集合、`java.util.Set` 集合）。

`java.util.List` 接口继承自 `Collection` 接口，是单列集合的一个重要分支，习惯性地会将实现了 `List` 接口的对象称为List集合。List集合还有一个特点就是元素有序，即元素的存入顺序和取出顺序一致。

#### 常用方法：

- `public void add(int index, E element)`: 将指定的元素，添加到该集合中的指定位置上。
- `public E get(int index)`:返回集合中指定位置的元素。
- `public E remove(int index)`: 移除列表中指定位置的元素, 返回的是被移除的元素。
- `public E set(int index, E element)`:用指定元素替换集合中指定位置的元素,返回值是更新前的元素。



## List 的子类

#### ArrayList 集合

`java.util.ArrayList` 集合数据存储的结构是数组结构。元素增删慢，查找快，由于日常开发中使用最多的功能为查询数据、遍历数据，所以 `ArrayList` 是最常用的集合。

#### LinkedList 集合

`java.util.LinkedList` 集合数据存储的结构是链表结构。方便元素添加、删除的集合。

> LinkedList是一个双向链表。

- `public void addFirst(E e)`：将指定元素插入此列表的开头。
- `public void addLast(E e)`：将指定元素添加到此列表的结尾。
- `public E getFirst()`：返回此列表的第一个元素。
- `public E getLast()`：返回此列表的最后一个元素。
- `public E removeFirst()`：移除并返回此列表的第一个元素。
- `public E removeLast()`：移除并返回此列表的最后一个元素。
- `public E pop()`：从此列表所表示的堆栈处弹出一个元素。
- `public void push(E e)`：将元素推入此列表所表示的堆栈。
- `public boolean isEmpty()`：如果列表不包含元素，则返回true。



## Set 接口

`java.util.Set` 接口和 `java.util.List` 接口一样，同样继承自 `Collection` 接口，它与 `Collection` 接口中的方法基本一致，并没有对 `Collection` 接口进行功能上的扩充，只是比 `Collection` 接口更加严格了。与 `List` 接口不同的是，`Set` 接口中元素无序，并且都会以某种规则保证存入的元素不出现重复。

`Set` 集合有多个子类，这里介绍其中的 `java.util.HashSet`、`java.util.LinkedHashSet` 这两个集合。

#### HashSet 集合

`java.util.HashSet` 是 `Set` 接口的一个实现类，它所存储的元素是不可重复的，并且元素都是无序的。 `java.util.HashSet` 底层的实现其实是一个 `java.util.HashMap` 支持。

`HashSet` 是根据对象的哈希值来确定元素在集合中的存储位置，因此具有良好的存取和查找性能。保证元素唯一性的方式依赖于：`hashCode` 与 `equals` 方法。

##### HashSet存储自定义类型元素

给 `HashSet` 中存放自定义类型元素时，需要重写对象中的 `hashCode` 和 `equals` 方法，建立自己的比较方式，才能保证 `HashSet` 集合中的对象唯一。

```java
public class Student {
  private String name;
  private int age;

  public Student() {
  }

  public Student(String name, int age) {
    this.name = name;
    this.age = age;
  }

  public String getName() {
    return name;
  }

  public void setName(String name) {
    this.name = name;
  }

  public int getAge() {
    return age;
  }

  public void setAge(int age) {
    this.age = age;
  }

  @Override
  public boolean equals(Object o) {
    if (this == o)
      return true;
    if (o == null || getClass() != o.getClass())
      return false;
    Student student = (Student) o;
    return age == student.age && Objects.equals(name, student.name);
  }

  @Override
  public int hashCode() {
    return Objects.hash(name, age);
  }
}
```

#### LinkedHashSet 集合

`java.util.LinkedHashSet` 它是链表和哈希表组合的一个数据存储结构，它是有序的。

```java
public class LinkedHashSetDemo {
	public static void main(String[] args) {
		Set<String> set = new LinkedHashSet<String>();
		set.add("bbb");
		set.add("aaa");
		set.add("abc");
		set.add("bbc");
    Iterator<String> it = set.iterator();
		while (it.hasNext()) {
			System.out.println(it.next());
		}
	}
}
结果：
  bbb
  aaa
  abc
  bbc
```



## Collections

- `java.utils.Collections` 是集合工具类，用来对集合进行操作。

常用功能：

- `public static <T> boolean addAll(Collection<T> c, T... elements)  `：往集合中添加一些元素。
- `public static void shuffle(List<?> list)` ：打乱集合顺序。
- `public static <T> void sort(List<T> list)`：将集合中元素按照默认规则排序。
- `public static <T> void sort(List<T> list，Comparator<? super T> )`：将集合中元素按照指定规则排序。

#### Comparator 比较器

- `public static <T> void sort(List<T> list)`：将集合中元素按照默认规则排序。

```java
public class CollectionsDemo {
  public static void main(String[] args) {
    ArrayList<Stirng> list = new ArrayList<String>();
    list.add("cba");
    list.add("aba");
    list.add("sba");
    list.add("nba");
    Collections.sort(list);
    System.out.println(list);
  }
}
// [aba, cba, nba, sba];
```

- `public int compare(Sttring o1, String o2)`：比较其两个参数的顺序。

```java
public class CollectionDemo {
  public static void main(String[] args) {
    ArrayList<String> list = new ArrayList<String>();
    list.add("cba");
    list.add("aba");
    list.add("sba");
    list.add("nba");
    Collections.sort(list, new Comparator<String>() {
      @Override
      public int compare(String o1, String o2) {
        return o2.charAt(0) - o1.charAt(0);
      }
    });
    System.out.println(list);
  }
}
// [sba, nba, cba, aba]
```

#### Comparable和Comparator两个接口的区别

**Comparable** 强行对实现它的每个类的对象进行整体排序。这种排序被称为类的自然排序，类的compareTo方法被称为它的自然比较方法。只能在类中实现compareTo()一次，不能经常修改类的代码实现自己想要的排序。实现此接口的对象列表（和数组）可以通过Collections.sort（和Arrays.sort）进行自动排序，对象可以用作有序映射中的键或有序集合中的元素，无需指定比较器。

**Comparator** 强行对某个对象进行整体排序。可以将Comparator 传递给sort方法（如Collections.sort或 Arrays.sort），从而允许在排序顺序上实现精确控制。还可以使用Comparator来控制某些数据结构（如有序set或有序映射）的顺序，或者为那些没有自然顺序的对象collection提供排序。

```java
public class Student implements Comparable<Student>{
  ....
  @Override
  public int compareTo(Student o) {
    return this.age-o.age;//升序
  }
}
```



## Map 集合

`java.util.Map`

#### Map 常用子类

- **HashMap**：存储数据采用的哈希表结构，元素的存取顺序不能保证一致。由于要保证键的唯一、不重复、需要重写键的 hashCode() 方法、equals() 方法。
- **LinkedHashMap**：HashMap 的子类。存储数据采用的哈希表结构+链表结构。通过链表结构可以保证元素的存取顺序一致；通过哈希表结构可以保证键的唯一、不重复，需要重写键的 hashCode() 方法、equals() 方法。

#### Map 接口中的常用方法

- `public V put(K key, V value)`:  添加指定键值对。
- `public V remove(Object key)`: 删除指定键值对，返回被删除元素的值。
- `public V get(Object key)` 根据指定的键，获取对应的值。
- `boolean containsKey(Object key)  ` 判断集合中是否包含指定的键。
- `public Set<K> keySet()`: 获取Map集合中所有的键，存储到Set集合中。
- `public Set<Map.Entry<K,V>> entrySet()`: 获取到Map集合中所有的键值对对象的集合(Set集合)。

```java
// 创建 map对象
HashMap<String, String>  map = new HashMap<String, String>();

// 添加元素到集合
map.put("黄晓明", "杨颖");
map.put("文章", "马伊琍");
map.put("邓超", "孙俪");
System.out.println(map);

// String remove(String key)
System.out.println(map.remove("邓超"));
System.out.println(map);

// 想要查看 黄晓明的媳妇 是谁
System.out.println(map.get("黄晓明"));
System.out.println(map.get("邓超"));  
```

> tips:
> 使用put方法时，若指定的键(key)在集合中没有，则没有这个键对应的值，返回null，并把指定的键值添加到集合中； 
> 若指定的键(key)在集合中存在，则返回值为集合中键对应的值（该值为替换前的值），并把指定键所对应的值，替换成指定的新值。 

#### Map 集合遍历

```java
HashMap<String, String> map = new HashMap<String, String>();
Set<String> keys = map.keySet();
for (String key : keys) {
  String value = map.get(key);
}
```

```java
HashMap<String, String> map = new HashMap<String, String>();
Set<Entry<String, String>> entrySet = map.entrySet();
for (Entry<String, String> entry : entrySet) {
  String key = entry.getKey();
  String value = entry.getValue();
}
```



## 异常

#### 异常体系

异常的根类是 `java.lang.Throwable` ，其下有两个子类： `java.lang.Error` 与 `java.lang.Exception` ，平常所说的异常指 `java.lang.Exception`。

##### Throwable 体系

- **Error**：严重错误 Error，无法通过处理的错误，只能事先避免。
- **Exception**：表示异常，异常产生后程序员可以通过代码的方式纠正。

##### Throwable 中的常用方法

- `public void printStackTrace()` ：打印异常的详细信息。
- `public String getMessage()` ：获取发生异常的原因。
- `public String toString()` ：获取异常的类型和异常描述信息（不用）。

#### 异常分类

- 编译期异常：checked 异常。
- 运行期异常：runtime 异常。



## 异常的处理

Java 异常处理的五个关键字：**try、catch、finally、throw、throws**

#### 抛出异常 throw

```java
throw new 异常类名(参数);
```

例如：

```java
throw new NullPointerException("要访问的arr数组不存在");
throw new ArrayIndexOutOfBoundsException("数组越界");
```

#### Objects 非空判断

- `public static <T> T requireNonNull(T obj)`：查看指定引用对象不是null。

源码对 null 进行了抛出异常操作：

```java
public static <T> T requireNonNull(T obj) {
  if (obj == null)
    throw new NullPointerException();
  return obj;
}
```

#### 声明异常 throws

**声明异常**：将问题标识出来，报告给调用者。

```java
修饰符 返回值类型 方法名(参数) throws 异常类名,异常类名2... { }
```

```java
public class ThrowsDemo {
  public static void main(String[] args) throws FileNotFoundException {
    read("a.txt");
  }
  
  public static void read(String path) throws FileNotFoundException {
    if (!path.equals("a.txt")) {
      throws new FileNotFoundException("文件不存在").
    }
  }
}
```

#### 捕获异常 try...catch

- **捕获异常**：对出现的异常进行指定方式的处理。

```java
try {
  // 可能出现异常的代码
} catch (异常类型 e) {
  // 处理异常的代码
  // 记录日志/打印异常信息/继续抛出异常
}
```

```java
public class TryCatchDemo {
  public static void main(String[] args) {
		try {
      read("b.txt");
    } catch (FileNotFoundException e) {
      System.out.println(e);
    }
    System.out.println("over");
  }
  
  public static void read(String path) throws FileNotFoundException {
    if (!path.equals("a.txt")) {
      throws new FileNotFoundException("文件不存在").
    }
  }
}
```

##### 获取异常信息

- `public String getMessage()` ：获取异常的描述信息，原因。
- `public String toString()` ：获取异常的类型和异常描述信息（不用）。
- `public void printStackTrace()` ：打印异常的跟踪栈信息并输出到控制台。

#### finally 代码块

**finally** ：无论异常是否发生，都会执行。

`try...catch...finally`

```java
public class TryCatchDemo {
  public static void main(String[] args) {
    try {
      read("a.txt");
    } catch (FileNotFoundException e) {
      throw new RuntimeException(e);
    } finally {
      System.out.println("不管程序怎么样，这里都将会被执行。");
    }
    System.out.println("over");
  }
  public static void read(String path) throws FileNotFoundException {
    if (!path.equals("a.txt")) {
      throw new FileNotFoundException("文件不存在");
    }
  }
}
```



## 自定义异常

`RegisterException` ，注册异常类。

- 自定义编译期异常：自定义类 并继承于 `java.lang.Exception`。
- 自定义运行期异常：自定义类 并继承于 `java.lang.RuntimeException`。

举个例子：

```java
public class RegisterException extends Exception {
  public RegisterException() {
    
  }
  public RegisterException(String message) {
    super(message);
  }
}
```

```java
public class Demo {
  private static String[] names = {"bill", "hill", "jill"};
  public static void main(String[] args) {
    try {
      checkUserName("null");
      System.out.println("注册成功");
    } catch (RegisterException e) {
      e.printStackTrace();
    }
  }
  public static boolean checkUserName(String uname) throws LoginException {
    for (String name: names) {
      if (name.equals(uname)) {
        throw new RegisterException(name + "已经被注册！");
      }
    }
    return true;
  }
}
```



## 多线程

### 多线程

#### 并发与并行

- **并发** ：指两个或多个事件在**同一个时间段内**发生。
- **并行** ：指两个或多个事件在**同一时刻**发生（同时发生）。

#### 线程与进程

- **进程**：是指一个内存中运行的应用程序，每个进程都有一个独立的内存空间，一个应用程序可以同时运行多个进程；进程也是程序的一次执行过程，是系统运行程序的基本单位；系统运行一个程序即是一个进程从创建、运行到消亡的过程。

- **线程**：线程是进程中的一个执行单元，负责当前进程中程序的执行，一个进程中至少有一个线程。一个进程中是可以有多个线程的，这个应用程序也可以称之为多线程程序。 

简而言之:一个程序运行后至少有一个进程，一个进程中可以包含多个线程。

**线程调度:**

- 分时调度

  所有线程轮流使用 CPU 的使用权，平均分配每个线程占用 CPU 的时间。

- 抢占式调度

  优先让优先级高的线程使用 CPU，如果线程的优先级相同，那么会随机选择一个(线程随机性)，Java使用的为抢占式调度。

#### 创建线程类

Java 使用 `java.lang.Thread` 类代表**线程**，所有的线程对象都必须是Thread类或其子类的实例。每个线程的作用是完成一定的任务，实际上就是执行一段程序流即一段顺序执行的代码。Java使用线程执行体来代表这段程序流。Java中通过继承Thread类来**创建**并**启动多线程**的步骤如下：

1. 定义Thread类的子类，并重写该类的run()方法，该run()方法的方法体就代表了线程需要完成的任务,因此把run()方法称为线程执行体。
2. 创建Thread子类的实例，即创建了线程对象
3. 调用线程对象的start()方法来启动该线程

测试类：

```java
public class Demo01 {
	public static void main(String[] args) {
		//创建自定义线程对象
		MyThread mt = new MyThread("新的线程！");
		//开启新线程
		mt.start();
		//在主方法中执行for循环
		for (int i = 0; i < 10; i++) {
			System.out.println("main线程！"+i);
		}
	}
}
```

自定义线程类：

```java
public class MyThread extends Thread {
	// 定义指定线程名称的构造方法
	public MyThread(String name) {
		// 调用父类的String参数的构造方法，指定线程的名称
		super(name);
	}
	/**
	 * 重写run方法，完成该线程执行的逻辑
	 */
	@Override
	public void run() {
		for (int i = 0; i < 10; i++) {
			System.out.println(getName()+"：正在执行！"+i);
		}
	}
}
```

#### Thread 类

`java.lang.Thread`

**构造方法**

- `public Thread()`：分配一个新的线程对象。
- `public Thread(String name)`：分配一个指定名字的线程对象。
- `public Thread(Runnable target)`：分配一个带有指定目标新的线程对象。
- `public Thread(Tunnable target, String name)`：分配一个带有指定目标的线程对象并指定名字。

**常用方法**

- `public String getName()`
- `public void start()`
- `public void run()`
- `public static void sleep(long millis)`
- `public static Thread currentThread()`

#### 创建线程方式二

`java.lang.Runnable`，只需要重写run方法即可。

```java
public class MyRunnable implements Runnable {
  @Override
  public void run() {
    for (int i = 0; i < 10; i++) {
      System.out.println(Thread.currentThread().getName()+" "+i);
    }
  }
}
```

```java
public class Demo {
  public static void main(String[] args) {
    MyRunnable mr = new MyRunnable();
    Thread t = new Thread(mr, "小黑");
    t.start();
    for (int i = 0; i < 10; i++) {
    	System.out.println("旺财" + i); 
    }
  }
}
```

通过实现Runnable接口，使得该类有了多线程类的特征。run()方法是多线程程序的一个执行目标。所有的多线程 代码都在run方法里面。Thread类实际上也是实现了Runnable接口的类。

#### Thread 和 Runnable 的区别

如果一个类继承Thread，则不适合资源共享。但是如果实现了Runnable接口的话，则很容易实现资源共享。

**实现Runnable接口比继承Thread类所具有的优势**

1.适合多个相同的程序代码的线程去共享同一个资源。
2.可以避免java中单继承的局限性。
3.增加程序的健壮性，实现解耦操作，代码可以被多个线程共享，代码和线程独立。
4.线程池只能放入实现Runnable或Callable类线程，不能直接放入继承Thread的类。

#### 匿名内部类方式实现线程的创建

```java
public class NoNameInnerClassThread {
  public static void main(String[] args) {
//    new Runnable() {
//      public void run() {
//    		for (int i = 0; i < 10; i++) {
//          System.out.println("aaa");
// 			  }
//      }
//    }; // 这个整体 相当于new MyRunnable()
    
    Runnable r = new Runnable() {
      public void run() {
        for (int i = 0; i < 10; i++) {
          System.out.println("bbb");
    		}
      }
    }
    
    new Thread(r).start();
    
    for (int i = 0; i < 10; i++) {
      System.out.println("ccc");
    }
  }
}
```



### 线程安全

#### 线程同步

使用 `synchronized` 实现线程同步。

三种方式实现同步操作：

1. 同步代码块。
2. 同步方法。
3. 锁机制。

#### 同步代码块

```java
synchronized (同步锁) {
  
}
```

```java
public class Ticket implements Runnable {
  Object lock = new Object();
  
  @Override
  public void run() {
    synchronized (lock) {

    }
  }
}
```

#### 同步方法

```java
public synchronized void method() {
  
}
```

> 同步锁是谁？
>
> 对于非static方法，同步锁就是this。
>
> 对于static方法，使用当前方法所在类的字节码对象（类名.class）。

```java
public class Ticket implements Runnable {
  @Override
  public void run() {
    sellTicket();
  }
  
  public synchronized void sellTicket() {
    
  }
}
```

#### Lock 锁

`java.util.concurrent.locks.Lock` 机制提供了比synchronized代码块和synchronized方法更广泛的锁定操作,同步代码块/同步方法具有的功能Lock都有,除此之外更强大,更体现面向对象。

Lock 锁也称同步锁，加锁与释放锁方法化了：

- `public void lock()`
- `public void unlock()`

```java
public class Ticket implements Runnable {
  Lock lock = new reetrantLock();
  
  @Override
  public void run() {
    lock.lock();
    // ...
    lock.unlock();
  }
}
```

### 线程状态

`java.lang.Thread.State` 给出了六种线程状态：

- New（新建）
- Runnable（可运行）
- Blocked（锁阻塞）
- Waiting（无限等待）
- Timed Waiting（计时等待）
- Teminated（被终止）

### 等待唤醒机制

#### 等待唤醒中的方法

1. wait：线程不再活动，不再参与调度，进入 wait set 中，因此不会浪费 CPU 资源，也不会去竞争锁了，这时的线程状态即是 WAITING。它还要等着别的线程执行一个**特别的动作**，也即是“**通知（notify）**”在这个对象上等待的线程从wait set 中释放出来，重新进入到调度队列（ready queue）中
2. notify：则选取所通知对象的 wait set 中的一个线程释放；例如，餐馆有空位置后，等候就餐最久的顾客最先入座。
3. notifyAll：则释放所通知对象的 wait set 上的全部线程。

**实例**

包子类资源：

```java
public class BaoZi {
  String pier;
  String xianer;
  boolean flag = false; // 包子资源 是否存在 包子资源状态
}
```

吃货线程类：

```java
public class ChiHuo extends Thread {
  private BaoZi bz;
  public ChiHuo(Stirng name, BaoZi bz) {
    super(name);
    this.bz = bz;
  }
  @Override
  public void run() {
    synchronized(bz) {
      if (bz.flag == false) { // 没包子
       	try {
          bz.wait();
        } catch (InterruptedException e) {
          e.printStackTrace();
        }
      }
      System.out.println("吃货正在吃"+bz.pier+bz.xianer+"包子");
      bz.flag = false;
      bz.notify();
    }
  }
}
```

包子铺线程类：

```java
public class BaoZiPu extends Thread {
  private BaoZi bz;
  
  public BaoZiPu(String name, BaoZi bz) {
    super(name);
    this.bz = bz;
  }
  
  @Override
  public void run() {
    int count = 0;
    // 造包子
    while(true) {
      // 同步
      synchronized(bz) {
        if (bz.flag == true) { // 包子资源 存在
          try {
            bz.wait();
          } catch (InterruptedException e) {
            e.printStackTrace();
          }
        }
        
        // 没有包子 造包子
        System.out.println("包子铺开始做包子");
        if (count%2 == 0) {
          bz.pier = "冰皮";
          bz.xianer = "五仁";
        } else {
          bz.pier = "薄皮";
          bz.xianer = "牛肉大葱";
        }
        count++;
        
        bz.flag = true;
        System.out.println("包子造好了:"+bz.pier+bz.xianer); 
        System.out.println("吃货来吃吧");
				// 唤醒等待线程 (吃货)
				bz.notify();
      }
    }
  }
}
```

测试类：

```java
public class Demo {
  public static void main(String[] args) {
    BaoZi bz = new BaoZi();
    
    ChiHuo ch = new ChiHuo("吃货", bz);
    BaoZiPu bzp = new BaoZiPu("包子铺", bz);
    
    ch.start();
    bzp.start();
  }
}
```

### 线程池

- **线程池**：其实就是一个容纳多个线程的容器，其中的线程可以反复使用，省去了频繁创建线程对象的操作， 无需反复创建线程而消耗过多资源。



## Lambda 表达式

**传统写法**

```java
public class DemoRunnable {
  public static void main(String[] args) {
    Runnable task = new Runnable() {
      @Override
      public void run() {
      	System.out.println("多线程任务执行!");  
      }
    };
    new Thread(task).start();
  }
}
```

**Lambda 优雅写法** Java8全新语法

```java
public class DemoLambdaRunnable {
  public static void main(String[] args) {
    new Thread(() -> System.out.println("多线程任务执行！")).start();
  }
}
```

#### Lambda 标准格式

```java
(参数类型 参数名称) -> { 代码语句 }
```



## File 类

`java.io.File` 类是文件和目录路径名的抽象表示。

#### 构造方法

- `public File(String pathname)`
- `public File(String parent, String child)`
- `public File(File parent, String child)`

#### 常用方法

**获取**

- `public String getAbsolutePath()`：返回此File的绝对路径名
- `public String getPath()`：返回File路径名
- `public String getName()`：返回File表示的文件或目录名
- `public long length()`：返回File表示的文件的长度

**判断**

- `public boolean exists()` ：文件或目录是否存在
- `public boolean isDirectory()` ：是否为目录
- `public boolean isFile()` ：是否为文件

**创建删除**

- `public boolean createNewFile()` ：文件不存在时，创建一个新的空文件
- `public boolean delete()` ：删除文件或目录
- `public boolean mkdir()` ：创建目录
- `public boolean mkdirs()` ：创建目录，包活不存在的父目录

#### 目录的遍历

- `public String[] list()` ：返回该目录中所有子文件或目录的名称
- `public File[] listFiles()` ：返回该目录中所有的子文件或目录

```java
public class FileFor {
  public static void main(String[] args) {
    File dir = new File("d:\\java_code");
    // 获取当前目录下的文件及文件夹的名称
    String[] names = dir.list();
    for (String name : names) {
      System.out.println(name);
    }
    // 获取当前目录下的文件及文件夹对象
    File[] files = dir.listFiles();
    for(File file : files) {
      System.out.println(file);
    }
  }
}
```



## 递归

#### 递归打印多级目录

```java
public class Dmoe {
	public static void main(String[] args) {
		File dir = new File("D:\\aa");
		printDir(dir);
	}

	public static void printDir(File dir) {
		File[] files = dir.listFiles;
		for (File file: files) {
			if (file.isFile) {
				System.out.println("文件名："+file.getAbsolutePath());
			} else {
				System.out.println("目录："+file.getAbsolutePath());
				printDir(file);
			}
		}
	}
}
```



## IO

#### IO 分类

根据数据的流向分为：

- **输入流** ：把数据从`其他设备`上读取到`内存`中的流。 
- **输出流** ：把数据从`内存` 中写出到`其他设备`上的流。

根据数据的类型分为：

- **字节流** ： 把数据从`内存` 中写出到`其他设备`上的流。
- **字符流** ： 以字符为单位，读写数据的流。

#### 顶级父类

|            |           **输入流**            |              输出流              |
| :--------: | :-----------------------------: | :------------------------------: |
| **字节流** | 字节输入流 **InputStream** | 字节输出流 **OutputStream** |
| **字符流** |   字符输入流 **Reader**   |    字符输出流 **Writer**    |

### 字节流

#### 字节输出流【OutputStream】

`java.io.OutputStream` ，字节输出流的所有类的超类。

- `public void close()`
- `public void flush()`
- `public void write(byte[] b)`
- `public void write(byte[] b, int off, int len)`

#### FileOutputStream

`java.io.FileOutputStream` 类是文件输出流，用于将数据写出到文件。

**构造方法**

- `public FileOutputStream(File file)`
- `public FileOutputStream(String name)`

**写出字节数据**

- `write(int b)` ：写出字节

```java
public static void main(String[] args) throws IOException {
  FileOutputStream fos = new FileOutputStream("a.txt");
  fos.write(97);
  fos.write(98);
  fos.close();
}
// ab
```

**写出字节数组**

- `write(byte[] b)` 

```java
public static void main(String[] args) throws IOException {
  FileOutputStream fos = new FileOutputStream("a.txt");
  byte[] b = "搬砖程序员".getBytes();
  fos.write(b);
  fos.close();
}
// 搬砖程序员
```

**写出指定长度字节数组**

- `write(byte[] b, int off, int len)`

```java
public static void main(String[] args) throws IOException {
  FileOutputStream fos = new FileOutputStream("a.txt");
  byte[] b = "abcde".getBytes();
  fos.write(b, 2, 2); // 从2开始，两个字节
  fos.close();
}
// cd
```

**数据追加续写**

- `public FileOutputStream(File file, boolean append)`
- `public FileOutputStream(String name, boolean append)`

参数boolean，`true`表示追加数据，`false` 表示清空原有数据。

```java
public static void main(String[] args) throws IOException {
  FileOutputStream fos = new FileOutputStream("a.txt", true);
  byte[] b = "abcde".getBytes();
  fos.write(b);
  fos.close();
}
```

**写出换行**

`\r\n`

```java
public static void main(String[] args) throws IOException {
  FileOutputStream fos = new FileOutputStream("a.txt");
  byte[] words = {97, 98, 99, 100, 101};
  for (int i = 0; i < words.length; i++) {
    fos.write(words[i]);
    fos.write("\r\n".getBytes());
  }
  fos.close();
}
```

> - 回车符 `\r` 和 换行符 `\n`
>   - 回车符：回到一行的开头（return）。
>   - 换行符：下一行（newline）。
> - 系统中的换行：
>   - Windows系统里，每行结尾是 `回车+换行`，即 `\r\n` ；
>   - Unix 系统里，每行结尾只有 `换行` ，即 `\n` ；
>   - Max 系统里，每行结尾是 `回车` ，即 `\r` 。从 Max OS X 开始与 Linux 统一。

#### 字节输入流【InputStream】

`java.io.InputStream`

- `public void close()`
- `public abstract int read()`
- `public int read(byte[] b)`

#### FileInputStream 类

`java.io.FileInputStream` 文件输入流，从文件中读取字节。

**构造方法**

- `FileInputStrram(File file)`
- `FileInputStream(String name)`

**读取字节数据**

- `read` 读取字节，每次读取一个字节数据，提升为int类型，读取到文件末尾，返回 `-1` 。

```java
public static void main(String[] args) throws IOException {
  FileInputStream fis = new FileInputStream("a.txt");
  int b;
  while ( (b = fis.read()) != -1) {
    System.out.println((char)b);
  }
  fis.close();
}
```

**使用字节数组读取**

- `read(byte[] b)` 

```java
public static void main(String[] args) throws IOException {
  FileInputStream fis = new FileInputStream("a.txt");
  int len;
  byte[] b = new byte[2];
  while ( (len = fis.read()) != -1) {
    System.out.println(new String(b, 0, len));
  }
  fis.close();
}
// 输出：
ab
cd
e
```

#### 字节流复制图片

```java
public static void main(String[] args) throws IOException {
  FileInputStream fis = new FileInputStream("D:\\a.jpg");
  FileOutputStream fos = new FileOutputStream(b.jpg);
  byte[] b = new byte[1024];
  int len;
  while ((len = fis.read(b)) != -1) {
    fos.write(b, 0, len);
  }
  fos.close();
  fis.close();
}
```

### 字符流

#### 字符输入流【Reader】

`java.io.Reader` 抽象类是表示用于读取字符流的所有类的超类。

- `public void close()`
- `public int read()`
- `public int read(char[] cbuf)`

#### FileReader 类

`java.io.FileReader`

**构造方法**

- `FileReader(File file)`
- `FileReader(String fileName)`

**读取字符数据**

**读取字符**： `read` 方法，每次读取一个字符的数据，提升为int类型，读取到文件末尾，返回`-1` 。

**使用字符数组读取**：`read(char[] cbuf)`

```java
public static void main(String[] args) throws IOException {
  FileReader fr = new FileReader("a.txt");
  int len;
  char[] cbuf = new char[2];
  while((len = fr.read(cbuf)) != -1) {
    System.out.println(new String(cbuf, 0, len));
  }
  fr.close();
}
```

#### 字符输出流【Writer】

`java.io.Writer` 抽象类是表示用于写出字符流的所有类的超类。

- `void write(int c)`
- `void write(char[] cbuf)`
- `abstract void write(char[] cbuf, int off, int len)`
- `void write(String str)`
- `void write(String str, int off, int len)`
- `void flush()`
- `void close()`

#### FileWriter 类

`java.io.FileWriter` 

**构造方法**

- `FileWriter(File file)`
- `FileWriter(String fileName)`

**写出数据**

- **写出字符**：`write(int b)` 

```java
public static void main(String[] args) throws IOException {
  FileWriter fw = new FileWriter("a.txt");
  fw.write('刷');
  fw.flush();
  fw.write('新');
  fw.flush();

  fw.write('关');
  fw.close();
  fw.write('闭'); //【报错】java.io.IOException: Stream closed
  fw.close();
}
```

- **写出字符数组** ：`write(char[] cbuf)` 和 `write(char[] cbuf, int off, int len)` 

```java
FileWriter fw = new FileWriter("a.txt");
char[] chars = "搬砖程序员".toCharArray();
fw.write(chars);
fw.write(chars, 2, 2);
fw.close();
```

- **写出字符串**：`write(String str)` 和 `wirte(String str, int off, int len)` 

```java
FileWriter fw = new FileWriter("a.txt");
String msg = "搬砖程序员";
fw.write(msg);
fw.write((msg, 2, 2));
fw.close();
```

- **续写和换行** ：`\r\n`

```java
FileWriter fw = new FileWriter("a.txt");
fw.write("搬砖");
fw.write("\r\n");
fw.write("程序员");
fw.close();
```



## IO 异常的处理

`try...catch...finally`

#### JDK7 前处理

```java
public static void main(String[] args) {
    FileWriter fw = null;
    try {
        fw = new FileWriter("a.txt");
        fw.write("搬砖程序员");
    } catch (IOException e) {
        e.printStackTrace();
    } finally {
        try {
            if (fw != null) {
                fw.close();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
```

#### JDK7的处理（扩展）

还可以使用JDK7优化后的`try-with-resource` 语句，该语句确保了每个资源在语句结束时关闭。所谓的资源（resource）是指在程序完成后，必须关闭的对象。

格式：

```java
try (创建流对象语句，如果多个,使用';'隔开) {
	// 读写数据
} catch (IOException e) {
	e.printStackTrace();
}
```

```java
public static void main(String[] args) {
    try ( FileWriter fw = new FileWriter("fw.txt"); ) {
        fw.write("搬砖程序员"); 
    } catch (IOException e) {
        e.printStackTrace();
    }
}
```

#### JDK9的改进（扩展）

JDK9中`try-with-resource` 的改进，对于**引入对象**的方式，支持的更加简洁。被引入的对象，同样可以自动关闭，无需手动close，我们来了解一下格式。

改进前格式：

```java
// 被final修饰的对象
final Resource resource1 = new Resource("resource1");
// 普通对象
Resource resource2 = new Resource("resource2");
// 引入方式：创建新的变量保存
try (Resource r1 = resource1;
     Resource r2 = resource2) {
     // 使用对象
}
```

改进后格式：

```java
// 被final修饰的对象
final Resource resource1 = new Resource("resource1");
// 普通对象
Resource resource2 = new Resource("resource2");

// 引入方式：直接引入
try (resource1; resource2) {
     // 使用对象
}
```

实例：

```java
public class TryDemo {
    public static void main(String[] args) throws IOException {
       	// 创建流对象
        final  FileReader fr  = new FileReader("in.txt");
        FileWriter fw = new FileWriter("out.txt");
       	// 引入到try中
        try (fr; fw) {
          	// 定义变量
            int b;
          	// 读取数据
          	while ((b = fr.read())!=-1) {
            	// 写出数据
            	fw.write(b);
          	}
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
```



## 属性集

`java.util.Properties ` 继承于` Hashtable` ，来表示一个持久的属性集。它使用键值结构存储数据，每个键及其对应值都是一个字符串。该类也被许多Java类使用，比如获取系统属性时，`System.getProperties` 方法就是返回一个`Properties`对象。

#### Properties 类

**构造方法**

- `public properties()`

**基本的存储方法**

- `public Object setProperty(String key, String value)`
- `public String getProperty(String key)`
- `public Set<String> stringPropertyNames()`

```java
public class ProDemo {
    public static void main(String[] args) throws FileNotFoundException {
        // 创建属性集对象
        Properties properties = new Properties();
        // 添加键值对元素
        properties.setProperty("filename", "a.txt");
        properties.setProperty("length", "209385038");
        properties.setProperty("location", "D:\\a.txt");
        // 打印属性集对象
        System.out.println(properties);
        // 通过键,获取属性值
        System.out.println(properties.getProperty("filename"));
        System.out.println(properties.getProperty("length"));
        System.out.println(properties.getProperty("location"));

        // 遍历属性集,获取所有键的集合
        Set<String> strings = properties.stringPropertyNames();
        // 打印键值对
        for (String key : strings ) {
          	System.out.println(key+" -- "+properties.getProperty(key));
        }
    }
}
输出结果：
{filename=a.txt, length=209385038, location=D:\a.txt}
a.txt
209385038
D:\a.txt
filename -- a.txt
length -- 209385038
location -- D:\a.txt
```

**与流相关的方法**

- `public void load(InputStream inStream)` ：从字节输入流中读取键值对。

```java
public class ProDemo2 {
    public static void main(String[] args) throws FileNotFoundException {
        // 创建属性集对象
        Properties pro = new Properties();
        // 加载文本中信息到属性集
        pro.load(new FileInputStream("read.txt"));
        // 遍历集合并打印
        Set<String> strings = pro.stringPropertyNames();
        for (String key : strings ) {
          	System.out.println(key+" -- "+pro.getProperty(key));
        }
     }
}
输出结果：
filename -- a.txt
length -- 209385038
location -- D:\a.txt
```



## 缓冲流

缓冲流也叫高效流，是对4个基本的 `FileXxx` 流的增强。

- **字节缓冲流**：`BufferedInputStream` , `BufferedOutputStream`
- **字符缓冲流**：`BufferedReader` , `BufferedWriter`

#### 字节缓冲流

**构造方法**

- `public BufferedInputStream(InputStream in)` ：创建缓冲输入流
- `public BufferedOutputStream(OutputStream out)` ：创建缓冲输出流

```java
BufferedInputStream bis = new BufferedInputStream(new FileInputStream("a.txt"));
BufferedOutputStream bos = new BufferedOutputStream(new FileOutputStream("b.txt"));
```

#### 字符缓冲流

**构造方法**

- `public BufferedReader(Reader in)` ：创建缓冲输入流
- `public BufferedWriter(Writer out)` ：创建缓冲输出流

```java
BufferedReader br = new BufferedReader(new FileReader("a.txt"));
BufferedWriter bw = new BufferedWriter(new FileWriter("b.txt"));
```

**特有方法**

- BufferedReader ：`public String readLine()` ：读取一行
- BufferedWriter ：`public void newLine()` ：写一行分隔符，由系统属性定义符号



## 转换流

#### InputStreamReader 类

转换流 `java.io.InputStreamReader` ，是 Reader 的子类，是字符流到字节流到桥梁。它读取字节，并使用指定 的字符集将其解码为字符。

**构造方法**

- `InputStreamReader(InputStream in)` ：创建一个使用默认字符集到字符流。
- `InputStreamReader(InputStream in, String charsetName)` ：创建一个指定字符集的字符流。

**指定编码读取**

```java
String fileName = "D:\\a.txt";
InputStreamReader isr = new InputStreamReader(new FileInputStream(fileName), "GBK");
int read;
while ((read = isr.read()) != -1) {
    System.out.println((char)read);
}
isr.close();
```

#### OutputStreamWriter 类

转换流 `java.io.OutputStreamWriter` ，是Writer的子类，是重字符流到字节流的桥梁。

**构造方法**

- `OutputStreamWriter(OutputStream in)` ：创建一个使用默认字符集的字符流。
- `OutputStreamWriter(OutputStream in, String charsetName)` ：创建一个指定字符集的字符流。

```java
OutputStreamWriter osw = new OutputStreamWriter(new FileOutputStream(fileName),"GBK");
```





## 序列化

day10





