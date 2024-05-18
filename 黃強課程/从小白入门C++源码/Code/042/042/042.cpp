#include<iostream>
using namespace  std;

class  A
{
public:
	A()
	{
		a = 100;
	}
	virtual  ~A()//虚函数，用于dynamic_cast
	{ 
	}

	 int  a;
};

class B :public  A
{
public:
	B()
	{
		b = 200;
	}

	int  b;

};


int  main()
{
   // static_cast  ，和C语言强制转换相似，不安全
	float  a = 1.234f;
	int     b = static_cast<int>(a);
	cout << b << endl;

	void  * p = &a;
	float *p2 = static_cast<float*>(p);
	cout << *p2 << endl;

	//子类转换为基类
	B  bb;
	A   * pA = static_cast<A*>(&bb);
	cout << pA->a << endl;


	//基类转化为子类，强大
	A   aa;
	B  *pB= static_cast<B*>(&aa);//竟然成功了，明显不安全
	cout << pB->a << endl;
	cout << pB->b << endl;//输出乱码



	//dynamic_cast,更安全，失败返回NULL
	//子类转换为基类,与static_cast一样
	B  *pB2 = new B;
	A  *pA2 = dynamic_cast<A*>(pB2);
	cout << pA2->a << endl;

	//基类转化为子类，强大 
	A  *pA3 = new  B;
	B  *pB3 = dynamic_cast<B*>(pA3);//必须要有virtual函数
	cout << pB3->b << endl;


	//const_cast ，去除const特性
	const int  d = 111;
	const int  *pD = &d;//指向常量的指针来指向
	//*pD = 200; //因为指向的内容是常量，无法更改

	int  *pD2 = const_cast<int *>(pD);
	*pD2 = 333;
	cout << *pD2 << endl;


	//定义常对象
	const B   e;
	//e.b = 444; //错误，无法更改常对象的值
	B &e2 = const_cast<B&>(e); //必须用引用
	e2.b = 444;
	cout << e.b << endl;//改变


	//reinterpret_cast
	B  f;
	
	unsigned char * pF =  (unsigned char *) (&f )  ;//模拟一段网络接收的数据

	A  *pAA = reinterpret_cast<A*>(pF);//相当于结构体或类的还原
	B * pBB =  reinterpret_cast<B*>(pF);
	cout << pAA->a << pBB->b << endl;


	return  0;
}