#include<afxwin.h>


class MyApp:public CWinApp 
{
	virtual  BOOL InitInstance()
	{
		CFrameWnd *pWnd = new CFrameWnd;
		pWnd->Create(NULL, L"Hello World!");
		pWnd->ShowWindow(SW_SHOW);

		m_pMainWnd = pWnd;

	
	
		return TRUE;
	}
}; 

MyApp theApp;