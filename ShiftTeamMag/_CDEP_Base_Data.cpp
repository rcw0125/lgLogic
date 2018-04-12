// �߼���CDEP_Base_DataԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CDEP_Base_Data.h"

IMPLEMENT_L3CLASS(CDEP_Base_Data,CL3Object,1)

BEGIN_L3PROPTABLE(CDEP_Base_Data,CL3Object)
    L3PROP_STRING(IronLadle)
	L3PROP_STRING(HeatID)
	L3PROP_STRING(PreHeatID)
	L3PROP_STRING(SteelGradeIndex)
	L3PROP_STRING(SteelGrade)
	L3PROP_STRING(Shift)
	L3PROP_STRING(Team)
	L3PROP_STRING(HeadFurnace)
	L3PROP_STRING(Assistant)
	L3PROP_STRING(SecondHand)
	L3PROP_DATETIME(ProductionDate)
	L3PROP_DATETIME(StatisticsDate)
	L3PROP_SHORT(Locked)
	L3PROP_LONG(NC_Confirm_Flag)
END_L3PROPTABLE(CDEP_Base_Data)

BEGIN_L3METHODMAP(CDEP_Base_Data,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CDEP_Base_Data,CL3Object)
END_L3EVENTSINK_MAP(CDEP_Base_Data)

CDEP_Base_Data::CDEP_Base_Data(void)
{
}

CDEP_Base_Data::~CDEP_Base_Data(void)
{
}
