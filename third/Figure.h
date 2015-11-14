class Point
{
public:
	int x;
	int y;
	Point(){}
	Point(int xx,int yy){x=xx;y=yy;}
	Point(Point &p){x=p.x;y=p.y;}
	void operator()(int a,int b)
	{
		x=a;y=b;
	}
	
};
class Figure
{
protected:
	int style;
	int pattern;
	int width;
	int fcol;
	int Incol;
public:
	Figure(){}
	virtual void draw()=0;
	virtual void erase()=0;
	virtual void move(int x, int y)=0;
	virtual int  Is_out(){return 0;}
};

class Circle:public Figure
{
	Point cen;
	int radius;
public:
	Circle(){}
	Circle(Point c,int s,int p,int w, int f,int I,int r)
	{
	style=s;
	pattern=p;
	width=w;
	fcol=f;
	Incol=I;
	cen=c;
	radius=r;
	}
	virtual void draw();
	virtual void erase();
	virtual void move(int x, int y);
	virtual int Is_out(){if(cen.x-radius>800) return 1; return 0;}
};

class Triangle:public Figure
{
	Point fir,sec,thi;
public:
	Triangle(){}
	Triangle(Point p1,Point p2,Point p3,int s,int p,int w, int f,int I);
	virtual void draw();
	virtual void erase();
	virtual void move(int x, int y);
	virtual int Is_out(){if(fir.x>750) return 1; return 0;}
};

class Rectangler:public Figure
{
	Point pt[4];
public:
	Rectangler(){}
	Rectangler(Point pp[4],int s,int p,int w, int f,int I);
	virtual void draw();
	virtual void erase();
		virtual void move(int x, int y);
		virtual int Is_out(){if(pt[0].x>750) return 1; return 0;}
};
