// �߼���CQA_BOF_Std_BlowԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CQA_BOF_Std_Blow.h"

IMPLEMENT_L3CLASS(CQA_BOF_Std_Blow,CL3Object,1)

BEGIN_L3PROPTABLE(CQA_BOF_Std_Blow,CL3Object)
	L3PROP_STRING(SteelGradeIndex)
	L3PROP_LONG(ReBlow_Cnt_Max)
	L3PROP_LONG(Catch_C_Temp_Min)
	L3PROP_LONG(ReBlow_Time_Max)
	L3PROP_STRING(Bottom_Blow_Base)
END_L3PROPTABLE(CQA_BOF_Std_Blow)

BEGIN_L3METHODMAP(CQA_BOF_Std_Blow,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CQA_BOF_Std_Blow,CL3Object)
END_L3EVENTSINK_MAP(CQA_BOF_Std_Blow)

CQA_BOF_Std_Blow::CQA_BOF_Std_Blow(void)
{
}

CQA_BOF_Std_Blow::~CQA_BOF_Std_Blow(void)
{
}
