
// 041Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "041.h"
#include "041Dlg.h"
#include "afxdialogex.h"
#include  "resource.h"

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


// CMy041Dlg �Ի���



CMy041Dlg::CMy041Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MY041_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy041Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMy041Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(LVN_ITEMCHANGED, 10000, &CMy041Dlg::OnLvnItemchangedList1)
	ON_NOTIFY(LVN_ITEMCHANGED, 10001, &CMy041Dlg::OnLvnItemchangedList1)
END_MESSAGE_MAP()


// CMy041Dlg ��Ϣ�������

BOOL CMy041Dlg::OnInitDialog()
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

	m_list.Create(WS_CHILD | WS_VISIBLE | WS_BORDER |/* LVS_SMALLICON |*/ LVS_LIST| LVS_SHOWSELALWAYS, CRect(100, 100, 300, 300), this, 10000);

	static CImageList imglist;
	imglist.Create(16,16,ILC_COLOR24,3,1);
	imglist.Add(AfxGetApp()->LoadIcon(IDI_ICON1));
	imglist.Add(AfxGetApp()->LoadIcon(IDI_ICON2));
	imglist.Add(AfxGetApp()->LoadIcon(IDI_ICON3));

	m_list.SetImageList(&imglist, LVSIL_SMALL);

	m_list.InsertItem(0, L"����", 0);
	m_list.InsertItem(0, L"ơ��", 1);
	m_list.InsertItem(0, L"ը��", 2);


	//������ʽ
	m_list2.Create(WS_CHILD | WS_VISIBLE | WS_BORDER | LVS_REPORT|LVS_SHOWSELALWAYS, CRect(400, 100, 700, 300), this, 10001);
	//��������

	m_list2.SetExtendedStyle(/*LVS_SHOWSELALWAYS | LVS_EX_CHECKBOXES |*/ LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_list2.InsertColumn(0, _T("����"), LVCFMT_LEFT, 100);
	m_list2.InsertColumn(1, _T("�Ա�"), LVCFMT_LEFT, 100);
	m_list2.InsertColumn(2, L"����", LVCFMT_LEFT ,100);
	m_list2.InsertItem(0, L"����С", 0);//�����һ�е�һ��
	m_list2.SetItemText(0, 1, L"��");//�����һ�еڶ���
	m_list2.SetItemText(0, 2, L"19");//�����һ�е�����
	m_list2.InsertItem(1, L"����", 0);//�����һ�е�һ��
	m_list2.SetItemText(1, 1, L"Ů");//�����һ�еڶ���
	m_list2.SetItemText(1, 2, L"29");//�����һ�е�����


	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMy041Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMy041Dlg::OnPaint()
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
HCURSOR CMy041Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMy041Dlg::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);

	// TODO: �ڴ���ӿؼ�֪ͨ����������

	if ((pNMLV->uChanged == LVIF_STATE)&&(pNMLV->uNewState & LVIS_SELECTED))
	{

		if (pNMLV->hdr.hwndFrom==m_list.GetSafeHwnd())
		{
			CString str = m_list.GetItemText(pNMLV->iItem, pNMLV->iSubItem);
			MessageBox(str);
		}
		if (pNMLV->hdr.hwndFrom == m_list2.GetSafeHwnd())
		{
			CString str = m_list2.GetItemText(pNMLV->iItem, pNMLV->iSubItem/*0,1,2*/);
			MessageBox(str);
		}

		
	}


	*pResult = 0;
}
