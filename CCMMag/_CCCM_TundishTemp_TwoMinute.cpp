// �߼���CCCM_TundishTemp_TwoMinuteԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CCCM_TundishTemp_TwoMinute.h"

IMPLEMENT_L3CLASS(CCCM_TundishTemp_TwoMinute,CL3Object,1)

BEGIN_L3PROPTABLE(CCCM_TundishTemp_TwoMinute,CL3Object)
	L3PROP_STRING(TreatNo)
	L3PROP_STRING(CCMID)
	L3PROP_STRING(CastingNo)
	L3PROP_STRING(HeatID)
	L3PROP_FLOAT(Temp)
	L3PROP_DATETIME(Measure_Time)
END_L3PROPTABLE(CCCM_TundishTemp_TwoMinute)

BEGIN_L3METHODMAP(CCCM_TundishTemp_TwoMinute,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CCCM_TundishTemp_TwoMinute,CL3Object)
END_L3EVENTSINK_MAP(CCCM_TundishTemp_TwoMinute)

CCCM_TundishTemp_TwoMinute::CCCM_TundishTemp_TwoMinute(void)
{
}

CCCM_TundishTemp_TwoMinute::~CCCM_TundishTemp_TwoMinute(void)
{
}
