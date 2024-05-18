#include<iostream>
using namespace  std;

//只要有一个纯虚函数，就成为抽象类
class Animal
{
public:
	virtual  void  eat() = 0;//纯虚函数
	virtual  void  sleep() = 0;//纯虚函数
	virtual  void  run() = 0;//纯虚函数 
};


class Tiger : public  Animal
{
public:
	//重写了纯虚函数，相当于实现了接口
	virtual  void  eat()
	{
		cout << "吃肉！" << endl;
	}
	virtual  void  sleep() 
	{
		cout << "趴着睡！" << endl;
	}
	virtual  void  run()
	{
		cout << "飞奔！" << endl;
	}

};


class Panda : public  Animal
{
public:
	//重写了纯虚函数，相当于实现了接口
	virtual  void  eat()
	{
		cout << "吃竹子！" << endl;
	}
	virtual  void  sleep()
	{
		cout << "躺着睡！" << endl;
	}
	virtual  void  run()
	{
		cout << "慢腾腾走！" << endl;
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
	//多态性的表现
	Tiger   t; 
	show(&t);


	Panda p;
	show(&p);

	return 0;
}