# JavaWeb

使用Java语言开发基于互联网的项目



## Web概念概述

	* 软件架构：
		1. C/S: Client/Server 客户端/服务器端
			* 在用户本地有一个客户端程序，在远程有一个服务器端程序
			* 如：QQ，迅雷...
			* 优点：
				1. 用户体验好
			* 缺点：
				1. 开发、安装，部署，维护 麻烦
		2. B/S: Browser/Server 浏览器/服务器端
			* 只需要一个浏览器，用户通过不同的网址(URL)，客户访问不同的服务器端程序
			* 优点：
				1. 开发、安装，部署，维护 简单
			* 缺点：
				1. 如果应用过大，用户的体验可能会受到影响
				2. 对硬件要求过高
	
	* B/S架构详解
		* 资源分类：
			1. 静态资源：
				* 使用静态网页开发技术发布的资源。
				* 特点：
					* 所有用户访问，得到的结果是一样的。
					* 如：文本，图片，音频、视频, HTML,CSS,JavaScript
					* 如果用户请求的是静态资源，那么服务器会直接将静态资源发送给浏览器。浏览器中内置了静态资源的解析引擎，可以展示静态资源
			2. 动态资源：
				* 使用动态网页及时发布的资源。
				* 特点：
					* 所有用户访问，得到的结果可能不一样。
					* 如：jsp/servlet,php,asp...
					* 如果用户请求的是动态资源，那么服务器会执行动态资源，转换为静态资源，再发送给浏览器




