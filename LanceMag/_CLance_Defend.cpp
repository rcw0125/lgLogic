// �߼���CLance_DefendԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CLance_Defend.h"

IMPLEMENT_L3CLASS(CLance_Defend,CL3Object,1)

BEGIN_L3PROPTABLE(CLance_Defend,CL3Object)
	L3PROP_DATETIME(Input_Time)
	L3PROP_STRING(LanceID)
	L3PROP_DATETIME(Check_Date)
	L3PROP_STRING(MakeID)
	L3PROP_STRING(Lance_Head_Type)
	L3PROP_DOUBLE(Test_Water_Pressure)
	L3PROP_DOUBLE(Nasal_Erosion)
	L3PROP_LONG(Exit_Shape)
	L3PROP_LONG(Sundry)
	L3PROP_STRING(TeamID)
	L3PROP_STRING(ShiftID)
	L3PROP_STRING(Operator)
	L3PROP_STRING(Note)
END_L3PROPTABLE(CLance_Defend)

BEGIN_L3METHODMAP(CLance_Defend,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CLance_Defend,CL3Object)
END_L3EVENTSINK_MAP(CLance_Defend)

CLance_Defend::CLance_Defend(void)
{
}

CLance_Defend::~CLance_Defend(void)
{
}
