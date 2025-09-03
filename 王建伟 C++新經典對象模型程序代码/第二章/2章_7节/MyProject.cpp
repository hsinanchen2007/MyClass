// MyProject.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//公众号：程序员速成   ，内含优质视频教程，欢迎关注

#include <iostream>
#include <time.h>

using namespace std;

class CTempValue
{
public:
	int val1;
	int val2;
public:
	CTempValue(int v1 = 0, int v2 = 0) : val1(v1), val2(v2) //构造函数
	{
	//	cout << "调用了CTempValue类的构造函数!" << endl;
	//	cout << "val1 = " << val1 << endl;
	//	cout << "val2 = " << val2 << endl;
	}
	CTempValue(const  CTempValue& t) : val1(t.val1), val2(t.val2) //拷贝构造函数
	{
	//	cout << "调用了CTempValue类的拷贝构造函数!" << endl;
	};
	virtual ~CTempValue() //析构函数
	{
	//	cout << "调用了CTempValue类的析构函数!" << endl;
	};
};
//CTempValue Double(CTempValue& ts) //第一个版本
//{
//	CTempValue tmpm; //这里会消耗我们一个构造和一个析构函数的调用
//	tmpm.val1 = ts.val1 * 2;
//	tmpm.val2 = ts.val2 * 2;
//	return tmpm;  //断点设置到这里，发现调用了拷贝构造函数和析构函数，这表示生成了临时对象
//}
CTempValue Double(CTempValue& ts) //第二个版本
{
	return CTempValue(ts.val1 * 2, ts.val2 * 2);//临时对象
}

//编译器视角
//void Double(CTempValue& tmpobj, CTempValue& ts1) //编译器会插入一个tmpobj参数
//{
//	tmpobj.CTempValue::CTempValue(ts1.val1 * 2, ts1.val2 * 2);//编译器手工调用构造函数
//	return;
//}



int main()
{
	//{
	//	CTempValue ts1(10, 20);		
	//	//Double(ts1);
	//	CTempValue ts2 = Double(ts1);

	//}

	//{
	//	CTempValue ts1;
	//	ts1.CTempValue::CTempValue(10, 20);
	//	CTempValue tmpobj;
	//	Double(tmpobj, ts1);

	//}
	

	CTempValue ts1(10, 20);
	clock_t start, end;
	start = clock(); //程序开始到本行执行时所用的毫秒数
	cout << "start = " << start << endl;
	for (int i = 0; i < 1000000; i++)
	{
		Double(ts1);
	}
	end = clock();
	cout << "end = " << end << endl;
	cout << "end - start = " << end - start << endl;


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
