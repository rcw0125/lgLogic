// BOFMag.h : BOFMag DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// ������


// CBOFMagApp
// �йش���ʵ�ֵ���Ϣ������� BOFMag.cpp
//

class CBOFMagApp : public CWinApp
{
public:
	CBOFMagApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};


DECLARE_L3COMPONENT(BOFMag,{bdc2dc5c-c97e-4a2c-98a4-2a9017beec1e})

