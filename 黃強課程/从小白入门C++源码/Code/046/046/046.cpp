#include<iostream>
using namespace  std;

class  A
{
private:
	int   a1;//˽��
protected:
	int  a2;//����
public:
	int  a3;//����
};


//˽�м̳�  private
class B : private   A
{
public:
	B()
	{
		//��������ڲ����Է�����Щ
		//a1 = 100; //���ɷ��ʸ����˽�г�Ա, ���ɼ�
		a2 = 200;//�ɷ��ʸ���ı�����Ա�� �˿����������б���Ϊprivate
		a3 = 300;//�ɷ��ʸ���Ĺ��г�Ա ,  �˿����������б���Ϊprivate 
	}

};

int  main()
{
	//��������Ķ����ܷ����
	B  b;
	//b.a1=100;//���ɼ�
	//b.a2=200; //���������б���Ϊprivate�� �����޷�����
	//b.a3 = 300;//���������б���Ϊprivate ,�����޷�����

	return 0;
}