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

	//定义一个结构体变量并初始化
	struct  Student   stu = {  10000, "zhangsan",  18  };

	//定义一个结构体指针变量
	struct  Student  * pStu = &stu;//用结构体变量的地址赋值

	//访问结构体成员    变量用 .    指针用 ->
	printf("学号：%d , 姓名： %s, 年龄：  %d\n", stu.num, stu.name, stu.age);// .操作符
	printf("学号：%d , 姓名： %s, 年龄：  %d\n", pStu->num, pStu->name, pStu->age);//  ->操作符



}

