// LFMag.h : LFMag DLL 的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// 主符号


// CLFMagApp
// 有关此类实现的信息，请参阅 LFMag.cpp
//

class CLFMagApp : public CWinApp
{
public:
	CLFMagApp();

// 重写
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};


DECLARE_L3COMPONENT(LFMag,{5b6ab9d3-c39b-4b0b-9156-fd4c224ba80a})

