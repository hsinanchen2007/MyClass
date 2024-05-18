#include<iostream>
#include<future>
#include<thread>
using namespace  std;
using  namespace  std::this_thread;
using namespace   std::chrono;

//费时的操作
int   work(int  a, int  b)
{
	cout << "开始计算：" << endl; 
	sleep_for(seconds(5));//这个计算耗时5秒
	return  a + b; 
}


int  main()
{
	//将来的结果
	future<int> result = async(work, 123, 456);//move赋值操作

	result.wait();//等待结果算出，算出后才会继续执行
	cout << "算出结果：" << endl;
	int  sum= result.get();//获取结果
	cout << "最终的结果是：" << sum << endl;

	return 0;
}
