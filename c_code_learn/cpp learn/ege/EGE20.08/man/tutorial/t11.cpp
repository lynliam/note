//ʹ��IMAGE����͸������͸��
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

	//�Ȼ�һ���Ǻ�ɫ�������Ա��ڱȽ�
	setbkcolor(EGERGB(0x80, 0x80, 0x80));
	cleardevice();

	//������ͼ�Ƚ�
	putimage(0, 0, img);
	putimage_alphablend(NULL, img, 160, 0, 0x80); //��͸����Ϊ0x80
	putimage_transparent(NULL, img, 0, 80, BLACK);	//͸����ͼ���ؼ�ɫΪBLACK��ԴͼΪ�����ɫ�ĵط��ᱻ����
	putimage_alphatransparent(NULL, img, 160, 80, BLACK, 0xA0); //ͬʱʹ��͸���Ͱ�͸��

	getch();

	delimage(img);

	closegraph();
	return 0;
}
