# Dart

## 基础语法

### 变量

- 明确类型申明

```dart
String name = "why";
// 类型推导（var/final/const）
var age = 20;
final height = 1.75;

```

- 类型推导（var/final/const）

```dart
// 变量申明
var age = 20;
// 常量申明，不可修改，可以通过计算/函数获取一个值（运行期间确定一个值）
final height = 1.75;
// 常量申明，不可修改，const必须赋值（编译期间需要有一个确定的值）
const address = "北京";
// e.g.
final date = DateTime.now();
```

实现创建对象时，初始值相同时，不创建新对象，为同一个对象：

```dart
void main(List<String> args) {
  const p1 = Person("why");
  const p2 = Person("why");
  const p3 = Person("haha");
  print(identical(p1, p2)); // true
  print(identical(p2, p3)); // false
}

class Person {
  final String name;
  const Person(this.name);
}
```

### 字符串

```dart
var name = "why";
var age = 18;
var height = 1.88;
// 字符串拼接 ${}，拼接变量，可以省略{}
var message = "name is ${name}, age is ${age}, height is ${height}";
var message1 = "name is $name, type is ${name.runtimeType}";
```

### 集合

- 列表 List

  ```dart
  var names = ["a", "b", "c"];
  ```

- 集合 Set

  ```dart
  var movies = {"a", "b", "c"};
  ```

- 映射 Map

  ```dart
  var info = {
    "name": "why",
    "age": 18
  };
  ```



## 函数

### 可选参数

```dart
void main(List<String> args) {
  say("why");
  say1("why", 18, 1.88);
  say2("why", age: 18, height: 1.88);
}

void say(String name) {
  print(name);
}

// 位置可选参数
void say1(String name, [int? age, double? height]) {}

// 命名可选参数
void say2(String name, {int? age, double? height}) {}
```

### 可选参数默认值

```dart
// 可选参数可以设置默认值
void say3(String name, {int age = 18, double height = 1.88}) {}
```

### 函数作为参数

```dart
void main(List<String> args) {
  test(bar);
}

void test(Function foo) {
  foo();
}

void bar() {
  print("bar 函数被调用");
}
```

- 匿名函数

  ```dart
  void main(List<String> args) {
    test(() {
      print("匿名函数被调用");
      return 10;
    });
  }
  
  void test(Function foo) {
    int res = foo();
    print(res);
  }
  ```

- 箭头函数

  条件：函数体只有一行代码

  ```dart
  void main(List<String> args) {
    test(() => print("箭头函数被调用"));
  }
  
  void test(Function foo) {
    foo();
  }
  ```

- typedef

  ```dart
  void main(List<String> args) {
    test((num1, num2) => num1 + num2);
  }
  
  typedef Calculate = int Function(int num1, int num2);
  
  void test(Calculate calc) {
    calc(10, 20);
  }
  ```

- 函数作为返回值

  ```dart
  void main(List<String> args) {
    var sum1 = sum();
    print(sum1(10, 20));
  }
  
  typedef Calculate = int Function(int num1, int num2);
  
  Calculate sum() {
    return (num1, num2) {
      return num1 + num2;
    };
  }
  ```

### 高阶函数

```dart
void main(List<String> args) {
  var names = ['abc', 'ad', 'true'];
  names.where((name) => name.contains('a')).forEach(print);
}
```



## 运算符

### ??=

当原来变量为null，那么执行赋值；

```dart
var name = "why";
name ??= "dart";
print(name); // why 
```

```dart
var name = null;
name ??= "dart";
print(name); // dart 
```

### ??

?? 前面的数据为 null 时，使用后面的值

```dart
var name = null;
var temp = name ?? "dart";
print(temp); // dart
```

### ..

级联运算符

```dart
void main(List<String> args) {
  var p = Person()
    ..name = "why"
    ..run();
}

class Person {
  late String name;

  void run() {
    print("$name run");
  }
}
```



## 类

### 初始化

