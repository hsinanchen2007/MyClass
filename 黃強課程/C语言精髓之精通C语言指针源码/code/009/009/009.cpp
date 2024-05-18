#include<iostream>
# include <memory> 
# include <string> 
using namespace  std;
 
template  <class T>
class SmartPointer
{
public :
	SmartPointer(T  *p)
	{
		ptr = p; 
	}

	~SmartPointer()
	{
		delete ptr;//自动删除内存，防止泄露
		ptr = NULL; //自动置空，防止野指针
	}

	//重载*运算符
	T & operator *()
	{
		return  *ptr;
	}

	//重载->运算符
	 T *  operator ->()
	{
		return  ptr;
	} 


private:
	T  *  ptr;
};

void main()
{  /*
   //自己实现的智能指针
	SmartPointer<int>  sp(new int(333));
    
	//获取指针的内容
	int  a = *sp; 
	cout << a << endl;
 
   
	SmartPointer<string>  sp2( new string("hello"));
	cout<<sp2->at(1)<<endl;


	//auto指针，已经废弃
	int  *p = new int(4);
	auto_ptr<int>  ap(p);
	cout << *ap << endl;

	auto_ptr<int>  ap2(p);
	cout << *ap2 << endl;
	 

	//独享型智能指针
	unique_ptr<int[]>  p(new int[5]{ 1, 2, 3, 4, 5 });
	cout << p[2] << endl;

	unique_ptr<int[]>  p2 =move(p);//无法拷贝，赋值，因为是独享的，只能move
	cout << p2[4] << "   " << (p == nullptr) << endl;//如果转移所有权，那么自己变成空
	*/


	//共享型智能指针
	shared_ptr<int> sp(new int(10));
	cout << sp.use_count() << endl;  //引用计数
	 
	weak_ptr <int>  wp = sp;//配合shared_ptr的工作
	cout << sp.use_count() << endl;//weak_ptr不占用资源



	shared_ptr<int> sp2 = sp;  //第二个shared_ptr,拷贝构造函数    
	cout << (sp == sp2) << "    " << wp.use_count() << endl;

	*sp2 = 100; //使用解引用操作符修改被指对象    
	cout << *sp << endl; //另一个shared_ptr也同时被修改  

	sp.reset();//释放
	cout << (sp == nullptr) << "    " << wp.use_count() << endl;

}
