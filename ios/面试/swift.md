Swift相关：
1.类（class）和 结构体（struct）有什么区别？
Struct不支持继承，Class支持继承
Struct是值类型，Class是引用类型
Struct使用let创建不可变，Class使用let创建可变
Struct无法修改自身属性值，函数需要添加mutating关键字
Struct不需要deinit方法，因为值类型不关系引用计数，Class需要deinit方法
Struct初始化方法是基于属性的

2.map、filter、reduce 的作用
map 用于映射, 可以将一个列表转换为另一个列表
filter 用于过滤, 可以筛选出想要的元素
reduce 合并

3.String 与 NSString 的关系与区别
NSString 与 String 之间可以随意转换,
String 是结构体, 值类型, NSString 是类, 引用类型.
通常, 没必要使用 NSString 类, 除非你要使用一些特有方法, 例如使用 pathExtension 属性

4.什么是高阶函数
一个函数如果可以以某一个函数作为参数, 或者是返回值, 那么这个函数就称之为高阶函数, 如 map, reduce, filter

5.逃逸闭包，非逃逸闭包，尾随闭包
1.非逃逸闭包：一个接受闭包作为参数的函数，闭包是在这个函数结束前内被调用，即可以理解为闭包是在函数作用域结束前被调用
1、不会产生循环引用，因为闭包的作用域在函数作用域内，在函数执行完成后，就会释放闭包捕获的所有对象
2、针对非逃逸闭包，编译器会做优化：省略内存管理调用

2.逃逸闭包：一个接受闭包作为参数的函数，逃逸闭包可能会在函数返回之后才被调用，即闭包逃离了函数的作用域
1、可能会产生循环引用，因为逃逸闭包中需要显式的引用self（猜测其原因是为了提醒开发者，这里可能会出现循环引用了），而self可能是持有闭包变量的（与OC中block的的循环引用类似）
2、一般用于异步函数的返回，例如网络请求

3、尾随闭包：函数的最后一个参数是闭包，就叫做尾随闭包，可以增强可读性

6.Swift比Objective-C有什么优势？
1、Swift是强类型（静态）语言，有类型推断，Objective-C弱类型（动态）语言
2、Swift面向协议编程，Objective-C面向对象编程
3、Swift注重值类型，Objective-C注重引用类型
4、Swift支持泛型，Objective-C只支持轻量泛型（给集合添加泛型）
5、Swift支持静态派发（效率高）、动态派发（函数表派发、消息派发）方式，Objective-

6、C支持动态派发（消息派发）方式
7、Swift支持函数式编程（高阶函数）
8、Swift的协议不仅可以被类实现，也可以被Struct和Enum实现
9、Swift有元组类型、支持运算符重载
10、Swift支持命名空间
11、Swift支持默认参数
12、Swift比Objective-C代码更简洁

7.Swift的可选项类型（Optionals）介绍
Swift引入了可选项类型，用于处理变量值不存在的情况。Optionals类似于OC中指向nil的指针，但是适用于所有数据类型，而非仅仅局限于类，Optionals相比于OC中的nil指针，更加安全和简明，并且也是Swift诸多最强大功能的核心。

8.Swift中的 ！和 ？
这两个符号是用来标记这个变量的值是否可选，！表示可选变量必须保证转换能够成功，否则报错，但定义的变量可以直接使用；？表示可选变量即使转换不成功也不会报错，变量值为nil，如果转换成功，要使用该变量时，后面需要加！进行修饰。

9.讲讲Swift的派发机制
函数的派发机制：静态派发（直接派发）、函数表派发、消息派发
swift派发机制总结：
Swift中所有ValueType（值类型：Struct、Enum）使用直接派发；
Swift中协议的Extensions使用直接派发，初始声明函数使用函数表派发；
Swift中Class中Extensions使用直接派发，初始声明函数使用函数表派发，dynamic修饰的函数使用消息派发；
Swift中NSObject的子类用@nonobjc或final修饰的函数使用直接派发，初始声明函数使用函数表派发，dynamic修饰的Extensions使用消息派发；
3）Swift中函数派发查看方式: 可将Swift代码转换为SIL（中间码）
swiftc -emit-silgen -O example.swift

10.什么是泛型？泛型是用来解决什么问题的？
泛型是用来使类型和算法安全的工作的一种类型。在 Swift 中，在函数和数据结构中都可以使用泛型，例如类、结构体和枚举。
泛型一般是用来解决代码复用的问题。常见的一种情况是，你有一个函数，它带有一个参数，参数类型是 A，然而当参数类型改变成B的时候，你不得不复制这个函数。

11.Swift常用关键字
1、class
在Swift当中, 我们使用Class关键字去声明一个类和声明类方法

2、let
Swift里用let修饰的变量会是一个不可变的常量，即我们不可以对它进行修改

