
// 062Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "062.h"
#include "062Dlg.h"
#include "afxdialogex.h"

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


// CMy062Dlg �Ի���



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


// CMy062Dlg ��Ϣ�������

BOOL CMy062Dlg::OnInitDialog()
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

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMy062Dlg::OnPaint()
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
	/*
		
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������
		 //1.�����뱾���ڼ��ݵĵڶ���������(�ߴ�ֻ��1.1����)
		CDC memDC;
		memDC.CreateCompatibleDC(&dc);

		CBitmap bmp;
		bmp.LoadBitmap(IDB_BITMAP1);

		//2.��λͼѡ������DC�У���Ϊ��������

		memDC.SelectObject(&bmp);
		//�ڻ����������������ϻ�����
		memDC.SetBkMode(TRANSPARENT);
		memDC.TextOut(0, 0, L"�����ҵ�ͼƬ");

		//3.�ѻ��������Ŀ�������һ���������ϣ�������ʾ��
		CRect rect;
		GetClientRect(rect);


		//dc.BitBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, SRCCOPY);

		dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0,720,451, SRCCOPY);//����ͼƬ�ߴ������ϴ��ڳߴ�
       */
		

		//////ʹ��һ��յ�λͼ��Ϊ����/////////////
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������
		//1.�����뱾���ڼ��ݵĵڶ���������(�ߴ�ֻ��1.1����)
		CDC memDC;
		memDC.CreateCompatibleDC(&dc);

	    CRect rect;
		GetClientRect(rect);

		//2.��������λͼ����λͼѡ������DC�У���Ϊ��������
		CBitmap bmp;
		bmp.CreateCompatibleBitmap(&memDC,rect.Width(),rect.Height());
		memDC.SelectObject(&bmp);
		//Ĭ���Ǻ�ɫ�����һ������ɫ
		memDC.FillSolidRect(CRect(0, 0, rect.Width(), rect.Height()), RGB(240, 240, 240));
		//�ڻ����������������ϻ�����
		memDC.SetBkMode(TRANSPARENT);
		memDC.Rectangle(100, 100, 200, 200);
		memDC.Ellipse(CRect(100, 100, 200, 200));
	
		//3.�ѻ��������Ŀ�������һ���������ϣ�������ʾ��
		

		//dc.BitBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, SRCCOPY);

		dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, 300, 300, SRCCOPY);//����ͼƬ�ߴ������ϴ��ڳߴ�


		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMy062Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

