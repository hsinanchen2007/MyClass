#include<iostream>
using namespace std;

template<typename  T>
class A
{
public:
	static  int   s;//������ģ������T�ľ�̬��Ա
	static   T    s2; //����ģ������T�ľ�̬��Ա  
};
 
//1.ģ����ľ�̬��Ա������ʼ��,  ����������T�Ķ���һ��ͨ�õ�ֵ
template<typename T>int  A<T>::s = 111;  
//2.�ػ��ķ�ʽ��ֻ�и����Ϳ��Ի�ȡ��ֵ
template <>int  A<int>::s = 222;//Ҳ�����ػ�������T����, ֻ��T��int��Ч
//s2ֻ���ػ�
template <>float  A<float>::s2 = 333.33f;
template <>char  A<char>::s2 = 'A';

template <>int  A<int>::s2 = 666;

void main()
{
	//����������T��s����һ��ͨ�õ�ֵ111
	cout << A<float>::s << endl;
	cout << A<int>::s << endl;
	cout << A<char>::s << endl;
	cout << A<double>::s << endl;


	//�ض����ͣ�s2�ض�ֵ
	cout << A<float>::s2 << endl;
    cout << A<int>::s2 << endl;
    cout << A<char>::s2 << endl;
	//cout << A<double>::s2 << endl;//�����ػ�����Ȼ�Ҳ���s2
}