#include<iostream>
using  namespace  std;

 
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
		// a = 100;//�����ԣ��ڳ���Ա�����У��޷��޸�

	     b = 200; //������mutable��ʹ���ڳ���Ա�����б������
		cout << b << endl;
	}
	  
private:
	    int   a;
	  mutable  int   b;//�ɱ�ģ��ױ��
};
 

int  main()
{
	B  b(111);
	b.print();

	return 0;
}