// DePMag1.h

//#pragma once
//
//using namespace System;
//
//namespace DePMag1 {
//
//	public ref class Class1
//	{
//		// TODO: �ڴ˴���Ӵ���ķ�����
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
//		// TODO: �ڴ˴���Ӵ���ķ�����
//	};
//}


// DeSMag.h : DeSMag DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// ������


// CDeSMagApp
// �йش���ʵ�ֵ���Ϣ������� DeSMag.cpp
//

class CDePMag1App : public CWinApp
{
public:
	CDePMag1App();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};


DECLARE_L3COMPONENT(DePMag1,{03e7c83c-6dd5-423d-aafc-952201b6db04})


