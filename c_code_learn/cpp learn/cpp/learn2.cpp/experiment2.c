#include<stdio.h>
#include<stdlib.h>
int Pell(int n);
int main()
{
    int n=0;
    scanf("%d",&n);
    getchar();
    int *p=(int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
    {
        scanf("%d",p+i);
        getchar();
    }

    for(int i=0;i<n;i++)
    {
        *(p+i)=Pell(*(p+i));
        printf("%d\n",*(p+i));
    }
    system("pause");
    return 0;
}

int Pell(int n)
{
    if(n==1)
        return 1;
    if(n==2)
        return 2;
    
    
    return 2*Pell(n-1)+Pell(n-2) ;
}

/*
// code here
#include<stdio.h>
#include<stdlib.h>
int chday(int y,int m);

int main()
{
    
    int y=2006,m=5;
    
    scanf("%d%*c%d",&y,&m);
    int month[5][7]={0};
    const int monthlist[12]={31,28,31,30,31,30,31,31,30,31,30,31}; 

    int a=chday(y,m);
    //printf("%d",a);
    int temp=1;
    int monthday=monthlist[m-1];
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<7;j++)
        {
            if(i==0&&j<a)
                month[i][j]=0;
            else if(temp<=monthday)
            {
                month[i][j]=temp;
                temp++;
            }
                
            
        }
    }
    printf("Sun\tMon\tTue\tWed\tThu\tFri\tSat\n");
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<7;j++)
        {
            if(month[i][j]==0)
                printf("\t");
            else
                
                printf("%d\t",month[i][j]);
        }
        if(i<4)
        printf("\n");
    }
    return 0;
}


int chday(int y,int m)
{
    int r=0;
    int flag=0;
    const int monthlist[12]={31,28,31,30,31,30,31,31,30,31,30,31}; 
    for(int i=1900;i<y;i++)
    {
        if((i%4==0&&i%100!=0)||i%400==0)
        {
            r++;
        }
    }

    
    if((y%4==0&&y%100!=0)||y%400==0)
        {
            flag=1;
        }
    

    int today=0;
    for(int j=1;j<m;j++)
    {
        today+=monthlist[j-1];
    }
    if(flag==1&&m>2)
        today++;

    
    int day=(365*(y-1900-r)+366*r+today+1)%7;
    
    return day;
}
*/