// Test.h : Test DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// ������


// CShiftTeamMagApp
// �йش���ʵ�ֵ���Ϣ������� Test.cpp
//

class CTestApp : public CWinApp
{
public:
	CTestApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};


DECLARE_L3COMPONENT(DePMag,{c5dcf682-1a11-400f-b133-d72c9f62ded1})

