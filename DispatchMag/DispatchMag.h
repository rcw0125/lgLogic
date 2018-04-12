// DispatchMag.h : DispatchMag DLL 的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// 主符号


// CDispatchMagApp
// 有关此类实现的信息，请参阅 DispatchMag.cpp
//

class CDispatchMagApp : public CWinApp
{
public:
	CDispatchMagApp();

// 重写
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};


DECLARE_L3COMPONENT(DispatchMag,{3ea8b49c-7b2c-400d-9d54-8ae1ac694b28})

