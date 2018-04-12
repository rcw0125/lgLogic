// �߼���CQA_Lab_SlagEle_TextԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CQA_Lab_SlagEle_Text.h"

IMPLEMENT_L3CLASS(CQA_Lab_SlagEle_Text,CL3Object,1)

BEGIN_L3PROPTABLE(CQA_Lab_SlagEle_Text,CL3Object)
	L3PROP_STRING(AppID)
	L3PROP_DATETIME(Arrive_Date)
	L3PROP_DATETIME(Report_Date)
	L3PROP_STRING(HeatID)
	L3PROP_STRING(Sample_Address)
	L3PROP_STRING(Sample_Type)
	L3PROP_STRING(Sample_Count)
	L3PROP_STRING(Sample_Code)
	L3PROP_STRING(TFe)
	L3PROP_STRING(FeO)
	L3PROP_STRING(SiO2)
	L3PROP_STRING(TCa)
	L3PROP_STRING(CaO)
	L3PROP_STRING(MgO)
	L3PROP_STRING(Al2O3)
	L3PROP_STRING(MnO)
	L3PROP_STRING(TiO2)
	L3PROP_STRING(P2O5)
	L3PROP_STRING(S)
	L3PROP_STRING(R)
	L3PROP_DATETIME(LogTime)
	L3PROP_LONG(DataLogMode)
	L3PROP_STRING(Operator)
END_L3PROPTABLE(CQA_Lab_SlagEle_Text)

BEGIN_L3METHODMAP(CQA_Lab_SlagEle_Text,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CQA_Lab_SlagEle_Text,CL3Object)
END_L3EVENTSINK_MAP(CQA_Lab_SlagEle_Text)

CQA_Lab_SlagEle_Text::CQA_Lab_SlagEle_Text(void)
{
}

CQA_Lab_SlagEle_Text::~CQA_Lab_SlagEle_Text(void)
{
}
