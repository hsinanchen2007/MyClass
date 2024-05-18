// test.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>

//使用静态库的步骤：
//1.包含头文件
#include "../002/002.h"
//2.配置.lib文件
//方法一：  #pragma comment (lib, "../Debug/002.lib")
//方法二：右键-》属性-》配置属性-》连接器-》输入-》附加依赖项



//程序发布的时候，不需要发布.lib文件，因为已经集成到.exe文件中了

int main()
{
	int  a= sum(111,222);
	std::cout << a << std::endl;

	std::cout << c << std::endl;

    return 0;
}

