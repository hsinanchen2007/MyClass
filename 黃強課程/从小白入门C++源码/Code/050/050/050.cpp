#include<iostream>
using namespace  std;
 
class   A
{
public :

	//�麯��
	virtual  void print()
	{
		cout << "A::print()" << endl;
	}

};


class  B: public  A
{
public:

	//�麯��, ��д�麯��
	virtual  void print()
	{
		cout << "B::print()" << endl;
	}

};




int  main()
{
	A  *pA = NULL;

	pA = new A;
	//ͬ���ĵ��÷�������ͬ�ı���
	pA->print();


	pA = new B;
	//ͬ���ĵ��÷�������ͬ�ı���
	pA->print();


	return 0;
}