#include<iostream>
using namespace std;

template<typename T>
void f1(T*)
{
	cout << typeid(T).name() << endl;//��ӡ����
}


template<typename T, int N>//���Ͳ���T, �����Ͳ���N
void f2(  T(&p)[N]  ) //����p ΪT [N]  ���������
{
	cout << N << ", " << typeid(T).name() << ", " << p[2] << endl;
}



class S 
{
public:
	void f(double*) {}
};

template<typename T1, typename T2, typename T3>
void f3(  T1(T2::*)(T3*)    )//T2һ����һ������߽ṹ��
{
	cout << typeid(T1).name() << "    " << typeid(T2).name() << "    " << typeid(T3).name() << endl;
}


template <int N>//�����Ͳ���N
class X {
public:
	typedef int I;//������һ������
	void f(int) { }
};



template<int N>//�����Ͳ���N
void  f4(    void (X<N>::*  p)(  typename X<N>::I   )     )//l��ģ�������
{
	cout << N << "    "<<typeid(X<N>::I).name() << endl;
}
// f4�Ĳ����Ǹ�X<N> �ĳ�Ա�������ú����Ļط�����Ϊ void������һ�� X<N>::I����



template<typename T>
void f5(T  t1)
{
	cout << typeid(T).name() << "," << t1 << endl;
}

template<typename T>
class M {
};

template<typename T>
class N : public M<T> {
};

template<typename T>
void f7(   M<T>  )
{
	cout << typeid(T).name() << endl;
}




template<typename T>
void f8(T)
{
	cout << typeid(T).name() << endl;
} 

//�������ã�����Ͳ��ᵱ��ָ����
template<typename T>
void f9(T& t)
{
	cout << typeid(T).name() << endl;
}


/*
T  &  t ��ʾ���ñ���
T  && t  ��ʾ������ֵ���ò���, ����������=�ұ�
*/
template <typename T>
void  f10(T && t)
{
	cout << typeid(t).name() << endl;
}




class Y
{
public:
	typedef   float    vType;
};

template <typename T>
void  f11()
{
	typename  T::vType    t;//��ʾT�������и�vType ����
	cout << typeid(t).name() << endl;
}




void  main()
{
	int ****p = 0;
	f1(p); //���Ƶ�Ϊ int***
	//f1<int ***>(p); �����Զ��Ƶ��� <int ***>���Ա�ʡ��

	int  b[42] = { 1,2,3,4,5 };
	char c[10] = "hello!";
	f2(b); // E���Ƶ�Ϊ  int�� N���Ƶ�Ϊ 42
	f2(c); // E���Ƶ�Ϊ  char�� N���Ƶ�Ϊ 10



	f3( &S::f);//ͨ������Ĳ������Զ��Ƶ�������������


     // f4�Ĳ����Ǹ�X<N> �ĳ�Ա�������ú����Ļط�����Ϊ void������һ�� X<N>::I����
	f4( &X<10>::f);


	//����ָ��f6
	void(*f6)(char) = f5;//�Ƶ��ɹ������� T�滻Ϊ char,�Ա��ָ�ֵ�ĺϷ���
	f6('A');

	N<long> n1;
	M<float> m1;
	f7(n1);// �Ƶ��ɹ��� T���滻Ϊ long
	f7(m1);// �Ƶ��ɹ��� T���滻Ϊ long


	char *p8 = "abc";
	f8(p8);// �Ƶ��ɹ��� T���滻Ϊ char* 
	f9(p8);// �Ƶ��ɹ��� T���滻Ϊ char* 
	double  pp[20];
	f8(pp);// �Ƶ��ɹ��� T���滻Ϊ double* 
	f9(pp);// �Ƶ��ɹ��� T���滻Ϊ double [20]


	int   aa = 99;//������ֵ��Ҳ����ֵ
	f10(aa); //��ȷ
	f10(100); //��ȷ�����Դ�����ֵ
	f10(0.003); //��ȷ�����Դ�����ֵ
	f10("sdfsf"); //��ȷ�����Դ�����ֵ

	f11<Y>();
}