
// 075View.h : CMy075View ��Ľӿ�
//

#pragma once


class CMy075View : public CView
{
protected: // �������л�����
	CMy075View();
	DECLARE_DYNCREATE(CMy075View)

// ����
public:
	CMy075Doc* GetDocument() const;

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
	virtual ~CMy075View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // 075View.cpp �еĵ��԰汾
inline CMy075Doc* CMy075View::GetDocument() const
   { return reinterpret_cast<CMy075Doc*>(m_pDocument); }
#endif

