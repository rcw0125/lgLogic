// �߼���CBOF_Temp_DataԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CBOF_Temp_Data.h"

IMPLEMENT_L3CLASS(CBOF_Temp_Data,CL3Object,1)

BEGIN_L3PROPTABLE(CBOF_Temp_Data,CL3Object)
	L3PROP_STRING(HeatID)
	L3PROP_LONG(Temp)
	L3PROP_DATETIME(Temp_Time)
	L3PROP_SHORT(Mode)
END_L3PROPTABLE(CBOF_Temp_Data)

BEGIN_L3METHODMAP(CBOF_Temp_Data,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CBOF_Temp_Data,CL3Object)
END_L3EVENTSINK_MAP(CBOF_Temp_Data)

CBOF_Temp_Data::CBOF_Temp_Data(void)
{
}

CBOF_Temp_Data::~CBOF_Temp_Data(void)
{
}
