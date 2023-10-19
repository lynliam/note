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

* Terminate the program（终止程序）

  ```c++
  DBCo：：~DBConn()
  {
      try{db.close();}
      catch(...)
      {
          ...;
          std::abort();
      }
  }
  ```

* Swallow the exception  (吞掉)

  ```c++
  DBCo：：~DBConn()
  {
      try{db.close();}
      catch(...)
      {
          ...;
      }
  }
  ```

* User's Handle Function:

  ```c++
  void close()
  {
      db.close();
      closed = true;
  }
  ```

### Summary

* Destructors should never emit exception. The destructors should **catch any exception** and then **swallow them or terminate the program**.
* The class should provide a regular function to have a way to handle the exception.



## 9.0   Never call virtual functions during construction or destruction.

### Solution:

Turn the function to be a non-virtual function.

### Summary 

* Never call virtual functions during construction or destruction. Because such call will never go to a more derived class than that of the currently executing constructor or destructor.  Informally speaking, during base construction, virtual functions aren't.

###  

## 10.0    Have assignment operators return a reference to `*this`



## 11.0    Handle assignment  to self  in `operator=`

Example:

```c++
class Wiget(){};
Wiget a;
a=a;                //An assignment to self

*py = *px   //potential assignment to self
```





### Summary

* Make sure `operator=` is well-behaved when an object is assigned to itself. Techniques include comparing address of source and target objects , careful statement ordering and copy-and-swap
* Make sure that any function operating on ore than one object behaves correctly if two or more of the objects are the same.









