#include<iostream>
using  namespace  std;

class  A
{
public:

	A(int  a1)
	{
		a = a1;
		cout << "�Զ�����вι��캯����"<<endl;
	}


	A( )
	{
		a = 100;
		cout << "�Զ����Ĭ�Ϲ��캯����" << endl;
	}

	void  print()
	{
		cout << a << endl;
	}

	void  setValue(int  a1)
	{
		a = a1;
	}
	 
private:
	int  a;
};



int  main()
{

	//1.�����������,����ʼ��
	A   arr[3] = { A(111) , A(222) , A(333) };


	//2.�ȶ����������
	A   arr2[3];//��ҪĬ�Ϲ��캯�������򱨴�
	//��ֵ
	arr2[0].setValue(444);
	arr2[1].setValue(555);
	arr2[2].setValue(666);


	//������������
	for (int i = 0; i < 3; ++i)
	{
		arr[i].print();
	}

	for (int i = 0; i < 3; ++i)
	{
		arr2[i].print();
	}

	return 0;
}