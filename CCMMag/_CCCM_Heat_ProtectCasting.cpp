// �߼���CCCM_Heat_ProtectCastingԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CCCM_Heat_ProtectCasting.h"

IMPLEMENT_L3CLASS(CCCM_Heat_ProtectCasting,CL3Object,1)

BEGIN_L3PROPTABLE(CCCM_Heat_ProtectCasting,CL3Object)
	L3PROP_STRING(HeatID)
	L3PROP_STRING(CCMID)
	L3PROP_DATETIME(Start_Time)
	L3PROP_DATETIME(Stop_Time)
	L3PROP_FLOAT(Ar_Flow)
END_L3PROPTABLE(CCCM_Heat_ProtectCasting)

BEGIN_L3METHODMAP(CCCM_Heat_ProtectCasting,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CCCM_Heat_ProtectCasting,CL3Object)
END_L3EVENTSINK_MAP(CCCM_Heat_ProtectCasting)

CCCM_Heat_ProtectCasting::CCCM_Heat_ProtectCasting(void)
{
}

CCCM_Heat_ProtectCasting::~CCCM_Heat_ProtectCasting(void)
{
}
