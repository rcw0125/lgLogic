// �߼���CLadle_Com_Lad_Rep_InfoԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CLadle_Com_Lad_Rep_Info.h"

IMPLEMENT_L3CLASS(CLadle_Com_Lad_Rep_Info,CL3Object,1)

BEGIN_L3PROPTABLE(CLadle_Com_Lad_Rep_Info,CL3Object)
	L3PROP_DATETIME(Input_Time)
	L3PROP_SHORT(Number)
	L3PROP_STRING(Ladle_ID)
	L3PROP_STRING(Water_gap_Bri_Fac)
	L3PROP_DOUBLE(Water_gap_Bri_Wast)
	L3PROP_STRING(Breathe_Bri_Fac)
	L3PROP_DOUBLE(Breathe_Bri_Wast)
	L3PROP_STRING(Cast_Fac)
	L3PROP_DOUBLE(Cast_Wast)
	L3PROP_DATETIME(Fire_Start_Time)
	L3PROP_DATETIME(Fire_End_Time)
	L3PROP_STRING(Rep_Ladle_Operator)
	L3PROP_STRING(TeamID)
	L3PROP_STRING(ShiftID)
	L3PROP_STRING(Operator)
	L3PROP_STRING(Note)
END_L3PROPTABLE(CLadle_Com_Lad_Rep_Info)

BEGIN_L3METHODMAP(CLadle_Com_Lad_Rep_Info,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CLadle_Com_Lad_Rep_Info,CL3Object)
END_L3EVENTSINK_MAP(CLadle_Com_Lad_Rep_Info)

CLadle_Com_Lad_Rep_Info::CLadle_Com_Lad_Rep_Info(void)
{
}

CLadle_Com_Lad_Rep_Info::~CLadle_Com_Lad_Rep_Info(void)
{
}
