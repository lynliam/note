//�û�������������1
#include <graphics.h>

//���������Ҫ���ͷ�ļ�
#include <stdio.h>

int main()
{
	initgraph(640, 480);

	setfont(18, 0, "����");
	outtextxy(0, 0, "please press any key");

	int k = 0;
	for ( ; k != key_esc; ) // key_esc��ege����İ�������
	{
		char str[32];
		//�ȴ��û����������ѵõ��İ�����k
		//����㲻��ȴ��������ڵ���getch֮ǰ��ʹ��kbhit����Ƿ��а�������
		//�� if ( kbhit() ) k = getch();
		k = getch();

		//��ʽ�����Ϊ�ַ��������ں������
		sprintf(str, "%c %3d", k, k);

		cleardevice();
		outtextxy(0, 0, str);
	}

	closegraph();
	return 0;
}
