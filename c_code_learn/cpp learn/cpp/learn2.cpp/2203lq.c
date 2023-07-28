#include<stdio.h>
#include<stdlib.h>

int main()
{
    int count=0;
    scanf("%d",&count);
    getchar();
    int *s=NULL;
    s=(int *)malloc(count*sizeof(int));
    for(int i=1;i<=count;i++)
    {
        int val;
        scanf("%d",&val);
        getchar();
        printf("\n------------------%d\n",val);
        int *p=NULL;
        p=(int*)malloc(val*sizeof(int));
        int j=0;
        while(j<val)
        {
            int b=0;
            scanf("%d",&b);
            getchar();
            *(p+j)=b;
            //printf("%d",*(p+j));
            ++j;
        }


        int key=0;
        for(int x=0;x<val;x++)
        {
            if(*(p+x)==1)
                {
                    continue;
                }
            if(*(p+x)==2)
                {
                    key++;
                    continue;
                }
            for(int y=2;y<*(p+x);y++)
            {
                if(*(p+x)%y==0)
                {
                    break;
                }
                if(y==*(p+x)-1&&*(p+x)%y!=0)
                {
                    key++;
                }
                
            }
        }
        *(s+i-1)=key;
        free(p);

    }

    for(int i=0;i<count;i++)
    {
        printf("%d\n",s[i]);
    }

    free(s);
    system("pause");
    return 0;
}