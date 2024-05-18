
// 022Dlg.h : 头文件
//

#pragma once


// CMy022Dlg 对话框
class CMy022Dlg : public CDialogEx
{
// 构造
public:
	CMy022Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY022_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

    private:
        //一个普通按钮
		CButton m_btn;


		//两个单选按钮
		CButton m_RadioBtn1;
		CButton m_RadioBtn2;

		//三个复选按钮

		CButton m_CheckBtn1;
		CButton m_CheckBtn2;
		CButton m_CheckBtn3;




// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedCheck1();
	DECLARE_MESSAGE_MAP()
};
