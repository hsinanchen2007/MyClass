#include<iostream>
#include<future>
#include<thread>
using namespace  std;
using  namespace  std::this_thread;
using namespace   std::chrono;

//��ʱ����
void  work(promise<int>  &  prom)
{
	cout << "��ʼ���㣡" << endl;
	sleep_for(seconds(5));
	//promise���ý��ֵ
	try
	{
		throw  runtime_error("����ʱ����");
	}
	catch (...)
	{
		//promise�����쳣
		prom.set_exception(current_exception());
	}

	
}

int  main()
{
	//����һ��promise
	promise<int>  prom;

	//future��promise����ʹ�ã�������aynsc
	future<int>  result = prom.get_future();

	thread  t1(work, ref(prom));
	t1.detach();

	try
	{
		int   sum = result.get();
		cout << "��ȡ�����" << sum << endl;
	}
	catch (exception &e)
	{
		cout << "����쳣��" << e.what() << endl;
	}


	return 0;
}
