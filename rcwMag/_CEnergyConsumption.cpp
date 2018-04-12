// �߼���CEnergyConsumptionԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CEnergyConsumption.h"

IMPLEMENT_L3CLASS(CEnergyConsumption,CL3Object,1)

BEGIN_L3PROPTABLE(CEnergyConsumption,CL3Object)
	L3PROP_STRING(ObjectID)
	L3PROP_STRING(ProductionDate)
	L3PROP_STRING(TagName)
	L3PROP_DOUBLE(TagValue)
	L3PROP_DOUBLE(DayValue)
	L3PROP_DOUBLE(MonthValue)
	L3PROP_DATETIME(CreateTime)
	L3PROP_DATETIME(ModifyTime)
	L3PROP_STRING(Operator)
END_L3PROPTABLE(CEnergyConsumption)

BEGIN_L3METHODMAP(CEnergyConsumption,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CEnergyConsumption,CL3Object)
END_L3EVENTSINK_MAP(CEnergyConsumption)

CEnergyConsumption::CEnergyConsumption(void)
{
}

CEnergyConsumption::~CEnergyConsumption(void)
{
}
