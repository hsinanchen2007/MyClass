// Plug.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Plug.h"
#include "afxdialogex.h"


// CPlug �Ի���

IMPLEMENT_DYNAMIC(CPlug, CDialog)

CPlug::CPlug(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_PLUG, pParent) 
	, b(0)
	, a(0)
	, c(_T(""))
{

}

CPlug::~CPlug()
{
}

void CPlug::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//  DDX_Text(pDX, IDC_EDIT2, a);
	DDX_Text(pDX, IDC_EDIT1, b);
	DDX_Text(pDX, IDC_EDIT2, a);
	DDX_Text(pDX, IDC_STATIC1, c);
}


BEGIN_MESSAGE_MAP(CPlug, CDialog)
	ON_BN_CLICKED(IDOK, &CPlug::OnBnClickedOk)
END_MESSAGE_MAP()


// CPlug ��Ϣ�������


void CPlug::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//CDialog::OnOK();
	UpdateData(true);
	if (a > b)  c = CString(L"a��");
	else c = CString(L"b��"); 
	UpdateData(false);


}


//����淶�����еĲ�����뵼���˽ӿ�
extern "C"   _declspec(dllexport)   CWnd * GetPlug()
{
	CPlug *p = new CPlug;
	p->Create(CPlug::IDD);
	return  p;
}

