#include<iostream>
using namespace  std;

class  A
{
private:
	int   a1;
protected:
	int  a2;
public: 
	int  a3;
};


//���м̳�  public
class B :public  A
{
public:
	B()
	{
	   //��������ڲ����Է�����Щ
		//a1 = 100; //���ɷ��ʸ����˽�г�Ա, ���ɼ�
		a2 = 200;//�ɷ��ʸ���ı�����Ա�� �˿����������б���Ϊprotected
		a3 = 300;//�ɷ��ʸ���Ĺ��г�Ա ,  �˿����������б���Ϊpublic 
	}

};

int  main()
{
	//��������Ķ����ܷ����
	B  b;
	//b.a1=100;//���ɼ�
	//b.a2=200;//���������б���Ϊprotected�� �����޷�����
	b.a3 = 300;//���������б���Ϊpublic ,������Է���

	return 0;
}