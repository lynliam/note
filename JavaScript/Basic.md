# Basic of JavaScript



## 1.0     Using JS

```html
<script>document.getElementById("demo").innerHTML = "Helo";</script>
```

**提示：**把脚本置于 `<body>` 元素的底部，可改善显示速度，因为脚本编译会拖慢显示

### 外部脚本

```html
<script src="myScript1.js"></script>
<script src="myScript2.js"></script>
```



##  2.0    Output

- 使用 `window.alert()` 写入警告框
- 使用 `document.write()` 写入 HTML 输出      //**出于测试目的** 
- 使用 `innerHTML` 写入 HTML 元素  
- 使用 `console.log()` 写入浏览器控制台



## 3.0   Variable

### 3.1   重复声明 JavaScript 变量

这样并不会报错， 并且`carName` 的 值不变：

```js
var carName = "porsche";
var carName;
```

但：在相同的作用域，或在相同的块中，通过 `let` 重新声明一个 `var` 变量是不允许的

```js
var x = 10;       // 允许
let x = 6;       // 不允许

{
  var x = 10;   // 允许
  let x = 6;   // 不允许
}
```



```js
var x = "8" + 3 + 5
//提示：如果把要给数值放入引号中，其余数值会被视作字符串并被级联。
```



###  3.2    函数作用域

```js
{
    var x = 10;
}
// 此处可以使用 x
```

#### 块作用域：

```js
{ 
  let x = 10;
}
// 此处不可以使用 x
```



#### 循环作用域：

```js
var i = 7;
for (var i = 0; i < 10; i++) {
  // 一些语句
}
// 此处，i 为 10
```

```js
let i = 7;
for (let i = 0; i < 10; i++) {
  // 一些语句
}
// 此处 i 为 7
```

#### 函数作用域:

在函数内声明变量时，使用 `var` 和 `let` 很相似。

它们都有*函数作用域*



#### 全局作用域:

如果在块外声明声明，那么 `var` 和 `let` 也很相似。



#### HTML 中的全局变量:

使用 JavaScript 的情况下，全局作用域是 JavaScript 环境。

在 HTML 中，全局作用域是 window 对象。

通过 `var` 关键词定义的全局变量属于 window 对象

```js
 var carName = "porsche";
// 此处的代码可使用 window.carName

let carName = "porsche";
// 此处的代码不可使用 window.carName
```

#### 提升:

通过 `var` 声明的变量会*提升*到顶端。但 const 和 let 不会

```js
// 在此处，您可以使用 carName
var carName;
```



#### Const:

不是真正的常数, 关键字 `const` 有一定的误导性。

它没有定义常量值。它定义了对值的常量引用。 因此，我们不能更改常量原始值，但我们可以更改常量对象的属性。

```js
const PI = 3.141592653589793;
PI = 3.14;      // 会出错
//------------------------------------------------------------------------------------
// 您可以创建 const 对象：
const car = {type:"porsche", model:"911", color:"Black"};

// 您可以更改属性：
car.color = "White";

// 您可以添加属性：
car.owner = "Bill";
```



## 4.0  数据类型

**字符串值，数值，布尔值，数组，对象**

您可以在字符串内使用引号，只要这些引号与包围字符串的引号不匹配：

```js
var answer = "It's alright";             // 双引号内的单引号
var answer = "He is called 'Bill'";    // 双引号内的单引号
var answer = 'He is called "Bill"';    // 单引号内的双引号
```

### JavaScript 对象

JavaScript 对象用花括号来书写。

对象属性是 *name*:*value* 对，由逗号分隔。

实例:

```js
var person = {firstName:"Bill", lastName:"Gates", age:62, eyeColor:"blue"};
```



### Undefined

在 JavaScript 中，没有值的变量，其值是 `undefined`。typeof 也返回 `undefined`。

```js
var person;                  // 值是 undefined，类型是 undefined。
```



### Null

在 JavaScript 中，`null` 是 "nothing"。它被看做不存在的事物。 **`null` 的数据类型是对象。**

 您可以把 `null` 在 JavaScript 中是对象理解为一个 bug。它本应是 `null`。

您可以通过设置值为 `null` 清空对象：

```js
var person = null;           // 值是 null，但是类型仍然是对象
```

`Undefined` 与 `null` 的值相等，但类型不相等:

```js
typeof undefined              // undefined
typeof null                   // object

null === undefined            // false
null == undefined             // true
```





`typeof` 运算符把对象、数组或 `null` 返回 `object`。

`typeof` 运算符不会把函数返回 `object`。

```js
typeof {name:'Bill', age:62} // 返回 "object"
typeof [1,2,3,4]             // 返回 "object" (并非 "array"，参见下面的注释)
typeof null                  // 返回 "object"
typeof function myFunc(){}   // 返回 "function"
```



## 5.0  对象

访问对象属性：

```js
objectName.propertyName
//  or
objectName["propertyName"]
```



## 6.0   事件

**HTML 事件是发生在 HTML 元素上的“事情”。**

**当在 HTML 页面中使用 JavaScript 时，JavaScript 能够“应对”这些事件。**

HTML 事件：

- HTML 网页完成加载
- HTML 输入字段被修改
- HTML 按钮被点击

