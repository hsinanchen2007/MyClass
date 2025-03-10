// 045.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<algorithm> //算法头文件

using namespace std;

  
struct  Is3_FO
{
	bool   operator()(int x) //判断这个值是否为3
	{
		return  x == 3;
	}
};

void  Print(int  x)
{
	cout << x << "	";//任意操作
}

int   Add2(int  x)
{
	return x + 2; //返回加2后的结果
}



int main()
{
	{
		//数据都在容器中
		vector<int> v = { 1,2,3,4,5 };

		//随机打乱位置
		random_shuffle(v.begin(), v.end());
		//打印
		for_each(v.begin(), v.end(), Print);
		cout << endl; 
	}
	
	{
		//数据都在容器中
		vector<int> v = { 1,2,3,4,3,5 };

		//替换v中所有元素为3的值替换为333
		replace(v.begin(), v.end(),3,333);
		//打印
		for_each(v.begin(), v.end(), Print);
		cout << endl;
	}


	{
		//数据都在容器中
		vector<int> v = { 1,2,3,4,3,5 };

		//替换v中所有元素为Is3_FO()(x)返回true的值替换为333
		replace_if(v.begin(), v.end(), Is3_FO(), 333);
		//打印
		for_each(v.begin(), v.end(), Print);
		cout << endl;
	}


	{
		//数据都在容器中
		vector<int> v = { 1,2,3,4,3,5 };
		vector<int> v2(6);

		//与replace一样，但是不改变v的序列，只是将替换后的结果copy到 v2中
		replace_copy(v.begin(), v.end(),v2.begin(), 3,  333);
		//打印
		for_each(v.begin(), v.end(), Print);
		cout << endl;
		//打印
		for_each(v2.begin(), v2.end(), Print);
		cout << endl;
	}



	{
		vector<int>  v(5);
		//将容器v中每个元素值填充为111
		fill(v.begin(), v.end(), 111);
		//打印
		for_each(v.begin(), v.end(), Print);
		cout << endl;
	
	}


	{
		//数据都在容器中
		vector<int> v = { 1,3,2,3,4,5 }; 
		//删除所有的特定元素，但是不会改变容器的大小，只会将后面的元素往前移动，
		//并返回删除后最后一个元素的结束位置
		vector<int>::iterator  itNewEnd=remove(v.begin(), v.end(), 3); 

		//打印
		for_each(v.begin(), itNewEnd, Print);
		cout << endl;   
	}


	{
		//数据都在容器中
		vector<int> v = { 1,2,3,4,5 };
		 
		//将v中的元素反序
		 reverse(v.begin(), v.end());

		//打印
		for_each(v.begin(), v.end(), Print);
		cout << endl;
	}


	{
		//数据都在容器中
		vector<int> v = { 1,2,3,3,3,4,5,3 };

		//删除【连续相同元素】，只保留一个，但是不会改变容器的大小，只会将后面的元素往前移动，
		//并返回删除后最后一个元素的结束位置，类似remove
		vector<int>::iterator  itNewEnd =	unique(v.begin(), v.end());

		//打印
		for_each(v.begin(), itNewEnd, Print);
		cout << endl;
	}

	{
		vector<int > v = { 1,2,3,4,5 };
		vector<int>  v2(5);

		//把v中每个元素传入到 Add2中执行后拷贝到v2，有点类似于  for_each
		transform(v.begin(), v.end(), v2.begin(), Add2);

		//打印
	    for_each(v.begin(), v.end(), Print);
		cout << endl;

		//打印
		for_each(v2.begin(), v2.end(), Print);
		cout << endl;
	}
	 
	 

	return 0;
}

