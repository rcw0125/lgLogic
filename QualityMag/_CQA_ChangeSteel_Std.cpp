// �߼���CQA_ChangeSteel_StdԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CQA_ChangeSteel_Std.h"

IMPLEMENT_L3CLASS(CQA_ChangeSteel_Std,CL3Object,1)

BEGIN_L3PROPTABLE(CQA_ChangeSteel_Std,CL3Object)
	L3PROP_STRING(SteelGrade)
	L3PROP_STRING(Judged_SteelGrade)
END_L3PROPTABLE(CQA_ChangeSteel_Std)

BEGIN_L3METHODMAP(CQA_ChangeSteel_Std,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CQA_ChangeSteel_Std,CL3Object)
END_L3EVENTSINK_MAP(CQA_ChangeSteel_Std)

CQA_ChangeSteel_Std::CQA_ChangeSteel_Std(void)
{
}

CQA_ChangeSteel_Std::~CQA_ChangeSteel_Std(void)
{
}
