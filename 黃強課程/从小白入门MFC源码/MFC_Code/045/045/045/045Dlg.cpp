
// 045Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "045.h"
#include "045Dlg.h"
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


// CMy045Dlg 对话框



CMy045Dlg::CMy045Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MY045_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy045Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMy045Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(10000, &CMy045Dlg::OnEnChangeRichedit21)
END_MESSAGE_MAP()


// CMy045Dlg 消息处理程序

BOOL CMy045Dlg::OnInitDialog()
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
	m_rich.Create(WS_CHILD | WS_VISIBLE | WS_BORDER|ES_MULTILINE, CRect(50, 50, 250, 250), this, 10000);
	m_rich.SetWindowText(L"对话框上使用Rich Edit控件");
	

	CHARFORMAT cf;
	cf.cbSize = sizeof(CHARFORMAT);
	m_rich.GetDefaultCharFormat(cf);


	//设置粗体，取消用cf.dwEffects&=～CFE_BOLD;
	cf.dwMask |= CFM_BOLD;
	cf.dwEffects |= CFE_BOLD;

	
	//设置斜体，取消用cf.dwEffects&=～CFE_ITALIC;
	cf.dwMask |= CFM_ITALIC;
	cf.dwEffects |= CFE_ITALIC;
	//设置下划线
	cf.dwMask |= CFM_UNDERLINE;
	cf.dwEffects |= CFE_UNDERLINE;
	cf.dwMask |= CFM_SIZE;
	cf.yHeight = 24 * 24;

	cf.dwEffects &= ~CFE_AUTOCOLOR;
	cf.dwMask |= CFM_COLOR;
	cf.crTextColor = RGB(255, 255, 0);


	m_rich.SetSel(4, 6);
	m_rich.SetSelectionCharFormat(cf);

	m_rich.SetFocus();
	//设置消息掩码
	m_rich.SetEventMask(ENM_CHANGE);
	

	return FALSE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMy045Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMy045Dlg::OnPaint()
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
HCURSOR CMy045Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMy045Dlg::OnEnChangeRichedit21()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	CString str;
	m_rich.GetWindowText(str);
	MessageBox(str);
}
