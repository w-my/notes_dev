# Java8 Stream流

## 概述

Stream 是 Java8 中处理集合的关键抽象概念，它可以指定你希望对集合进行的操作，可以执行非常复杂的查找、过滤和映射数据等操作。使用Stream API 对集合数据进行操作，就类似于使用 SQL 执行的数据库查询。

**特点**

- 不是数据结构，不会保存数据。
- 不会修改原数据源，是将操作后的数据保存到另一个对象中。
- 惰性求值，流在中间处理过程中，只是对操作进行了记录，并不会立即执行，需要等到执行终止操作的时候才会进行实际的计算。

|          | Stream 操作分类 |                                               |
| -------- | --------------- | --------------------------------------------- |
| 中间操作 | 无状态          | filter map flatMap peek                       |
|          | 有状态          | distinct sorted limit skip                    |
| 结束操作 | 非短路操作      | forEach reduce collect max min count          |
|          | 短路操作        | anyMatch allMatch noneMatch findFirst findAny |

- **无状态**：指元素的处理不受之前元素的影响；
- **有状态**：指该操作只有拿到所有元素之后才能继续下去。
- **非短路操作**：指必须处理所有元素才能得到最终结果；
- **短路操作**：指遇到某些符合条件的元素就可以得到最终结果，如 A || B ，只要A为true，则无需判断B的结果。

## Stream流的具体用法

### 1. 流的常用创建方法

1.1 使用 Collection 下的 stream() 和 parallelStream() 方法

```java
List<String> list = new ArrayList<>();
Stream<String> stream = list.stream(); // 顺序流
Stream<String> stringStream = list.parallelStream(); // 并行流
```

stream 是单线程，parallelStream 用在多线程并发处理

1.2 使用 Arrays 中的 stream() 方法，将数组转成流

```java
Integer[] nums = new Integer[]{1, 2, 3, 4, 5};
Stream<Integer> Integerstream = Arrays.Stream(nums);
```

1.3 使用 Stream 中的静态方法：of()、iterate()、generate()

```java
Stream<Integer> stream1 = Stream.of(1, 2, 3, 4, 5);
// iterate()、generate() 方法可以创建无限流，可以通过 limit() 限制数量
Stream<Integer> stream2 = Stream.iterate(0, x->x+2);
Stream<Integer> stream3 = Stream.generate(() -> new Random().nextInt(10));
Stream<Integer> stream4 = Stream.iterate(0, x->x+2).limit(10);
```

1.4 使用 BufferedReader.lines() 方法，将每行内容转成流

```java
BufferedReader reader = new BufferedReader(new FileReader("F:\\test_stream.txt"));
Stream<String> lineStream = reader.lines();
// 等价于上面两行
Stream<String> lineStream2 = new BufferedReader(new FileReader("F:\\test_stream.txt")).lines();
```

1.5 使用 Pattern.splitAsStream() 方法，将字符串分隔成流

```java
Pattern pattern = Pattern.complie(",");
Stream<String> stream = pattern.splitAsStream("a,b,c,d");
```

### 2. 流的中间操作

2.1 筛选与切片

- **filter**：过滤流中的某些元素
- **limit(n)**：获取n个元素，限制获取元素的个数
- **skip(n)**：跳过n元素，配合 `limit(n)` 可以实现分页
- **distinct**：通过流中元素的 `hashCode()` 和 `equals()` 去除重复元素

``` java
Stream<Integer> stream = Stream.of(6,6,6,8,8,10,12,45,14);
Stream<Integer> streamFilter = stream.filter(item -> item < 30) // 6 6 6 8 8 10 12 14
  .distinct() // 6 8 10 12 14
  .skip(2) // 10 12 14
  .limit(1); // 10
```

2.2 映射

`map`

```java
List<String> list = Arrays.asList("String", "a,b,c");
Stream<String> stringStream = list.stream().map(s -> s.replaceAll(",", "")); // String abc
```

