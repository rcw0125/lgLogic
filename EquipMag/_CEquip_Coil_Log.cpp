// �߼���CEquip_Coil_LogԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CEquip_Coil_Log.h"

IMPLEMENT_L3CLASS(CEquip_Coil_Log,CL3Object,1)

BEGIN_L3PROPTABLE(CEquip_Coil_Log,CL3Object)
	L3PROP_STRING(CCMID)
	L3PROP_STRING(StrandNo)
	L3PROP_STRING(CoilNo)
	L3PROP_STRING(Insulating)
	L3PROP_STRING(Elec_Intensity_Std)
	L3PROP_STRING(Elec_Intensity_Act)
	L3PROP_DATETIME(Check_Date)
	L3PROP_DATETIME(Create_Time)
	L3PROP_STRING(Operator)
	L3PROP_LONG(Status)
END_L3PROPTABLE(CEquip_Coil_Log)

BEGIN_L3METHODMAP(CEquip_Coil_Log,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CEquip_Coil_Log,CL3Object)
END_L3EVENTSINK_MAP(CEquip_Coil_Log)

CEquip_Coil_Log::CEquip_Coil_Log(void)
{
}

CEquip_Coil_Log::~CEquip_Coil_Log(void)
{
}
