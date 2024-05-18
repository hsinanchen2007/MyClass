#include<iostream>
using  namespace  std;

class  Home
{
public:
	int      mailBox;//邮箱、公有

	void   eat()//吃饭，公有
	{  }

protected:
	int   houseCard;//房产证、保护

	void   sleep()//睡觉、保护
	{}

private:
	int   bankCard;//银行卡，私有

	void   clean()//做卫生，私有
	{}


public:
	//在类的内部三种权限都可以访问
	void  test()
	{
		//访问三种成员变量
		cout << mailBox << houseCard << bankCard << endl;

		//访问三种成员函数
		eat();
		sleep();
		clean(); 
	}
		 

};
 

int  main()
{
 
	//在类的外部，三种权限只有public可以访问
	Home   home;

	home.mailBox;//只能访问public的成员变量
	home.eat();//只能访问public的成员函数

	home.houseCard;//不可访问protected
	home.sleep();

	home.bandCard;//不可访问private
	home.clean();

	return 0;
}