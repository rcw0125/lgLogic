// �߼���CPlan_EquipmentԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CPlan_Equipment.h"

IMPLEMENT_L3CLASS(CPlan_Equipment,CL3Object,1)

BEGIN_L3PROPTABLE(CPlan_Equipment,CL3Object)
	L3PROP_STRING(UnitID)
	L3PROP_STRING(Unit_TypeID)
	L3PROP_DATETIME(EndStopTime_Aim)
	L3PROP_DATETIME(BeginStopTime_Aim)
	L3PROP_STRING(TeamID)
	L3PROP_STRING(ShiftID)
	L3PROP_STRING(Operator)
END_L3PROPTABLE(CPlan_Equipment)

BEGIN_L3METHODMAP(CPlan_Equipment,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CPlan_Equipment,CL3Object)
END_L3EVENTSINK_MAP(CPlan_Equipment)

CPlan_Equipment::CPlan_Equipment(void)
{
}

CPlan_Equipment::~CPlan_Equipment(void)
{
}
