// �߼���CTap_Temp_DataԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CTap_Temp_Data.h"

IMPLEMENT_L3CLASS(CTap_Temp_Data,CL3Object,1)

BEGIN_L3PROPTABLE(CTap_Temp_Data,CL3Object)
	L3PROP_STRING(HeatID)
	L3PROP_LONG(Temperature)
	L3PROP_DATETIME(MeasureTime)
	L3PROP_SHORT(MeasureType)
END_L3PROPTABLE(CTap_Temp_Data)

BEGIN_L3METHODMAP(CTap_Temp_Data,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CTap_Temp_Data,CL3Object)
END_L3EVENTSINK_MAP(CTap_Temp_Data)

CTap_Temp_Data::CTap_Temp_Data(void)
{
}

CTap_Temp_Data::~CTap_Temp_Data(void)
{
}
