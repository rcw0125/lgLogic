// �߼���CCCM_Heat_TundishTempԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CCCM_Heat_TundishTemp.h"

IMPLEMENT_L3CLASS(CCCM_Heat_TundishTemp,CL3Object,1)

BEGIN_L3PROPTABLE(CCCM_Heat_TundishTemp,CL3Object)
	L3PROP_STRING(HeatID)
	L3PROP_STRING(CCMID)
	L3PROP_SHORT(TempID)
	L3PROP_SHORT(Temp)
	L3PROP_DATETIME(Measure_Time)
	L3PROP_SHORT(InValidFlag)
END_L3PROPTABLE(CCCM_Heat_TundishTemp)

BEGIN_L3METHODMAP(CCCM_Heat_TundishTemp,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CCCM_Heat_TundishTemp,CL3Object)
END_L3EVENTSINK_MAP(CCCM_Heat_TundishTemp)

CCCM_Heat_TundishTemp::CCCM_Heat_TundishTemp(void)
{
}

CCCM_Heat_TundishTemp::~CCCM_Heat_TundishTemp(void)
{
}
