#include<iostream>
using  namespace  std;

class Student
{
private:
	//���  ��Ա����  ��   ��Ա����
	int  num;//ѧ��
	char  name[100];//����
	char   sex;//�Ա�

public:
	//���еĳ�Ա����
	int   grade;//�꼶


	//���  ��Ա����  ��   ��Ա����
	//�Ͽ�,������ڲ�����ʵ�֣�������������
	void   GoClass()
	{
		cout << "�Ͽ�" << endl;
	}

	//�������������ڲ���������������ʵ��
	void    DoExercise();
	void    DoHomework();
};

void    Student::DoExercise()
{
	cout << "����" << endl;
}
void    Student::DoHomework()
{
	cout << "����ҵ" << endl;
}


int  main()
{
	Student   stu;//������Ķ�����ı��������ʵ��

	//�á�.��������Ĺ��г�Ա�����ͳ�Ա����
	//cout << stu.name << endl;

	stu.grade = 6;
	cout << stu.grade << endl;
	stu.GoClass();
	stu.DoHomework();

	return 0;
}