#pragma once


// CNoModalDialog �Ի���

class CNoModalDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CNoModalDialog)

public:
	CNoModalDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CNoModalDialog();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_NOMODAL };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void PostNcDestroy();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
