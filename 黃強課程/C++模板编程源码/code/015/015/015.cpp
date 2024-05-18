#include<iostream>
using  namespace  std;



//主模板,什么都不用做
template<bool  b>//非类型参数
struct If;
//{};


//全特化、为真的时候执行
template<>
struct If<true>
{
	static  void  fun()
	{
		cout << "为真执行语句！"<<endl;
	}
}; 
 
//全特化、为假的时候执行
template<>
struct If<false>
{
	static  void  fun()
	{
		cout << "为假执行语句！" << endl;
	}
};

//////////////////////////////////////////////


//主模板,什么都不用做
template<int  Case>//非类型参数
struct Switch
{
	static void f()	{		cout << "执行default默认语句！" << endl;	}

};

//全特化、Case为1的时候执行
template<>
struct Switch<1>
{
	static void f()	{		cout << "执行 case 1语句！" << endl;	}

};


template<>
struct Switch<2>
{
	static void f()	{		cout << "执行 case 2语句！" << endl;	}

};

template<>
struct Switch<3>
{
	static void f()	{		cout << "执行 case 3语句！" << endl;	}

};

void  main()
{
	//编译期的if结构
	If<true>::fun();
	If<false>::fun();


	//编译期的swicth结构
	Switch<1>::f();
	Switch<2>::f();
	Switch<666>::f();


}