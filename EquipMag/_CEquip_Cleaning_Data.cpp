// �߼���CEquip_Cleaning_DataԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CEquip_Cleaning_Data.h"

IMPLEMENT_L3CLASS(CEquip_Cleaning_Data,CL3Object,1)

BEGIN_L3PROPTABLE(CEquip_Cleaning_Data,CL3Object)
	L3PROP_STRING(TagName)
	L3PROP_LONG(TagType)
	L3PROP_LONG(TagValue)
	L3PROP_DATETIME(Catch_Time)
END_L3PROPTABLE(CEquip_Cleaning_Data)

BEGIN_L3METHODMAP(CEquip_Cleaning_Data,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CEquip_Cleaning_Data,CL3Object)
END_L3EVENTSINK_MAP(CEquip_Cleaning_Data)

CEquip_Cleaning_Data::CEquip_Cleaning_Data(void)
{
}

CEquip_Cleaning_Data::~CEquip_Cleaning_Data(void)
{
}
