//��������һ���淶���
#include <graphics.h>

void mainloop()
{
	// is_run �������Ƿ��յ��ر���Ϣ���յ��Ļ��᷵��false����Ӧ���˳�����
	// delay_fps ����֡�ʣ�60��ʾ��ƽ����ʱ��Ϊ1000/60����
	// Ϊʲôʹ��60����Ϊ60����ʾ����Ĭ��ˢ���ʣ�99.9%����ʾ�������������
	for ( ; is_run(); delay_fps(60) )
	{
		// ����
		cleardevice();
		
		// todo: �߼�����
		//

		// todo: ͼ�θ���
	}
}

int main(void)
{
	// ���ֳ�ʼ��
	// setinitmode���ó�ʼ��ģʽ��
	// INIT_DEFAULT egeĬ������
	// INIT_NOFORCEEXIT �������Ͻ�X��ʱ��ǿ���˳������ɳ�������Ϳ��ƽ���
	// INIT_RENDERMANUAL �����µ�setrendermode(RENDER_MANUAL)��Ч
	setinitmode(INIT_DEFAULT|INIT_NOFORCEEXIT);
	// ͼ�γ�ʼ�������ڳߴ�640x480
	initgraph(640, 480);
	// �������ʼ���������Ҫʹ��������Ļ�
	randomize();
	// ��ͼ����ģʽ����Ϊ�ֶ���������delay_fps/delay_ms�Ⱥ���ʱ��ˢ�£�������˸
	// ��������RENDER_AUTOģʽ�£��κλ�ͼ��������ʱ������ˢ�£�������cleardevice����ʾ
	// ������Ļ����ʱ����ʾһ��������û���������ݵ�����˸
	setrendermode(RENDER_MANUAL);
	// ������ѭ��
	mainloop();
	// �رջ�ͼ�豸
	closegraph();
	return 0;
}
