// �߼���CLadle_Cha_Dre_Lin_InfoԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CLadle_Cha_Dre_Lin_Info.h"

IMPLEMENT_L3CLASS(CLadle_Cha_Dre_Lin_Info,CL3Object,1)

BEGIN_L3PROPTABLE(CLadle_Cha_Dre_Lin_Info,CL3Object)
	L3PROP_DATETIME(Input_Time)
	L3PROP_SHORT(Number)
	L3PROP_STRING(Ladle_ID)
	L3PROP_DATETIME(Cha_Slag_Line_Time)
	L3PROP_STRING(Water_gap_Bri_Fac)
	L3PROP_DOUBLE(Water_gap_Bri_Wast)
	L3PROP_STRING(Breathe_Bri_Fac)
	L3PROP_DOUBLE(Breathe_Bri_Wast)
	L3PROP_STRING(Bot_Wall_Rep_Mat_Fac)
	L3PROP_DOUBLE(Bot_Wall_Rep_Mat_Wast)
	L3PROP_STRING(Spi_Cast_Fac)
	L3PROP_DOUBLE(Spi_Cast_Wast)
	L3PROP_STRING(Seat_Bri_Installer)
	L3PROP_STRING(Buttom_Builder)
	L3PROP_STRING(Wall_Builder)
	L3PROP_STRING(Rep_Ladle_Bot)
	L3PROP_DATETIME(Fire_Start_Time)
	L3PROP_DATETIME(Fire_End_Time)
	L3PROP_DATETIME(Thr_Ladle_Time)
	L3PROP_STRING(TeamID)
	L3PROP_STRING(ShiftID)
	L3PROP_STRING(Operator)
	L3PROP_STRING(Note)
END_L3PROPTABLE(CLadle_Cha_Dre_Lin_Info)

BEGIN_L3METHODMAP(CLadle_Cha_Dre_Lin_Info,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CLadle_Cha_Dre_Lin_Info,CL3Object)
END_L3EVENTSINK_MAP(CLadle_Cha_Dre_Lin_Info)

CLadle_Cha_Dre_Lin_Info::CLadle_Cha_Dre_Lin_Info(void)
{
}

CLadle_Cha_Dre_Lin_Info::~CLadle_Cha_Dre_Lin_Info(void)
{
}
