//���������ģ���͸�����뵭��
#include <graphics.h>

void mainloop()
{
	// x,y��¼��ǰλ�ã�dx,dy��¼�ٶȵķ���r��¼Բ�뾶
	int x = 0, y = 0, dx = 1, dy = 1, r = 100;
	// alpha��¼��ǰalphaֵ��daΪalpha�仯����
	int alpha = 0, da = 1;

	// ��Ҫ����imgʵ��͸����͸��
	PIMAGE img;

	// img ����Ϊ w=r*2, h=r*2��С
	img = newimage(r * 2, r * 2);

	setcolor(0x00FF00, img);
	setfillcolor(0xFF0000, img);
	
	// ����img��
	fillellipse(r, r, r, r, img);

	setbkcolor(DARKGRAY);

	for ( ; is_run(); delay_fps(60) )
	{
		// todo: �߼�����
		// ��ǰλ�� + �ٶ�
		x += dx;
		y += dy;
		if (x < 0) dx = 1; //����
		if (y < 0) dy = 1; //����
		if (x >= ege::getwidth()  - r * 2) dx = -1; //����
		if (y >= ege::getheight() - r * 2) dy = -1; //����

		// �ı�alphaֵ��������ΧΪ 0 ~ 0xFF(255)
		alpha += da;
		if (alpha <= 0) da = 1;
		if (alpha >= 0xFF) da = -1;

		// todo: ͼ�θ���
		cleardevice();
		putimage_alphatransparent(NULL, img, x, y, BLACK, (unsigned char)alpha);
	}

	// �ͷ�img
	delimage(img);
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
