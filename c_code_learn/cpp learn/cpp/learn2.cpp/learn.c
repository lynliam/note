#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *p=NULL;
    p=(int*)malloc(sizeof(int)*5);
        int j=0;
        while(j<5)
        {
            int b=0;
            scanf("%d",&b);
            getchar();
            *(p+j)=b;
            printf("%d",*(p+j));
            ++j;
            
        }

    system("pause");
    
    
    return 0;
}