
// 060Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "060.h"
#include "060Dlg.h"
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


// CMy060Dlg 对话框



CMy060Dlg::CMy060Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MY060_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy060Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMy060Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMy060Dlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CMy060Dlg 消息处理程序

BOOL CMy060Dlg::OnInitDialog()
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

void CMy060Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMy060Dlg::OnPaint()
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
HCURSOR CMy060Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMy060Dlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码

	CDC*pDC = GetDC();
	pDC->MoveTo(CPoint(10, 10));
	pDC->LineTo(CPoint(200, 300));

	CPen pen;
	pen.CreatePen(PS_SOLID, 2, RGB(0, 255, 0));
	pDC->Rectangle(10, 20, 100, 100);//画矩形

	CBrush bsh(RGB(0, 0, 255));//改背景
	CBrush *pOld = pDC->SelectObject(&bsh);

	pDC->Ellipse(10, 200,110,310);
	pDC->SelectObject(pOld);

	pDC->RoundRect(10, 350, 110, 400, 20, 20);//后两个参数指定椭圆的宽和高
	pDC->FillRect(CRect(250, 200, 300, 350), &bsh);
	//改变文字背景颜色
	pDC->SetBkColor(RGB(23, 201, 56));
	//设置背景模式
	pDC->SetBkMode(TRANSPARENT);


	//写字
	pDC->Rectangle(300, 50, 480, 150);
	pDC->TextOut(1, 300, L"hello!");
	pDC->DrawText(L"黄老师精品课堂",CRect(300,50,480,150),DT_RIGHT);

	//获取当前文字的高度
	TEXTMETRIC tm;
	pDC->GetTextMetrics(&tm);
	CString str;
	str.Format(L"字体高度%d   最大字符宽%d", tm.tmHeight, tm.tmMaxCharWidth);
	pDC->TextOut(200, 200, str);

	ReleaseDC(pDC);

}
