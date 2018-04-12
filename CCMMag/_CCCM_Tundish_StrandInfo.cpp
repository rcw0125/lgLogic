// �߼���CCCM_Tundish_StrandInfoԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CCCM_Tundish_StrandInfo.h"

IMPLEMENT_L3CLASS(CCCM_Tundish_StrandInfo,CL3Object,1)

BEGIN_L3PROPTABLE(CCCM_Tundish_StrandInfo,CL3Object)
	L3PROP_STRING(CastingNo)
	L3PROP_STRING(TundishNo)
	L3PROP_STRING(TundishID)
	L3PROP_STRING(StrandNo)
	L3PROP_DATETIME(Start_Time)
	L3PROP_DATETIME(Stop_Time)
	L3PROP_STRING(InjectionBarNo)
	L3PROP_SHORT(WaterGap_Usage_Case)
	L3PROP_STRING(InjectionBar_Usage_Case)
	L3PROP_STRING(Reason_Holt_Casting)
	L3PROP_FLOAT(RemainWeight)
	L3PROP_STRING(Fir_HeatID)
	L3PROP_STRING(Last_HeatID)
END_L3PROPTABLE(CCCM_Tundish_StrandInfo)

BEGIN_L3METHODMAP(CCCM_Tundish_StrandInfo,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CCCM_Tundish_StrandInfo,CL3Object)
END_L3EVENTSINK_MAP(CCCM_Tundish_StrandInfo)

CCCM_Tundish_StrandInfo::CCCM_Tundish_StrandInfo(void)
{
}

CCCM_Tundish_StrandInfo::~CCCM_Tundish_StrandInfo(void)
{
}
