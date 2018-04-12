// �߼���CRHL_Temp_DataԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CRHL_Temp_Data.h"

IMPLEMENT_L3CLASS(CRHL_Temp_Data,CL3Object,1)

BEGIN_L3PROPTABLE(CRHL_Temp_Data,CL3Object)
	L3PROP_STRING(TreatNo)
	L3PROP_STRING(HeatID)
	L3PROP_LONG(Temperature)
	L3PROP_DATETIME(MeasureTime)
	L3PROP_SHORT(Mode)
END_L3PROPTABLE(CRHL_Temp_Data)

BEGIN_L3METHODMAP(CRHL_Temp_Data,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CRHL_Temp_Data,CL3Object)
END_L3EVENTSINK_MAP(CRHL_Temp_Data)

CRHL_Temp_Data::CRHL_Temp_Data(void)
{
}

CRHL_Temp_Data::~CRHL_Temp_Data(void)
{
}