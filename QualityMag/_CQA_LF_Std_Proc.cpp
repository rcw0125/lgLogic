// �߼���CQA_LF_Std_ProcԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CQA_LF_Std_Proc.h"

IMPLEMENT_L3CLASS(CQA_LF_Std_Proc,CL3Object,1)

BEGIN_L3PROPTABLE(CQA_LF_Std_Proc,CL3Object)
	L3PROP_STRING(SteelGradeIndex)
	L3PROP_LONG(LeaFir_Temp_Aim)
	L3PROP_LONG(LeaFir_Temp_Min)
	L3PROP_LONG(LeaFir_Temp_Max)
	L3PROP_LONG(Lea_Temp_Aim)
	L3PROP_LONG(Lea_Temp_Min)
	L3PROP_LONG(Lea_Temp_Max)
	L3PROP_LONG(Sample_Flag)
	L3PROP_LONG(Soft_Blow_Time_Min)
	L3PROP_LONG(Hot_Time_Min)
	L3PROP_LONG(Hot_Time_Max)
	L3PROP_DOUBLE(Hot_Ar_Min)
	L3PROP_DOUBLE(Hot_Ar_Max)
	L3PROP_DOUBLE(Soft_Ar_Min)
	L3PROP_DOUBLE(Soft_Ar_Max)
	L3PROP_DOUBLE(Hold_Steel_Time_Max)
	L3PROP_DOUBLE(Stay_Steel_Time_Max)
	L3PROP_DOUBLE(Refine_Time_Max)
	L3PROP_DOUBLE(Refine_Time_Min)
END_L3PROPTABLE(CQA_LF_Std_Proc)

BEGIN_L3METHODMAP(CQA_LF_Std_Proc,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CQA_LF_Std_Proc,CL3Object)
END_L3EVENTSINK_MAP(CQA_LF_Std_Proc)

CQA_LF_Std_Proc::CQA_LF_Std_Proc(void)
{
}

CQA_LF_Std_Proc::~CQA_LF_Std_Proc(void)
{
}
