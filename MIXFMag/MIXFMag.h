// MIXFMag.h : MIXFMag DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// ������


// CMIXFMagApp
// �йش���ʵ�ֵ���Ϣ������� MIXFMag.cpp
//

class CMIXFMagApp : public CWinApp
{
public:
	CMIXFMagApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};


DECLARE_L3COMPONENT(MIXFMag,{b94c73a0-064a-4f4e-b775-7e1bd8e91dc1})

