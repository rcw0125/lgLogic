// BaseDataMag.h : BaseDataMag DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// ������


// CBaseDataMagApp
// �йش���ʵ�ֵ���Ϣ������� BaseDataMag.cpp
//

class CBaseDataMagApp : public CWinApp
{
public:
	CBaseDataMagApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};


DECLARE_L3COMPONENT(BaseDataMag,{d667d2d0-f031-497c-8cf2-8f580da53dcb})
