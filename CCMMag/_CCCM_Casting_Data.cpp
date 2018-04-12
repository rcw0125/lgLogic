// �߼���CCCM_Casting_DataԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CCCM_Casting_Data.h"

IMPLEMENT_L3CLASS(CCCM_Casting_Data,CL3Object,1)

BEGIN_L3PROPTABLE(CCCM_Casting_Data,CL3Object)
	L3PROP_STRING(CastingNo)
	L3PROP_STRING(CCMID)
	L3PROP_DATETIME(Casting_Start_Time)
	L3PROP_DATETIME(Casting_Stop_Time)
	L3PROP_STRING(Shift)
	L3PROP_STRING(Team)
	L3PROP_STRING(First_HeatID)
	L3PROP_STRING(Last_HeatID)
	L3PROP_LONG(HeatCount)
END_L3PROPTABLE(CCCM_Casting_Data)

BEGIN_L3METHODMAP(CCCM_Casting_Data,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CCCM_Casting_Data,CL3Object)
END_L3EVENTSINK_MAP(CCCM_Casting_Data)

CCCM_Casting_Data::CCCM_Casting_Data(void)
{
}

CCCM_Casting_Data::~CCCM_Casting_Data(void)
{
}
