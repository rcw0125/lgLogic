// LanceMag.h : LanceMag DLL 的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// 主符号


// CLanceMagApp
// 有关此类实现的信息，请参阅 LanceMag.cpp
//

class CLanceMagApp : public CWinApp
{
public:
	CLanceMagApp();

// 重写
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};


DECLARE_L3COMPONENT(LanceMag,{fe6090e8-bbe4-446a-ad00-9c20911ff07f})

