// VacTubeMag.h : VacTubeMag DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// ������


// CVacTubeMagApp
// �йش���ʵ�ֵ���Ϣ������� VacTubeMag.cpp
//

class CVacTubeMagApp : public CWinApp
{
public:
	CVacTubeMagApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};


DECLARE_L3COMPONENT(VacTubeMag,{18079098-ace4-4f8a-9a4a-5ba0a94db4d8})

