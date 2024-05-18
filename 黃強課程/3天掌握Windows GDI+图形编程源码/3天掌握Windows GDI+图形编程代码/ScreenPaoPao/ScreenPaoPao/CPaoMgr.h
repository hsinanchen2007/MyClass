#pragma once

#include "CPao.h"

class CPaoMgr
{
public:
	CPaoMgr();
	virtual ~CPaoMgr();

public:
	//创建N个泡泡
	void CreatePaos(int N, HWND hwnd);

	//绘制所有泡泡
	void  DrawPaos(Graphics  &graphics);

	//更新所有泡泡的位置
	void UpdatePaos(int intval);

	//销毁所有泡泡
	void DesroyPaos();

protected: 
	//截取桌面位图
	HBITMAP  GetScreenBmp();

private:
	//泡泡存放的数组
	vector<CPao*> m_vecPao;

	//内存位图缓冲区
	Bitmap * m_pBmp =nullptr;

	//保存桌面位图对象
	Bitmap * m_pDesktop =nullptr;

	//窗口绘制区域
	RECT     m_rClient;

};

