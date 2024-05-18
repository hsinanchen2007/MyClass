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
	//定义结构体变量stu1并初始化化
	struct  Student   stu1 = {10000,   "zhangshan",  18};

	//先定义结构体变量stu2，然后再赋值
	struct  Student    stu2;
	stu2.num = 10001;//用. 来访问成员
	strcpy(stu2.name,  "lisi" );
	stu2.age = 20;


	printf("学号： %d\n",stu1.num);
	printf("姓名： %s\n", stu1.name);
	printf("年龄： %d\n", stu1.age);
}

