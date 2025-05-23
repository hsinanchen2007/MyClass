// 044.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<algorithm> //算法头文件

using namespace std;


bool   Is3(int x) //判断这个值是否为3
{
	return  x == 3;
}

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



int main()
{
	//数据都在容器中
	vector<int> v = {1,2,3,4,5};


	{	//查找 , 算法不能直接操作容器，它通过桥梁（容器迭代器来操作容器）
	    //vector<int>::iterator  it=find< vector<int>::iterator, int>(v.begin(), v.end(), 3);
		vector<int>::iterator  it = find(v.begin(), v.end(), 3);//类型自动推导
		if (it != v.end()) //如果没有找到，返回end() 
		{
			cout << "找到了" << *it << endl;
		}
		else
		{
			cout << "没找到！" << endl;
		}
	}


	{
	//与find类似，只不需要一元函数（或一元函数对象）对象返回为true时候就是找到了
    //find_if 会依次将 元素值放入  Is3中去检查，结果返回true时，认为找到了
	//vector<int>::iterator  it =find_if(v.begin(), v.end(), Is3);  //普通函数指针
	 vector<int>::iterator  it = find_if(v.begin(), v.end(), Is3_FO() ); //函数对象
	if (it != v.end()) //如果没有找到，返回end() 
	{
		cout << "找到了" << *it << endl;
	}
	else
	{
		cout << "没找到！" << endl;
	}
	}

	{
		//查找到  2,3中的任何一个值就认为查找到了
		vector<int>  v2 = { 99,88}; //作为查找值
		vector<int>::iterator  it =find_first_of(v.begin(), v.end(), v2.begin(), v2.end());
		if (it != v.end()) //如果没有找到，返回end() 
		{
			cout << "找到了" << *it << endl;
		}
		else
		{
			cout << "没找到！" << endl;
		}
	
	}


	{
		//将每个元素依次作为参数传入到 一元函数Print中执行
		for_each(v.begin(), v.end(), Print);//传入函数指针 
		cout << endl;
	}


	{
		vector<int>  v2 = { 1,2,2,2,2,3,4,5 };  
		//统计一个元素出现的次数
		cout << "2出现的次数" << count(v2.begin(), v2.end(), 2) << endl;;
	
	}
	
	{
		vector<int>  v2 = { 1,2,2,2,2,3,4,5 };
		//统计一个元素出现的次数
		cout << "3出现的次数" << count_if(v2.begin(), v2.end(), Is3  ) << endl;;
	}


	{
		//在容器序列中，查找一段子序列    12345，  比如 12 、234就是一个子序列
		vector<int>  v2 = {  2,3,4 };
		vector<int>::iterator  it=search(v.begin(), v.end(), v2.begin(), v2.end());
		if (it != v.end()) //如果没有找到，返回end() 
		{
			cout << "找到了" << *it << endl;
		}
		else
		{
			cout << "没找到！" << endl;
		}
	}



	{
		vector<int>  v2 = { 1,2,3,4,4,4,5,6 };

		//在v2中查找3个连续的元素4
		vector<int>::iterator  it = search_n(v2.begin(), v2.end(), 3, 4);  
		if (it != v2.end()) //如果没有找到，返回end() 
		{
			cout << "找到了" << *it << endl;
		}
		else
		{
			cout << "没找到！" << endl;
		}
	}


    return 0;
}

