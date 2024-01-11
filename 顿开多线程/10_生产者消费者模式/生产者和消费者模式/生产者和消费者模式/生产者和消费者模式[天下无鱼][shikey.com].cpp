#include <iostream>
#include <mutex>
#include <thread>
#include <deque>
#include <cstdio>
#include <condition_variable>
using namespace std;
const int kProduceItems = 20;		//产品个数
const int kRepositorySize = 5;		//仓库大小

//仓库类
template <class T>
class Repository 
{
public:
	deque<T> items_buff;				//存储产品 
	mutex mtx;							//生产者和消费者的互斥量
	mutex produce_mutex;				//生产计数互斥量
	mutex consume_mutex;				//消费计数互斥量

	condition_variable repo_not_full;	//仓库不满状态条件变量
	condition_variable repo_not_empty;	//仓库不空的条件

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
//工厂类
template <class T>
class Factory 
{
protected:
	Repository<T> repo;
	//产品放到仓库
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
	//从仓库取产品
	T ConsumeItem(Repository<T>& repo) 
	{
		unique_lock<mutex> lock(repo.mtx);
		while (repo.items_buff.empty()) 
		{
			//cout << "无货源,等待..." << endl;
			printf("无货源, 等待...\n");
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
	//生产者操作
	void  ProduceTask() 
	{
		bool ready_to_exit = false;
		while (true) 
		{
			std::unique_lock<mutex> lock(repo.produce_mutex);
			//线程结束条件
			if(repo.produce_item_count<kProduceItems)
			{
				repo.produce_item_count++;
				//生产产品的代码块
				this_thread::sleep_for(1s);
				T item = repo.produce_item_count;
				//cout << "生产者id:" << this_thread::get_id() << "货源编号:【" << item << "】\n";
				printf("生产者id:%p 货源编号:【%d】\n", this_thread::get_id(), item);
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
	//消费者操作
	void ConsumeTask() 
	{
		bool read_to_exit = false;
		while (true)
		{
			unique_lock<mutex> lock(repo.consume_mutex);
			if (repo.consume_item_count < kProduceItems)
			{
				T item = ConsumeItem(repo);
				//消费商品代码
				this_thread::sleep_for(1s);
				//cout << "消费者id:" << this_thread::get_id() << "货源编号:【" << item << "】\n";
				printf("消费者id:%p 货源编号:【%d】\n", this_thread::get_id(), item);
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