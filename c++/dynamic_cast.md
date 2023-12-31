# C++ 中的动态强制dynamic_cast



## 简介

> ​	C++中提供了动态强制（dynamic_cast），是一种运行时类型识别机制，可以从一个虚的基类强制到一个派生类。我们常常需要知道，在运行过程中，我们真正在使用的是哪个类的对象，这时，可以明确地使用dynamic_cast来得到运行时类型的信息。
>
> ​	在dynamic_cast被设计之前，C++无法实现从一个虚基类到派生类的强制转换。dynamic_cast就是为解决**虚基类到派生类的转换**而设计的。

## 使用：

> **向上转换，无论是否使用 dynamic_cast C++ 总能够正确识别，即将派生类的指针赋值给基类指针**
>
> **如果向下转换则不行，必须使用 dynamic_cast， 该功能实现原理是 RTTI 机制**

```c++

//美术家
class Artist {
    public:
        virtual void draw() {printf("Artist draw\n");}
};
 
//音乐家
class Musician {
	public:
};
 
//教师
class Teacher {
    public:
        virtual void teachStu() {printf("Teacher teachStu\n");}
};
 
//即是美术，又是音乐家，又是教师的人
class People: public virtual Artist,public virtual Musician,public Teacher {
	public:
```

```c++
void test1() {
 
	People *p1 = new People();
	
	printf("\ndynamic_cast test:\n");
 
	Artist *a1 = p1; //success
	//People *p2 = (People*)a1; //error: cannot cast 'Artist *' to 'People *' via virtual base 'Artist'
	People *p3 = dynamic_cast<People*>(a1);//success：加了dynamic_cast，进行强转
}
```

## RTTI 机制

> 运行阶段类型识别，C++ 新特性，旨在为程序在运行阶段确定对象的类型提供一种标准方式。
>
> RTTI 用途
> 考虑一种情况：假如现在有一个基类 Base，并且基类中包含有虚函数 Fun1，然后派生类 A 继承于基类 Base，并实现基类的虚函数Fun1，同时，派生类 A 又定义一个虚函数 Fun2，接着，派生类 B 继承于 A，并且实现了基类中的两个虚函数 Fun1和 Fun2，那么，当我们选择一个类 A 或 B，创建一个对象，并将指针赋值给基类指针，这时候，当我们要用改指针的时候就不知道该指针真正指向哪个对象。
> 那么问题来了，可能你会问，干嘛要知道该指针类型呢？**如果说通过该指针去调用基类本身就有的虚函数，则可以正常调用，不需要知道对象的类型，但是当调用派生类中新定义的函数，这时候就会出错啦**。这种情况下，只有某些类型的对象可以使用该方法。所以就需要进行判断对象类型，或者进行相应的强制合理转换对象类型。
>
> RTTI解决方案：
>
> * dynamic_cast :  将一个指向基类的指针来生成一个指向派生类的指针，如果转换不合理，返回空指针。
> * typeid： 返回一个指出对象的类型的值

## dynamic_cast  机制：

1）查找规则：当使用 dynamic_cast 对指针进行类型转换时，会先找到该指针指向的对象，再根据对象找到当前类（指针指向的对象所属的类）的类型信息，并从此节点开始沿着继承链向上遍历（注意是向上），如果找到了要转化的目标类型，那么说明这种转换是安全的，就能够转换成功，如果没有找到要转换的目标类型，那么说明这种转换存在较大的风险，就不能转换。

2）作用对象：注意dynamic_cast转换符只能用于含有虚函数的类。

