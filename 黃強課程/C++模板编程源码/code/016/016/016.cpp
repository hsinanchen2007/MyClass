#include<iostream> 
using  namespace  std;
 

//��ģ��
template<int  N>//�����͵Ĳ���
struct For
{ 
	static  void  F()
	{
		 cout << "ѭ����ִ�����"<<N<<endl;
		  For<N - 1>::F();//����Ǵ����ݹ�ĺ��ģ��Ӷ�����ѭ��
	} 
};
 
//����ȫ�ػ���ֹ�ݹ�,���û�����ȫ�ػ�����һֱ��ѭ���ݹ�
template<>
struct For<1>
{
	static  void  F()
	{
		cout << "ѭ����ִ�����" << 1 << endl;
	}
};

void  main()
{
	  //�����ڵ�forѭ��
	   For<100>::F();
}