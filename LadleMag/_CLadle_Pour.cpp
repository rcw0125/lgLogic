// �߼���CLadle_PourԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CLadle_Pour.h"

IMPLEMENT_L3CLASS(CLadle_Pour,CL3Object,1)

BEGIN_L3PROPTABLE(CLadle_Pour,CL3Object)
	L3PROP_DATETIME(Input_Time)
	L3PROP_STRING(Steel_Grade)
	L3PROP_STRING(HeatID)
	L3PROP_STRING(Out_LadleID)
	L3PROP_STRING(In_LadleID)
	L3PROP_STRING(Weight)
	L3PROP_STRING(WorkID)
	L3PROP_STRING(TeamID)
	L3PROP_STRING(ShiftID)
	L3PROP_STRING(Operator)
	L3PROP_STRING(Note)
	L3PROP_LONG(Confirm_Flag)
END_L3PROPTABLE(CLadle_Pour)

BEGIN_L3METHODMAP(CLadle_Pour,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CLadle_Pour,CL3Object)
END_L3EVENTSINK_MAP(CLadle_Pour)

CLadle_Pour::CLadle_Pour(void)
{
}

CLadle_Pour::~CLadle_Pour(void)
{
}
