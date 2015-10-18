#include <iostream>
#include <string.h>
using namespace std;
string name1="zhang";

class worker                  //抽象基类
{
protected:
	string name;
	int age;
	char sex;
	float pay_per_hour;
public:
	worker(string n,int a,char s,float p)
	{
		name=n;
		age=a;
		sex=s;
		pay_per_hour=p;
	}
	virtual void compute_pay(double hours)=0;            //纯虚函数，该类不能实例化对象，需要在子类中实现
    friend ostream& operator<<(ostream& out,const worker& w);      //友元函数，显示工人基本信息
};

         
                   //问题？




ostream& operator<<(ostream& out,const worker&w)
{
	

	out<<w.name<<w.age<<w.sex<<w.pay_per_hour<<endl;    
	//这里报错，不知道为什么友元不能引用protected类型的成员？？？？？？？？？

	
	return out;
}






class HourlyWorker:public worker
{
private:
	int level;
	int hours;
	float zhouxin;
public:
	
	HourlyWorker(string n,int a,char s,float p):worker(n,a,s,p){
	};

	void compute_pay(double hours)
	{
		switch(level)        //不同级别
		{
case 1:if(hours<40)
	   zhouxin=10*hours;
		else
			zhouxin=10*40+1.5*10*(hours-40);break;                     //计算小时制工人周薪
case 2:if(hours<40)
	   zhouxin=20*hours;
		else
			zhouxin=20*40+1.5*20*(hours-40);break;
case 3:if(hours<40)
	   zhouxin=40*hours;
		else
			zhouxin=40*40+1.5*40*(hours-40);break;
		}
	}

friend ostream& operator<<(ostream& out,const HourlyWorker& w);      //友元函数，显示工人基本信息

	void display()
	{
		cout<<"周薪:"<<zhouxin;
		
	}
  

};

ostream& operator<<(ostream& out,const HourlyWorker&w)
{
	out<<w.name<<w.age<<w.sex<<w.pay_per_hour<<endl;  
	return out;
}



class SalariedWorker:public worker
{
private:
	int level;
	int hours;
	float zhouxin;
public:
	SalariedWorker(string n,int a,char s,float p):worker(n,a,s,p){
	};

	void compute_pay(double hours)
	{
		switch(level)
		{                                                            //计算薪水制工人周薪
		case 4:if(hours>=35)
				   zhouxin=30*40;
			else zhouxin=30*hours+0.5*30*(35-hours);break;
		case 5:if(hours>=35)
				   zhouxin=50*40;
			else zhouxin=50*hours+0.5*50*(35-hours);break;
		}
	}

	    friend ostream& operator<<(ostream& out,const SalariedWorker& w);      //友元函数，显示工人基本信息


	void display()
	{
		cout<<"周薪:"<<zhouxin;      
		
		//应该显示周薪，用友元函数，此处有问题？？？？？？？？？？？
	}
};


ostream& operator<<(ostream& out,const SalariedWorker&w)
{
	

	out<<w.name<<w.age<<w.sex<<w.pay_per_hour<<endl;  
	return out;
}




int main()
{

	string name;
	int age;
	char sex;
	float pay_per_hour;
	int level;         //等级
	worker* p[5];
	for(int i=0;i<5;i++)            //输入
	{
		cout<<"please enter name,age,sex,pay per hour,level:"<<endl;
		cin>>name>>age>>sex>>pay_per_hour>>level;
		if(pay_per_hour==10 ||pay_per_hour==20 ||pay_per_hour==40 )
		{
			p[i]=new HourlyWorker;
			p[i]->worker(name,age,sex,pay_per_hour);
		}
		else if(pay_per_hour==30||pay_per_hour==50 )
		{
			p[i]=new SalariedWorker;
	    	p[i]->worker(name,age,sex,pay_per_hour);

		}
	}


	for(i=0;i<5;i++)                 
	{
		p[i]->compute_pay()
	}
	return 0;
}
