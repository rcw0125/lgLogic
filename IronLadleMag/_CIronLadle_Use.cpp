// �߼���CIronLadle_UseԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CIronLadle_Use.h"

IMPLEMENT_L3CLASS(CIronLadle_Use,CL3Object,1)

BEGIN_L3PROPTABLE(CIronLadle_Use,CL3Object)
	L3PROP_DATETIME(Input_Time)
	L3PROP_STRING(IronLadleID)
	L3PROP_STRING(TieID)
	L3PROP_DATETIME(Check_Time)
	L3PROP_LONG(IronLadle_Age)
	L3PROP_FLOAT(Wall_TEMP)
	L3PROP_FLOAT(Bottom_TEMP)
	L3PROP_STRING(Stop_Reason)
	L3PROP_STRING(Throw_Time)
	L3PROP_STRING(TeamID)
	L3PROP_STRING(ShiftID)
	L3PROP_STRING(Operator)
	L3PROP_STRING(Note)
END_L3PROPTABLE(CIronLadle_Use)

BEGIN_L3METHODMAP(CIronLadle_Use,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CIronLadle_Use,CL3Object)
END_L3EVENTSINK_MAP(CIronLadle_Use)

CIronLadle_Use::CIronLadle_Use(void)
{
}

CIronLadle_Use::~CIronLadle_Use(void)
{
}
