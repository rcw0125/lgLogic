// �߼���CAlloy_Bulk_RelationԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CAlloy_Bulk_Relation.h"

IMPLEMENT_L3CLASS(CAlloy_Bulk_Relation,CL3Object,1)

BEGIN_L3PROPTABLE(CAlloy_Bulk_Relation,CL3Object)
	L3PROP_STRING(Alloy_Area)
	L3PROP_STRING(Alloy_Code)
	L3PROP_LONG(TopSlagFlag)
    L3PROP_STRING(Alloy_Vendor)
END_L3PROPTABLE(CAlloy_Bulk_Relation)

BEGIN_L3METHODMAP(CAlloy_Bulk_Relation,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CAlloy_Bulk_Relation,CL3Object)
END_L3EVENTSINK_MAP(CAlloy_Bulk_Relation)

CAlloy_Bulk_Relation::CAlloy_Bulk_Relation(void)
{
}

CAlloy_Bulk_Relation::~CAlloy_Bulk_Relation(void)
{
}
