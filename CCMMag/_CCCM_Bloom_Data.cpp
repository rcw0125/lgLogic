// �߼���CCCM_Bloom_DataԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CCCM_Bloom_Data.h"

IMPLEMENT_L3CLASS(CCCM_Bloom_Data,CL3Object,1)

BEGIN_L3PROPTABLE(CCCM_Bloom_Data,CL3Object)
	L3PROP_STRING(Caster_ID)
	L3PROP_STRING(Casting_No)
	L3PROP_LONG(Casting_Heat_Cnt)
	L3PROP_STRING(SteelGradeIndex)
	L3PROP_STRING(SteelGrade)
	L3PROP_LONG(Width)
	L3PROP_LONG(Length)
	L3PROP_DOUBLE(Cal_Weight)
	L3PROP_DOUBLE(Weight)
	L3PROP_DATETIME(Cut_Time)
	L3PROP_LONG(Thickness)
END_L3PROPTABLE(CCCM_Bloom_Data)

BEGIN_L3METHODMAP(CCCM_Bloom_Data,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CCCM_Bloom_Data,CL3Object)
END_L3EVENTSINK_MAP(CCCM_Bloom_Data)

CCCM_Bloom_Data::CCCM_Bloom_Data(void)
{
}

CCCM_Bloom_Data::~CCCM_Bloom_Data(void)
{
}
