// �߼���CTundish_TFF_Refra_UseԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CTundish_TFF_Refra_Use.h"

IMPLEMENT_L3CLASS(CTundish_TFF_Refra_Use,CL3Object,1)

BEGIN_L3PROPTABLE(CTundish_TFF_Refra_Use,CL3Object)
	L3PROP_DATETIME(Input_Time)
	L3PROP_STRING(TundishID)
	L3PROP_STRING(Cast_ID)
	L3PROP_STRING(Stop_Cast_Reason)
	L3PROP_STRING(Daub_Use_Case)
	L3PROP_STRING(Tranq_Case)
	L3PROP_STRING(Frist_Tuck_Stick_Case)
	L3PROP_STRING(Sec_Tuck_Stick_Case)
	L3PROP_STRING(Thr_Tuck_Stick_Case)
	L3PROP_STRING(For_Tuck_Stick_Case)
	L3PROP_STRING(Frist_Water_Gap_Case)
	L3PROP_STRING(Sec_Water_Gap_Case)
	L3PROP_STRING(Thr_Water_Gap_Case)
	L3PROP_STRING(For_Water_Gap_Case)
	L3PROP_STRING(Ward_Dregs_Case)
	L3PROP_STRING(Cover_Use_Case)
	L3PROP_STRING(Protect_Use_Case)
	L3PROP_STRING(Pro_Temp_Use_Case)
	L3PROP_STRING(Note)
	L3PROP_STRING(TeamID)
	L3PROP_STRING(ShiftID)
	L3PROP_STRING(Operator)
	L3PROP_STRING(TundishNO)
	L3PROP_LONG(Confirm_Flag)

END_L3PROPTABLE(CTundish_TFF_Refra_Use)

BEGIN_L3METHODMAP(CTundish_TFF_Refra_Use,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CTundish_TFF_Refra_Use,CL3Object)
END_L3EVENTSINK_MAP(CTundish_TFF_Refra_Use)

CTundish_TFF_Refra_Use::CTundish_TFF_Refra_Use(void)
{
}

CTundish_TFF_Refra_Use::~CTundish_TFF_Refra_Use(void)
{
}
