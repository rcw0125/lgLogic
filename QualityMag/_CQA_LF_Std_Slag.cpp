// �߼���CQA_LF_Std_SlagԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CQA_LF_Std_Slag.h"

IMPLEMENT_L3CLASS(CQA_LF_Std_Slag,CL3Object,1)

BEGIN_L3PROPTABLE(CQA_LF_Std_Slag,CL3Object)
	L3PROP_STRING(SteelGradeIndex)
	L3PROP_STRING(Slag_Code)
	L3PROP_DOUBLE(Slag_Weight)
END_L3PROPTABLE(CQA_LF_Std_Slag)

BEGIN_L3METHODMAP(CQA_LF_Std_Slag,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CQA_LF_Std_Slag,CL3Object)
END_L3EVENTSINK_MAP(CQA_LF_Std_Slag)

CQA_LF_Std_Slag::CQA_LF_Std_Slag(void)
{
}

CQA_LF_Std_Slag::~CQA_LF_Std_Slag(void)
{
}
