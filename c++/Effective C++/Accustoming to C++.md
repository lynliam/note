# Accustoming Yourself to C++

## 1.0 View C++ as a federation of languages

C++ is a federation of related languages:

* ***C***
* ***Object-Oriented C++***
* ***Template C++***
* ***The STL***



## 2.0   Prefer `consts, enums, inlines` to `#defines`.

Using :

```c++
const double AspectRatio = 1.652;
```

To replace :

```c++
#define ASPECTRATIO = 1.652
```

### 2.1   The backwards of  `#define` :

* the name(`ASPECTRATIO`)  may not be in the **symbol table**.

* the **macro** name `ASPECTRATIO` with 1.653  could result in multiple copies of `1.653`.

* bugs:

  * ```C++
    #define Call_MAX(a,b) f((a)>(b)?(a):(b))
    
    int a = 5, b = 0;
    Call_MAX(++a, b);   // it will cause incremented twice
    ```

  * replace it with `template<typename T> inline void CallMax(const T &a ,const T &b){ ...  }`



### 2.2   `Const`

Two special cases:

* constant point :  `char* const p = a;`
* Pointing to constant :  `const char * p;`

 The advantage:

* the limit scope

> When you see :
>
> ```c++
> class GP
> {
>   ...
>   private:
>     static const int NumTurn = 5;
> };
> ```
>
> It is a **declaration** , not a **definition**. So you should add the **definition** in the implement file:
>
> ```c++
> const int GP::NumTurn;
> ```
>
> Older compiler may require this rule:
>
> ```c++
> class GP
> {
>   ...
>   private:
>     static const int NumTurn ;     //It doesn't allow you to declare it with initial value
> };
> const int GP::NumTurn = 5;
> ```



### 2.3 `enum`

Sometimes the compiler insist on knowing the size of the array and forbid the in-class specification of initial values for static integral class constants. Fortunately,  you can use **the `enum` hack**:

```c++
class GP
{
    private:
    	enum {NumTurn = 5};   //Like the #define 
}
```

The advantages :

* a good way to enforce the constraint that forbidding people get a pointer or reference to specific integral constants.



## 3.0   Use `const` whenever possible

***Unless you need to be able to modify a parameter or local object, be sure to declare it const.***



Two different type but the same meaning:

```c++
const Wiget *pow;
wiget const *pow;
```



### 3.1   `Iterator `

```c++
const std::vector<int>::iterator iter;   //act like T* const
std::vector<int>::const_iterator iter2;   //ack like const T*
++iter2;
```

 

### 3.2   Having a function return a constant value

```c++
class Rational{...};
const Rational operator*(const ,const ){return };
```

Doing this can prevent assignment:
```c++
if(a*b = c)...;              //Oops! a Typo. 
```



### 3.3    Member Functions

The fact:  ***the member functions differing only in their `constness` can be overloaded.***

> 2.常成员函数的主要特点：
> 1）不能更新类的 hon-static 成员变量
> 2）不能调用该类中没有用 `const` 修饰的成员函数，即只能调用常成员函数
> 3）可以被类中其它的成员函数调用
> 4）常对象只能调用常成员函数，而不能调用其他的成员函数。

> **It is illegal to modify the return value of a function that return a build-in type.**



```c++
class TextBlock
{
    public:
    ...
    const char& operator[](std::size_t position) const
    {return text[Position];}
    
    private:
    std::string text;
};

TextBlock tb("Hello");
std::cout<<tb[0];

const TextBlock ctb("World");
std::cout << ctb[0];                   
ctb[0] = 'x';                   //error!!!
```

#### 3.3.1 Mutable

> `mutable`   frees non-static data members from the constraints of `bitwise constness`;
>
> mutable 可以突破`const`的限制，那么 类的常成员函数可以改变 `mutable` 修饰的变量。



### 3.4    Avoid Duplication in `const` and  `Non-const`  Member Functions

 When you want to keep both the versions of such function (`const version` and `non-const version` ), it will bring many problems such as attendant compolation time, maintenance, and code-bloat headaches.

> `const_cast<>()`

```c++
class TextBlock
{
    public:
    ...
    const char& operator[](std::size_t position) const
    {return text[Position];}
    
    char& operator[](std::size_t position)
    {
        return 
            const_cast<char& >(static_cast<const TextBlock&>(*this)[position]);  //先将 *this 从 TextBlock& 转换为 cosnt TextBlock& 调用const 版本的 operator[]
    }
    
    private:
    std::string text;
};
```













