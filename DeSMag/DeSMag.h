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

class CDeSMagApp : public CWinApp
{
public:
	CDeSMagApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};


DECLARE_L3COMPONENT(DeSMag,{03e7c83c-6dd5-423d-aafc-952201b6db05})

