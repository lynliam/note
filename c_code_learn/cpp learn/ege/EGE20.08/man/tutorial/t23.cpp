//���������������ḻ�ı仯��֡��

#include <graphics.h>

#include <stdio.h>

void mainloop()
{
	//x,y��¼��ǰλ�ã�dx,dy��¼�ٶ�������r��¼Բ�뾶
	int x = 0, y = 0, dx = 1, dy = 1, r = 100;

	for ( ; is_run(); delay_fps(60) )
	{
		// todo: �߼�����
		// ��ǰλ�� + �ٶ�
		x += dx;
		y += dy;
		if (x < r) dx = 1; //����
		if (y < r) dy = 1; //����
		if (x >= ege::getwidth()  - r) dx = -1; //����
		if (y >= ege::getheight() - r) dy = -1; //����

		// todo: ͼ�θ���
		cleardevice();
		setcolor(GREEN);
		setfillcolor(BLUE);
		fillellipse(x, y, r, r);
		{// ��֡������
			char str[20];
			sprintf(str, "fps %.02f", getfps()); //����getfpsȡ�õ�ǰ֡��
			setcolor(WHITE);
			outtextxy(0, 0, str);
		}
	}
}

int main(void)
{
	setinitmode(INIT_ANIMATION);
	// ͼ�γ�ʼ�������ڳߴ�640x480
	initgraph(640, 480);
	// �������ʼ���������Ҫʹ��������Ļ�
	randomize();
	// ������ѭ��
	mainloop();
	// �رջ�ͼ�豸
	closegraph();
	return 0;
}
