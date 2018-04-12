// �߼���CTundish_Inner_BuildԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CTundish_Inner_Build.h"

IMPLEMENT_L3CLASS(CTundish_Inner_Build,CL3Object,1)

BEGIN_L3PROPTABLE(CTundish_Inner_Build,CL3Object)
	L3PROP_STRING(TundishID)
	L3PROP_STRING(InnerID)
	L3PROP_SHORT(Inner_Use_Count)
	L3PROP_DATETIME(Tie_Start_Time)
	L3PROP_DATETIME(Tie_End_Time)
	L3PROP_STRING(Refra_Fac)
	L3PROP_STRING(Refra_ID)
	L3PROP_DOUBLE(Waste)
	L3PROP_STRING(TeamID)
	L3PROP_STRING(ShiftID)
	L3PROP_STRING(Operator)
	L3PROP_STRING(Note)
	L3PROP_DATETIME(Check_Date)
	L3PROP_LONG(Confirm_Flag)
	
	
END_L3PROPTABLE(CTundish_Inner_Build)

BEGIN_L3METHODMAP(CTundish_Inner_Build,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CTundish_Inner_Build,CL3Object)
END_L3EVENTSINK_MAP(CTundish_Inner_Build)

CTundish_Inner_Build::CTundish_Inner_Build(void)
{
}

CTundish_Inner_Build::~CTundish_Inner_Build(void)
{
}
