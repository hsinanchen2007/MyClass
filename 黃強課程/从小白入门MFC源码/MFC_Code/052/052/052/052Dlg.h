
// 052Dlg.h : ͷ�ļ�
//

#pragma once


// CMy052Dlg �Ի���
class CMy052Dlg : public CDialogEx
{
// ����
public:
	CMy052Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY052_DIALOG };
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

	CMFCEditBrowseCtrl m_editBC;
public:
	afx_msg void OnEnChangeMfceditbrowse1();
};
