
// 031Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CMy031Dlg �Ի���
class CMy031Dlg : public CDialogEx
{
// ����
public:
	CMy031Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY031_DIALOG };
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
	CListBox m_listbox;	
	
public:
	CListBox m_listbox2;
	afx_msg void OnLbnSelchangeList1();

};
