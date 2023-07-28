#include<stdio.h>
#include<stdlib.h>

int main()
{
    int a;
    int students[a];

}

void arrysorth(int score[],int n)
{
    for(int i=0;i<n;i++)
    {
        int k=i;
        int t=0;
        for(int j=i+1;j<=n;j++)
        {
            if(score[j]>=score[k])
            k=j;
        }
        int temp=score[j];
        score[i]=score[j];
        score[j]=temp;
    }
    return;

}

void arrysortl(int score[],int n)
{
    for(int i=0;i<n;i++)
    {
        int k=i;
        int t=0;
        for(int j=i+1;j<=n;j++)
        {
            if(score[j]<=score[k])
            k=j;
        }
        int temp=score[j];
        score[i]=score[j];
        score[j]=temp;
    }
    return;

}

int readstu(int score[],long num[])
{
    int i=-1;
    do{
        i++;
        int ret=0;
        printf("ID :");
        ret=scanf("%ld%d",&num[i],&score[i]);
        int *ret1=&ret;
        while(ret!=2)
        {
            printf("wrong!\n");
            *ret1=scanf("%ld%d",&num[i],&score[i])
        }

    }while(num[i]>0&&score[i]>=0);
    return i;
}