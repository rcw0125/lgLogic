// �߼���CQA_RH_Std_AlloyԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CQA_RH_Std_Alloy.h"

IMPLEMENT_L3CLASS(CQA_RH_Std_Alloy,CL3Object,1)

BEGIN_L3PROPTABLE(CQA_RH_Std_Alloy,CL3Object)
	L3PROP_STRING(SteelGradeIndex)
	L3PROP_LONG(Alloy_Flag)
	L3PROP_STRING(Alloy_Code)
	L3PROP_DOUBLE(Alloy_Yield)
END_L3PROPTABLE(CQA_RH_Std_Alloy)

BEGIN_L3METHODMAP(CQA_RH_Std_Alloy,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CQA_RH_Std_Alloy,CL3Object)
END_L3EVENTSINK_MAP(CQA_RH_Std_Alloy)

CQA_RH_Std_Alloy::CQA_RH_Std_Alloy(void)
{
}

CQA_RH_Std_Alloy::~CQA_RH_Std_Alloy(void)
{
}
