#include<afxwin.h>

class  MyWnd :public  CWnd
{
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam)
	{
		if (message == WM_LBUTTONDOWN)
		{
			int  a = 100;
		}
		return   CWnd::WindowProc(message, wParam, lParam);
	}
	virtual BOOL OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pResult)
	{
		if (message == WM_LBUTTONDOWN)
		{
			//��ʾû�д������Ϣ��ת��DefWindowProc
			return  false;
		}
		return CWnd::OnWndMsg(message, wParam, lParam, pResult);
	}

	virtual LRESULT DefWindowProc(UINT message, WPARAM wParam, LPARAM lParam)
	{
		if (message == WM_LBUTTONDOWN)
		{
			int  a = 100;
		}
		return CWnd::DefWindowProc(message, wParam, lParam);
	}

};


class  MyApp :public  CWinApp
{
	virtual  BOOL  InitInstance()
	{

		MyWnd *pWnd = new MyWnd;
		//����class��ΪϵͳԤ��ģ��䴰�ڴ�����Ϊȫ�ֵ�DefWindowProc��
		//����MFC����ù��Ӹ���ΪCWnd��WndProc
		pWnd->CreateEx(0, NULL, _T("Hello"), WS_CHILD | WS_BORDER,
			100, 100, 300, 300, GetDesktopWindow(), 0);
		pWnd->ShowWindow(SW_SHOW);
		m_pMainWnd = pWnd;
		return true;
	}

};

//Ψһһ��ȫ��MFC���ó���ʵ��
MyApp  theApp;