# Constructors,Destructors, and Assignment Operator

## 5.0   Know what functions C++ silently writes and calls

* `Empty(){}`
* `Empty(cosnt Empty&rhs){}`
* `~Empty(){}`
* `Empty& operator = (const Empty& rhs){}`



## 6.0   Explicitly disallow the use of compiler-generated functions you do not want

To prevent these functions from being generated, you must declare them yourself, but there is nothing that requires that you declare the copy constructor and the copy assignment operator private.

```c++
class HomeForSale{
    public:
    private:
    HomeForSale(const HomeForSale&);
    HomeForSale& operator=(const HomeForSale&);
}
```

or

```c++
class Uncopyable{
    protected:
    Uncopyable(){}
    ~Uncopyable(){}
    
    private:
    Uncopyable(const Uncopyable&);
    Uncopyable& operator=(const Uncopyable&);
}

class HomeForSale:private Uncopyable{}

```



## 7.0    Declare destructors virtual in polymorphic base classes.

```c++
class TimeKeeper
{
    public:
    TimeKeeper();
	virtual ~ TimeKeeper();
}
TimeKeeper *ptk = getTimee();


delete ptk;
```

Then this form of a pointer called a **vptr** (virtual table pointer). It will increase the size of the Pointer.

So it  is a bad behavior to inherit a non-virtual destructor(`std::string`).

### 7.1   Abstract classes

If there is no any pure virtual functionis and functions, do this :

```c++
calss AW{
    public:
    virtual ~AW() = 0;
}

AW::~AW(){}                               //You must put the defination of pure virtual destructor
```





### Summary

* Polymorphic base classes should declare virtual destructors. If a class has any virtual functions, it should have a virtual destructor.
* Classes not designed to be base classes or not designed to be used polymorphically should not declare virtual destructors.



## 8.0  Prevent exceptions from leaving destructors

During destruction of the object, if an exception is throw, it will be a disaster and yields undefined behavior. Although it throws an error ,it also should be destroy, so it will also invoke their destructor  and  get a second exception.

### Solution:

* Terminate the program

  ```c++
  ```

* Swallow the exception

  ```c++
  ```

  

###  









