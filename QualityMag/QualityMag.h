// QualityMag.h : QualityMag DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// ������


// CQualityMagApp
// �йش���ʵ�ֵ���Ϣ������� QualityMag.cpp
//

class CQualityMagApp : public CWinApp
{
public:
	CQualityMagApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};


DECLARE_L3COMPONENT(QualityMag,{4d8174a4-bdb1-40d3-a4a5-ced4cb07707d})

