// �߼���CEupip_Adjust_StdԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CEupip_Adjust_Std.h"

IMPLEMENT_L3CLASS(CEupip_Adjust_Std,CL3Object,1)

BEGIN_L3PROPTABLE(CEupip_Adjust_Std,CL3Object)
	L3PROP_STRING(AdjustType)
	L3PROP_STRING(UnitID)
	L3PROP_STRING(AdjustObject)
	L3PROP_STRING(Items)
	L3PROP_STRING(Standard)
	L3PROP_LONG(ValidFlag)
END_L3PROPTABLE(CEupip_Adjust_Std)

BEGIN_L3METHODMAP(CEupip_Adjust_Std,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CEupip_Adjust_Std,CL3Object)
END_L3EVENTSINK_MAP(CEupip_Adjust_Std)

CEupip_Adjust_Std::CEupip_Adjust_Std(void)
{
}

CEupip_Adjust_Std::~CEupip_Adjust_Std(void)
{
}
