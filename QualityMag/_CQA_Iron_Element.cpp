// �߼���CQA_Iron_ElementԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CQA_Iron_Element.h"

IMPLEMENT_L3CLASS(CQA_Iron_Element,CL3Object,1)

BEGIN_L3PROPTABLE(CQA_Iron_Element,CL3Object)
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
	L3PROP_STRING_LEN(C,10)
	L3PROP_STRING_LEN(Si,10)
	L3PROP_STRING_LEN(Mn,10)
	L3PROP_STRING_LEN(P,10)
	L3PROP_STRING_LEN(S,10)
	L3PROP_STRING_LEN(S_Before,10)
	L3PROP_STRING_LEN(S_After,10)
	L3PROP_STRING_LEN(Ti,10)

	//add by hyh 2012-04-04
	L3PROP_STRING_LEN(Sn,10)
	L3PROP_STRING_LEN(Sb,10)
	L3PROP_STRING_LEN(As,10)
	L3PROP_STRING_LEN(Pb,10)
	//end

	//add by hyh 2012-08-09 Ӧҵ��Ҫ��������Ni(��)��Mo(��)��Cu(ͭ) ��Cr(��)��B(��)��V(��)��Al(��)��Nb(��)��Zn(п)��W(��)
	L3PROP_STRING_LEN(Ni,10)
	L3PROP_STRING_LEN(Mo,10)
	L3PROP_STRING_LEN(Cu,10)
	L3PROP_STRING_LEN(Cr,10)
	L3PROP_STRING_LEN(B,10)
	L3PROP_STRING_LEN(V,10)
	L3PROP_STRING_LEN(Al,10)
	L3PROP_STRING_LEN(Nb,10)
	L3PROP_STRING_LEN(Zn,10)
	L3PROP_STRING_LEN(W,10)
	//end

	L3PROP_DATETIME(LogTime)
	L3PROP_LONG(DataLogMode)
	L3PROP_STRING(Operator)
END_L3PROPTABLE(CQA_Iron_Element)

BEGIN_L3METHODMAP(CQA_Iron_Element,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CQA_Iron_Element,CL3Object)
END_L3EVENTSINK_MAP(CQA_Iron_Element)

CQA_Iron_Element::CQA_Iron_Element(void)
{
}

CQA_Iron_Element::~CQA_Iron_Element(void)
{
}
