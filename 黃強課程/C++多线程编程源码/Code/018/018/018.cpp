#include<iostream> 
#include<thread> 
using  namespace  std; 
//�����ռ�this_thread�����е��̸߳�������  get_id()   yield()  sleep_for()   sleep_until
using namespace std::this_thread;

//�����ռ�chrono��secondsģ���ࡢmillisecondsģ����
using  namespace  std::chrono;

void   ThreadFun(string  &str);

int  main()
{
	thread t1(ThreadFun, string("hello"));
	cout << t1.get_id() << endl;

	//�ȴ����߳����
	t1.join();

	return 0;
}


void   ThreadFun(string  &str)
{
	cout <<"�߳�ID:"<< get_id() << endl;//��ȡ�߳�ID

	while (true)
	{
		cout << str.c_str() << endl;
		//sleep_for(seconds(1));//���߳�˯��1��

		yield();//���߳�˯��һ����С��ʱ��Ƭ���������߳�ִ��

		sleep_until(system_clock::now() + milliseconds(1000));//���߳�˯�ߵ�ǰʱ��+1��

	}

}

 