// �߼���CQA_RH_Std_BaseԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CQA_RH_Std_Base.h"

IMPLEMENT_L3CLASS(CQA_RH_Std_Base,CL3Object,1)

BEGIN_L3PROPTABLE(CQA_RH_Std_Base,CL3Object)
	L3PROP_STRING(SteelGradeIndex)
	L3PROP_DATETIME(Valid_Date)
	L3PROP_STRING(New_Code)
	L3PROP_STRING(Note)
END_L3PROPTABLE(CQA_RH_Std_Base)

BEGIN_L3METHODMAP(CQA_RH_Std_Base,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CQA_RH_Std_Base,CL3Object)
END_L3EVENTSINK_MAP(CQA_RH_Std_Base)

CQA_RH_Std_Base::CQA_RH_Std_Base(void)
{
}

CQA_RH_Std_Base::~CQA_RH_Std_Base(void)
{
}
