//ɫ�ʵļ���
#include <graphics.h>

int main()
{
	initgraph(640, 480);

	//���û�ͼ��ɫ��ʹ��RGB�꣬��������ֵ�ķ�Χ��Ϊ0 - 255 (0xFF)
	//�ֱ��ʾ��ɫ���ȣ���ɫ���ȣ���ɫ����
	//EGERGB(0xFF, 0x0, 0x0) (����ɫ) �ȼ���0xFF0000
	setcolor(EGERGB(0xFF, 0x0, 0x0));

	//��һԲ��Բ����(200,200)���뾶100
	circle(200, 200, 100);

	getch();

	closegraph();
	return 0;
}
