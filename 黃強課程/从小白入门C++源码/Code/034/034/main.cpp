#include<iostream>
using  namespace  std;
 



void    fun2()
{
	static   int n = 0;//3. ��̬�洢���ı�����ֻ��ʼ��һ�Σ���������Ϊ���������ڼ�
	cout << ++n << endl;
}


//4.���γ�Ա�����ͺ�����ʹ���ɾ�̬�ĳ�Ա���������ж����е�
class A
{
public:
	//��̬��Ա����
	static  void  print()
	{
		cout << "��̬��Ա������" << endl;
	}
private:
	static  int  a;//��̬��Ա����  
};


int  main()
{
	
	extern  int  a;//ֻ������
	//cout << a << endl;

	extern  void fun();//����������
	//fun();



	//fun2����3��
	fun2();
	fun2();
	fun2();


	//���������þ�̬����
	A::print();

	return 0;
}