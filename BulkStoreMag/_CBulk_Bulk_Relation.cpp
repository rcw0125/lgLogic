// �߼���CBulk_Bulk_RelationԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CBulk_Bulk_Relation.h"

IMPLEMENT_L3CLASS(CBulk_Bulk_Relation,CL3Object,1)

BEGIN_L3PROPTABLE(CBulk_Bulk_Relation,CL3Object)
	L3PROP_STRING(Bulk_Area)
	L3PROP_STRING(Bulk_Code)
	L3PROP_LONG(TopSlagFlag)
END_L3PROPTABLE(CBulk_Bulk_Relation)

BEGIN_L3METHODMAP(CBulk_Bulk_Relation,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CBulk_Bulk_Relation,CL3Object)
END_L3EVENTSINK_MAP(CBulk_Bulk_Relation)

CBulk_Bulk_Relation::CBulk_Bulk_Relation(void)
{
}

CBulk_Bulk_Relation::~CBulk_Bulk_Relation(void)
{
}
