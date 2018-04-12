// �߼���CLadle_Use_InfoԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CLadle_Use_Info.h"

IMPLEMENT_L3CLASS(CLadle_Use_Info,CL3Object,1)

BEGIN_L3PROPTABLE(CLadle_Use_Info,CL3Object)
	L3PROP_DATETIME(Input_Time)
	L3PROP_STRING(Ladle_ID)
	L3PROP_DATETIME(Use_Date)
	L3PROP_SHORT(Ladle_Age)
	L3PROP_STRING(Bof_ID)
	L3PROP_STRING(Steel_Grade)
	L3PROP_DATETIME(Seat_OK_Time)
	L3PROP_DATETIME(Tap_Time)
	L3PROP_DATETIME(Irr_Time)
	L3PROP_DATETIME(Off_Ladle_Time)
	L3PROP_DATETIME(Arrive_Time)
	L3PROP_DATETIME(Complete_Time)
	L3PROP_DOUBLE(Fire_Time_Len)
	L3PROP_DOUBLE(Stop_Time_Len)
	L3PROP_STRING(Ladle_Check)
	L3PROP_STRING(Off_Reason)
	L3PROP_STRING(Sk_Board_Keep)
	L3PROP_STRING(Ladle_Grade)
	L3PROP_STRING(TeamID)
	L3PROP_STRING(ShiftID)
	L3PROP_STRING(Operator)
	L3PROP_STRING(Note)
END_L3PROPTABLE(CLadle_Use_Info)

BEGIN_L3METHODMAP(CLadle_Use_Info,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CLadle_Use_Info,CL3Object)
END_L3EVENTSINK_MAP(CLadle_Use_Info)

CLadle_Use_Info::CLadle_Use_Info(void)
{
}

CLadle_Use_Info::~CLadle_Use_Info(void)
{
}
