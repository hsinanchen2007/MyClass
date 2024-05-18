#include<iostream>
using namespace  std;

class  A
{
public:
	A()
	{
		a = 100;
	}
	virtual  ~A()//�麯��������dynamic_cast
	{ 
	}

	 int  a;
};

class B :public  A
{
public:
	B()
	{
		b = 200;
	}

	int  b;

};


int  main()
{
   // static_cast  ����C����ǿ��ת�����ƣ�����ȫ
	float  a = 1.234f;
	int     b = static_cast<int>(a);
	cout << b << endl;

	void  * p = &a;
	float *p2 = static_cast<float*>(p);
	cout << *p2 << endl;

	//����ת��Ϊ����
	B  bb;
	A   * pA = static_cast<A*>(&bb);
	cout << pA->a << endl;


	//����ת��Ϊ���࣬ǿ��
	A   aa;
	B  *pB= static_cast<B*>(&aa);//��Ȼ�ɹ��ˣ����Բ���ȫ
	cout << pB->a << endl;
	cout << pB->b << endl;//�������



	//dynamic_cast,����ȫ��ʧ�ܷ���NULL
	//����ת��Ϊ����,��static_castһ��
	B  *pB2 = new B;
	A  *pA2 = dynamic_cast<A*>(pB2);
	cout << pA2->a << endl;

	//����ת��Ϊ���࣬ǿ�� 
	A  *pA3 = new  B;
	B  *pB3 = dynamic_cast<B*>(pA3);//����Ҫ��virtual����
	cout << pB3->b << endl;


	//const_cast ��ȥ��const����
	const int  d = 111;
	const int  *pD = &d;//ָ������ָ����ָ��
	//*pD = 200; //��Ϊָ��������ǳ������޷�����

	int  *pD2 = const_cast<int *>(pD);
	*pD2 = 333;
	cout << *pD2 << endl;


	//���峣����
	const B   e;
	//e.b = 444; //�����޷����ĳ������ֵ
	B &e2 = const_cast<B&>(e); //����������
	e2.b = 444;
	cout << e.b << endl;//�ı�


	//reinterpret_cast
	B  f;
	
	unsigned char * pF =  (unsigned char *) (&f )  ;//ģ��һ��������յ�����

	A  *pAA = reinterpret_cast<A*>(pF);//�൱�ڽṹ�����Ļ�ԭ
	B * pBB =  reinterpret_cast<B*>(pF);
	cout << pAA->a << pBB->b << endl;


	return  0;
}