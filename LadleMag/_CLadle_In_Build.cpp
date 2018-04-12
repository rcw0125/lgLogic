// �߼���CLadle_In_BuildԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CLadle_In_Build.h"

IMPLEMENT_L3CLASS(CLadle_In_Build,CL3Object,1)

BEGIN_L3PROPTABLE(CLadle_In_Build,CL3Object)
	L3PROP_DATETIME(Input_Time)
	L3PROP_STRING(InnerID)
	L3PROP_STRING(LadleID)
	L3PROP_DATETIME(Build_Start_Time)
	L3PROP_DATETIME(Build_End_Time)
	L3PROP_STRING(Ato_Lig_Cast_Fac)
	L3PROP_DOUBLE(Ato_Lig_Cast_Wast)
	L3PROP_STRING(Hard_Fi_Adi_Boa_Fac)
	L3PROP_DOUBLE(Hard_Fi_Adi_Boa_Wast)
	L3PROP_STRING(Spinel_Cast_Fac)
	L3PROP_DOUBLE(Spinel_Cast_Wast)
	L3PROP_STRING(Al_Mg_Brick_Fac)
	L3PROP_DOUBLE(Al_Mg_Brick_Wast)
	L3PROP_STRING(Mg_Firecaly_Fact)
	L3PROP_DOUBLE(Mg_Firecaly_Wast)
	L3PROP_LONG(Ladle_Inner_Use_Count)
	L3PROP_STRING(TeamID)
	L3PROP_STRING(ShiftID)
	L3PROP_STRING(Operator)
	L3PROP_STRING(Note)
	L3PROP_LONG(Confirm_Flag)
END_L3PROPTABLE(CLadle_In_Build)

BEGIN_L3METHODMAP(CLadle_In_Build,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CLadle_In_Build,CL3Object)
END_L3EVENTSINK_MAP(CLadle_In_Build)

CLadle_In_Build::CLadle_In_Build(void)
{
}

CLadle_In_Build::~CLadle_In_Build(void)
{
}
