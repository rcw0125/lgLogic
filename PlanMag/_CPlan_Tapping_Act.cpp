// �߼���CPlan_Tapping_ActԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CPlan_Tapping_Act.h"

IMPLEMENT_L3CLASS(CPlan_Tapping_Act,CL3Object,1)

BEGIN_L3PROPTABLE(CPlan_Tapping_Act,CL3Object)
	L3PROP_STRING(PreHeatID)
	L3PROP_STRING(CasterID)
	L3PROP_STRING(HeatID)
	L3PROP_STRING(LF_TreatNo)
	L3PROP_STRING(RH_TreatNo)
	L3PROP_STRING(Caster_TreatNo)
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
	L3PROP_DATETIME(CreateDate)
	L3PROP_STRING(BOFID)
	L3PROP_STRING(LFID)
	L3PROP_STRING(RHID)
END_L3PROPTABLE(CPlan_Tapping_Act)

BEGIN_L3METHODMAP(CPlan_Tapping_Act,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CPlan_Tapping_Act,CL3Object)
END_L3EVENTSINK_MAP(CPlan_Tapping_Act)

CPlan_Tapping_Act::CPlan_Tapping_Act(void)
{
}

CPlan_Tapping_Act::~CPlan_Tapping_Act(void)
{
}
