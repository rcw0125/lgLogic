// �߼���CEquip_Level_LogԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CEquip_Level_Log.h"

IMPLEMENT_L3CLASS(CEquip_Level_Log,CL3Object,1)

BEGIN_L3PROPTABLE(CEquip_Level_Log,CL3Object)
	L3PROP_STRING(CCMID)
	L3PROP_STRING(StrandNo)
	L3PROP_STRING(Zero_B_Act)
	L3PROP_STRING(Zero_A_Act)
	L3PROP_STRING(Full_B_Act)
	L3PROP_STRING(Full_A_Act)
	L3PROP_STRING(N0_Std)
	L3PROP_STRING(N0_Act)
	L3PROP_STRING(N7_N8_Std)
	L3PROP_STRING(N7_N8_Act)
	L3PROP_STRING(N10_Std)
	L3PROP_STRING(N10_Act)
	L3PROP_DATETIME(Check_Date)
	L3PROP_DATETIME(Create_Time)
	L3PROP_STRING(Operator)
	L3PROP_LONG(Status)
END_L3PROPTABLE(CEquip_Level_Log)

BEGIN_L3METHODMAP(CEquip_Level_Log,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CEquip_Level_Log,CL3Object)
END_L3EVENTSINK_MAP(CEquip_Level_Log)

CEquip_Level_Log::CEquip_Level_Log(void)
{
}

CEquip_Level_Log::~CEquip_Level_Log(void)
{
}
