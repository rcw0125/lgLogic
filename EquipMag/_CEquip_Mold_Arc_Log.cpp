// �߼���CEquip_Mold_Arc_LogԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CEquip_Mold_Arc_Log.h"

IMPLEMENT_L3CLASS(CEquip_Mold_Arc_Log,CL3Object,1)

BEGIN_L3PROPTABLE(CEquip_Mold_Arc_Log,CL3Object)
	L3PROP_STRING(CCMID)
	L3PROP_STRING(StrandNo)
	L3PROP_STRING(MoldNo)
	L3PROP_STRING(Arc_Out_Std)
	L3PROP_STRING(Arc_Out_Act)
	L3PROP_STRING(Arc_South_Std)
	L3PROP_STRING(Arc_South_Act)
	L3PROP_DATETIME(Check_Date)
	L3PROP_DATETIME(Create_Time)
	L3PROP_STRING(Operator)
	L3PROP_LONG(Status)
END_L3PROPTABLE(CEquip_Mold_Arc_Log)

BEGIN_L3METHODMAP(CEquip_Mold_Arc_Log,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CEquip_Mold_Arc_Log,CL3Object)
END_L3EVENTSINK_MAP(CEquip_Mold_Arc_Log)

CEquip_Mold_Arc_Log::CEquip_Mold_Arc_Log(void)
{
}

CEquip_Mold_Arc_Log::~CEquip_Mold_Arc_Log(void)
{
}
