// �߼���CEquip_Collet_LogԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CEquip_Collet_Log.h"

IMPLEMENT_L3CLASS(CEquip_Collet_Log,CL3Object,1)

BEGIN_L3PROPTABLE(CEquip_Collet_Log,CL3Object)
	L3PROP_STRING(LFID)
	L3PROP_STRING(PhaseNo)
	L3PROP_STRING(Collet_Std)
	L3PROP_STRING(Collet_Act)
	L3PROP_DATETIME(Check_Date)
	L3PROP_DATETIME(Create_Time)
	L3PROP_STRING(Operator)
	L3PROP_LONG(Status)
END_L3PROPTABLE(CEquip_Collet_Log)

BEGIN_L3METHODMAP(CEquip_Collet_Log,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CEquip_Collet_Log,CL3Object)
END_L3EVENTSINK_MAP(CEquip_Collet_Log)

CEquip_Collet_Log::CEquip_Collet_Log(void)
{
}

CEquip_Collet_Log::~CEquip_Collet_Log(void)
{
}
