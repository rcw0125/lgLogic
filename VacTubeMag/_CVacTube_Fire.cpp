// �߼���CVacTube_FireԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CVacTube_Fire.h"

IMPLEMENT_L3CLASS(CVacTube_Fire,CL3Object,1)

BEGIN_L3PROPTABLE(CVacTube_Fire,CL3Object)

	L3PROP_DATETIME(Input_Time)
	L3PROP_STRING(VacTube_Code)
	L3PROP_STRING(Install_ID)
	L3PROP_STRING(Position)
	L3PROP_STRING(Up_Slot_ID)
	L3PROP_STRING(Bel_Slot_ID)
	L3PROP_DATETIME(Fire_Start_Time)
	L3PROP_DATETIME(Fire_End_Time)
	L3PROP_STRING(TeamID)
	L3PROP_STRING(ShiftID)
	L3PROP_STRING(Log_Per)
	L3PROP_STRING(Note)
	L3PROP_STRING(Object_ID)
	L3PROP_LONG(Fire_Soruce)
END_L3PROPTABLE(CVacTube_Fire)

BEGIN_L3METHODMAP(CVacTube_Fire,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CVacTube_Fire,CL3Object)
END_L3EVENTSINK_MAP(CVacTube_Fire)

CVacTube_Fire::CVacTube_Fire(void)
{
}

CVacTube_Fire::~CVacTube_Fire(void)
{
}
