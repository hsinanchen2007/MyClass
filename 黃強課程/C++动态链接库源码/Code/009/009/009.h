#pragma once

/*
//����C++��
class  _declspec(dllexport)    Stu
{
public:
	Stu(int  id);
	void  Print();
private:
	int  id; 
};
*/


//���õĵ�����ķ�ʽ
//�ӿ���
class   IAnimal
{
public:
	virtual  void   eat() = 0;
	virtual  void   sleep() = 0; 
};

_declspec(dllexport)   IAnimal   *   GetCat();
_declspec(dllexport)   bool     DelCat(IAnimal   * animal);