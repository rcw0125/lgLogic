// BloomStoreMag.h : BloomStoreMag DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// ������


// CBloomStoreMagApp
// �йش���ʵ�ֵ���Ϣ������� BloomStoreMag.cpp
//

class CBloomStoreMagApp : public CWinApp
{
public:
	CBloomStoreMagApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};


DECLARE_L3COMPONENT(BloomStoreMag,{f6c99bed-a5e8-4f75-ae0f-5cb68bbb66d6})

