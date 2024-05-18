
// 041Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "041.h"
#include "041Dlg.h"
#include "afxdialogex.h"
#include  "resource.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CMy041Dlg 对话框



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


// CMy041Dlg 消息处理程序

BOOL CMy041Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	m_list.Create(WS_CHILD | WS_VISIBLE | WS_BORDER |/* LVS_SMALLICON |*/ LVS_LIST| LVS_SHOWSELALWAYS, CRect(100, 100, 300, 300), this, 10000);

	static CImageList imglist;
	imglist.Create(16,16,ILC_COLOR24,3,1);
	imglist.Add(AfxGetApp()->LoadIcon(IDI_ICON1));
	imglist.Add(AfxGetApp()->LoadIcon(IDI_ICON2));
	imglist.Add(AfxGetApp()->LoadIcon(IDI_ICON3));

	m_list.SetImageList(&imglist, LVSIL_SMALL);

	m_list.InsertItem(0, L"音乐", 0);
	m_list.InsertItem(0, L"啤酒", 1);
	m_list.InsertItem(0, L"炸鸡", 2);


	//报表样式
	m_list2.Create(WS_CHILD | WS_VISIBLE | WS_BORDER | LVS_REPORT|LVS_SHOWSELALWAYS, CRect(400, 100, 700, 300), this, 10001);
	//插入三列

	m_list2.SetExtendedStyle(/*LVS_SHOWSELALWAYS | LVS_EX_CHECKBOXES |*/ LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_list2.InsertColumn(0, _T("姓名"), LVCFMT_LEFT, 100);
	m_list2.InsertColumn(1, _T("性别"), LVCFMT_LEFT, 100);
	m_list2.InsertColumn(2, L"年龄", LVCFMT_LEFT ,100);
	m_list2.InsertItem(0, L"王二小", 0);//插入第一行第一列
	m_list2.SetItemText(0, 1, L"男");//插入第一行第二列
	m_list2.SetItemText(0, 2, L"19");//插入第一行第三列
	m_list2.InsertItem(1, L"李四", 0);//插入第一行第一列
	m_list2.SetItemText(1, 1, L"女");//插入第一行第二列
	m_list2.SetItemText(1, 2, L"29");//插入第一行第三列


	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMy041Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMy041Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMy041Dlg::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);

	// TODO: 在此添加控件通知处理程序代码

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
