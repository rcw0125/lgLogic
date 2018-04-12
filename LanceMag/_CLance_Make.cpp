// �߼���CLance_MakeԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CLance_Make.h"

IMPLEMENT_L3CLASS(CLance_Make,CL3Object,1)

BEGIN_L3PROPTABLE(CLance_Make,CL3Object)
	L3PROP_DATETIME(Input_Time)
	L3PROP_STRING(LanceID)
	L3PROP_DATETIME(Check_Date)
	L3PROP_STRING(Lance_Head_Type)
	L3PROP_STRING(MakeID)
	L3PROP_STRING(Nozzle_Factury)
	L3PROP_DOUBLE(Nozzle_Throat_Dia)
	L3PROP_DOUBLE(Nozzle_Angle)
	L3PROP_STRING(Weld_Operator)
	L3PROP_STRING(Suppress_Operator)
	L3PROP_DOUBLE(Test_Water_Pressure)
	L3PROP_DATETIME(Assembly_Starte_Time)
	L3PROP_DATETIME(Assembly_End_Time)
	L3PROP_DOUBLE(Nasal_Erosion)
	L3PROP_LONG(Exit_Shape)
	L3PROP_LONG(Sundry)
	L3PROP_STRING(TeamID)
	L3PROP_STRING(ShiftID)
	L3PROP_STRING(Operator)
	L3PROP_STRING(Note)
END_L3PROPTABLE(CLance_Make)

BEGIN_L3METHODMAP(CLance_Make,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CLance_Make,CL3Object)
END_L3EVENTSINK_MAP(CLance_Make)

CLance_Make::CLance_Make(void)
{
}

CLance_Make::~CLance_Make(void)
{
}