## HTML

	1. 概念：是最基础的网页开发语言
		* Hyper Text Markup Language 超文本标记语言
			* 超文本:
				* 超文本是用超链接的方法，将各种不同空间的文字信息组织在一起的网状文本.
			* 标记语言:
				* 由标签构成的语言。<标签名称> 如 html，xml
				* 标记语言不是编程语言
	
	2. 快速入门：
		* 语法：
			1. html文档后缀名 .html 或者 .htm
			2. 标签分为
				1. 围堵标签：有开始标签和结束标签。如 <html> </html>
				2. 自闭和标签：开始标签和结束标签在一起。如 <br/>
			3. 标签可以嵌套：<a><b></b></a>
			4. 在开始标签中可以定义属性。属性是由键值对构成，值需要用引号(单双都可)引起来
			5. html的标签不区分大小写，但是建议使用小写。
	
	3. 标签学习：
		1. 文件标签：构成html最基本的标签
			* <!DOCTYPE html>：html5中定义该文档是html文档
			* html：html文档的根标签
			* head：头标签。用于指定html文档的一些属性。引入外部的资源
			* title：标题标签。
			* body：体标签
		2. 文本标签：和文本有关的标签
			* 注释：<!-- 注释内容 -->
			* <h1> to <h6>：标题标签
				* h1~h6:字体大小逐渐递减
			* <p>：段落标签
			* <br>：换行标签
			* <hr>：展示一条水平线
				* 属性：
					* color：颜色
					* width：宽度
					* size：高度
					* align：对其方式
						* center：居中
						* left：左对齐
						* right：右对齐
			* <b>：字体加粗
			* <i>：字体斜体
			* <font>:字体标签
			* <center>:文本居中
				* 属性：
					* color：颜色
					* size：大小
					* face：字体
			* 属性定义：
				* color：
					1. 英文单词：red,green,blue
					2. rgb(值1，值2，值3)：值的范围：0~255  如  rgb(0,0,255)
					3. #值1值2值3：值的范围：00~FF之间。如： #FF00FF
				* width：
					1. 数值：width='20', 数值的单位，默认是 px(像素)
					2. 数值%：占比相对于父元素的比例
		3. 图片标签：
			* img：展示图片
				* 属性：
					* src：指定图片的位置
		4. 列表标签：
			* 有序列表：
				* ol:
				* li:
			* 无序列表：
				* ul:
				* li:
		5. 链接标签：
			* a：定义一个超链接
				* 属性：
					* href：指定访问资源的URL(统一资源定位符)
					* target：指定打开资源的方式
						* _self：默认值，在当前页面打开
						* _blank：在空白页面打开
		6. div和span：
			* div：每一个div占满一整行。块级标签
	    * span：文本信息在一行展示，行内标签 内联标签
		7. 语义化标签：html5中为了提高程序的可读性，提供了一些标签。
			1. <header>：页眉
			2. <footer>：页脚
		8. 表格标签：
			* table：定义表格
				* width：宽度
				* border：边框
				* cellpadding：定义内容和单元格的距离
				* cellspacing：定义单元格之间的距离。如果指定为0，则单元格的线会合为一条、
				* bgcolor：背景色
				* align：对齐方式
			* tr：定义行
				* bgcolor：背景色
				* align：对齐方式
			* td：定义单元格
				* colspan：合并列
				* rowspan：合并行
			* th：定义表头单元格
			* <caption>：表格标题
			* <thead>：表示表格的头部分
			* <tbody>：表示表格的体部分
			* <tfoot>：表示表格的脚部分
		9. 表单
			* 概念：用于采集用户输入的数据的。用于和服务器进行交互。
			* form：用于定义表单的。可以定义一个范围，范围代表采集用户数据的范围
	        * 属性：
	            * action：指定提交数据的URL
	            * method:指定提交方式
	                * 分类：一共7种，2种比较常用
	                   * get：
	                        1. 请求参数会在地址栏中显示。会封装到请求行中(HTTP协议后讲解)。
	                        2. 请求参数大小是有限制的。
	                        3. 不太安全。
	                   * post：
	                        2. 请求参数不会再地址栏中显示。会封装在请求体中(HTTP协议后讲解)
	                        2. 请求参数的大小没有限制。
	                        3. 较为安全。
	
	        * 表单项中的数据要想被提交：必须指定其name属性
	 	10. 表单项标签
	 		* input：可以通过type属性值，改变元素展示的样式
				* type属性：
					* text：文本输入框，默认值
						* placeholder：指定输入框的提示信息，当输入框的内容发生变化，会自动清空提示信息	
					* password：密码输入框
					* radio:单选框
						* 注意：
							1. 要想让多个单选框实现单选的效果，则多个单选框的name属性值必须一样。
							2. 一般会给每一个单选框提供value属性，指定其被选中后提交的值
							3. checked属性，可以指定默认值
					* checkbox：复选框
						* 注意：
							1. 一般会给每一个单选框提供value属性，指定其被选中后提交的值
							2. checked属性，可以指定默认值
					* file：文件选择框
					* hidden：隐藏域，用于提交一些信息。
					* 按钮：
						* submit：提交按钮。可以提交表单
						* button：普通按钮
						* image：图片提交按钮
							* src属性指定图片的路径	
			   * label：指定输入项的文字描述信息
				   * 注意：
					   * label的for属性一般会和 input 的 id属性值 对应。如果对应了，则点击label区域，会让input输入框获取焦点。
			* select: 下拉列表
				* 子元素：option，指定列表项
			* textarea：文本域
				* cols：指定列数，每一行有多少个字符
				* rows：默认多少行。



