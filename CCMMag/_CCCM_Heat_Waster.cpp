// �߼���CCCM_Heat_WasterԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CCCM_Heat_Waster.h"

IMPLEMENT_L3CLASS(CCCM_Heat_Waster,CL3Object,1)

BEGIN_L3PROPTABLE(CCCM_Heat_Waster,CL3Object)
	L3PROP_STRING(HeatID)
	L3PROP_STRING(CCMID)
	L3PROP_STRING(TreatNo)
	L3PROP_STRING(BloomID)
	L3PROP_FLOAT(Weight)
	L3PROP_STRING(Reason)
	L3PROP_DATETIME(Log_Time)
END_L3PROPTABLE(CCCM_Heat_Waster)

BEGIN_L3METHODMAP(CCCM_Heat_Waster,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CCCM_Heat_Waster,CL3Object)
END_L3EVENTSINK_MAP(CCCM_Heat_Waster)

CCCM_Heat_Waster::CCCM_Heat_Waster(void)
{
}

CCCM_Heat_Waster::~CCCM_Heat_Waster(void)
{
}
