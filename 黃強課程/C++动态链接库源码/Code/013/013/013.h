// 013.h : 013 DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMy013App
// �йش���ʵ�ֵ���Ϣ������� 013.cpp
//

class CMy013App : public CWinApp
{
public:
	CMy013App();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
