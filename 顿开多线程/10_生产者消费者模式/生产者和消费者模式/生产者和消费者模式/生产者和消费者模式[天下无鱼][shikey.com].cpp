#include <iostream>
#include <mutex>
#include <thread>
#include <deque>
#include <cstdio>
#include <condition_variable>
using namespace std;
const int kProduceItems = 20;		//��Ʒ����
const int kRepositorySize = 5;		//�ֿ��С

//�ֿ���
template <class T>
class Repository 
{
public:
	deque<T> items_buff;				//�洢��Ʒ 
	mutex mtx;							//�����ߺ������ߵĻ�����
	mutex produce_mutex;				//��������������
	mutex consume_mutex;				//���Ѽ���������

	condition_variable repo_not_full;	//�ֿⲻ��״̬��������
	condition_variable repo_not_empty;	//�ֿⲻ�յ�����

	size_t produce_item_count;
	size_t consume_item_count;

	size_t produce_position;
	size_t consume_position;

	Repository() 
	{
		 produce_item_count=0;
		 consume_item_count=0;

		 produce_position=0;
		 consume_position=0;
	}	
};
//������
template <class T>
class Factory 
{
protected:
	Repository<T> repo;
	//��Ʒ�ŵ��ֿ�
	void ProduceItem(Repository<T>& repo, T item) 
	{
		unique_lock<mutex> lock(repo.mtx);
		repo.items_buff.push_back(item);
		if (repo.produce_position == kRepositorySize) 
		{
			repo.consume_position = 0;
		}
		repo.repo_not_empty.notify_all();
		lock.unlock();
	}
	//�Ӳֿ�ȡ��Ʒ
	T ConsumeItem(Repository<T>& repo) 
	{
		unique_lock<mutex> lock(repo.mtx);
		while (repo.items_buff.empty()) 
		{
			//cout << "�޻�Դ,�ȴ�..." << endl;
			printf("�޻�Դ, �ȴ�...\n");
			repo.repo_not_empty.wait(lock);
		}
		T data = repo.items_buff.front();
		repo.items_buff.pop_front();

		if (repo.consume_position == kRepositorySize) 
		{
			repo.consume_position = 0;
		}
		repo.repo_not_full.notify_all();
		lock.unlock();
		return data;
	}
public:
	//�����߲���
	void  ProduceTask() 
	{
		bool ready_to_exit = false;
		while (true) 
		{
			std::unique_lock<mutex> lock(repo.produce_mutex);
			//�߳̽�������
			if(repo.produce_item_count<kProduceItems)
			{
				repo.produce_item_count++;
				//������Ʒ�Ĵ����
				this_thread::sleep_for(1s);
				T item = repo.produce_item_count;
				//cout << "������id:" << this_thread::get_id() << "��Դ���:��" << item << "��\n";
				printf("������id:%p ��Դ���:��%d��\n", this_thread::get_id(), item);
				ProduceItem(repo, item);
			}
			else 
			{
				ready_to_exit = true;
			}
			lock.unlock();
			if (ready_to_exit) 
			{
				break;
			}
		}
	}
	//�����߲���
	void ConsumeTask() 
	{
		bool read_to_exit = false;
		while (true)
		{
			unique_lock<mutex> lock(repo.consume_mutex);
			if (repo.consume_item_count < kProduceItems)
			{
				T item = ConsumeItem(repo);
				//������Ʒ����
				this_thread::sleep_for(1s);
				//cout << "������id:" << this_thread::get_id() << "��Դ���:��" << item << "��\n";
				printf("������id:%p ��Դ���:��%d��\n", this_thread::get_id(), item);
				repo.consume_item_count++;
			}
			else
			{
				read_to_exit = true;
			}
			lock.unlock();
			if (read_to_exit) 
			{
				break;
			}
		}
	}
};

int main() 
{
	cout << "Main thread id:" << this_thread::get_id() << endl;
	Factory<int>  myFactory;
	thread produce1(&Factory<int>::ProduceTask, &myFactory);
	thread produce2(&Factory<int>::ProduceTask, &myFactory);

	thread consumer1(&Factory<int>::ConsumeTask, &myFactory);
	thread consumer2(&Factory<int>::ConsumeTask, &myFactory);
	thread consumer3(&Factory<int>::ConsumeTask, &myFactory);

	produce1.join();
	produce2.join();
	consumer1.join();
	consumer2.join();
	consumer3.join();
	return 0;
}