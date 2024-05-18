
// 043Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "043.h"
#include "043Dlg.h"
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


// CMy043Dlg �Ի���



CMy043Dlg::CMy043Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MY043_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy043Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMy043Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TCN_SELCHANGE, 10000, &CMy043Dlg::OnTcnSelchangeTab1)
END_MESSAGE_MAP()


// CMy043Dlg ��Ϣ�������

BOOL CMy043Dlg::OnInitDialog()
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

	m_tab.Create(WS_CHILD | WS_VISIBLE|TCS_TABS, CRect(100, 100, 400, 400), this, 10000);
	m_tab.InsertItem(0, L"��������", 0);
	m_tab.InsertItem(0, L"ѧ����Ϣ", 1);
	m_tab.InsertItem(0, L"��������", 1);
	m_tab.SetCurSel(1);

	UINT nIconlID[] = { IDI_ICON1,IDI_ICON2, IDI_ICON3 };
	static CImageList imglist;
	imglist.Create(16, 16, ILC_COLOR24, 3, 1);

	for (int i = 0; i < 3; i++)
	{
		imglist.Add(theApp.LoadIcon(nIconlID[i]));
		
	}
	m_tab.SetImageList(&imglist);

	m_dlg1.Create(IDD_DIALOG1, &m_tab);
	m_dlg2.Create(IDD_DIALOG2, &m_tab);

	m_dlg1.ShowWindow(SW_HIDE);
	m_dlg2.ShowWindow(SW_SHOW); 
	CRect rc;
	m_tab.GetClientRect(&rc);

	rc.DeflateRect(30, 30);
	m_dlg1.MoveWindow(rc);
	m_dlg2.MoveWindow(rc);



	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMy043Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMy043Dlg::OnPaint()
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
HCURSOR CMy043Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMy043Dlg::OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int cur = m_tab.GetCurSel();
	switch (cur)
	{

	case 0:
		m_dlg1.ShowWindow(SW_SHOW);
		m_dlg2.ShowWindow(SW_HIDE);
		break;

	case 1:

		m_dlg1.ShowWindow(SW_HIDE);
		m_dlg2.ShowWindow(SW_SHOW);
		break;
	}

	*pResult = 0;
}
