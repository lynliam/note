

# python学习

```python
#注释
'''
多行注释
'''
"""
行与缩进
"""
#多行语句
total = item_1 + \
item_2
#python中单双引号完全相同
#使用r可以让反斜杠不转义
print(r'Ru\noob')
>>> Ru\noob
```

## 基本数据类型

Python变量不需要声明。

Python允许同时为多个变量赋值。

> #### 标准数据类型

六大数据类型

### Number

* int
* float
* bool
* complex

```python
isinstance()    #会认为子类是父类
type()          #不会认为子类是父类

#创建Number对象方法
var=1
a,b=1,100
a=b=c=d=10
#删除对象方法
del var

#数值运算
2/4    #得到浮点数
2//7   #得到整数
2 **5  #乘方
17%3   #取余
#混合运算时会将整型转换成浮点数
```



* string、list 和 tuple 都属于 sequence（序列）

  ### String

Python中的字符串不能被改变

Python 不支持单字符类型

```python
str_1= "djkfjd"
str_2 = "hello\n"
#字符串截取格式：    变量[头下标:头上标]
```

|  -6  |  -5  |  -4  |  -3  |  -2  |  -1  |
| :--: | :--: | :--: | :--: | :--: | :--: |
|  0   |  1   |  2   |  3   |  4   |  5   |
|  R   |  u   |  n   |  o   |  o   |  b   |

| ：   | 1    |  2   |  3   |  4   |    5 |   ： |
| :--- | :--- | :--: | :--: | :--: | ---: | ---: |
| ：   | -5   |  -4  |  -3  |  -2  |   -1 |   ： |



```python
# + 是字符串连接符
# * 表示复制当前字符串

str = 'Runoob'

print (str)          # 输出字符串
print (str[0:-1])    # 输出第一个到倒数第二个的所有字符
print (str[0])       # 输出字符串第一个字符
print (str[2:5])     # 输出从第三个开始到第五个的字符
print (str[2:])      # 输出从第三个开始的后的所有字符
print (str * 2)      # 输出字符串两次，也可以写成 print (2 * str)
print (str + "TEST") # 连接字符串
print (str[1:4:2])   # 截取1-4之间的元素，并且获取步长2（间隔1）
print (str[1:4:-1])  #最后一个参数附属表示逆向读取
```

转义字符：

需要使用特殊字符时可以用```\```来转义

```python
\    #续行符
\000 #空字符
```

字符串运算符：

```python
+
*
[]
[:]
in           #判断该字符是不是在字符串中
not in
r/R          #原始字符串
%            #格式字符串
```

#### Python字符串格式化：

```python
#Python支持格式化字符串
%c
%s
%d
#格式化操作符辅助指令：
*             #定义宽度或者小数点精度
-             #用做左对齐
+             #在证书前面显示加号
0             #在数字前面填充0
m.n.          #m显示最小总宽度，n是小数点后面的位数
print("Hello %s"% name)
```

#### Python三引号：

允许跨行字符串

#### F-string(字面量格式化字符串):

以`***f*** 开头

```python
name = "rlsif"
f'Hello {name}'
```

内建函数：

```python
capitalize()              #将第一个字符转换成大写
count(str, beg=0,end=len(string))     #返回范围内string出现的次数
find(str,bdg=0,end=len(string))       #检测指定范围内是否有该值
```



### List

列表是写在方括号 ```[]``` 之间、用逗号分隔开的元素列表， 元素类型可以不同。

列表同样可以被索引和截取

列表中的元素可以**`改变`**

```python
list = [ 'abcd', 786 , 2.23, 'runoob', 70.2 ]
tinylist = [123, 'runoob']

# + 是连接符，  * 是重复操作符
print (list)            # 输出完整列表
print (list[0])         # 输出列表第一个元素
print (list[1:3])       # 从第二个开始输出到第三个元素
print (list[2:])        # 输出从第三个元素开始的所有元素
print (tinylist * 2)    # 输出两次列表
print (list + tinylist) # 连接列表
```

#### 更新List

```python
list1.append("kdk")
```

#### 删除元素

```python
del list1[2]
```

#### 脚本操作符

```python
len()
max()
min()
list(seq)      #将元组转换为列表
[1,2,3]+['d',5,'s']
[1,5,]*10
3 in (1,3,2)
for x in (1,2,3)
```

#### 嵌套List

```python
[[4,5],['dd']]
```

#### List比较(比较是否相同）：

```python
import operator
operator.eq(list1,lsit2)
```

#### 方法：

```python
list.append(obj)
list.count(obj)
list。extend(seq)
list.index(obj)        #找出匹配的索引
list.insert(insdex,obj)
lsit.pop([index=-1])
list.remove(obj)        #移除第一个匹配值
lsit.clear()
list.copy()             #复制列表
list.sort()             #对原列表进行排序
list.reverse()          #反向列表元素
```



### Tuple (元组)

元组元素不能修改，元素类型可以不同。

元组的元素不可改变，但它可以包含可变的对象，比如list列表。

