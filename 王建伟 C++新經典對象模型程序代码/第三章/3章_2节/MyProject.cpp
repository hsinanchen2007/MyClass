// MyProject.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//公众号：程序员速成   ，内含优质视频教程，欢迎关注

#include <iostream>
#include <time.h>

using namespace std;

class Base
{
public:
	virtual void f() 
	{
		cout << "Base::f()" << endl; 
	}
	virtual void g() 
	{ 
		cout << "Base::g()" << endl; 
	}
	virtual void h() 
	{ 
		cout << "Base::h()" << endl; 
	}
};
class Derive : public Base {
public:
	void g() 
	{
		cout << "Derive::g()" << endl; 
	}
};


int main()
{
	{
		cout << sizeof(Base) << endl;   //4字节，说明虚函数表的指针在这里的x86平台是4字节的（vptr），g++编译器是8字节
		cout << sizeof(Derive) << endl; //4字节，和Base类一个道理
		Derive* d = new Derive();       //派生类指针，其实用基类指针指向派生类也一样Base *d = new Derive();  	
		long* pvptr = (long*)d;         //指向对象d的指针转成long *型,大家注意，目前d对象里只有虚函数表指针
		long* vptr = (long*)(*pvptr);   //(*pvptr)表示pvptr指向的对象，也就是Derive对象本身。这个对象4字节，这个4字节是虚函数表地址
										//比如 *pvptr 可能等于15440724（0xeb9b54），这个其实就是虚函数表地址
										//把一个虚函数地址用(long *)一转，则本行的意思就是让vptr代表Derive对象虚函数指针，用于指向类Derive的虚函数表

		for (int i = 0; i <= 4; i++)
		{
			printf("vptr[%d] = 0x:%p\n", i, vptr[i]); //这样打印可能会打印到非法内存，但好在程序不崩溃，使我们能看到结果 
		}

		typedef void(*Func)(void); //typedef后面是定义一个函数指针，那加上typedef就代表Func是个函数指针类型，也就是它能当类型用
		//Func当类型用后就可以象下面这样
		Func f = (Func)vptr[0]; //f,g,h就是 函数指针变量  vptr[0]指向第一个虚函数{project4.exe!Base::f(void)}	
		Func g = (Func)vptr[1]; //vptr[1]指向第二个虚函数{project4.exe!Derive::g(void)}
		Func h = (Func)vptr[2]; //vptr[2]指向第三个虚函数{project4.exe!Base::h(void)}
		Func i = (Func)vptr[3]; //vptr[3]
		Func j = (Func)vptr[4]; //vptr[4]
		f();                    //base::f
		g();                    //derive::g   子类覆盖父类的虚函数
		h();                    //base::h
	//	i();                    //运行异常
	//	j();                    //运行异常

		//---------------------------
		Base* dpar = new Base();
		long* pvptrpar = (long*)dpar;
		long* vptrpar = (long*)(*pvptrpar);
		for (int i = 0; i <= 4; i++)
		{
			printf("vptr_Base [%d] = 0x:%p\n", i, vptrpar[i]); //这样打印可能会打印到非法内存，但好在程序不崩溃
		}
		Func fpar = (Func)vptrpar[0];     //project4.exe!Base::f(void)}
		Func gpar = (Func)vptrpar[1];     //project4.exe!Base::g(void)}
		Func hpar = (Func)vptrpar[2];     //project4.exe!Base::h(void)}
		Func ipar = (Func)vptrpar[3];     
		Func jpar = (Func)vptrpar[4];    
		fpar();                           //base::f
		gpar();                           //base::g  
		hpar();                           //base::h
	//	ipar();                           //运行异常
	//	jpar();                           //运行异常

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
