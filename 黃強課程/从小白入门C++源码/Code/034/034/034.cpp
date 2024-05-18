#include<iostream>
using namespace std;

static  int   a = 100;//1. 限定全局变量只能在本文件使用

static  void fun()//2. 限定函数只能在本文件使用
{
	cout << "fun" << endl;
}