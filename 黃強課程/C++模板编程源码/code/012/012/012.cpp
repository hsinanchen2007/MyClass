#include<iostream>
using namespace std;

template<typename T>
void f1(T*)
{
	cout << typeid(T).name() << endl;//打印类型
}


template<typename T, int N>//类型参数T, 非类型参数N
void f2(  T(&p)[N]  ) //参数p 为T [N]  数组的引用
{
	cout << N << ", " << typeid(T).name() << ", " << p[2] << endl;
}



class S 
{
public:
	void f(double*) {}
};

template<typename T1, typename T2, typename T3>
void f3(  T1(T2::*)(T3*)    )//T2一定是一个类或者结构体
{
	cout << typeid(T1).name() << "    " << typeid(T2).name() << "    " << typeid(T3).name() << endl;
}


template <int N>//非类型参数N
class X {
public:
	typedef int I;//定义了一个类型
	void f(int) { }
};



template<int N>//非类型参数N
void  f4(    void (X<N>::*  p)(  typename X<N>::I   )     )//l是模板的类型
{
	cout << N << "    "<<typeid(X<N>::I).name() << endl;
}
// f4的参数是个X<N> 的成员函数、该函数的回返类型为 void，接受一个 X<N>::I参数



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

//加了引用，数组就不会当成指针了
template<typename T>
void f9(T& t)
{
	cout << typeid(T).name() << endl;
}


/*
T  &  t 表示引用变量
T  && t  表示可以右值引用参数, 常量，放在=右边
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
	typename  T::vType    t;//表示T类型中有个vType 类型
	cout << typeid(t).name() << endl;
}




void  main()
{
	int ****p = 0;
	f1(p); //被推导为 int***
	//f1<int ***>(p); 由于自动推导， <int ***>可以被省略

	int  b[42] = { 1,2,3,4,5 };
	char c[10] = "hello!";
	f2(b); // E被推导为  int， N被推导为 42
	f2(c); // E被推导为  char， N被推导为 10



	f3( &S::f);//通过传入的参数，自动推导出来，很智能


     // f4的参数是个X<N> 的成员函数、该函数的回返类型为 void，接受一个 X<N>::I参数
	f4( &X<10>::f);


	//函数指针f6
	void(*f6)(char) = f5;//推导成功，并将 T替换为 char,以保持赋值的合法性
	f6('A');

	N<long> n1;
	M<float> m1;
	f7(n1);// 推导成功： T被替换为 long
	f7(m1);// 推导成功： T被替换为 long


	char *p8 = "abc";
	f8(p8);// 推导成功： T被替换为 char* 
	f9(p8);// 推导成功： T被替换为 char* 
	double  pp[20];
	f8(pp);// 推导成功： T被替换为 double* 
	f9(pp);// 推导成功： T被替换为 double [20]


	int   aa = 99;//即是左值，也是右值
	f10(aa); //正确
	f10(100); //正确，可以传入右值
	f10(0.003); //正确，可以传入右值
	f10("sdfsf"); //正确，可以传入右值

	f11<Y>();
}