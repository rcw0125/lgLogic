// �߼���CQA_Heat_Prod_ExceptԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CQA_Heat_Prod_Except.h"

IMPLEMENT_L3CLASS(CQA_Heat_Prod_Except,CL3Object,1)

BEGIN_L3PROPTABLE(CQA_Heat_Prod_Except,CL3Object)
	L3PROP_STRING(ID_Object)
	L3PROP_STRING(HeatID)
	L3PROP_LONG(Process_Count)
	L3PROP_STRING(UnitTypeID)
	L3PROP_STRING(UnitID)
	L3PROP_STRING(PreHeatID)
	L3PROP_STRING(Pre_SteelGradeIndex)
	L3PROP_STRING(SteelGradeIndex)
	L3PROP_STRING(Exceptional_Code)
	L3PROP_STRING(Decide_Code)
	L3PROP_LONG  (Classify)
	L3PROP_DATETIME(Exceptional_Time)
END_L3PROPTABLE(CQA_Heat_Prod_Except)

BEGIN_L3METHODMAP(CQA_Heat_Prod_Except,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CQA_Heat_Prod_Except,CL3Object)
END_L3EVENTSINK_MAP(CQA_Heat_Prod_Except)

CQA_Heat_Prod_Except::CQA_Heat_Prod_Except(void)
{
}

CQA_Heat_Prod_Except::~CQA_Heat_Prod_Except(void)
{
}
