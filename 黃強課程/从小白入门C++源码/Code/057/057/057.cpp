#include<iostream>
using namespace  std;

 
//�����Զ����C++��׼�쳣��
class  MyException : public  exception
{
public:
	//���캯����ʼ���б����������
	MyException(const char *p):exception(p)
	{
	}
};


int  main()
{
	/*
	//�ſ��ܳ����쳣�Ĵ���
	try
	{
		cout << "��ͷ����" << endl;

		int  a = 10;
		int  b = 0;
		int  c = a / b;//��0�쳣���Ӵ˴�ִֹͣ��

		cout << "��β����" << endl;
	}
	catch (...)
	{
		cout << "�����쳣�����д���" << endl;
	}
	*/


	/*
	try
	{
		cout << "��ͷ����" << endl;

		//throw  "�ַ�����";//�׳��ַ������͵��쳣
		//throw  1000;//�׳��������͵��쳣
		//throw   1.234f;//�׳����������͵��쳣

		throw  1.456;//��Ĭ�ϵĲ���

		cout << "��β����" << endl;
	}
	catch (const char  * p)
	{
		cout << "�����쳣��"<<p << endl;
	}
	catch (int   p)
	{
		cout << "�����쳣��" << p << endl;
	}
	catch (float   p)
	{
		cout << "�����쳣��" << p << endl;
	}
	catch (...)
	{
		cout << "�����쳣�����д���" << endl;
	}
	*/



	/*
	try
	{
		for (int i = 0; i < 1000; ++i)
		{
			//�������׼C++�쳣�� bad_alloc�쳣
			new  int[1000000];
		}
	}
	catch (const exception&  e) //exception��C++��׼�쳣��Ļ���
	{
		cout << e.what() << endl;
	}
	*/


	try
	{
		throw  MyException("�Զ����C++��׼�쳣��");
	}
	catch (const exception&  e)
	{
		cout << e.what() << endl;
	}


 
	return 0;
}