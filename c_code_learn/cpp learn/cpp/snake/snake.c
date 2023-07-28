#include<stdlib.h>
#include<conio.h>
#include<stdio.h>
#include<windows.h>
#include<time.h>
#include<string.h>

#define SNAKE_LONG 60
#define false 0
#define true 1


int g_arrsnake[SNAKE_LONG][3]={0};
enum {to_east=2,to_west =-2,to_north =-1,to_south=1}; 
int g_nSnakeDir = to_west;
int g_Food=true;
int g_R,g_C;
int g_SnakeLen=2;
int g_Score=0;

char c[20][48] = {
                                "■■■■■■■■■■■■■■■■■■■■■■■\n",
                                "■                                          ■\n",
                                "■                                          ■\n",
                                "■                                          ■\n",
                                "■                                          ■\n",
                                "■                                          ■\n",
                                "■                                          ■\n",
                                "■                                          ■\n",
                                "■                                          ■\n",
                                "■                                          ■\n",
                                "■                                          ■\n",
                                "■                                          ■\n",
                                "■                                          ■\n",
                                "■                                          ■\n",
                                "■                                          ■\n",
                                "■                                          ■\n",
                                "■                                          ■\n",
                                "■                                          ■\n",
                                "■                                          ■\n",
                                "■■■■■■■■■■■■■■■■■■■■■■■\n"
                                                            };

void FirstPage()
{
    printf("---------------按任意键开始---------------");
}

void TestSpace()
{
    char ch;
    while(ch=_getch())
    {
        if(ch==' ')
        system("cls");
        break;
    }
}

void ShowBack()
{
    for(int i=0;i<20;i++)
    {
        printf(c[i]);
    }
}

void DrawSnake()
{
    strncpy(&c[g_arrsnake[0][0]][g_arrsnake[0][1]],"□",2);
    for(int i=1;g_arrsnake[i][0]!=0;i++)
    {
        strncpy(&c[g_arrsnake[i][0]][g_arrsnake[i][1]],"■",2);
    }
}

void RmSnake()
{
    for(int i=0;g_arrsnake[i][0]!=0;i++)
    {
        strncpy(&c[g_arrsnake[i][0]][g_arrsnake[i][1]],"  ",2);
    }
}

void SetSnake()
{
    int nX=-1,nY=-1;
    srand((unsigned int)time(NULL));

    nX=rand()%19 +1;
    nY=rand()%18 +1;

    g_arrsnake[0][0]=nY;
    g_arrsnake[0][1]=nX*2;
    g_arrsnake[0][2]=to_west;

    g_arrsnake[1][0]=nY;
    g_arrsnake[1][1]=nX*2+2;
    g_arrsnake[1][2]=to_west;

    g_arrsnake[2][0]=nY;
    g_arrsnake[2][1]=nX*2+4;
    g_arrsnake[2][2]=to_west;

    DrawSnake();

}

void MoveSnake()
{
    RmSnake();

    for(int i=SNAKE_LONG-1;i>=1;i--)
    {
        if(g_arrsnake[i][1]==0)
            continue;
        g_arrsnake[i][0]=g_arrsnake[i-1][0];
        g_arrsnake[i][1]=g_arrsnake[i-1][1];
        g_arrsnake[i][2]=g_arrsnake[i-1][2];
    }

    //head
    g_arrsnake[0][2]=g_nSnakeDir;

    if(g_arrsnake[0][2]==to_west||g_arrsnake[0][2]==to_east)
    {
        g_arrsnake[0][1]+=g_arrsnake[0][2];
    }
    else{
        g_arrsnake[0][0]+=g_arrsnake[0][2];
    }
    for(int j=SNAKE_LONG-1;j>=1;j--)
    {
        if(g_arrsnake[j][1]==0) continue;

        if(g_arrsnake[0][0]==g_arrsnake[j][0]&&g_arrsnake[0][1]==g_arrsnake[j][1])
        {
            printf("You died !!!!\n");
            printf("Ending Scores: \n");
            system("pause");
        }
    }

}

