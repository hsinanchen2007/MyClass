#include<iostream>
#include<future>
#include<thread>
using namespace  std;
using  namespace  std::this_thread;
using namespace   std::chrono;
 
 
int  work(int  a, int b)
{
	//�����ʱ����
	cout << "��ʼ���㣡" << endl;
	sleep_for(seconds(5));
	cout << "�������㣡" << endl;
	return  a + b;
}


int  main()
{
  //packaged_task��װ��һ���ɵ��õ�Ŀ��
	packaged_task<int(int, int)>  pack(work );

	future<int> result = pack.get_future();//��ȡpackaged_task�ڲ���future

	thread  t1( move( pack) ,123,456);//��packaged_task���߳�ִ��
	t1.detach();

	int  sum = result.get();
	cout << "��ȡ�����" << sum << endl;

	return 0;
}
