// 051.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<deque>
using namespace  std;

//实现一个函数模板，要求可以传入迭代器时，返回该迭代器指向的元素值 
 template<class  T> 
 typename  T::value_type  fun(T   it)  //参数是一个迭代器
 { /*加了typename才表示它是类型*/

     return 	 *it;  //获取迭代器指向的元素的值
 } //有一个缺陷，不支持原始指针


 //利用模板的偏特化判断是否这个类型是指针
 template<typename T>
 struct IsPointer
 { 
	 static  const bool   value = false;
 };
 
 template<typename T>
 struct IsPointer<T *>//偏特化
 {
	 static  const  bool   value = true;
 };


 //参考IsPointer， 写一个中间类，实现对普通类型与指针类型都具有value_type内部类型
 template<class T>
 struct  my_traits //不是指针类型
 {
	 typedef     typename T::value_type          value_type;//它的value_type就是迭代器
	 /*加了typename才表示它是类型，否则编译器以为是T的静态成员*/
 };

 template<class T>
 struct  my_traits <T *>//是指针类型
 {
	 typedef    T  value_type; //T *的value_type 就是T
 };

 //利用my_traits 实现一个fun2
 template<class  T>
 typename  my_traits<T>::value_type  fun2(T   it)  //参数是一个迭代器
 { /*加了typename才表示它是类型*/

	 return 	 *it;  //获取迭代器指向的元素的值
	 /*
	  my_traits<int*>::value_type 就是int，从而兼容了指针这种特殊的迭代器 
	 */
 }




int main()
{
	//  value_type是该容器迭代器指向的 元素  的类型
	//vector<int>::iterator::value_type;
	//deque<int>::iterator::value_type;

	vector<int>  v = { 1,2,3,4,5 };
	cout << fun<vector<int>::iterator>(v.begin()) << endl;;
	cout << fun2<vector<int>::iterator>(v.begin()) << endl;;


	int  v2[] = { 1,2,3,4,5 };
	int  *pV = v2; //原始指针也是一种特殊的迭代器
//	cout << fun< int *>( pV) << endl;  //  int *   没有内部类型value_type
    cout << fun2< int *>( pV) << endl;  // 完美，my_traits有内部类型value_type



	{
	   //测试IsPointer
		cout <<"int 是否是指针类型："<< IsPointer<int>::value << endl;
		cout << "string 是否是指针类型：" << IsPointer<string>::value << endl;
		cout << "int *是否是指针类型：" << IsPointer<int*>::value << endl;
		cout << "string * 是否是指针类型：" << IsPointer<string *>::value << endl;
		cout << "string ** 是否是指针类型：" << IsPointer<string **>::value << endl;
	}


    return 0;
}