```java
Stream<String> stringStream2 = list.stream.flatMap(s -> {
  String[] split = s.split(",");
  Stream<String> testStream = Arrays.stream(split);
  return testStream;
}); // String  a b c
```

```java
String[] words = new String[]{"Hello","World"};
List<String[]> a = Arrays.stream(words)
  .map(word -> word.split(""))
  .distinct()
  .collect(toList()); // [[H,e,l,l,o], [W,o,r,l,d]]
```

```java
String[] words = new String[]{"Hello","World"};
List<String> a = Arrays.stream(words)
  .map(word -> word.split(""))
  .flatMap(Arrays::stream)
  .distinct()
  .collect(toList());
a.forEach(System.out::print); // HeloWrd
```

2.3 排序

`sorted()`：自然排序，流中元素需要实现 `Comparable` 接口

```java
List<String> list = Arrays.asList("tg", "er", "ab");
list.stream().sorted().forEach(System.out::println); // ab er tg
```

```java
Person p1 = new Person("zhangsan",26);
Person p2 = new Person("zhangsan",22);
Person p3 = new Person("wangwu",23);
List<Person> list = Arrays.asList(p1,p2,p3);
// 自定义Comparator排序器 自定义排序：先按姓名升序，姓名相同则按年龄升序
list.stream().sorted((o1,o2) -> {
  if (o1.getName().equals(o2.getName())) {
    return o1.getAge()-o2.getAge();
	}else {
		return o1.getName().compareTo(o2.getName());
	}
}).forEach(System.out::println);
```

2.4 消费

`peek`：如同于map，能得到流中的每一个元素。但map接收的是一个`Function`表达式，有返回值；而peek接收的是`Consumer`表达式，没有返回值。

```java
Person p1 = new Person("zhangsan",26);
Person p2 = new Person("lisi",22);
Person p3 = new Person("wangwu",23);
List<Person> list = Arrays.asList(p1,p2,p3);
list.stream().map(item -> {
	item.setAge(100);
	return item;
}).forEach(System.out::println);
```

```java
Person p1 = new Person("zhangsan", 26);
Person p2 = new Person("lisi", 22);
Person p3 = new Person("wangwu", 23);
List<Person> list = Arrays.asList(p1, p2, p3);
list.stream().peek(item->item.setAge(100)).forEach(System.out::println);
```

### 3. 流的终止操作

3.1 匹配、聚合操作

- allMatch：接收一个 Predicate 函数，当流中每个元素都符合该断言时才返回true，否则返回false
- noteMatch：接收一个 Predicate 函数，当流中每个元素都不符合该断言时才返回true，否则返回false
- anyMatch：接收一个 Predicate 函数，只要流中有一个元素满足该断言则返回true，否则返回false
- findFirst：返回流中第一个元素
- findAny：返回流中的任意元素
- count：返回流中元素的总个数
- max：返回流中元素最大值
- min：返回流中元素最小值

```java
List<Integer> list = Arrays.asList(1, 2, 3, 4, 5);
boolean allMatch = list.stream().allMatch(e -> e > 4); // false
boolean noneMatch = list.stream().noneMatch(e -> e > 10); // true
boolean anyMatch = list.stream().anyMatch(e -> e > 4); // true

Integer findFirst = list.stream().findFirst().get(); // 1
Integer findAny = list.stream().findAny().get(); // 1

long count = list.stream().count(); // 5
Integer max = list.stream().max(Integer::compareTo).get(); // 5
Integer min = list.stream().min(Integer::compareTo).get(); // 1
```

3.2 规约操作

`Stream` 中的 `Reduce` 方法：根据一定的规则将Stream中的元素进行计算后返回一个唯一的值，它有三个变种，输入参数分别是一个参数、二个参数以及三个参数。

3.2.1 一个参数

```java
Optional<T> reduce(BinaryOperator<T> accumulator);
```

