
// 070View.h : CMy070View ��Ľӿ�
//

#pragma once


class CMy070View : public CView
{
protected: // �������л�����
	CMy070View();
	DECLARE_DYNCREATE(CMy070View)

// ����
public:
	CMy070Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CMy070View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // 070View.cpp �еĵ��԰汾
inline CMy070Doc* CMy070View::GetDocument() const
   { return reinterpret_cast<CMy070Doc*>(m_pDocument); }
#endif

