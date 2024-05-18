// NoModalDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "019.h"
#include "NoModalDialog.h"
#include "afxdialogex.h"


// CNoModalDialog �Ի���

IMPLEMENT_DYNAMIC(CNoModalDialog, CDialogEx)

CNoModalDialog::CNoModalDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DLG_NOMODAL, pParent)
{

}

CNoModalDialog::~CNoModalDialog()
{
}

void CNoModalDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CNoModalDialog, CDialogEx)
	ON_BN_CLICKED(IDOK, &CNoModalDialog::OnBnClickedOk)
END_MESSAGE_MAP()


// CNoModalDialog ��Ϣ�������


void CNoModalDialog::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//CDialogEx::OnOK();

  	DestroyWindow();

}

void CNoModalDialog::PostNcDestroy()
{
	CDialogEx::PostNcDestroy();
	//ɾ��new�Ķ���
	delete this;

}