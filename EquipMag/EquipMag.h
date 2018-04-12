// EquipMag.h : EquipMag DLL 的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// 主符号


// CEquipMagApp
// 有关此类实现的信息，请参阅 EquipMag.cpp
//

class CEquipMagApp : public CWinApp
{
public:
	CEquipMagApp();

// 重写
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};


DECLARE_L3COMPONENT(EquipMag,{0454afb6-cde1-4f49-930e-cfc67280e000})

