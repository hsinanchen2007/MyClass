#include<afxwin.h>
#include "resource.h"

class CMyDlg :public CDialog
{
	//在窗口销毁后，CWnd::OnPostNcDestroy会调用PostNcDestroy
	virtual void PostNcDestroy();
	virtual void OnOK();
	virtual void OnCancel();
};

void CMyDlg::PostNcDestroy()
{
	CDialog::PostNcDestroy();
	delete this;

}
void CMyDlg::OnOK()
{

	CDialog::OnOK();
	DestroyWindow();

}
void CMyDlg::OnCancel()
{

	CDialog::OnCancel();
	DestroyWindow();
}

class MyApp :public CWinApp
{
public:

	//创建非模态对话框
	BOOL InitInstance()
	{
		CMyDlg *pDlg = new CMyDlg;
		pDlg->Create(IDD_DIALOG1);
		pDlg->ShowWindow(SW_SHOW);
		m_pMainWnd = pDlg;
		return true;
	
	}


};


MyApp theApp;