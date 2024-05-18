
// 039Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "039.h"
#include "039Dlg.h"
#include "afxdialogex.h"

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


// CMy039Dlg 对话框



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


// CMy039Dlg 消息处理程序

BOOL CMy039Dlg::OnInitDialog()
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
	m_list.Create(WS_CHILD | WS_VISIBLE|WS_BORDER| LVS_ICON|LVS_SHOWSELALWAYS, CRect(100, 100, 300, 300), this, 10000);
	//设置控件背景
	m_list.SetBkColor(RGB(255, 0, 0));
	 
	//设置文字背景
	m_list.SetTextBkColor(RGB(0, 255, 255));

	UINT nIconID[]={ IDI_ICON1,IDI_ICON2,IDI_ICON3 };

	static CImageList imglist;
	imglist.Create(32, 32, ILC_COLOR32, 3, 1);
	//设置图标背景

	imglist.SetBkColor(RGB(123, 123, 111));
	for ( int i = 0; i < 3;i++)
	{
		imglist.Add(AfxGetApp()->LoadIcon(nIconID[i]));//将图标添加到CImagelit
	}
	m_list.SetImageList(&imglist, LVSIL_NORMAL);


	m_list.InsertItem(0, L"音乐", 0);
	m_list.InsertItem(0, L"啤酒", 1);
	m_list.InsertItem(0, L"炸鸡", 2);

	m_list.SetItemState(1, LVIS_FOCUSED | LVIS_SELECTED, LVIS_FOCUSED | LVIS_SELECTED);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMy039Dlg::OnPaint()
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
HCURSOR CMy039Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMy039Dlg::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{
 	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);

	// TODO: 在此添加控件通知处理程序代码
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
	// TODO: 在此添加控件通知处理程序代码


	MessageBox(L"右键单击");
	*pResult = 0;
}
