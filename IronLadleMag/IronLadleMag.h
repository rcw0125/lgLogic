// IronLadleMag.h : IronLadleMag DLL 的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// 主符号


// CIronLadleMagApp
// 有关此类实现的信息，请参阅 IronLadleMag.cpp
//

class CIronLadleMagApp : public CWinApp
{
public:
	CIronLadleMagApp();

// 重写
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};


DECLARE_L3COMPONENT(IronLadleMag,{075c04d7-bae0-4453-b611-95aa4aadaee0})

