// RHLMag.h
//
//#pragma once
//
//using namespace System;
//
//namespace RHLMag {
//
//	public ref class Class1
//	{
//		// TODO: �ڴ˴���Ӵ���ķ�����
//	};
//}


// LFMag.h : LFMag DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// ������


// CRHLMagApp
// �йش���ʵ�ֵ���Ϣ������� LFMag.cpp
//

class CRHLMagApp : public CWinApp
{
public:
	CRHLMagApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};


DECLARE_L3COMPONENT(RHLMag,{5b6ab9d3-c39b-4b0b-9156-fd4c224ba801})