## CSS


	1. 概念：Cascading Style Sheets 层叠样式表
		* 层叠：多个样式可以作用在同一个html的元素上，同时生效
	2. 好处：
		1. 功能强大
		2. 将内容展示和样式控制分离
			* 降低耦合度。解耦
			* 让分工协作更容易
			* 提高开发效率
	3. CSS的使用：CSS与html结合方式
		1. 内联样式
			 * 在标签内使用style属性指定css代码
			 * 如：<div style="color:red;">hello css</div>
		2. 内部样式
			* 在head标签内，定义style标签，style标签的标签体内容就是css代码
			* 如：
				<style>
	          div{
	              color:blue;
	          }
			  </style>
				<div>hello css</div>
		3. 外部样式
			1. 定义css资源文件。
			2. 在head标签内，定义link标签，引入外部的资源文件
			* 如：
	      * a.css文件：
	        div{
	            color:green;
	        }
				<link rel="stylesheet" href="css/a.css">
				<div>hello css</div>
				<div>hello css</div>
		* 注意：
			* 1,2,3种方式css作用范围越来越大
			* 1方式不常用，后期常用2,3
			* 3种格式可以写为：
				<style>
	          @import "css/a.css";
	      </style>
	4. css语法：
		* 格式：
			选择器 {
				属性名1:属性值1;
				属性名2:属性值2;
				...
			}
		* 选择器：筛选具有相似特征的元素
		* 注意：
			* 每一对属性需要使用；隔开，最后一对属性可以不加；
	5. 选择器：筛选具有相似特征的元素
		* 分类：
			1. 基础选择器
				1. id选择器：选择具体的id属性值的元素.建议在一个html页面中id值唯一
	          * 语法：#id属性值{}
	      2. 元素选择器：选择具有相同标签名称的元素
	          * 语法： 标签名称{}
	          * 注意：id选择器优先级高于元素选择器
	      3. 类选择器：选择具有相同的class属性值的元素。
	          * 语法：.class属性值{}
	          * 注意：类选择器选择器优先级高于元素选择器
			2. 扩展选择器：
				1. 选择所有元素：
					* 语法： *{}
				2. 并集选择器：
					* 选择器1,选择器2{}
				3. 子选择器：筛选选择器1元素下的选择器2元素
					* 语法： 选择器1 选择器2{}
				4. 父选择器：筛选选择器2的父元素选择器1
					* 语法： 选择器1 > 选择器2{}
				5. 属性选择器：选择元素名称，属性名=属性值的元素
					* 语法： 元素名称[属性名="属性值"]{}
				6. 伪类选择器：选择一些元素具有的状态
					* 语法： 元素:状态{}
					* 如： <a>
						* 状态：
							* link：初始化的状态
							* visited：被访问过的状态
							* active：正在访问状态
							* hover：鼠标悬浮状态
	6. 属性
		1. 字体、文本
			* font-size：字体大小
			* color：文本颜色
			* text-align：对其方式
			* line-height：行高 
		2. 背景
			* background：
		3. 边框
			* border：设置边框，符合属性
		4. 尺寸
			* width：宽度
			* height：高度
		5. 盒子模型：控制布局
			* margin：外边距
			* padding：内边距
				* 默认情况下内边距会影响整个盒子的大小
				* box-sizing: border-box;  设置盒子的属性，让width和height就是最终盒子的大小
			* float：浮动
				* left
				* center
				* right



## JavaScript

