// �߼���CQA_Heat_FinJudge_LogԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CQA_Heat_FinJudge_Log.h"

IMPLEMENT_L3CLASS(CQA_Heat_FinJudge_Log,CL3Object,1)

BEGIN_L3PROPTABLE(CQA_Heat_FinJudge_Log,CL3Object)
	L3PROP_STRING(HeatID)
	L3PROP_STRING(SteelGradeIndex)
	L3PROP_STRING(Final_SteelGradeIndex)
	L3PROP_DATETIME(Judge_Date)
	L3PROP_STRING(Operator)
	L3PROP_STRING(TeamID)
	L3PROP_STRING(ShiftID)
END_L3PROPTABLE(CQA_Heat_FinJudge_Log)

BEGIN_L3METHODMAP(CQA_Heat_FinJudge_Log,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CQA_Heat_FinJudge_Log,CL3Object)
END_L3EVENTSINK_MAP(CQA_Heat_FinJudge_Log)

CQA_Heat_FinJudge_Log::CQA_Heat_FinJudge_Log(void)
{
}

CQA_Heat_FinJudge_Log::~CQA_Heat_FinJudge_Log(void)
{
}
