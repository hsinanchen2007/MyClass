#include<iostream>
#include<future>
#include<thread>
using namespace  std;
using  namespace  std::this_thread;
using namespace   std::chrono;

//费时操作
void  work( promise<int>  &  prom)
{
	cout << "开始计算！" << endl;
	sleep_for(seconds(5));
	//promise设置结果值
	cout << "计算完成！" << endl;
	prom.set_value(666);//设置结果，future会get到
}

int  main()
{
	//定义一个promise
	promise<int>  prom;

	//future和promise搭配使用，类似于aynsc
	future<int>  result=  prom.get_future();

	thread  t1(work , ref( prom) );
	t1.detach();
	 
	int   sum=result.get();
	cout << "获取结果：" << sum << endl;

	return 0;
}
