// �߼���CQA_Lab_Sheet_AppԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CQA_Lab_Sheet_App.h"

IMPLEMENT_L3CLASS(CQA_Lab_Sheet_App,CL3Object,1)

BEGIN_L3PROPTABLE(CQA_Lab_Sheet_App,CL3Object)
	L3PROP_STRING(AppID)
	L3PROP_STRING(HeatID)
	L3PROP_STRING(Sample_Code)
	L3PROP_STRING(Sample_Address)
	L3PROP_STRING(Sample_Type)
	L3PROP_STRING(Sample_Count)
	L3PROP_DATETIME(Sample_Date)
	L3PROP_LONG(Fin_Prod_Flag)
	L3PROP_LONG(Asis_Flag)
	L3PROP_STRING(SteelGrade)
	L3PROP_STRING(Treaty)
	L3PROP_LONG(Back_Flag)
	L3PROP_DATETIME(Back_Date)
	L3PROP_LONG(ReSample_Flag)
	L3PROP_STRING(ReSample_Reason)
	L3PROP_DATETIME(ReSample_Date)
	L3PROP_LONG(SendFlag)
	L3PROP_LONG(ReSampled)
END_L3PROPTABLE(CQA_Lab_Sheet_App)

BEGIN_L3METHODMAP(CQA_Lab_Sheet_App,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CQA_Lab_Sheet_App,CL3Object)
END_L3EVENTSINK_MAP(CQA_Lab_Sheet_App)

CQA_Lab_Sheet_App::CQA_Lab_Sheet_App(void)
{
}

CQA_Lab_Sheet_App::~CQA_Lab_Sheet_App(void)
{
}
