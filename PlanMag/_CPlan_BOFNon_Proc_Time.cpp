// �߼���CPlan_BOFNon_Proc_TimeԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CPlan_BOFNon_Proc_Time.h"

IMPLEMENT_L3CLASS(CPlan_BOFNon_Proc_Time,CL3Object,1)

BEGIN_L3PROPTABLE(CPlan_BOFNon_Proc_Time,CL3Object)
	L3PROP_DOUBLE(Aim_Time_BOFRepared)
	L3PROP_DOUBLE(Aim_Time_BlowN2)
	L3PROP_STRING(HeatID)
END_L3PROPTABLE(CPlan_BOFNon_Proc_Time)

BEGIN_L3METHODMAP(CPlan_BOFNon_Proc_Time,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CPlan_BOFNon_Proc_Time,CL3Object)
END_L3EVENTSINK_MAP(CPlan_BOFNon_Proc_Time)

CPlan_BOFNon_Proc_Time::CPlan_BOFNon_Proc_Time(void)
{
}

CPlan_BOFNon_Proc_Time::~CPlan_BOFNon_Proc_Time(void)
{
}
