// AlloyStoreMag.h : AlloyStoreMag DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// ������


// CAlloyStoreMagApp
// �йش���ʵ�ֵ���Ϣ������� AlloyStoreMag.cpp
//

class CAlloyStoreMagApp : public CWinApp
{
public:
	CAlloyStoreMagApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};


DECLARE_L3COMPONENT(AlloyStoreMag,{df5e5d16-185e-4f96-934c-e59a44e44912})

