# Python



## 基础语法

#### 标准数据类型

- Numbers
- String
- List（列表）
- Tuple（元组）
- Dictionary（字典）

#### 变量

```python
counter = 100
name = "Tom"
print counter
print name
# 100
# Tom
```

#### del

删除对象引用，语法：`del var1[,var2[,var3[....,varN]]]`

```python
del counter, name
```

#### 数字

- int（有符号整型）
- long（长整形）L
- float（浮点型）
- complex（复数）j

#### 字符串

```python
	R		U		N		O		O		B
	0 	1 	2 	3 	4 	5
 -6 	-5 	-4 	-3 	-2 	-1
```

```python
s = "runoob"
print s[0] 			# r
print s[1,3] 		# un
print s[-4]			# n
print s * 2 		# runoobrunoob
print s + 'aaa' # runoobaaa
```

#### 列表

![python_list_01](/Users/digiqal/Documents/git/gitee/notes_dev/python/img/python_list_01.png)

```python
list = ['runoob', 786, 2.23, 'john', 70.2]
tinylist = [123, 'john']

print list[0]  			# runoob
print list[1:3]  		# [786, 2.23]
print list[2:]  		# [2.23, 'john', 70.2]
print tinylist * 2  # [123, 'john', 123, 'john']
print list + tinylist  # ['runoob', 786, 2.23, 'john', 70.2, 123, 'john']
```

#### 元组

不能二次赋值，相当于只读列表

```python
tuple = ( 'runoob', 786, 2.23, 'john', 70.2 )
tinytuple = (123, 'john')

print tuple[0]  			# runoob
print tuple[1:3]  		# [786, 2.23]
print tuple[2:]  			# [2.23, 'john', 70.2]
print tinytuple * 2  	# [123, 'john', 123, 'john']
print tuple + tinytuple  # ['runoob', 786, 2.23, 'john', 70.2, 123, 'john']
```

*`tuple[0] = 'abc'` 是不合法的*

#### 字典

```python
dict = {}
dict['one'] = "This is one"
dict[2] = "This is two"

tinydict = {'name': 'runoob','code':6734, 'dept': 'sales'} 
 
print dict['one']          # This is one
print dict[2]              # This is two
print tinydict             # {'dept': 'sales', 'code': 6734, 'name': 'runoob'}
print tinydict.keys()      # ['dept', 'code', 'name']
print tinydict.values()    # ['sales', 6734, 'runoob']
```

#### 数据类型转换

