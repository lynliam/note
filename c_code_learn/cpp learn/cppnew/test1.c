#include<stdio.h>
#include<stdlib.h>
int main()
{
 int a[10],*p=a,p1;
 int i;

  for(p=a;p<(a+10);p++)
        scanf("%d",p);
        //p=a+9;
/*
 for(i=0;i<10;i++)
        scanf("%d",&a[i]);
*/
/*
//p=a+10;
//p--;
 p=a;
 for(i=0;i<5;i++){
  *p=a[i];  
  p1=*p;
  *(p+5)=a[i+5];
  *p=*(p+5);
  *(p+5)=p1;
 }

//第一个和第六个交换
 for(i=0;i<5;i++)
 {
  p1=a[i];
  a[i]=a[i+5];
  a[i+5]=p1;
 }

 //首尾交换
 for(i=0;i<5;i++)
 {
  p1=a[i];
  a[i]=a[9-i];
  a[9-i]=p1;
 }
*/
 //首尾交换（指针）
  for(p=a,p1=*(a+9);p<(a+5);p++,p1--)
  {
    p1=*p;
    *p=*(a+9);
    *(a+9)=p1;
  }

 for(i=0;i<10;i++)
        printf("%2d",*(a+i));
  system("pause");
 return 0;
}