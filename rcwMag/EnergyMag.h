// EnergyMag.h : EnergyMag DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// ������


// CEnergyMagApp
// �йش���ʵ�ֵ���Ϣ������� EnergyMag.cpp
//

class CEnergyMagApp : public CWinApp
{
public:
	CEnergyMagApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};


DECLARE_L3COMPONENT(EnergyMag,{66c00b1c-46c3-4082-8252-254afa05540e})

