// �߼���CCCM_Heat_ProtectSlagԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CCCM_Heat_ProtectSlag.h"

IMPLEMENT_L3CLASS(CCCM_Heat_ProtectSlag,CL3Object,1)

BEGIN_L3PROPTABLE(CCCM_Heat_ProtectSlag,CL3Object)
    ///2009-02-13 ʹ�������������
	L3PROP_STRING(HeatID)
	L3PROP_STRING(CCMID)
	L3PROP_SHORT(StrandID)
	L3PROP_STRING(Element)
	L3PROP_STRING(Factory)
	L3PROP_STRING(BatchNo)
	L3PROP_STRING(UseInformation)
	L3PROP_DOUBLE(Amount)
END_L3PROPTABLE(CCCM_Heat_ProtectSlag)

BEGIN_L3METHODMAP(CCCM_Heat_ProtectSlag,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CCCM_Heat_ProtectSlag,CL3Object)
END_L3EVENTSINK_MAP(CCCM_Heat_ProtectSlag)

CCCM_Heat_ProtectSlag::CCCM_Heat_ProtectSlag(void)
{
}

CCCM_Heat_ProtectSlag::~CCCM_Heat_ProtectSlag(void)
{
}
