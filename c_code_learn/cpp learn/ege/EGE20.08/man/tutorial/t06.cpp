//��Ļ����ɫ
#include <graphics.h>

int main()
{
	initgraph(640, 480);

	//��һ�����ñ���ɫ
	setbkcolor(EGERGB(0x0, 0x40, 0x0)); //ǳ��ɫ

	setcolor(EGERGB(0xFF, 0xFF, 0x0));
	setfillcolor(EGERGB(0xFF, 0x0, 0x80));

	//������������
	sector(200, 200, 45, 135, 150, 100);

	getch();

	//����һ��������ٴθı䱳��ɫ
	setbkcolor(EGERGB(0x0, 0x0, 0x40)); //ǳ��ɫ

	getch();

	closegraph();
	return 0;
}

//���䣺����setbkcolor_f�����������õ���cleardevice������ʹ�õ���ɫ��
//����Ҫ�ȵ�cleardevice����ʱ������Ч���Ż�չ�֡�
//��Ȼ��setbkcolorҲ�����ã���ͬʱҲ����������Ļ�ϵ�ԭ����ɫ�ı�

