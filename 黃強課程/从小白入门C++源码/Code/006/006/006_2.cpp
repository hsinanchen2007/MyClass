#include<iostream>
#include<windows.h>
using namespace  std;


//CPU�ľ�����ʱ��������
inline unsigned __int64 GetCycleCount()
{
	__asm _emit 0x0F
	__asm _emit 0x31
}

int  main()
{
	__int64  t1 = GetCycleCount();
	Sleep(1780);//˯��1.78�� 
	__int64  t2 = GetCycleCount();

	//�˴�2.8G��cpu��Ƶ
	cout << (t2 - t1) / 2.8*1000*1000*1000 << endl;

	return 0;
}
