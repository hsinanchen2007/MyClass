#include<iostream>
using  namespace  std;
 

class  A
{
public:
	 
	void   printThis()
	{
	  //thisָ��ֻ��������ڲ�ʹ�� ������this�����Ѿ�����ֵΪ��ǰ����ĵ�ַ���ɷ���ʹ��
		cout << typeid(this).name()<<"    "<< this << endl;
	} 
};


int  main()
{
 
	A  a;//�������a

	//pAָ�����ĵ�ַ
	A* pA = &a; 
	cout << pA << endl; 
	a.printThis();


	//ÿ��������һ��thisָ�룬ָ���Լ����׵�ַ
	A  a2;
	A* pA2 = &a2;
	cout << pA2 << endl;  
	a2.printThis();


	return 0;
}