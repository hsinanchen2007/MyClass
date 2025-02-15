#include<iostream>
#include<future>
#include<thread>
using namespace  std;
using  namespace  std::this_thread;
using namespace   std::chrono;

//费时操作
void  work(promise<int>  &  prom)
{
	cout << "开始计算！" << endl;
	sleep_for(seconds(5));
	//promise设置结果值
	try
	{
		throw  runtime_error("运行时错误");
	}
	catch (...)
	{
		//promise设置异常
		prom.set_exception(current_exception());
	}

	
}

int  main()
{
	//定义一个promise
	promise<int>  prom;

	//future和promise搭配使用，类似于aynsc
	future<int>  result = prom.get_future();

	thread  t1(work, ref(prom));
	t1.detach();

	try
	{
		int   sum = result.get();
		cout << "获取结果：" << sum << endl;
	}
	catch (exception &e)
	{
		cout << "结果异常：" << e.what() << endl;
	}


	return 0;
}
