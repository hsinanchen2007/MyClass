// 009.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
#include"009.h"

/*
Stu::Stu(int id)
{
	this->id=id;
} 
void  Stu::Print()
{
	cout << id << endl;
} 
*/

//实现接口
class Cat :public  IAnimal
{
public:

	Cat(int  age)
	{
		this->age = age;
		cout << "猫构造" << endl;
	}

	virtual  void   eat()
	{
		cout << "猫吃鱼" <<endl;
	}

	virtual  void   sleep()
	{
		cout << "猫睡觉" << endl;
	}

	virtual  ~Cat()
	{
		cout << "猫销毁" << endl;
	}

private: 
	int  age; 

};


//利用一个函数导出此类
 _declspec(dllexport)   IAnimal   *   GetCat()
{
	return  new Cat(6);
}

 //释放对象
 _declspec(dllexport)   bool     DelCat(IAnimal   * animal)
 {
	 delete  (Cat *)animal;
	 return true;
 }