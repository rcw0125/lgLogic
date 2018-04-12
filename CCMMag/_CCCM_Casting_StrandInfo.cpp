// �߼���CCCM_Casting_StrandInfoԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CCCM_Casting_StrandInfo.h"

IMPLEMENT_L3CLASS(CCCM_Casting_StrandInfo,CL3Object,1)

BEGIN_L3PROPTABLE(CCCM_Casting_StrandInfo,CL3Object)
	L3PROP_STRING(CastingNo)
	L3PROP_STRING(CCMID)
	L3PROP_SHORT(StrandNo)
	L3PROP_DATETIME(LEAD_TIME)
	L3PROP_STRING(Mold)
	L3PROP_STRING(Cu_Factory)
	L3PROP_DOUBLE(Pass_Steel_Weight)
END_L3PROPTABLE(CCCM_Casting_StrandInfo)

BEGIN_L3METHODMAP(CCCM_Casting_StrandInfo,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CCCM_Casting_StrandInfo,CL3Object)
END_L3EVENTSINK_MAP(CCCM_Casting_StrandInfo)

CCCM_Casting_StrandInfo::CCCM_Casting_StrandInfo(void)
{
}

CCCM_Casting_StrandInfo::~CCCM_Casting_StrandInfo(void)
{
}