```
* 概念：	一门客户端脚本语言
	* 运行在客户端浏览器中的。每一个浏览器都有JavaScript的解析引擎
	* 脚本语言：不需要编译，直接就可以被浏览器解析执行了
* 功能：
	* 可以来增强用户和html页面的交互过程，可以来控制html元素，让页面有一些动态的效果，增强用户的体验。
* JavaScript发展史：
	1. 1992年，Nombase公司，开发出第一门客户端脚本语言，专门用于表单的校验。命名为：C--	，后来更名为：ScriptEase
	2. 1995年，Netscape(网景)公司，开发了一门客户端脚本语言：LiveScript。后来，请来SUN公司的专家，修改LiveScript，命名为JavaScript
	3. 1996年，微软抄袭JavaScript开发出JScript语言
	4. 1997年，ECMA(欧洲计算机制造商协会)，制定出客户端脚本语言的标准：ECMAScript，就是统一了所有客户端脚本语言的编码方式。
	* JavaScript = ECMAScript + JavaScript自己特有的东西(BOM+DOM)
* ECMAScript：客户端脚本语言的标准
	1. 基本语法：
		1. 与html结合方式
			1. 内部JS：
				* 定义<script>，标签体内容就是js代码
			2. 外部JS：
				* 定义<script>，通过src属性引入外部的js文件
			* 注意：
				1. <script>可以定义在html页面的任何地方。但是定义的位置会影响执行顺序。
				2. <script>可以定义多个。
		2. 注释
			1. 单行注释：//注释内容
			2. 多行注释：/*注释内容*/
		3. 数据类型：
			1. 原始数据类型(基本数据类型)：
				1. number：数字。 整数/小数/NaN(not a number 一个不是数字的数字类型)
				2. string：字符串。 字符串  "abc" "a" 'abc'
				3. boolean: true和false
				4. null：一个对象为空的占位符
				5. undefined：未定义。如果一个变量没有给初始化值，则会被默认赋值为undefined
			2. 引用数据类型：对象
		4. 变量
			* 变量：一小块存储数据的内存空间
			* Java语言是强类型语言，而JavaScript是弱类型语言。
				* 强类型：在开辟变量存储空间时，定义了空间将来存储的数据的数据类型。只能存储固定类型的数据
				* 弱类型：在开辟变量存储空间时，不定义空间将来的存储数据类型，可以存放任意类型的数据。
			* 语法：
				* var 变量名 = 初始化值;
			* typeof运算符：获取变量的类型。
				* 注：null运算后得到的是object
		5. 运算符
			1. 一元运算符：只有一个运算数的运算符
				++，-- ，+(正号)  
				* ++ --: 自增(自减)
					* ++(--) 在前，先自增(自减)，再运算
					* ++(--) 在后，先运算，再自增(自减)
				* +(-)：正负号
        * 注意：在JS中，如果运算数不是运算符所要求的类型，那么js引擎会自动的将运算数进行类型转换
        * 其他类型转number：
            * string转number：按照字面值转换。如果字面值不是数字，则转为NaN（不是数字的数字）
            * boolean转number：true转为1，false转为0
			2. 算数运算符
				+ - * / % ...
			3. 赋值运算符
				= += -+....
			4. 比较运算符
				> < >= <= == ===(全等于)
				* 比较方式
          1. 类型相同：直接比较
              * 字符串：按照字典顺序比较。按位逐一比较，直到得出大小为止。
          2. 类型不同：先进行类型转换，再比较
              * ===：全等于。在比较之前，先判断类型，如果类型不一样，则直接返回false
			5. 逻辑运算符
				&& || !
				* 其他类型转boolean：
          1. number：0或NaN为假，其他为真
          2. string：除了空字符串("")，其他都是true
          3. null&undefined:都是false
          4. 对象：所有对象都为true
			6. 三元运算符
				? : 表达式
		 		var c = a > b ? 1:0;
		6. 流程控制语句：
			1. if...else...
			2. switch:
				* 在java中，switch语句可以接受的数据类型： byte int shor char,枚举(1.5) ,String(1.7)
				* 在JS中,switch语句可以接受任意的原始数据类型
			3. while
			4. do...while
			5. for
		7. JS特殊语法：
			1. 语句以;结尾，如果一行只有一条语句则;可以省略 (不建议)
			2. 变量的定义使用var关键字，也可以不使用
        * 用： 定义的变量是局部变量
        * 不用：定义的变量是全局变量(不建议)
		
	2. 基本对象：
		1. Function：函数(方法)对象
        1. 创建：
        		1. 
               function 方法名称(形式参数列表){
                  方法体
               }
            2. 
               var 方法名 = function(形式参数列表){
               		方法体
               }
        2. 方法：

        3. 属性：
            length:代表形参的个数
        4. 特点：
            1. 方法定义是，形参的类型不用写,返回值类型也不写。
            2. 方法是一个对象，如果定义名称相同的方法，会覆盖
            3. 在JS中，方法的调用只与方法的名称有关，和参数列表无关
            4. 在方法声明中有一个隐藏的内置对象（数组），arguments,封装所有的实际参数
        5. 调用：
            方法名称(实际参数列表);
		2. Array:数组对象
        1. 创建：
            1. var arr = new Array(元素列表);
            2. var arr = new Array(默认长度);
            3. var arr = [元素列表];
        2. 方法
            join(参数):将数组中的元素按照指定的分隔符拼接为字符串
            push()	向数组的末尾添加一个或更多元素，并返回新的长度。
        3. 属性
            length:数组的长度
        4. 特点：
            1. JS中，数组元素的类型可变的。
            2. JS中，数组长度可变的。
		3. Boolean
		4. Date：日期对象
        1. 创建：
            var date = new Date();
        2. 方法：
            toLocaleString()：返回当前date对象对应的时间本地字符串格式
            getTime():获取毫秒值。返回当前如期对象描述的时间到1970年1月1日零点的毫秒值差
		5. Math：数学对象
        1. 创建：
            * 特点：Math对象不用创建，直接使用。  Math.方法名();
        2. 方法：
            random():返回 0 ~ 1 之间的随机数。 含0不含1
            ceil(x)：对数进行上舍入。
            floor(x)：对数进行下舍入。
            round(x)：把数四舍五入为最接近的整数。
        3. 属性：
            PI
		6. Number
		7. String
		8. RegExp：正则表达式对象
			1. 正则表达式：定义字符串的组成规则。
				1. 单个字符:[]
					如： [a] [ab] [a-zA-Z0-9_]
					* 特殊符号代表特殊含义的单个字符:
						\d:单个数字字符 [0-9]
						\w:单个单词字符[a-zA-Z0-9_]
				2. 量词符号：
					?：表示出现0次或1次
					*：表示出现0次或多次
					+：出现1次或多次
					{m,n}:表示 m<= 数量 <= n
						* m如果缺省：{,n}:最多n次
						* n如果缺省：{m,} 最少m次
				3. 开始结束符号
					* ^:开始
					* $:结束
			2. 正则对象：
				1. 创建
					1. var reg = new RegExp("正则表达式");
					2. var reg = /正则表达式/;
				2. 方法	
					1. test(参数):验证指定的字符串是否符合正则定义的规范	
		9. Global
			1. 特点：全局对象，这个Global中封装的方法不需要对象就可以直接调用。 方法名();
			2. 方法：
			    encodeURI():url编码
			    decodeURI():url解码

			    encodeURIComponent():url编码,编码的字符更多
			    decodeURIComponent():url解码

			    parseInt(): 将字符串转为数字
			       * 逐一判断每一个字符是否是数字，直到不是数字为止，将前边数字部分转为number
			    isNaN(): 判断一个值是否是NaN
			       * NaN六亲不认，连自己都不认。NaN参与的==比较全部问false
			    eval(): 讲 JavaScript 字符串，并把它作为脚本代码来执行。
      3. URL编码
         传智播客 =  %E4%BC%A0%E6%99%BA%E6%92%AD%E5%AE%A2

* BOM

* DOM
```


