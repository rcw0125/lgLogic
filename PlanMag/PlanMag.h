// PlanMag.h : PlanMag DLL 的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// 主符号


// CPlanMagApp
// 有关此类实现的信息，请参阅 PlanMag.cpp
//

class CPlanMagApp : public CWinApp
{
public:
	CPlanMagApp();

// 重写
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};


DECLARE_L3COMPONENT(PlanMag,{6d1cbff8-c3b2-420a-bbf0-a4461d1a72d7})

