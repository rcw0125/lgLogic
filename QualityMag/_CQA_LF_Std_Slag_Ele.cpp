// �߼���CQA_LF_Std_Slag_EleԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CQA_LF_Std_Slag_Ele.h"

IMPLEMENT_L3CLASS(CQA_LF_Std_Slag_Ele,CL3Object,1)

BEGIN_L3PROPTABLE(CQA_LF_Std_Slag_Ele,CL3Object)
	L3PROP_STRING(SteelGradeIndex)
	L3PROP_DOUBLE(CaO_Max)
	L3PROP_DOUBLE(CaO_Min)
	L3PROP_DOUBLE(SiO2_Max)
	L3PROP_DOUBLE(SiO2_Min)
	L3PROP_DOUBLE(MgO_Max)
	L3PROP_DOUBLE(MgO_Min)
	L3PROP_DOUBLE(Al2O3_Max)
	L3PROP_DOUBLE(Al2O3_Min)
	L3PROP_DOUBLE(S_Max)
	L3PROP_DOUBLE(S_Min)
	L3PROP_DOUBLE(P_Max)
	L3PROP_DOUBLE(P_Min)
	L3PROP_DOUBLE(MnO_Max)
	L3PROP_DOUBLE(MnO_Min)
	L3PROP_DOUBLE(TiO2_Max)
	L3PROP_DOUBLE(TiO2_Min)
	L3PROP_DOUBLE(FeO_Max)
	L3PROP_DOUBLE(FeO_Min)
END_L3PROPTABLE(CQA_LF_Std_Slag_Ele)

BEGIN_L3METHODMAP(CQA_LF_Std_Slag_Ele,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CQA_LF_Std_Slag_Ele,CL3Object)
END_L3EVENTSINK_MAP(CQA_LF_Std_Slag_Ele)

CQA_LF_Std_Slag_Ele::CQA_LF_Std_Slag_Ele(void)
{
}

CQA_LF_Std_Slag_Ele::~CQA_LF_Std_Slag_Ele(void)
{
}
