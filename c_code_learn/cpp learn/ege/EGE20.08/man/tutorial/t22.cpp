//��������������ƽ�ƶ���
#include <graphics.h>

void mainloop()
{
	// �������Ʊ��������ƺ����꣬��ʼֵΪ0
	int x = 0;

	setcolor(EGERGB(0, 0xFF, 0));
	setfillcolor(EGERGB(0, 0, 0xFF));

	for ( ; is_run(); delay_fps(60) )
	{
		// todo: �߼�����
		//���������꣬����һ�����أ��������440�������ƻ�x=0���ﵽ����ѭ��
		x = ( x + 1 ) % 440;

		// todo: ͼ�θ���
		//�������������µ�λ�û�ͼͼ��
		cleardevice();
		//��xΪԲ����߽�滭��Ϊʲô����߽磿��ΪԲ�������� (x + �뾶) ��
		fillellipse(x + 100, 200, 100, 100);
	}
}

int main(void)
{
	//INIT_ANIMATION�൱��INIT_NOFORCEEXIT|INIT_DEFAULT|INIT_RENDERMANUAL
	//����Ͳ���Ҫ�ٶ�һ��setrendermode
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
