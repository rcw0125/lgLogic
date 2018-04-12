// �߼���CLF_Base_DataԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CLF_Base_Data.h"

IMPLEMENT_L3CLASS(CLF_Base_Data,CL3Object,1)

BEGIN_L3PROPTABLE(CLF_Base_Data,CL3Object)
	L3PROP_STRING(TreatNo)
	L3PROP_STRING(HeatID)
	L3PROP_STRING(PreHeatID)
	L3PROP_STRING(SteelGradeIndex)
	L3PROP_STRING(SteelGrade)
	L3PROP_STRING(LadleNo)
	L3PROP_STRING(HeadFurnace)
	L3PROP_STRING(Assistant)
	L3PROP_STRING(SecondHand)
	L3PROP_DATETIME(ProductionDate)
	L3PROP_SHORT(Locked)
	L3PROP_STRING(Shift)
	L3PROP_STRING(Team)
	L3PROP_LONG(NC_Confirm_Flag)
END_L3PROPTABLE(CLF_Base_Data)

BEGIN_L3METHODMAP(CLF_Base_Data,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CLF_Base_Data,CL3Object)
END_L3EVENTSINK_MAP(CLF_Base_Data)

CLF_Base_Data::CLF_Base_Data(void)
{
}

CLF_Base_Data::~CLF_Base_Data(void)
{
}
