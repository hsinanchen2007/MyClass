#pragma once
#include<afxext.h>


// CMyView 视图

class CMyView : public CEditView
{
	DECLARE_DYNCREATE(CMyView)

protected:
	CMyView();           // 动态创建所使用的受保护的构造函数
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


