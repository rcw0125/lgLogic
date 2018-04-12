// QualityMag.h : QualityMag DLL 的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// 主符号


// CQualityMagApp
// 有关此类实现的信息，请参阅 QualityMag.cpp
//

class CQualityMagApp : public CWinApp
{
public:
	CQualityMagApp();

// 重写
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};


DECLARE_L3COMPONENT(QualityMag,{4d8174a4-bdb1-40d3-a4a5-ced4cb07707d})

