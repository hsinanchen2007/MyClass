
// 043Dlg.h : ͷ�ļ�
//

#pragma once
#include "Dlg1.h"
#include "Dlg2.h"


// CMy043Dlg �Ի���
class CMy043Dlg : public CDialogEx
{
// ����
public:
	CMy043Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY043_DIALOG };
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

	CTabCtrl m_tab;
	CDlg1 m_dlg1;
	CDlg2 m_dlg2;

public:
	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
};
