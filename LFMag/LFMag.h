// LFMag.h : LFMag DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// ������


// CLFMagApp
// �йش���ʵ�ֵ���Ϣ������� LFMag.cpp
//

class CLFMagApp : public CWinApp
{
public:
	CLFMagApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};


DECLARE_L3COMPONENT(LFMag,{5b6ab9d3-c39b-4b0b-9156-fd4c224ba80a})

