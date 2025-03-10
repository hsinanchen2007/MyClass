#include "stdafx.h"

#include<iostream>
#include<array>
using namespace  std;


//迭代器课程中写的，当时支持了数组，链表
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
	//定义array对象初始化元素值
	array<int, 5>  arr = { 1,2,3 ,4,5}; 
	 
	//array<int, 5>容器 对应的迭代器类型是  array<int, 5>::iterator
	
	using  ArrayIterator =array<int, 5>::iterator;

	  //ArrayIterator::value_type   迭代器所指的元素的类型
	  //ArrayIterator::iterator_category   迭代器的五种类型之一类型
	 // ArrayIterator::difference_type   两个迭代器相减得到的值的类型
	//ArrayIterator::pointer  迭代器所指的元素的指针类型
	//ArrayIterator::reference  迭代器所指的元素的引用类型

	cout << typeid(ArrayIterator::iterator_category).name() << endl;
	//得出结论：  array的迭代器类型是  random_access_iterator
	//随机访问迭代器支持 ++  、-- 、[]  、+=、   - 、    +n、    >、   < 、 !=、   *
  
	//ArrayIterator  begin(arr);//迭代器类的对象
	//ArrayIterator  end(arr+5);//迭代器类的对象
	//Print<ArrayIterator>( begin , end); 自己实现的时候

	/*STL的实现原理与我们之前自己写的例子类似*/
	array<int, 5>::iterator begin = arr.begin();
	array<int, 5>::iterator end = arr.end();
	Print<array<int, 5>::iterator>(begin, end);
	//Print<array<int, 5>::iterator>(arr.begin(),arr.end());//简写


	//下面演示随机访问迭代器的操作
	// +n
	array<int, 5>::iterator  it1 = arr.begin()+3; //往后移3个单位
	cout << *it1 << endl;

	//++
	it1++;
   cout << *it1 << endl;

   // --   
   --it1; 
   --it1;
   cout << *it1 << endl;

   //[] ,相当于当前位置+1
   cout <<it1[1] << endl;

   // -=
   it1 -= 2;
   cout << *it1 << endl;

   //可以修改array<int, 5>::iterator指向元素的值
   *it1 = 111;
   Print<array<int, 5>::iterator>(begin, end);



   //cbegin返回容器中第一个元素的位置的迭代器，但是这个迭代器是只读的
   array<int, 5>::const_iterator  cit = arr.cbegin();
   cout << typeid(array<int, 5>::const_iterator::iterator_category).name() << endl;
   cout << *cit << endl;//只读
   // *cit = 111; //不可修改的


   //Print中没有修改元素的操作，所以没问题
   Print<array<int, 5>::const_iterator>(arr.cbegin(), arr.cend());


   //rbegin返回容器中最后一个元素的位置的迭代器
   array<int, 5>::reverse_iterator  it3 = arr.rbegin();
   cout << *it3 << endl;

   Print<array<int, 5>::reverse_iterator>(arr.rbegin(), arr.rend());
   Print(arr.rbegin(), arr.rend());//模板自动推导



	return 0;
}