[HTML DOM 事件 (w3school.com.cn)](https://www.w3school.com.cn/jsref/dom_obj_event.asp)



## 7.0   字符串

内建属性 `length` 可返回字符串的*长度*

```js
var txt = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
var sln = txt.length;
```

请不要把字符串创建为对象。它会拖慢执行速度。

`new` 关键字使代码复杂化。也可能产生一些意想不到的结果：

当使用 `==` 相等运算符时，相等字符串是相等的：

当使用 `===` 运算符时，相等字符串是不相等的，因为 `===` 运算符需要类型和值同时相等。

### 方法：

* `length` 属性返回字符串的长度
* `indexOf()` 方法返回字符串中指定文本*首次*出现的索引（位置）
* `lastIndexOf()` 方法返回指定文本在字符串中*最后*一次出现的索引
  * 如果未找到文本， `indexOf()` 和 `lastIndexOf()` 均返回 -1
* `search()` 方法搜索特定值的字符串，并返回匹配的位置

```js
var str = "The full name of China is the People's Republic of China.";
var pos = str.search("locate");
```

### 提取部分字符串

有三种提取部分字符串的方法：

- slice(*start*, *end*)
- substring(*start*, *end*)      不接受负的索引
- substr(*start*, *length*)       不同之处在于第二个参数规定被提取部分的*长度*。



### 替换字符串内容

`replace()` 方法用另一个值替换在字符串中指定的值：

```js
str = "Please visit Microsoft!";
var n = str.replace("Microsoft", "W3School");
```



### String.trim()

`trim()` 方法删除字符串两端的空白符



### 提取字符串字符

这是两个提取字符串字符的*安全*方法：

- charAt(*position*)              方法返回字符串中指定下标（位置）的字符串
- charCodeAt(*position*)      `charCodeAt()` 方法返回字符串中指定索引的字符 unicode 编码



### 字符串内的引号

#### 插值

*模板字面量*提供了一种将变量和表达式插入字符串的简单方法。

该方法称为字符串插值（string interpolation）。

```js
let firstName = "Bill";
let lastName = "Gates";

let text = `Welcome ${firstName}, ${lastName}!`;
```



### JS  数字

#### JavaScript 数值始终是 64 位的浮点数

#### 数字字符串

```js
var x = "100";
var y = "10";
var z = x * y;       // z 将是 1000
```

原则：  +  由于字符串级联符号也是这个  所以不会自动去计算



#### NaN - 非数值

`NaN` 属于 JavaScript 保留词，指示某个数不是合法数。

要小心 `NaN`。假如您在数学运算中使用了 `NaN`，则结果也将是 `NaN`

#### Infinity

`Infinity` （或 `-Infinity`）是 JavaScript 在计算数时超出最大可能数范围时返回的值



## 8.0   BigInt

JavaScript BigInt 变量用于存储太大而无法用普通 JavaScript 数字表示的大整数值。

### 如何创建 BigInt

如需创建 BigInt，可以在整数末尾添加 `n`，或调用 `BigInt()` 函数：

```js
let y = 9999999999999999n;

let y = BigInt(1234567890123456789012345)
```

### BigInt 小数

BigInt 不能有小数。

### 安全整数？？？



## 9.0   数组

**JavaScript 数组用于在单一变量中存储多个值。**

```js
var cars = ["Saab", "Volvo", "BMW"];
```



### 访问完整数组

通过 JavaScript，可通过引用数组名来访问完整数组

### 数组是对象

数组是一种特殊类型的对象。在 JavaScript 中对数组使用 `typeof` 运算符会返回 "object"。

### 添加数组元素

向数组添加新元素的最佳方法是使用 `push()` 方法

```js
var fruits = ["Banana", "Orange", "Apple", "Mango"];
fruits.push("Lemon");                // 向 fruits 添加一个新元素 (Lemon)
```

或者：

```js
var fruits = ["Banana", "Orange", "Apple", "Mango"];
fruits[fruits.length] = "Lemon";     // 向 fruits 添加一个新元素 (Lemon)
```



JavaScript *不支持*命名索引的数组。  在 JavaScript 中，数组只能使用*数字索引*。

```js
var person = [];
person[0] = "Bill";
person[1] = "Gates";
person[2] = 62;
var x = person.length;          // person.length 返回 3
var y = person[0];              // person[0] 返回 "Bill"
```

假如您使用命名索引，**JavaScript 会把数组重定义为标准对象**

识别数组：

```js
Array.isArray(fruits);     // 返回 true
```



## 10.0   For  

JavaScript `for in` 语句循环遍历对象的属性   /   数组的属性

> 如果索引*顺序*很重要，请不要在数组上使用 *for in*。
>
> 索引顺序依赖于实现，可能不会按照您期望的顺序访问数组值。
>
> 当顺序很重要时，最好使用 *for* 循环、*for of* 循环或 *Array.forEach()*。

### Array.forEach()

`forEach()` 方法为每个数组元素调用一次函数（回调函数）。



### For Of 循环

JavaScript `for of` 语句循环遍历可迭代对象的值。

它允许您循环遍历可迭代的数据结构，例如数组、字符串、映射、节点列表等



### 11.0     JavaScript    类

```js
class ClassName {
  constructor(name, year) {
    this.name = name;
    this.year = year;
  }
  method_1() { ... }
  method_2() { ... }
  method_3() { ... }
}

let myCar1 = new Car("Ford", 2014);
```



如需创建类继承，请使用 `extends` 关键字。

使用类继承创建的类继承了另一个类的所有方法：

```js
class Car {
  constructor(brand) {
    this.carname = brand;
  }
  present() {
    return 'I have a ' + this.carname;
  }
}

class Model extends Car {
  constructor(brand, mod) {
    super(brand);
    this.model = mod;
  }
  show() {
    return this.present() + ', it is a ' + this.model;
  }
}

let myCar = new Model("Ford", "Mustang");
document.getElementById("demo").innerHTML = myCar.show();
```







## 11.0     JavaScript 模块

模块是使用 `import` 语句从外部文件导入的。

模块还依赖于 <script> 标签中的 `type="module"`。

```js
<script type="module">
import message from "./message.js";
</script>
```



### 导出

带有*函数*或*变量*的模块可以存储在任何外部文件中。

导出有两种类型：*命名导出*和*默认导出*。
