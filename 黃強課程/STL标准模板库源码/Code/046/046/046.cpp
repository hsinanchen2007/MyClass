// 046.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<algorithm> //算法头文件

using namespace std;


struct  Is2Or3
{
	bool   operator()(int x) //判断这个值是否为3
	{
		return  x == 3 ||  x==2;
	}
};

bool   MyGreater(int a  ,  int b)  
{
		return   a>b;
}


class  A
{
public:
	A(int _a, int _b) :a(_a), b(_b) {}
	int   a;
	int  b;
};

bool   MyGreaterA(A a, A b)
{
	return   a.a>b.a;
}

void  PrintA(A  a)
{
	cout << a.a<<"-"<<a.b << "	";//任意操作
}


void  Print(int  x)
{
	cout << x << "	";//任意操作
} 

int main()
{
	{
		//数据都在容器中
		vector<int> v = { 1,2,3,4,5 };
 
		//分区域，  满足仿函数结果为true放到前面，为false的放到后面
		vector<int>::iterator  itMid=partition(v.begin(), v.end(), Is2Or3());

		//打印
		for_each(v.begin(), itMid, Print);
		cout << endl;

		//打印
		for_each(itMid, v.end(), Print);
		cout << endl;
	}
	 
	{
		//数据都在容器中
		vector<int> v = { 1,2,3,4,5 };

		//分区域，  满足仿函数结果为true放到前面，为false的放到后面
		//保留元素原有的先后顺序
		vector<int>::iterator  itMid = stable_partition(v.begin(), v.end(), Is2Or3());

		//打印
		for_each(v.begin(), itMid, Print);
		cout << endl;

		//打印
		for_each(itMid, v.end(), Print);
		cout << endl;
	}


	{
		//数据都在容器中
		vector<int> v = { 1,2,3,4,5 };

		//排序，默认升序
		 //sort(v.begin(), v.end()  );
		
		 //降序
		//sort(v.begin(), v.end(),greater<int>()); //使用STL预定义的函数对象
		 sort(v.begin(), v.end(), MyGreater); //使用普通函数指针

		//打印
		for_each(v.begin(),   v.end(), Print);
		cout << endl;
	}



	{

		//数据都在容器中
		vector<A> v = {A(1,111) ,A(3,330), A(4,444) , A(3,332) , A(2,222)  ,  A(3,331) };
		 
		//降序,保证相同元素值的原有顺序
		stable_sort(v.begin(), v.end(), MyGreaterA); 

	     //打印
		for_each(v.begin(), v.end(), PrintA);
		cout << endl;
	}



	{

		//数据都在容器中
		vector<int> v = {  99, 59, 60 ,23, 89,45,66  };

		//想知道所有成绩最高的前三名，不关心后面的成绩顺序
		partial_sort(v.begin(),  v.begin()+3,   v.end() ,greater<int>() );

		//打印
		for_each(v.begin(), v.end(), Print);
		cout << endl;
	}


	{ 
		//数据都在容器中
		vector<int> v = { 99, 59, 60 ,23, 89,45,66 };

		//把第n大的元素排到第n个位置，不关心其它元素
		 nth_element(v.begin(), v.begin() + 4, v.end());

		//打印
		for_each(v.begin(), v.end(), Print);
		cout << endl;
	}


	return 0;
}