#### BOM:

	1. 概念：Browser Object Model 浏览器对象模型
		* 将浏览器的各个组成部分封装成对象。
	2. 组成：
		* Window：窗口对象
		* Navigator：浏览器对象
		* Screen：显示器屏幕对象
		* History：历史记录对象
		* Location：地址栏对象
	3. Window：窗口对象
	    1. 创建
	    2. 方法
	        1. 与弹出框有关的方法：
	           alert()	显示带有一段消息和一个确认按钮的警告框。
	           confirm()	显示带有一段消息以及确认按钮和取消按钮的对话框。
	              * 如果用户点击确定按钮，则方法返回true
	              * 如果用户点击取消按钮，则方法返回false
	           prompt()	显示可提示用户输入的对话框。
	              * 返回值：获取用户输入的值
	        2. 与打开关闭有关的方法：
	           close()	关闭浏览器窗口。
	              * 谁调用我 ，我关谁
	           open()	打开一个新的浏览器窗口
	              * 返回新的Window对象
	        3. 与定时器有关的方式
	           setTimeout()	在指定的毫秒数后调用函数或计算表达式。
	              * 参数：
	                  1. js代码或者方法对象
	                  2. 毫秒值
	              * 返回值：唯一标识，用于取消定时器
	           clearTimeout()	取消由 setTimeout() 方法设置的 timeout。
	           setInterval()	按照指定的周期（以毫秒计）来调用函数或计算表达式。
	           clearInterval()	取消由 setInterval() 设置的 timeout。
	    3. 属性：
	        1. 获取其他BOM对象：
	        		history
	            location
	            Navigator
	            Screen:
					2. 获取DOM对象
	            document
	    4. 特点
					* Window对象不需要创建可以直接使用 window使用。 window.方法名();
	        * window引用可以省略。  方法名();
	4. Location：地址栏对象
	    1. 创建(获取)：
	        1. window.location
	        2. location
	    2. 方法：
	        * reload()	重新加载当前文档。刷新
	    3. 属性
	        * href	设置或返回完整的 URL。
	5. History：历史记录对象
	    1. 创建(获取)：
	        1. window.history
	        2. history
	    2. 方法：
	        * back()	加载 history 列表中的前一个 URL。
	        * forward()	加载 history 列表中的下一个 URL。
	        * go(参数)	加载 history 列表中的某个具体页面。
	            * 参数：
	                * 正数：前进几个历史记录
	                * 负数：后退几个历史记录
	    3. 属性：
	        * length	返回当前窗口历史列表中的 URL 数量。


