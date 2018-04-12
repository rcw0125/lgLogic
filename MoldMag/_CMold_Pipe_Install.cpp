// �߼���CMold_Pipe_InstallԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CMold_Pipe_Install.h"

IMPLEMENT_L3CLASS(CMold_Pipe_Install,CL3Object,1)

BEGIN_L3PROPTABLE(CMold_Pipe_Install,CL3Object)
	L3PROP_DATETIME(Input_Time)
	L3PROP_DATETIME(Install_Date)
	L3PROP_STRING(MoldID)
	L3PROP_LONG(Hit_Press_Flag)
	L3PROP_STRING(Copper_ID)
	L3PROP_STRING(Copper_Fac)
	L3PROP_STRING(Install_Per)
	L3PROP_DATETIME(Repair_Start_Time)
	L3PROP_DATETIME(Repair_End_Time)
	L3PROP_STRING(Repair_Content)
	L3PROP_STRING(TeamID)
	L3PROP_STRING(ShiftID)
	L3PROP_STRING(Operator)
	L3PROP_STRING(Note)
	L3PROP_STRING(InStallID)
	L3PROP_LONG(ConfirmFlag)
END_L3PROPTABLE(CMold_Pipe_Install)

BEGIN_L3METHODMAP(CMold_Pipe_Install,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CMold_Pipe_Install,CL3Object)
END_L3EVENTSINK_MAP(CMold_Pipe_Install)

CMold_Pipe_Install::CMold_Pipe_Install(void)
{
}

CMold_Pipe_Install::~CMold_Pipe_Install(void)
{
}
