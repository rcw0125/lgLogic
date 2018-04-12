// �߼���CLF_Oxygen_DataԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CLF_Oxygen_Data.h"

IMPLEMENT_L3CLASS(CLF_Oxygen_Data,CL3Object,1)

BEGIN_L3PROPTABLE(CLF_Oxygen_Data,CL3Object)
	L3PROP_STRING(TreatNo)
	L3PROP_STRING(HeatID)
	L3PROP_FLOAT(Oxygen_Content)
	L3PROP_DATETIME(Measure_Time)
	L3PROP_LONG(Temp)
END_L3PROPTABLE(CLF_Oxygen_Data)

BEGIN_L3METHODMAP(CLF_Oxygen_Data,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CLF_Oxygen_Data,CL3Object)
END_L3EVENTSINK_MAP(CLF_Oxygen_Data)

CLF_Oxygen_Data::CLF_Oxygen_Data(void)
{
}

CLF_Oxygen_Data::~CLF_Oxygen_Data(void)
{
}
