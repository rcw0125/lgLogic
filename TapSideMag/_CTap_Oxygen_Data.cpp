// �߼���CTap_Oxygen_DataԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CTap_Oxygen_Data.h"

IMPLEMENT_L3CLASS(CTap_Oxygen_Data,CL3Object,1)

BEGIN_L3PROPTABLE(CTap_Oxygen_Data,CL3Object)
	L3PROP_STRING(HeatID)
	L3PROP_FLOAT(Oxygen_Content)
	L3PROP_DATETIME(MeasureTime)
	L3PROP_LONG(Temp)
END_L3PROPTABLE(CTap_Oxygen_Data)

BEGIN_L3METHODMAP(CTap_Oxygen_Data,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CTap_Oxygen_Data,CL3Object)
END_L3EVENTSINK_MAP(CTap_Oxygen_Data)

CTap_Oxygen_Data::CTap_Oxygen_Data(void)
{
}

CTap_Oxygen_Data::~CTap_Oxygen_Data(void)
{
}
