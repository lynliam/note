//�û�������������2
#include <graphics.h>

//���������Ҫ���ͷ�ļ�
#include <stdio.h>

int main()
{
	initgraph(640, 480);

	setfont(18, 0, "����");
	outtextxy(0, 0, "press any key");

	key_msg k = {0};
	for ( ; k.key != key_esc; ) // key_esc��ege����İ�������
	{
		char str[32];
		//�ȴ��û����������ѵõ��İ�����k
		//����㲻��ȴ��������ڵ���getkey֮ǰ��ʹ��kbmsg����Ƿ��а�������
		//�� if ( kbmsg() ) k = getkey();
		k = getkey();

		//��ʽ�����Ϊ�ַ��������ں������
		//msg�μ�key_msg_e, flag�μ�key_flag_e
		sprintf(str, "key= %c %3d %2x  msg=%d flag=%d", k.key, k.key, k.key, k.msg, k.flags);

		cleardevice();
		outtextxy(0, 0, str);
	}

	closegraph();
	return 0;
}
