// �߼���CCCM_Heat_ElecStirringԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CCCM_Heat_ElecStirring.h"

IMPLEMENT_L3CLASS(CCCM_Heat_ElecStirring,CL3Object,1)

BEGIN_L3PROPTABLE(CCCM_Heat_ElecStirring,CL3Object)
	L3PROP_STRING(HeatID)
	L3PROP_STRING(CCMID)
	L3PROP_SHORT(StrandID)
	L3PROP_SHORT(Stirring)
	L3PROP_FLOAT(Current)
	L3PROP_FLOAT(Frequency)
	L3PROP_SHORT(Mode)
END_L3PROPTABLE(CCCM_Heat_ElecStirring)

BEGIN_L3METHODMAP(CCCM_Heat_ElecStirring,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CCCM_Heat_ElecStirring,CL3Object)
END_L3EVENTSINK_MAP(CCCM_Heat_ElecStirring)

CCCM_Heat_ElecStirring::CCCM_Heat_ElecStirring(void)
{
}

CCCM_Heat_ElecStirring::~CCCM_Heat_ElecStirring(void)
{
}
