
#include <stdio.h>

struct  Student
{
	int id;
	char name[20];
	int age;
};

int main()
{
	//定义Student结构体类型的变量
	struct  Student stu = { 1000,"张三",12 };

	//定义Student结构体类型的指针变量
	struct  Student* pStu = &stu;

	//有了指针，就可以通过->访问结构体成员
	printf("学号%d   姓名%s   年龄%d\n",
		pStu->id, pStu->name, pStu->age);


}
