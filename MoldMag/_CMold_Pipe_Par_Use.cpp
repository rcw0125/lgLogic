// �߼���CMold_Pipe_Par_UseԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CMold_Pipe_Par_Use.h"

IMPLEMENT_L3CLASS(CMold_Pipe_Par_Use,CL3Object,1)

BEGIN_L3PROPTABLE(CMold_Pipe_Par_Use,CL3Object)
	L3PROP_DATETIME(Input_Time)
	L3PROP_STRING(MoldID)
	L3PROP_STRING(Copper_ID)
	L3PROP_STRING(Copper_Fac)
	L3PROP_LONG(Cur_Use_Count)
	L3PROP_LONG(Total_Use_Count)
	L3PROP_DOUBLE(Cur_Pull_Mea)
	L3PROP_DOUBLE(Total_Pull_Mea)
	L3PROP_STRING(Cast_ID)
	L3PROP_STRING(FlowID)
	L3PROP_LONG(OnLine_Flag)
	L3PROP_DATETIME(OnLine_Time)
	L3PROP_STRING(Stop_Reason)
	L3PROP_LONG(OffLine_Flag)
	L3PROP_DATETIME(OffLine_Time)
	L3PROP_DOUBLE(Ruler)
	L3PROP_STRING(TeamID)
	L3PROP_STRING(ShiftID)
	L3PROP_STRING(Operator)
	L3PROP_STRING(Note)
	L3PROP_STRING(InStallID)
	L3PROP_LONG(ConfirmFlag)
END_L3PROPTABLE(CMold_Pipe_Par_Use)

BEGIN_L3METHODMAP(CMold_Pipe_Par_Use,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CMold_Pipe_Par_Use,CL3Object)
END_L3EVENTSINK_MAP(CMold_Pipe_Par_Use)

CMold_Pipe_Par_Use::CMold_Pipe_Par_Use(void)
{
}

CMold_Pipe_Par_Use::~CMold_Pipe_Par_Use(void)
{
}
