// �߼���CVacTube_Hot_Syp_RepairԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CVacTube_Hot_Syp_Repair.h"

IMPLEMENT_L3CLASS(CVacTube_Hot_Syp_Repair,CL3Object,1)

BEGIN_L3PROPTABLE(CVacTube_Hot_Syp_Repair,CL3Object)
	
	L3PROP_DATETIME(Input_Time)
	L3PROP_STRING(Build_ID)
	L3PROP_STRING(Hot_Syp_ID)
	L3PROP_STRING(Refra_Fac)
	L3PROP_LONG(Hot_Syp_Age)
	L3PROP_DOUBLE(Mg_Cr_Bri_Dir_Waste)
	L3PROP_DOUBLE(Mg_Cr_Bri_Half_Waste)
	L3PROP_DOUBLE(Bear_Fir_Waste)
	L3PROP_DOUBLE(Si_Ca_Boa_Waste)
	L3PROP_DOUBLE(Light_Mat_Bri_Waste)
	L3PROP_DOUBLE(Cast_Wast)
	L3PROP_STRING(Repair_Position)
	L3PROP_STRING(Repair_Case)
	L3PROP_STRING(Repair_Per)
	L3PROP_STRING(TeamID)
	L3PROP_STRING(ShiftID)
	L3PROP_STRING(Note)
END_L3PROPTABLE(CVacTube_Hot_Syp_Repair)

BEGIN_L3METHODMAP(CVacTube_Hot_Syp_Repair,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CVacTube_Hot_Syp_Repair,CL3Object)
END_L3EVENTSINK_MAP(CVacTube_Hot_Syp_Repair)

CVacTube_Hot_Syp_Repair::CVacTube_Hot_Syp_Repair(void)
{
}

CVacTube_Hot_Syp_Repair::~CVacTube_Hot_Syp_Repair(void)
{
}
