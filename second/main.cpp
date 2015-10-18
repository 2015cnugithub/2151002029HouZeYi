#include <iostream>
#include <string.h>
using namespace std;
string name1="zhang";

class worker                  //�������
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
	virtual void compute_pay(double hours)=0;            //���麯�������಻��ʵ����������Ҫ��������ʵ��
    friend ostream& operator<<(ostream& out,const worker& w);      //��Ԫ��������ʾ���˻�����Ϣ
};

         
                   //���⣿




ostream& operator<<(ostream& out,const worker&w)
{
	

	out<<w.name<<w.age<<w.sex<<w.pay_per_hour<<endl;    
	//���ﱨ����֪��Ϊʲô��Ԫ��������protected���͵ĳ�Ա������������������

	
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
		switch(level)        //��ͬ����
		{
case 1:if(hours<40)
	   zhouxin=10*hours;
		else
			zhouxin=10*40+1.5*10*(hours-40);break;                     //����Сʱ�ƹ�����н
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

friend ostream& operator<<(ostream& out,const HourlyWorker& w);      //��Ԫ��������ʾ���˻�����Ϣ

	void display()
	{
		cout<<"��н:"<<zhouxin;
		
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
		{                                                            //����нˮ�ƹ�����н
		case 4:if(hours>=35)
				   zhouxin=30*40;
			else zhouxin=30*hours+0.5*30*(35-hours);break;
		case 5:if(hours>=35)
				   zhouxin=50*40;
			else zhouxin=50*hours+0.5*50*(35-hours);break;
		}
	}

	    friend ostream& operator<<(ostream& out,const SalariedWorker& w);      //��Ԫ��������ʾ���˻�����Ϣ


	void display()
	{
		cout<<"��н:"<<zhouxin;      
		
		//Ӧ����ʾ��н������Ԫ�������˴������⣿��������������������
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
	int level;         //�ȼ�
	worker* p[5];
	for(int i=0;i<5;i++)            //����
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
