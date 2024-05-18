#include<iostream>
using namespace  std;
 
#include"../009/009.h"
#pragma  comment(lib,  "../Debug/009.lib")

int  main()
{ 
	//Stu  s(666);
	//s.Print(); 


	//利用虚函数、接口成功使用dll中Cat类
	IAnimal  *pCat = GetCat();
	pCat->eat();
	pCat->sleep();
	DelCat(pCat);


	return 0;
}