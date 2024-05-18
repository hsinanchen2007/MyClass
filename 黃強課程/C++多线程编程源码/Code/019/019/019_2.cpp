#include<atomic>
#include<thread>
#include<vector>
#include<iostream>
using namespace  std;
using namespace  std::this_thread;

atomic<bool>  ready = false;//�Ƿ�ǹ��

atomic_flag  win = ATOMIC_FLAG_INIT;//�յ���

void   Run(int  id)
{
	//ǹû�죬������
	while (!ready)
	{
		 yield();//�������߳���ִ��
	}

	//��ʾ�ܵĹ���
	for (int i = 0; i < 100000; ++i) 
	{}

	//���û�б����ù�������false
	if (! win.test_and_set())//���ú�Ὣ������
	{
		cout << id << "��ѡ��Ӯ�õ�һ����" << endl;
	}

}

int  main()
{
	//ʮ��ѡ������
	vector<thread>   vecPlayers;
	for (int i = 1; i <= 10; ++i)
	{
		vecPlayers.push_back( thread(Run ,  i ));
	}
	cout << "10��ѡ���Ѿ�׼���ã�" << endl;

	//׼�������Ԥ����
	sleep_for(chrono::seconds(3));
	cout << "3��2��1 Ԥ���ܣ�" << endl;

	ready = true;//��������

	//�ȴ�����ѡ������
	for (thread &t : vecPlayers)
	{
		t.join();
	}

	return 0;
}