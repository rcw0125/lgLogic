// �߼���CMIF_WeightԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CMIF_Weight.h"

IMPLEMENT_L3CLASS(CMIF_Weight,CL3Object,1)

BEGIN_L3PROPTABLE(CMIF_Weight,CL3Object)
	L3PROP_DOUBLE(Weight)
	L3PROP_DATETIME(Weight_Time)
	L3PROP_STRING(Source)
	L3PROP_STRING(Shift)
	L3PROP_STRING(Team)
END_L3PROPTABLE(CMIF_Weight)

BEGIN_L3METHODMAP(CMIF_Weight,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CMIF_Weight,CL3Object)
END_L3EVENTSINK_MAP(CMIF_Weight)

CMIF_Weight::CMIF_Weight(void)
{
}

CMIF_Weight::~CMIF_Weight(void)
{
}
