// L2CommLogicObj.h : L2CommLogicObj DLL 的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// 主符号


// CL2CommLogicObjApp
// 有关此类实现的信息，请参阅 L2CommLogicObj.cpp
//


class CL2CommLogicObjApp : public CWinApp
{
public:
	CL2CommLogicObjApp();

// 重写
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

DECLARE_L3COMPONENT(L2CommLogicObj,{869615A0-FFAD-445f-B20A-E1E5CD7B0899})
