#include<iostream>
using  namespace  std;


class  A
{
public:
	A()
	{
		++count;//ÿ����һ���������ü�����1
	}

	void print()
	{
		cout << "��ʱ��������" << count << "������" << endl;
	}

	//��̬��Ա����
	static  void print2()
	{
		//��̬��Ա�����޷�����  �Ǿ�̬��Ա����
		//cout << a << endl;//����

		cout <<"��̬��Ա������"<< count << endl;//���ʾ�̬��Ա�����뾲̬��Ա����
	}

public:
	static  int  count;//ͳ���ж��ٸ�����,��̬��Ա�������еĶ�����ֻ��һ���ڴ�ռ�
	int   a;
};

//��̬��Ա����ֻ���������ʼ�������Ҽ���A::ǰ׺
int    A::count = 0;


int  main()
{
	A  a;
	a.print();

	A   b;
	a.print();
	b.print();

	A  c;
	a.print();
	b.print();
	b.print();


	//���ַ��ʹ��о�̬��Ա�����ķ�ʽ   A::     ����.
	cout << A::count << endl;
	cout << a.count << endl;

	//���ַ��ʹ��о�̬��Ա�����ķ�ʽ   A::     ����.
	A::print2();
	a.print2();

	return 0;
}