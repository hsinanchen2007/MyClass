
// 011Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"


// CMy013Dlg �Ի���
class CMy013Dlg : public CDialogEx
{
// ����
public:
	CMy013Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY011_DIALOG };
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
	CString m_id;
	afx_msg void OnBnClickedInsert();
	CString m_name;
	CString m_age;
	afx_msg void OnBnClickedDelete();
	afx_msg void OnBnClickedUpdate();
	afx_msg void OnBnClickedSelect();
	CListCtrl m_list;
	afx_msg void OnClickList1(NMHDR *pNMHDR, LRESULT *pResult);
	 
};
