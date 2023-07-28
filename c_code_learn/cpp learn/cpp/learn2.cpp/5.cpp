#include<iostream>
#include<stdlib.h>

class Complex
{
    public:
    Complex()=default;
    Complex(double n,double k):r(n),i(k){}
    //friend Complex operator + (Complex &a1,Complex &a2);
    void display();
    double getreal(){return r;}
    double getimages(){return i;}
    private:
    double r;
    double i;  
};



Complex operator + (Complex &a1,Complex &a2)
{
    return Complex(a1.getreal()+a2.getreal(),a1.getimages()+a2.getimages());
}



int main()
{
    Complex j1(2.0,6.3),j2(2.3,5.6);
    j1=j1+j2;
    j1.display();
    system("pause");
    return 0;

}
