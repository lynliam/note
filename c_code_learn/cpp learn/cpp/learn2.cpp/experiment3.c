#include<stdio.h>
#include<stdlib.h>

int main()
{
    int nums=0;
    int *p=0;
    scanf("%d",&nums);
    p=(int *)malloc(nums*sizeof(int));
    int key=1;
    while(key<=nums)
    {
        scanf("%d",p+key-1);
        getchar();
        key++;
    }




    if(nums==1)
    {
        printf("%d\n",nums);
        printf("%d",p[0]);
    }


    for(int j=1;j<nums;j++)
    {
        int i=j-1;
        int key=p[j];
        while(i>=0&&p[i]>key)
        {
            p[i+1]=p[i];
            i=i-1;
            p[i+1]=key;
        }
    }


    //s
    int slow=1,fast=1;
    int count=0;
    while (fast<nums)
    {
        if(p[fast]!=p[fast-1])
        {
            p[slow]=p[fast];
            slow++;
        }
        else
            count++;
        fast++;
    }
    printf("%d\n",nums-count);
    for(int i=0;i<nums-count;i++)
    {
        printf("%d",*(p+i));
    }
    return 0;
}
