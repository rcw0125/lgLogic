// MIXFMag.h : MIXFMag DLL 的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// 主符号


// CMIXFMagApp
// 有关此类实现的信息，请参阅 MIXFMag.cpp
//

class CMIXFMagApp : public CWinApp
{
public:
	CMIXFMagApp();

// 重写
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};


DECLARE_L3COMPONENT(MIXFMag,{b94c73a0-064a-4f4e-b775-7e1bd8e91dc1})

