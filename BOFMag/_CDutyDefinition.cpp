// �߼���CDutyDefinitionԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CDutyDefinition.h"

IMPLEMENT_L3CLASS(CDutyDefinition,CL3Object,1)

BEGIN_L3PROPTABLE(CDutyDefinition,CL3Object)
	L3PROP_SHORT(UnitID)
	L3PROP_SHORT(PlantID)
	L3PROP_SHORT(TeamID)
	L3PROP_STRING(HeadFurnace)
	L3PROP_STRING(Assistant)
	L3PROP_STRING(SecondHand)
END_L3PROPTABLE(CDutyDefinition)

BEGIN_L3METHODMAP(CDutyDefinition,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CDutyDefinition,CL3Object)
END_L3EVENTSINK_MAP(CDutyDefinition)

CDutyDefinition::CDutyDefinition(void)
{
}

CDutyDefinition::~CDutyDefinition(void)
{
}
