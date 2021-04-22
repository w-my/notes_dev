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

#### 面向对象的三大特征

- **封装**：将一些细节信息隐藏起来，对于外界不可见；
- **继承**：
- **多态**：



## 类

```java
public class Demo01 {
    public static void main(String[] args) {
        Dog dogA = new Dog();
        dogA.setName("小狗");
        dogA.run();
      
      	Dog dogB = new Dog("大狗", true);
    }
}

class Dog {
    private String name;
  	private boolean sleep;
  
  	public Dog() {
      
    }
  
  	public Dog(String name, boolean sleep) {
      	this.name = name;
      	this.sleep = sleep;
    }
  
    public void run() {
        System.out.println(name + " 在跑步");
    }
  
  	public void setName(String str) {
        name = str;
    }
  	public String getName() {
      	return name;
    }
  
  	public void setSleep(boolean b) {
      	sleep = b;
    }
  	public boolean isSleep() { // boolean getter方法特殊，需要使用 isXxx
      	return sleep;
    }
}
```



## Scanner

一个可以解析基本类型和字符串的简单文本扫描器。

**求和**

```java
public class Demo {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		System.out.println("请输入第一个数据：");
		int a = sc.nextInt();

		System.out.println("请输入第二个数据：");
		int b = sc.nextInt();

		int sum = a + b;
		System.out.println("sum: " + sum);
	}
}
```



## Random

用于生成伪随机数。

- 获取 1-n 之间的随机数，包含 n。

```java
public class Demo {
	public static void main(String[] args) {
		int n = 50;
		Random r = new Random();
		int num = r.nextInt(n) + 1;
		System.out.println("num: " + num);
	}
}
```



## ArrayList

`java.util.ArrayList` 是大小可变的数组的实现。此类提供一些方法来操作内部存储 的元素。

```java
ArrayList<String> list = new ArrayList<>();
```

#### 常用方法和遍历

- `public boolean add(E e)`：将指定的元素添加到此集合的尾部。
- `public E remove(int index) `：移除此集合中指定位置上的元素。返回被删除的元素。 
- `public E get(int index)`：返回此集合中指定位置上的元素。返回获取的元素。
- `public int size()`：返回此集合中的元素数。遍历集合时，可以控制索引范围，防止越界。

```java
public class Demo {
	public static void main(String[] args) {
		ArrayList<String> list = new ArrayList<>();
		list.add("aa");
		list.add("bb");
		for (int i = 0; i < list.size(); i++) {
			System.out.println(list.get(i));
		}
	}
}
```

#### 如何存储基本数据类型

ArrayList对象不能存储基本类型，只能存储引用类型的数据。类似 `<int>` 不能写，但是存储基本数据类型对应的 包装类型是可以的。

| 基本类型 | 基本类型包装类 |
| -------- | -------------- |
| byte     | Byte           |
| short    | Short          |
| int      | Integer        |
| long     | Long           |
| float    | Float          |
| double   | Double         |
| char     | Character      |
| boolean  | Boolean        |

```java
ArrayList<Integer> list = new ArrayList<Integer>();
```



 ## String

`java.lang.String`

**特点：**

1、字符串在创建后不可被更改；

```java
String s1 = "abc";
s1 += "d";
System.out.println(s1); // "abcd"
// 内存中有“abc”，“abcd”两个对象，s1从指向“abc”，改变指向，指向了“abcd”。
```

2、因为String对象是不可变的，所以可以被共享；

```java
String s1 = "abc";
String s2 = "abc";
// 内存中只有一个“abc”对象被创建，同时被s1和s2共享。
```

3、`"abc"` 等效于 `char[] data = {'a', 'b', 'c'}`；

```java
String str = "abc";
相当于：
char data[] = {'a', 'b', 'c'};
String str = new String(data);
// String底层是靠字符数组实现的。
```

#### 常用方法

##### 判断功能的方法

- `public boolean equals (Object anObject) ` ：与指定对象进行比较。
- `public boolean equalsIgnoreCase (String anotherString)` ：与指定对象进行比较，忽略大小写。

##### 获取功能的方法

- `public int length ()` ：返回此字符串的长度。
- `public String concat (String str)` ：将指定的字符串连接到该字符串的末尾。
- `public char charAt (int index)` ：返回指定索引处的 char值。
- `public int indexOf (String str)` ：返回指定子字符串第一次出现在该字符串内的索引。
- `public String substring (int beginIndex)` ：返回子字符串，从beginIndex开始截取字符串到字符串结尾。
- `public String substring (int beginIndex, int endIndex)` ：返回一个子字符串，从beginIndex到endIndex截取字符串。含beginIndex，不含endIndex。

##### 转换功能的方法

- `public char[] toCharArray ()` ：将此字符串转换为新的字符数组。
- `public byte[] getBytes ()` ：使用平台的默认字符集将该 String编码转换为新的字节数组。
- `public String replace (CharSequence target, CharSequence replacement)` ：将与target匹配的字符串使用replacement字符串替换。

##### 分割功能的方法

- `public String[] split(String regex)` ：将此字符串按照给定的regex(规则)拆分为字符串数组。



## Static关键字

关于 `static` 关键字的使用，它可以用来修饰的成员变量和成员方法，被修饰的成员是属于类的，而s单单是属 于某个对象的。也就是说，既然属于类，就可以不靠创建对象来调用了。

#### 类变量

```java
static 数据类型 变量名;
```

#### 静态方法

```java
修饰符 static 返回值类型 方法名(参数列表) {
  // 执行语句
}
```

#### 访问方式

被 `static` 修饰的成员可以并且建议通过类名直接访问。

```java
// 访问类变量 
类名.类变量名;
// 调用静态方法 
类名.静态方法名(参数);
```

#### `static` 修饰的内容：

- 是随着类的加载而加载的，且只加载一次。
- 存储于一块固定的内存区域(静态区)，所以，可以直接被类名调用。 
- 它优先于对象存在，所以，可以被所有对象共享。

#### 静态代码块

- **静态代码块**：定义在成员位置，使用 static 修饰的代码块 {} 。
  - 位置：类中方法外。
  - 执行：随着类的加载而执行且执行一次，优先于main方法和构造方法的执行。 

```java
public class ClassName {
  static {
    // 执行语句
  }
}
```

```java
public class Game {
  public static int number;
  public static ArrayList<String> list;
  
  static {
    // 给变量赋值
    number = 2;
    list = new ArrayList<String>();
    list.add("aa");
    list.add("bb");
  }
}
```

> static 关键字，可以修饰变量、方法和代码块。在使用的过程中，其主要目的还是想在不创建对象的情况下，去调用方法。下面两个工具类，来体现 static 方法的便利。



## Arrays 类

`java.util.Arrays` 此类包含用来操作数组的各种方法，比如排序和搜索等。其所有方法均为静态方法，调用起来非常简单。

#### 操作数组的方法

- `public static String toString(int[] a)` ：返回指定数组内容的字符串表示形式。
- `public static void sort(int[] a)` ：对指定的 int 型数组按数字升序进行排序。



## Math 类

`java.lang.Math` 类包含用于执行基本数学运算的方法，如初等指数、对数、平方根和三角函数。类似这样的工具 类，其所有方法均为静态方法，并且不会创建对象，调用起来非常简单。

#### 基本运算的方法

- `public static double abs(double a)` ：返回 double 值的绝对值。
- `public static double ceil(double a)` ：返回大于等于参数的最小的整数。
- `public static double floor(double a)` ：返回小于等于参数最大的整数。
- `public static double round(double a)` ：返回最接近参数的 long。（相当于四舍五入）



## 继承

09









## 抽象类















