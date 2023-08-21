#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char word[10];
    scanf("%s",word);
    int f=strlen(word);
    float a=atof(word);
    printf("%f\n%d",a,f);
    system("pause");
    return 0;
}