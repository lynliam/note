//���ֻ����������������
#include <graphics.h>

int main()
{
	initgraph(640, 480);

	//�Ȼ�һ�����Σ��Ա��ڿ�������ɫ������
	setfillcolor(EGERGB(0x0, 0x80, 0x80));
	bar(50, 50, 500, 200);

	//������ɫ
	setcolor(EGERGB(0x0, 0xFF, 0x0));

	//���ֱ���ɫ��ע��setbkcolor����Ҳ��ͬʱ�ı����ֱ���ɫ��
	setfontbkcolor(EGERGB(0x80, 0x00, 0x80));

	//�������壬��һ������������ĸ߶ȣ����أ����ڶ�������������Ŀ�ȣ��ڶ����������Ϊ0����ʹ��Ĭ�ϱ���ֵ
	//����߶�Ϊ12�����൱��С����֣�����9���֣�ʵ�ʵĻ�����Լ���ɰ�
	setfont(12, 0, "����");

	//д���֣�ע�⣺outtextxy��֧��\t \n�����ʽ���õ������ַ��������ַ��ᱻ����
	//Ҫʹ�������ʽ���ַ�����outtextrect
	outtextxy(100, 100, "Hello EGE Graphics");
	outtextrect(100, 120, 200, 100, "\tHello EGE Graphics\nHere is the next line.");

	//�������ֱ�����䷽ʽΪ͸����Ĭ��ΪOPAQUE��͸��
	setbkmode(TRANSPARENT);
	outtextxy(100, 150, "Hello EGE Graphics, ����Ҳ��֧�ֵ�");

	getch();

	closegraph();
	return 0;
}