元组中**只包含一个元素**时，需要在元素后面添加逗号 ”**,**“ ，否则括号会被当作运算符使用

```python
tuple = ( 'abcd', 786 , 2.23, 'runoob', 70.2  )
tinytuple = (123, 'runoob')

print (tuple)             # 输出完整元组
print (tuple[0])          # 输出元组的第一个元素
print (tuple[1:3])        # 输出从第二个元素开始到第三个元素
print (tuple[2:])         # 输出从第三个元素开始的所有元素
print (tinytuple * 2)     # 输出两次元组
print (tuple + tinytuple) # 连接元组
#与字符串具有相同的截取方法，字符串可以看做是特殊的元组。
```

```python
tup1 = ()    # 空元组
tup2 = (20,) # 一个元素，需要在元素后添加逗号
```

#### 对元组进行组合

```python
tup1=(12,65,45)
tup2=(12,)
tup3 = tup1+tup2
```

#### 删除元组

```python
del tup1
```

#### 脚本操作符

```python
#与List一致
```

#### 内置函数

```python
tuple(iterable)         #将可迭代系列转化为元组
```





### Set （集合）

Set是由一个或者数个形态各异的大小整体组成的，构成集合的实物或对象称作元素或者是成员。

功能：成员关系测试和删除重复元素。

```python
sites = {'Google', 'Taobao', 'Runoob', 'Facebook', 'Zhihu', 'Baidu'}
set(sites)
#创建一个空集合必须用set()而不是{},{}创建一个空字典。
print(sites)   # 输出集合，重复的元素被自动去掉

# 成员测试
if 'Runoob' in sites :
    print('Runoob 在集合中')
else :
    print('Runoob 不在集合中')


# set可以进行集合运算
a = set('abracadabra')
b = set('alacazam')

print(a)

print(a - b)     # a 和 b 的差集

print(a | b)     # a 和 b 的并集

print(a & b)     # a 和 b 的交集

print(a ^ b)     # a 和 b 中不同时存在的元素
```

#### 内置函数

```python
s.add(x)              #添加元素
s.update(seq)           #添加列表，元组或者字典
s.clear()            #移除所有元素
s.remove(x)          #移除时，不存在会报错
s.discard(x)         #~移除不会报错
s.pop()              #随机删除
union()              #返回两个集合的并集
```



### Dictionary

字典是无序对象的集合。字典中的元素是通过键来存取的，而不是便偏移存储。

```键(Key)：值(Value)```的集合。```{ }```

字典中的关键字必须为不可变类型。

**键**  必须唯一不可变

```python
dict = {}
dict['one'] = "1 - 菜鸟教程"
dict[2]     = "2 - 菜鸟工具"

tinydict = {'name': 'runoob','code':1, 'site': 'www.runoob.com'}

print (dict['one'])       # 输出键为 'one' 的值
print (dict[2])           # 输出键为 2 的值
print (tinydict)          # 输出完整的字典
print (tinydict.keys())   # 输出所有键
print (tinydict.values()) # 输出所有值
#构造函数 dict() 可以直接从键值对序列中构建字典
dict([('Runoob', 1), ('Google', 2), ('Taobao', 3)])
{x: x**2 for x in (2, 4, 6)}
dict(Runoob=1, Google=2, Taobao=3)

#添加键值对
tinydict['df']= 8
```

#### 删除

```python
del tinydict['df']
del ttinydict                #删除字典
```

#### 字典值

```python
#创建时如果同一个键被赋值两次，后一个值会被记住
```

#### 内置函数&方法

```python
len(dict)
str(dict)
dict.clear()
dict.copy()
dict.fromkeys()                         #创建一个新字典
dict.get(key,default=None)              #返回指定值的值，如果不在返回default里面设置的值
pop(key[,default])
dict.setdefault(key,default=None)
key in dict
```



------

## 数据类型转换

* 隐式类型转换

一般较低的数据类型转换为较高的数据类型，避免数据丢失。

* 显式类型转换

强制类型转换。

```python
int()
float()
complex(x)
complex(x,y)    #将x,y转换成一个复数，y为虚部
str()
#转换成相应字符串
oct(s)
hex(s)
chr(x)

```



------

## Python推导式

Python 推导式是一种独特的数据处理方式，可以从一个数据序列构建另一个新的数据序列的结构体。

#### 列表推导式

```python
news= ['dfdf','dfdfs']
news_name = [name.upper() for name in news if len(name)>3]
```

#### 字典推导式

```python
{ key_expr: value_expr for value in collection if condition }
```

#### 集合推导式

```python
{ expression for item in Sequence if conditional }
```

#### 元组推导式（生成器表达式）

```python
(expression for item in Sequence if conditional)
```

------

## 解释器

让py脚本像SHELL脚本一样直接执行

```
#! /usr/bin/env python3
```

------

## 运算符

```python
:=  #海象运算符

#位运算符
&
|
^     #按位异或
~
<<
>>

#逻辑运算符
x and y
x or y 
not x

#成员运算符
in             #在指定序列中找到值则返回True
not in

#身份运算符
is            #两个标识符是不是引用自同一个对象，判断两个变量引用对象是否为同一个
is not 
```



## 条件控制

```python
#if语句
if condition_q:
   	if condition:
        djfkld
elif condition_2:
    djkf
else:
    djfkd

#match...case 
#类似于switch...case
match subject:
    case <pattern_1>:
        <action_1>
    case_:
        <action_wildcard>
```

## 循环

```python
while (condition):
    (statements)
    
    
#while循环+else
while<expr>:
    <statement>
else:
    <additional_statements>
    
#简单语句组
while(flag): print("djfdk")

#for
for <variable> in <sequence>:
    <statement>
else:
    <statement>
    
#for...else
for item in iterable:
    <statement>
else:
    <statememt>
    
range()
break
continue
pass     #空语句为了保持程序结构的完整性
```

## 迭代器和生成器

迭代器对象从集合的第一根元素开始访问，且只能前进。

```iter()```   和   ```next()```

```python
list_1[1,2,3.4]
it = iter(list_1)      #创建迭代器对象
print(next(it))

for x in it:
    print(x,end=" ")
    
while True:
    try:
        print(next(it))
    except StopIteration:
        sys.exit()
```

生成器：返回迭代器的函数，只能用于迭代操作。一边循环一边计算的机制。

## 函数

```python
def max(a,b):
    if a>b:
        return a
    else:
        return b
    

```

#### 参数传递

在Python中，类型属于对象，对象有不同的类型区分，变量是没有类型的。

* 不可变类型：类似C++的值传递，（整数，字符串，元组）  ，对当前对象的修改是不会影响到原来的对象的。
* 可变类型：类似C++的引用传递（列表，字典）

#### 参数

* 必须参数

必须正确的传入函数，调用数量必须和声明的一致

* 关键字参数

使用函数中的关键字参数

```python
def print_my(str,a):
    print(str*a)
    return
print_my(str="dfdf",a=2)
```

* 默认参数

```python
def print_my(str='dfdf',a=1):
    ~
    return

```

* 不定长参数

```python
def functionname([formal_args,] *var_args_tuple ):
   "函数_文档字符串"
   function_suite
   return [expression]
#加了星号 * 的参数会以元组(tuple)的形式导入，存放所有未命名的变量参数。
def printinfo( arg1, *vartuple ):
   "打印任何传入的参数"
   print ("输出: ")
   print (arg1)
   print (vartuple)
```

```markdown
输出: 
70
(60, 50)
```

```python
def functionname([formal_args,] **var_args_dict ):
   "函数_文档字符串"
   function_suite
   return [expression]
#加了两个星号 ** 的参数会以字典的形式导入。
# 可写函数说明
def printinfo( arg1, **vardict ):
   "打印任何传入的参数"
   print ("输出: ")
   print (arg1)
   print (vardict)
 
# 调用printinfo 函数
printinfo(1, a=2,b=3)
```

#### 匿名函数

Python 使用 **lambda** 来创建匿名函数。

所谓匿名，意即不再使用 **def** 语句这样标准的形式定义一个函数。

- **lambda** 只是一个表达式，函数体比 **def** 简单很多。
- lambda 的主体是一个表达式，而不是一个代码块。仅仅能在 lambda 表达式中封装有限的逻辑进去。
- lambda 函数拥有自己的命名空间，且不能访问自己参数列表之外或全局命名空间里的参数。
- 虽然 lambda 函数看起来只能写一行，却不等同于 C 或 C++ 的内联函数，后者的目的是调用小函数时不占用栈内存从而增加运行效率。

```python
#语法
lambda [arg1 [,arg2,......argn]]:expression
```

#### 强制位置参数

Python3.8 新增了一个函数形参语法 / 用来指明函数形参必须使用指定位置参数，不能使用关键字参数的形式。



## 模块

```python
import sys
from modname import name1[,name2,....]
from modname import *

#__name__属性，当其值是'__main__'时，表示模块自身正在运行，否则表示被引用。
```

```dir()```函数可以找到模块内定义的所有名称，以字符串列表的形式返回。



## Python3输入输出

* ```str()```：返回一个用户易读的表达形式
* ```repr()```：产生一个解释器易读的表达式

```python
string_1.rjust(num)       #将字符串靠右
string_1.zfill(num)       #将字符串靠左
```

```str.format()```的使用

```python
print("{}是{}".format("胡萝卜","蔬菜"))
print("{1}是{0}".format("蔬菜","胡萝卜"))
print("{name}是{veg}".format(name="胡萝卜",veg="蔬菜"))
{!a}   =   ascii()
{!s}   =   str()
{!r}   =   repr()
print('常量 PI 的值近似为 {0:.3f}。'.format(math.pi))
print('{0:10} ==> {1:10d}'.format(name, number))
table = {'Google': 1, 'Runoob': 2, 'Taobao': 3}
print('Runoob: {0[Runoob]:d}; Google: {0[Google]:d};Taobao{0[Taobao]:d}'.format(table))
```

输入

```python
str=input("请输入：")
```

