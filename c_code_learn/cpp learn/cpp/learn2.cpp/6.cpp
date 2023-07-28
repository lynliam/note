#include<iostream>
#include<stdlib.h>

using namespace std;
class Complex1
{
    public:
    Complex1()=default;
    Complex1(double n,double u):r(n),i(u){}
    void display();
    Complex1 operator + (Complex1 &c1);
    private:
    double r;
    double i;
};

int main()
{
    Complex1 w(1.0,2.0),b(1.0,2.0);
    b=w+b;
    b.display();

    system("pause");

    return 0;
}




Complex1 Complex1::operator + (Complex1 &c1)
{
    Complex1 c;
    c.r=r+c1.r;
    c.i=i+c1.i;
    return c;
}

void Complex1::display()
{
    cout<<"("<<r<<","<<i<<")"<<endl;
}
