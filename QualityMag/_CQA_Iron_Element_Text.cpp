// �߼���CQA_Iron_Element_TextԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CQA_Iron_Element_Text.h"

IMPLEMENT_L3CLASS(CQA_Iron_Element_Text,CL3Object,1)

BEGIN_L3PROPTABLE(CQA_Iron_Element_Text,CL3Object)
	L3PROP_STRING(AppID)
	L3PROP_STRING(TAP_No)
	L3PROP_STRING(TPC_No)
	L3PROP_STRING(Sample_Code)
	L3PROP_DATETIME(Arrive_Date)
	L3PROP_DATETIME(Report_Date)
	L3PROP_LONG(UnitTypeID)
	L3PROP_LONG(UnitID)
	L3PROP_STRING(Sample_Address)
	L3PROP_STRING(Sample_Type)
	L3PROP_STRING(Sample_Count)
	L3PROP_STRING(C)
	L3PROP_STRING(Si)
	L3PROP_STRING(Mn)
	L3PROP_STRING(P)
	L3PROP_STRING(S)
	L3PROP_STRING(S_Before)
	L3PROP_STRING(S_After)
	L3PROP_STRING(Ti)

	//add by hyh 2012=04-12
	L3PROP_STRING(Sn)
	L3PROP_STRING(Sb)
	L3PROP_STRING(As)
	L3PROP_STRING(Pb)
	//end

	//add by hyh 2012-08-09 Ӧҵ��Ҫ��������Ni(��)��Mo(��)��Cu(ͭ) ��Cr(��)��B(��)��V(��)��Al(��)��Nb(��)��Zn(п)��W(��)
	L3PROP_STRING(Ni)
	L3PROP_STRING(Mo)
	L3PROP_STRING(Cu)
	L3PROP_STRING(Cr)
	L3PROP_STRING(B)
	L3PROP_STRING(V)
	L3PROP_STRING(Al)
	L3PROP_STRING(Nb)
	L3PROP_STRING(Zn)
	L3PROP_STRING(W)
	//end

	L3PROP_DATETIME(LogTime)
	L3PROP_LONG(DataLogMode)
	L3PROP_STRING(Operator)
END_L3PROPTABLE(CQA_Iron_Element_Text)

BEGIN_L3METHODMAP(CQA_Iron_Element_Text,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CQA_Iron_Element_Text,CL3Object)
END_L3EVENTSINK_MAP(CQA_Iron_Element_Text)

CQA_Iron_Element_Text::CQA_Iron_Element_Text(void)
{
}

CQA_Iron_Element_Text::~CQA_Iron_Element_Text(void)
{
}
