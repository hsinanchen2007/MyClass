// MyDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "013.h"
#include "MyDialog.h"
#include "afxdialogex.h"


// CMyDialog 对话框

IMPLEMENT_DYNAMIC(CMyDialog, CDialog)

CMyDialog::CMyDialog(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_MYDIALOG, pParent)
{

}

CMyDialog::~CMyDialog()
{
}

void CMyDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMyDialog, CDialog)
END_MESSAGE_MAP()


// CMyDialog 消息处理程序
