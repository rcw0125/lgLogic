// �߼���CCCM_StrandInfoԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CCCM_StrandInfo.h"

IMPLEMENT_L3CLASS(CCCM_StrandInfo,CL3Object,1)

BEGIN_L3PROPTABLE(CCCM_StrandInfo,CL3Object)
	L3PROP_STRING(CCMID)
	L3PROP_LONG(StrandNo)
	L3PROP_LONG(OnOff)
	L3PROP_DATETIME(ChangeTime)
	L3PROP_STRING(CastingNo)
	L3PROP_STRING(TundishNo)
	L3PROP_STRING(HeatID)
END_L3PROPTABLE(CCCM_StrandInfo)

BEGIN_L3METHODMAP(CCCM_StrandInfo,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CCCM_StrandInfo,CL3Object)
END_L3EVENTSINK_MAP(CCCM_StrandInfo)

CCCM_StrandInfo::CCCM_StrandInfo(void)
{
}

CCCM_StrandInfo::~CCCM_StrandInfo(void)
{
}
