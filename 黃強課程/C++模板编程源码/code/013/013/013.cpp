#include<iostream>
using namespace std;
 
template<typename T>//ʹ�����ڶ����A<void>
class A {
private:
	A<void> a;  //������һ���ݹ鶨�壬�������޷���ȷA�Ķ���
};

//�ػ��ս�ݹ鶨��
template <>
class A<void>
{
};


template<int N>
class Sum
{
public:
	enum//��ö�����ͣ���Ϊ�ñ�����������ȥ�ڱ������Ƶ�ֵ�ģ�C++���Ա������ʼ�����ܷ����ඨ���У�
	{
		value = N + Sum<N - 1>::value 
	};
};

//��Ҫ�ػ�0, �ػ�����������ͣ�����  ����ػ���-1�� ������-1
template<>
class Sum<0>
{
public:
	enum
	{
		value = 0
	};
};


//���嵽98����ֹ�����
template<>
class Sum<98>
{
public:
	enum
	{
		value = 98
	};
};




// ��ģ��
template<unsigned long N>
struct  BinToDec
{
	static    const unsigned   val = BinToDec<N / 10>::val * 2 + N % 10;
};

template<>
struct  BinToDec<0>//�ػ�
{
	static    const unsigned   val = 0;
};



void  main()
{
	A<int>  a;//ģ����


	//���ñ����ڵݹ�ʵ����ͺ���
   cout<<	Sum<100>::value<<endl;


   //���ñ����ڵݹ�ʵ�ֶ�����תʮ����
   cout << BinToDec<10000>::val << endl;
   cout << BinToDec<10001>::val << endl;
}