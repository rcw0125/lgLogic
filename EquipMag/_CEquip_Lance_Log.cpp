// �߼���CEquip_Lance_LogԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CEquip_Lance_Log.h"

IMPLEMENT_L3CLASS(CEquip_Lance_Log,CL3Object,1)

BEGIN_L3PROPTABLE(CEquip_Lance_Log,CL3Object)
	L3PROP_STRING(BOFID)
	L3PROP_STRING(Lance_Std)
	L3PROP_STRING(Lance_Act)
	L3PROP_DATETIME(Check_Date)
	L3PROP_DATETIME(Create_Time)
	L3PROP_STRING(Operator)
	L3PROP_LONG(Status)
END_L3PROPTABLE(CEquip_Lance_Log)

BEGIN_L3METHODMAP(CEquip_Lance_Log,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CEquip_Lance_Log,CL3Object)
END_L3EVENTSINK_MAP(CEquip_Lance_Log)

CEquip_Lance_Log::CEquip_Lance_Log(void)
{
}

CEquip_Lance_Log::~CEquip_Lance_Log(void)
{
}
