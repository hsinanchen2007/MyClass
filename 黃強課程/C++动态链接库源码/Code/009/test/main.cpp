#include<iostream>
using namespace  std;
 
#include"../009/009.h"
#pragma  comment(lib,  "../Debug/009.lib")

int  main()
{ 
	//Stu  s(666);
	//s.Print(); 


	//�����麯�����ӿڳɹ�ʹ��dll��Cat��
	IAnimal  *pCat = GetCat();
	pCat->eat();
	pCat->sleep();
	DelCat(pCat);


	return 0;
}