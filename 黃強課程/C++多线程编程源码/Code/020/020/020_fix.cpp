#include<stdio.h>
#include<thread>
#include<mutex>
 

using namespace std;
using namespace  std::this_thread;
using namespace  std::chrono;

int   tickets = 100;
 
//����һ���������
mutex  m;
recursive_mutex   m2;//���Եݹ����
timed_mutex  m3;//����ָ����ס��ʱ��

void  SellThread(string  & str )
{

	while (tickets>0)
	{
	
		int t = rand() % 5000;

		printf("%s ��ʼ�������� \n", str.c_str());
		bool b = m3.try_lock_for(seconds(3));//�ٴμ���
		printf("%s ������� %d \n", str.c_str(), b);
		if (b &&  tickets > 0)
		{ 
			printf("%s ���� %d Ʊ\n" , str.c_str(),  tickets-- );  
		 
			 //��Ʊ����ʱ��
			 sleep_for(milliseconds(t)); 

			 printf("%s �����ˣ�\n", str.c_str() );
			 m3.unlock();//ȥ������ 
			
		} 
		 
		 printf("%s ��������%d \n", str.c_str(), b);
	}

}

int  main()
{
	srand(time(0));
	thread  t1(SellThread, string("��Ʊ����A: "));
	thread  t2(SellThread, string("��Ʊ����B: "));
	 
	t1.join();
	t2.join();

	return 0;
}