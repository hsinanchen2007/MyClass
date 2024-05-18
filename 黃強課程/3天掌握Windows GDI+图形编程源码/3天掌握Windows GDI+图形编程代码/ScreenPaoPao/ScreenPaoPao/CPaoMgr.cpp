#include "stdafx.h"
#include "CPaoMgr.h"


CPaoMgr::CPaoMgr()
{

}


CPaoMgr::~CPaoMgr()
{ 
}


//����N������
void CPaoMgr::CreatePaos(int N, HWND hwnd)
{
	//��ȡ��ʾ���ڵĴ�С 
	GetClientRect(hwnd,&m_rClient);

	//�����ڴ�λͼ
	m_pBmp = new Bitmap(m_rClient.right, m_rClient.bottom);

	//���������ͼ
	m_pDesktop = new Bitmap(GetScreenBmp(), NULL);

	//���ʱ������
	srand(time(NULL));


	while(m_vecPao.size()<N)
	{
		int  x = 100 + rand() % (m_rClient.right - 200);
		int  y = 100 + rand() % (m_rClient.bottom - 200);
	  
		//�뾶�������С50�����200
		float  R = 50 + rand() % 150;

		//��ʼ�ٶ����
		float sx = (rand() % 15)*0.1 + 0.1;
		float sy = (rand() % 15)*0.1 + 0.1;

		//��ɫ���
		Color c(rand() % 256, rand() % 256, rand() % 256);


		CPao * pao = new CPao(PointF( x,y ),R,sx, sy ,c);

		/*
		bool  flag = true; 
		//����Ƿ����Ѿ������������ص� 
		for (auto &o : m_vecPao)
		{
		 
			float  X = abs(pao->GetPos().X - o->GetPos().X);
			float  Y = abs(pao->GetPos().Y - o->GetPos().Y);

			//������������ĵľ���
			float S = sqrtf(X*X + Y * Y);

			//�ж��Ƿ��Ѿ���ײ
			if (S <= pao->GetR() + o->GetR() )
			{
				 //��Բ�Ķ���
				flag = false;
			}

		}


		if (flag)
		{//���Լ�������
			pao->SetBound(RectF(m_rClient.left, m_rClient.top, m_rClient.right, m_rClient.bottom));
			m_vecPao.push_back(pao);
		}
		*/


		//���������ص����
		pao->SetBound(RectF(m_rClient.left, m_rClient.top, m_rClient.right, m_rClient.bottom));
		m_vecPao.push_back(pao);
	}
}

//������������
void  CPaoMgr::DrawPaos(Graphics  &graphics)
{

	//����һ���ڴ�Graphics����
	Graphics *memG = Graphics::FromImage(m_pBmp);

	//�Լ�ˢ�±���
	//memG->FillRectangle(&SolidBrush(Color::White), Rect(0, 0, m_rClient.right, m_rClient.bottom));

	//�������ͼ��Ϊ����
	memG->DrawImage(m_pDesktop, 0, 0, m_rClient.right, m_rClient.bottom);

	//ȥ���
	memG->SetSmoothingMode(SmoothingModeHighQuality);


	//���Ƶ��ڴ�λͼ��
	for (  auto &p: m_vecPao  )
	{
		p->Draw(*memG);
	}

	
	//һ���Ի��Ƶ���Ļ��
	graphics.DrawImage(m_pBmp, 0, 0, m_rClient.right, m_rClient.bottom);
}


//������������
void  CPaoMgr::UpdatePaos(int intval)
{
	for (  auto &p: m_vecPao  )
	{
		p->Update(intval , m_vecPao);
	}
}


//��ȡ����λͼ
HBITMAP CPaoMgr::GetScreenBmp()
{
	//����һ�����洰��DC
	HDC  hDesktop = GetWindowDC(NULL);

	//�����ڴ����DC
	HDC  hMemDC= CreateCompatibleDC(hDesktop);

	//�����ڴ����λͼ
	HBITMAP  hBmp=CreateCompatibleBitmap(hDesktop, m_rClient.right, m_rClient.bottom);
	 
	//���ڴ�λͼѡ�����DC�Ի�ͼ
	SelectObject(hMemDC,hBmp);

	//������DC�����ݿ������ڴ����DC, �൱�ڰ������ͼ�ŵ���hBmp��
	BitBlt(hMemDC, 0, 0, m_rClient.right, m_rClient.bottom, hDesktop, 0, 0, SRCCOPY);

	return hBmp;
}


//������������
void CPaoMgr::DesroyPaos()
{
	for (auto &p : m_vecPao)
	{
		//�ͷŵ����ݶ���
		delete p;
	}

	if (m_pBmp)
	{
		delete  m_pBmp;//ɾ���ڴ�λͼ
		m_pBmp = nullptr;
	}
	
	m_vecPao.clear();//�������
}