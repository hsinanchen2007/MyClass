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
	PointF  GetPos();//��ȡԲ��
	float  GetR();//��ȡ�뾶
private:
	float      m_R;//�뾶
	PointF   m_pos;//Բ��
	float      m_speedX;//x������ٶ�
	float      m_speedY;//y������ٶ�
	Color     m_color;//������ɫ
	RectF     m_bound;//�����˶��ı߽�


};

