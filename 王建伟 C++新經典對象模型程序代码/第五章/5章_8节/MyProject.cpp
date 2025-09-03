// MyProject.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//公众号：程序员速成   ，内含优质视频教程，欢迎关注

#include <iostream>
#include <time.h>
#include <cstdio>

using namespace std;

class Base
{
public:
	virtual void f() { cout << "Base::f()" << endl; }
	virtual void g() { cout << "Base::g()" << endl; }
	virtual void h() { cout << "Base::h()" << endl; }
	virtual ~Base() {}
};
class Derive : public Base {
public:
	virtual void g() { cout << "Derive::g()" << endl; }
	void myselffunc() {} //只属于Derive的函数
	virtual ~Derive() {}
};


int main()
{	
	//{
	//	Base* pb = new Derive();  //基类指针指向一个子类对象
	//	pb->g();

	//	Derive myderive;
	//	Base& yb = myderive;  //基类引用引用的是一个子类对象
	//	yb.g();

	//	cout << typeid(*pb).name() << endl;
	//	cout << typeid(yb).name() << endl;


	//	Derive* pderive = dynamic_cast<Derive*>(pb);
	//	if (pderive != NULL)
	//	{
	//		cout << "pb指向的实际是一个Derive类型" << endl;
	//		pderive->myselffunc(); //调用属于子类自己的函数
	//	}
	//	const std::type_info& tp = typeid(*pb);
	//	
	//	Base* pb2 = new Derive();
	//	const std::type_info& tp2 = typeid(*pb2);
	//	if (tp == tp2) //条件成立
	//	{
	//		cout << "很好，类型相同" << endl; 
	//	}
	//	cout << "断点设置在这里" << endl;
	//}
	//{
	//	cout << typeid(int).name() << endl;
	//	cout << typeid(Base).name() << endl;
	//	cout << typeid(Derive).name() << endl;
	//	Derive* pa3 = new Derive();
	//	cout << typeid(pa3).name() << endl;
	//}
	{
		Base* pb = new Derive();
		Derive myderive;
		Base& yb = myderive;
		cout << typeid(*pb).name() << endl;  //class Derive
		cout << typeid(yb).name() << endl; //class Derive
		Base* pb2 = new Derive();
		const std::type_info& tp2 = typeid(*pb2);
		cout << tp2.name() << endl;

		//---------------------------------------
		printf("tp2地址为 :%p\n", &tp2);

		long* pvptr = (long*)pb2;         //指向对象pb2的指针转成long *型,大家注意，目前pb2对象里只有虚函数表指针
		long* vptr = (long*)(*pvptr);     //指向虚函数表(虚函数表首地址)

		printf("虚函数表首地址为:%p\n", vptr);
		printf("虚函数表首地址之前一个地址为:%p\n", vptr - 1); //注意，long在当前这个环境是4字节，所以vptr-1,其实得到的地址是往回走了4个地址

		//取得这个地址中的内容
		long* prttiiinfo = (long*)(*(vptr - 1));
		prttiiinfo += 3; //跳过12个字节
		long* ptypeinfoaddr = (long*)(*prttiiinfo);
		const std::type_info* ptypeinfoaddrreal = (const std::type_info*)ptypeinfoaddr;
		printf("ptypeinfoaddrreal地址为 :%p\n", ptypeinfoaddrreal);
		cout << ptypeinfoaddrreal->name() << endl;  //结果class Derive

		cout << typeid(int).name() << endl; //输出int
	}
 	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
