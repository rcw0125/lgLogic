// L2CommLogicObj.h : L2CommLogicObj DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// ������


// CL2CommLogicObjApp
// �йش���ʵ�ֵ���Ϣ������� L2CommLogicObj.cpp
//


class CL2CommLogicObjApp : public CWinApp
{
public:
	CL2CommLogicObjApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

DECLARE_L3COMPONENT(L2CommLogicObj,{869615A0-FFAD-445f-B20A-E1E5CD7B0899})
