//ʹ��IMAGE����ץͼ���滭��IMAGE��IMAGE����Ļ
#include <graphics.h>

//IMAGE�����൱��һ����ͼ�壬��ͬʱҲ������ΪͼƬ��������IMAGE��
//����һ���ǳ����Ķ��󣬸��ӵĻ�ͼ��Ҫ����IMAGE���Ա���õر�������ͼ��

int main()
{
	//����һ��imgͼƬ����
	PIMAGE img;

	initgraph(640, 480);

	//����㻭һЩ����
	setcolor(EGERGB(0xFF, 0xFF, 0x0));
	setfillcolor(EGERGB(0xFF, 0x0, 0x80));
	fillellipse(50, 50, 50, 50);

	//��newimage��initgraph�󴴽�������󡣵��ǵ�Ҫ�ڲ�ʹ�õ�ʱ��delimage
	img = newimage();

	//����Ļ�Ͻ�ȡ(0, 0) - (80, 60)�ⲿ����Ϊimg�����img��СΪ80*60
	//img�ĳߴ�����裬��С�ɵ������ĸ���������
	//ע�⣬(0,0)���ᱻ������img���(80, 60)������
	getimage(img, 0, 0, 80, 60);

	//��img�������ɫΪ��ɫ
	setfillcolor(EGERGB(0x0, 0x70, 0x0), img);

	//��img��ʵ�ľ���
	bar(40, 20, 70, 50, img);

	int x, y;
	//��imgƽ������Ļ�ϣ�ʹ��һ������ѭ��
	for (y = 0; y < 8; ++y)
	{
		for (x = 0; x < 8; ++x)
		{
			//��img����������ָ���������ϣ����ϽǶ����������
			putimage(x * 80, y * 60, img);
		}
	}

	getch();

	delimage(img);

	closegraph();
	return 0;
}
