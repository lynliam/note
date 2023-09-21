#include <graphics.h>					//包含EGE的头文件
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#define SNAKE_N 500


struct Snake
{
	int size;
	int dir;
	int speed;
	POINT coor[SNAKE_N];


}snake;


class Food
{
	public:
	int x;
	int y;
	int r;
	bool flag;
	DWORD color;
}food;



void GameInit()
{
	snake.size=3;
	snake.dir;
	snake.speed=10;
	for(int i=0;i<snake.size;i++)
	{
	snake.coor[i].x=10*i+10;
	snake.coor[i].y=10*i+10;
	}

}

void GameDraw()
{
	initgraph(640, 480,INIT_RENDERMANUAL);		//初始化图形界面
	setcolor(EGERGB(0xFF, 0x0, 0x0));	//设置绘画颜色为红色
	setbkcolor(WHITE);					//设置背景颜色为白色


	for(int i=0;i<snake.size;i++)
	{
	setfillcolor(RED);
	fillellipse(snake.coor[i].x,snake.coor[0].y,7,5);
	}
	getch();
	cleardevice();
	closegraph();						//关闭图形界面
}

void snake_move()
{
	for(int i=snake.size;i>=0;i--)
	{
	(snake.coor[i].x)+=100;
	}

}


int main()
{
	GameInit();
	//GameDraw();
	
	
		
	snake_move();
	GameDraw();
	
	return 0;
}

