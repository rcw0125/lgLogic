// �߼���CTundish_OT_InstallԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CTundish_OT_Install.h"

IMPLEMENT_L3CLASS(CTundish_OT_Install,CL3Object,1)

BEGIN_L3PROPTABLE(CTundish_OT_Install,CL3Object)
	
	L3PROP_STRING(TundishID)
	L3PROP_STRING(WorkID)
	L3PROP_STRING(Daub_Fac)
	L3PROP_STRING(Fra_Case)
	L3PROP_STRING(Slip_Blo_Fac)
	L3PROP_STRING(Gap_Fac)
	L3PROP_STRING(Install_Per)
	L3PROP_DATETIME(Install_Time)
	L3PROP_STRING(Note)
	L3PROP_LONG(Confirm_Flag)
	
END_L3PROPTABLE(CTundish_OT_Install)

BEGIN_L3METHODMAP(CTundish_OT_Install,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CTundish_OT_Install,CL3Object)
END_L3EVENTSINK_MAP(CTundish_OT_Install)

CTundish_OT_Install::CTundish_OT_Install(void)
{
}

CTundish_OT_Install::~CTundish_OT_Install(void)
{
}
