
// 070View.cpp : CMy070View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMy070View 构造/析构

CMy070View::CMy070View()
{
	// TODO: 在此处添加构造代码

}

CMy070View::~CMy070View()
{
}

BOOL CMy070View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy070View 绘制

void CMy070View::OnDraw(CDC* /*pDC*/)
{
	CMy070Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMy070View 打印

BOOL CMy070View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy070View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy070View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy070View 诊断

#ifdef _DEBUG
void CMy070View::AssertValid() const
{
	CView::AssertValid();
}

void CMy070View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy070Doc* CMy070View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy070Doc)));
	return (CMy070Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy070View 消息处理程序
