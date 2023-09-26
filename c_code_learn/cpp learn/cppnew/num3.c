#include<stdio.h>
#include<stdlib.h>

void menu();
void matrix_init();
void Transpose();
void up_triangle_0();
void average();
void down_triangle_0();

int matrix[5][5];

int main()
{

    int key=10;
    menu();
    while(1)
    {
        scanf("%d",&key);
        switch (key)
        {
        case 1:
            matrix_init();
            break;
        case 2:
            Transpose();
            break;
        case 3:
            up_triangle_0();
            break;
        case 4:
            average();
            break;
        case 5:
            down_triangle_0();
            break;
        case 0:
            exit(0);
            break;
        default:
            break;
        }
        key=10;
    }

    system("pause");

}

void menu()
{
    printf("******************************菜单******************************\n");
    printf("请输入:\n");
    printf("1:调用矩阵赋值函数\n");
    printf("2:转置矩阵\n");
    printf("3:矩阵上三角元素全为0\n");
    printf("4:求矩阵对角线多有元素平均值\n");
    printf("5:下对角线变为0\n");
    printf("0:exit\n");
    printf("****************************************************************\n");
}

void matrix_init()
{
    printf("依次输入:\n");
    int value=0;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            int key_=scanf("%d",&value);
            while (key_!=1)
            {
                printf("invalid value!\n");
                key_=scanf("%d",&value);
            }
            matrix[i][j]=value;
        }
    }
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            printf("%d ",matrix[i][j]);
            if(j==4)
                printf("\n");
        }
    }
    printf("Done!\n");
}

void Transpose()
{
    for(int i=0;i++;i<5)
    {
        for(int j=i+1;j++;j<5)
        {
            int temp_val=0;
            temp_val=matrix[i][j];
            matrix[i][j]=matrix[j][i];
            matrix[j][i]=temp_val;
        }
    }
    printf("Done!\n");
}

void up_triangle_0()
{
    for(int i=0;i++;i<5)
    {
        for(int j=i;j++;j<5)
        {
            matrix[i][j]=0;
        }
    }
    printf("Done!\n");
}

void average()
{
    float sum = 0;
    for(int i=0;i<5;i++)
    {
        sum+=matrix[i][i];
    }
    printf("average: %f",sum/5.0);
    printf("Done!\n");
}

void down_triangle_0()
{
    for(int i=0;i++;i<5)
    {
        for(int j=i;j--;j>=0)
        {
            matrix[i][j]=0;
        }
    }
    printf("Done!\n");
}