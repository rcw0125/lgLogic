// CCMMag.h : CCMMag DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// ������


// CCCMMagApp
// �йش���ʵ�ֵ���Ϣ������� CCMMag.cpp
//

class CCCMMagApp : public CWinApp
{
public:
	CCCMMagApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};


DECLARE_L3COMPONENT(CCMMag,{bfdbffd7-012b-4a57-bbf3-bf37ca68b63d})

