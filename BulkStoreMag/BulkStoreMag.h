// BulkStoreMag.h : BulkStoreMag DLL 的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// 主符号


// CBulkStoreMagApp
// 有关此类实现的信息，请参阅 BulkStoreMag.cpp
//

class CBulkStoreMagApp : public CWinApp
{
public:
	CBulkStoreMagApp();

// 重写
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};


DECLARE_L3COMPONENT(BulkStoreMag,{b15f1e9c-8fb5-4a09-b15d-2021ce2966cc})

