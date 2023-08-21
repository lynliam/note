#include<stdio.h>
#define N 10
void Transpose(int a[][N],int m,int n);
void swap(int i,int j,int n, int a[][N]);

int main()
{
    //int m=0;
    int m=0;
    int n=0;
    //scanf("%d,%d",&m,&n)
    scanf("%d",&m);
    getchar();
    scanf("%d",&n);
    getchar();
    int a[N][N]={0};
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
            getchar();
        }
    }

    Transpose(a,m,n);
    printf("\n");

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            printf("%d",a[i][j]);
            if(j==m-1)
                printf("\n");
            else
                printf(" ");
        }

    }


    return 0;
}

void Transpose(int a[][N] ,int m,int n)
{
    for(int i=0;i<m;i++)
    {
        for(int j=i;j<n;j++)
        {
            swap(i,j,n,a);
        }
    }
}
void swap(int i,int j,int n, int a[][N])
{
    //printf("%d - %d  ||  ",a[i*10+j],a[j*10+i]);
    int temp=a[i][j];
    a[i][j]=a[j][i];
    a[j][i]=temp;
    //printf("%d - %d  |",a[i*10+j],a[j*10+i]);
}
