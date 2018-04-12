// �߼���CLF_Ladle_InfoԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CLF_Ladle_Info.h"

IMPLEMENT_L3CLASS(CLF_Ladle_Info,CL3Object,1)

BEGIN_L3PROPTABLE(CLF_Ladle_Info,CL3Object)
	L3PROP_STRING(TreatNo)
	L3PROP_STRING(HeatID)
	L3PROP_STRING(LadleID)
	L3PROP_STRING(Last_Ladle_Grade)
	L3PROP_LONG(Temp)
	L3PROP_STRING(Last_SteelGrade)
	L3PROP_STRING(Act_Ladle_Grade)
	L3PROP_STRING(Cur_SteelGrade)
	L3PROP_STRING(In_Ladle_Grade)
	L3PROP_LONG(Stop_Time_Len)
	L3PROP_LONG(Ladle_Age)
	L3PROP_LONG(Small_Fire)
	L3PROP_LONG(Middle_Fire)
	L3PROP_LONG(Big_Fire)
	L3PROP_STRING(Note)
	L3PROP_STRING(Other1)
	L3PROP_STRING(Other2)
	L3PROP_STRING(Other3)
	L3PROP_LONG(MaxTemp)
END_L3PROPTABLE(CLF_Ladle_Info)

BEGIN_L3METHODMAP(CLF_Ladle_Info,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CLF_Ladle_Info,CL3Object)
END_L3EVENTSINK_MAP(CLF_Ladle_Info)

CLF_Ladle_Info::CLF_Ladle_Info(void)
{
}

CLF_Ladle_Info::~CLF_Ladle_Info(void)
{
}
