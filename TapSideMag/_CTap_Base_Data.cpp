// �߼���CTap_Base_DataԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CTap_Base_Data.h"

IMPLEMENT_L3CLASS(CTap_Base_Data,CL3Object,1)

BEGIN_L3PROPTABLE(CTap_Base_Data,CL3Object)
	L3PROP_STRING(HeatID)
	L3PROP_STRING(SteelGradeIndex)
	L3PROP_STRING(SteelGrade)
	L3PROP_STRING(LadleNo)
	L3PROP_STRING(PreHeatID)
	L3PROP_DATETIME(ProductionDate)
	L3PROP_STRING(Shift)
	L3PROP_STRING(Team)
	L3PROP_SHORT(Locked)
END_L3PROPTABLE(CTap_Base_Data)

BEGIN_L3METHODMAP(CTap_Base_Data,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CTap_Base_Data,CL3Object)
END_L3EVENTSINK_MAP(CTap_Base_Data)

CTap_Base_Data::CTap_Base_Data(void)
{
}

CTap_Base_Data::~CTap_Base_Data(void)
{
}
