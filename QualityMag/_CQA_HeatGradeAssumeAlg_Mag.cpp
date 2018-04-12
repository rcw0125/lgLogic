// �߼���CQA_HeatGradeAssumeAlg_MagԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CQA_HeatGradeAssumeAlg_Mag.h"

IMPLEMENT_L3CLASS(CQA_HeatGradeAssumeAlg_Mag,CL3Object,1)

BEGIN_L3PROPTABLE(CQA_HeatGradeAssumeAlg_Mag,CL3Object)
END_L3PROPTABLE(CQA_HeatGradeAssumeAlg_Mag)

BEGIN_L3METHODMAP(CQA_HeatGradeAssumeAlg_Mag,CL3Object)
	L3_METHOD(CQA_HeatGradeAssumeAlg_Mag,"EstimateHeatGrade",0,EstimateHeatGrade,L3VT_BOOL,L3VTS_SHORT L3VTS_SHORT L3VTS_STRING L3VTS_SHORT)
	L3_METHOD(CQA_HeatGradeAssumeAlg_Mag,"EstimateHeatChemical",1,EstimateHeatChemical,L3VT_LONG,L3VTS_SHORT L3VTS_SHORT L3VTS_STRING L3VTS_SHORT L3VTS_RECORDSET)
	L3_METHOD(CQA_HeatGradeAssumeAlg_Mag,"RecommendSteelGradeIndex",2,RecommendSteelGradeIndex,L3VT_LONG,L3VTS_STRING L3VTS_PRECORDSET)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CQA_HeatGradeAssumeAlg_Mag,CL3Object)
END_L3EVENTSINK_MAP(CQA_HeatGradeAssumeAlg_Mag)

CQA_HeatGradeAssumeAlg_Mag::CQA_HeatGradeAssumeAlg_Mag(void)
{
}

CQA_HeatGradeAssumeAlg_Mag::~CQA_HeatGradeAssumeAlg_Mag(void)
{
}
