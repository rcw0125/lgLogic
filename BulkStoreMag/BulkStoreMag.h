// BulkStoreMag.h : BulkStoreMag DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// ������


// CBulkStoreMagApp
// �йش���ʵ�ֵ���Ϣ������� BulkStoreMag.cpp
//

class CBulkStoreMagApp : public CWinApp
{
public:
	CBulkStoreMagApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};


DECLARE_L3COMPONENT(BulkStoreMag,{b15f1e9c-8fb5-4a09-b15d-2021ce2966cc})

