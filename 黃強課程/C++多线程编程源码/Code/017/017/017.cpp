#include<iostream>
#include<thread>

using  namespace  std;
 
void   ThreadFun(string   &str);

int main()
{
	//Ĭ�Ϲ��캯��
	thread  t1;
	cout << t1.get_id()<<endl;//�߳�IDΪ0
	cout << t1.joinable() << endl;//Ϊ0,��ʾ�����Ա�join

	//ʹ�ô������Ĺ��캯�� 
	thread  t2(ThreadFun,  string("hello"));
	cout << t2.get_id() << endl;//
	cout << t2.joinable() << endl;//

	//thread����������֮ǰ�������join�����������ֹ������detach
	//t2.join();//join�ȴ����߳�ִ����ϣ�������waitforsingleobject������
	t2.detach(); //�뵱ǰ�̶߳�����룬��Ϊ�¶��߳�

	return 0;
}


void   ThreadFun(string   &str)
{
	cout << str.c_str() << endl;
}