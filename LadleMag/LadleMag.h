// LadleMag.h : LadleMag DLL 的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// 主符号


// CLadleMagApp
// 有关此类实现的信息，请参阅 LadleMag.cpp
//

class CLadleMagApp : public CWinApp
{
public:
	CLadleMagApp();

// 重写
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};


DECLARE_L3COMPONENT(LadleMag,{248bcad8-8b48-4d70-bdfb-57a5dc76995c})

