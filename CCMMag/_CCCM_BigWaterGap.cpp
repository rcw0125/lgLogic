// �߼���CCCM_BigWaterGapԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CCCM_BigWaterGap.h"

IMPLEMENT_L3CLASS(CCCM_BigWaterGap,CL3Object,1)

BEGIN_L3PROPTABLE(CCCM_BigWaterGap,CL3Object)
	L3PROP_STRING(CCMID)
	L3PROP_LONG(StrandNo)
	L3PROP_STRING(GapID)
	L3PROP_STRING(Factory)
	L3PROP_STRING(MatType)
	L3PROP_LONG(GapLife)
	L3PROP_DATETIME(ChangeTime)
	L3PROP_STRING(HeatID)
	L3PROP_STRING(Reason)
END_L3PROPTABLE(CCCM_BigWaterGap)

BEGIN_L3METHODMAP(CCCM_BigWaterGap,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CCCM_BigWaterGap,CL3Object)
END_L3EVENTSINK_MAP(CCCM_BigWaterGap)

CCCM_BigWaterGap::CCCM_BigWaterGap(void)
{
}

CCCM_BigWaterGap::~CCCM_BigWaterGap(void)
{
}
