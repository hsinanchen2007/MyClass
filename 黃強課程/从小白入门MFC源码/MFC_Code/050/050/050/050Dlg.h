
// 050Dlg.h : ͷ�ļ�
//

#pragma once


// CMy050Dlg �Ի���
class CMy050Dlg : public CDialogEx
{
// ����
public:
	CMy050Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY050_DIALOG };
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

	CLinkCtrl m_link;
public:
	afx_msg void OnNMClickSyslink1(NMHDR *pNMHDR, LRESULT *pResult);
};
