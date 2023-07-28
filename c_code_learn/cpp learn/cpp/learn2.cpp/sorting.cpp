#include<iostream>

bool Ef(int a[],int n1,int n2,int m);

int main()
{
    int a[6]={1,3,6,7,8,11};
    bool b=Ef(a,1,6,4);
    std::cout<<b<<std::endl;
    return 0;
}

bool Ef(int a[],int n1,int n2,int m)
{
    int q=n2/2+1;
    if(n2-n1==1)
    {
        for(int i=n1-1;i<n2;i++)
    {
        if(a[i]==m)
            return true;
        if(i==n2-1&&a[i]!=m)
            return false;
    }
    }
    else if(a[q-1]==m)
        return true;
    else if(a[q-1]>m)
        return Ef(a,1,q,m);
    else if(a[q-1]<m)
        return Ef(a,q+1,n2,m);
    return false;
}


