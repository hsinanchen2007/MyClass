
// 022Dlg.h : ͷ�ļ�
//

#pragma once


// CMy022Dlg �Ի���
class CMy022Dlg : public CDialogEx
{
// ����
public:
	CMy022Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY022_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

    private:
        //һ����ͨ��ť
		CButton m_btn;


		//������ѡ��ť
		CButton m_RadioBtn1;
		CButton m_RadioBtn2;

		//������ѡ��ť

		CButton m_CheckBtn1;
		CButton m_CheckBtn2;
		CButton m_CheckBtn3;




// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedCheck1();
	DECLARE_MESSAGE_MAP()
};
