
// The Book Manage System.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CTheBookManageSystemApp: 
// �йش����ʵ�֣������ The Book Manage System.cpp
//

class CTheBookManageSystemApp : public CWinApp
{
public:
	CTheBookManageSystemApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CTheBookManageSystemApp theApp;