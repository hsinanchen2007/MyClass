#include "MyApp.h"
#include"MainFrame.h"
#include"MyDoc.h"
#include"MyView.h"
#include"resource.h"

BEGIN_MESSAGE_MAP(CMyApp, CWinApp)
	// �����ļ��ı�׼�ĵ�����
	ON_COMMAND(ID_FILE_NEW, &CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, &CWinApp::OnFileOpen)
END_MESSAGE_MAP()


CMyApp::CMyApp()
{
}


CMyApp::~CMyApp()
{
}


BOOL CMyApp::InitInstance()
{
	/*
	CMainFrame  * p = new   CMainFrame;
	p->Create(NULL, L"���±�");
	this->m_pMainWnd = p;
	p->UpdateWindow();
	p->ShowWindow(SW_SHOW);*/


	// ע��Ӧ�ó�����ĵ�ģ�塣  �ĵ�ģ��
	// �������ĵ�����ܴ��ں���ͼ֮�������
	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MENU1,
		RUNTIME_CLASS(CMyDoc),
		RUNTIME_CLASS(CMainFrame),       // �� SDI ��ܴ���
		RUNTIME_CLASS(CMyView));
	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(pDocTemplate);

	OnFileNew();

	// Ψһ��һ�������ѳ�ʼ���������ʾ����������и���
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();

	return   true;
}


//Ψһ��Ӧ�ó���ʵ������
CMyApp  theApp;