// �߼���CCCM_Heat_SpeedԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CCCM_Heat_Speed.h"

IMPLEMENT_L3CLASS(CCCM_Heat_Speed,CL3Object,1)

BEGIN_L3PROPTABLE(CCCM_Heat_Speed,CL3Object)
	L3PROP_STRING(HeatID)
	L3PROP_STRING(CCMID)
	L3PROP_SHORT(StrandID)
	L3PROP_FLOAT(Speed)
	L3PROP_DATETIME(Change_Time)
END_L3PROPTABLE(CCCM_Heat_Speed)

BEGIN_L3METHODMAP(CCCM_Heat_Speed,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CCCM_Heat_Speed,CL3Object)
END_L3EVENTSINK_MAP(CCCM_Heat_Speed)

CCCM_Heat_Speed::CCCM_Heat_Speed(void)
{
}

CCCM_Heat_Speed::~CCCM_Heat_Speed(void)
{
}
