// �߼���CQA_RH_Std_FeedԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CQA_RH_Std_Feed.h"

IMPLEMENT_L3CLASS(CQA_RH_Std_Feed,CL3Object,1)

BEGIN_L3PROPTABLE(CQA_RH_Std_Feed,CL3Object)
	L3PROP_STRING(SteelGradeIndex)
	L3PROP_STRING(CaProc_Code )
	L3PROP_DOUBLE(CaProc_Code_Weight_Max)
	L3PROP_DOUBLE(CaProc_Code_Weight_Min)
END_L3PROPTABLE(CQA_RH_Std_Feed)

BEGIN_L3METHODMAP(CQA_RH_Std_Feed,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CQA_RH_Std_Feed,CL3Object)
END_L3EVENTSINK_MAP(CQA_RH_Std_Feed)

CQA_RH_Std_Feed::CQA_RH_Std_Feed(void)
{
}

CQA_RH_Std_Feed::~CQA_RH_Std_Feed(void)
{
}
