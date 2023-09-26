/*#include<stdio.h>

int main()
{
    int a1=0,a2=0,b1=0,b2=0;
    scanf("%d/%d,%d/%d",&a1,&a2,&b1,&b2);
    if(a1*b2>a2*b1)
    {
        printf("%d/%d > %d/%d",a1,a2,b1,b2);
    }
    else if(a1*b2<a2*b1)
    {
        printf("%d/%d < %d/%d",a1,a2,b1,b2);
    }
    else
    {
        printf("%d/%d = %d/%d",a1,a2,b1,b2);
    }
    return 0;
}
*/
/*
#include<stdio.h>
#include<stdlib.h>
int LCM(int ,int );
int main ()
{
    int a=0,b=0;
    scanf("%d,%d",&a,&b);
    int u=LCM(a,b);
    printf("%d",u);
        system("pause");
    return 0;
}

int LCM(int n1,int n2)
{
    for(int i=1;i<68750;i++)
    {
        if(i%n1==0 && i%n2==0)
        return i;
    }

    return 0;
}*/
#include<stdio.h>
#define N 10
void transpose(int *a,int n);
void swap(int i,int j,int n, int *a);
int main()
{
    //int m=0;
    int n=0;
    //scanf("%d,%d",&m,&n)
    scanf("%d",&n);
    getchar();
    int a[N][N]={0};
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
            getchar();
        }
    }

    Transpose(*a,n);
printf("\n");
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {

            printf("%d ",a[i][j]);
            if(j==N-1)
                printf("\n");
        }
    }


    return 0;
}


/*

void transpose(int a[][N],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            swap(i,j,a[][N]);
        }
    }
}
*/


void Transpose(int *a ,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            swap(i,j,n,a);
        }
    }

}
void swap(int i,int j,int n, int *a)
{
   //printf("%d - %d  ||  ",a[i*10+j],a[j*10+i]);
    int temp=a[i*10+j];
    a[i*10+j]=a[j*10+i];
    a[j*10+i]=temp;
    //printf("%d - %d  |",a[i*10+j],a[j*10+i]);
}



/*


void Transpose(int (*a)[N],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            swap(i,j,a);
        }
    }
}

*/
/*
void swap(int x,int y,int *a)
{
    int temp=a[x][y];
    a[x][y]=a[y][x];
    a[y][x]=temp;
}
*/
