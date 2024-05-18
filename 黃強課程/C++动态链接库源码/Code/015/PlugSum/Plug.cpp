// Plug.cpp : 实现文件
//

#include "stdafx.h"
#include "Plug.h"
#include "afxdialogex.h"


// CPlug 对话框

IMPLEMENT_DYNAMIC(CPlug, CDialog)

CPlug::CPlug(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_PLUG, pParent)
	, a(0)
	, b(0)
	, c(0)
{

}

CPlug::~CPlug()
{
}

void CPlug::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, a);
	DDX_Text(pDX, IDC_EDIT1, b);
	DDX_Text(pDX, IDC_STATIC1, c);
}


BEGIN_MESSAGE_MAP(CPlug, CDialog)
	ON_BN_CLICKED(IDOK, &CPlug::OnBnClickedOk)
END_MESSAGE_MAP()


// CPlug 消息处理程序


void CPlug::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	//CDialog::OnOK(); 
	 UpdateData(true);
	  c = a  +  b;
     UpdateData(false);

}

//插件规范，所有的插件必须导出此接口
extern "C"   _declspec(dllexport)   CWnd * GetPlug()
{
	CPlug *p = new CPlug;
	p->Create(CPlug::IDD);
	return  p; 
}





