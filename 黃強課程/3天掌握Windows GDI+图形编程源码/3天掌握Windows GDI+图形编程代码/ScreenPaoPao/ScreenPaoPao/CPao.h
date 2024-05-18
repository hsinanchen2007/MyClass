#pragma once
class CPao
{
public:
	CPao( PointF p= PointF(300,300), float R=100, float sx= 0.5,float sy= 0.5, Color c=Color::Red  );
	virtual ~CPao();

public:
	void  Draw( Graphics &graphics );
	void  Update(int intval, vector<CPao*> vecPao);

	void  SetBound(RectF r);
	PointF  GetPos();//获取圆心
	float  GetR();//获取半径
private:
	float      m_R;//半径
	PointF   m_pos;//圆心
	float      m_speedX;//x方向的速度
	float      m_speedY;//y方向的速度
	Color     m_color;//泡泡颜色
	RectF     m_bound;//泡泡运动的边界


};

