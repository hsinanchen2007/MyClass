#include<iostream>
using namespace  std;

/*
//���ؼ̳з�ʽһ
class  A
{
public:
	A( )
	{
		cout << "A���캯����" << endl; 
	} 
	~A()
	{
		cout << "A����������" << endl;
	}
}; 

class  B: public  A
{
public:
	B( )
	{
		cout << "B���캯����" << endl; 
	} 
	~B()
	{
		cout << "B����������" << endl;
	}
};

class  C : public  B
{
public: 
	C( ) 
	{
		cout << "C���캯����" << endl; 
	} 
	~C()
	{
		cout << "C����������" << endl;
	}
};
*/



//���ؼ̳з�ʽ��
class  A
{
public:
	A()
	{
		cout << "A���캯����" << endl;
	}
	~A()
	{
		cout << "A����������" << endl;
	}
};

class  B  
{
public:
	B()
	{
		cout << "B���캯����" << endl;
	}
	~B()
	{
		cout << "B����������" << endl;
	}
};

class  C : public  A , public  B //���̳�˳����
{
public:
	C()
	{
		cout << "C���캯����" << endl;
	}
	~C()
	{
		cout << "C����������" << endl;
	}
};


int  main()
{
	//�������ַ�ʽ������������˳�����빹��˳���෴
	C   c ;
	 

	return  0;
}