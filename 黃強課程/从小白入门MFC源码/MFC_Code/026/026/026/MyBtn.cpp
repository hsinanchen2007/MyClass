// MyBtn.cpp : ʵ���ļ�
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



// CMyBtn ��Ϣ�������

void CMyBtn::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{

	// TODO:  ������Ĵ����Ի���ָ����
	CDC *pDC = CDC::FromHandle(lpDrawItemStruct->hDC);
	CRect rc = lpDrawItemStruct->rcItem;
	//���ư�ť�ı߿�
	UINT state = lpDrawItemStruct->itemState;
	if (state&ODS_SELECTED)
		pDC->DrawFrameControl(rc, DFC_BUTTON, DFCS_BUTTONPUSH | DFCS_PUSHED);
	else
		pDC->DrawFrameControl(rc, DFC_BUTTON, DFCS_BUTTONPUSH);
	//���ƾ��εı���ɫ����Ҫ����3d�ı߿�,DeflateRect��С����
	rc.DeflateRect(CSize(GetSystemMetrics(SM_CXEDGE), GetSystemMetrics(SM_CYEDGE)));
	pDC->FillSolidRect(&rc, m_color);

	//�������ֱ���͸��
	int mode = pDC->SetBkMode(TRANSPARENT);
	//���Ʊ���
	CString text;
	GetWindowText(text);
	pDC->DrawText(text, &rc, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	//��ԭ֮ǰ�ı�������
	pDC->SetBkMode(mode);

}


void CMyBtn::PreSubclassWindow()
{
	// TODO: �ڴ����ר�ô����/����û���
	ModifyStyle(0, BS_OWNERDRAW);//��ֹ������ʹ�����ǵ���ʱ���������ð�ťΪBS_OWNERDRAW

	CButton::PreSubclassWindow();
}


void CMyBtn::OnMouseHover(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	m_color = RGB(255, 255, 0);
	Invalidate();
	CButton::OnMouseHover(nFlags, point);
}


void CMyBtn::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	TRACKMOUSEEVENT csTIME;
	csTIME.cbSize = sizeof(csTIME);
	csTIME.dwFlags = TME_LEAVE | TME_HOVER;
	csTIME.hwndTrack = m_hWnd;//ָ��Ҫ׷�ٵĴ���
	csTIME.dwHoverTime = 2;//����ڰ�ť��ͣ������2ms������Ϊ״̬Ϊhover
	::_TrackMouseEvent(&csTIME);

	CButton::OnMouseMove(nFlags, point);
}


void CMyBtn::OnMouseLeave()
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	m_color = RGB(255, 0, 0);
	Invalidate();
	CButton::OnMouseLeave();
}
