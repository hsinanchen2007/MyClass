
// 058Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CMy058Dlg �Ի���
class CMy058Dlg : public CDialogEx
{
// ����
public:
	CMy058Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY058_DIALOG };
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


public:
	CStatic m_lbl;
	afx_msg void OnBnClickedSet();
	afx_msg void OnBnClickedKill();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
