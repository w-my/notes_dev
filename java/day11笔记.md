###11.01_Java开发工具(常见开发工具介绍)
* A:操作系统自带的记事本软件
* B:高级记事本软件
* C:集成开发环境 IDE
	* (Integrated Development Environment)
* D:Eclipse和MyEclipse的区别
	* a:Eclipse是一种可扩展的开放源代码的IDE。
	* b:Eclipse的特点描述
		* 免费
		* 纯Java语言编写
		* 免安装
		* 扩展性强
	* c:MyEclipse
		* 在Eclipse基础上追加的功能性插件，对插件收费
		* 在WEB开发中提供强大的系统架构平台

###11.02_Java开发工具(Eclipse的下载安装及卸载)
* A:下载 http://eclipse.org/
* B:安装
	* 绿色版	解压就可以使用(Eclipse)
	* 安装版   双击运行,一路next即可(JDK)
* C:卸载
	* 绿色版	直接删除文件夹即可
	* 安装版 专业卸载软件或者控制面板添加删除程序

###11.03_Java开发工具(Eclipse中HelloWorld案例以及汉化)
* A:选择工作空间
	* 工作空间  其实就是我们写的源代码所在的目录
* B:用Eclipse来完成一个HelloWorld案例
	* 代码以项目为基本单位
	* 创建项目
	* 创建包
	* 创建类
	* 编写代码
* C:编译和运行
* D:Eclipse的汉化
	* 从Eclipse3.5开始，安装目录下就多了一个dropins目录，
	* 只要将插件解压后放到到该目录即可。
	* 同理，这种方式卸载插件也是特别的方便，推荐这种方式
* E:语法检查提示
	* 红色波浪线
	* 黄色波浪线	

###11.04_Java开发工具(Eclipse的视窗和视图概述)
* A:视窗  每一个基本的窗体被称为视窗
	* PackageExplorer  显示项目结构，包，类，及资源
	* Outline   显示类的结构，方便查找，识别，修改
	* Console  程序运行的结果在该窗口显示
	* Hierarchy 显示Java继承层次结构，选中类后F4
* B:视图  是由某些视窗的组合而成的
	* Java视图
	* Debug视图

###11.05_Java开发工具(Eclipse工作空间的基本配置)
* A:程序的编译和运行的环境配置(一般不改)
	* window -- Preferences -- Java
	* 编译环境：Compiler	默认选中的就是最高版本。
	* 运行环境：Installed JREs	默认会找你安装的那个JDK。建议配置了Java的环境变量。
	* 问题：
		* 低编译，高运行。可以。
		* 高编译，低运行。不可以。
		* 建议，编译和运行的版本一致。
* B:如何去掉默认注释?
	* window -- Preferences -- Java -- Code Style -- Code Templates
	* 选择你不想要的内容，通过右边Edit编辑。
	* 注意：请只删除注释部分，不是注释部分的不要删除。
* C:行号的显示和隐藏
	* 显示：在代码区域的最左边的空白区域，右键 -- Show Line Numbers即可。
	* 隐藏：把上面的动作再做一次。
* D:字体大小及颜色
	* a:Java代码区域的字体大小和颜色：
		* window -- Preferences -- General -- Appearance -- Colors And Fonts --Java修改 -- Java Edit Text Font
	* b:控制台
		* window -- Preferences -- General -- Appearance -- Colors And Fonts -- Debug -- Console font
	* c:其他文件
		* window -- Preferences -- General -- Appearance -- Colors And Fonts -- Basic -- Text Font
* E:窗体给弄乱了，怎么办?
	* window -- Reset Perspective
* F:控制台找不到了，怎么办?
	* Window--Show View—Console

###11.06_Java开发工具(Eclipse中内容辅助键的使用)
* A:Alt+/ 起提示作用
* B:main+alt+/,syso+alt+/,给出其他提示

###11.07_Java开发工具(Eclipse中快捷键的使用)
* A:格式化  ctrl+shift+f
* B:导入包  ctrl+shift+o 
* C:注释  ctrl+/,ctrl+shift+/,ctrl+shift+\
* D:代码上下移动 选中代码alt+上/下箭头
* E:查看源码  选中类名(F3或者Ctrl+鼠标点击)
* F:给建议 ctrl+1
* G:查找具体的类 ctrl + shift + t
* H:创建新的类或者接口 ctrl + n
* alt + shift + m 抽取方法
* alt + shift + r 改名

###11.08_Java开发工具(Eclipse中如何提高开发效率)
* alt + shift + s
* A:自动生成构造方法
* B:自动生成get/set方法
* C:Eclipse中继承抽象类或者实现接口的简化

