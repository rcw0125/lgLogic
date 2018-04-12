// �߼���CCCM_Heat_LadleԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CCCM_Heat_Ladle.h"

IMPLEMENT_L3CLASS(CCCM_Heat_Ladle,CL3Object,1)

BEGIN_L3PROPTABLE(CCCM_Heat_Ladle,CL3Object)
	///2009-02-13 ����Ƿ��Զ������� ���Զ�����ԭ��
	L3PROP_STRING(HeatID)
	L3PROP_STRING(TreatNo)
	L3PROP_STRING(CCMID)
	L3PROP_STRING(LadleID)
	L3PROP_FLOAT(Weight)
	L3PROP_FLOAT(RemainWeight)
	L3PROP_DATETIME(Arrival_Time)
	L3PROP_STRING(LadleType)
	L3PROP_DATETIME(Departure_Time)
	L3PROP_DATETIME(Casting_Start_Time)
	L3PROP_DATETIME(Casting_Stop_Time)
	L3PROP_LONG(HoldTime)
	L3PROP_LONG(Temp)
	L3PROP_SHORT(TempUpTo)
	L3PROP_STRING(HoldTime_Reason)
	L3PROP_SHORT(Protection)
	L3PROP_STRING(UnProtection_Reason)
	L3PROP_LONG(AutoFlow)
	L3PROP_STRING(UnAutoFlow_Reason)
	L3PROP_FLOAT(CastingTundishWeight)
END_L3PROPTABLE(CCCM_Heat_Ladle)

BEGIN_L3METHODMAP(CCCM_Heat_Ladle,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CCCM_Heat_Ladle,CL3Object)
END_L3EVENTSINK_MAP(CCCM_Heat_Ladle)

CCCM_Heat_Ladle::CCCM_Heat_Ladle(void)
{
}

CCCM_Heat_Ladle::~CCCM_Heat_Ladle(void)
{
}
