#include <afxwin.h>

class MyApp :public  CWinApp
{

	virtual  BOOL  InitInstance()
	{

		CWinThread* pThread = AfxGetThread();
		CWinApp* pApp = AfxGetApp();

		//  AfxGetApp()  AfxGetThread()��ָ��theApp�ĵ�ַ��ֵ���
		bool  b1 = (pThread == pApp);
		bool  b2 = (pThread == this);

		return TRUE;
	}
};

//����ȫ��Ψһ����
MyApp  theApp;