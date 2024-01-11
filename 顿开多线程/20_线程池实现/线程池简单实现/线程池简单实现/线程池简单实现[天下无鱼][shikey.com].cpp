#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <future>
#include <exception>
#include <iostream>
using namespace std;
class ThreadPool 
{
public:
	ThreadPool(size_t size);
	~ThreadPool();
	template <class F,class ...Args>
	auto enqueue(F&& f, Args&& ...args)->future<decltype(f(args...))>;
protected:

	queue<function<void()>> tasks;		//任务列表
	vector<thread> workers;				//工作线程

	mutex queue_mutex;
	condition_variable condition;		
	bool stop;							
};
ThreadPool::ThreadPool(size_t size):stop(false)
{
	for (int i = 0; i < size; i++) 
	{
		workers.emplace_back(
			[this] 
			{
				while (true) 
				{
					function<void()> task; 
					{
						unique_lock<mutex> lock(this->queue_mutex);
						this->condition.wait(lock, [this] {return this->stop || !this->tasks.empty(); });
						if (this->stop && this->tasks.empty()) 
						{
							return;
						}
						task = move(this->tasks.front());
						this->tasks.pop();
					}
					task();
				}
			}
		);
	}
}
ThreadPool::~ThreadPool() 
{
	{
		unique_lock<mutex> lock(queue_mutex);
		stop = true;
	}
	condition.notify_all();
	for (auto &t :workers) 
	{
		t.join();
	}
}
template <class F, class ...Args>
auto ThreadPool::enqueue(F&& f, Args&& ...args)->future<decltype(f(args...))> 
{
	using  Type = decltype(f(args...));
	auto task = make_shared<packaged_task<Type()>>(bind(forward<F>(f), forward<Args>(args)...));
	future<Type> res = task->get_future();
	{
		unique_lock<mutex> lock(queue_mutex);
		if (stop) 
		{
			throw runtime_error("停止....");
		}
		tasks.emplace([task] {(*task)(); });
	}
	condition.notify_one();
	return res;
}
int func(int i) 
{
	printf("线程干货:%d\n", i);
	this_thread::sleep_for(1s);
	printf("线程结束:%d\n", i);
	return i * i;
}
int main() 
{
	ThreadPool pool(4);
	vector<future<int>> results;
	for (int i = 0; i < 8; i++) 
	{
		results.emplace_back(pool.enqueue(func, i));
	}
	for (auto&& t : results) 
	{
		printf("结束:%d\n", t.get());
	}
	return 0;
}
