
// 057Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "057.h"
#include "057Dlg.h"
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


// CMy057Dlg 对话框



CMy057Dlg::CMy057Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MY057_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy057Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMy057Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMy057Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMy057Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMy057Dlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CMy057Dlg 消息处理程序

BOOL CMy057Dlg::OnInitDialog()
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

void CMy057Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMy057Dlg::OnPaint()
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
HCURSOR CMy057Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMy057Dlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
/*
		CFileDialog dlg(
		true,//打开
		NULL,//默认扩展名
		NULL//默认标记名
		,OFN_HIDEREADONLY| OFN_OVERWRITEPROMPT| OFN_ALLOWMULTISELECT,//标记
		L"源文件(*.cpp)|*.cpp||",//过滤后缀名
		this);//父窗口
		dlg.DoModal();

	if (dlg.DoModal()==IDOK)
	{
		//MessageBox(dlg.GetFileName());
		MessageBox(dlg.GetPathName());

	}
	*/
	CFileDialog dlg(
		false,//保存
		
		L"xxx",//默认扩展名
		L"test",//默认文件名
		 OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT /*| OFN_ALLOWMULTISELECT*/,//标记
		L"源文件(*.cpp)|*.cpp||",//过滤后缀名
		this);//父窗口
	dlg.DoModal();

}


void CMy057Dlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	CFontDialog fontDlg;
	if (fontDlg.DoModal() == IDOK) 
	{

		LOGFONT font;
		fontDlg.GetCurrentFont(&font);
		MessageBox(font.lfFaceName);
	

	}
	
}


void CMy057Dlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	CColorDialog dlg;
	if (dlg.DoModal() == IDOK)
	{
		COLORREF color = dlg.GetColor();
		CString str;
		str.Format(L"%d,%d,%d", GetRValue(color), GetGValue(color), GetBValue(color));
		MessageBox(str);

	}


}
