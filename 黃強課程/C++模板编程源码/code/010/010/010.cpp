#include<iostream>
using namespace  std;

 //len���Ƿ����Ͳ���������һ������
template<  int   len>
void   test()
{
	int  arr[len];//��������ڱ�����ȷ����С
	cout << sizeof(arr)<<endl;
}


char  str2[] = "hello world!";
//����һ���ַ���
template< char *str>
void   test2()
{ 
	cout << str << endl;
}


int  i3 = 100;
//�������͵�����
template< int &  i>
void   test3()
{
	cout << i << endl;
}


//����ָ��
template< int *  p>
void   test4()
{
	cout << *p << endl;
}


void  fun5(int a)
{
	cout << a << endl;
}
//���뺯��ָ��
template<void(*pf)(int)>void  test5(){	pf(666);};


void  main()
{
	//ʵ���˶�̬���飬���û�ָ������
	test<10>();
	test<20>();


	//�������÷��ⲿʵ��
	//test2<"hello world!">();

	//char  str[] = "hello world!";
	//test2< str>();//�Ǿ�̬�洢�ı���

	test2<str2>();
 
	test3<i3>();

	test4<&i3>(); 

	test5<fun5>();
}