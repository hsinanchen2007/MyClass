
// 062Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "062.h"
#include "062Dlg.h"
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


// CMy062Dlg 对话框



CMy062Dlg::CMy062Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MY062_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy062Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMy062Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CMy062Dlg 消息处理程序

BOOL CMy062Dlg::OnInitDialog()
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

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMy062Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMy062Dlg::OnPaint()
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
	/*
		
		CPaintDC dc(this); // 用于绘制的设备上下文
		 //1.创建与本窗口兼容的第二个缓冲区(尺寸只有1.1像素)
		CDC memDC;
		memDC.CreateCompatibleDC(&dc);

		CBitmap bmp;
		bmp.LoadBitmap(IDB_BITMAP1);

		//2.把位图选进兼容DC中，作为画布区域

		memDC.SelectObject(&bmp);
		//在画布（缓冲区二）上画东西
		memDC.SetBkMode(TRANSPARENT);
		memDC.TextOut(0, 0, L"这是我的图片");

		//3.把缓冲区二的拷贝到第一个缓冲区上（立即显示）
		CRect rect;
		GetClientRect(rect);


		//dc.BitBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, SRCCOPY);

		dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0,720,451, SRCCOPY);//拉伸图片尺寸至符合窗口尺寸
       */
		

		//////使用一块空的位图作为画布/////////////
		CPaintDC dc(this); // 用于绘制的设备上下文
		//1.创建与本窗口兼容的第二个缓冲区(尺寸只有1.1像素)
		CDC memDC;
		memDC.CreateCompatibleDC(&dc);

	    CRect rect;
		GetClientRect(rect);

		//2.创建兼容位图，把位图选进兼容DC中，作为画布区域
		CBitmap bmp;
		bmp.CreateCompatibleBitmap(&memDC,rect.Width(),rect.Height());
		memDC.SelectObject(&bmp);
		//默认是黑色，填充一个背景色
		memDC.FillSolidRect(CRect(0, 0, rect.Width(), rect.Height()), RGB(240, 240, 240));
		//在画布（缓冲区二）上画东西
		memDC.SetBkMode(TRANSPARENT);
		memDC.Rectangle(100, 100, 200, 200);
		memDC.Ellipse(CRect(100, 100, 200, 200));
	
		//3.把缓冲区二的拷贝到第一个缓冲区上（立即显示）
		

		//dc.BitBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, SRCCOPY);

		dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, 300, 300, SRCCOPY);//拉伸图片尺寸至符合窗口尺寸


		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMy062Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

