// �߼���CPlan_Cur_PreHeatIDԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CPlan_Cur_PreHeatID.h"

IMPLEMENT_L3CLASS(CPlan_Cur_PreHeatID,CL3Object,1)

BEGIN_L3PROPTABLE(CPlan_Cur_PreHeatID,CL3Object)
	L3PROP_STRING(CasterID)
	L3PROP_LONG(Cur_PreHeatID)
	L3PROP_STRING(Year)
END_L3PROPTABLE(CPlan_Cur_PreHeatID)

BEGIN_L3METHODMAP(CPlan_Cur_PreHeatID,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CPlan_Cur_PreHeatID,CL3Object)
END_L3EVENTSINK_MAP(CPlan_Cur_PreHeatID)

CPlan_Cur_PreHeatID::CPlan_Cur_PreHeatID(void)
{
}

CPlan_Cur_PreHeatID::~CPlan_Cur_PreHeatID(void)
{
}
