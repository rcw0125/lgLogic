// �߼���CQA_Element_StdԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CQA_Element_Std.h"

IMPLEMENT_L3CLASS(CQA_Element_Std,CL3Object,1)

BEGIN_L3PROPTABLE(CQA_Element_Std,CL3Object)
	L3PROP_STRING(SteelGrade)
	L3PROP_STRING(SteelGradeIndex)
	L3PROP_STRING(C_Max)
	L3PROP_STRING(C_Min)
	L3PROP_STRING(Si_Max)
	L3PROP_STRING(Si_Min)
	L3PROP_STRING(Mn_Max)
	L3PROP_STRING(Mn_Min)
	L3PROP_STRING(P_Max)
	L3PROP_STRING(P_Min)
	L3PROP_STRING(S_Max)
	L3PROP_STRING(S_Min)
	L3PROP_STRING(Ti_Max)
	L3PROP_STRING(Ti_Min)
	L3PROP_STRING(Sn_Max)
	L3PROP_STRING(Sn_Min)
	L3PROP_STRING(Sb_Max)
	L3PROP_STRING(Sb_Min)
	L3PROP_STRING(As_Max)
	L3PROP_STRING(As_Min)
	L3PROP_STRING(Pb_Max)
	L3PROP_STRING(Pb_Min)
END_L3PROPTABLE(CQA_Element_Std)

BEGIN_L3METHODMAP(CQA_Element_Std,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CQA_Element_Std,CL3Object)
END_L3EVENTSINK_MAP(CQA_Element_Std)

CQA_Element_Std::CQA_Element_Std(void)
{
}

CQA_Element_Std::~CQA_Element_Std(void)
{
}
