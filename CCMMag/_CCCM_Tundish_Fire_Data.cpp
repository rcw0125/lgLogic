// �߼���CCCM_Tundish_Fire_DataԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CCCM_Tundish_Fire_Data.h"

IMPLEMENT_L3CLASS(CCCM_Tundish_Fire_Data,CL3Object,1)

BEGIN_L3PROPTABLE(CCCM_Tundish_Fire_Data,CL3Object)
	L3PROP_STRING(WorkID)
	L3PROP_STRING(Cast_ID)
	L3PROP_STRING(TundishID)
	L3PROP_FLOAT(Flow_Gas)
	L3PROP_STRING(Position)
	L3PROP_STRING(Fire_Type)
	L3PROP_DATETIME(MeasureTime)
END_L3PROPTABLE(CCCM_Tundish_Fire_Data)

BEGIN_L3METHODMAP(CCCM_Tundish_Fire_Data,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CCCM_Tundish_Fire_Data,CL3Object)
END_L3EVENTSINK_MAP(CCCM_Tundish_Fire_Data)

CCCM_Tundish_Fire_Data::CCCM_Tundish_Fire_Data(void)
{
}

CCCM_Tundish_Fire_Data::~CCCM_Tundish_Fire_Data(void)
{
}
