// �߼���CQA_BOF_Std_LadleԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CQA_BOF_Std_Ladle.h"

IMPLEMENT_L3CLASS(CQA_BOF_Std_Ladle,CL3Object,1)

BEGIN_L3PROPTABLE(CQA_BOF_Std_Ladle,CL3Object)
	L3PROP_STRING(SteelGradeIndex)
	L3PROP_STRING(Ladle_Mat_Name)
	L3PROP_DOUBLE(Ladle_Mat_Min)
	L3PROP_DOUBLE(Ladle_Mat_Max)
	L3PROP_DOUBLE(Ladle_Mat_Aim)
END_L3PROPTABLE(CQA_BOF_Std_Ladle)

BEGIN_L3METHODMAP(CQA_BOF_Std_Ladle,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CQA_BOF_Std_Ladle,CL3Object)
END_L3EVENTSINK_MAP(CQA_BOF_Std_Ladle)

CQA_BOF_Std_Ladle::CQA_BOF_Std_Ladle(void)
{
}

CQA_BOF_Std_Ladle::~CQA_BOF_Std_Ladle(void)
{
}
