# include<stdio.h>
# include<graphics.h>
# include<conio.h>
# include<stdlib.h>

#define SNAKE_NUM 500
enum DIR //表示蛇的方向
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
};

struct Food
{
	int x;
	int y;
	int r;
	bool flag;//定义食物是否被吃掉
	DWORD color;
}food;

struct Snake
{
	int size;
	int speed;
	int dir;
	POINT coor[SNAKE_NUM];
}snake;

void GameInit()
{
	//窗口
	initgraph(640,480);
	//设置随机数种子   
	srand(GetTickCount());//GetTickCount()获取系统开机 到现在所经过的毫秒数

	//蛇
	snake.size = 3;
	snake.speed = 10;
	snake.dir=RIGHT;
	for(int i=0;i< snake.size;i++)
	{
		snake.coor[i].x=30-i*10;
		snake.coor[i].y=10;
	}

	//食物
	food.x = rand() % 640;//防止超出窗口
	food.y = rand() % 480;
	food.color = RGB(rand()%256,rand()%256,rand()%256);//颜色初始化
	food.r = rand()%10+5;
	food.flag = true;

}
void GameDraw()
{
	BeginBatchDraw();

	//窗口
	setbkcolor(RGB(14,218,243));//背景色是蓝色
	cleardevice();

	//蛇
	for(int i=0;i<snake.size;i++)
	{
	solidcircle(snake.coor[i].x,snake.coor[i].y,5);
	}
	setfillcolor(WHITE);

	//食物
	if(food.flag)
	{
		solidcircle(food.x,food.y,food.r);
	}

	EndBatchDraw();
}
void SnakeMove()
{
	//蛇头
	snake.coor[0].x++;

	//蛇身
	for(int i = snake.size-1;i>0;i--)//从后往前
	{
		snake.coor[i] = snake.coor[i-1];
	}
	switch(snake.dir)
	{
    case UP:
		snake.coor[0].y-=snake.speed;
		if(snake.coor[0].y+10<=0)//坐标、半径和边界的关系判定
			{
				snake.coor[0].y = 480; //480就是窗口的宽
			}
			break;

	case DOWN:
		snake.coor[0].y+=snake.speed;
		if(snake.coor[0].y-10>=480)
			{
				snake.coor[0].y = 0; 
			}
			break;

	case LEFT:
		snake.coor[0].x-=snake.speed;
		if(snake.coor[0].x+10<=0)
			{
				snake.coor[0].x = 640; 
			}
			break;

	case RIGHT:
		snake.coor[0].x+=snake.speed;
		if(snake.coor[0].x-10>=640)
			{
				snake.coor[0].x = 0; 
			}
			break;
	}
}
void KeyControl()
{
	if(_kbhit())//检查是否有输入，有则返回真
	{
		switch(_getch()) 
	 {
	 case 'w':
	 case 'W':
	 case '72':
		//改变方向,但是不能调头
		if(snake.dir != DOWN)
			snake.dir=UP;
		break;

	 case 's':
	 case 'S':
	 case '80':
		if(snake.dir != UP)
			snake.dir=DOWN;
		break;

	 case 'a':
	 case 'A':
	 case '75':
		if(snake.dir != RIGHT)
			snake.dir=LEFT;
		break;

	 case 'd':
	 case 'D':
	 case '77':
		if(snake.dir != LEFT)
			snake.dir=RIGHT;
		break;

	//游戏暂停逻辑
	 case ' ':
		 while(1)
		 {
			if(_getch() == ' ')
				return;
		 }
		 break;
	 }
	}
}
void EatFood()
{
	if(food.flag && snake.coor[0].x >= food.x-food.r && snake.coor[0].x <= food.x+food.r && snake.coor[0].y >= food.y - food.r && snake.coor[0].y<=food.y+food.r)
	{
		food.flag = false;
		snake.size++;
	}
	//生成新食物
	if(!food.flag)
	{
		food.x = rand() % 640;
		food.y = rand() % 480;
		food.color = RGB(rand()%256,rand()%256,rand()%256);
		food.r = rand()%10+5;
		food.flag = true;
	}
}

int main()
{
	GameInit();

	while(1)
	{
		GameDraw();
		KeyControl();
		EatFood();
		SnakeMove();
		Sleep(150);
	}
}