#include<iostream>
using  namespace  std;

class  A
{
public:
	A( )
	{ 
		pA = new int[10];
		cout << "A�Ĺ��캯����" << endl;
	}
	~A()
	{
		//���ڴ��ͷ�������
		delete[]pA;
		pA = NULL;
		cout << "A������������" << endl;
	}
 
private:
	int  *pA;
};


class  B : public  A
{
public:
	 
	B()
	{ 
		pB = new int[10];
		cout << "B�Ĺ��캯����" << endl;
	}
	~B()
	{
		//���ڴ��ͷ�������
		delete[]pB;
		pB = NULL;
		cout << "B������������" << endl;
	}


private:
	int  *pB;
};


int  main()
{
	//�����͹����˳�������෴
	B  b;

	return 0;
}