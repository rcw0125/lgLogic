// �߼���CQA_HeatGradeDataԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CQA_HeatGradeData.h"

IMPLEMENT_L3CLASS(CQA_HeatGradeData,CL3Object,1)

BEGIN_L3PROPTABLE(CQA_HeatGradeData,CL3Object)
	L3PROP_STRING(ID_Object)
	L3PROP_STRING(HeatID)
	L3PROP_LONG(ProcessCount)
	L3PROP_LONG(UnitTypeID)
	L3PROP_LONG(UnitID)
	L3PROP_STRING(Exceptional_Code)
	L3PROP_STRING(Decide_Code)
	L3PROP_STRING(HeatGrade)
	L3PROP_STRING(PreHeatID)
	L3PROP_STRING(Pre_SteelGradeIndex)
	L3PROP_STRING(SteelGradeIndex)
	L3PROP_LONG(DataLogMode)
END_L3PROPTABLE(CQA_HeatGradeData)

BEGIN_L3METHODMAP(CQA_HeatGradeData,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CQA_HeatGradeData,CL3Object)
END_L3EVENTSINK_MAP(CQA_HeatGradeData)

CQA_HeatGradeData::CQA_HeatGradeData(void)
{
}

CQA_HeatGradeData::~CQA_HeatGradeData(void)
{
}
