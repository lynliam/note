#include<stdio.h>
#include<stdlib.h>
int main()
{
    char num1[50];
    char num2[50];
    scanf("%s",num1);
    scanf("%s",num2);
    int count1=0;
    int count2=0;
    int carry=0;
    for (int i = 0; num1[i]!='\0'; i++)
    {
        count1++;
    }
    for (int i = 0; num2[i]!='\0'; i++)
    {
        count2++;
    }



    //printf("%d,%d",count1,count2);
    //system("pause");

    int nuss[100]={0};
    int flag=0;
    if(count1>count2)
    {
        for(int j=count1-1;j>=0;j--)
        {
            if(j>=count1-count2)
            {
                nuss[j+1]=num1[j+1]-'0'+num2[j+1-(count1-count2)]-'0'+carry;
                carry=0;
            }
            else
            {
                nuss[j+1]=num1[j+1]-'0'+carry;
                carry=0;
            }


            if(nuss[j+1]>=10)
            {
                carry=1;
                nuss[j+1]=nuss[j+1]%10;
            }

            if(j+1==1&&carry==1)
            {
                flag=1;
                nuss[1]=nuss[1]%10;
                nuss[0]=1;
            }
        }
/*
        for(int i=0;i<count1-count2;i++)
        {
            nuss[i]=num1[i]-'0';
        }
*/
        if(flag==1)
        {
            for(int i=0;i<=count1;i++)
            {
                printf("%d",nuss[i]);
            }
        }
        else
        {
            for(int i=1;i<=count1;i++)
            {
                printf("%d",nuss[i]);
            }
        }
    }

    else
    {
        for(int j=count2-1;j>=count2-count1;j--)
        {
            nuss[j]=num2[j]-'0'+num1[j-(count2-count1)]-'0'+carry;
            carry=0;
            if(nuss[j]>=10)
            {
                carry=1;
                nuss[j]=nuss[j]%10;
            }
        }

        for(int i=0;i<count2-count1;i++)
        {
            nuss[i]=num2[i]-'0';
        }

    if ((carry==1))
        {
        for(int i=0;i<count2;i++)
        {
            if(i==0)
            printf("1");
            printf("%d",nuss[i]);
        }
        }
    else
        {
        for(int i=0;i<count2;i++)
        {
            printf("%d",nuss[i]);
        }
        }

    }
    //system("pause");
    return 0;
}

