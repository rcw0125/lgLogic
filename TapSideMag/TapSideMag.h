// TapSideMag.h : TapSideMag DLL 的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// 主符号


// CTapSideMagApp
// 有关此类实现的信息，请参阅 TapSideMag.cpp
//

class CTapSideMagApp : public CWinApp
{
public:
	CTapSideMagApp();

// 重写
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};


DECLARE_L3COMPONENT(TapSideMag,{2f31a700-eb58-4e09-a1c9-89f3fbf772e9})

