// TundishMag.h : TundishMag DLL 的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// 主符号


// CTundishMagApp
// 有关此类实现的信息，请参阅 TundishMag.cpp
//

class CTundishMagApp : public CWinApp
{
public:
	CTundishMagApp();

// 重写
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};


DECLARE_L3COMPONENT(TundishMag,{8ece5748-eb05-4d29-88b1-572089dbda20})

