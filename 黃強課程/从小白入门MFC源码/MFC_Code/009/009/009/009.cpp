#include<afxwin.h>

class MyApp :public  CWinApp
{
	BOOL  InitInstance()
	{
		/*
		CWnd  *pWnd = new CWnd;
		//���ڳ����д����Ӵ��ڣ��ؼ����������ǰ�������������
		pWnd->Create(NULL, L"hello", WS_CHILD | WS_BORDER, CRect(100, 100, 400, 400)
			,  CWnd::FromHandle( GetDesktopWindow()), 1111); 
		pWnd->ShowWindow(SW_SHOW);

		this->m_pMainWnd = pWnd;
*/

		//ʹ��CreateEx�����ص�����
		CWnd *pWnd = new CWnd;
		//ΪCWndע�ᴰ����
		CString  className = AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW,
			(HCURSOR)0, (HBRUSH)(COLOR_3DSHADOW));
		//��������
		pWnd->CreateEx(0, className, _T("Hello"), WS_OVERLAPPEDWINDOW,
			100, 100, 300, 300, NULL, NULL);
		//��ʾ����
		pWnd->ShowWindow(SW_SHOW);


		m_pMainWnd = pWnd; 

		return TRUE;
	} 
};

MyApp  theApp;