#include<iostream>
using  namespace  std;


class  A
{
public:
	A(int  a1):   a(a1)//��ʼ���б�
	{
		//a = a1;  //����д���������� const�ĳ�Ա���������ó�ʼ���б�
	}

	void  print()
	{
		//a = 200;  //��Ա�����У��޷��޸�const��Ա����
		cout << a << endl;
	}

private:
	const  int   a;//����const������Ա����
};


class  B
{
public:
	B(int  b1)  
	{
		 b = b1; 
	}

	//ϣ��print���޷��ı��κγ�Ա������ֵ�����������Ϊconst  ������Ա����
	void  print()  const
	{
		//b = 200;  ���ܽ����κ��޸ĳ�Ա������ֵ������b�����޸�
		cout << b << endl;
	}

	//��ͨ��Ա����
	void  print2()  
	{
		 b = 200;   
		cout << b << endl;
	}

private:
  int   b; 
};




 
int  main()
{
    //����Ա����
	A  a(111);
	a.print();
 
	//����Ա����
	B  b(333);
	b.print();
	b.print2();

	return 0;
}