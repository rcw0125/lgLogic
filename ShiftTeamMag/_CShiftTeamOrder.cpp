// �߼���ShiftTeamOrderԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CShiftTeamOrder.h"

IMPLEMENT_L3CLASS(CShiftTeamOrder,CL3Object,1)

BEGIN_L3PROPTABLE(CShiftTeamOrder,CL3Object)
	L3PROP_SHORT(L3Index)
	L3PROP_STRING(ShiftType)
	L3PROP_SHORT(OrderIndex)
	L3PROP_SHORT(ShiftID)
	L3PROP_SHORT(TeamID)
END_L3PROPTABLE(CShiftTeamOrder)

BEGIN_L3METHODMAP(CShiftTeamOrder,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CShiftTeamOrder,CL3Object)
END_L3EVENTSINK_MAP(CShiftTeamOrder)

CShiftTeamOrder::CShiftTeamOrder(void)
{
}

CShiftTeamOrder::~CShiftTeamOrder(void)
{
}
