// 009.cpp : ���� DLL Ӧ�ó���ĵ���������
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

//ʵ�ֽӿ�
class Cat :public  IAnimal
{
public:

	Cat(int  age)
	{
		this->age = age;
		cout << "è����" << endl;
	}

	virtual  void   eat()
	{
		cout << "è����" <<endl;
	}

	virtual  void   sleep()
	{
		cout << "è˯��" << endl;
	}

	virtual  ~Cat()
	{
		cout << "è����" << endl;
	}

private: 
	int  age; 

};


//����һ��������������
 _declspec(dllexport)   IAnimal   *   GetCat()
{
	return  new Cat(6);
}

 //�ͷŶ���
 _declspec(dllexport)   bool     DelCat(IAnimal   * animal)
 {
	 delete  (Cat *)animal;
	 return true;
 }