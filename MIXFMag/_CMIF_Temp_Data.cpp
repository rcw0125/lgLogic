// �߼���CMIF_Temp_DataԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CMIF_Temp_Data.h"

IMPLEMENT_L3CLASS(CMIF_Temp_Data,CL3Object,1)

BEGIN_L3PROPTABLE(CMIF_Temp_Data,CL3Object)
	L3PROP_STRING(MIFID)
	L3PROP_LONG(Temp)
	L3PROP_DATETIME(Temp_Time)
	L3PROP_STRING(Shift)
	L3PROP_STRING(Team)
END_L3PROPTABLE(CMIF_Temp_Data)

BEGIN_L3METHODMAP(CMIF_Temp_Data,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CMIF_Temp_Data,CL3Object)
END_L3EVENTSINK_MAP(CMIF_Temp_Data)

CMIF_Temp_Data::CMIF_Temp_Data(void)
{
}

CMIF_Temp_Data::~CMIF_Temp_Data(void)
{
}
