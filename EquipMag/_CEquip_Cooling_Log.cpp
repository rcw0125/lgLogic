// �߼���CEquip_Cooling_LogԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CEquip_Cooling_Log.h"

IMPLEMENT_L3CLASS(CEquip_Cooling_Log,CL3Object,1)

BEGIN_L3PROPTABLE(CEquip_Cooling_Log,CL3Object)
	L3PROP_STRING(BOFID)
	L3PROP_DATETIME(Time_Chong_called)
	L3PROP_DATETIME(Time_Experiment)
	L3PROP_STRING(Reason_UnCleaning)
	L3PROP_STRING(Problem_Inspection)
	L3PROP_DATETIME(Check_Date)
	L3PROP_DATETIME(Create_Time)
	L3PROP_STRING(Operator)
	L3PROP_LONG(Status)
END_L3PROPTABLE(CEquip_Cooling_Log)

BEGIN_L3METHODMAP(CEquip_Cooling_Log,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CEquip_Cooling_Log,CL3Object)
END_L3EVENTSINK_MAP(CEquip_Cooling_Log)

CEquip_Cooling_Log::CEquip_Cooling_Log(void)
{
}

CEquip_Cooling_Log::~CEquip_Cooling_Log(void)
{
}
