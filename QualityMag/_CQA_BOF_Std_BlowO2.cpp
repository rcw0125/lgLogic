// �߼���CQA_BOF_Std_BlowO2Դ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CQA_BOF_Std_BlowO2.h"

IMPLEMENT_L3CLASS(CQA_BOF_Std_BlowO2,CL3Object,1)

BEGIN_L3PROPTABLE(CQA_BOF_Std_BlowO2,CL3Object)
	L3PROP_STRING(SteelGradeIndex)
	L3PROP_STRING(Total_O2_Press_Ctr)
	L3PROP_STRING(Work_O2_Press_Ctr)
	L3PROP_STRING(O2_Blow_Ctr)
END_L3PROPTABLE(CQA_BOF_Std_BlowO2)

BEGIN_L3METHODMAP(CQA_BOF_Std_BlowO2,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CQA_BOF_Std_BlowO2,CL3Object)
END_L3EVENTSINK_MAP(CQA_BOF_Std_BlowO2)

CQA_BOF_Std_BlowO2::CQA_BOF_Std_BlowO2(void)
{
}

CQA_BOF_Std_BlowO2::~CQA_BOF_Std_BlowO2(void)
{
}
