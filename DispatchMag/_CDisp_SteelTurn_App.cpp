// �߼���CDisp_SteelTurn_AppԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CDisp_SteelTurn_App.h"

IMPLEMENT_L3CLASS(CDisp_SteelTurn_App,CL3Object,1)

BEGIN_L3PROPTABLE(CDisp_SteelTurn_App,CL3Object)
	L3PROP_STRING(ObjectID)
	L3PROP_STRING(PreHeatID)
	L3PROP_STRING(SteelGradeIndex)
	L3PROP_STRING(HeatID)
	L3PROP_DATETIME(App_Time)
	L3PROP_STRING(App_UnitID)
	L3PROP_DOUBLE(App_Steel_Weight)
	L3PROP_STRING(App_Operator)
	L3PROP_STRING(App_Reason)
	L3PROP_DATETIME(Turn_Time)
	L3PROP_STRING(Turn_Operator)
	L3PROP_LONG(Turn_Flag)
	L3PROP_LONG(All_Turn_Flag)
	L3PROP_LONG(NC_Confirm_Flag)
	L3PROP_STRING(Shift)
	L3PROP_STRING(Team)
END_L3PROPTABLE(CDisp_SteelTurn_App)

BEGIN_L3METHODMAP(CDisp_SteelTurn_App,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CDisp_SteelTurn_App,CL3Object)
END_L3EVENTSINK_MAP(CDisp_SteelTurn_App)

CDisp_SteelTurn_App::CDisp_SteelTurn_App(void)
{
}

CDisp_SteelTurn_App::~CDisp_SteelTurn_App(void)
{
}
