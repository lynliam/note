

#include<stdio.h>
/*
int hour,minute,second;

void Update()
{
    second++;
    if(second==60)
    {
        second=0;
        minute++;
    }
    if(minute==60)
    {
        minute=0;
        hour++;
    }
    if(hour==24)
    hour=0;
}

void Display()
{
    printf("%d,%d,%d",hour,minute,second);
}

void Delay()
{
    int t ;
    for(t=0;t<100000000;t++);
}
int main(void)
{
    int i;
    for(i=0;i<1000000;i++)
    {
    Update();
    Display();
    Delay();
    }
    return 0;
}
*/
/*
//7.4
#include<stdio.h>
int LCM(int ,int );
int main ()
{
    int a=0,b=0;
    scanf("%d,%d",&a,&b);
    int u=LCM(a,b);
    printf("%d",u);
    return 0;
}

int LCM(int n1,int n2)
{
    for(int i=1;i<68750;i++)
    {
        if(i%n1==0 && i%n2==0)
        return i;
        else
        printf("invalid nums");
    }
    return 0;
}
*/

int GCD(int ,int);

int main()
{
    int a=0,b=0;
    scanf("%d,%d",&a,&b);
    GCD(a,b);
    return 0;
}

int GCD(int a,int b)
{
    int n=a>b?b:a;
    for(int i=n;i>0;i--)
    {
        if(a%i==0&&b%i==0)
        {
            printf("%d",i);
        }
    }
    return 0;
}