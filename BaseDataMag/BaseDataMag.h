// BaseDataMag.h : BaseDataMag DLL 的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// 主符号


// CBaseDataMagApp
// 有关此类实现的信息，请参阅 BaseDataMag.cpp
//

class CBaseDataMagApp : public CWinApp
{
public:
	CBaseDataMagApp();

// 重写
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};


DECLARE_L3COMPONENT(BaseDataMag,{d667d2d0-f031-497c-8cf2-8f580da53dcb})
