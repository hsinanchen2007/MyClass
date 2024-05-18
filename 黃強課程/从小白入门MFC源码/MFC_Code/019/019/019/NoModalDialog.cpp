// NoModalDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "019.h"
#include "NoModalDialog.h"
#include "afxdialogex.h"


// CNoModalDialog 对话框

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


// CNoModalDialog 消息处理程序


void CNoModalDialog::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	//CDialogEx::OnOK();

  	DestroyWindow();

}

void CNoModalDialog::PostNcDestroy()
{
	CDialogEx::PostNcDestroy();
	//删除new的对象
	delete this;

}