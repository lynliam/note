//ʹ��IMAGE��������
#include <graphics.h>

int main()
{
	PIMAGE img;

	initgraph(640, 480);

	//����㻭һЩ����
	setcolor(EGERGB(0xFF, 0xFF, 0x0));
	setfillcolor(EGERGB(0xFF, 0x0, 0x80));
	fillellipse(50, 50, 50, 50);

	img = newimage();
	getimage(img, 0, 0, 160, 120);

	int x, y;
	//��imgƽ������Ļ�ϣ�ʹ��һ������ѭ��
	for (y = 0; y < 8; ++y)
	{
		for (x = 0; x < 8; ++x)
		{
			//��img���������컭��ָ���ľ�����
			//��Ҫָ��Ŀ����Σ�Դ����
			//Դ���β������ܺ��ԣ����������������칦�ܵ���ͼ��������
			putimage(x * 80, y * 60, 80, 60, img, 0, 0, 160, 120);
		}
	}

	getch();

	delimage(img);

	closegraph();
	return 0;
}
