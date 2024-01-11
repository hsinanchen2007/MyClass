#include <algorithm>
#include <numeric>
#include <chrono>
#include <vector>
#include <random>
#include <iostream>
#include <execution>
using namespace std;
/*
	���Ӳ�����sequenced_policy  �ṩ��Ӧ���а��㷨
	execution::seq		  �����㷨ִ�п��Բ����л�
	execution::par		  �����㷨ִ�п��Բ��л�
	execution::par_unseq  �����㷨ִ�еĿ��Բ����Լ�������
*/
void randomData(vector<double>& data, int size) 
{
	//�����
	random_device rd;
	mt19937 mt(rd());
	uniform_real_distribution<double> dist(1.0, 100.0);

	for (int i = 0; i < size; i++) 
	{
		data.push_back(dist(mt));
	}
}
int main() 
{
	vector<double> data;
	randomData(data, 10e6);

	vector<double> test1(data);
	vector<double> test2(data);
	vector<double> test3(data);
	vector<double> test4(data);

	auto stime = chrono::steady_clock::now();
	sort(execution::seq, test1.begin(), test1.end());
	auto etime = chrono::steady_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(etime - stime).count();
	cout << "execution::seq:" << duration << "ms" << endl;

	stime = chrono::steady_clock::now();
	sort(execution::par, test2.begin(), test2.end());
	etime = chrono::steady_clock::now();
	auto duration2 = chrono::duration_cast<chrono::milliseconds>(etime - stime).count();
	cout << "execution::seq:" << duration2 << "ms" << endl;

	stime = chrono::steady_clock::now();
	sort(execution::par_unseq, test3.begin(), test3.end());
	etime = chrono::steady_clock::now();
	auto duration3 = chrono::duration_cast<chrono::milliseconds>(etime - stime).count();
	cout << "execution::seq:" << duration3 << "ms" << endl;

	stime = chrono::steady_clock::now();
	sort(test4.begin(), test4.end());
	etime = chrono::steady_clock::now();
	auto duration4 = chrono::duration_cast<chrono::milliseconds>(etime - stime).count();
	cout << "sort:" << duration4 << "ms" << endl;

	return 0;
}