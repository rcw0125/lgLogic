// IronLadleMag.h : IronLadleMag DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// ������


// CIronLadleMagApp
// �йش���ʵ�ֵ���Ϣ������� IronLadleMag.cpp
//

class CIronLadleMagApp : public CWinApp
{
public:
	CIronLadleMagApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};


DECLARE_L3COMPONENT(IronLadleMag,{075c04d7-bae0-4453-b611-95aa4aadaee0})

