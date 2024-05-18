#include "stdafx.h"
#include "CPaoMgr.h"


CPaoMgr::CPaoMgr()
{

}


CPaoMgr::~CPaoMgr()
{ 
}


//创建N个泡泡
void CPaoMgr::CreatePaos(int N, HWND hwnd)
{
	//获取显示窗口的大小 
	GetClientRect(hwnd,&m_rClient);

	//创建内存位图
	m_pBmp = new Bitmap(m_rClient.right, m_rClient.bottom);

	//创建桌面截图
	m_pDesktop = new Bitmap(GetScreenBmp(), NULL);

	//随机时间种子
	srand(time(NULL));


	while(m_vecPao.size()<N)
	{
		int  x = 100 + rand() % (m_rClient.right - 200);
		int  y = 100 + rand() % (m_rClient.bottom - 200);
	  
		//半径随机，最小50，最大200
		float  R = 50 + rand() % 150;

		//初始速度随机
		float sx = (rand() % 15)*0.1 + 0.1;
		float sy = (rand() % 15)*0.1 + 0.1;

		//颜色随机
		Color c(rand() % 256, rand() % 256, rand() % 256);


		CPao * pao = new CPao(PointF( x,y ),R,sx, sy ,c);

		/*
		bool  flag = true; 
		//检测是否与已经产生的泡泡重叠 
		for (auto &o : m_vecPao)
		{
		 
			float  X = abs(pao->GetPos().X - o->GetPos().X);
			float  Y = abs(pao->GetPos().Y - o->GetPos().Y);

			//求出两个球球心的距离
			float S = sqrtf(X*X + Y * Y);

			//判断是否已经碰撞
			if (S <= pao->GetR() + o->GetR() )
			{
				 //此圆心丢弃
				flag = false;
			}

		}


		if (flag)
		{//可以加入泡泡
			pao->SetBound(RectF(m_rClient.left, m_rClient.top, m_rClient.right, m_rClient.bottom));
			m_vecPao.push_back(pao);
		}
		*/


		//不作泡泡重叠检测
		pao->SetBound(RectF(m_rClient.left, m_rClient.top, m_rClient.right, m_rClient.bottom));
		m_vecPao.push_back(pao);
	}
}

//绘制所有泡泡
void  CPaoMgr::DrawPaos(Graphics  &graphics)
{

	//产生一个内存Graphics对象
	Graphics *memG = Graphics::FromImage(m_pBmp);

	//自己刷新背景
	//memG->FillRectangle(&SolidBrush(Color::White), Rect(0, 0, m_rClient.right, m_rClient.bottom));

	//把桌面截图作为背景
	memG->DrawImage(m_pDesktop, 0, 0, m_rClient.right, m_rClient.bottom);

	//去锯齿
	memG->SetSmoothingMode(SmoothingModeHighQuality);


	//绘制到内存位图中
	for (  auto &p: m_vecPao  )
	{
		p->Draw(*memG);
	}

	
	//一次性绘制到屏幕上
	graphics.DrawImage(m_pBmp, 0, 0, m_rClient.right, m_rClient.bottom);
}


//绘制所有泡泡
void  CPaoMgr::UpdatePaos(int intval)
{
	for (  auto &p: m_vecPao  )
	{
		p->Update(intval , m_vecPao);
	}
}


//截取桌面位图
HBITMAP CPaoMgr::GetScreenBmp()
{
	//创建一个桌面窗口DC
	HDC  hDesktop = GetWindowDC(NULL);

	//创建内存兼容DC
	HDC  hMemDC= CreateCompatibleDC(hDesktop);

	//创建内存兼容位图
	HBITMAP  hBmp=CreateCompatibleBitmap(hDesktop, m_rClient.right, m_rClient.bottom);
	 
	//将内存位图选入兼容DC以绘图
	SelectObject(hMemDC,hBmp);

	//将桌面DC的内容拷贝到内存兼容DC, 相当于把桌面截图放到了hBmp中
	BitBlt(hMemDC, 0, 0, m_rClient.right, m_rClient.bottom, hDesktop, 0, 0, SRCCOPY);

	return hBmp;
}


//销毁所有泡泡
void CPaoMgr::DesroyPaos()
{
	for (auto &p : m_vecPao)
	{
		//释放掉泡泡对象
		delete p;
	}

	if (m_pBmp)
	{
		delete  m_pBmp;//删除内存位图
		m_pBmp = nullptr;
	}
	
	m_vecPao.clear();//清空数据
}