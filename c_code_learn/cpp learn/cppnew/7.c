#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
    int carry=0;
    char num1[52];
    char num2[52];
    char big[52];
    char small[52];
    int nuss[100]={0};
    scanf("%s",num1);
    scanf("%s",num2);
    int count1=strlen(num1);
    int count2=strlen(num2);
    int minus=abs(count1-count2);
    small[52]="0";
    big[52]="0";
    if(count1>count2)
    {
        strcat(big,num1);
        strcat(small,num2);
    }
    else if(count2>count1)
    {
        strcat(big,num2);
        strcat(small,num1);
    }
    else
    {
        strcat(big,num1);
        strcat(small,num2);
    }
    count1=strlen(big);
    count2=strlen(small);
    for(int j=count1-1;j>=0;j--)
    {
        if(j>=minus)
        {
            nuss[j]=big[j]-'0'+small[j-minus]-'0'+carry;
            carry=0;
        }
        else
        {
            nuss[j]=big[j]-'0'+carry;
            carry=0;
        }
        if(nuss[j]>=10)
        {
            carry=1;
            nuss[j]=nuss[j]%10;
        }
    }
    for(int i=0;i<count1;i++)
    {
        if(i==0&&nuss[0]==0)
        continue;
        printf("%d",nuss[i]);
    }

    return 0;
}