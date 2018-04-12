// BOFMag.h : BOFMag DLL 的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// 主符号


// CBOFMagApp
// 有关此类实现的信息，请参阅 BOFMag.cpp
//

class CBOFMagApp : public CWinApp
{
public:
	CBOFMagApp();

// 重写
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};


DECLARE_L3COMPONENT(BOFMag,{bdc2dc5c-c97e-4a2c-98a4-2a9017beec1e})

