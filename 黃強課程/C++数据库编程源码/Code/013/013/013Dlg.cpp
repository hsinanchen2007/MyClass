
// 011Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "013.h"
#include "013Dlg.h"
#include "afxdialogex.h"
#include "Student.h"

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


// CMy013Dlg 对话框



CMy013Dlg::CMy013Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MY011_DIALOG, pParent)
	, m_id(_T(""))
	, m_name(_T(""))
	, m_age(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy013Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);

	DDX_Text(pDX, IDC_EDIT_ID, m_id);
	DDX_Text(pDX, IDC_EDIT_NAME, m_name);
	DDX_Text(pDX, IDC_EDIT_AGE, m_age);
}

BEGIN_MESSAGE_MAP(CMy013Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(ID_INSERT, &CMy013Dlg::OnBnClickedInsert)
	ON_BN_CLICKED(ID_DELETE, &CMy013Dlg::OnBnClickedDelete)
	ON_BN_CLICKED(ID_UPDATE, &CMy013Dlg::OnBnClickedUpdate)
	ON_BN_CLICKED(ID_SELECT, &CMy013Dlg::OnBnClickedSelect)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, &CMy013Dlg::OnClickList1)
END_MESSAGE_MAP()


// CMy013Dlg 消息处理程序

BOOL CMy013Dlg::OnInitDialog()
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
	 
	m_list.SetExtendedStyle(m_list.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_list.InsertColumn(0, _T("学号"), LVCFMT_CENTER, 100, 0);
	m_list.InsertColumn(1, _T("姓名"), LVCFMT_CENTER, 200, 1);
	m_list.InsertColumn(2, _T("年龄"), LVCFMT_CENTER, 100, 2);

	/*
	m_list.InsertItem(0, _T(""));
	m_list.SetItemText(0, 0, _T("1000"));
	m_list.SetItemText(0, 1, _T("张三"));
	m_list.SetItemText(0, 2, _T("10"));

	m_list.InsertItem(1, _T(""));
	m_list.SetItemText(1, 0, _T("1001"));
	m_list.SetItemText(1, 1, _T("李四"));
	m_list.SetItemText(1, 2, _T("18"));
	*/
	  


	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMy013Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMy013Dlg::OnPaint()
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
HCURSOR CMy013Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMy013Dlg::OnBnClickedInsert()
{ 
	//让控件的值同步到m_id,m_name,m_age变量上
	UpdateData(true);

	if (m_id.IsEmpty() || m_name.IsEmpty() || m_age.IsEmpty()) {
		MessageBox(_T("插入的数据不能为空！"));
	   return ;
	}

	//定义一个CRecordSet类的对象
	CStudent  rs;
	//打开数据集
	BOOL  bOpen = rs.Open();

	if (rs.IsOpen()) {
    
		//增加新行
		rs.AddNew();

		//字段赋值
		rs.m_id = _ttoi(m_id);
		rs.m_name = m_name;
		rs.m_age = _ttoi(m_age);

		//更新
		rs.Update();

	}
	//关闭数据集
	rs.Close();

	OnBnClickedSelect();

	MessageBox(_T("插入数据成功！"));
	  
}


void CMy013Dlg::OnBnClickedDelete()
{
	
	//让控件的值同步到m_id,m_name,m_age变量上
	UpdateData(true);

	if (m_id.IsEmpty()) {
		MessageBox(_T("删除的数据id不能为空！"));
		return;
	}

	//查出该id的这条数据
	CString sql;
	sql.Format(_T("SELECT *  FROM  Student WHERE  id =%s"), m_id);

	//定义一个CRecordSet类的对象
	CStudent  rs;
	//打开数据集
	BOOL  bOpen = rs.Open(AFX_DB_USE_DEFAULT_TYPE, sql);

	if (rs.IsOpen()) {
		//删除该行
		rs.Delete();

	}
	//关闭数据集
	rs.Close();

	OnBnClickedSelect();

	MessageBox(_T("删除数据成功！"));
	 

}


void CMy013Dlg::OnBnClickedUpdate()
{
	//让控件的值同步到m_id,m_name,m_age变量上
	UpdateData(true);

	if (m_id.IsEmpty()  ) {
		MessageBox(_T("修改的数据id不能为空！"));
		return;
	}

	//查出该id的这条数据
	CString sql;
	sql.Format(_T("SELECT *  FROM  Student WHERE  id =%s"), m_id);

	//定义一个CRecordSet类的对象
	CStudent  rs;
	//打开数据集
	BOOL  bOpen = rs.Open(AFX_DB_USE_DEFAULT_TYPE ,sql);

	if (rs.IsOpen()) {

		//开始修改
		rs.Edit();

		//字段赋修改值
		//rs.m_id = _ttoi(m_id);
		rs.m_name = m_name;
		rs.m_age = _ttoi(m_age);

		//更新
		rs.Update();

	}
	//关闭数据集
	rs.Close();

	OnBnClickedSelect();

	MessageBox(_T("修改数据成功！"));
}


void CMy013Dlg::OnBnClickedSelect()
{
	//清空列表控件上的旧数据
	m_list.DeleteAllItems();

	//定义一个CRecordSet类的对象
	CStudent  rs;
	//打开数据集
	BOOL  bOpen=rs.Open();

	if (rs.IsOpen()) {

		int row = 0;
		while (!rs.IsEOF())
		{
			m_list.InsertItem(row, _T(""));

			CString strID;
			strID.Format(_T("%d"), rs.m_id);
			m_list.SetItemText(row, 0, strID);

			m_list.SetItemText(row, 1,  rs.m_name);

			CString strAge;
			strAge.Format(_T("%d"), rs.m_age); 
			m_list.SetItemText(row, 2, strAge);

			++row;
			//移动到下一行数据
			rs.MoveNext();
		} 
	}

	//关闭数据集
	rs.Close();
	 
}


void CMy013Dlg::OnClickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码

	if (-1 != pNMItemActivate->iItem)        // 如果iItem不是-1，就说明有列表项被选择   
	{
		//将选中的信息赋给选中变量
		m_id = m_list.GetItemText(pNMItemActivate->iItem, 0);
		m_name = m_list.GetItemText(pNMItemActivate->iItem, 1);
		m_age = m_list.GetItemText(pNMItemActivate->iItem, 2);

		//将变量值刷新到控件
		UpdateData(false);
	}

	*pResult = 0;
}
