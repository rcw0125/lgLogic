// �߼���CCost_Standard_RateԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CCost_Standard_Rate.h"

IMPLEMENT_L3CLASS(CCost_Standard_Rate,CL3Object,1)

BEGIN_L3PROPTABLE(CCost_Standard_Rate,CL3Object)
	L3PROP_STRING(Cost_Item)
	L3PROP_STRING(Cost_Center)
	L3PROP_STRING(Pro_type)
	L3PROP_FLOAT(Standard_Cost)
END_L3PROPTABLE(CCost_Standard_Rate)

BEGIN_L3METHODMAP(CCost_Standard_Rate,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CCost_Standard_Rate,CL3Object)
END_L3EVENTSINK_MAP(CCost_Standard_Rate)

CCost_Standard_Rate::CCost_Standard_Rate(void)
{
}

CCost_Standard_Rate::~CCost_Standard_Rate(void)
{
}
