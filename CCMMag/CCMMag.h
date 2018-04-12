// CCMMag.h : CCMMag DLL 的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// 主符号


// CCCMMagApp
// 有关此类实现的信息，请参阅 CCMMag.cpp
//

class CCCMMagApp : public CWinApp
{
public:
	CCCMMagApp();

// 重写
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};


DECLARE_L3COMPONENT(CCMMag,{bfdbffd7-012b-4a57-bbf3-bf37ca68b63d})

