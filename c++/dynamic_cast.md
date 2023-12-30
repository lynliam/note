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

> 

