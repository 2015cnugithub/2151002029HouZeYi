#include"Figure.h"
#include"Vehicle.h"
#include"math.h"
#include <graphics.h>

 void Circle::draw()
 {
	 setfillcolor(Incol);
	 setlinestyle(style, width);
	fillcircle (cen.x,cen.y, radius);
}
 void Circle::erase()
 {
     setfillcolor(BLACK);
	 setlinestyle(style, width);
	fillcircle (cen.x,cen.y, radius);
 }
 void Circle::move(int x,int y)
 {
	 cen.x+=x;
	 cen.y+=y;
 }
 Triangle::Triangle(Point p1,Point p2,Point p3,int s,int p,int w, int f,int I)
 {
	style=s;
	pattern=p;
	width=w;
	fcol=f;
	Incol=I;
	fir=p1;
	sec=p2;
	thi=p3;
}
 void Triangle::move(int x,int y)
 {
	  fir.x+=x;
	 fir.y+=y;
	  sec.x+=x;
	 sec.y+=y;
	  thi.x+=x;
	 thi.y+=y;
 }
 void Triangle::draw()
 {
    setfillcolor(Incol);               //填充颜色
	setlinecolor(WHITE);
	setlinestyle(style, width);
	line(fir.x,fir.y,sec.x,sec.y);
	line(sec.x,sec.y,thi.x,thi.y);
	line(fir.x,fir.y,thi.x,thi.y);
	Point tem,tem1;
	tem.x=(fir.x+sec.x)/2;
	tem.y=(fir.y+sec.y)/2;
	tem1.x=(tem.x+thi.x)/2;
    tem1.y=(tem.y+thi.y)/2;
	floodfill(tem1.x,tem1.y,WHITE);                 //这个函数用于填充区域
}
 void Triangle::erase()
 {
	 setfillcolor(BLACK);
	 setlinecolor(BLACK);
	setlinestyle(style, width);
	line(fir.x,fir.y,sec.x,sec.y);
	line(sec.x,sec.y,thi.x,thi.y);
	line(fir.x,fir.y,thi.x,thi.y);
	Point tem,tem1;
	tem.x=(fir.x+sec.x)/2;
	tem.y=(fir.y+sec.y)/2;
	tem1.x=(tem.x+thi.x)/2;
    tem1.y=(tem.y+thi.y)/2;
	floodfill(tem1.x,tem1.y,BLACK);
}
 Rectangler::Rectangler(Point pp[4],int s,int p,int w, int f,int I)
 {
	 int i;
	 for(i=0;i<4;i++)
	 {pt[i].x=pp[i].x;pt[i].y=pp[i].y;}
	 style=s;
	pattern=p;
	width=w;
	fcol=f;
	Incol=I;
}
 void Rectangler::draw()
 {
	setlinecolor(WHITE);
	 setfillcolor(Incol);
	setlinestyle(style, width);
	line(pt[1].x,pt[1].y,pt[2].x,pt[2].y);
	line(pt[0].x,pt[0].y,pt[1].x,pt[1].y);
	line(pt[3].x,pt[3].y,pt[2].x,pt[2].y);
	line(pt[3].x,pt[3].y,pt[0].x,pt[0].y);
	floodfill(pt[0].x+1,(pt[1].y+pt[2].y)/2,WHITE);
	
}
 void Rectangler::move(int x, int y)
 {
	 for(int i=0;i<4;i++)
	 {
		 pt[i].x+=x;
		 pt[i].y+=y;
	 }
 }
 void Rectangler::erase()
 {
     setlinecolor(BLACK);
	 setfillcolor(BLACK);
	setlinestyle(style, width);
	line(pt[1].x,pt[1].y,pt[2].x,pt[2].y);
	line(pt[0].x,pt[0].y,pt[1].x,pt[1].y);
	line(pt[3].x,pt[3].y,pt[2].x,pt[2].y);
	line(pt[3].x,pt[3].y,pt[0].x,pt[0].y);

	floodfill(pt[0].x+1,(pt[1].y+pt[2].y)/2,BLACK);
}
 Car::Car(Figure *a1[20],int k)
 {
	 int i=0;
	 head=&content;
	 FigureLink *p=head;
	Point p1(250,240),p2(370,250),p3(420,440);
	for(;i<k;i++)
	{
    head=new FigureLink;
	head->Set(a1[i]);
	p->Setnext(head);
	p=head;
	}
}

 void Car::draw()
 {
	 FigureLink *p=content.GetNext();
	 Figure *cast;
	 while(/*p->GetNext()!=NULL*/1)
	 {
		 cast=p->Get();
		 cast->draw();
		 p=p->GetNext();
		 if(p==0) return;
	 }
 }
 int Car::Is_out()
 {
	 FigureLink *p=content.GetNext();
	 Figure *cast;
	 cast=p->Get();
	 if(cast->Is_out()==1) return 1;
	 return 0;
 }

 Truck:: Truck(Figure *a1[20],int k)
 {
	 int i=0;
	 head=&content;
	 FigureLink *p=head;
	Point p1(250,240),p2(370,250),p3(420,440);
	for(;i<k;i++)
	{
    head=new FigureLink;
	head->Set(a1[i]);
	p->Setnext(head);
	p=head;
	}
}
void Truck::draw()
 {
	 FigureLink *p=content.GetNext();
	 Figure *cast;
	 while(/*p->GetNext()!=NULL*/1)
	 {
		 cast=p->Get();
		 cast->draw();
		 p=p->GetNext();
		 if(p==0) return;
	 }
 }
int Truck::Is_out()
{
	 FigureLink *p=content.GetNext();
	 Figure *cast;
	 cast=p->Get();
	 if(cast->Is_out()==1) return 1;
	 return 0;
 }

void Vehicle::erase()
{ 
	 FigureLink *p=content.GetNext();
	 Figure *cast;
	 while(/*p->GetNext()!=NULL*/1)
	 {
		 cast=p->Get();
		 cast->erase();
		 p=p->GetNext();
		 if(p==0) return;
	 }
 }
void Vehicle::move(int x,int y)
{
	FigureLink *p=content.GetNext();
	 Figure *cast;
	 while(/*p->GetNext()!=NULL*/1)
	 {
		 cast=p->Get();
		 cast->move(x,y);
		 p=p->GetNext();
		 if(p==0) return;
	 }
 }