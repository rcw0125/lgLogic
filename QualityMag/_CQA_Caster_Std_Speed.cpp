// �߼���CQA_Caster_Std_SpeedԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CQA_Caster_Std_Speed.h"

IMPLEMENT_L3CLASS(CQA_Caster_Std_Speed,CL3Object,1)

BEGIN_L3PROPTABLE(CQA_Caster_Std_Speed,CL3Object)
	L3PROP_STRING(SteelGradeIndex)
	L3PROP_DOUBLE(Speed_Fir_Min)
	L3PROP_DOUBLE(Speed_Fir_Max)
	L3PROP_DOUBLE(Speed_Min)
	L3PROP_DOUBLE(Speed_Max)
END_L3PROPTABLE(CQA_Caster_Std_Speed)

BEGIN_L3METHODMAP(CQA_Caster_Std_Speed,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CQA_Caster_Std_Speed,CL3Object)
END_L3EVENTSINK_MAP(CQA_Caster_Std_Speed)

CQA_Caster_Std_Speed::CQA_Caster_Std_Speed(void)
{
}

CQA_Caster_Std_Speed::~CQA_Caster_Std_Speed(void)
{
}
