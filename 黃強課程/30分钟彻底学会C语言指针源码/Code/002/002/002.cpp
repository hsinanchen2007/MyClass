#include<iostream>
using  namespace  std;

struct  A
{
	int a;
	int b; 
};

int  main()
{
	 
	//��ָ֤�����͵ı���
	cout << sizeof(unsigned  int) << endl;//ռ4���ֽ�


	cout << sizeof(char *) << endl;//�ַ�ָ�����ͣ�ռ4���ֽ�
	cout << sizeof(int*) << endl;//����ָ�����ͣ�ռ4���ֽ�
	cout << sizeof(short*) << endl;//������ָ�����ͣ�ռ4���ֽ�
	cout << sizeof(float*) << endl;//������ָ�����ͣ�ռ4���ֽ�
	cout << sizeof(double*) << endl;//������ָ�����ͣ�ռ4���ֽ�
	cout << sizeof(A*) << endl;//�ṹ����ָ�����ͣ�ռ4���ֽ�

	//�ɴ˿�����֤��32λϵͳ�£� ָ�����һ���ڴ��ַ���޷��ŵ�32λ������ֵ��

	return 0;
}