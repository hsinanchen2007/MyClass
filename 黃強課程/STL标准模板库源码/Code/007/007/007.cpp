// 007.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include<iostream>
#include<array>
using namespace  std;

int main()
{
	//定义array对象，元素默认值随机
	array<int, 5>  arr; //数组元素类型int，长度为5， 底层就是  int  arr[5]
	cout << "数组大小" << arr.size() << "	" << arr[0] << endl;

	//定义array对象初始化元素值
	array<int, 5>  arr2 = {1,2,3}; //其它剩余元素的默认为0
	cout << "数组大小" << arr2.size() << "	" << arr2[0] << endl;

	//拷贝构造
	array<int, 5>  arr3(arr2);
	cout << "数组大小" << arr3.size() << "	" << arr3[3] << endl;


	//像使用普通数组一样的使用array模板类
	arr[0] = 11;
	arr[1] = 22;
	arr[2] = 33;
	arr.at(3) = 44;//at成员函数等价于 []
	arr.at(4) = 55;

	for (size_t i = 0; i < arr.size(); i++)
	{
		//cout << arr[i] << "		";
		cout << arr.at(i) << "		";
	}
	cout << endl;


	//将普通数组封装为类模板之后，提供成员方法，使用更方便，更安全
	cout << "获取第一个元素"<<arr.front()<<endl;
	cout << "获取最后一个元素" << arr.back() << endl;
	cout << "检测数组长度为零" << arr.empty() << endl;

	array<int, 0>  arr4;
	cout << "检测arr4长度为零" << arr4.empty() << endl;

	cout << "返回内部数组的首地址" << arr.data()<<"," <<&arr[0]<< endl;



    return 0;
}

