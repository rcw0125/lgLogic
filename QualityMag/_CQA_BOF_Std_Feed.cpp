// �߼���CQA_BOF_Std_FeedԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CQA_BOF_Std_Feed.h"

IMPLEMENT_L3CLASS(CQA_BOF_Std_Feed,CL3Object,1)

BEGIN_L3PROPTABLE(CQA_BOF_Std_Feed,CL3Object)
	L3PROP_STRING(SteelGradeIndex)
	L3PROP_STRING(Feed_Code)
	L3PROP_DOUBLE(Feed_Weight_Min)
	L3PROP_DOUBLE(Feed_Weight_Max)
END_L3PROPTABLE(CQA_BOF_Std_Feed)

BEGIN_L3METHODMAP(CQA_BOF_Std_Feed,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CQA_BOF_Std_Feed,CL3Object)
END_L3EVENTSINK_MAP(CQA_BOF_Std_Feed)

CQA_BOF_Std_Feed::CQA_BOF_Std_Feed(void)
{
}

CQA_BOF_Std_Feed::~CQA_BOF_Std_Feed(void)
{
}
