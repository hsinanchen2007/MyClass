
// 011Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "013.h"
#include "013Dlg.h"
#include "afxdialogex.h"
#include "Student.h"

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


// CMy013Dlg �Ի���



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


// CMy013Dlg ��Ϣ�������

BOOL CMy013Dlg::OnInitDialog()
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
	 
	m_list.SetExtendedStyle(m_list.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_list.InsertColumn(0, _T("ѧ��"), LVCFMT_CENTER, 100, 0);
	m_list.InsertColumn(1, _T("����"), LVCFMT_CENTER, 200, 1);
	m_list.InsertColumn(2, _T("����"), LVCFMT_CENTER, 100, 2);

	/*
	m_list.InsertItem(0, _T(""));
	m_list.SetItemText(0, 0, _T("1000"));
	m_list.SetItemText(0, 1, _T("����"));
	m_list.SetItemText(0, 2, _T("10"));

	m_list.InsertItem(1, _T(""));
	m_list.SetItemText(1, 0, _T("1001"));
	m_list.SetItemText(1, 1, _T("����"));
	m_list.SetItemText(1, 2, _T("18"));
	*/
	  


	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMy013Dlg::OnPaint()
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
HCURSOR CMy013Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMy013Dlg::OnBnClickedInsert()
{ 
	//�ÿؼ���ֵͬ����m_id,m_name,m_age������
	UpdateData(true);

	if (m_id.IsEmpty() || m_name.IsEmpty() || m_age.IsEmpty()) {
		MessageBox(_T("��������ݲ���Ϊ�գ�"));
	   return ;
	}

	//����һ��CRecordSet��Ķ���
	CStudent  rs;
	//�����ݼ�
	BOOL  bOpen = rs.Open();

	if (rs.IsOpen()) {
    
		//��������
		rs.AddNew();

		//�ֶθ�ֵ
		rs.m_id = _ttoi(m_id);
		rs.m_name = m_name;
		rs.m_age = _ttoi(m_age);

		//����
		rs.Update();

	}
	//�ر����ݼ�
	rs.Close();

	OnBnClickedSelect();

	MessageBox(_T("�������ݳɹ���"));
	  
}


void CMy013Dlg::OnBnClickedDelete()
{
	
	//�ÿؼ���ֵͬ����m_id,m_name,m_age������
	UpdateData(true);

	if (m_id.IsEmpty()) {
		MessageBox(_T("ɾ��������id����Ϊ�գ�"));
		return;
	}

	//�����id����������
	CString sql;
	sql.Format(_T("SELECT *  FROM  Student WHERE  id =%s"), m_id);

	//����һ��CRecordSet��Ķ���
	CStudent  rs;
	//�����ݼ�
	BOOL  bOpen = rs.Open(AFX_DB_USE_DEFAULT_TYPE, sql);

	if (rs.IsOpen()) {
		//ɾ������
		rs.Delete();

	}
	//�ر����ݼ�
	rs.Close();

	OnBnClickedSelect();

	MessageBox(_T("ɾ�����ݳɹ���"));
	 

}


void CMy013Dlg::OnBnClickedUpdate()
{
	//�ÿؼ���ֵͬ����m_id,m_name,m_age������
	UpdateData(true);

	if (m_id.IsEmpty()  ) {
		MessageBox(_T("�޸ĵ�����id����Ϊ�գ�"));
		return;
	}

	//�����id����������
	CString sql;
	sql.Format(_T("SELECT *  FROM  Student WHERE  id =%s"), m_id);

	//����һ��CRecordSet��Ķ���
	CStudent  rs;
	//�����ݼ�
	BOOL  bOpen = rs.Open(AFX_DB_USE_DEFAULT_TYPE ,sql);

	if (rs.IsOpen()) {

		//��ʼ�޸�
		rs.Edit();

		//�ֶθ��޸�ֵ
		//rs.m_id = _ttoi(m_id);
		rs.m_name = m_name;
		rs.m_age = _ttoi(m_age);

		//����
		rs.Update();

	}
	//�ر����ݼ�
	rs.Close();

	OnBnClickedSelect();

	MessageBox(_T("�޸����ݳɹ���"));
}


void CMy013Dlg::OnBnClickedSelect()
{
	//����б�ؼ��ϵľ�����
	m_list.DeleteAllItems();

	//����һ��CRecordSet��Ķ���
	CStudent  rs;
	//�����ݼ�
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
			//�ƶ�����һ������
			rs.MoveNext();
		} 
	}

	//�ر����ݼ�
	rs.Close();
	 
}


void CMy013Dlg::OnClickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	if (-1 != pNMItemActivate->iItem)        // ���iItem����-1����˵�����б��ѡ��   
	{
		//��ѡ�е���Ϣ����ѡ�б���
		m_id = m_list.GetItemText(pNMItemActivate->iItem, 0);
		m_name = m_list.GetItemText(pNMItemActivate->iItem, 1);
		m_age = m_list.GetItemText(pNMItemActivate->iItem, 2);

		//������ֵˢ�µ��ؼ�
		UpdateData(false);
	}

	*pResult = 0;
}
