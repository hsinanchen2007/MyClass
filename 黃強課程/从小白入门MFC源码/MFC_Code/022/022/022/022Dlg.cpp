
// 022Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "022.h"
#include "022Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMy022Dlg �Ի���



CMy022Dlg::CMy022Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MY022_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy022Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMy022Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(10000,&CMy022Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(10001, &CMy022Dlg::OnBnClickedRadio1)
	ON_BN_CLICKED(10003, &CMy022Dlg::OnBnClickedCheck1)
END_MESSAGE_MAP()


// CMy022Dlg ��Ϣ�������
void CMy022Dlg::OnBnClickedButton1()
{
	MessageBox(L"��ť���");

}
void CMy022Dlg::OnBnClickedRadio1()
{
	MessageBox(L"Radio��ť���");

}
void CMy022Dlg::OnBnClickedCheck1()
{

	MessageBox(L"Check��ť���");
}


BOOL CMy022Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	//������ť

	m_btn.Create(L"��ͨ��ť", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		CRect(50, 50, 150, 150), this, 10000);
	m_RadioBtn1.Create(L"��", WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
		CRect(150, 150, 200, 200), this, 10001);
	m_RadioBtn2.Create(L"Ů", WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
		CRect(150, 200, 200, 250), this, 10002);
	m_CheckBtn1.Create(L"����", WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX,
		CRect(200, 50, 250, 100), this, 10003);
	m_CheckBtn2.Create(L"����", WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX,
			CRect(200, 100, 250, 150), this, 10004);
	m_CheckBtn3.Create(L"���", WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX,
		CRect(200, 150, 250, 200), this, 10005);
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMy022Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMy022Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMy022Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

