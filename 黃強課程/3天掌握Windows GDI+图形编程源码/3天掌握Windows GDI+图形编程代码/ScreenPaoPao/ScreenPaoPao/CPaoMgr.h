#pragma once

#include "CPao.h"

class CPaoMgr
{
public:
	CPaoMgr();
	virtual ~CPaoMgr();

public:
	//����N������
	void CreatePaos(int N, HWND hwnd);

	//������������
	void  DrawPaos(Graphics  &graphics);

	//�����������ݵ�λ��
	void UpdatePaos(int intval);

	//������������
	void DesroyPaos();

protected: 
	//��ȡ����λͼ
	HBITMAP  GetScreenBmp();

private:
	//���ݴ�ŵ�����
	vector<CPao*> m_vecPao;

	//�ڴ�λͼ������
	Bitmap * m_pBmp =nullptr;

	//��������λͼ����
	Bitmap * m_pDesktop =nullptr;

	//���ڻ�������
	RECT     m_rClient;

};

