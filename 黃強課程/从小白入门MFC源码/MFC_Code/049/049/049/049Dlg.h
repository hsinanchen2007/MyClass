
// 049Dlg.h : 头文件
//

#pragma once


// CMy049Dlg 对话框
class CMy049Dlg : public CDialogEx
{
// 构造
public:
	CMy049Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY049_DIALOG };
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
	CSplitButton m_split;
public:
	afx_msg void OnBnClickedSplit();
	afx_msg void On32771();
};
