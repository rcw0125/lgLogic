// �߼���CQA_Heat_DataԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CQA_Heat_Data.h"

IMPLEMENT_L3CLASS(CQA_Heat_Data,CL3Object,1)

BEGIN_L3PROPTABLE(CQA_Heat_Data,CL3Object)
	L3PROP_STRING(HeatID)
	L3PROP_LONG(Proc_Cnt)
	L3PROP_STRING(Unit_Type)
	L3PROP_STRING(UnitID)
	L3PROP_STRING(Except_Code)
	L3PROP_STRING(Decide_Code)
	L3PROP_STRING(PreHeatID)
	L3PROP_STRING(Heat_Lev)
	L3PROP_STRING(SteelGradeIndex)
	L3PROP_STRING(Act_SteelGradeIndex)
	L3PROP_LONG(Data_Mod)
END_L3PROPTABLE(CQA_Heat_Data)

BEGIN_L3METHODMAP(CQA_Heat_Data,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CQA_Heat_Data,CL3Object)
END_L3EVENTSINK_MAP(CQA_Heat_Data)

CQA_Heat_Data::CQA_Heat_Data(void)
{
}

CQA_Heat_Data::~CQA_Heat_Data(void)
{
}
