// LanceMag.h : LanceMag DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// ������


// CLanceMagApp
// �йش���ʵ�ֵ���Ϣ������� LanceMag.cpp
//

class CLanceMagApp : public CWinApp
{
public:
	CLanceMagApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};


DECLARE_L3COMPONENT(LanceMag,{fe6090e8-bbe4-446a-ad00-9c20911ff07f})

