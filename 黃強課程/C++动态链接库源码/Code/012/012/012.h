// 012.h : 012 DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMy012App
// �йش���ʵ�ֵ���Ϣ������� 012.cpp
//

class CMy012App : public CWinApp
{
public:
	CMy012App();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
