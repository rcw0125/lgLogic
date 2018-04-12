//// AODMag.h
//
//#pragma once
//
//using namespace System;
//
//namespace AODMag {
//
//	public ref class Class1
//	{
//		// TODO: 在此处添加此类的方法。
//	};
//}
//

// AODMag.h : AODMag DLL 的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// 主符号


// CAODMagApp
// 有关此类实现的信息，请参阅 AODMag.cpp
//

class CAODMagApp : public CWinApp
{
public:
	CAODMagApp();

// 重写
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};


DECLARE_L3COMPONENT(AODMag,{5b6ab9d3-c39b-4b0b-9156-fd4c224ba801})