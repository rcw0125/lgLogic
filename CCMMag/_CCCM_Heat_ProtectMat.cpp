// �߼���CCCM_Heat_ProtectMatԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CCCM_Heat_ProtectMat.h"

IMPLEMENT_L3CLASS(CCCM_Heat_ProtectMat,CL3Object,1)

BEGIN_L3PROPTABLE(CCCM_Heat_ProtectMat,CL3Object)
	L3PROP_STRING(HeatID)
	L3PROP_STRING(CCMID)
	L3PROP_STRING(Element)
	L3PROP_STRING(Factory)
END_L3PROPTABLE(CCCM_Heat_ProtectMat)

BEGIN_L3METHODMAP(CCCM_Heat_ProtectMat,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CCCM_Heat_ProtectMat,CL3Object)
END_L3EVENTSINK_MAP(CCCM_Heat_ProtectMat)

CCCM_Heat_ProtectMat::CCCM_Heat_ProtectMat(void)
{
}

CCCM_Heat_ProtectMat::~CCCM_Heat_ProtectMat(void)
{
}
