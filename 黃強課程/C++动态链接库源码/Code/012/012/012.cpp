// 012.cpp : ���� DLL �ĳ�ʼ�����̡�
//

#include "stdafx.h"
#include "012.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO:  ����� DLL ����� MFC DLL �Ƕ�̬���ӵģ�
//		��Ӵ� DLL �������κε���
//		MFC �ĺ������뽫 AFX_MANAGE_STATE ����ӵ�
//		�ú�������ǰ�档
//
//		����: 
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// �˴�Ϊ��ͨ������
//		}
//
//		�˺������κ� MFC ����
//		������ÿ��������ʮ����Ҫ��  ����ζ��
//		��������Ϊ�����еĵ�һ�����
//		���֣������������ж������������
//		������Ϊ���ǵĹ��캯���������� MFC
//		DLL ���á�
//
//		�й�������ϸ��Ϣ��
//		����� MFC ����˵�� 33 �� 58��
//

// CMy012App

BEGIN_MESSAGE_MAP(CMy012App, CWinApp)
END_MESSAGE_MAP()


// CMy012App ����

CMy012App::CMy012App()
{
	// TODO:  �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CMy012App ����

CMy012App theApp;


// CMy012App ��ʼ��

BOOL CMy012App::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}
#include"MyDialog.h"
_declspec(dllexport)    void  ShowDialog()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	CMyDialog  dlg;
	dlg.DoModal();
}

