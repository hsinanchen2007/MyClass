
// 054Dlg.h : ͷ�ļ�
//

#pragma once


// CMy054Dlg �Ի���
class CMy054Dlg : public CDialogEx
{
// ����
public:
	CMy054Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY054_DIALOG };
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

	CMFCFontComboBox m_font;
public:
	afx_msg void OnCbnSelchangeMfcfontcombo1();
};
