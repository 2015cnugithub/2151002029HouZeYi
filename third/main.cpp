#include <graphics.h>           // ��ͼ��ͷ�ļ�����ͼ�����Ҫ
#include"Figure.h"
#include"Vehicle.h"
#include"Windows.h"
#include"iostream.h"
#include "conio.h"      // ����̨�������ͷ�ļ��� getch()�����Ҫ 
#include <time.h> 

void delay(int sec)
{ 
   time_t start_time, cur_time; // �������� 
time(&start_time); 
do { time(&cur_time); 
} while((cur_time - start_time) < 1.0*sec/(1.0*1000 )); 
} 

void animate(Vehicle *p, int velo)              //�Ӽ��ٿ��ƺ���
{
	while(!p->Is_out())
	{
		p->erase();
		p->move(velo,0);
		p->draw();
		Sleep(50);
		 if(kbhit())                                //��鵱ǰ�Ƿ��м������룬�����򷵻�һ����0ֵ�����򷵻�0
		 {
			 char c=getch();
			 switch(c)
			 {
			 case 'a': velo+=10; break;
			 case 'd': if(velo>=10) velo-=10; break;
			 default:;break;
			 }
		 }
	}

}

int main() {  
//	initgraph(940, 480);     

	Point p1(250,240),p2(370,250),p3(420,440),p4(50,350),p5(210,350),p6(50,370),p7(210,370);
	Point p8(85,380),p9(175,380),p10(75,350),p11(95,350),p12(95,330),p13(165,330),p14(165,350);
	Point p15(185,350),p16(70,360),p17(95,360),p18(185,360),p19(210,360),p20(255,360);
		Point k[4],k1[4];
	k[0]=p4;
	k[1]=p5;
	k[2]=p7;
	k[3]=p6;

	Point ea[4];
	ea[0]=p12;
    ea[1]=p13;
	ea[2]=p14;
	ea[3]=p11;

	Point cc[4],dd[4];
		cc[0](50,270);
		cc[1](230,270);
		cc[2](230,350);
		cc[3](50,350);
		dd[0](235,290);
		dd[1](275,290);
		dd[2](275,350);
		dd[3](235,350);
		Rectangler r1(k,PS_SOLID,0,2,0,0),r2(ea,PS_SOLID,0,2,0,0),r3(cc,PS_SOLID,0,2,0,0);
		Rectangler r4(dd,PS_SOLID,0,2,0,0);
		Circle c1(p8,PS_SOLID,0,2,0,0,10),c2(p9,PS_SOLID,0,2,0,0,10),c3(p16,PS_SOLID,0,2,0,0,10);
		Circle c4(p17,PS_SOLID,0,2,0,0,10),c5(p18,PS_SOLID,0,2,0,0,10),c6(p19,PS_SOLID,0,2,0,0,10);
		Circle c7(p20,PS_SOLID,0,2,0,0,10);
	Triangle t(p10,p11,p12,PS_SOLID,0,2,0,0),t1(p15,p14,p13,PS_SOLID,0,2,0,0);
	Figure *sta[20];
	sta[0]=&t;
	sta[1]=&r1;
	sta[2]=&c1;
	sta[3]=&c2;
	sta[4]=&r2;
	sta[5]=&t1;

	Figure *mina[20];
	mina[0]=&r3;
	mina[1]=&c3;
	mina[2]=&c4;
	mina[3]=&c5;
	mina[4]=&c6;
	mina[5]=&r4;
	mina[6]=&c7;
	Car c(sta,6);
	Truck tr(mina,7);


	Car test(sta,1);

	Vehicle *p=&c,*f=&tr,*v=&test;

	initgraph(1000, 600);            // ��ʼ��1000x600�Ļ�ͼ��Ļ

	outtextxy(70, 230, "�����Ƕ�̬��̬ʵ�飺"); 
	outtextxy(70, 250, "С���˶������а�����A������"); 
	outtextxy(70, 270, "С���˶������а�����D������"); 
	outtextxy(70, 290, "�밴�����������ִ��Ч��"); 

	// �ȴ���������
	getch();

	cleardevice();						// �����������ֽ�������Ч������


	p->draw();                            //С�����˶�
	animate(p,10);

	getch();

	cleardevice();						// �����������ֽ�������Ч������
	f->draw();                         //�����˶�
	animate(f,10);

	getch();
    closegraph();

 return 0;
}