```java
Stream<Integer> s = Stream.of(1, 2, 3, 4, 5);
Integer sum = s.reduce((a, b) -> a + b).get();
System.out.println(sum); // 15
```

通过reduce方法完成数的求和，其实就是前两个数作为输入，算出它们的和并将其作为输出。

3.2.2 两个参数

```java
T reduce(T identity, BinaryOperator<T> accumulator);
```

可以看出多出了一个参数`T identity`，这个相当于一个初始参数。

```java
Stream<String> s = Stream.of("test", "t1", "t2", "teeeee", "aaaa", "taaa");
System.out.println(s.reduce("[value]", (s1, s2) -> s1.concat(s2))); // [value]testt1t2teeeeeaaaataaa
```

3.2.3 三个参数

```java
<U> U reduce(U identity, 
             BiFunction<U, ? super T, 
             U> accumulator, BinaryOperator<U> combiner);
```

- **identity**：一个初始化的值；这个初始化的值其类型是泛型`U`，与`Reduce`方法返回的类型一致；注意此时`Stream`中元素的类型是`T`，与`U`可以不一样也可以一样，这样的话操作空间就大了；不管`Stream`中存储的元素是什么类型，`U`都可以是任何类型，如`U`可以是一些基本数据类型的包装类型`Integer、Long`等；或者是`String`，又或者是一些集合类型`ArrayList`等。（这个和之前的两参数和单参数就不一样了）
- **accumulator**：其类型是`BiFunction`，输入是`U`与`T`两个类型的数据，而返回的是U类型；也就是说返回的类型与输入的第一个参数类型是一样的，而输入的第二个参数类型与Stream中元素类型是一样的。
- **combiner**：其类型是`BinaryOperator`，支持的是对`U`类型的对象进行操作。

3.2.3.1 非并行时

如果 Stream 是非并行的，combiner 不生效；

```java
Stream<String> s1 = Stream.of("aa", "ab", "c", "ad");
System.out.println(s1.reduce(new ArrayList<String>(), (r, t) -> {r.add(t); return r; }, (r1, r2) -> r1));
```

可以看出输入类型是`String`，也就是`T`。输出的是`ArrayList`，也就是`U`。

```java
Stream<String> s1 = Stream.of("aa", "ab", "c", "ad");
s1.reduce(new ArrayList<String>(), 
          (r, t) -> {if (t.contains("a")) r.add(t);  return r;},
          (r1, r2) -> r1)
  .stream().forEach(System.out::println);//aa ab ad
```

完成了筛选包含"a"的单词，并加入`ArrayList`。在非并行时，其实第三个参数没有太大意义，可以指定r1或者r2为返回值，也可以指定返回值为null。

3.2.3.2 并行

当`Stream`是并行时，第三个参数就有意义了，它会将不同线程计算的结果调用`combiner`做汇总后返回。

```java
System.out.println(Stream.of(1, 2, 3).parallel().reduce(4, (s1, s2) -> s1 + s2, (s1, s2) -> s1 + s2)); // 18
```

如果是非并行时，初始值为4,然后执行累加，应该是10。那为什么并行时为18，因为多线程并行时，多个线程分别取执行参数2的操作，就是：`4+1=5` `4+2=6` `4+3=7`得到了5,6,7这三个数，最后就是把各个线程并行处理的结果再执行第三个参数规定的操作即累加。

```java
Stream<String> s1 = Stream.of("aa", "ab", "c", "ad");
s1.parallel().reduce(Collections.synchronizedList(new ArrayList<>()),
                     (r, t) -> {if (t.contains("a")) r.add(t);  return r; },
                     (r1, r2) -> r1)
  .stream().forEach(System.out::println); // ab ad aa
```

3.3 收集操作

`collect`：接收一个`Collector`实例，将流中元素收集成另外一个数据结构。

`Collector<T, A, R>` 是一个接口，有以下5个抽象方法：

- **Supplier<A> supplier()：** 创建一个结果容器A

