#include<iostream>
#include<string>
#include<stdlib.h>
using std::string;
using std::cout;
using std::cin;
using std::endl;
int find_char(const string &a1,const char b1,int &c1);
int main()
{
    string d1(4,'d'),d2(4,'d');
    char e1;
    int f1=0;
    cout<<"Please enter two sentence:"<<endl;
    getline(cin,d1);
    cout<<"continue..."<<endl;
    cin>>e1;
    int pos1=find_char(d1,e1,f1);
    cout<<f1<<"  "<<pos1<<endl;
    system("pause");
    return 0;


}

int find_char(const string &a1,const char b1,int &c1)
{
    int pos=0;
    for(auto g1=a1.begin(),g2=a1.end();g1!=g2;++g1){
        if(*g1==b1){
            ++c1;
            if(g1!=a1.begin())
            pos=c1;
        }
        
        
    }
    return pos;
}