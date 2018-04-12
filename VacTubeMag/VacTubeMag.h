// VacTubeMag.h : VacTubeMag DLL 的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// 主符号


// CVacTubeMagApp
// 有关此类实现的信息，请参阅 VacTubeMag.cpp
//

class CVacTubeMagApp : public CWinApp
{
public:
	CVacTubeMagApp();

// 重写
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};


DECLARE_L3COMPONENT(VacTubeMag,{18079098-ace4-4f8a-9a4a-5ba0a94db4d8})

