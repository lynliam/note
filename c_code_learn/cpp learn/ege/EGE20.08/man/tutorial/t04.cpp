//��ɫ���
#include <graphics.h>

int main()
{
	initgraph(640, 480);

	//���������ɫ��һ��Ϊͼ���ڲ���ɫ
	setfillcolor(EGERGB(0xFF, 0x0, 0x80));

	//��һʵ�ľ��Σ���ΧΪ��x�����50-300��y�����100-200
	bar(50, 100, 300, 200);

	getch();

	closegraph();
	return 0;
}
