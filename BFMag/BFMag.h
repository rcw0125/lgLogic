// BFMag.h : BFMag DLL 的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// 主符号


// CBFMagApp
// 有关此类实现的信息，请参阅 BFMag.cpp
//

class CBFMagApp : public CWinApp
{
public:
	CBFMagApp();

// 重写
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};


DECLARE_L3COMPONENT(BFMag,{564d5d8a-4051-43cd-ad8c-9e2051a647fe})

