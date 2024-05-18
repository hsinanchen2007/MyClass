#include<stdio.h> //系统头文件，包含了printf,scanf等系统函数的声明
#include<string.h> //系统头文件，包含了strcpy , strlen等系统函数的声明


//定义一个学生结构体类型
struct   Student
{
	int  num;//学号
	char name[20];//姓名
	int   age;//年龄 
};


void  main()//系统主函数，整个程序的入口函数，这个是它的简写
{

	//定义结构体数组并初始化,数组的每个元素都是一个结构体
	struct   Student   stus1[3] =
	{
		{ 10000, "zhangshan", 18},
		{ 10001, "lisi", 19 },
		{ 10002, "zhaowu", 20 }
	};

	//先定义，再赋值
	struct   Student   stus2[3]; 
	//第一个元素的赋值
	stus2[0].num = 20001;
	strcpy(stus2[0].name, "sunliu");
	stus2[0].age = 31; 
	//第二个元素的赋值
	stus2[1].num = 20002;
	strcpy(stus2[1].name, "huangwu");
	stus2[1].age = 32; 
	//第三个元素的赋值
	stus2[2].num = 20003;
	strcpy(stus2[2].name, "xiaoqi");
	stus2[2].age = 33;



	for (int i = 0; i < 3; ++i)
	{
		//每个数组元素都是一个结构体
		struct  Student tmp = stus1[i]; 
		printf("学号：%d   姓名: %s    年龄:%d  \n", tmp.num, tmp.name, tmp.age);
	}


}

