
// 022Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "022.h"
#include "022Dlg.h"
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


// CMy022Dlg 对话框



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


// CMy022Dlg 消息处理程序
void CMy022Dlg::OnBnClickedButton1()
{
	MessageBox(L"按钮点击");

}
void CMy022Dlg::OnBnClickedRadio1()
{
	MessageBox(L"Radio按钮点击");

}
void CMy022Dlg::OnBnClickedCheck1()
{

	MessageBox(L"Check按钮点击");
}


BOOL CMy022Dlg::OnInitDialog()
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
	//创建按钮

	m_btn.Create(L"普通按钮", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		CRect(50, 50, 150, 150), this, 10000);
	m_RadioBtn1.Create(L"男", WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
		CRect(150, 150, 200, 200), this, 10001);
	m_RadioBtn2.Create(L"女", WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
		CRect(150, 200, 200, 250), this, 10002);
	m_CheckBtn1.Create(L"篮球", WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX,
		CRect(200, 50, 250, 100), this, 10003);
	m_CheckBtn2.Create(L"音乐", WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX,
			CRect(200, 100, 250, 150), this, 10004);
	m_CheckBtn3.Create(L"编程", WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX,
		CRect(200, 150, 250, 200), this, 10005);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMy022Dlg::OnPaint()
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
HCURSOR CMy022Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

