// TundishMag.h : TundishMag DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// ������


// CTundishMagApp
// �йش���ʵ�ֵ���Ϣ������� TundishMag.cpp
//

class CTundishMagApp : public CWinApp
{
public:
	CTundishMagApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};


DECLARE_L3COMPONENT(TundishMag,{8ece5748-eb05-4d29-88b1-572089dbda20})

