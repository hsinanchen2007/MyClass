#include<iostream>
using namespace  std;

/*
//多重继承方式一
class  A
{
public:
	A( )
	{
		cout << "A构造函数！" << endl; 
	} 
	~A()
	{
		cout << "A析构函数！" << endl;
	}
}; 

class  B: public  A
{
public:
	B( )
	{
		cout << "B构造函数！" << endl; 
	} 
	~B()
	{
		cout << "B析构函数！" << endl;
	}
};

class  C : public  B
{
public: 
	C( ) 
	{
		cout << "C构造函数！" << endl; 
	} 
	~C()
	{
		cout << "C析构函数！" << endl;
	}
};
*/



//多重继承方式二
class  A
{
public:
	A()
	{
		cout << "A构造函数！" << endl;
	}
	~A()
	{
		cout << "A析构函数！" << endl;
	}
};

class  B  
{
public:
	B()
	{
		cout << "B构造函数！" << endl;
	}
	~B()
	{
		cout << "B析构函数！" << endl;
	}
};

class  C : public  A , public  B //按继承顺序来
{
public:
	C()
	{
		cout << "C构造函数！" << endl;
	}
	~C()
	{
		cout << "C析构函数！" << endl;
	}
};


int  main()
{
	//不论哪种方式，析构函数的顺序总与构造顺序相反
	C   c ;
	 

	return  0;
}