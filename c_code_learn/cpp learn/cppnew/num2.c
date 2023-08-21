#include<stdio.h>
#include<stdlib.h>  
#include<string.h>

int main()
{
    char* str1;
    char* str2;
    char* str3;

    char* str;             //str作为中转存储使用
    int i=1;
    str1=(char*)malloc(sizeof(char)*(i+1));
    while('\n'!=(str1[i-1]=getchar()))
    {
              i++;
              str=(char*)malloc((strlen(str1)+1)*sizeof(char));
              str1[i-1]='\0';
              strcpy(str,str1);
              free(str1);
              str1=(char*)malloc(sizeof(char)*(i+1));
              if(NULL==str1)              //判断是否申请成功，失败需要释放内存
              {
                   free(str);
                   return NULL;
              }
              strcpy(str1,str);
              free(str);
    }
       str1[i-1]='\0';             //字符串结尾符

    i=1;
    str2=(char*)malloc(sizeof(char)*(i+1));
    while('\n'!=(str2[i-1]=getchar()))
    {
              i++;
              str=(char*)malloc((strlen(str2)+1)*sizeof(char));
              str2[i-1]='\0';
              strcpy(str,str2);
              free(str2);
              str2=(char*)malloc(sizeof(char)*(i+1));
              if(NULL==str2)              //判断是否申请成功，失败需要释放内存
              {
                   free(str);
                   return NULL;
              }
              strcpy(str2,str);
              free(str);
    }
       str2[i-1]='\0';             //字符串结尾符


    i=1;
    str3=(char*)malloc(sizeof(char)*(i+1));
    while('\n'!=(str3[i-1]=getchar()))
    {
              i++;
              str=(char*)malloc((strlen(str3)+1)*sizeof(char));
              str3[i-1]='\0';
              strcpy(str,str3);
              free(str3);
              str3=(char*)malloc(sizeof(char)*(i+1));
              if(NULL==str3)              //判断是否申请成功，失败需要释放内存
              {
                   free(str);
                   return NULL;
              }
              strcpy(str3,str);
              free(str);
    }
       str3[i-1]='\0';             //字符串结尾符




    if(strcmp(str1,str2))
    {
        if(strcmp(str1,str3))
            printf("str1 max\n");
        else
            printf("str3 max\n");
    }
    else
    {
        if(strcmp(str2,str3))
            printf("str2 max\n");
        else
            printf("str3 max\n");
    }
    system("pause");
    return 0;
}
