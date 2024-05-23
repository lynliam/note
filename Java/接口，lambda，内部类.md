# 第六章

### 6.1 接口（没有实例字段的抽象类）：

接口是对希望符合这个接口的类的一组需求。接口例子：

```java
//接口中所有方法自动都是 public
//接口可以定义常量

public interface Comparable<T>
{
    int compareTo(T other)
}
```

为了使用一个接口：

* 将类声明为实现给定的接口
* 对接口中所有方法***(方法一定是public的，字段是public static final)***提供定义

```java
class Employee impliments Comparale<Employee>
{
    public int compareTo(Employee other)
    {
        return Double.compare(salary, other.salary);
	}
}
```



#### 接口的属性：

* 不能构造接口的对象，却能声明接口的变量。
* 允许由多条接口链，从通用性较高的接口扩展到专用性较高的接口。
* 每个类可以实现多个接口。
* 允许在接口中增加静态方法（通常做法都是将静态方法放在伴随类当中）



#### 使用接口变量接受对象的好处：

定义接口变量为接受类型属于面对接口的变成，通过接口的抽象能减少类之间的耦合，增加复用性。

* 一种规范约束：  使用的都是一套API
* 分离设计和实现：  使得系统支持开闭原则和依赖倒转原则。程序员只需要按接口写实现。
* 解耦合：替换实现类的时候，可以将影响减少到最少。
* 方便做单元测试
* 与设计有关：**接口和实现分离**
* String的Ioc



### 默认方法：

可以为接口方法提供一个**默认实现**，是接口演化中的重要用法：

给类中指定一个默认方法可以有效避免使用这个接口的类的兼容性（因为每个接口中的方法，类必须去实例化）



### 解决默认方法冲突：

1. 超类优先
2. 接口冲突

```java
public interface Person
{
    default String getName() {retutn "";}
}
public interface Named
{
    default String getName() {return getClass().getName() + " "+hashCode();}
}
//这样就可以指定其选择冲突方法中的一个
class Student implements Person,Named
{
	public String getName() {return Person.super.getName();}
}
```



### 对象克隆：

``Cloneable``接口



## Lambda表达式：

lambda表达式就是一个代码块，以及必须传入的代码的变量规范。无需指定lambda表达式的**返回类型**。lambda表达式可以转换成接口。

```java
(String first, String second) -> 
{
	if(first.length()  < second.length())
        return 0;
}
```



* 如果可以推断参数类型，则可以忽略参数
* 如果只有一个参数且可以被推断，则可以忽略小括号



#### 函数式接口：

函数式接口：只有一个抽象方法的接口，需要这种接口的对象时，就可以提供一个Lambda表达式。

可以使用```BiFunction<T,U,R>```描述并接收参数类型为T和U而且返回类型为R的函数：

```java
BIFunction<String, String, Integer> cmp = (String first, String second) -> 
{
	if(first.length()  < second.length())
        return 0;
}
```

![image-20230308160858998](/home/lynliam/.config/Typora/typora-user-images/image-20230308160858998.png)

![image-20230308160935630](/home/lynliam/.config/Typora/typora-user-images/image-20230308160935630.png)

#### 方法引用：

方法引用，止时编译器生成一个函数时的接口实例，覆盖这个接口的抽象方法来调用给定的方法。只有当Lambda表达式的体**只调用一个方法**而不做其他操作的时候，再把lambda重写为方法引用。

使用```::```运算符分割方法名和对象

1. ```object::instanceMethod```
2. ```Class::instanceMethod```     :第一个参数会变成隐式参数。    ？？？？
3. ```Class::staticMethod```       :```Math::pow = (x,y)->Math.pow(x,y)```

```java
var timer = new Timer(1000,event->System.out.println(event));
=
var timer = new Timer(1000,System.out::println);
```

可以在方法引用中使用```this```参数以及```super```             例子：```super::greet```和```this::greet```=```this.greet(this)```

```super::instanceMethod```



#### 构造器引用：

```Person::new```    是Person的构造器的一个引用。



#### 变量作用域：

lambda表达式可以补货外围作用域中的变量的值，且只能引用值不会改变的变量（无论这个变量企图在lambda表达式还是外部变化），这意味着捕获的变量必须是***事实最终变量***。

#### lambda表达式应用：

使用lambda表达式的重点是**延迟执行**，即当前不会被执行的函数。很多类似于**回调函数**。

* 在单独的线程中运行代码
* 多次运行代码
* 算法适当位置执行代码
* 发生某种情况时执行代码
* 必要时运行

若要接受这个lambda表达式，需要选择一个**函数式接口**。



#### 内部类：

* 内部类可以对同一个包中的其他类隐藏。
* 内部类可以访问原本私有的数据。

编译器会修改所有内部类构造器，添加一个对应的外围类引用的参数。如果没有定义内部类构造器，则会自动生成一个无参构造器：

```java
public TimerPrinter(TalkingClock clock)
{
    outer = clock;
}
```

```java
var listener = new TimePrinter(this);  // "this" parameter automatically added
```



#### 局部内部类：

如如果内部类型名只出现一次，则可以在一个方法中局部的定义这个类。

```java
public void start()
{
    class TimePrinter implements ActionListener
    {
        public void actionPerformed(ActionEvent event)
        {
            ...
		}
	}
    
    var listener = new TimerPrinter();
    var timer = new Timer(interval,listener);
    timer.start();
}
```



#### 静态内部类：

将内部类声明为```static```，这样就可以不生成内部类外围对象的引用。（只要内部类不需要访问外围对象，就应该使用静态内部类）

> 静态内部类
>
> * 可以有静态字段和方法。
> * 在接口中声明的内部类自动是static和public。







