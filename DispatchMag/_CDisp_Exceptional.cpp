// �߼���CDisp_ExceptionalԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CDisp_Exceptional.h"

IMPLEMENT_L3CLASS(CDisp_Exceptional,CL3Object,1)

BEGIN_L3PROPTABLE(CDisp_Exceptional,CL3Object)
	L3PROP_STRING(IDObject)
	L3PROP_STRING(CreateDate)
	L3PROP_STRING(UnitID)
	L3PROP_STRING(Shift)
	L3PROP_STRING(Team)
	L3PROP_STRING(CreateTime)
	L3PROP_STRING(Operator)
	L3PROP_LONG(SendFlag)
END_L3PROPTABLE(CDisp_Exceptional)

BEGIN_L3METHODMAP(CDisp_Exceptional,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CDisp_Exceptional,CL3Object)
END_L3EVENTSINK_MAP(CDisp_Exceptional)

CDisp_Exceptional::CDisp_Exceptional(void)
{
}

CDisp_Exceptional::~CDisp_Exceptional(void)
{
}
