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
//		// TODO: �ڴ˴���Ӵ���ķ�����
//	};
//}
//

// AODMag.h : AODMag DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// ������


// CAODMagApp
// �йش���ʵ�ֵ���Ϣ������� AODMag.cpp
//

class CAODMagApp : public CWinApp
{
public:
	CAODMagApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};


DECLARE_L3COMPONENT(AODMag,{5b6ab9d3-c39b-4b0b-9156-fd4c224ba801})