| 函数                                                         | 描述                                                |
| :----------------------------------------------------------- | :-------------------------------------------------- |
| [int(x, base)](https://www.runoob.com/python/python-func-int.html) | 将x转换为一个整数                                   |
| [long(x, base)](https://www.runoob.com/python/python-func-long.html) | 将x转换为一个长整数                                 |
| [float(x)](https://www.runoob.com/python/python-func-float.html) | 将x转换到一个浮点数                                 |
| [complex(real, imag)](https://www.runoob.com/python/python-func-complex.html) | 创建一个复数                                        |
| [str(x)](https://www.runoob.com/python/python-func-str.html) | 将对象 x 转换为字符串                               |
| [repr(x)](https://www.runoob.com/python/python-func-repr.html) | 将对象 x 转换为表达式字符串                         |
| [eval(str)](https://www.runoob.com/python/python-func-eval.html) | 用来计算在字符串中的有效Python表达式,并返回一个对象 |
| [tuple(s)](https://www.runoob.com/python/att-tuple-tuple.html) | 将序列 s 转换为一个元组                             |
| [list(s)](https://www.runoob.com/python/att-list-list.html)  | 将序列 s 转换为一个列表                             |
| [set(s)](https://www.runoob.com/python/python-func-set.html) | 转换为可变集合                                      |
| [dict(d)](https://www.runoob.com/python/python-func-dict.html) | 创建一个字典。d 必须是一个序列 (key,value)元组。    |
| [frozenset(s)](https://www.runoob.com/python/python-func-frozenset.html) | 转换为不可变集合                                    |
| [chr(x)](https://www.runoob.com/python/python-func-chr.html) | 将一个整数转换为一个字符                            |
| [unichr(x)](https://www.runoob.com/python/python-func-unichr.html) | 将一个整数转换为Unicode字符                         |
| [ord(x)](https://www.runoob.com/python/python-func-ord.html) | 将一个字符转换为它的整数值                          |
| [hex(x)](https://www.runoob.com/python/python-func-hex.html) | 将一个整数转换为一个十六进制字符串                  |
| [oct(x)](https://www.runoob.com/python/python-func-oct.html) | 将一个整数转换为一个八进制字符串                    |



## 运算符

#### 逻辑运算符

##### and、or、not

```python
a = 10
b = 20
```

| 运算符 | 逻辑表达式 | 描述                                                         | 实例                    |
| :----- | :--------- | :----------------------------------------------------------- | :---------------------- |
| and    | x and y    | 布尔"与" - 如果 x 为 False，x and y 返回 False，否则它返回 y 的计算值。 | (a and b) 返回 20。     |
| or     | x or y     | 布尔"或" - 如果 x 是非 0，它返回 x 的计算值，否则它返回 y 的计算值。 | (a or b) 返回 10。      |
| not    | not x      | 布尔"非" - 如果 x 为 True，返回 False 。如果 x 为 False，它返回 True。 | not(a and b) 返回 False |

#### 成员运算符

##### in、not in

| 运算符 | 描述                                                    | 实例                                              |
| :----- | :------------------------------------------------------ | :------------------------------------------------ |
| in     | 如果在指定的序列中找到值返回 True，否则返回 False。     | x 在 y 序列中 , 如果 x 在 y 序列中返回 True。     |
| not in | 如果在指定的序列中没有找到值返回 True，否则返回 False。 | x 不在 y 序列中 , 如果 x 不在 y 序列中返回 True。 |

```python
a = 10
list = [1, 2, 3, 4, 5 ]
 
if ( a not in list ):
   print "变量 a 不在给定的列表中 list 中"
else:
   print "变量 a 在给定的列表中 list 中"
```

#### 身份运算符

##### is、is not

用于比较两个对象的存储单元

| 运算符 | 描述                                        | 实例                                                         |
| :----- | :------------------------------------------ | :----------------------------------------------------------- |
| is     | is 是判断两个标识符是不是引用自一个对象     | **x is y**, 类似 **id(x) == id(y)** , 如果引用的是同一个对象则返回 True，否则返回 False |
| is not | is not 是判断两个标识符是不是引用自不同对象 | **x is not y** ， 类似 **id(a) != id(b)**。如果引用的不是同一个对象则返回结果 True，否则返回 False。 |

> is 与 == 区别：
>
> is 用于判断两个变量引用对象是否为同一个(同一块内存空间)， == 用于判断引用变量的值是否相等。



## 条件语句

#### if、elif、else

```python
if 条件1:
  执行1
elif 条件2:
  执行2
else: 
  执行3
```

#### while

```python
while 条件:
  执行语句
```

```python
while 条件:
  执行语句
else: 
  执行语句
```

#### for

```python
for iterating_var in sequence:
   statements(s)
```

```python
fruits = ['banana', 'apple',  'mango']
for fruit in fruits:
   print ('水果: %s'% fruit)
```

通过序列索引迭代

```python
fruits = ['banana', 'apple',  'mango']
for index in range(len(fruits)):
   print ('水果 : %s' % fruits[index])
```

使用 else 语句

```python
for num in range(10,20):  # 迭代 10 到 20 之间的数字
   for i in range(2,num): # 根据因子迭代
      if num%i == 0:      # 确定第一个因子
         j=num/i          # 计算第二个因子
         print ('%d 等于 %d * %d' % (num,i,j))
         break            # 跳出当前循环
   else:                  # 循环的 else 部分
      print ('%d 是一个质数' % num)
```

#### break

终止当前循环

#### continue

跳出本次循环，而break跳出整个循环



## 数字

https://www.runoob.com/python/python-numbers.html



