3、var
Swift中用var修饰的变量是一个可变的变量，即可以对它进行修改

4、struct
在Swift中, 我们使用struct关键字去声明结构体

5、enum
在Swift中, 我们使用enum关键字去声明枚举

6、final
Swift中，final关键字可以在class、func和var前修饰。表示 不可重写 可以将类或者类中的部分实现保护起来,从而避免子类破坏

7、override
在Swift中, 如果我们要重写某个方法, 或者某个属性的话, 我们需要在重写的变量前增加一个override关键字

8、subscript
在Swft中，subscript关键字表示下标，可以让class、struct、以及enum使用下标访问内部的值

9、static
Swift中，用static关键字声明静态变量或者函数，它保证在对应的作用域当中只有一份, 同时也不需要依赖实例化

10、mutating
Swift中，mutating关键字指的是可变即可修改。用在structure和enumeration中,虽然结构体和枚举可以定义自己的方法，但是默认情况下，实例方法中是不可以修改值类型的属性。为了能够在实例方法中修改属性值，可以在方法定义前添加关键字mutating

11、typealias
在Swift中，使用关键字typealias定义类型别名(typealias就相当于objective-c中的typedef)，就是将类型重命名，看起来更加语义化

12、lazy
在Swift中，lazy关键修饰的变量, 只有在第一次被调用的时候才会去初始化值（即懒加载）

13、init
在Swift 中，init关键字也表示构造器

14、required
在Swift里，required是用来修饰init方法的，说明该构造方法是必须实现的

15、extension
在swift中，extension与Objective-C的category有点类似，但是extension比起category来说更加强大和灵活，它不仅可以扩展某种类型或结构体的方法，同时它还可以与protocol等结合使用，编写出更加灵活和强大的代码。它可以为特定的class, strut, enum或者protocol添加新的特性。当你没有权限对源代码进行改造的时候，此时可以通过extension来对类型进行扩展

16、convenient
swift中，使用convenience修饰的构造函数叫做便利构造函数 。便利构造函数通常用在对系统的类进行构造函数的扩充时使用

17、deinit
在Swift中，deinit属于析构函数，当对象结束其生命周期时（例如对象所在的函数已调用完毕），系统自动执行析构函数。和OC中的dealloc 一样的

18、fallthrough
swift语言特性switch语句的break可以忽略不写,满足条件时直接跳出循环.fallthrough的作用就是执行完当前case,继续执行下面的case.类似于其它语言中省去break里，会继续往后一个case跑，直到碰到break或default才完成的效果

19、protocol
在Swift中，protocol关键字也是属于协议

20、open
在Swift中，open修饰的对象表示可以被任何人使用，包括override和继承

21、public
在Swift中，public表示公有访问权限，类或者类的公有属性或者公有方法可以从文件或者模块的任何地方进行访问

22、internal
在Swift中，public表示内部的访问权限。即有着internal访问权限的属性和方法说明在模块内部可以访问，超出模块内部就不可被访问了。在Swift中默认就是internal的访问权限。

23、private
在Swift中，private私有访问权限。被private修饰的类或者类的属性或方法可以在同一个物理文件中访问。如果超出该物理文件，那么有着private访问权限的属性和方法就不能被访问

24、fileprivate
在Swift中，fileprivate访问级别所修饰的属性或者方法在当前的Swift源文件里可以访问

说明：5种修饰符访问权限排序open> public > interal > fileprivate > private。

12.指定构造器和便利构x3造器有什么区别？
类必须要有一个指定构造器，可以没有便利构造器
便利构造器必须调用本类另一个构造器，最终调用到本类的指定构造器
便利构造器前面需要添加convenience关键字

13.Swift中的访问控制权限?
Open：实体可被同一模块内所有实体访问，模块外可导入该模块即可访问，模块外可被继承和重写。
Public：实体可被同一模块内所有实体访问，模块外可导入该模块即可访问，模块外不能被继承和重写。
Internal：实体可被同一模块内所有实体访问，模块外无法访问，大部分实体默认是Internal级别。
fileprivate:限制实体只能在当前文件内访问到，不管是否在本类的作用域。
private: 限制实体只能在本类的作用域且在当前文件内能访问。

14.try try? try! 的区别
try 出现异常处理异常
try? 不处理异常,返回一个可选值类型,出现异常返回nil
try! 不让异常继续传播,一旦出现异常程序停止,类似NSAssert()

15.计算属性与存储属性
存储属性就是存储在特定类、结构体里的一个常量或者变量。
可以在定义存储属性的时候指定默认值。
可以在构造过程中设置或者修改存储属性的值。

枚举、类、结构体除了拥有存储属性，还可以定义计算属性。
计算属性不直接存储值，而是提供一个getter和一个可选的setter来间接获取、设置其他属性和变量的值

