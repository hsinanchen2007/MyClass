#include<iostream>
using  namespace  std;

class  A
{
public:

	//���캯��
	A(char * str)
	{
		int len = strlen(str) + 1;
		p = new  char[len];
		memcpy(p, str, len);
	}

	void  print()
	{
		cout << p << endl;
	}


	//�Զ���Ŀ������캯��- ���
	A(const  A  &  a1)
	{
		int len = strlen(a1.p) + 1;
		p = new char[len];
		memcpy(p, a1.p, len);
	}


	char *p;//ָ����� 

};




int  main()
{
	//���ù��캯��
	A  a("hello");
	a.print();

	A   b(a);//ǳ������ ����Ĭ�ϵĿ������캯��������ֵ�������൱�� b.p= a.p;
	            //�����ʹ���Զ���Ŀ������캯�����൱�ڽ������ڴ�Ŀ���
	b.print();

	strcpy(a.p, "world");
	a.print();

	//�˿�b��p��ֵҲ���ı��ˣ��������Ǵ���
	b.print();

	 
	return 0;
}