#include <thread>    
#include <mutex>   
#include <condition_variable>   
#include<iostream>
using namespace  std;
using namespace  std::this_thread;
using namespace  std::chrono;

condition_variable   cv;//��֧��unique_lock<mutex> ��Ϊwait�Ĳ���
condition_variable_any   cv2;//�����κ� lockable������Ϊwait�Ĳ���
mutex  m;


void  ThreadFun(int id)
{ 
	unique_lock<mutex>  lck(m); 
	//cv.wait(lck);//�ȴ������� 

	cv2.wait(lck);

	cout << "�߳�ID:" << id << "ִ�У�" << endl;

}

int main()
{
	thread  t1(ThreadFun, 1);
	thread  t2(ThreadFun, 2);
	thread  t3(ThreadFun, 3);
	
	cout << "3����ѣ�" << endl;

	sleep_for(seconds(3));//3��֮���������߳�

	//cv.notify_all();//�������� 

	//cv.notify_one();
	//cv.notify_one();

	cv2.notify_all();

	t1.join();
	t2.join();
	t3.join();
	return 0;
}