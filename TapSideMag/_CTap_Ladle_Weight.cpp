// �߼���CTap_Ladle_WeightԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CTap_Ladle_Weight.h"

IMPLEMENT_L3CLASS(CTap_Ladle_Weight,CL3Object,1)

BEGIN_L3PROPTABLE(CTap_Ladle_Weight,CL3Object)
	L3PROP_SHORT(TAPID)
	L3PROP_DOUBLE(Weight)
	L3PROP_SHORT(Status)
	L3PROP_STRING(LadleNo)
	L3PROP_STRING(HeatID)
	L3PROP_DATETIME(Log_Time)
END_L3PROPTABLE(CTap_Ladle_Weight)

BEGIN_L3METHODMAP(CTap_Ladle_Weight,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CTap_Ladle_Weight,CL3Object)
END_L3EVENTSINK_MAP(CTap_Ladle_Weight)

CTap_Ladle_Weight::CTap_Ladle_Weight(void)
{
}

CTap_Ladle_Weight::~CTap_Ladle_Weight(void)
{
}
