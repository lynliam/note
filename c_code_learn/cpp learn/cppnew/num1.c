#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{

    int count=0;   //单词数目
    int count_invalue=0;


    char* str1;
    char* str2;             //str2作为中转存储使用
    int i=1;
    str1=(char*)malloc(sizeof(char)*(i+1));
    while('\n'!=(str1[i-1]=getchar()))
    {
              i++;
              str2=(char*)malloc((strlen(str1)+1)*sizeof(char));
              str1[i-1]='\0';
              strcpy(str2,str1);
              free(str1);
              str1=(char*)malloc(sizeof(char)*(i+1));
              if(NULL==str1)              //判断是否申请成功，失败需要释放内存
              {
                   free(str2);
                   return NULL;
              }
              strcpy(str1,str2);
              free(str2);
    }
       str1[i-1]='\0';             //字符串结尾符
       printf("%s",str1);

    for(int j=0;j<=strlen(str1);j++)
    {
        
        if(str1[j]==' '&& count_invalue!=0)
        {
            count++;
            count_invalue=0;
        }
        else{
            if(str1[j]!=' ')
                count_invalue++;
        }
    }
    printf("count:%d",count+1);
   //system("pause");
}