#include<iostream>
using  namespace  std;

class  Home
{
public:
	int      mailBox;//���䡢����

	void   eat()//�Է�������
	{  }

protected:
	int   houseCard;//����֤������

	void   sleep()//˯��������
	{}

private:
	int   bankCard;//���п���˽��

	void   clean()//��������˽��
	{}


public:
	//������ڲ�����Ȩ�޶����Է���
	void  test()
	{
		//�������ֳ�Ա����
		cout << mailBox << houseCard << bankCard << endl;

		//�������ֳ�Ա����
		eat();
		sleep();
		clean(); 
	}
		 

};
 

int  main()
{
 
	//������ⲿ������Ȩ��ֻ��public���Է���
	Home   home;

	home.mailBox;//ֻ�ܷ���public�ĳ�Ա����
	home.eat();//ֻ�ܷ���public�ĳ�Ա����

	home.houseCard;//���ɷ���protected
	home.sleep();

	home.bandCard;//���ɷ���private
	home.clean();

	return 0;
}