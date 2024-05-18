#include<iostream>
using namespace std;

template<typename  T>
class A
{
public:
	static  int   s;//不依赖模版类型T的静态成员
	static   T    s2; //依赖模版类型T的静态成员  
};
 
//1.模板类的静态成员变量初始化,  对任意类型T的都有一份通用的值
template<typename T>int  A<T>::s = 111;  
//2.特化的方式，只有该类型可以获取此值
template <>int  A<int>::s = 222;//也可以特化，给出T类型, 只对T是int生效
//s2只能特化
template <>float  A<float>::s2 = 333.33f;
template <>char  A<char>::s2 = 'A';

template <>int  A<int>::s2 = 666;

void main()
{
	//对任意类型T的s都有一份通用的值111
	cout << A<float>::s << endl;
	cout << A<int>::s << endl;
	cout << A<char>::s << endl;
	cout << A<double>::s << endl;


	//特定类型，s2特定值
	cout << A<float>::s2 << endl;
    cout << A<int>::s2 << endl;
    cout << A<char>::s2 << endl;
	//cout << A<double>::s2 << endl;//必须特化，不然找不到s2
}