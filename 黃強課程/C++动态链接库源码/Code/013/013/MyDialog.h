#pragma once


// CMyDialog �Ի���

class CMyDialog : public CDialog
{
	DECLARE_DYNAMIC(CMyDialog)

public:
	CMyDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CMyDialog();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MYDIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
