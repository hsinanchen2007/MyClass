
// 075View.cpp : CMy075View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMy075View 构造/析构

CMy075View::CMy075View()
{
	// TODO: 在此处添加构造代码

}

CMy075View::~CMy075View()
{
}

BOOL CMy075View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy075View 绘制

void CMy075View::OnDraw(CDC* /*pDC*/)
{
	CMy075Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMy075View 打印

BOOL CMy075View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy075View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy075View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy075View 诊断

#ifdef _DEBUG
void CMy075View::AssertValid() const
{
	CView::AssertValid();
}

void CMy075View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy075Doc* CMy075View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy075Doc)));
	return (CMy075Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy075View 消息处理程序
