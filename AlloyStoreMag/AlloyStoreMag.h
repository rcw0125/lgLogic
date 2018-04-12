// AlloyStoreMag.h : AlloyStoreMag DLL 的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// 主符号


// CAlloyStoreMagApp
// 有关此类实现的信息，请参阅 AlloyStoreMag.cpp
//

class CAlloyStoreMagApp : public CWinApp
{
public:
	CAlloyStoreMagApp();

// 重写
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};


DECLARE_L3COMPONENT(AlloyStoreMag,{df5e5d16-185e-4f96-934c-e59a44e44912})

