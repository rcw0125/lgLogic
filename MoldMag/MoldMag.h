// MoldMag.h : MoldMag DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// ������


// CMoldMagApp
// �йش���ʵ�ֵ���Ϣ������� MoldMag.cpp
//

class CMoldMagApp : public CWinApp
{
public:
	CMoldMagApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};


DECLARE_L3COMPONENT(MoldMag,{91e50e2e-9537-46d7-bbf2-454184766307})


BEGIN_L3EVENT(MoldChangeFlowID)
END_L3EVENT()
