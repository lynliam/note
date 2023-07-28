#include<stdio.h>

int main()
{
    int n=0,y=0,r=0;
    printf("请输入日期（年，月，日）");
    scanf("%d,%d,%d",&n,&y,&r);
    int flag=0;
    if(((y%4==0)&&(y%100!=0))||(y%400==0))
        flag=1;
    int sum=0;
    int nums[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    if(y==1)
    {
        printf("\n%d月%d日是%d年的第%d天。",y,r,n,r);
    }
    else
    {
            for(int i=1;i<=y-1;i++)
        {
            sum+=nums[i-1];
        }
        sum+=y;
        if(flag==1&&y>2)
        sum+=1;
    }
    printf("\n%d月%d日是%d年的第%d天。",y,r,n,sum);

    return 0;
}