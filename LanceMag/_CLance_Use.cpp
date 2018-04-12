// �߼���CLance_UseԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CLance_Use.h"

IMPLEMENT_L3CLASS(CLance_Use,CL3Object,1)

BEGIN_L3PROPTABLE(CLance_Use,CL3Object)
	L3PROP_DATETIME(Input_Time)
	L3PROP_STRING(LanceID)
	L3PROP_STRING(MakeID)
	L3PROP_STRING(Lance_Head_Type)
	L3PROP_STRING(HeatID)
	L3PROP_DATETIME(Shift_Date)
	L3PROP_DOUBLE(Cool_Water_Flow)
	L3PROP_DOUBLE(Cool_Water_Temp)
	L3PROP_DOUBLE(Oxygen_Pressure)
	L3PROP_DOUBLE(Oxygen_Flow)
	L3PROP_LONG(Furnace_Count)
	L3PROP_STRING(Change_Lance_Reason)
	L3PROP_LONG(Total_Lance_Age)
	L3PROP_STRING(Amelt_Confirm_Pepole)
	L3PROP_STRING(Maintain_Confirm_Pepole)
	L3PROP_STRING(TeamID)
	L3PROP_STRING(ShiftID)
	L3PROP_STRING(Operator)
	L3PROP_STRING(Note)
END_L3PROPTABLE(CLance_Use)

BEGIN_L3METHODMAP(CLance_Use,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CLance_Use,CL3Object)
END_L3EVENTSINK_MAP(CLance_Use)

CLance_Use::CLance_Use(void)
{
}

CLance_Use::~CLance_Use(void)
{
}
