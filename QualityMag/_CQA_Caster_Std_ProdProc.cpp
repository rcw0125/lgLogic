// �߼���CQA_Caster_Std_ProdProcԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CQA_Caster_Std_ProdProc.h"

IMPLEMENT_L3CLASS(CQA_Caster_Std_ProdProc,CL3Object,1)

BEGIN_L3PROPTABLE(CQA_Caster_Std_ProdProc,CL3Object)
	L3PROP_STRING(SteelGradeIndex)
	L3PROP_STRING(CasterID)
	L3PROP_LONG(Spec_Seq)
	L3PROP_LONG(Width_Min)
	L3PROP_LONG(Width_Max)
	L3PROP_LONG(Thickness_Min)
	L3PROP_LONG(Thickness_Max)
	L3PROP_LONG(Length_Min)
	L3PROP_LONG(Length_Max)
END_L3PROPTABLE(CQA_Caster_Std_ProdProc)

BEGIN_L3METHODMAP(CQA_Caster_Std_ProdProc,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CQA_Caster_Std_ProdProc,CL3Object)
END_L3EVENTSINK_MAP(CQA_Caster_Std_ProdProc)

CQA_Caster_Std_ProdProc::CQA_Caster_Std_ProdProc(void)
{
}

CQA_Caster_Std_ProdProc::~CQA_Caster_Std_ProdProc(void)
{
}