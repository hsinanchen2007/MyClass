#include <iostream>
#include <future>
#include <thread>
using namespace  std;
using namespace  std::this_thread;
using namespace  std::chrono;
 
//��ʱ����
void  work1(promise<int> &prom, int  a, int b)
{
	cout << "work1��ʼ���㣺" << endl;
	sleep_for(seconds(3));
	prom.set_value(a+b);
}

int  work2( int  a, int b)
{
	cout << "work2��ʼ���㣺" << endl;
	sleep_for(seconds(2));
	return a + b;
}

int  work3(int  a, int b)
{
	cout << "work3��ʼ���㣺" << endl;
	sleep_for(seconds(2));
	return a + b;
}



int main()
{ 
	//promise�ڲ���װ��һ��ֵ
	promise<int>  prom;
	future<int> f1 = prom.get_future();//ʹ��get_future��Ա������ȡfuture
	thread(work1, ref(prom), 1, 2).detach();
	f1.wait();//�ȴ�ֵ����
	cout<<"��������"<<f1.get()<<endl;//��ȡ���


	//packaged_task��װһ������
	packaged_task<int(int, int)>  task(work2);
	future<int> f2 = task.get_future();//ʹ��get_future��Ա������ȡfuture
	thread(move(task), 11, 22).detach();
	f2.wait();//�ȴ����
	cout << "��������" << f2.get() << endl;//��ȡ���


	//async�ڲ���һ���߳�
	future<int> f3 = async(work3,111,222);
	f3.wait();//�ȴ����
	cout << "��������" << f3.get() << endl;//��ȡ���
}