```dart
void main(List<String> args) {
  var p = Person("dart", 18);
  var p1 = Person.withNameAgeHeight('', 18, 180.0);
  var p2 = Person.fromMap({"name": "p", "age": 16, "height": 180.0});
  print(p2);
}

class Person {
  String name = '';
  int age = 0;
  double height = 0.0;

  Person(this.name, this.age);

  Person.withNameAgeHeight(this.name, this.age, this.height);

  Person.fromMap(Map<String, dynamic> map) {
    this.name = map["name"];
    this.age = map["age"];
    this.height = map["height"];
  }

  @override
  String toString() {
    return "name: $name, age: $age, height: $height";
  }
}
```

### 初始化列表

```dart
void main(List<String> args) {
  var p = Person("why");
  var p1 = Person("why", age: 18);
}

class Person {
  final String name;
  final int age;

  Person(this.name, {int? age}) : this.age = age ?? 10;
}
```

### 构造函数的重定向

```dart
void main(List<String> args) {
  var p = Person("why");
  print(p.age);
}

class Person {
  String name;
  int age;

  // 构造函数的重定向
  Person(name) : this._internal(name, 0);

  Person._internal(this.name, this.age);
}
```

### 常量构造函数

同一个参数创建出来的对象是相同的

```dart
void main(List<String> args) {
  const p1 = Person("why");
  const p2 = Person("why");
  print(identical(p1, p2)); // true
}

class Person {
  final String name;

  const Person(this.name);
}
```

### 工厂构造函数

工厂构造函数最大的特点：需要手动返回对象

```dart
void main(List<String> args) {
  final p1 = Person.withName("why");
  final p2 = Person.withName("why");
  print(identical(p1, p2));

  final p3 = Person.withColor("red");
  final p4 = Person.withColor("red");
  print(identical(p3, p4));
}

class Person {
  String name;
  String color;

  static final Map<String, Person> _nameCache = {};
  static final Map<String, Person> _colorCache = {};

  factory Person.withName(String name) {
    if (_nameCache.containsKey(name)) {
      return _nameCache[name]!;
    } else {
      final p = Person(name, "");
      _nameCache[name] = p;
      return p;
    }
  }

  factory Person.withColor(String color) {
    if (_colorCache.containsKey(color)) {
      return _colorCache[color]!;
    } else {
      final p = Person("", color);
      _colorCache[color] = p;
      return p;
    }
  }

  Person(this.name, this.color);
}
```

### 类的setter/getter

```dart
void main(List<String> args) {
  final p = Person();
  p.setName = "why";
  print(p.getName);
}

class Person {
  String name = "";
  
	// setter
  set setName(String name) {
    this.name = name;
  }
	// getter
  String get getName {
    return name;
  }
}
```

或

```dart
void main(List<String> args) {
  final p = Person();
  p.setName = "why";
  print(p.getName);
}

class Person {
  String name = "";

  // setter
  set setName(String name) => this.name = name;
  // getter
  String get getName => name;
}
```

### 类的继承

```dart
class Animal {
  int age;
  Animal(this.age);

  void run() {}
}

class Person extends Animal {
  String name;

  Person(this.name, int age) : super(age);

  @override
  void run() {
    print("$name在蹦跑");
  }
}
```

### 抽象类

```dart
void main(List<String> args) {
  final s = Shape._internal(); // 通过工厂模式实例化
  final r = Rectangle(); // 子类实例化
}

// 抽象类不能实例化，但是可以通过工厂构造函数实例化
// external，将方法的声明和方法的实现分离，在其他地方通过注解 @patch 实现方法
abstract class Shape {
  int getArea();
  String getInfo() {
    return "形状";
  }

  Shape();

  // 通过工厂模式，使用默认子类实例化
  factory Shape._internal() {
    return Rectangle();
  }
}

// 继承抽象类后，必须实现抽象类的抽象方法
class Rectangle extends Shape {
  @override
  int getArea() {
    return 10;
  }
}
```

50分钟







