#include "003.h"
#include<iostream>
using namespace std;


void main()
{
   //ģ���࣬ ʵ������ģ��

	//����Math��
	Math<int>  math;
	cout<< math.sum(111,999)<<endl;
	cout << math.max(111, 999) << endl;

	//float  Math��
	Math<float>  math2;
	cout << math2.sum(1.234f, 4.567f) << endl;
	cout << math2.max(1.234f, 4.567f) << endl;


	//double  Math��
	Math<double>  math3;
	cout << math3.sum(1.234, 4.567) << endl;
	cout << math3.max(1.234, 4.567) << endl;

}