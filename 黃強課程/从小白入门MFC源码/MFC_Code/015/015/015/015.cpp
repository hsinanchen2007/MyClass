#include<afxwin.h>

#include"resource.h"

class MyApp :public CWinApp
{
	virtual  BOOL  InitInstance()
	{
		CFrameWnd  *pWnd = new  CFrameWnd;

		//1.ʹ��Create����
		pWnd->Create(NULL, L"hello");//NULL��ʾʹ��ϵͳԤ���崰����

									 //2.ʹ��LoadFrame ������ԴID����
									 //pWnd->LoadFrame(IDI_ICON1); 


		pWnd->ShowWindow(SW_SHOW);
		this->m_pMainWnd = pWnd;

		return TRUE;
	}

};

MyApp  theApp;