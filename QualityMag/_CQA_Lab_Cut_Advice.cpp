// �߼���CQA_Lab_Cut_AdviceԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CQA_Lab_Cut_Advice.h"

IMPLEMENT_L3CLASS(CQA_Lab_Cut_Advice,CL3Object,1)

BEGIN_L3PROPTABLE(CQA_Lab_Cut_Advice,CL3Object)
	L3PROP_STRING(HeatID)
	L3PROP_STRING(SteelGradeIndex)
	L3PROP_STRING(SteelGrade)
	L3PROP_STRING(Protocol)
	L3PROP_STRING(CasterID)
	L3PROP_LONG(Cut_Count)
	L3PROP_STRING(Cut_Position)
	L3PROP_STRING(Cut_Dimen)
	L3PROP_STRING(Cut_Mark)
	L3PROP_DATETIME(Log_Time)
END_L3PROPTABLE(CQA_Lab_Cut_Advice)

BEGIN_L3METHODMAP(CQA_Lab_Cut_Advice,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CQA_Lab_Cut_Advice,CL3Object)
END_L3EVENTSINK_MAP(CQA_Lab_Cut_Advice)

CQA_Lab_Cut_Advice::CQA_Lab_Cut_Advice(void)
{
}

CQA_Lab_Cut_Advice::~CQA_Lab_Cut_Advice(void)
{
}