#### DOM：

	* 概念：Document Object Model 文档对象模型
		* 将标记语言文档的各个组成部分，封装为对象。可以使用这些对象，对标记语言文档进行CRUD的动态操作

```
* W3C DOM 标准被分为 3 个不同的部分：
	* 核心 DOM - 针对任何结构化文档的标准模型
		* Document：文档对象
		* Element：元素对象
		* Attribute：属性对象
		* Text：文本对象
		* Comment:注释对象
		* Node：节点对象，其他5个的父对象
	* XML DOM - 针对 XML 文档的标准模型
	* HTML DOM - 针对 HTML 文档的标准模型
```

```
* 核心DOM模型：
	* Document：文档对象
		1. 创建(获取)：在html dom模型中可以使用window对象来获取
			1. window.document
			2. document
		2. 方法：
			1. 获取Element对象：
				1. getElementById()：根据id属性值获取元素对象。id属性值一般唯一
				2. getElementsByTagName()：根据元素名称获取元素对象们。返回值是一个数组
				3. getElementsByClassName()：根据Class属性值获取元素对象们。返回值是一个数组
				4. getElementsByName()：根据name属性值获取元素对象们。返回值是一个数组
			2. 创建其他DOM对象：
				createAttribute(name)
        createComment()
        createElement()
        createTextNode()
		3. 属性
      * Element：元素对象
        1. 获取/创建：通过document来获取和创建
        2. 方法：
          1. removeAttribute()：删除属性
          2. setAttribute()：设置属性
      * Node：节点对象，其他5个的父对象
        * 特点：所有dom对象都可以被认为是一个节点
        * 方法：
          * CRUD dom树：
            * appendChild()：向节点的子节点列表的结尾添加新的子节点。
            * removeChild()：删除（并返回）当前节点的指定子节点。
            * replaceChild()：用新节点替换一个子节点。
        * 属性：
          * parentNode 返回节点的父节点。
        * HTML DOM
          1. 标签体的设置和获取：innerHTML
          2. 使用html元素对象的属性
          3. 控制元素样式
            1. 使用元素的style属性来设置
              //修改样式方式1
              div1.style.border = "1px solid red";
              div1.style.width = "200px";
              //font-size--> fontSize
              div1.style.fontSize = "20px";
            2. 提前定义好类选择器的样式，通过元素的className属性来设置其class属性值。
```




#### 事件监听机制：

	* 概念：某些组件被执行了某些操作后，触发某些代码的执行。	
		* 事件：某些操作。如：单击，双击，键盘按下了，鼠标移动了
		* 事件源：组件。如：按钮 文本输入框...
		* 监听器：代码。
		* 注册监听：将事件，事件源，监听器结合在一起。 当事件源上发生了某个事件，则触发执行某个监听器代码。


	* 常见的事件：
		1. 点击事件：
			1. onclick：单击事件
			2. ondblclick：双击事件
		2. 焦点事件
			1. onblur：失去焦点
			2. onfocus：元素获得焦点。
		3. 加载事件：
			1. onload：一张页面或一幅图像完成加载。
		4. 鼠标事件：
			1. onmousedown	鼠标按钮被按下。
			2. onmouseup	  鼠标按键被松开。
			3. onmousemove	鼠标被移动。
			4. onmouseover	鼠标移到某元素之上。
			5. onmouseout	  鼠标从某元素移开。
		5. 键盘事件：
			1. onkeydown	某个键盘按键被按下。	
			2. onkeyup		某个键盘按键被松开。
			3. onkeypress	某个键盘按键被按下并松开。
		6. 选择和改变
			1. onchange	域的内容被改变。
			2. onselect	文本被选中。
		7. 表单事件：
			1. onsubmit	确认按钮被点击。
			2. onreset	重置按钮被点击。
