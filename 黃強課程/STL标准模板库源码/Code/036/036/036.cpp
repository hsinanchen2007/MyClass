// 036.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<unordered_set>
using  namespace std;

template<class T>
void   Print(T  begin, T  end)
{
	//此处编写代码
	for (T p = begin; p != end; ++p)
	{
		cout << *p << "		";
	}
	cout << endl;
}


int main()
{ 
	// unordered_set 元素值唯一，无序的  集合，内部通过哈希表实现，查找效率比set高
	unordered_set<int> s = { 3,1,2,5,4,3 }; //重复元素无法插入
	 
	// 双向迭代器   bidirectional_iterator_tag
	cout << typeid(unordered_set<int>::iterator::iterator_category).name() << endl;

	//支持  ++  --  *  !=  =  ==   
	unordered_set<int>::iterator  it = s.begin();
	//*it = 111;  说明set的元素值不允许更改， 因为 元素的位置是由它的值决定，那么你改了它的元素值，会导致位置不正确

	unordered_set<int>::const_iterator  it2 = s.cbegin();//或者  s.begin()
	//*it2 = 111;


	//set  、unordered_set容器中，这两个是同一种类型
	cout << typeid(unordered_set<int>::iterator ).name() << endl;
	cout << typeid(unordered_set<int>::const_iterator).name() << endl;



	//正向遍历
	for (unordered_set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << "     ";
	}
	cout << endl;


	//没有反向遍历，因为我们说 unordered_set 是无序的，所以提供反向无意义

	//测试Print
	Print<unordered_set<int>::iterator>(s.begin(),s.end());


	return 0;
}

