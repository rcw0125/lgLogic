// �߼���CQA_Cal_Weight_StdԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CQA_Cal_Weight_Std.h"

IMPLEMENT_L3CLASS(CQA_Cal_Weight_Std,CL3Object,1)

BEGIN_L3PROPTABLE(CQA_Cal_Weight_Std,CL3Object)
	L3PROP_STRING(ObjectID)
	L3PROP_STRING(SteelGrade)
	L3PROP_LONG(Length)
	L3PROP_DOUBLE(Weight)
	L3PROP_STRING(Spec)
END_L3PROPTABLE(CQA_Cal_Weight_Std)

BEGIN_L3METHODMAP(CQA_Cal_Weight_Std,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CQA_Cal_Weight_Std,CL3Object)
END_L3EVENTSINK_MAP(CQA_Cal_Weight_Std)

CQA_Cal_Weight_Std::CQA_Cal_Weight_Std(void)
{
}

CQA_Cal_Weight_Std::~CQA_Cal_Weight_Std(void)
{
}