//改变蛇的方位
void ChangeDir()
{
    if(GetAsyncKeyState('W'))
    {
        if(g_arrsnake[0][2]!=to_south){
            g_nSnakeDir=to_north;
        }
    }
    else if(GetAsyncKeyState('S'))
    {
        if(g_arrsnake[0][2]!=to_north){
            g_nSnakeDir=to_south;
        }
    }
    else if(GetAsyncKeyState('A'))
    {
        if(g_arrsnake[0][2]!=to_east){
            g_nSnakeDir=to_west;
        }
    }
    else if(GetAsyncKeyState('D'))
    {
        if(g_arrsnake[0][2]!=to_west){
            g_nSnakeDir=to_east;
        }
    }

}

//判断蛇是否死亡
int SnakeDie()
{
    if(!strncmp(&c[g_arrsnake[0][0]][g_arrsnake[0][1]],"■",2))
        return false;
}

//产生食物

void ProduceFood()
{
    if(g_Food==false)
        return ;
    int flag =true;
    srand((unsigned)time(NULL));
    while(1)
    {
        g_R=rand()%18+1;
        g_C=rand()%20+1;
        for(int i=0;g_arrsnake[i][1]!=0;i++)
        {
            if(g_arrsnake[i][0]==g_R&&g_arrsnake[i][1]==g_C)
            flag=false;
        }
        if(flag==true)
            break;
    }
    strncpy(&c[g_R][g_C*2],"●",2);
    g_Food=false;
}

void SnakeGrow() {
    //如果食物坐标和蛇头坐标相等
    if (g_arrsnake[0][0] == g_R && g_arrsnake[0][1] == g_C * 2) {
        if (g_arrsnake[0][2] == to_east) {  //判断尾结点在哪个方向上
            g_arrsnake[g_SnakeLen + 1][0] = g_arrsnake[g_SnakeLen][0];
            g_arrsnake[g_SnakeLen + 1][1] = g_arrsnake[g_SnakeLen][1] - 2;
            g_arrsnake[g_SnakeLen + 1][2] = g_arrsnake[g_SnakeLen][2];
        } else if (g_arrsnake[0][2] == to_west) {
            g_arrsnake[g_SnakeLen + 1][0] = g_arrsnake[g_SnakeLen][0];
            g_arrsnake[g_SnakeLen + 1][1] = g_arrsnake[g_SnakeLen][1] + 2;
            g_arrsnake[g_SnakeLen + 1][2] = g_arrsnake[g_SnakeLen][2];
        } else if (g_arrsnake[0][2] == to_north) {
            g_arrsnake[g_SnakeLen + 1][0] = g_arrsnake[g_SnakeLen][0] + 1;
            g_arrsnake[g_SnakeLen + 1][1] = g_arrsnake[g_SnakeLen][1];
            g_arrsnake[g_SnakeLen + 1][2] = g_arrsnake[g_SnakeLen][2];
        } else if (g_arrsnake[0][2] == to_south){
            g_arrsnake[g_SnakeLen + 1][0] = g_arrsnake[g_SnakeLen][0] - 1;
            g_arrsnake[g_SnakeLen + 1][1] = g_arrsnake[g_SnakeLen][1];
            g_arrsnake[g_SnakeLen + 1][2] = g_arrsnake[g_SnakeLen][2];
        }
        g_SnakeLen++;
        g_Food = true;
        g_Score++;

        }
}

void Score() {
    //COORD是Windows API中定义的一种结构，表示一个字符在控制台屏幕上的坐标。
    COORD rd;
    rd.X = 56;
    rd.Y = 8;
    //设置光标位置
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), rd);
    //打印
    printf("Score: ");

    rd.X = 64;
    rd.Y = 8;
    //设置光标位置
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), rd);
    //打印
    printf("%d", g_Score);

}

int main()
{
    FirstPage();
    TestSpace();
    SetSnake();
    while(1){
        system("cls");
        ChangeDir();
        SnakeGrow();
        ProduceFood();
        MoveSnake();
        if (SnakeDie() == false) {
            printf("Snake Die!\n");
            printf("Ending Scores: %d\n", g_Score);
            break;
        }
        DrawSnake();
        ShowBack();
        Score();
        Sleep(150);
    }
    
    system("pause");
    return 0;
}
