// �߼���CCCM_DutyԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CCCM_Duty.h"

IMPLEMENT_L3CLASS(CCCM_Duty,CL3Object,1)

BEGIN_L3PROPTABLE(CCCM_Duty,CL3Object)

	L3PROP_STRING(CCMID)
	L3PROP_STRING(TeamID)
	L3PROP_STRING(Station)
	L3PROP_STRING(Operator_name)

END_L3PROPTABLE(CCCM_Duty)

BEGIN_L3METHODMAP(CCCM_Duty,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CCCM_Duty,CL3Object)
END_L3EVENTSINK_MAP(CCCM_Duty)

CCCM_Duty::CCCM_Duty(void)
{
}

CCCM_Duty::~CCCM_Duty(void)
{
}
