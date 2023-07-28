#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#include"game.h"

int game(void);

void menu()
{
    printf("--------------------------------\n");
    printf("------------1.play--------------\n");
    printf("--------------------------------\n");
    printf("------------0.exit--------------\n");
    printf("--------------------------------\n");
    printf("--------------------------------\n");
    printf("\n");
    printf("please enter your option :");
    return;

}



int main()
{
    int key=0;
    srand((unsigned)time(NULL));

    do{
        menu();
        int ret=0,*rets=&ret;
        ret=scanf("%d",&key);
        while(ret!=1)
        {
            fflush(stdin);
            printf("Please reset :");
            *rets=scanf(" %d",&key);
        }
        printf("\n");


        switch (key)
        {
        case 1:
            //int fin=game();
            break;
        case 0:
            printf("exit\n");
            break;
        default:
            printf("invalid value\n");

            break;
        }



    }while(key);
}

int game(void)
{
    char row[ROWS][COLOMNS]={0};
    char column[ROWS][COLOMNS]={0};
    //初始化
    InsetRow(row,ROWS,COLOMNS,'0');
    InsetCol(column,ROWS,COLOMNS,'*');
    //打印
    Display(column,ROWS,COLOMNS);




    return 1;

}