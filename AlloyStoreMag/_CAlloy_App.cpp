// �߼���CAlloy_AppԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CAlloy_App.h"

IMPLEMENT_L3CLASS(CAlloy_App,CL3Object,1)

BEGIN_L3PROPTABLE(CAlloy_App,CL3Object)
	L3PROP_STRING(Alloy_Code)
	L3PROP_DOUBLE(Amount)
	L3PROP_DATETIME(App_Time)
	L3PROP_STRING(App_UnitID)
	L3PROP_STRING(App_Operator)
	L3PROP_LONG(Confirm_Flag)
	L3PROP_STRING(Confirm_Operator)
	L3PROP_DATETIME(Confirm_Time)
END_L3PROPTABLE(CAlloy_App)

BEGIN_L3METHODMAP(CAlloy_App,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CAlloy_App,CL3Object)
END_L3EVENTSINK_MAP(CAlloy_App)

CAlloy_App::CAlloy_App(void)
{
}

CAlloy_App::~CAlloy_App(void)
{
}
