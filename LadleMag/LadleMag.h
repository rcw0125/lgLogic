// LadleMag.h : LadleMag DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// ������


// CLadleMagApp
// �йش���ʵ�ֵ���Ϣ������� LadleMag.cpp
//

class CLadleMagApp : public CWinApp
{
public:
	CLadleMagApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};


DECLARE_L3COMPONENT(LadleMag,{248bcad8-8b48-4d70-bdfb-57a5dc76995c})

