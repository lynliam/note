# std::function和std::bind

### std::function

类模板 std :: function 是一个通用的多态函数包装器。 std :: function 的实例可以存储，复制和调用任何可调用的目标 ：包括函数，lambda表达式，绑定表达式或其他函数对象，以及指向成员函数和指向数据成员的指针。当std::function对象未包裹任何实际的可调用元素，调用该 std::function 对象将抛出std::bad_function_call 异常。**它的最基本的作用是，简化调用的复杂程度，统一调用的方式。

> std::bind与 std::function 不同的是，**function 是模板类，bind 是模板函数，而 bind 返回的可调用对象可以直接给 function 进行包装并保存**。
>
> 为什么要进行“包装”与“转发”呢？
>
> 首先，不规范的解释是，function 的作用是包装，它可以包装类成员函数，但却无法生成类成员函数的可调用对象。而 std::bind 则是可以生成。

std::function 包含于头文件 `#includ<functional>` 中，可将各种可调用实体进行封装统一，包括：

1. 普通函数
2. lambda表达式
3. 函数指针
4. 仿函数(functor 重载括号运算符实现)
5. 类成员函数
6. 静态成员函数



### std::bind

可将std::bind函数看作一个通用的函数适配器，它接受一个可调用对象，生成一个新的可调用对象来“适应”原对象的参数列表。std::bind将**可调用对象与其参数一起进行绑定**，绑定后的结果可以使用**std::function**保存。那么什么是“绑定”？它本身作为延迟计算的思想的一种实现，**作为一个调用过程当中的转发者而存在，返回一个 std::function 对象**。std::bind主要有以下两个作用：

- 将可调用对象和其参数绑定成一个仿函数；
- 只绑定部分参数，减少可调用对象传入的参数。

####  std::bind绑定普通函数

```cp
auto NewCall = std::bind(callableFunction, std::placeholders::_1);
```

> 1，调用指向非静态成员函数指针或指向非静态数据成员指针时，首参数必须是引用或指针（可以包含智能指针，如 std::shared_ptr 与 std::unique_ptr），指向将访问其成员的对象。
> 2，到 bind 的参数被复制或移动，而且决不按引用传递，除非包装于 std::ref 或 std::cref 。
> 3，允许同一 bind 表达式中的多重占位符（例如多个 `_1` ），但结果仅若对应参数（ `u1` ）是左值或不可移动右值才良好定义。
>  --- CPP Reference

- bind的第一个参数是函数名，普通函数做实参时，会隐式转换成函数指针。因此std::bind(callableFunc,_1,2)等价于std::bind (&callableFunc,_1,2)；
- _1表示占位符，位于<functional>中，std::placeholders::_1；
- 第一个参数被占位符占用，表示这个参数以调用时传入的参数为准，在这里调用NewCallable时，给它传入了10，其实就想到于调用callableFunc(10,2);

* bind绑定类成员函数时，第一个参数表示对象的成员函数的指针，第二个参数表示对象的地址。
* 必须显式地指定&Base::diplay_sum，因为编译器不会将对象的成员函数隐式转换成函数指针，所以必须在Base::display_sum前添加&；
* 使用对象成员函数的指针时，必须要知道该指针属于哪个对象，因此第二个参数为对象的地址 &base；



## 回调函数

回调函数的创建步骤大概为：

1，声明一个函数指针类型。

2，拟写使用回调函数的函数，将函数指针类型及变量名声明作为参数传递。

3，拟写符合函数指针类型的实现函数，将实现函数的指针作为参数传递给使用它的函数。

```cpp
//定义回调函数的指针类型，返回值类型和函数指针，参数表
typedef int (*Calc)(int a, int b);

int CalcValue(int a, int b, const Calc &func) {
    return func(a, b);
}

int Add(int a, int b) {
    return a + b;
}

int main()
{
    int a = 4;
    int b = 6;
    int c = CalcValue(a, b, Add);

    std::cout << "Value: " << c << std::endl;
    return EXIT_SUCCESS;
}
//上面演示了最简单的回调函数创建及使用，然而，上面的代码却出现了一个局限性，就是：
//如果需要去回调一个类成员函数，函数指针则无法指向类成员函数。
```

