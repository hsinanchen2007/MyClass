
// 011Dlg.h : 头文件
//

#pragma once
#include "afxcmn.h"


// CMy013Dlg 对话框
class CMy013Dlg : public CDialogEx
{
// 构造
public:
	CMy013Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY011_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
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
