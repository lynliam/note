//�߼����������ɫ��ʾ�취(HSV/HSL)
#include <graphics.h>

int main()
{
	initgraph(640, 480);

	//��ʼ�����������
	randomize();

	for (; ;)
	{
		//ʹ�����ɫ�ʣ�����Ϊ1.0������Ϊ0.5
		//��һ��������Χ��0 - 360����ʾһ���Ƕȣ������ɫ���ڵ�HSL˫ͷԲ׶�ķ�λ
		//0�Ǻ�ɫ��120����ɫ��240����ɫ�����pdf�ĵ��ڵ�HSL��ɫ�ռ��˵��
		setfillcolor(hsl2rgb(float(randomf() * 360), 1.0f, 0.5f));

		bar(100,100, 300, 200);

		//��һ�°����仯һ����ɫ��ESC�˳�
		if (getch() == 27) break;
	}

	closegraph();
	return 0;
}
