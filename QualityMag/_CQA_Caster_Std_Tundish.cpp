// �߼���CQA_Caster_Std_TundishԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CQA_Caster_Std_Tundish.h"

IMPLEMENT_L3CLASS(CQA_Caster_Std_Tundish,CL3Object,1)

BEGIN_L3PROPTABLE(CQA_Caster_Std_Tundish,CL3Object)
	L3PROP_STRING(SteelGradeIndex)
	L3PROP_LONG(Tundish_Temp_Fir_Min)
	L3PROP_LONG(Tundish_Temp_Fir_Max)
	L3PROP_LONG(Tundish_Temp_Min)
	L3PROP_LONG(Tundish_Temp_Max)
END_L3PROPTABLE(CQA_Caster_Std_Tundish)

BEGIN_L3METHODMAP(CQA_Caster_Std_Tundish,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CQA_Caster_Std_Tundish,CL3Object)
END_L3EVENTSINK_MAP(CQA_Caster_Std_Tundish)

CQA_Caster_Std_Tundish::CQA_Caster_Std_Tundish(void)
{
}

CQA_Caster_Std_Tundish::~CQA_Caster_Std_Tundish(void)
{
}