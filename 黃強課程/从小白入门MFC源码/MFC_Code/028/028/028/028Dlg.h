
// 028Dlg.h : ͷ�ļ�
//

#pragma once


// CMy028Dlg �Ի���
class CMy028Dlg : public CDialogEx
{
// ����
public:
	CMy028Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY028_DIALOG };
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

private:

	CEdit m_edit;

public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnChangeEdit1();
	afx_msg void OnSetfocusEdit2();
};
