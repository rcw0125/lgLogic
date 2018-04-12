// �߼���CTundish_Inner_FireԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CTundish_Inner_Fire.h"

IMPLEMENT_L3CLASS(CTundish_Inner_Fire,CL3Object,1)

BEGIN_L3PROPTABLE(CTundish_Inner_Fire,CL3Object)
	
	L3PROP_STRING(TundishID)
	L3PROP_STRING(InnerID)
	L3PROP_DATETIME(Small_Fire_Time)
	L3PROP_STRING(Small_Fire_Operator)
	L3PROP_DATETIME(Mid_Fire_Time)
	L3PROP_STRING(Mid_Fire_Operator)
	L3PROP_DATETIME(Big_Fire_Time)
	L3PROP_STRING(Big_Fire_Operator)
	L3PROP_DATETIME(Close_Fire_Time)
	L3PROP_STRING(Close_Fire_Operator)
	L3PROP_STRING(TeamID)
	L3PROP_STRING(ShiftID)
	L3PROP_STRING(Operator)
	L3PROP_STRING(Note)
	L3PROP_LONG(Confirm_Flag)
	
END_L3PROPTABLE(CTundish_Inner_Fire)

BEGIN_L3METHODMAP(CTundish_Inner_Fire,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CTundish_Inner_Fire,CL3Object)
END_L3EVENTSINK_MAP(CTundish_Inner_Fire)

CTundish_Inner_Fire::CTundish_Inner_Fire(void)
{
}

CTundish_Inner_Fire::~CTundish_Inner_Fire(void)
{
}
