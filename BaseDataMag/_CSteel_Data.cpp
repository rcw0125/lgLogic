// �߼���CSteel_DataԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CSteel_Data.h"

IMPLEMENT_L3CLASS(CSteel_Data,Material,1)

BEGIN_L3PROPTABLE(CSteel_Data,Material)
	L3PROP_STRING(PreHeatID)
	L3PROP_STRING(SteelGradeIndex)
	L3PROP_STRING(Pre_SteelGradeIndex)
	L3PROP_STRING(Final_SteelGradeIndex)
	L3PROP_STRING(Decide_SteelGradeIndex)
	L3PROP_STRING(HeatID)
	L3PROP_STRING(LadleID)
	L3PROP_FLOAT(Weight)
	L3PROP_STRING(Decide_Code)
	L3PROP_STRING(HeatGrade)
	L3PROP_STRING(Classify)
	L3PROP_STRING(Exceptional_Code)
	L3PROP_STRING(DecideSteelGradeIndexFlag)
	L3PROP_STRING(DecideFinalFlag)
	L3PROP_STRING(BOFFinishedFlag)
	L3PROP_STRING(LFFinishedFlag)
	L3PROP_STRING(RHFinishedFlag)
	L3PROP_STRING(CCMFinishedFlag)
	L3PROP_STRING(FinalChemiclaFlag)
	L3PROP_STRING(DivFinalChemiclaFlag)
END_L3PROPTABLE(CSteel_Data)

BEGIN_L3METHODMAP(CSteel_Data,Material)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CSteel_Data,Material)
END_L3EVENTSINK_MAP(CSteel_Data)

CSteel_Data::CSteel_Data(void)
{
}

CSteel_Data::~CSteel_Data(void)
{
}
