// 043.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<functional>
using namespace  std;

//使用适配器，改变接口符合用户需求
struct  LessThan3
{
	bool  operator()(int x)
	{
		return  less<int>()(x, 3); //内部实际使用现成的STL类
	} 
};

//为了模拟binder1st    binder2nd   
struct  LessThan4
{
	LessThan4(less<int>  _fn, int  _val):  fn(_fn) , val(_val)
	{ }

	bool  operator()(int x)
	{
		return   fn(x, val); //内部实际使用现成的STL类
	}

	int  val;
	less<int>   fn;
};



int main()
{
	//现在用户想实现 传入一个x，得到是否比3小的结果
	//less<int>()(2,3);//不符合要求，它需要传入两个参数，但用户只想传入一个即可
	cout << "现有的类（功能符合，接口不符合）" << less<int>()(2, 3) << endl;

	//符合用户需求了
	cout << "使用适配器(接口符合) "<<LessThan3()(4) << endl;




	//STL 将  2元函数对象 转换为  1元函数对象 的适配器类，内部填充第一个参数
	binder1st<  less<int> >    uf(  less<int>()/*真正实现功能的仿函数*/,  3  );
    // 相当于less<T>( 3,  ?) 

	//uf是一个一元函数对象
	cout<<"是否比3大： "<< uf(2)<<endl;


	//STL 将  2元函数对象 转换为  1元函数对象 的适配器类 ，内部填充第二个参数
	binder2nd<  less<int> >    uf2(less<int>()/*真正实现功能的仿函数*/, 3);
	// 相当于less<T>( ？,  3)  

	//uf是一个一元函数对象
	cout << "是否比3小： " << uf2(2) << endl;

	//直接写,构造无名对象
	cout<<"无名仿函数对象"<<binder2nd<  less<int> >(less<int>(), 3)(2) << endl;

	//模拟binder1st  binder2nd
	LessThan4   lt(less<int>(), 4);
	cout << "是否比4小： " << lt(5) << endl;


	//直接使用【函数模板bind1st】   产生  【仿函数适配器binder1st】
	cout<< "返回binder1st仿函数对象 ，是否比3大"<<  bind1st(less<int>(), 3) (4) <<endl;

	//直接使用【函数模板bind2nd】   产生  【仿函数适配器binder2nd】


    return 0;
}

