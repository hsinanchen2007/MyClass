#include<iostream>
using  namespace  std;
 
class  A
{
public: 
	A()
	{
		cout << "�Զ���Ĭ�ϵĹ��캯����" << endl;
	}


	~A()
	{
		//������ɨβ����
		cout << "�Զ��������������" << endl;
	}


};


int  main()
{
	A  a;//a������ʱ���죬���ٵ�ʱ������

	A   *p = new  A;//���ù��캯��
   delete p;//������������



	return 0;
}