// MyView.cpp : ʵ���ļ�
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


// CMyView ���

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


// CMyView ��Ϣ�������


void CMyView::OnUpdate(CView* /*pSender*/, LPARAM /*lHint*/, CObject* /*pHint*/)
{
	// TODO: �ڴ����ר�ô����/����û���

	CMyDoc *pDoc = (CMyDoc *)m_pDocument;

	GetEditCtrl().SetWindowText(pDoc->m_txt);
}
