class Figure;

class FigureLink
{
	Figure *data;
	FigureLink *next;
public:
	FigureLink(){data=0;next=0;}
	~FigureLink()	{}
	void Set(Figure *k)
	{
		data=k;
	}
	void Setnext(FigureLink *k)
	{
		next=k;
	}
	Figure * Get()
	{
		return data;
	}
	FigureLink *GetNext()
	{
		return next;
	}
	
};

class Vehicle
{
protected:
	FigureLink content;
	FigureLink *head;
public:
	Vehicle(){}
	virtual void draw()=0;
	virtual void erase();
	virtual void move(int x,int y);
	virtual int Is_out()=0;
};

class Car:public Vehicle
{
public:
	Car(){}
	Car(Figure *a1[20],int k);
	virtual void draw();
	virtual int Is_out();
};

class Truck :public Vehicle

{
public:
	Truck(){}
	Truck(Figure *a1[20],int k);
	void draw();
	virtual int Is_out();
	};