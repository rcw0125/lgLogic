// �߼���CLadle_PlanԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CLadle_Plan.h"

IMPLEMENT_L3CLASS(CLadle_Plan,CL3Object,1)

BEGIN_L3PROPTABLE(CLadle_Plan,CL3Object)
	L3PROP_STRING(PlanID)
	L3PROP_STRING(SteelGradeIndex)				
	L3PROP_DATETIME(CreateDate)
	L3PROP_STRING(HeatID)
	L3PROP_STRING(CasterID)
	L3PROP_STRING(UnitID)	
	L3PROP_STRING(LadleID)
	L3PROP_LONG(Ladle_Age)
	L3PROP_LONG(New_BOF_Flag)
	L3PROP_STRING(Status)
	L3PROP_DATETIME(Act_Time_IronPrepared)
	L3PROP_DATETIME(Act_Time_BOFStart)
	L3PROP_DATETIME(Act_Time_BOFTapped)
	L3PROP_DATETIME(Act_Time_TappedSideEnd)
	L3PROP_DATETIME(Act_Time_LFArrival)
	L3PROP_DATETIME(Act_Time_LFStart)
	L3PROP_DATETIME(Act_Time_LFEnd)
	L3PROP_DATETIME(Act_Time_LFLeave)
	L3PROP_DATETIME(Act_Time_RHArrival)
	L3PROP_DATETIME(Act_Time_RHStart)
	L3PROP_DATETIME(Act_Time_RHEnd)
	L3PROP_DATETIME(Act_Time_RHLeave)
	L3PROP_DATETIME(Act_Time_CasterArrival)
	L3PROP_DATETIME(Act_Time_CastingStart)
	L3PROP_DATETIME(Act_Time_CastingEnd)
	L3PROP_STRING(TeamID)
	L3PROP_STRING(ShiftID)
	L3PROP_STRING(Operator)
	L3PROP_STRING(Note)

END_L3PROPTABLE(CLadle_Plan)

BEGIN_L3METHODMAP(CLadle_Plan,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CLadle_Plan,CL3Object)
END_L3EVENTSINK_MAP(CLadle_Plan)

CLadle_Plan::CLadle_Plan(void)
{
}

CLadle_Plan::~CLadle_Plan(void)
{
}
