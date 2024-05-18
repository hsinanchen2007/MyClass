#pragma once


// CPlug 对话框
#include"resource.h"

class CPlug : public CDialog
{
	DECLARE_DYNAMIC(CPlug)

public:
	CPlug(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CPlug();

// 对话框数据
//#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PLUG };
//#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int a;
	int b;
	afx_msg void OnBnClickedOk();
	int c;
};
