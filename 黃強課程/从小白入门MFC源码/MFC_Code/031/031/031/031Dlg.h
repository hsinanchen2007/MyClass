
// 031Dlg.h : 头文件
//

#pragma once
#include "afxwin.h"


// CMy031Dlg 对话框
class CMy031Dlg : public CDialogEx
{
// 构造
public:
	CMy031Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY031_DIALOG };
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

private:
	CListBox m_listbox;	
	
public:
	CListBox m_listbox2;
	afx_msg void OnLbnSelchangeList1();

};
