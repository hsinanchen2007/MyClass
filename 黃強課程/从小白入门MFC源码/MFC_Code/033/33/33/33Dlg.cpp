
// 33Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "33.h"
#include "33Dlg.h"
#include "afxdialogex.h"
#include "Resource.h"

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


// CMy33Dlg �Ի���



CMy33Dlg::CMy33Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MY33_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy33Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMy33Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CMy33Dlg ��Ϣ�������

BOOL CMy33Dlg::OnInitDialog()
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

	m_picture.Create(L"xxx", WS_CHILD | WS_VISIBLE | WS_BORDER | SS_BITMAP|SS_CENTERIMAGE, CRect(100,100, 300, 300), this, 10000);
	
	//HBITMAP hBmp = LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BITMAP1));
	//m_picture.SetBitmap(hBmp);

	CRect rc;
	m_picture.GetClientRect(&rc);
	CDC*dc = m_picture.GetDC();

	CBitmap bitmap1;
	bitmap1.LoadBitmapW(IDB_BITMAP1);
	BITMAP bmp1;
	bitmap1.GetBitmap(&bmp1);

	CDC memdc;
	memdc.CreateCompatibleDC(dc);
	memdc.SelectObject(&bitmap1);
	CBitmap bitmap2;//������λͼ
	bitmap2.CreateCompatibleBitmap(dc, rc.right, rc.bottom);

	CDC memdc2;
	memdc2.CreateCompatibleDC(dc);
	memdc2.SelectObject(&bitmap2);
	//����λͼ�У�����ָ���Ĵ�Сת��

	memdc2.StretchBlt(rc.left, rc.top, rc.Width(), rc.Height(), &memdc, 0, 0, bmp1.bmWidth,
		bmp1.bmHeight, SRCCOPY);

	m_picture.SetBitmap((HBITMAP)bitmap2.Detach());
	m_picture.ReleaseDC(dc);
	memdc.DeleteDC();
	memdc2.DeleteDC();











	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMy33Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMy33Dlg::OnPaint()
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
HCURSOR CMy33Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

