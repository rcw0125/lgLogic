// �߼���CIronLadle_FireԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CIronLadle_Fire.h"

IMPLEMENT_L3CLASS(CIronLadle_Fire,CL3Object,1)

BEGIN_L3PROPTABLE(CIronLadle_Fire,CL3Object)
	L3PROP_DATETIME(Input_Time)
	L3PROP_STRING(IronLadleID)
	L3PROP_STRING(TieID)
	L3PROP_STRING(Fire_Type)
	L3PROP_DATETIME(Fire_Start_Time)
	L3PROP_DATETIME(Fire_End_Time)
	L3PROP_LONG(Fire_Length)
	L3PROP_STRING(Operator)
	L3PROP_STRING(NOTE)
	L3PROP_STRING(TeamID)
	L3PROP_STRING(ShiftID)
	
	//2009-03-17
	L3PROP_LONG(FireID)
	L3PROP_STRING(Object_ID)

END_L3PROPTABLE(CIronLadle_Fire)

BEGIN_L3METHODMAP(CIronLadle_Fire,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CIronLadle_Fire,CL3Object)
END_L3EVENTSINK_MAP(CIronLadle_Fire)

CIronLadle_Fire::CIronLadle_Fire(void)
{
}

CIronLadle_Fire::~CIronLadle_Fire(void)
{
}