- **BiConsumer<A, T> accumulator()：** 消费型接口，第一个参数为容器A，第二个参数为流中元素T。

- **BinaryOperator<A> combiner()：** 函数接口，该参数的作用跟上一个方法(reduce)中的`combiner`参数一样，将并行流中各 个子进程的运行结果(`accumulator`函数操作后的容器A)进行合并。

- **Function<A, R> finisher()：** 函数式接口，参数为：容器A，返回类型为：`collect`方法最终想要的结果R。

- **Set characteristics()：** 返回一个不可变的Set集合，用来表明该`Collector`的特征。有以下三个特征：

- - **CONCURRENT：** 表示此收集器支持并发。
  - **UNORDERED：** 表示该收集操作不会保留流中元素原有的顺序。
  - **IDENTITY_FINISH：** 表示`finisher`参数只是标识而已，可忽略。

```java
Person p1 = new Person("zhangsan", 26);
Person p2 = new Person("lisi", 22);
Person p3 = new Person("wangwu", 23);
List<Person> list = Arrays.asList(p1, p2, p3);
// 装成list
List<Integer> ageList = list.stream().map(Person::getAge).collect(Collectors.toList()); // [26, 22, 22]
// 转成set
Set<Integer> ageSet = list.stream().map(Person::getAge).collect(Collectors.toSet()); // [26, 22]

// 转成map,注:key不能相同，否则报错
Map<String, Integer> studentMap = list.stream().collect(Collectors.toMap(Person::getName, Person::getAge)); 
// {zhangsan=26, lisi=22, wangwu=22}

// 字符串分隔符连接
String joinName = list.stream().map(Person::getName).collect(Collectors.joining(",", "(", ")")); 
// (zhangsan, lisi, wangwu)

// 聚合操作
// 1.总数
Long count = list.stream().collect(Collectors.counting()); // 3
// 2.最大年龄 (最小的minBy同理)
Integer maxAge = list.stream().map(Person::getAge).collect(Collectors.maxBy(Integer::compare)).get(); // 26
// 3.所有人的年龄求和
Integer sumAge = list.stream().collect(Collectors.summingInt(Person::getAge)); // 70
// 4.平均年龄
Double averageAge = list.stream().collect(Collectors.averagingDouble(Person::getAge)); // 23.333333333333332
// 带上以上所有方法
DoubleSummaryStatistics statistics = list.stream().collect(Collectors.summarizingDouble(Person::getAge));
System.out.println("count:" + statistics.getCount() + ",max:" + statistics.getMax() + ",sum:" + statistics.getSum() + ",average:" + statistics.getAverage());
        
// 分组 按年龄分组
Map<Integer, List<Person>> ageMap = list.stream().collect(Collectors.groupingBy(Person::getAge));
// 分区
// 分成两部分，一部分大于10岁，一部分小于等于10岁
Map<Boolean, List<Person>> partMap = list.stream().collect(Collectors.partitioningBy(v -> v.getAge() > 10));
// 规约
Integer allAge = list.stream().map(Person::getAge).collect(Collectors.reducing(Integer::sum)).get(); // 40 
```

3.3.1 `Collectors.toList()` 解析

方法源码

```java
public static <T> Collector<T, ?, List<T>> toList() {
  return new CollectorImpl<>((Supplier<List<T>>) ArrayList::new, List::add,
                             (left, right) -> { left.addAll(right); return left; },
                             CH_ID);
}
```

`(left, right) -> { left.addAll(right); return left; },CH_ID);`

源码这么看，比较难懂得，按照理解将其写成这样：

```java
public <T> Collector<T, ?, List<T>> toList() {
    Supplier<List<T>> supplier = () -> new ArrayList();
    BiConsumer<List<T>, T> accumulator = (list, t) -> list.add(t);
    BinaryOperator<List<T>> combiner = (list1, list2) -> {
        list1.addAll(list2);
        return list1;
    };
}
```



