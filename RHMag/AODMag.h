// AODMag.h : AODMag DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// ������


// CAODMagApp
// �йش���ʵ�ֵ���Ϣ������� AODMag.cpp
//

class CAODMagApp : public CWinApp
{
public:
	CAODMagApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};


DECLARE_L3COMPONENT(AODMag,{39e41f19-4e01-413e-856b-817351a3c341})

