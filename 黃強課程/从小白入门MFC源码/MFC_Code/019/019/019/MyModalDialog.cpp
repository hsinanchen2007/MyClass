// MyModalDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "019.h"
#include "MyModalDialog.h"
#include "afxdialogex.h"


// CMyModalDialog �Ի���

IMPLEMENT_DYNAMIC(CMyModalDialog, CDialogEx)

CMyModalDialog::CMyModalDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DLG_Modal, pParent)
{

}

CMyModalDialog::~CMyModalDialog()
{
}

void CMyModalDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMyModalDialog, CDialogEx)
END_MESSAGE_MAP()


// CMyModalDialog ��Ϣ�������
