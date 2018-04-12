// ScrapStoreMag.h : ScrapStoreMag DLL 的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// 主符号


// CScrapStoreMagApp
// 有关此类实现的信息，请参阅 ScrapStoreMag.cpp
//

class CScrapStoreMagApp : public CWinApp
{
public:
	CScrapStoreMagApp();

// 重写
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};


DECLARE_L3COMPONENT(ScrapStoreMag,{cede0efd-90e9-42dd-9f4a-69f776c506ab})

