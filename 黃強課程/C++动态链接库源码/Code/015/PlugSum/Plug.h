#pragma once


// CPlug �Ի���
#include"resource.h"

class CPlug : public CDialog
{
	DECLARE_DYNAMIC(CPlug)

public:
	CPlug(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CPlug();

// �Ի�������
//#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PLUG };
//#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	int a;
	int b;
	afx_msg void OnBnClickedOk();
	int c;
};
