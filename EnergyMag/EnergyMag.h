// EnergyMag.h : EnergyMag DLL 的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// 主符号


// CEnergyMagApp
// 有关此类实现的信息，请参阅 EnergyMag.cpp
//

class CEnergyMagApp : public CWinApp
{
public:
	CEnergyMagApp();

// 重写
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};


DECLARE_L3COMPONENT(EnergyMag,{66c00b1c-46c3-4082-8252-254afa05540e})

