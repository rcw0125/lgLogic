// �߼���CQA_Caster_Std_FluxԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CQA_Caster_Std_Flux.h"

IMPLEMENT_L3CLASS(CQA_Caster_Std_Flux,CL3Object,1)

BEGIN_L3PROPTABLE(CQA_Caster_Std_Flux,CL3Object)
	L3PROP_STRING(SteelGradeIndex)
	L3PROP_STRING(Tundish_Flux_Name)
	L3PROP_DOUBLE(Tundish_Flux_Weight)
END_L3PROPTABLE(CQA_Caster_Std_Flux)

BEGIN_L3METHODMAP(CQA_Caster_Std_Flux,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CQA_Caster_Std_Flux,CL3Object)
END_L3EVENTSINK_MAP(CQA_Caster_Std_Flux)

CQA_Caster_Std_Flux::CQA_Caster_Std_Flux(void)
{
}

CQA_Caster_Std_Flux::~CQA_Caster_Std_Flux(void)
{
}
