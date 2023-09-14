#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 9
#define COLOMN 9
#define ROWS ROW+2
#define COLOMNS COLOMN+2


void InsetRow(char row[ROWS][COLOMNS],int rows,int cols,char set);
void InsetCol(char column[ROWS][COLOMNS],int rows,int cols,char set);

void Display(char column[ROWS][COLOMNS],int rows,int cols);
void Display1(char row[ROWS][COLOMNS],int rows,int cols);


int Setmine(char row[ROWS][COLOMNS],int rows,int cols);

void note(int *x,int *y);
void show(char row[ROWS][COLOMNS],char column[ROWS][COLOMNS],int x,int y);

int GameSuccess(char colomn[ROWS][COLOMNS]);


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
            game();
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
    int x=0,y=0;
    int find=1;
    //初始化
    InsetRow(row,ROWS,COLOMNS,'0');
    InsetCol(column,ROWS,COLOMNS,'*');

    //设置雷
    Setmine(row,ROW,COLOMN);

    //打印
    
    //打印test
    //Display1(row,ROWS,COLOMNS);

    do{
    Display(column,ROWS,COLOMNS);
    note(&x,&y);
    if(row[x][y]=='1')
    {
        printf("\ngame over!");
        break;

    }
    else
    {
        show(row,column,x,y);
        printf("Continue:\n");
    }
    //判断游戏是否
    find=GameSuccess(column);
    }while(find!=1);


    return 0;
}



void InsetRow(char row[ROWS][COLOMNS],int rows,int cols,char set)
{
    for(int i=1;i<=rows;i++)
    {
        for(int j=1;j<=cols;j++)
        {
            row[i][j]=set;


        }
    }
}
void InsetCol(char column[ROWS][COLOMNS],int rows,int cols,char set)
{
    for(int i=1;i<=rows;i++)
    {
        for(int j=1;j<=cols;j++)
        {
            column[i][j]=set;
        }
    }
}

void Display(char column[ROWS][COLOMNS],int rows,int cols)
{
    char a=124;
    for(int ij=0;ij<=ROWS;ij++)
    {
        if(ij==0)
        printf(" %d",ij);
        else if(ij==10)
        printf("%d%c",ij,a);
        else if(ij==11)
        printf("%d%c",ij,a);
        else
        printf(" %d%c",ij,a);
    }
    printf("\n");
    for(int i=1;i<=rows;i++)
    {
        if(i<=9)
        printf(" %d",i);
        else
        printf("%d",i);
        for(int j=1;j<=cols;j++)
        {
            printf(" %c%c",column[i][j],a);
        }
        printf("\n");
    }


    return;
}

void Display1(char row[ROWS][COLOMNS],int rows,int cols)
{
    char a=124;
    for(int ij=0;ij<=ROWS;ij++)
    {
        printf(" %d",ij);
    }
    printf("\n");
    for(int i=1;i<=rows;i++)
    {
        if(i<=9)
        printf(" %d",i);
        else
        printf("%d",i);
        for(int j=1;j<=cols;j++)
        {
            printf(" %c%c",row[i][j],a);

        }
        printf("\n");
    }


    return;
}


int Setmine(char row[ROWS][COLOMNS],int rows,int cols)
{
    int x=0;
    int y=0;
    int count=1;

    for(;count<=ROW+1;count++)
    {
        x=rand()%9+1;
        y=rand()%9+1;
        if(row[x][y]=='0')
        {
            row[x][y]='1';

        }
    }

    return 0;
}

void note(int *x,int *y)
{

    int ret=0;
    printf("please enter your position:\n");
    ret=scanf("%d%*c%d",x,y);
    while(ret!=2)
    {
        printf("invalid value!");
        ret=scanf("%d%*c%d",x,y);
    }

    return;
}




int GameSuccess(char colomn[ROWS][COLOMNS])
{
    char value='0';
    for(int i=1;i<=ROW;i++)
    {
        for(int j=1;j<=COLOMN;j++)
        {
            if(colomn[i][j]=='*')
            value='*';

        }
    }
    if(value=='0')
    {
        printf("Success!");
        return 1;
    }
    else
    return 0;


}

void show(char row[ROWS][COLOMNS],char column[ROWS][COLOMNS],int x,int y)
{
    int count=0;
    char countc='0';
    for(int i=x-1;i<=(x+1);i++)
    {
        for(int j=y-1;j<=(y+1);j++)
        {
            if(row[i][j]=='1')
            ++count;
        }

    }
    switch (count)
    {
    case 1:
        countc='1';
        break;
    case 2:
        countc='2';
        break;
    case 3:
        countc='3';
        break;
    case 4:
        countc='4';
        break;
    case 5:
        countc='5';
        break;
    case 6:
        countc='6';
        break;
    case 7:
        countc='7';
        break;
    case 8:
        countc='8';
        break;
    default:
        break;
    }
    

    column[x][y]=countc;
    return;


}