#include <afxwin.h>//����CWinThread��ͷ�ļ�
#include <iostream>
using namespace std;

UINT ThreadFun(LPVOID param)
{
	for (int i=0;i<5;++i)
	{ 
		char *str = (char*)param;
		cout << str << endl;
		Sleep(1000);
	}
	return 0;
}

int main()
{
	//����һ����Ķ���
	CWinThread t(ThreadFun,"hello");
	//�ֲ���������Ҫ�߳̽�����ʱ���Զ�����t

	t.m_bAutoDelete = FALSE;


  //�����̵߳ĳ�Ա�����������߳�
	t.CreateThread();

	//���������Ա����,������֮��Ż���
	cout << "����:" << (char *)t.m_pThreadParams << endl;
	cout << "�߳̾��:" << t.m_hThread << endl;
	cout << "�߳�ID:" << t.m_nThreadID << endl;
	//�ȴ��߳�ִ�����
	WaitForSingleObject(t.m_hThread, INFINITE);

	cout << "main����" << endl;
	


	return 0;
}