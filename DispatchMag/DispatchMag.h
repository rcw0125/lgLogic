// DispatchMag.h : DispatchMag DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// ������


// CDispatchMagApp
// �йش���ʵ�ֵ���Ϣ������� DispatchMag.cpp
//

class CDispatchMagApp : public CWinApp
{
public:
	CDispatchMagApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};


DECLARE_L3COMPONENT(DispatchMag,{3ea8b49c-7b2c-400d-9d54-8ae1ac694b28})

