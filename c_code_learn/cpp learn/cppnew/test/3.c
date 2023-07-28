#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main()
{
    int x,i,j,t,m=0,n=0,b[10][10]={0};
    char a[100];
    gets(a);

    for (i=0;i<strlen(a);i++)
    {
        if (a[i]<=57&&a[i]>=48)
        {
            b[m][n]=a[i]-48;
            n++;
            if (a[i+1]>57||a[i+1]<48)
            {
                x=0;
                t=n;
                for(j=0;j<n;j++)
                {
                    x+=b[m][j]*(int)pow(10,t-1);
                    t--;
                }
                printf("%10d\n",x);
                n=0;
                m++;
            }
        }
    }
    system("pause");
    return 0;
}
