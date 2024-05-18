#include "stdafx.h"
#include "CPao.h"

 
CPao::CPao(PointF p , float R , float sx , float sy, Color c )
{
	m_pos = p;
	m_R = R;
	m_speedX = sx;
	m_speedY = sy;
	m_color = c;
}


CPao::~CPao()
{
}

PointF  CPao::GetPos()
{
	return m_pos;
}


float  CPao::GetR()
{
	return m_R;
}



void  CPao::Update(int intval ,  vector<CPao*> vecPao)
{
	//�ƶ�����
	m_pos.X += intval * m_speedX;
	m_pos.Y += intval * m_speedY;

	//�ж��Ƿ���������������ײ
	for ( auto  &o : vecPao)
	{
		if (o == this) continue;//�Լ��ų�����
  
		float  X = abs( this->m_pos.X - o->m_pos.X);
		float  Y = abs(this->m_pos.Y - o->m_pos.Y);

		//������������ĵľ���
		float S = sqrtf(X*X + Y * Y);

		//�ж��Ƿ��Ѿ���ײ
		if (S <= this->m_R+ o->m_R )
		{
			float tempX = this->m_speedX;
			float tempY = this->m_speedY;

			this->m_speedX = o->m_speedX;
			this->m_speedY = o->m_speedY;

			o->m_speedX = tempX;
			o->m_speedY = tempY;

			//���ص����򵯳����ӳ����ϣ����䲻���ص�
			//x'  =  xa +   ( (Ra+Rb) - S )* (xa-xb)/S  ;
			//y'  =  ya +   ( (Ra+Rb) - S )* (ya-yb)/S  ;
			//�����Լ�
			this->m_pos.X +=  ((this->m_R + o->m_R) - S) *(this->m_pos.X - o->m_pos.X) / S;
			this->m_pos.Y +=  ((this->m_R + o->m_R) - S) *(this->m_pos.Y- o->m_pos.Y) / S;

			//�����Է�
			o->m_pos.X += ((o->m_R + this->m_R) - S) *(o->m_pos.X - this->m_pos.X) / S;
			o->m_pos.Y += ((o->m_R + this->m_R) - S) *(o->m_pos.Y - this->m_pos.Y) / S;

	 
		}

	}




	//�����߽���Ҫ����
	RectF   rPao(m_pos.X - m_R, m_pos.Y - m_R, 2 * m_R, 2 * m_R);


	if ( rPao.GetLeft() < m_bound.GetLeft())
	{//���������߽磬�ٶ�Ӧ��Ϊ�����������������˶�
		m_speedX = abs(m_speedX);
	}
	if (rPao.GetRight() > m_bound.GetRight() )
	{
		m_speedX =  - abs(m_speedX);
	}
	if (rPao.GetTop() < m_bound.GetTop())
	{
		m_speedY = abs(m_speedY);
	}
	if (rPao.GetBottom() > m_bound.GetBottom())
	{
		m_speedY = -abs(m_speedY);
	}

}

void  CPao::SetBound(RectF r)
{
	m_bound = r;
}


void  CPao::Draw(Graphics &graphics)
{

	//����Բ
	Rect  rPao(  m_pos.X -m_R  , m_pos.Y- m_R, 2 * m_R, 2 * m_R);
	graphics.DrawEllipse(&Pen( m_color, 0.5), rPao);

	//ʹ�����Խ��仭ˢ�������
	LinearGradientBrush  lgb(rPao, m_color, Color(255, 255, 255), 45);
	graphics.FillEllipse(&lgb, rPao);

	//������С����
	graphics.FillEllipse(&SolidBrush(Color::White), rPao.GetLeft() + m_R / 2,
		rPao.GetTop() + m_R / 3, m_R / 3, m_R / 3);

	graphics.FillEllipse(&SolidBrush(Color::White), rPao.GetLeft() + m_R / 3,
		rPao.GetTop() + 2 * m_R / 3, m_R / 4, m_R / 4);

}