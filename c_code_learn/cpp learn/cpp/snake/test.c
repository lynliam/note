#define SNAKE_LONG 60
#define bool int
#define false 0
#define true 1

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>   //_getch所在头文件
#include <time.h>

char g_strGameBack[20][100] = {
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
//方向
enum {to_east = 2, to_west = -2, to_north = -1, to_south = 1};
//蛇数组
int g_arrsnake[SNAKE_LONG][3] = {0};  //[i][0]表示行的坐标，[i][1]表示列的坐标，[i][2]表示移动的方向
//蛇的方向
int g_nSnakeDir = to_west;
//
bool g_ProFood = true;
//产生随机坐标
int g_Row, g_Col;
//蛇长度
int g_SnakeLen = 2; 
//分数
int g_Score = 0;

void FirstPage() {
    printf("\n\n\n\n\t\t\t   <<按下空格开始游戏>>\n");
}
void TestSpace() {
    char ch;
    //当输入为空格，就进入游戏
    while (ch = _getch()) {   //_getch的作用是读入一个字符，不用按回车
        if (ch == ' ') break;
	}
}
void ShowBackground() {
    for (int i = 0; i < 20; i++) {
        printf(g_strGameBack[i]);    //打印g_strGameBack数组20次
    }
}
//画蛇，根据设置好的数组将蛇画到背景中
void DrawSnake() {
    strncpy(&g_strGameBack[g_arrsnake[0][0]][g_arrsnake[0][1]], "□", 2);
    for (int i = 1; g_arrsnake[i][0] != 0; i++) {   //连续循环3次，把方块拷贝到空白地图上面
        strncpy(&g_strGameBack[g_arrsnake[i][0]][g_arrsnake[i][1]], "■", 2);
    }
}
//删除蛇残留
void DestroySnake() {
    for (int i = 0; g_arrsnake[i][0] != 0; i++) {   //连续循环3次，把方块拷贝到空白地图上面
        strncpy(&g_strGameBack[g_arrsnake[i][0]][g_arrsnake[i][1]], "  ", 2);
    }
}
//设置蛇的开始位置
void SetSnakeRandPos() {
    int nX = -1, nY = -1;
    srand((unsigned int)time(NULL));   //设置随机数种子
    nX = rand() % 19 + 1;    //因为初始长度是3，最后一列22是墙，所以第一个蛇方块上限是19
    nY = rand() % 18 + 1;    //因为最后一行19是墙，所以上限是18
    // printf("%d %d\n", nX, nY);
    g_arrsnake[0][0] = nY;   //行
    g_arrsnake[0][1] = nX * 2;
    g_arrsnake[0][2] = to_west;

    g_arrsnake[1][0] = nY;   //行
    g_arrsnake[1][1] = nX * 2 + 2;
    g_arrsnake[1][2] = to_west;

    g_arrsnake[2][0] = nY;   //行
    g_arrsnake[2][1] = nX * 2 + 4;
    g_arrsnake[2][2] = to_west;
    DrawSnake();
}
//蛇动起来
void SnakeMove() {
    //先从背景删掉原来的蛇
    DestroySnake();

    int i = SNAKE_LONG - 1;  //数组下标0到19
    for (i; i >= 1; i--) {
        //过滤掉非法蛇身
        if (g_arrsnake[i][1] == 0) continue;
        //把前一个结点的值，赋给当前结点
        g_arrsnake[i][0] = g_arrsnake[i - 1][0];
        g_arrsnake[i][1] = g_arrsnake[i - 1][1];
        g_arrsnake[i][2] = g_arrsnake[i - 1][2];
    }
    //处理蛇头
    g_arrsnake[0][2] = g_nSnakeDir;  //初始化方向为向西
    //如果是东西方向
    if (g_arrsnake[0][2] == to_west || g_arrsnake[0][2] == to_east) {
        g_arrsnake[0][1] += g_arrsnake[0][2];
    } else {  //如果是东西方向
        g_arrsnake[0][0] += g_arrsnake[0][2];
    }
    for (int j = SNAKE_LONG - 1; j >= 1; j--) {
        if (g_arrsnake[j][1] == 0) continue;
        //g_arrsnake[0][0]和g_arrsnake[0][1]为蛇头坐标
        //判断蛇头改变方向以后会不会咬到自己
        if (g_arrsnake[0][0] == g_arrsnake[j][0] && g_arrsnake[0][1] == g_arrsnake[j][1]) {
                printf("Snake Die!\n");
                printf("Ending Scores: %d\n", g_Score);
                system("pause");
            }
        }
}
//蛇随方向动起来
void ChangeDir() {
    //不可以用_getch(),该函数会等待用户输入，如果不输入则蛇不移动（同步检测）
    //GetAsyncKeystate()异步检测函数
    //GetAsyncKeyState('W'); //如果输入W，就返回一个非0值
    if (GetAsyncKeyState('W')) {
        if (g_arrsnake[0][2] != to_south) {  //不能向相反的方向走
            g_nSnakeDir = to_north;
        }
    } else if (GetAsyncKeyState('S')) {
        if (g_arrsnake[0][2] != to_north) {
            g_nSnakeDir = to_south;
        }
    } else if (GetAsyncKeyState('A')) {
        if (g_arrsnake[0][2] != to_east) {
            g_nSnakeDir = to_west;
        }
    } else if (GetAsyncKeyState('D')) {
        if (g_arrsnake[0][2] != to_west) {
            g_nSnakeDir = to_east;
        }
        
    }
}
//判断蛇是否死亡
bool SnakeDie() {
    //如果蛇头的下一个位置是方块，就返回0
    //if (g_arrsnake[0][2] == to_west || g_arrsnake[0][2] == to_east) {
        // if (!strncmp(&g_strGameBack[g_arrsnake[0][0]][g_arrsnake[0][1] + g_arrsnake[0][2]], "■", 2))
        //if (!strncmp(&g_strGameBack[g_arrsnake[0][0]][g_arrsnake[0][1]], "■", 2))
            //return false;
    //} else if (g_arrsnake[0][2] == to_north || g_arrsnake[0][2] == to_south)
        // if (!strncmp(&g_strGameBack[g_arrsnake[0][0] + g_arrsnake[0][2]][g_arrsnake[0][1]], "■", 2))
        if (!strncmp(&g_strGameBack[g_arrsnake[0][0]][g_arrsnake[0][1]], "■", 2)) {
            return false;
    }
    return true;
}
//随机产生新的食物
void ProduceFood() {
    //判断是否有必要产生新的食物
    if (g_ProFood == false)
        return;
    bool flag = true;
    srand((unsigned int)time(NULL));
    while (1) {
        g_Row = rand() % 18 + 1;
        g_Col = rand() % 20 + 1;
        //遍历蛇身，如果随机坐标产生在蛇身，就重新生成随即坐标
        for (int i = 0; g_arrsnake[i][0] != 0; i++)
            if (g_arrsnake[i][0] == g_Row && g_arrsnake[i][1] == g_Col)
                flag = false;
        if (flag == true)
            break;
    }
    //坐标画食物
    strncpy(&g_strGameBack[g_Row][g_Col * 2], "●", 2);
    g_ProFood = false;
}
//蛇变长
void SnakeGrow() {
    //如果食物坐标和蛇头坐标相等
    if (g_arrsnake[0][0] == g_Row && g_arrsnake[0][1] == g_Col * 2) {
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
        g_ProFood = true;
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
    //首页
    FirstPage();
    //按下空格
    TestSpace();
    // 清空屏幕
    system("cls");
    //设置蛇的位置
    SetSnakeRandPos();
    //打印游戏界面
    while (1) {
        system("cls");
        //改变方向
        ChangeDir();
        //蛇变长
        SnakeGrow();
        //产生食物
        ProduceFood();
        //蛇移动
        SnakeMove();
        //判断蛇是否死亡
        if (SnakeDie() == false) {
            printf("Snake Die!\n");
            printf("Ending Scores: %d\n", g_Score);
            break;
        }
        //在背景上显示蛇
        DrawSnake();
        //打印背景
        ShowBackground();
        //打印分数
        Score();
        Sleep(150);     //每150毫秒刷新刷新打印一次，在windows.h头文件中
    }
    system("pause");
    return 0;
}


