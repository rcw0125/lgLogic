// �߼���CEnergyRunTimeDataԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CEnergyRunTimeData.h"

IMPLEMENT_L3CLASS(CEnergyRunTimeData,CL3Object,1)

BEGIN_L3PROPTABLE(CEnergyRunTimeData,CL3Object)
	L3PROP_STRING(TagName)
	L3PROP_STRING(TagCode)
	L3PROP_STRING(TagDesc)
	L3PROP_DOUBLE(Pressure)
	L3PROP_DOUBLE(Flow)
	L3PROP_DOUBLE(P_Max)
	L3PROP_DOUBLE(P_Min)
	L3PROP_DOUBLE(P_High)
	L3PROP_DOUBLE(P_Low)
	L3PROP_DOUBLE(F_Max)
	L3PROP_DOUBLE(F_Min)
	L3PROP_DOUBLE(F_High)
	L3PROP_DOUBLE(F_Low)
	L3PROP_DATETIME(Catch_Time)
	L3PROP_DOUBLE(Multiple)
	L3PROP_DOUBLE(MeasuringRange)
END_L3PROPTABLE(CEnergyRunTimeData)

BEGIN_L3METHODMAP(CEnergyRunTimeData,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CEnergyRunTimeData,CL3Object)
END_L3EVENTSINK_MAP(CEnergyRunTimeData)

CEnergyRunTimeData::CEnergyRunTimeData(void)
{
}

CEnergyRunTimeData::~CEnergyRunTimeData(void)
{
}
