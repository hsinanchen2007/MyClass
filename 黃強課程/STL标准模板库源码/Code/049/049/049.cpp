// 049.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<deque>
#include<iterator> //迭代器及其适配器头文件

using namespace  std;

int main()
{
	
 {
	vector<int>  v = { 1,2,3,4,5 };
	//迭代器适配器 ，实现反向
	reverse_iterator< vector<int>::iterator  >   rit(v.end());
	cout << *rit << endl;
	++rit;// 普通迭代器的操作，实现了反向遍历 
	cout << *rit << endl;


	//这就是迭代器适配器的运用例子
	//源码中就是using reverse_iterator = _STD reverse_iterator<iterator>;
	/*
		reverse_iterator rbegin() _NOEXCEPT
		{	// return iterator for beginning of reversed mutable sequence
		return (reverse_iterator(end()));
		}
	*/
	for (vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); it++)
	{
		cout << *it << "   ";
	}
	cout << endl;

}

 {
	 //适配器类，接口是迭代器， 功能实现头部插入功能
	//用户像使用迭代器一样的插入元素，容器必须有push_front成员方法
	// vector<int>  v = { 1,2,3,4,5 }; //无push_front
	 deque<int>  d = { 1,2,3,4,5 };
	 front_insert_iterator<deque<int>>  fit(d);

	 *fit = 111;//在头部插入一个111，看起来很简洁，并且也符合逻辑，给头部赋值，自然就是插入了
	 //在以往的理解中， *fit=111,表示  fit指向元素值改为111，在这里实际上是新的含义

	 for (deque<int>::iterator it = d.begin(); it != d.end(); ++it)
	 {
		 cout << *it << "   ";
	 }
	 cout << endl;
 }




 {
	 //适配器类，接口是迭代器， 功能实现尾部插入功能
	 //用户像使用迭代器一样的在尾部插入元素，容器必须有push_back成员方法
	 vector<int>  v= { 1,2,3,4,5 }; //有push_back
	 //deque<int>  d = { 1,2,3,4,5 };//有push_back
	  back_insert_iterator<vector<int>>  fit(v);

	 *fit = 111;//在尾部插入一个111，看起来很简洁，并且也符合逻辑，给尾部赋值，自然就是插入了
				//在以往的理解中， *fit=111,表示  fit指向元素值改为111，在这里实际上是新的含义

	 for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
	 {
		 cout << *it << "   ";
	 }
	 cout << endl;
 }




 {
	 //适配器类，接口是迭代器， 功能实现在指定位置插入功能
	 //用户像使用迭代器一样的插入元素，容器必须有insert成员方法
	 vector<int>  v = { 1,2,3,4,5 }; //有insert 
	 //deque<int>  d = { 1,2,3,4,5 };//有insert
	 insert_iterator<vector<int>>  fit(v, v.begin()+ 2);

	 *fit = 111;//在第2个元素后插入一个111，看起来很简洁，并且也符合逻辑
				//在以往的理解中， *fit=111,表示  fit指向元素值改为111，在这里实际上是新的含义

	 for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
	 {
		 cout << *it << "   ";
	 }
	 cout << endl;
 }


 {
     //以前输入元素时,用户会这样写
	// int   a;
	// cin >> a;
	// cout << a << endl;
 
	 //现在遇到了一个特别喜爱使用迭代器的用户，
	 //它希望像使用迭代器一样的输入，输出变量
      //提供一个适配器，接口就是迭代器的接口，内部实现依然用cin   cout
	 istream_iterator<int >   itEnd;//表示输入结束

	 istream_iterator<int >   it(std::cin);//可以开始输入了，按下Ctrl+z表示结束输入

	 int  num1 = *it;//获取第一个输入的值,新的含义，解释为获取用户输入的内容
	 ++it; //移动到下个位置
	 int  num2 = *it;//获取输入的第二个值

	 cout << num1 << endl;
	 cout << num2 << endl;

	 ++it; //移动到下个位置

	 if (it == itEnd) cout << "已经没输入了！" << endl;
	   
 }
 cout << "---------------------------------------------------" << endl;

 {
	 ostream_iterator<int >   it(std::cout, "\n");//内部调用cout
	 *it = 111;//等价于  cout<<111<<"\n"
	 *it = 222;//等价于  cout<<222<<"\n" 
 }

    return 0;
}

