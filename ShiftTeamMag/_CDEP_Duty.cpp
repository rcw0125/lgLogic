// �߼���CDutyDefinitionԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CDEP_Duty.h"

IMPLEMENT_L3CLASS(CDEP_Duty,CL3Object,1)

BEGIN_L3PROPTABLE(CDEP_Duty,CL3Object)
    L3PROP_STRING(ObjectID)
	L3PROP_STRING(UnitID)
	L3PROP_STRING(Team)
	L3PROP_STRING(HeadFurnace)
	L3PROP_STRING(Assistant)
	L3PROP_STRING(SecondHand)
END_L3PROPTABLE(CDEP_Duty)

BEGIN_L3METHODMAP(CDEP_Duty,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CDEP_Duty,CL3Object)
END_L3EVENTSINK_MAP(CDEP_Duty)

CDEP_Duty::CDEP_Duty(void)
{
}

CDEP_Duty::~CDEP_Duty(void)
{
}
