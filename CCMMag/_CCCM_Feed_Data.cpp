// �߼���CCCM_Feed_DataԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CCCM_Feed_Data.h"

IMPLEMENT_L3CLASS(CCCM_Feed_Data,UnitFeedingLog,1)

BEGIN_L3PROPTABLE(CCCM_Feed_Data,UnitFeedingLog)
	L3PROP_STRING(PreHeatID)
	L3PROP_STRING(HeatID)
	L3PROP_STRING(SteelGradeIndex)
	L3PROP_STRING(TreatNo)
	L3PROP_STRING(LadleNo)
END_L3PROPTABLE(CCCM_Feed_Data)

BEGIN_L3METHODMAP(CCCM_Feed_Data,UnitFeedingLog)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CCCM_Feed_Data,UnitFeedingLog)
END_L3EVENTSINK_MAP(CCCM_Feed_Data)

CCCM_Feed_Data::CCCM_Feed_Data(void)
{
}

CCCM_Feed_Data::~CCCM_Feed_Data(void)
{
}
