#include<afxwin.h>
#include<afxext.h>

class CMyApp: public CWinApp
{
	
	virtual BOOL InitInstance()
	{	
		CFrameWnd *pWnd = new CFrameWnd;
		pWnd->Create(NULL, L"Hello!");

		CRect r;
		pWnd->GetClientRect(r);
 		CEditView *pEV = new CEditView;
		pEV->Create(NULL, L"±à¼­", WS_CHILD | WS_VISIBLE | WS_BORDER, r, pWnd, 10000);


		this->m_pMainWnd = pWnd;
	    pWnd->ShowWindow(SW_SHOW);

		
		return TRUE;

	}


};
CMyApp theAPP;