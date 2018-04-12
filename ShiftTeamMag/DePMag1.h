// DePMag1.h

//#pragma once
//
//using namespace System;
//
//namespace DePMag1 {
//
//	public ref class Class1
//	{
//		// TODO: 在此处添加此类的方法。
//	};
//}


// DePMag1.h

//#pragma once
//
//using namespace System;
//
//namespace DePMag1 {
//
//	public ref class Class1
//	{
//		// TODO: 在此处添加此类的方法。
//	};
//}


// DeSMag.h : DeSMag DLL 的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// 主符号


// CDeSMagApp
// 有关此类实现的信息，请参阅 DeSMag.cpp
//

class CDePMag1App : public CWinApp
{
public:
	CDePMag1App();

// 重写
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};


DECLARE_L3COMPONENT(DePMag1,{03e7c83c-6dd5-423d-aafc-952201b6db04})


