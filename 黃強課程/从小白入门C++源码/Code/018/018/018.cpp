#include<iostream>
using  namespace  std;


class  Student
{
public:
	int  age;//����

	void  ListenClass()
	{
		cout << "���Σ�" << endl;
	}  
};


int  main()
{
	Student   stu;//����һ����Ķ���

	//������ .   ���ʹ��г�Ա�������Ա����
	stu.age = 18;
	stu.ListenClass();

	//������ָ��
	Student  *  pStu = &stu;//��ֵΪ����������󣩵ĵ�ַ

	//����ָ���� ->  ���ʹ��г�Ա�������Ա����
	cout << pStu->age << endl;
	pStu->ListenClass();

	 
	return 0;
}