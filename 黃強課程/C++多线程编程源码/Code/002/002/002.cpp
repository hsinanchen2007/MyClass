#include<windows.h>//�߳����ͷ�ļ�
#include<iostream>
using namespace  std;

//�̴߳�������windows��׼����Լ��_stdcall
DWORD   WINAPI  ThreadFun ( LPVOID lpThreadParameter );

int  main()
{
   
	DWORD    threadId=0;

	HANDLE hThread=CreateThread(NULL,//��ΪNULLʹ��Ĭ�ϰ�ȫ��
		0,//���Ϊ0����ôĬ�Ͻ�ʹ������øú������߳���ͬ��ջ�ռ��С��
		ThreadFun,//�̴߳����������������Ǻ���ָ��
		"hello",//���̺߳�������Ĳ���
		0,//��������������
		&threadId);

	if (hThread == NULL)
	{
		cout << "�̴߳���ʧ��:" << GetLastError() << endl;
	}

	cout << "�̵߳ľ����" << hThread << endl;
	cout << "���̵߳�ID��" << threadId << endl; 
	cout << "���߳�ID��" << GetCurrentThreadId() << endl;


	//�ر��߳̾��,���ü���-1�� ��û�н����߳�
	//CloseHandle(hThread);//��ʾ�Ժ������þ�� 
	getchar();

	//�����߳�
	SuspendThread(hThread);

	getchar();

	//�ָ��߳�ִ��
	ResumeThread(hThread);

	getchar();
	 

	return 0; 
}


DWORD   WINAPI  ThreadFun(LPVOID lpThreadParameter)
{
	char *str = (char*)lpThreadParameter;

	while(TRUE)
	{  
	   cout << "�̴߳������У�"<<str << endl;
	   cout << "���߳�ID�� " << GetCurrentThreadId() << endl;

	   Sleep(1000);//����1��
	}

	return  0;
}