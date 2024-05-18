#include<iostream>
#include<windows.h>
using namespace  std;


//CPU的经过的时钟周期数
inline unsigned __int64 GetCycleCount()
{
	__asm _emit 0x0F
	__asm _emit 0x31
}

int  main()
{
	__int64  t1 = GetCycleCount();
	Sleep(1780);//睡眠1.78秒 
	__int64  t2 = GetCycleCount();

	//此处2.8G的cpu主频
	cout << (t2 - t1) / 2.8*1000*1000*1000 << endl;

	return 0;
}
