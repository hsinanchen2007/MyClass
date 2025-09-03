// MyProject.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//公众号：程序员速成   ，内含优质视频教程，欢迎关注

#include <iostream>
class A
{
public:
	void func() {};
	void func1() {};
	void func2() {};

	int ab;
};

int main()
{
	{
		std::cout << "Hello World!\n";
		printf("很高兴我们大家一起学习!\n");
		printf("35+48的值是%d\n", 35 + 48);
	}

	{
		//char aaa[1000] = "safasdfa\0def";
		//printf(aaa);

	}
	//{
	//	A a;
	//	//sizeof()：返回一个对象所占的字节数字
	//	int ilen = sizeof(a); //等价于sizeof(A)，结果为1
	//	printf("ilen = %d\n", ilen); //ilen = 1
	//}
	//{
	//	A a;	
	//	int ilen = sizeof(a); 	
	//	a.ab = 'c';
	//	printf("ilen = %d\n", ilen); //ilen = 1
	//}
	{
		A a;		
		int ilen = sizeof(a);
		a.ab = 12;
		printf("ilen = %d\n", ilen);
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
