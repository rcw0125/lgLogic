// �߼���CTundish_Use_InfoԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CTundish_Use_Info.h"

IMPLEMENT_L3CLASS(CTundish_Use_Info,CL3Object,1)

BEGIN_L3PROPTABLE(CTundish_Use_Info,CL3Object)
	L3PROP_DATETIME(Creat_Time)
	L3PROP_STRING(TundishID)
	L3PROP_STRING(InnerID)
	L3PROP_STRING(WorkID)
	L3PROP_STRING(Vehicle_ID)
	L3PROP_STRING(Cast_ID)
	L3PROP_STRING(TundishNO)
	L3PROP_DATETIME(Inner_Tie_Start_Time)
	L3PROP_DATETIME(Inner_Tie_End_Time)
	L3PROP_DATETIME(Inner_Small_Fire_Time)
	L3PROP_DATETIME(Inner_Close_Fire_Time)
	L3PROP_DATETIME(Daub_Start_Time)
	L3PROP_DATETIME(Daub_End_Time)
	L3PROP_DATETIME(Fire_Start_Time)
	L3PROP_DATETIME(Fire_End_Time)
	L3PROP_DATETIME(Install_Start_Time)
	L3PROP_DATETIME(Install_End_Time)
	L3PROP_DATETIME(Hot_Small_Start_Time)
	L3PROP_DATETIME(Hot_Big_End_Time)
	L3PROP_DATETIME(Cast_Start_Time)
	L3PROP_DATETIME(Cast_End_Time)
	L3PROP_LONG(Confirm_Flag)
	
END_L3PROPTABLE(CTundish_Use_Info)

BEGIN_L3METHODMAP(CTundish_Use_Info,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CTundish_Use_Info,CL3Object)
END_L3EVENTSINK_MAP(CTundish_Use_Info)

CTundish_Use_Info::CTundish_Use_Info(void)
{
}

CTundish_Use_Info::~CTundish_Use_Info(void)
{
}

