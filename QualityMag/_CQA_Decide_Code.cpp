// �߼���CQA_Decide_CodeԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CQA_Decide_Code.h"

IMPLEMENT_L3CLASS(CQA_Decide_Code,CL3Object,1)

BEGIN_L3PROPTABLE(CQA_Decide_Code,CL3Object)
	L3PROP_STRING(Decide_Code)
	L3PROP_STRING(Decide_Des)
	L3PROP_LONG(Classify)
END_L3PROPTABLE(CQA_Decide_Code)

BEGIN_L3METHODMAP(CQA_Decide_Code,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CQA_Decide_Code,CL3Object)
END_L3EVENTSINK_MAP(CQA_Decide_Code)

CQA_Decide_Code::CQA_Decide_Code(void)
{
}

CQA_Decide_Code::~CQA_Decide_Code(void)
{
}
