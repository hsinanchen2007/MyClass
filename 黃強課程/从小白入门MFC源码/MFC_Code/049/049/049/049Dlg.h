
// 049Dlg.h : ͷ�ļ�
//

#pragma once


// CMy049Dlg �Ի���
class CMy049Dlg : public CDialogEx
{
// ����
public:
	CMy049Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY049_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	CSplitButton m_split;
public:
	afx_msg void OnBnClickedSplit();
	afx_msg void On32771();
};
