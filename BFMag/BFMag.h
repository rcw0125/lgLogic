// BFMag.h : BFMag DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// ������


// CBFMagApp
// �йش���ʵ�ֵ���Ϣ������� BFMag.cpp
//

class CBFMagApp : public CWinApp
{
public:
	CBFMagApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};


DECLARE_L3COMPONENT(BFMag,{564d5d8a-4051-43cd-ad8c-9e2051a647fe})

