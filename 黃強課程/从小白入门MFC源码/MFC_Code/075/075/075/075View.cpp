
// 075View.cpp : CMy075View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "075.h"
#endif

#include "075Doc.h"
#include "075View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy075View

IMPLEMENT_DYNCREATE(CMy075View, CView)

BEGIN_MESSAGE_MAP(CMy075View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMy075View ����/����

CMy075View::CMy075View()
{
	// TODO: �ڴ˴���ӹ������

}

CMy075View::~CMy075View()
{
}

BOOL CMy075View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy075View ����

void CMy075View::OnDraw(CDC* /*pDC*/)
{
	CMy075Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMy075View ��ӡ

BOOL CMy075View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy075View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy075View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMy075View ���

#ifdef _DEBUG
void CMy075View::AssertValid() const
{
	CView::AssertValid();
}

void CMy075View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy075Doc* CMy075View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy075Doc)));
	return (CMy075Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy075View ��Ϣ�������
