// PlanMag.h : PlanMag DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// ������


// CPlanMagApp
// �йش���ʵ�ֵ���Ϣ������� PlanMag.cpp
//

class CPlanMagApp : public CWinApp
{
public:
	CPlanMagApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};


DECLARE_L3COMPONENT(PlanMag,{6d1cbff8-c3b2-420a-bbf0-a4461d1a72d7})

