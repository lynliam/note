//���������壬�����װ��ʹ�����������
#include <graphics.h>

//����һ��AniObj����ǰһ�������Բ���������д������ṹ����
struct AniObj
{
	int x, y, r;
	int dx, dy;
	int alpha, da;
	PIMAGE img;
};

//��ʼ�����������꣬�ٶȷ���͸���ȣ�����IMAGE��
void initobj(AniObj* obj)
{
	obj->x = 0;
	obj->y = 0;
	obj->r = 100;
	obj->dx = 1;
	obj->dy = 1;
	obj->alpha = 0;
	obj->da = 1;

	// ��ʼ��img
	obj->img = newimage(obj->r * 2, obj->r * 2);

	setcolor(0x00FF00, obj->img);
	setfillcolor(0xFF0000, obj->img);

	fillellipse(obj->r, obj->r, obj->r, obj->r, obj->img);
}

//����λ�õ��������
void updateobj(AniObj* obj)
{
	// ��ǰλ�� + �ٶ�
	obj->x += obj->dx;
	obj->y += obj->dy;
	if (obj->x < 0) obj->dx = 1; //����
	if (obj->y < 0) obj->dy = 1; //����
	if (obj->x >= ege::getwidth()  - obj->r * 2) obj->dx = -1; //����
	if (obj->y >= ege::getheight() - obj->r * 2) obj->dy = -1; //����

	// �ı�alphaֵ
	obj->alpha += obj->da;
	if (obj->alpha <= 0) obj->da = 1;
	if (obj->alpha >= 0xFF) obj->da = -1;
}

//��������ֵ�滭
void drawobj(AniObj* obj)
{
	putimage_alphatransparent(NULL, obj->img, obj->x, obj->y, BLACK, (unsigned char)obj->alpha);
}

//�ͷ��������ʱ����
void releaseobj(AniObj* obj)
{
	delimage(obj->img);
}

void mainloop()
{
	AniObj obj; //����AniObj����
	initobj(&obj); //��ʼ��

	for ( ; is_run(); delay_fps(60) )
	{
		// todo: �߼�����
		updateobj(&obj); //����λ��

		// todo: ͼ�θ���
		cleardevice();
		drawobj(&obj); //�滭
	}

	releaseobj(&obj); //�ͷ�
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
