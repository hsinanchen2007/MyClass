#include<process.h>
#include<windows.h>
#include<stdio.h>


void    __cdecl   SellThread1(void* param);
void    __cdecl   SellThread2(void* param);

//100��Ʊ
int   tickets = 100;

int  main()
{ 
	printf("��ʼ��Ʊ�ˣ�\n");

	//����������Ʊ���� 
	uintptr_t   t1 = _beginthread(SellThread1, 0,  "�ۿڴ���A");
	uintptr_t   t2 = _beginthread(SellThread2, 0,  "�ۿڴ���B");

	//���޵ȴ������߳�ȫ��ִ�����
	HANDLE  hArr []= {  (HANDLE)t1,  (HANDLE)t2   }; 
	WaitForMultipleObjects(2, hArr, true, INFINITE);

	printf("��Ʊ������\n");

	return 0;
}


void    __cdecl   SellThread1(void* param)
{
	char  *name= (char *)param;
	while (tickets > 0)
	{
		Sleep(10);
		//CPUǡ��ִ�е�������ʱ���߳�ʱ��Ƭ���ˣ����Ҵ�ʱ��ʣ���һ��Ʊ
		printf("%s������%d��Ʊ��\n", name, tickets--  );
	}

}
void    __cdecl   SellThread2(void* param)
{
	char  *name = (char *)param;
	while (tickets > 0)
	{
		Sleep(10);
		//CPUǡ��ִ�е�������ʱ���߳�ʱ��Ƭ���ˣ����Ҵ�ʱ��ʣ���һ��Ʊ
		printf("%s������%d��Ʊ��\n", name, tickets--);
	}
}