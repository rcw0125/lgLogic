// �߼���CQA_BOF_Std_ArԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CQA_BOF_Std_Ar.h"

IMPLEMENT_L3CLASS(CQA_BOF_Std_Ar,CL3Object,1)

BEGIN_L3PROPTABLE(CQA_BOF_Std_Ar,CL3Object)
	L3PROP_STRING(SteelGradeIndex)
	L3PROP_LONG(PreAr_SteelTemp_Fir_Max)
	L3PROP_LONG(PreAr_SteelTemp_Fir_Min)
	L3PROP_LONG(PreAr_SteelTemp_Fir_Aim)
	L3PROP_LONG(PreAr_SteelTemp_Max)
	L3PROP_LONG(PreAr_SteelTemp_Min)
	L3PROP_LONG(PreAr_SteelTemp_Aim)
	L3PROP_LONG(BeAr_SteelTemp_Fir_Max)
	L3PROP_LONG(BeAr_SteelTemp_Fir_Min)
	L3PROP_LONG(BeAr_SteelTemp_Fir_Aim)
	L3PROP_LONG(BeAr_SteelTemp_Max)
	L3PROP_LONG(BeAr_SteelTemp_Min)
	L3PROP_LONG(BeAr_SteelTemp_Aim)
	L3PROP_LONG(Oxy_Flag)
	L3PROP_DOUBLE(PreAr_Oxy_Max)
	L3PROP_DOUBLE(PreAr_Oxy_Min)
	L3PROP_LONG(Ar_Time_UpLimit)
	L3PROP_LONG(Ar_Time_LowLimit)
	L3PROP_LONG(Ar_Press_Max)
	L3PROP_LONG(Ar_Press_Min)
	L3PROP_DOUBLE(Ar_Blow_Max)
	L3PROP_DOUBLE(Ar_Blow_Min)
	L3PROP_DOUBLE(BeAr_Oxy_Max)
	L3PROP_DOUBLE(BeAr_Oxy_Min)
END_L3PROPTABLE(CQA_BOF_Std_Ar)

BEGIN_L3METHODMAP(CQA_BOF_Std_Ar,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CQA_BOF_Std_Ar,CL3Object)
END_L3EVENTSINK_MAP(CQA_BOF_Std_Ar)

CQA_BOF_Std_Ar::CQA_BOF_Std_Ar(void)
{
}

CQA_BOF_Std_Ar::~CQA_BOF_Std_Ar(void)
{
}
