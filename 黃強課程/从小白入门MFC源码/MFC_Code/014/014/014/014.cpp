#include<afxwin.h>

//ʹ��VS����MFC����������̣���ʾCWnd��Ϣ������Ϣӳ�����
//ע���Ҽ�����     ����->MFCʹ��-> �ھ�̬��ʹ��MFC


class MyWnd :public  CWnd
{
protected:
	//1.��Ϣ����������
	afx_msg    int    OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg   void  OnLButtonDown(UINT nFlags, CPoint point);
	void   OnLButtonDblClk(UINT nFlags, CPoint point);
	//2��Ϣӳ������
	DECLARE_MESSAGE_MAP()
};


BEGIN_MESSAGE_MAP(MyWnd, CWnd)
	//3����ӳ���
	ON_WM_CREATE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONDBLCLK()
	//.....
END_MESSAGE_MAP()

//4.ʵ����Ϣ������
int    MyWnd::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	return  0;
}

void  MyWnd::OnLButtonDown(UINT nFlags, CPoint point)
{
	int  a = 100;
}

void  MyWnd::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	int  a = 100;
}

class MyApp :public  CWinApp
{

	virtual   BOOL  InitInstance()
	{
		//ע�ᴰ����
		CString  className = AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS, (HCURSOR)0, (HBRUSH)(COLOR_3DSHADOW));

		MyWnd *pWnd = new MyWnd;
		pWnd->CreateEx(0, className, _T("Hello"), WS_OVERLAPPEDWINDOW, 100, 100, 300, 300, NULL, 0);
		pWnd->ShowWindow(SW_SHOW);

		m_pMainWnd = pWnd;
		return  TRUE;
	}

};

//ȫ��Ψһ��Ӧ�ó���ʵ��
MyApp  theApp;