//�û������������1
#include <graphics.h>

#include <stdio.h>

int main()
{
	initgraph(640, 480);

	setfont(18, 0, "����");

	int k = 0;

	// ���ѭ����is_run�жϴ����Ƿ��ڣ�delay_fps����ʱ
	// ���潲������ʱ�����ϸ���⣬�ֲ�Ҫ�ڴ˾���
	for ( ; is_run(); delay_fps(60))
	{
		char str[32];
		int x, y;

		//��ȡ������꣬�˺������ȴ���������Ƴ��˴��ڣ���ô����ֵ�������
		//��������ǣ��㰴���������ţ��ϳ����ڣ���������ֵ����Ȼ����
		mousepos(&x, &y);

		//��ʽ�����Ϊ�ַ��������ں������
		sprintf(str, "%4d %4d", x, y);

		outtextxy(0, 0, str);
	}

	closegraph();
	return 0;
}
