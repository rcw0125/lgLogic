// �߼���CCCM_Heat_CoverԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CCCM_Heat_Cover.h"

IMPLEMENT_L3CLASS(CCCM_Heat_Cover,CL3Object,1)

BEGIN_L3PROPTABLE(CCCM_Heat_Cover,CL3Object)
	///2009-02-13 ������κš�ʹ�����
	L3PROP_STRING(HeatID)
	L3PROP_STRING(CCMID)
	L3PROP_STRING(Element)
	L3PROP_FLOAT(Amount)
	L3PROP_STRING(Origin)
	L3PROP_STRING(Batch_ID)
	L3PROP_STRING(UseInformation)
END_L3PROPTABLE(CCCM_Heat_Cover)

BEGIN_L3METHODMAP(CCCM_Heat_Cover,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CCCM_Heat_Cover,CL3Object)
END_L3EVENTSINK_MAP(CCCM_Heat_Cover)

CCCM_Heat_Cover::CCCM_Heat_Cover(void)
{
}

CCCM_Heat_Cover::~CCCM_Heat_Cover(void)
{
}
