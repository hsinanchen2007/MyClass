#include<iostream>
#include<vector>
#include<map>
#include<thread>

using namespace std;

//用lambda表达式创建线程
int main() {
	auto mylamthread = [] {
		cout << "我的线程3开始执行了" << endl;
		cout << "我的线程3执行结束了" << endl;
	};

	thread myobj3(mylamthread);

    myobj3.join();

    cout << "I Love China1!" << endl;

    return 0;
}
