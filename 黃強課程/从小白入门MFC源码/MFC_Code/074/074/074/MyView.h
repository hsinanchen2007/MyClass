#pragma once
#include<afxext.h>


// CMyView ��ͼ

class CMyView : public CEditView
{
	DECLARE_DYNCREATE(CMyView)

protected:
	CMyView();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CMyView();

public:
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
	virtual void OnUpdate(CView* /*pSender*/, LPARAM /*lHint*/, CObject* /*pHint*/);
};


