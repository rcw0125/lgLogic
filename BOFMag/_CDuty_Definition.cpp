// �߼���CDutyDefinitionԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CDuty_Definition.h"

IMPLEMENT_L3CLASS(CDuty_Definition,CL3Object,1)

BEGIN_L3PROPTABLE(CDuty_Definition,CL3Object)
    L3PROP_STRING(ObjectID)
	L3PROP_STRING(UnitID)
	L3PROP_STRING(Team)
	L3PROP_STRING(HeadFurnace)
	L3PROP_STRING(Assistant)
	L3PROP_STRING(SecondHand)
END_L3PROPTABLE(CDuty_Definition)

BEGIN_L3METHODMAP(CDuty_Definition,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CDuty_Definition,CL3Object)
END_L3EVENTSINK_MAP(CDuty_Definition)

CDuty_Definition::CDuty_Definition(void)
{
}

CDuty_Definition::~CDuty_Definition(void)
{
}
