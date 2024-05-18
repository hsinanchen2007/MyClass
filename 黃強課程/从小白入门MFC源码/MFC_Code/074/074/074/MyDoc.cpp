// MyDoc.cpp : 实现文件
//

#include "stdafx.h"
#include "MyDoc.h"


// CMyDoc

IMPLEMENT_DYNCREATE(CMyDoc, CDocument)

CMyDoc::CMyDoc()
{
}

BOOL CMyDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	return TRUE;
}

CMyDoc::~CMyDoc()
{
}


BEGIN_MESSAGE_MAP(CMyDoc, CDocument)
END_MESSAGE_MAP()


// CMyDoc 诊断

#ifdef _DEBUG
void CMyDoc::AssertValid() const
{
	CDocument::AssertValid();
}

#ifndef _WIN32_WCE
void CMyDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif
#endif //_DEBUG

#ifndef _WIN32_WCE
// CMyDoc 序列化

void CMyDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())//存储文件
	{
		// TODO:  在此添加存储代码
		CEditView * pView = (CEditView *)m_viewList.GetHead();
		
		pView->GetEditCtrl().GetWindowText(m_txt);
		ar.WriteString(m_txt);
	}
	else//打开文件
	{
		// TODO:  在此添加加载代码

		//ar.ReadString(m_txt); 只能读取一行
		TCHAR tmp[1024] = {0};
		ar.Read(tmp, 1024);
		m_txt = tmp;
	}
}
#endif


// CMyDoc 命令


void CMyDoc::DeleteContents()
{
	// TODO: 在此添加专用代码和/或调用基类

	m_txt = L"";

	CDocument::DeleteContents();
}
