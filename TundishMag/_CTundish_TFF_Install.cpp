// �߼���CTundish_TFF_InstallԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CTundish_TFF_Install.h"

IMPLEMENT_L3CLASS(CTundish_TFF_Install,CL3Object,1)

BEGIN_L3PROPTABLE(CTundish_TFF_Install,CL3Object)
	L3PROP_STRING(TundishID)
	L3PROP_STRING(WorkID)
	L3PROP_STRING(Daub_Fac)
	L3PROP_STRING(Refra_Fac)
	L3PROP_STRING(Fra_Switch_Case)
	L3PROP_STRING(Con_Per)
	L3PROP_STRING(Gap_Fac)
	L3PROP_DATETIME(Gap_Pro_Date)
	L3PROP_STRING(First_Gap_ID)
	L3PROP_STRING(Second_Gap_ID)
	L3PROP_STRING(Third_Gap_ID)
	L3PROP_STRING(Fourth_Gap_ID)
	L3PROP_STRING(Stu_Sti_Fac)
	L3PROP_DATETIME(Stu_Sti_Pro_Date)
	L3PROP_STRING(First_Stu_Sti_ID)
	L3PROP_STRING(Second_Stu_Sti_ID)
	L3PROP_STRING(Third_Stu_Sti_ID)
	L3PROP_STRING(Fourth_Stu_Sti_ID)
	L3PROP_STRING(Install_Per)
	L3PROP_DATETIME(Install_Time)
	L3PROP_STRING(Note)
	L3PROP_LONG(Confirm_Flag)
	
END_L3PROPTABLE(CTundish_TFF_Install)

BEGIN_L3METHODMAP(CTundish_TFF_Install,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CTundish_TFF_Install,CL3Object)
END_L3EVENTSINK_MAP(CTundish_TFF_Install)

CTundish_TFF_Install::CTundish_TFF_Install(void)
{
}

CTundish_TFF_Install::~CTundish_TFF_Install(void)
{
}
