// �߼���CLadle_Fire_InfoԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CLadle_Fire_Info.h"

IMPLEMENT_L3CLASS(CLadle_Fire_Info,CL3Object,1)

BEGIN_L3PROPTABLE(CLadle_Fire_Info,CL3Object)
	L3PROP_DATETIME(Input_Time)
	L3PROP_STRING(Fire_Type)
	L3PROP_STRING(Roaster_ID)
	L3PROP_STRING(Ladle_ID)
	L3PROP_DATETIME(Start_Time)
	L3PROP_STRING(Start_Operator)
	L3PROP_DATETIME(Set_One_Time)
	L3PROP_STRING(Set_One_Operator)
	L3PROP_DATETIME(Set_Two_Time)
	L3PROP_STRING(Set_Two_Operator)
	L3PROP_DATETIME(Set_Three_Time)
	L3PROP_STRING(Set_Three_Operator)
	L3PROP_DATETIME(Set_Four_Time)
	L3PROP_STRING(Set_Four_Operator)
	L3PROP_DATETIME(End_Time)
	L3PROP_STRING(End_Operator)
	L3PROP_DATETIME(Suspend_Time)
	L3PROP_STRING(Suspend_Operator)
	L3PROP_STRING(TeamID)
	L3PROP_STRING(ShiftID)
	L3PROP_STRING(Operator)
	L3PROP_STRING(Note)
END_L3PROPTABLE(CLadle_Fire_Info)

BEGIN_L3METHODMAP(CLadle_Fire_Info,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CLadle_Fire_Info,CL3Object)
END_L3EVENTSINK_MAP(CLadle_Fire_Info)

CLadle_Fire_Info::CLadle_Fire_Info(void)
{
}

CLadle_Fire_Info::~CLadle_Fire_Info(void)
{
}
