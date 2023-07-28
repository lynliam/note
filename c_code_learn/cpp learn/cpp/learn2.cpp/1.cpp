#include<iostream>
#include<string>
#include<initializer_list>
#include<stdlib.h>
using std::cout;
using std::endl;
using std::cin;
using std::string;


void err_s(std::initializer_list<string> a)
{
    for(auto beg=a.begin();beg!=a.end();++beg){
        cout<<*beg<<" ";

    }
    cout<<endl;


}

int main()
{
    string ba(10,'d');

    cout<<"Please enter sentence:"<<endl;;
    getline(cin ,ba);
    cout<<ba<<endl;
    err_s({ba});
    system("pause");

    return 0;


}