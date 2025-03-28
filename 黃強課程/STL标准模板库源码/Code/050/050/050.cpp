// 050.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>
using namespace std;

int main()
{
	//copy算法可以认为内部就是一个for循环,伪代码
	template<class _InIt, class _OutIt>
	inline   _OutIt copy(_InIt _First, _InIt _Last,  	_OutIt _Dest)
	{	 
		for (it = first; it != last;   ++it,  ++ dest  )
		{
			*dest = *it;
		}
	}



	//以往将 用户输入的值放到vector中
	/*
	  vector<int>  v;
	   for(int i=0;i<3;++i)
	   {
	      int  a;
	     cin>>a;
		 v.push_back(a);
	   } 
	*/

/*
	{
	//流迭代器适配器  +   copy算法实现上述功能
	istream_iterator<int>  iit(cin);
	istream_iterator<int>  iit_end;

	vector<int>  v(3);//必须要初始化容量
	copy(iit, iit_end, v.begin()); //表示，将用户的输入拷贝到vector中
	//算法本质，  *it = *itt  ,就是赋值而已， 因为*iit 的功能就是取到用户输入的数据
	//所以，能符合这个算法的写法

	for (size_t i = 0; i < v.size(); i++)
	{
		cout << v[i] << "    ";
	}
	cout << endl;

	}
	*/


	/*
	{
		//流迭代器适配器  +   copy算法实现上述功能
		istream_iterator<int>  iit(cin);
		istream_iterator<int>  iit_end;

		vector<int>  v;//可以不用初始化容器大小了

		 back_insert_iterator<vector<int>>  bit(v);
		 //*bit = 333;//其实就是  v.push_back(333)

		//front_insert_iterator<vector<int>>  bit(v); //front_insert_iterator需要deque容器

		  copy(iit, iit_end,  bit); //表示，将用户的输入插入到vector末尾
		  //算法本质，  *bit = *itt  ,就是赋值而已， 因为 back_insert_iterator  重载=  的功能就是
		   //向容器末尾插入元素，从而将用户输入的数据插入到容器尾部
		  //所以，能符合这个算法的写法

		for (size_t i = 0; i < v.size(); i++)
		{
			cout << v[i] << "    ";
		}
		cout << endl;

	}
	*/

	{
		//如果是以前要输出一个vector中的元素

	 	vector<int> v = { 1,2,3,4,5 };
	//	for (size_t i = 0; i < v.size(); i++)
	//	{  }
	//	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	//	{ 	}

		ostream_iterator<int> oit(cout, "    ");
		//*oit = 333;//其实就是  cout<<333

		copy(v.begin(), v.end(), oit);
		//copy的本质就是    *oit =  *it ,   ostream_iterator的 = 运算符重载,   功能就是cout<<
		cout << endl;

	}



	{
		//流迭代器适配器  +   copy算法实现上述功能
		istream_iterator<int>  iit(cin);
		istream_iterator<int>  iit_end;

		//流输出迭代器
		ostream_iterator<int> oit(cout, "    ");
		copy(iit, iit_end, oit);
		//copy的本质就是    *oit  =  *iit ,   ostream_iterator的 = 运算符重载,   功能就是cout<<
	
	}






    return 0;
}

