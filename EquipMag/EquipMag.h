// EquipMag.h : EquipMag DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// ������


// CEquipMagApp
// �йش���ʵ�ֵ���Ϣ������� EquipMag.cpp
//

class CEquipMagApp : public CWinApp
{
public:
	CEquipMagApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};


DECLARE_L3COMPONENT(EquipMag,{0454afb6-cde1-4f49-930e-cfc67280e000})

