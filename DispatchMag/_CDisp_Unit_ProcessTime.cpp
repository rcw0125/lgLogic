// �߼���CDisp_Unit_ProcessTimeԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CDisp_Unit_ProcessTime.h"

IMPLEMENT_L3CLASS(CDisp_Unit_ProcessTime,CL3Object,1)

BEGIN_L3PROPTABLE(CDisp_Unit_ProcessTime,CL3Object)
	L3PROP_STRING(ObjectID)
	L3PROP_STRING(ProductDate)
	L3PROP_STRING(UnitID)
	L3PROP_STRING(Team)
	L3PROP_STRING(ProcessType)
	L3PROP_LONG(ProcessTime)
	L3PROP_DATETIME(CreateTime)
END_L3PROPTABLE(CDisp_Unit_ProcessTime)

BEGIN_L3METHODMAP(CDisp_Unit_ProcessTime,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CDisp_Unit_ProcessTime,CL3Object)
END_L3EVENTSINK_MAP(CDisp_Unit_ProcessTime)

CDisp_Unit_ProcessTime::CDisp_Unit_ProcessTime(void)
{
}

CDisp_Unit_ProcessTime::~CDisp_Unit_ProcessTime(void)
{
}
