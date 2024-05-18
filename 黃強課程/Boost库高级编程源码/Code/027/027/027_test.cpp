
#include<iostream>
using namespace std;

#include<boost/array.hpp> 
#include<boost/timer/timer.hpp>
using namespace  boost;
using namespace  boost::timer;

#include<vector>

//测试 普通数组，boost::array , std::vector

const  int N = 10000;

template< typename T>
void   Work(T   arr)
{ 
	for (size_t i = 0; i < N; i++)
	for (size_t j= 0; j< N; j++)
	{
		arr[i] = arr[j];
	}
}


int main()
{
	 
	//普通数组
	{
		int  arr[N] = {0};
		auto_cpu_timer  t(6, "普通数组消耗时间%w\n");
		Work<int[]>(arr);
	}


	//boost::array
	{
		boost::array<int,N> arr= { 0 };
		auto_cpu_timer  t(6, "boost::array消耗时间%w\n");
		Work<boost::array<int,N>>(arr);
	}

	//std::vector
	{
		vector<int> arr;
		arr.resize(N);
		auto_cpu_timer  t(6, "std::vector消耗时间%w\n");
		Work<vector<int>>(arr);
	}
 

	return 0;
}
