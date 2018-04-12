// �߼���CIronLadle_TieԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CIronLadle_Tie.h"

IMPLEMENT_L3CLASS(CIronLadle_Tie,CL3Object,1)

BEGIN_L3PROPTABLE(CIronLadle_Tie,CL3Object)
	L3PROP_DATETIME(InPut_Time)
	L3PROP_STRING(IronLadleID)
	L3PROP_STRING(TieID)
	L3PROP_STRING(Refra_Produce)
	L3PROP_STRING(Refra_ID)
	L3PROP_FLOAT(Consumption)
	L3PROP_DATETIME(Tie_Start_Time)
	L3PROP_DATETIME(Tie_End_Time)
	L3PROP_STRING(TeamID)
	L3PROP_STRING(ShiftID)
	L3PROP_STRING(Operator)
	L3PROP_STRING(Note)
	L3PROP_DATETIME(Doff_Mod_Time)
END_L3PROPTABLE(CIronLadle_Tie)

BEGIN_L3METHODMAP(CIronLadle_Tie,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CIronLadle_Tie,CL3Object)
END_L3EVENTSINK_MAP(CIronLadle_Tie)

CIronLadle_Tie::CIronLadle_Tie(void)
{
}

CIronLadle_Tie::~CIronLadle_Tie(void)
{
}
