#include<afxwin.h>

class CMyApp :public CWinApp
{
	virtual BOOL InitInstance()
	{	//new�Ķ�̬����
		//CFrameWnd *pWnd = new CFrameWnd;
		//MFC�Ķ�̬����

		CRuntimeClass *p = CFrameWnd::GetThisClass();
		CFrameWnd *pWnd = (CFrameWnd *)p->CreateObject();
		pWnd->Create(NULL,L"�ҵĴ���");

		this->m_pMainWnd = pWnd;
		pWnd->ShowWindow(SW_SHOW);

		return TRUE;
	
	}
	
};

CMyApp theApp;