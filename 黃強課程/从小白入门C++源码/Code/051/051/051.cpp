#include<iostream>
using namespace  std;

//ֻҪ��һ�����麯�����ͳ�Ϊ������
class Animal
{
public:
	virtual  void  eat() = 0;//���麯��
	virtual  void  sleep() = 0;//���麯��
	virtual  void  run() = 0;//���麯�� 
};


class Tiger : public  Animal
{
public:
	//��д�˴��麯�����൱��ʵ���˽ӿ�
	virtual  void  eat()
	{
		cout << "���⣡" << endl;
	}
	virtual  void  sleep() 
	{
		cout << "ſ��˯��" << endl;
	}
	virtual  void  run()
	{
		cout << "�ɱ���" << endl;
	}

};


class Panda : public  Animal
{
public:
	//��д�˴��麯�����൱��ʵ���˽ӿ�
	virtual  void  eat()
	{
		cout << "�����ӣ�" << endl;
	}
	virtual  void  sleep()
	{
		cout << "����˯��" << endl;
	}
	virtual  void  run()
	{
		cout << "�������ߣ�" << endl;
	}

};



void  show(Animal  *p)
{
	p->eat();
	p->run();
	p->sleep();
}


int  main()
{
	//��̬�Եı���
	Tiger   t; 
	show(&t);


	Panda p;
	show(&p);

	return 0;
}