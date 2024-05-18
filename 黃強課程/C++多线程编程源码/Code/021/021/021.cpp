#include<iostream>
#include<mutex>
#include<thread>
#include<stdexcept>
using namespace std;
using  namespace  std::this_thread;
mutex  m;

void  ThreadFun()
{
	try
	{
		for (int i = 0; i < 10; ++i)
		{
			sleep_for(chrono::seconds(1));
			//m.lock();
			lock_guard<mutex>   lck(m);//���·����쳣Ҳ�ǿ��԰�ȫ��������Ϊlck��������Ȼ�����mutex

			if (i == 3)  throw   logic_error("�����쳣��!");

			cout << "A��ӡ" << i << endl;
			  
			//m.unlock();//�׳��쳣ʱ������û��unlock��ʹ��B�޷���ȡmutex�� ����
			
		}

	}
	catch (logic_error  & e)
	{
		cout << "����" <<e.what()<< endl;
	}
	
}

void  ThreadFun2()
{
	for (int i = 0; i < 10; ++i)
	{
		sleep_for(chrono::seconds(1));

		lock_guard<mutex>   lck(m);

		//m.lock(); 
		cout << "B��ӡ" << i << endl; 
		//m.unlock(); 
	}
}


int  main()
{

	thread  t1(ThreadFun);
	thread  t2(ThreadFun2);

	t1.join();
	t2.join();


	return 0;
}