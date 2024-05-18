#include<afxwin.h>
#include "resource.h"

class CMyDlg :public CDialog
{
	//�ڴ������ٺ�CWnd::OnPostNcDestroy�����PostNcDestroy
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

	//������ģ̬�Ի���
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