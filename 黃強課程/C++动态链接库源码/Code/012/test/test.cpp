// test.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

_declspec(dllimport)    void  ShowDialog();
#pragma  comment(lib, "../Debug/012.lib")

int main()
{
	ShowDialog(); 
	getchar();

    return 0;
}

