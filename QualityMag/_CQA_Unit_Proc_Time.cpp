// �߼���CQA_Unit_Proc_TimeԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CQA_Unit_Proc_Time.h"

IMPLEMENT_L3CLASS(CQA_Unit_Proc_Time,CL3Object,1)

BEGIN_L3PROPTABLE(CQA_Unit_Proc_Time,CL3Object)
	L3PROP_STRING(SteelGradeIndex)
	L3PROP_LONG(BOF_Proc_Time)
	L3PROP_LONG(LF_Proc_Time)
	L3PROP_LONG(RH_Proc_Time)
	L3PROP_LONG(Caster_Proc_Time)
	L3PROP_LONG(Tapped_Proc_Time)
END_L3PROPTABLE(CQA_Unit_Proc_Time)

BEGIN_L3METHODMAP(CQA_Unit_Proc_Time,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CQA_Unit_Proc_Time,CL3Object)
END_L3EVENTSINK_MAP(CQA_Unit_Proc_Time)

CQA_Unit_Proc_Time::CQA_Unit_Proc_Time(void)
{
}

CQA_Unit_Proc_Time::~CQA_Unit_Proc_Time(void)
{
}
