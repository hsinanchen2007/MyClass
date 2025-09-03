// MyProject.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//公众号：程序员速成   ，内含优质视频教程，欢迎关注

#include <iostream>
#include <time.h>

using namespace std;

int* ptest = new int(120);
int g1;
int g2;

int g3 = 12;
int g4 = 32;
int g5;
int g6 = 0;
static int g7;
static int g8 = 0;
static int g9 = 10;
void mygfunc()
{
	return;
}
//定义一个类
class MYACLS
{
public:
	int m_i;
	static int m_si; //这是声明不是定义
	int m_j;
	static int m_sj;
	int m_k;
	static int m_sk;
};
int MYACLS::m_sj = 12; //这才是定义


int main()
{
	{
		int e_mytest;  //该变量在程序运行时临时放在栈中
		e_mytest = 9;
	}

	{		
		printf("ptest地址=%p\n", &ptest);
		printf("g1地址=%p\n", &g1);
		printf("g2地址=%p\n", &g2);
		printf("g3地址=%p\n", &g3);
		printf("g4地址=%p\n", &g4);
		printf("g5地址=%p\n", &g5);
		printf("g6地址=%p\n", &g6);
		printf("g7地址=%p\n", &g7);
		printf("g8地址=%p\n", &g8);
		printf("g9地址=%p\n", &g9);
		printf("MYACLS::m_sj地址=%p\n", &(MYACLS::m_sj));
		printf("mygfunc()地址=%p\n", mygfunc);
		printf("main()地址=%p\n", main);

		int i = 7;
		printf("i地址=%p\n", &i);
		

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
