// 013.cpp : ���� DLL �ĳ�ʼ�����̡�
//

#include "stdafx.h"
#include "013.h"

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

// CMy013App

BEGIN_MESSAGE_MAP(CMy013App, CWinApp)
END_MESSAGE_MAP()


// CMy013App ����

CMy013App::CMy013App()
{
	// TODO:  �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CMy013App ����

CMy013App theApp;


// CMy013App ��ʼ��

BOOL CMy013App::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

#include"MyDialog.h"
_declspec (dllexport)  void  ShowDialog()
{
	CMyDialog  dlg;
	dlg.DoModal();
}