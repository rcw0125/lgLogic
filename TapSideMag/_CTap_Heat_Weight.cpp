// �߼���CTap_Heat_WeightԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CTap_Heat_Weight.h"

IMPLEMENT_L3CLASS(CTap_Heat_Weight,CL3Object,1)

BEGIN_L3PROPTABLE(CTap_Heat_Weight,CL3Object)
	L3PROP_STRING(HeatID)
	L3PROP_SHORT(Status)
	L3PROP_DOUBLE(Weight)
	L3PROP_STRING(LadleNo)
END_L3PROPTABLE(CTap_Heat_Weight)

BEGIN_L3METHODMAP(CTap_Heat_Weight,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CTap_Heat_Weight,CL3Object)
END_L3EVENTSINK_MAP(CTap_Heat_Weight)

CTap_Heat_Weight::CTap_Heat_Weight(void)
{
}

CTap_Heat_Weight::~CTap_Heat_Weight(void)
{
}
