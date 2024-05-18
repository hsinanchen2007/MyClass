// MyView.cpp : 实现文件
//

#include "stdafx.h"
#include "MyView.h"
#include "MyDoc.h"


// CMyView

IMPLEMENT_DYNCREATE(CMyView, CEditView)

CMyView::CMyView()
{

}

CMyView::~CMyView()
{
}

BEGIN_MESSAGE_MAP(CMyView, CEditView)
END_MESSAGE_MAP()


// CMyView 诊断

#ifdef _DEBUG
void CMyView::AssertValid() const
{
	CEditView::AssertValid();
}

#ifndef _WIN32_WCE
void CMyView::Dump(CDumpContext& dc) const
{
	CEditView::Dump(dc);
}
#endif
#endif //_DEBUG


// CMyView 消息处理程序


void CMyView::OnUpdate(CView* /*pSender*/, LPARAM /*lHint*/, CObject* /*pHint*/)
{
	// TODO: 在此添加专用代码和/或调用基类

	CMyDoc *pDoc = (CMyDoc *)m_pDocument;

	GetEditCtrl().SetWindowText(pDoc->m_txt);
}
