// �߼���CQA_BOF_Std_InToConverԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CQA_BOF_Std_InToConver.h"

IMPLEMENT_L3CLASS(CQA_BOF_Std_InToConver,CL3Object,1)

BEGIN_L3PROPTABLE(CQA_BOF_Std_InToConver,CL3Object)
	L3PROP_STRING(SteelGradeIndex)
	L3PROP_LONG(Iron_Temp_Min)
	L3PROP_LONG(Iron_Temp_Max)
	L3PROP_DOUBLE(Iron_Weight_Max)
	L3PROP_DOUBLE(Iron_Weight_Min)
	L3PROP_DOUBLE(Iron_S_Max)
	L3PROP_DOUBLE(Iron_S_Min)
	L3PROP_DOUBLE(Iron_P_Max)
	L3PROP_DOUBLE(Iron_P_Min)
	L3PROP_DOUBLE(Iron_Si_Max)
	L3PROP_DOUBLE(Iron_Si_Min)
	L3PROP_DOUBLE(Iron_Ti_Min)
	L3PROP_DOUBLE(Iron_Ti_Max)
	L3PROP_STRING(Scrap_Type)
	L3PROP_DOUBLE(Scrap_Weight_Max)
	L3PROP_DOUBLE(Scrap_Weight_Min)
	L3PROP_DOUBLE(PigIron_Weight_Max)
	L3PROP_DOUBLE(PigIron_Weight_Min)
	L3PROP_DOUBLE(Total_Weight_Min)
	L3PROP_DOUBLE(Total_Weight_Max)
END_L3PROPTABLE(CQA_BOF_Std_InToConver)

BEGIN_L3METHODMAP(CQA_BOF_Std_InToConver,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CQA_BOF_Std_InToConver,CL3Object)
END_L3EVENTSINK_MAP(CQA_BOF_Std_InToConver)

CQA_BOF_Std_InToConver::CQA_BOF_Std_InToConver(void)
{
}

CQA_BOF_Std_InToConver::~CQA_BOF_Std_InToConver(void)
{
}
