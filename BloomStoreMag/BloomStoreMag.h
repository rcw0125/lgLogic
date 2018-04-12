// BloomStoreMag.h : BloomStoreMag DLL 的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// 主符号


// CBloomStoreMagApp
// 有关此类实现的信息，请参阅 BloomStoreMag.cpp
//

class CBloomStoreMagApp : public CWinApp
{
public:
	CBloomStoreMagApp();

// 重写
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};


DECLARE_L3COMPONENT(BloomStoreMag,{f6c99bed-a5e8-4f75-ae0f-5cb68bbb66d6})

