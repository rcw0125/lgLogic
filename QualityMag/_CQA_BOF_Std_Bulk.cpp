// �߼���CQA_BOF_Std_BulkԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CQA_BOF_Std_Bulk.h"

IMPLEMENT_L3CLASS(CQA_BOF_Std_Bulk,CL3Object,1)

BEGIN_L3PROPTABLE(CQA_BOF_Std_Bulk,CL3Object)
	L3PROP_STRING(SteelGradeIndex)
	L3PROP_STRING(Bulk_Code)
	L3PROP_DOUBLE(Bulk_Weight_Min)
	L3PROP_DOUBLE(Bulk_Weight_Max)
END_L3PROPTABLE(CQA_BOF_Std_Bulk)

BEGIN_L3METHODMAP(CQA_BOF_Std_Bulk,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CQA_BOF_Std_Bulk,CL3Object)
END_L3EVENTSINK_MAP(CQA_BOF_Std_Bulk)

CQA_BOF_Std_Bulk::CQA_BOF_Std_Bulk(void)
{
}

CQA_BOF_Std_Bulk::~CQA_BOF_Std_Bulk(void)
{
}
