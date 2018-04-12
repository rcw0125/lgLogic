// �߼���CEquip_SupplyWater_DataԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CEquip_SupplyWater_Data.h"

IMPLEMENT_L3CLASS(CEquip_SupplyWater_Data,CL3Object,1)

BEGIN_L3PROPTABLE(CEquip_SupplyWater_Data,CL3Object)
	L3PROP_STRING(BOFID)
	L3PROP_STRING(HeatID)
	L3PROP_FLOAT(Level_Boil)
	L3PROP_FLOAT(P_Boil)
	L3PROP_FLOAT(P_Pump_SupplyWater)
	L3PROP_FLOAT(P_Pump_SoftWater)
	L3PROP_FLOAT(Level_DeO2Box)
	L3PROP_FLOAT(Level_SoftWaterBox)
	L3PROP_FLOAT(P_MainPipe_Steam)
	L3PROP_DATETIME(Time_Start)
	L3PROP_DATETIME(Time_Stop)
	L3PROP_DATETIME(Time_Blow)
	L3PROP_SHORT(EndFlag)
	L3PROP_STRING(Shift)
	L3PROP_STRING(Team)
	L3PROP_STRING(Operator)
END_L3PROPTABLE(CEquip_SupplyWater_Data)

BEGIN_L3METHODMAP(CEquip_SupplyWater_Data,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CEquip_SupplyWater_Data,CL3Object)
END_L3EVENTSINK_MAP(CEquip_SupplyWater_Data)

CEquip_SupplyWater_Data::CEquip_SupplyWater_Data(void)
{
}

CEquip_SupplyWater_Data::~CEquip_SupplyWater_Data(void)
{
}
