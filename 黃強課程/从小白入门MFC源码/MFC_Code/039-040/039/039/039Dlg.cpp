
// 039Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "039.h"
#include "039Dlg.h"
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


// CMy039Dlg �Ի���



CMy039Dlg::CMy039Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MY039_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy039Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMy039Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(LVN_ITEMCHANGED, 10000, &CMy039Dlg::OnLvnItemchangedList1)
	ON_NOTIFY(NM_RCLICK, 10000, &CMy039Dlg::OnNMRClickList1)
END_MESSAGE_MAP()


// CMy039Dlg ��Ϣ�������

BOOL CMy039Dlg::OnInitDialog()
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
	m_list.Create(WS_CHILD | WS_VISIBLE|WS_BORDER| LVS_ICON|LVS_SHOWSELALWAYS, CRect(100, 100, 300, 300), this, 10000);
	//���ÿؼ�����
	m_list.SetBkColor(RGB(255, 0, 0));
	 
	//�������ֱ���
	m_list.SetTextBkColor(RGB(0, 255, 255));

	UINT nIconID[]={ IDI_ICON1,IDI_ICON2,IDI_ICON3 };

	static CImageList imglist;
	imglist.Create(32, 32, ILC_COLOR32, 3, 1);
	//����ͼ�걳��

	imglist.SetBkColor(RGB(123, 123, 111));
	for ( int i = 0; i < 3;i++)
	{
		imglist.Add(AfxGetApp()->LoadIcon(nIconID[i]));//��ͼ����ӵ�CImagelit
	}
	m_list.SetImageList(&imglist, LVSIL_NORMAL);


	m_list.InsertItem(0, L"����", 0);
	m_list.InsertItem(0, L"ơ��", 1);
	m_list.InsertItem(0, L"ը��", 2);

	m_list.SetItemState(1, LVIS_FOCUSED | LVIS_SELECTED, LVIS_FOCUSED | LVIS_SELECTED);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMy039Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMy039Dlg::OnPaint()
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
HCURSOR CMy039Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMy039Dlg::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{
 	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);

	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (pNMLV->uChanged == LVIF_STATE)
	{
		if (pNMLV->uNewState&LVIS_SELECTED)
		{
			int nItem = pNMLV->iItem;
			CString str = m_list.GetItemText(nItem, 0);
			MessageBox(str);
	}
	}
	*pResult = 0;
}


void CMy039Dlg::OnNMRClickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������


	MessageBox(L"�Ҽ�����");
	*pResult = 0;
}
