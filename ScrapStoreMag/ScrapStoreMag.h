// ScrapStoreMag.h : ScrapStoreMag DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// ������


// CScrapStoreMagApp
// �йش���ʵ�ֵ���Ϣ������� ScrapStoreMag.cpp
//

class CScrapStoreMagApp : public CWinApp
{
public:
	CScrapStoreMagApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};


DECLARE_L3COMPONENT(ScrapStoreMag,{cede0efd-90e9-42dd-9f4a-69f776c506ab})

