// �߼���CTundish_DaubԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CTundish_Daub.h"

IMPLEMENT_L3CLASS(CTundish_Daub,CL3Object,1)

BEGIN_L3PROPTABLE(CTundish_Daub,CL3Object)
	L3PROP_STRING(TundishID)	
	L3PROP_STRING(WorkID)
	L3PROP_STRING(InnerID)
	L3PROP_SHORT(Inner_Use_Count)
	L3PROP_STRING(Cast_ID)
	L3PROP_STRING(Project)
	L3PROP_STRING(Gap_Bri_Fac)
	L3PROP_DOUBLE(Gap_Bri_Consume)
	L3PROP_STRING(Ward_Dregs_Fac)
	L3PROP_DOUBLE(Ward_Dregs_Consume)
	L3PROP_STRING(Tranq_Fac)
	L3PROP_DOUBLE(Tranq_Consume)
	L3PROP_STRING(Daub_Fac)
	L3PROP_DOUBLE(Daub_Consume)
	L3PROP_STRING(Dry_Flap_Fac)
	L3PROP_DOUBLE(Dry_Flap_Consume)
	L3PROP_STRING(Gluemud_Fac)
	L3PROP_DOUBLE(Gluemud_Consume)
	L3PROP_DATETIME(Daub_Start_Time)
	L3PROP_DATETIME(Daub_End_Time)
	L3PROP_DATETIME(Fire_Start_Time)
	L3PROP_DATETIME(Fire_End_Time)
	L3PROP_STRING(TeamID)
	L3PROP_STRING(ShiftID)
	L3PROP_STRING(Operator)
	L3PROP_STRING(Note)
	L3PROP_LONG(Confirm_Flag)

END_L3PROPTABLE(CTundish_Daub)

BEGIN_L3METHODMAP(CTundish_Daub,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CTundish_Daub,CL3Object)
END_L3EVENTSINK_MAP(CTundish_Daub)

CTundish_Daub::CTundish_Daub(void)
{
}

CTundish_Daub::~CTundish_Daub(void)
{
}
