
// 070View.cpp : CMy070View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "070.h"
#endif

#include "070Doc.h"
#include "070View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy070View

IMPLEMENT_DYNCREATE(CMy070View, CView)

BEGIN_MESSAGE_MAP(CMy070View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMy070View ����/����

CMy070View::CMy070View()
{
	// TODO: �ڴ˴���ӹ������

}

CMy070View::~CMy070View()
{
}

BOOL CMy070View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy070View ����

void CMy070View::OnDraw(CDC* /*pDC*/)
{
	CMy070Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMy070View ��ӡ

BOOL CMy070View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy070View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy070View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMy070View ���

#ifdef _DEBUG
void CMy070View::AssertValid() const
{
	CView::AssertValid();
}

void CMy070View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy070Doc* CMy070View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy070Doc)));
	return (CMy070Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy070View ��Ϣ�������
