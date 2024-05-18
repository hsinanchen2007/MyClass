#include<iostream>
using  namespace  std;

class Student
{
private:
	//类的  成员变量  或   成员属性
	int  num;//学号
	char  name[100];//姓名
	char   sex;//性别

public:
	//公有的成员变量
	int   grade;//年级


	//类的  成员函数  或   成员方法
	//上课,在类的内部定义实现，属于内联函数
	void   GoClass()
	{
		cout << "上课" << endl;
	}

	//做锻炼，在类内部仅声明，在类外实现
	void    DoExercise();
	void    DoHomework();
};

void    Student::DoExercise()
{
	cout << "锻炼" << endl;
}
void    Student::DoHomework()
{
	cout << "做作业" << endl;
}


int  main()
{
	Student   stu;//定义类的对象、类的变量、类的实例

	//用“.”访问类的公有成员变量和成员函数
	//cout << stu.name << endl;

	stu.grade = 6;
	cout << stu.grade << endl;
	stu.GoClass();
	stu.DoHomework();

	return 0;
}