###11.09_Java开发工具(Eclipse中一个标准学生类及其测试)
* A:案例演示
	* 用Eclipse实现标准学生类及其测试

###11.10_Java开发工具(Eclipse中接口抽象类具体类代码体现)
* A:案例演示
	* 用Eclipse实现接口抽象类具体类代码

###11.11_Java开发工具(Eclipse中如何生成jar包并导入到项目中)
* A:jar是什么?
	* jar是多个class文件的压缩包。
* B:jar有什么用?
	* 用别人写好的东西
* C:打jar包
	* 选中项目--右键--Export--Java--Jar--自己指定一个路径和一个名称--Finish
* D:导入jar包
	* 复制到项目路径下并添加至构建路径。

###11.12_Java开发工具(Eclipse中如何制作帮助文档和使用jar包)
* A:针对源程序添加文档注释
	* 对用Eclipse实现接口抽象类具体类代码加入文档注释
* B:生成帮助文档
	* 选中项目--右键--Export--Java--Javadoc—Finish
* C:使用jar包

###11.13_Java开发工具(Eclipse中如何删除项目和导入项目)
* A:删除项目
	* 选中项目 – 右键 – 删除
		* 从项目区域中删除
		* 从硬盘上删除
* B:导入项目
	* 在项目区域右键找到import
	* 找到General，展开，并找到
	* Existing Projects into Workspace
	* 点击next,然后选择你要导入的项目
	* 注意：这里选择的是项目名称

###11.14_Java开发工具(Eclipse中断点调试的基本使用)
* A:Debug的作用
	* 调试程序
	* 查看程序执行流程
* B:如何查看程序执行流程
	* 什么是断点
	* 如何设置断点
	* 在哪里设置断点
	* 如何运行设置断点后的程序
	* 看哪些地方
	* 如何去除断点

###11.15_Java开发工具(Eclipse查看Java中参数传递问题)
* A:断点演示
	* 断点查看Java中参数传递问题

###11.16_常见对象(API概述)
* A:API(Application Programming Interface) 
	* 应用程序编程接口
* B:Java API
	* 就是Java提供给我们使用的类，这些类将底层的实现封装了起来，
	* 我们不需要关心这些类是如何实现的，只需要学习这些类如何使用。

###11.17_常见对象(Object类的概述)
* A:Object类概述
	* 类层次结构的根类
	* 所有类都直接或者间接的继承自该类
* B:构造方法
	* public Object()
	* 回想面向对象中为什么说：
	* 子类的构造方法默认访问的是父类的无参构造方法

###11.18_常见对象(Object类的hashCode()方法)
* A:案例演示
	* public int hashCode()
	* a:返回该对象的哈希码值。默认情况下，该方法会根据对象的地址来计算。
	* b:不同对象的，hashCode()一般来说不会相同。但是，同一个对象的hashCode()值肯定相同。
	* c:不是对象的实际地址值，可以理解为逻辑地址值。
		* 举例：物体和编号。	

###11.19_常见对象(Object类的getClass()方法)
* A:案例演示
	* public final Class getClass()
	* a:返回此 Object 的运行时类。
	* b:可以通过Class类中的一个方法，获取对象的真实类的全名称。	
		* public String getName()

###11.20_常见对象(Object类的toString()方法)
* A:案例演示
	* public String toString()
	* a:返回该对象的字符串表示。
* 
		
		public Stirng toString() {
			return name + "," + age;
		}
	* b:它的值等于： 
		* getClass().getName() + '@' + Integer.toHexString(hashCode()) 
	* c:由于默认情况下的数据对我们来说没有意义，一般建议重写该方法。
* B:最终版
	* 自动生成

###11.21_常见对象(Object类的equals()方法)
* A:案例演示
	* a:指示其他某个对象是否与此对象“相等”。 
	* b:默认情况下比较的是对象的引用是否相同。
	* c:由于比较对象的引用没有意义，一般建议重写该方法。
	* d:==和equals()的区别。(面试题)

###11.22_常见对象(==号和equals方法的区别)
* ==是一个比较运算符号,既可以比较基本数据类型,也可以比较引用数据类型,基本数据类型比较的是值,引用数据类型比较的是地址值
* equals方法是一个方法,只能比较引用数据类型,所有的对象都会继承Object类中的方法,如果没有重写Object类中的equals方法,equals方法和==号比较引用数据类型无区别,重写后的equals方法比较的是对象中的属性

###11.23_day11总结
* 把今天的知识点总结一遍。