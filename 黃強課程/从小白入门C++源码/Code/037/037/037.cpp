#include<iostream>
using  namespace  std;
 
class  A
{
public:
	A(int  a1)
	{
		a = a1;
		cout << "A�Ĵ��������캯����" << endl;
	}

	void  print()
	{
		cout << a << endl;
	}
private :
	int  a;
};


class  B: public  A
{
public:
	//���츸����Ҫ�ڳ�ʼ�������б���ʵ��
	B(int  b1, int  a1):   A(a1)
	{ 
		b = b1;
		cout << "B�Ĵ��ι��캯����" << endl;
	}

	void  print()
	{
		A::print();//��ȷ��ָ������A��print��  ������������ȡ��ͬ��
		cout << b << endl;
	}


private:
	int  b;
};


int  main()
{
 
	//���и��ף����ж��ӣ� �ȹ��츸�࣬�ٹ�������
	B  b(222,111);
	b.print();


	return 0;
}