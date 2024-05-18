// MyBtn.cpp : 实现文件
//

#include "stdafx.h"
#include "026.h"
#include "MyBtn.h"


// CMyBtn

IMPLEMENT_DYNAMIC(CMyBtn, CButton)

CMyBtn::CMyBtn()
{

	m_color = RGB(255, 0, 0);


}

CMyBtn::~CMyBtn()
{
}


BEGIN_MESSAGE_MAP(CMyBtn, CButton)
	ON_WM_MOUSEHOVER()
	ON_WM_MOUSEMOVE()
	ON_WM_MOUSELEAVE()
END_MESSAGE_MAP()



// CMyBtn 消息处理程序

void CMyBtn::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{

	// TODO:  添加您的代码以绘制指定项
	CDC *pDC = CDC::FromHandle(lpDrawItemStruct->hDC);
	CRect rc = lpDrawItemStruct->rcItem;
	//绘制按钮的边框
	UINT state = lpDrawItemStruct->itemState;
	if (state&ODS_SELECTED)
		pDC->DrawFrameControl(rc, DFC_BUTTON, DFCS_BUTTONPUSH | DFCS_PUSHED);
	else
		pDC->DrawFrameControl(rc, DFC_BUTTON, DFCS_BUTTONPUSH);
	//绘制矩形的背景色（不要覆盖3d的边框）,DeflateRect缩小矩形
	rc.DeflateRect(CSize(GetSystemMetrics(SM_CXEDGE), GetSystemMetrics(SM_CYEDGE)));
	pDC->FillSolidRect(&rc, m_color);

	//设置文字背景透明
	int mode = pDC->SetBkMode(TRANSPARENT);
	//绘制标题
	CString text;
	GetWindowText(text);
	pDC->DrawText(text, &rc, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	//还原之前的背景属性
	pDC->SetBkMode(mode);

}


void CMyBtn::PreSubclassWindow()
{
	// TODO: 在此添加专用代码和/或调用基类
	ModifyStyle(0, BS_OWNERDRAW);//防止第三方使用我们的类时，忘记设置按钮为BS_OWNERDRAW

	CButton::PreSubclassWindow();
}


void CMyBtn::OnMouseHover(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	m_color = RGB(255, 255, 0);
	Invalidate();
	CButton::OnMouseHover(nFlags, point);
}


void CMyBtn::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	TRACKMOUSEEVENT csTIME;
	csTIME.cbSize = sizeof(csTIME);
	csTIME.dwFlags = TME_LEAVE | TME_HOVER;
	csTIME.hwndTrack = m_hWnd;//指定要追踪的窗口
	csTIME.dwHoverTime = 2;//鼠标在按钮上停留超过2ms，才认为状态为hover
	::_TrackMouseEvent(&csTIME);

	CButton::OnMouseMove(nFlags, point);
}


void CMyBtn::OnMouseLeave()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	m_color = RGB(255, 0, 0);
	Invalidate();
	CButton::OnMouseLeave();
}
