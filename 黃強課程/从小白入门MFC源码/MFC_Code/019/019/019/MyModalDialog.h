#pragma once


// CMyModalDialog �Ի���

class CMyModalDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CMyModalDialog)

public:
	CMyModalDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CMyModalDialog();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_Modal };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
