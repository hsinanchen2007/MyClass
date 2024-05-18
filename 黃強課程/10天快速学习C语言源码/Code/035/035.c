
#include <stdio.h>

struct  Student
{
	int id;
	char name[20];
	int age;
};//学生结构体类型


int main()
{
	//定义结构体数组，并且初始2个值
	struct  Student  stus[3] =
	{
		{1000,"张三",12},
		{1001,"李四",14}
	};

	//给第3个结构体赋值
	stus[2].id = 1002;
	strcpy( stus[2].name , "王五");
	stus[2].age = 13;

	//打印结构体数组
	for ( int  i = 0; i < 3; i++)
	{
		printf("学号  %d     姓名 %s    年龄 %d\n", 
			stus[i].id, stus[i].name, stus[i].age);
	}
}
