//ͼ�α߽�����
#include <graphics.h>

int main()
{
	initgraph(640, 480);

	//���û�ͼ��ɫ��һ�����ڱ߽�
	setcolor(EGERGB(0xFF, 0xFF, 0x0));

	//���������ɫ��һ��Ϊͼ���ڲ���ɫ
	setfillcolor(EGERGB(0xFF, 0x0, 0x80));

	//��һ��������Բ
	fillellipse(200, 200, 150, 100);

	//��һ������Բ
	circle(500, 300, 100);

	//�ٴ����������ɫ�����ھ�����һ����������ɫ
	setfillcolor(EGERGB(0x80, 0x0, 0xFF));

	//�ֹ����
	//x,y�ǿ�ʼ�������꣬���������������ı߽���ɫ������˵�������ɫ��Ϊ�߽�
	//�������߽粻��գ���ô�ᵼ��������Ļ���������ɫ
	//ע�⣬ ��������ǽ������ʹ��floodfill, ���������Ҫ����ʵ����Բ, ����Ȼʹ��fillellipse
	floodfill(500, 300, EGERGB(0xFF, 0xFF, 0x0));

	getch();

	closegraph();
	return 0;
}
