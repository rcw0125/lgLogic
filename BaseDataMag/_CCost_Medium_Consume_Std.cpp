// �߼���CCost_Medium_Consume_StandardԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CCost_Medium_Consume_Std.h"

IMPLEMENT_L3CLASS(CCost_Medium_Consume_Std,CL3Object,1)

BEGIN_L3PROPTABLE(CCost_Medium_Consume_Std,CL3Object)
	L3PROP_STRING(Medium)
	L3PROP_STRING(Cost_Center)
	L3PROP_STRING(Stock_Type)
	L3PROP_FLOAT(Standard_Cost)
END_L3PROPTABLE(CCost_Medium_Consume_Std)

BEGIN_L3METHODMAP(CCost_Medium_Consume_Std,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CCost_Medium_Consume_Std,CL3Object)
END_L3EVENTSINK_MAP(CCost_Medium_Consume_Std)

CCost_Medium_Consume_Std::CCost_Medium_Consume_Std(void)
{
}

CCost_Medium_Consume_Std::~CCost_Medium_Consume_Std(void)
{
}
