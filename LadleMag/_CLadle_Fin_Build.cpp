// �߼���CLadle_Fin_BuildԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CLadle_Fin_Build.h"

IMPLEMENT_L3CLASS(CLadle_Fin_Build,CL3Object,1)

BEGIN_L3PROPTABLE(CLadle_Fin_Build,CL3Object)
	L3PROP_DATETIME(Input_Time)
	L3PROP_STRING(WorkID)
	L3PROP_STRING(LadleID)
	L3PROP_DATETIME(Build_Start_Time)
	L3PROP_DATETIME(Build_End_Time)
	L3PROP_STRING(Water_Gap_Bri_Fac)
	L3PROP_DOUBLE(Water_Gap_Bri_Wast)
	L3PROP_STRING(Breathe_Bri_Fac)
	L3PROP_DOUBLE(Breathe_Bri_Wast)
	L3PROP_STRING(Bricklaying_Fac)
	L3PROP_STRING(Bot_Pro_Refr_Name)
	L3PROP_DOUBLE(Bot_Pro_Refr_Wast)
	L3PROP_STRING(Bot_Woke_Refr_Name)
	L3PROP_DOUBLE(Bot_Woke_Refr_Wast)
	L3PROP_STRING(Wall_Refr_Name)
	L3PROP_DOUBLE(Wall_Refr_Wast)
	L3PROP_STRING(Slag_Line_Refe_Name)
	L3PROP_DOUBLE(Slag_Line_Refe_Wast)
	L3PROP_STRING(Bot_Wall_Rep_Mat_Fac)
	L3PROP_DOUBLE(Bot_Wall_Rep_Mat_Wast)
	L3PROP_STRING(Spi_Cast_Fac)
	L3PROP_DOUBLE(Spi_Cast_Wast)
	L3PROP_STRING(Ladle_Inner_Checker)
	L3PROP_LONG(Ladle_Inner_Use_Count)
	L3PROP_STRING(Seat_Bri_Installer)
	L3PROP_STRING(Buttom_Builder)
	L3PROP_STRING(Wall_Builder)
	L3PROP_STRING(Line_Refe_Builder)
	L3PROP_STRING(Rep_Ladle_Bot)
	L3PROP_DATETIME(Fire_Start_Time)
	L3PROP_DATETIME(Fire_End_Time)
	L3PROP_DATETIME(Thr_Ladle_Time)
	L3PROP_STRING(TeamID)
	L3PROP_STRING(ShiftID)
	L3PROP_STRING(Operator)
	L3PROP_STRING(Note)
	L3PROP_LONG(Confirm_Flag)
END_L3PROPTABLE(CLadle_Fin_Build)

BEGIN_L3METHODMAP(CLadle_Fin_Build,CL3Object)
	
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CLadle_Fin_Build,CL3Object)
END_L3EVENTSINK_MAP(CLadle_Fin_Build)

CLadle_Fin_Build::CLadle_Fin_Build(void)
{
}

CLadle_Fin_Build::~CLadle_Fin_Build(void)
{
}
