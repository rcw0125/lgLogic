// TapSideMag.h : TapSideMag DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// ������


// CTapSideMagApp
// �йش���ʵ�ֵ���Ϣ������� TapSideMag.cpp
//

class CTapSideMagApp : public CWinApp
{
public:
	CTapSideMagApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};


DECLARE_L3COMPONENT(TapSideMag,{2f31a700-eb58-4e09-a1c9-89f3fbf772e9})

