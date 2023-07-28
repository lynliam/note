#include<stdio.h>
#include<string.h>
#include<math.h>

int main()
{
    int c[52]={0};
    int d[52]={0};
    int e[52]={0};
    int n;
    int m;
    int t,i,z=0,r=0;
    char a[52]={0},b[52]={0};
    do
    {
       fgets(a,52*sizeof(int),stdin);
       n=strlen(a)-1;
       fgets(b,52*sizeof(int),stdin);
       m=strlen(b)-1;
       t=fabs(m-n);
    }while (n<20||m<20);
    if (n>=m)
    {
        for (i=1;i<=n;i++)
        {
            c[i]=a[z]-48;
            z++;
        }
        for (i=0;i<=m;i++)
        {
            d[t+1]=b[i]-48;
            t++;
        }
        for (i=1;i<=n;i++)
        {
            e[i]=c[i]+d[i];
            if (e[i]>=10)
            {
                e[i-1]+=1;
                e[i]=e[i]%10;
            }
        }
        if (e[0]==0)
        {
            for (i=1;i<=n;i++)
            {
                printf("%d",e[i]);
            }
            printf("\n");
        }
        if (e[0]!=0)
        {
            for (i=0;i<=n;i++)
            {
                printf("%d",e[i]);
            }
            printf("\n");
        }
    }
    if (m>n)
    {
        for (i=0;i<=n;i++)
        {
            c[t+1]=a[i]-48;
            t++;
        }
        for (i=1;i<=m;i++)
        {
            d[i]=b[r]-48;
            r++;
        }
        for (i=1;i<=m;i++)
        {
            e[i]=c[i]+d[i];
            if (e[i]>=10)
            {
                e[i-1]+=1;
                e[i]=e[i]%10;
            }
        }
        if (e[0]==0)
        {
            for (i=1;i<=m;i++)
            {
                printf("%d",e[i]);
            }
            printf("\n");
        }
        if (e[0]!=0)
        {
            for (i=0;i<=m;i++)
            {
                printf("%d",e[i]);
            }
            printf("\n");
        }
    }
    return 0;
}
