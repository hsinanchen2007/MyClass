
// 056Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxshelltreectrl.h"


// CMy056Dlg �Ի���
class CMy056Dlg : public CDialogEx
{
// ����
public:
	CMy056Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY056_DIALOG };
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

	CMFCShellListCtrl m_shellList;
public:
	afx_msg void OnLvnItemchangedMfcshelllist1(NMHDR *pNMHDR, LRESULT *pResult);
	CMFCShellTreeCtrl m_shellTree;
	afx_msg void OnTvnSelchangedMfcshelltree1(NMHDR *pNMHDR, LRESULT *pResult);
};
