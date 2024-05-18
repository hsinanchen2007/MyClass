#include "MyApp.h"
#include"MainFrame.h"
#include"MyDoc.h"
#include"MyView.h"
#include"resource.h"
#include"ChildFrame.h"


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
	p->LoadFrame(IDR_MAINFRAME);
	this->m_pMainWnd = p;
	p->UpdateWindow();
	p->ShowWindow(SW_SHOW); 
	return  TRUE;
*/

// ע��Ӧ�ó�����ĵ�ģ�塣  �ĵ�ģ��
// �������ĵ�����ܴ��ں���ͼ֮�������
	CMultiDocTemplate* pDocTemplate;
	pDocTemplate = new CMultiDocTemplate(IDR_MFCApplication1TYPE,
		RUNTIME_CLASS(CMyDoc),
		RUNTIME_CLASS(CChildFrame), // �Զ��� MDI �ӿ��
		RUNTIME_CLASS(CMyView));
	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(pDocTemplate);

   // ������ MDI ��ܴ���
	CMainFrame* pMainFrame = new CMainFrame;
	if (!pMainFrame || !pMainFrame->LoadFrame(IDR_MAINFRAME))
	{
		delete pMainFrame;
		return FALSE;
	}

	m_pMainWnd = pMainFrame;
	 

	OnFileNew();

	// Ψһ��һ�������ѳ�ʼ���������ʾ����������и���
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();

	return   true; 
}


//Ψһ��Ӧ�ó���ʵ������
CMyApp  theApp;