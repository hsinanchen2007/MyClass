#include<iostream>
using  namespace  std;



//��ģ��,ʲô��������
template<bool  b>//�����Ͳ���
struct If;
//{};


//ȫ�ػ���Ϊ���ʱ��ִ��
template<>
struct If<true>
{
	static  void  fun()
	{
		cout << "Ϊ��ִ����䣡"<<endl;
	}
}; 
 
//ȫ�ػ���Ϊ�ٵ�ʱ��ִ��
template<>
struct If<false>
{
	static  void  fun()
	{
		cout << "Ϊ��ִ����䣡" << endl;
	}
};

//////////////////////////////////////////////


//��ģ��,ʲô��������
template<int  Case>//�����Ͳ���
struct Switch
{
	static void f()	{		cout << "ִ��defaultĬ����䣡" << endl;	}

};

//ȫ�ػ���CaseΪ1��ʱ��ִ��
template<>
struct Switch<1>
{
	static void f()	{		cout << "ִ�� case 1��䣡" << endl;	}

};


template<>
struct Switch<2>
{
	static void f()	{		cout << "ִ�� case 2��䣡" << endl;	}

};

template<>
struct Switch<3>
{
	static void f()	{		cout << "ִ�� case 3��䣡" << endl;	}

};

void  main()
{
	//�����ڵ�if�ṹ
	If<true>::fun();
	If<false>::fun();


	//�����ڵ�swicth�ṹ
	Switch<1>::f();
	Switch<2>::f();
	Switch<666>::f();


}