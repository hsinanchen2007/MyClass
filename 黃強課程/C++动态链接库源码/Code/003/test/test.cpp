#include<iostream>



//���������dllimport ���뺯��
extern "C"  _declspec(dllimport)     int   sum(int  a, int b);

//�����.lib�ļ������Ǿ�̬�⣬���Ƕ�̬��ķ����ļ�
//����һ:  #pragma  comment (lib,"../Debug/003.lib")
//������:  �Ҽ�-������-����������-��������-������-������������

//������ʱ�򣬻���Ҫ����.dll�ļ�
int  main()
{
	std::cout << sum(123, 456) << std::endl;
}